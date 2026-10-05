#include "game.h"
namespace game
{

/* align: skip  */
void Application::asm_sub_416820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00416820  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00416821  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00416822  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00416824  bf36000000             -mov edi, 0x36
    cpu.edi = 54 /*0x36*/;
L_0x00416829:
    // 00416829  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041682c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041682e  7407                   -je 0x416837
    if (cpu.flags.zf)
    {
        goto L_0x00416837;
    }
    // 00416830  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00416832  e809000000             -call 0x416840
    cpu.esp -= 4;
    sub_416840(app, cpu);
L_0x00416837:
    // 00416837  83c630                 +add esi, 0x30
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041683a  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041683b  75ec                   -jne 0x416829
    if (!cpu.flags.zf)
    {
        goto L_0x00416829;
    }
    // 0041683d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041683e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041683f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_416840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00416840  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00416841  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00416842  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00416843  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00416845  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00416846  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00416849  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0041684c  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0041684f  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 00416852  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 00416855  8b8f78d54800           -mov ecx, dword ptr [edi + 0x48d578]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4773240) /* 0x48d578 */);
    // 0041685b  8b83d0d44800           -mov eax, dword ptr [ebx + 0x48d4d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4773072) /* 0x48d4d0 */);
    // 00416861  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00416863  8b0d88c74a00           -mov ecx, dword ptr [0x4ac788]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00416869  03c2                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041686b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041686f  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00416873  d8890c180000           -fmul dword ptr [ecx + 0x180c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(6156) /* 0x180c */));
    // 00416879  e812050600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0041687e  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00416881  8b93d4d44800           -mov edx, dword ptr [ebx + 0x48d4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4773076) /* 0x48d4d4 */);
    // 00416887  8b8f7cd54800           -mov ecx, dword ptr [edi + 0x48d57c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4773244) /* 0x48d57c */);
    // 0041688d  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00416890  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00416892  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00416894  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00416899  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0041689d  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 004168a1  d88810180000           -fmul dword ptr [eax + 0x1810]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(6160) /* 0x1810 */));
    // 004168a7  e8e4040600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 004168ac  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004168af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004168b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004168b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004168b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004168b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4168c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004168c0  db8104180000           -fild dword ptr [ecx + 0x1804]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6148) /* 0x1804 */))));
    // 004168c6  d80db0754800           -fmul dword ptr [0x4875b0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748720) /* 0x4875b0 */));
    // 004168cc  d9990c180000           -fstp dword ptr [ecx + 0x180c]
    app->getMemory<float>(cpu.ecx + x86::reg32(6156) /* 0x180c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004168d2  db8108180000           -fild dword ptr [ecx + 0x1808]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6152) /* 0x1808 */))));
    // 004168d8  d80dac754800           -fmul dword ptr [0x4875ac]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748716) /* 0x4875ac */));
    // 004168de  d99910180000           -fstp dword ptr [ecx + 0x1810]
    app->getMemory<float>(cpu.ecx + x86::reg32(6160) /* 0x1810 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004168e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4168f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004168f0  890dd4c74a00           -mov dword ptr [0x4ac7d4], ecx
    app->getMemory<x86::reg32>(x86::reg32(4900820) /* 0x4ac7d4 */) = cpu.ecx;
    // 004168f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_416900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00416900  a1d4c74a00             -mov eax, dword ptr [0x4ac7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900820) /* 0x4ac7d4 */);
    // 00416905  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_416910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00416910  83f90e                 +cmp ecx, 0xe
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00416913  7736                   -ja 0x41694b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041694b;
    }
    // 00416915  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00416917  8a816c694100           -mov al, byte ptr [ecx + 0x41696c]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4286828) /* 0x41696c */);
    // 0041691d  ff248554694100         -jmp dword ptr [eax*4 + 0x416954]
    cpu.ip = app->getMemory<x86::reg32>(4286804 + cpu.eax * 4); goto dynamic_jump;
  case 0x00416924:
    // 00416924  b830fc4800             -mov eax, 0x48fc30
    cpu.eax = 4783152 /*0x48fc30*/;
    // 00416929  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041692a:
    // 0041692a  803d1015520007         +cmp byte ptr [0x521510], 7
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
    // 00416931  7406                   -je 0x416939
    if (cpu.flags.zf)
    {
        goto L_0x00416939;
    }
    // 00416933  b860fc4800             -mov eax, 0x48fc60
    cpu.eax = 4783200 /*0x48fc60*/;
    // 00416938  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00416939:
    // 00416939  b870fc4800             -mov eax, 0x48fc70
    cpu.eax = 4783216 /*0x48fc70*/;
    // 0041693e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041693f:
    // 0041693f  b848fc4800             -mov eax, 0x48fc48
    cpu.eax = 4783176 /*0x48fc48*/;
    // 00416944  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00416945:
    // 00416945  b8b4fc4800             -mov eax, 0x48fcb4
    cpu.eax = 4783284 /*0x48fcb4*/;
    // 0041694a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041694b:
L_0x0041694b:
    // 0041694b  b814fc4800             -mov eax, 0x48fc14
    cpu.eax = 4783124 /*0x48fc14*/;
    // 00416950  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_416980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00416980  e87bffffff             -call 0x416900
    cpu.esp -= 4;
    sub_416900(app, cpu);
    // 00416985  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00416986  7414                   -je 0x41699c
    if (cpu.flags.zf)
    {
        goto L_0x0041699c;
    }
    // 00416988  83e802                 +sub eax, 2
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
    // 0041698b  7409                   -je 0x416996
    if (cpu.flags.zf)
    {
        goto L_0x00416996;
    }
    // 0041698d  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041698e  750c                   -jne 0x41699c
    if (!cpu.flags.zf)
    {
        goto L_0x0041699c;
    }
    // 00416990  b830fc4800             -mov eax, 0x48fc30
    cpu.eax = 4783152 /*0x48fc30*/;
    // 00416995  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00416996:
    // 00416996  b8e8fc4800             -mov eax, 0x48fce8
    cpu.eax = 4783336 /*0x48fce8*/;
    // 0041699b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041699c:
    // 0041699c  b8c8fc4800             -mov eax, 0x48fcc8
    cpu.eax = 4783304 /*0x48fcc8*/;
    // 004169a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4169b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004169b0  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 004169b5  e936e8ffff             -jmp 0x4151f0
    return sub_4151f0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4169c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004169c0  49                     -dec ecx
    (cpu.ecx)--;
    // 004169c1  b859000000             -mov eax, 0x59
    cpu.eax = 89 /*0x59*/;
    // 004169c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4169d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004169d0  a148845100             -mov eax, dword ptr [0x518448]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 004169d5  8b150cfd4800           -mov edx, dword ptr [0x48fd0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783372) /* 0x48fd0c */);
    // 004169db  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004169dd  83f802                 +cmp eax, 2
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
    // 004169e0  7e05                   -jle 0x4169e7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004169e7;
    }
    // 004169e2  e889550000             -call 0x41bf70
    cpu.esp -= 4;
    sub_41bf70(app, cpu);
L_0x004169e7:
    // 004169e7  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 004169ed  890d0cfd4800           -mov dword ptr [0x48fd0c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4783372) /* 0x48fd0c */) = cpu.ecx;
    // 004169f3  e8a8e1ffff             -call 0x414ba0
    cpu.esp -= 4;
    sub_414ba0(app, cpu);
    // 004169f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004169fa  7405                   -je 0x416a01
    if (cpu.flags.zf)
    {
        goto L_0x00416a01;
    }
    // 004169fc  e85f070000             -call 0x417160
    cpu.esp -= 4;
    sub_417160(app, cpu);
L_0x00416a01:
    // 00416a01  e8ca060100             -call 0x4270d0
    cpu.esp -= 4;
    sub_4270d0(app, cpu);
    // 00416a06  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00416a08  e903000000             -jmp 0x416a10
    return sub_416a10(app, cpu);
}

/* align: skip  */
void Application::asm_sub_416a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00416a10  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00416a12  7422                   -je 0x416a36
    if (cpu.flags.zf)
    {
        goto L_0x00416a36;
    }
    // 00416a14  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00416a16  83f8ff                 +cmp eax, -1
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
    // 00416a19  7416                   -je 0x416a31
    if (cpu.flags.zf)
    {
        goto L_0x00416a31;
    }
    // 00416a1b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00416a1c  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x00416a1e:
    // 00416a1e  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00416a20  e81b000000             -call 0x416a40
    cpu.esp -= 4;
    sub_416a40(app, cpu);
    // 00416a25  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00416a28  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00416a2b  83f8ff                 +cmp eax, -1
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
    // 00416a2e  75ee                   -jne 0x416a1e
    if (!cpu.flags.zf)
    {
        goto L_0x00416a1e;
    }
    // 00416a30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00416a31:
    // 00416a31  e9ea320000             -jmp 0x419d20
    return sub_419d20(app, cpu);
L_0x00416a36:
    // 00416a36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_416a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00416a40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00416a41  8d3449                 -lea esi, [ecx + ecx*2]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00416a44  8b0d88c74a00           -mov ecx, dword ptr [0x4ac788]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00416a4a  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00416a4d  03f1                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00416a4f  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00416a52  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00416a54  7416                   -je 0x416a6c
    if (cpu.flags.zf)
    {
        goto L_0x00416a6c;
    }
    // 00416a56  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00416a58  e8b3060000             -call 0x417110
    cpu.esp -= 4;
    sub_417110(app, cpu);
    // 00416a5d  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00416a60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00416a62  7408                   -je 0x416a6c
    if (cpu.flags.zf)
    {
        goto L_0x00416a6c;
    }
    // 00416a64  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00416a66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00416a67  e904000000             -jmp 0x416a70
    return sub_416a70(app, cpu);
L_0x00416a6c:
    // 00416a6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00416a6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_416a70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00416a70  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00416a73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00416a74  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00416a76  8b0d88c74a00           -mov ecx, dword ptr [0x4ac788]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00416a7c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00416a7d  e86efdffff             -call 0x4167f0
    cpu.esp -= 4;
    sub_4167f0(app, cpu);
    // 00416a82  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00416a84  e8e7050000             -call 0x417070
    cpu.esp -= 4;
    sub_417070(app, cpu);
    // 00416a89  8b7528                 -mov esi, dword ptr [ebp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00416a8c  c744240800000000       -mov dword ptr [esp + 8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00416a94  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00416a96  0f8407020000           -je 0x416ca3
    if (cpu.flags.zf)
    {
        goto L_0x00416ca3;
    }
    // 00416a9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00416a9d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00416a9e:
    // 00416a9e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00416aa0  e82b020000             -call 0x416cd0
    cpu.esp -= 4;
    sub_416cd0(app, cpu);
    // 00416aa5  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00416aa7  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00416aa9  e882050000             -call 0x417030
    cpu.esp -= 4;
    sub_417030(app, cpu);
    // 00416aae  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00416ab0  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00416ab2  e8f9090000             -call 0x4174b0
    cpu.esp -= 4;
    sub_4174b0(app, cpu);
    // 00416ab7  f686c000000010         +test byte ptr [esi + 0xc0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(192) /* 0xc0 */) & 16 /*0x10*/));
    // 00416abe  7507                   -jne 0x416ac7
    if (!cpu.flags.zf)
    {
        goto L_0x00416ac7;
    }
    // 00416ac0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00416ac2  e8c90c0000             -call 0x417790
    cpu.esp -= 4;
    sub_417790(app, cpu);
L_0x00416ac7:
    // 00416ac7  8b8e90000000           -mov ecx, dword ptr [esi + 0x90]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */);
    // 00416acd  8dbe84000000           -lea edi, [esi + 0x84]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00416ad3  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00416ad6  89484c                 -mov dword ptr [eax + 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.ecx;
    // 00416ad9  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00416adb  895040                 -mov dword ptr [eax + 0x40], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 00416ade  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00416ae1  894844                 -mov dword ptr [eax + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = cpu.ecx;
    // 00416ae4  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00416ae7  895048                 -mov dword ptr [eax + 0x48], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00416aea  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00416aed  83e208                 +and edx, 8
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(8 /*0x8*/))));
    // 00416af0  740d                   -je 0x416aff
    if (cpu.flags.zf)
    {
        goto L_0x00416aff;
    }
    // 00416af2  83beb800000002         +cmp dword ptr [esi + 0xb8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00416af9  0f858b010000           -jne 0x416c8a
    if (!cpu.flags.zf)
    {
        goto L_0x00416c8a;
    }
L_0x00416aff:
    // 00416aff  8b8eb8000000           -mov ecx, dword ptr [esi + 0xb8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */);
    // 00416b05  83f905                 +cmp ecx, 5
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
    // 00416b08  0f877c010000           -ja 0x416c8a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00416c8a;
    }
    // 00416b0e  ff248dac6c4100         -jmp dword ptr [ecx*4 + 0x416cac]
    cpu.ip = app->getMemory<x86::reg32>(4287660 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00416b15:
    // 00416b15  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00416b17  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00416b19  0f846b010000           -je 0x416c8a
    if (cpu.flags.zf)
    {
        goto L_0x00416c8a;
    }
    // 00416b1f  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00416b21  ff1560845100           -call dword ptr [0x518460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342304) /* 0x518460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00416b27  e95e010000             -jmp 0x416c8a
    goto L_0x00416c8a;
  case 0x00416b2c:
    // 00416b2c  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00416b2e  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00416b30  e87b0f0000             -call 0x417ab0
    cpu.esp -= 4;
    sub_417ab0(app, cpu);
    // 00416b35  e950010000             -jmp 0x416c8a
    goto L_0x00416c8a;
  case 0x00416b3a:
    // 00416b3a  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00416b3c  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00416b3e  e8cd0f0000             -call 0x417b10
    cpu.esp -= 4;
    sub_417b10(app, cpu);
    // 00416b43  e942010000             -jmp 0x416c8a
    goto L_0x00416c8a;
  case 0x00416b48:
    // 00416b48  8b8ebc000000           -mov ecx, dword ptr [esi + 0xbc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00416b4e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00416b4f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00416b50  8b3d88c74a00           -mov edi, dword ptr [0x4ac788]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00416b56  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00416b59  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00416b5c  8b8138d74800           -mov eax, dword ptr [ecx + 0x48d738]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773688) /* 0x48d738 */);
    // 00416b62  8b9934d74800           -mov ebx, dword ptr [ecx + 0x48d734]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773684) /* 0x48d734 */);
    // 00416b68  8b4e64                 -mov ecx, dword ptr [esi + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */);
    // 00416b6b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00416b6c  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00416b6d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00416b6f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00416b70  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00416b72  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00416b74  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00416b77  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00416b7b  db442424               -fild dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 00416b7f  d88f10180000           -fmul dword ptr [edi + 0x1810]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(6160) /* 0x1810 */));
    // 00416b85  da4508                 -fiadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00416b88  e803020600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00416b8d  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00416b91  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00416b93  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00416b94  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00416b96  8b5660                 -mov edx, dword ptr [esi + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 00416b99  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00416b9b  2bd0                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00416b9d  83c20c                 +add edx, 0xc
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
    // 00416ba0  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00416ba4  db442424               +fild dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 00416ba8  d88f0c180000           +fmul dword ptr [edi + 0x180c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(6156) /* 0x180c */));
    // 00416bae  da4504                 +fiadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 00416bb1  e8da010600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00416bb6  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00416bba  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00416bbc  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00416bbe  e8dd7fffff             -call 0x40eba0
    cpu.esp -= 4;
    sub_40eba0(app, cpu);
    // 00416bc3  e9c2000000             -jmp 0x416c8a
    goto L_0x00416c8a;
  case 0x00416bc8:
    // 00416bc8  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00416bce  8d0c40                 -lea ecx, [eax + eax*2]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00416bd1  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00416bd4  8b8138d74800           -mov eax, dword ptr [ecx + 0x48d738]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773688) /* 0x48d738 */);
    // 00416bda  8b9934d74800           -mov ebx, dword ptr [ecx + 0x48d734]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773684) /* 0x48d734 */);
    // 00416be0  8b8ec0000000           -mov ecx, dword ptr [esi + 0xc0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */);
    // 00416be6  83e160                 -and ecx, 0x60
    cpu.ecx &= x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00416be9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00416bea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00416beb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00416bec  8b3d88c74a00           -mov edi, dword ptr [0x4ac788]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00416bf2  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00416bf3  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00416bf5  8b5664                 -mov edx, dword ptr [esi + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */);
    // 00416bf8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00416bfa  2bd0                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00416bfc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00416bfd  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00416c00  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00416c04  db442428               -fild dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 00416c08  d88f10180000           -fmul dword ptr [edi + 0x1810]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(6160) /* 0x1810 */));
    // 00416c0e  da4508                 -fiadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00416c11  e87a010600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00416c16  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00416c17  8b4e60                 -mov ecx, dword ptr [esi + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 00416c1a  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00416c1c  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00416c1d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00416c1f  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00416c21  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00416c23  83c10c                 +add ecx, 0xc
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00416c26  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 00416c2a  db44242c               +fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 00416c2e  d88f0c180000           +fmul dword ptr [edi + 0x180c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(6156) /* 0x180c */));
    // 00416c34  da4504                 +fiadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 00416c37  e854010600             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00416c3c  8b8ed0000000           -mov ecx, dword ptr [esi + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */);
    // 00416c42  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00416c44  e8077bffff             -call 0x40e750
    cpu.esp -= 4;
    sub_40e750(app, cpu);
    // 00416c49  eb3f                   -jmp 0x416c8a
    goto L_0x00416c8a;
  case 0x00416c4b:
    // 00416c4b  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00416c4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00416c51  740d                   -je 0x416c60
    if (cpu.flags.zf)
    {
        goto L_0x00416c60;
    }
    // 00416c53  68e4054900             -push 0x4905e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785636 /*0x4905e4*/;
    cpu.esp -= 4;
    // 00416c58  e8b3df0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00416c5d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00416c60:
    // 00416c60  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00416c66  8b152cc84a00           -mov edx, dword ptr [0x4ac82c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900908) /* 0x4ac82c */);
    // 00416c6c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00416c6d  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00416c6f  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00416c72  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00416c75  8b8828d74800           -mov ecx, dword ptr [eax + 0x48d728]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773672) /* 0x48d728 */);
    // 00416c7b  e8f0710000             -call 0x41de70
    cpu.esp -= 4;
    sub_41de70(app, cpu);
    // 00416c80  c7052cc84a0000000000   -mov dword ptr [0x4ac82c], 0
    app->getMemory<x86::reg32>(x86::reg32(4900908) /* 0x4ac82c */) = 0 /*0x0*/;
L_0x00416c8a:
    // 00416c8a  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00416c8e  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 00416c94  41                     -inc ecx
    (cpu.ecx)++;
    // 00416c95  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00416c97  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00416c9b  0f85fdfdffff           -jne 0x416a9e
    if (!cpu.flags.zf)
    {
        goto L_0x00416a9e;
    }
    // 00416ca1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00416ca2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00416ca3:
    // 00416ca3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00416ca4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00416ca5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00416ca8  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_416cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00416cd0  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00416cd3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00416cd4  8b99c0000000           -mov ebx, dword ptr [ecx + 0xc0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(192) /* 0xc0 */);
    // 00416cda  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 00416cdd  0f84cf010000           -je 0x416eb2
    if (cpu.flags.zf)
    {
        goto L_0x00416eb2;
    }
    // 00416ce3  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 00416ce6  0f84cb010000           -je 0x416eb7
    if (cpu.flags.zf)
    {
        goto L_0x00416eb7;
    }
    // 00416cec  d981a4000000           -fld dword ptr [ecx + 0xa4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(164) /* 0xa4 */)));
    // 00416cf2  d88184000000           -fadd dword ptr [ecx + 0x84]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(132) /* 0x84 */));
    // 00416cf8  8d91a4000000           -lea edx, [ecx + 0xa4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 00416cfe  d99184000000           -fst dword ptr [ecx + 0x84]
    app->getMemory<float>(cpu.ecx + x86::reg32(132) /* 0x84 */) = float(cpu.fpu.st(0));
    // 00416d04  d98188000000           -fld dword ptr [ecx + 0x88]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(136) /* 0x88 */)));
    // 00416d0a  d881a8000000           -fadd dword ptr [ecx + 0xa8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(168) /* 0xa8 */));
    // 00416d10  d954240c               -fst dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    // 00416d14  d99988000000           -fstp dword ptr [ecx + 0x88]
    app->getMemory<float>(cpu.ecx + x86::reg32(136) /* 0x88 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00416d1a  d9818c000000           -fld dword ptr [ecx + 0x8c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(140) /* 0x8c */)));
    // 00416d20  d881ac000000           -fadd dword ptr [ecx + 0xac]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(172) /* 0xac */));
    // 00416d26  d9542408               -fst dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    // 00416d2a  d9998c000000           -fstp dword ptr [ecx + 0x8c]
    app->getMemory<float>(cpu.ecx + x86::reg32(140) /* 0x8c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00416d30  d98190000000           -fld dword ptr [ecx + 0x90]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(144) /* 0x90 */)));
    // 00416d36  d881b0000000           -fadd dword ptr [ecx + 0xb0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(176) /* 0xb0 */));
    // 00416d3c  d9542410               -fst dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    // 00416d40  d99990000000           -fstp dword ptr [ecx + 0x90]
    app->getMemory<float>(cpu.ecx + x86::reg32(144) /* 0x90 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00416d46  d8a994000000           -fsubr dword ptr [ecx + 0x94]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(148) /* 0x94 */)) - cpu.fpu.st(0);
    // 00416d4c  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00416d52  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416d54  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 00416d59  7402                   -je 0x416d5d
    if (cpu.flags.zf)
    {
        goto L_0x00416d5d;
    }
    // 00416d5b  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00416d5d:
    // 00416d5d  d98198000000           -fld dword ptr [ecx + 0x98]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(152) /* 0x98 */)));
    // 00416d63  d864240c               -fsub dword ptr [esp + 0xc]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 00416d67  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00416d6d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416d6f  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 00416d74  7402                   -je 0x416d78
    if (cpu.flags.zf)
    {
        goto L_0x00416d78;
    }
    // 00416d76  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00416d78:
    // 00416d78  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00416d7c  d9819c000000           -fld dword ptr [ecx + 0x9c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(156) /* 0x9c */)));
    // 00416d82  d8642408               -fsub dword ptr [esp + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00416d86  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00416d8c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416d8e  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 00416d93  7402                   -je 0x416d97
    if (cpu.flags.zf)
    {
        goto L_0x00416d97;
    }
    // 00416d95  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00416d97:
    // 00416d97  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00416d9b  d981a0000000           -fld dword ptr [ecx + 0xa0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(160) /* 0xa0 */)));
    // 00416da1  d8642410               -fsub dword ptr [esp + 0x10]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00416da5  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00416dab  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416dad  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 00416db2  7402                   -je 0x416db6
    if (cpu.flags.zf)
    {
        goto L_0x00416db6;
    }
    // 00416db4  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00416db6:
    // 00416db6  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00416dba  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00416dbc  dcc0                   -fadd st(0), st(0)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(0));
    // 00416dbe  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00416dc4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416dc6  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 00416dcb  7402                   -je 0x416dcf
    if (cpu.flags.zf)
    {
        goto L_0x00416dcf;
    }
    // 00416dcd  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00416dcf:
    // 00416dcf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00416dd1  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00416dd3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416dd5  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 00416dd8  0f8ad4000000           -jp 0x416eb2
    if (cpu.flags.pf)
    {
        goto L_0x00416eb2;
    }
    // 00416dde  d981a8000000           -fld dword ptr [ecx + 0xa8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(168) /* 0xa8 */)));
    // 00416de4  dcc0                   -fadd st(0), st(0)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(0));
    // 00416de6  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00416dec  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416dee  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 00416df3  7402                   -je 0x416df7
    if (cpu.flags.zf)
    {
        goto L_0x00416df7;
    }
    // 00416df5  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00416df7:
    // 00416df7  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00416dfb  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00416dfd  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416dff  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 00416e02  0f8aaa000000           -jp 0x416eb2
    if (cpu.flags.pf)
    {
        goto L_0x00416eb2;
    }
    // 00416e08  d981ac000000           -fld dword ptr [ecx + 0xac]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(172) /* 0xac */)));
    // 00416e0e  dcc0                   -fadd st(0), st(0)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(0));
    // 00416e10  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00416e16  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416e18  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 00416e1d  7402                   -je 0x416e21
    if (cpu.flags.zf)
    {
        goto L_0x00416e21;
    }
    // 00416e1f  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00416e21:
    // 00416e21  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00416e25  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00416e27  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416e29  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 00416e2c  0f8a80000000           -jp 0x416eb2
    if (cpu.flags.pf)
    {
        goto L_0x00416eb2;
    }
    // 00416e32  d981b0000000           -fld dword ptr [ecx + 0xb0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(176) /* 0xb0 */)));
    // 00416e38  dcc0                   -fadd st(0), st(0)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(0));
    // 00416e3a  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00416e40  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416e42  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 00416e47  7402                   -je 0x416e4b
    if (cpu.flags.zf)
    {
        goto L_0x00416e4b;
    }
    // 00416e49  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00416e4b:
    // 00416e4b  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00416e4f  ded9                   -fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00416e51  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416e53  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 00416e56  7a5a                   -jp 0x416eb2
    if (cpu.flags.pf)
    {
        goto L_0x00416eb2;
    }
    // 00416e58  8b8194000000           -mov eax, dword ptr [ecx + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */);
    // 00416e5e  83e3f3                 -and ebx, 0xfffffff3
    cpu.ebx &= x86::reg32(x86::sreg32(4294967283 /*0xfffffff3*/));
    // 00416e61  898184000000           -mov dword ptr [ecx + 0x84], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 00416e67  8b8198000000           -mov eax, dword ptr [ecx + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 00416e6d  898188000000           -mov dword ptr [ecx + 0x88], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 00416e73  8b819c000000           -mov eax, dword ptr [ecx + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 00416e79  89818c000000           -mov dword ptr [ecx + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 00416e7f  8b81a0000000           -mov eax, dword ptr [ecx + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 00416e85  898190000000           -mov dword ptr [ecx + 0x90], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 00416e8b  8999c0000000           -mov dword ptr [ecx + 0xc0], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(192) /* 0xc0 */) = cpu.ebx;
    // 00416e91  8b0dc4c74a00           -mov ecx, dword ptr [0x4ac7c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900804) /* 0x4ac7c4 */);
    // 00416e97  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00416e99  a1c8c74a00             -mov eax, dword ptr [0x4ac7c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900808) /* 0x4ac7c8 */);
    // 00416e9e  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00416ea1  8b0dccc74a00           -mov ecx, dword ptr [0x4ac7cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900812) /* 0x4ac7cc */);
    // 00416ea7  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00416eaa  a1d0c74a00             -mov eax, dword ptr [0x4ac7d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900816) /* 0x4ac7d0 */);
    // 00416eaf  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00416eb2:
    // 00416eb2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00416eb3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00416eb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00416eb7:
    // 00416eb7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00416eb8  83c410                 +add esp, 0x10
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
    // 00416ebb  e900000000             -jmp 0x416ec0
    goto L_0x00416ec0;
L_0x00416ec0:
    // 00416ec0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00416ec3  8b81b4000000           -mov eax, dword ptr [ecx + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(180) /* 0xb4 */);
    // 00416ec9  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00416ecd  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00416ed1  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00416ed7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416ed9  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 00416edc  0f8be3000000           -jnp 0x416fc5
    if (!cpu.flags.pf)
    {
        goto L_0x00416fc5;
    }
    // 00416ee2  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00416ee6  d81d08754800           -fcomp dword ptr [0x487508]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748552) /* 0x487508 */)));
    cpu.fpu.pop();
    // 00416eec  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416eee  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 00416ef3  0f84cc000000           -je 0x416fc5
    if (cpu.flags.zf)
    {
        goto L_0x00416fc5;
    }
    // 00416ef9  d98194000000           -fld dword ptr [ecx + 0x94]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(148) /* 0x94 */)));
    // 00416eff  d8a184000000           -fsub dword ptr [ecx + 0x84]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(132) /* 0x84 */));
    // 00416f05  d84c2400               -fmul dword ptr [esp]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp));
    // 00416f09  d991a4000000           -fst dword ptr [ecx + 0xa4]
    app->getMemory<float>(cpu.ecx + x86::reg32(164) /* 0xa4 */) = float(cpu.fpu.st(0));
    // 00416f0f  d98198000000           -fld dword ptr [ecx + 0x98]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(152) /* 0x98 */)));
    // 00416f15  d8a188000000           -fsub dword ptr [ecx + 0x88]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(136) /* 0x88 */));
    // 00416f1b  d84c2400               -fmul dword ptr [esp]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp));
    // 00416f1f  d9542404               -fst dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    // 00416f23  d999a8000000           -fstp dword ptr [ecx + 0xa8]
    app->getMemory<float>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00416f29  d9819c000000           -fld dword ptr [ecx + 0x9c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(156) /* 0x9c */)));
    // 00416f2f  d8a18c000000           -fsub dword ptr [ecx + 0x8c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(140) /* 0x8c */));
    // 00416f35  d84c2400               -fmul dword ptr [esp]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp));
    // 00416f39  d9542408               -fst dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    // 00416f3d  d999ac000000           -fstp dword ptr [ecx + 0xac]
    app->getMemory<float>(cpu.ecx + x86::reg32(172) /* 0xac */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00416f43  d981a0000000           -fld dword ptr [ecx + 0xa0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(160) /* 0xa0 */)));
    // 00416f49  d8a190000000           -fsub dword ptr [ecx + 0x90]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(144) /* 0x90 */));
    // 00416f4f  d84c2400               -fmul dword ptr [esp]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp));
    // 00416f53  d95c2400               -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00416f57  8b542400               -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00416f5b  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00416f61  8991b0000000           -mov dword ptr [ecx + 0xb0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.edx;
    // 00416f67  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416f69  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00416f6c  7a45                   -jp 0x416fb3
    if (cpu.flags.pf)
    {
        goto L_0x00416fb3;
    }
    // 00416f6e  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00416f72  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00416f78  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416f7a  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00416f7d  7a34                   -jp 0x416fb3
    if (cpu.flags.pf)
    {
        goto L_0x00416fb3;
    }
    // 00416f7f  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00416f83  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00416f89  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416f8b  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00416f8e  7a23                   -jp 0x416fb3
    if (cpu.flags.pf)
    {
        goto L_0x00416fb3;
    }
    // 00416f90  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00416f94  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00416f9a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00416f9c  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00416f9f  7a12                   -jp 0x416fb3
    if (cpu.flags.pf)
    {
        goto L_0x00416fb3;
    }
    // 00416fa1  8b81c0000000           -mov eax, dword ptr [ecx + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(192) /* 0xc0 */);
    // 00416fa7  24f3                   -and al, 0xf3
    cpu.al &= x86::reg8(x86::sreg8(243 /*0xf3*/));
    // 00416fa9  8981c0000000           -mov dword ptr [ecx + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00416faf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00416fb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00416fb3:
    // 00416fb3  8b81c0000000           -mov eax, dword ptr [ecx + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(192) /* 0xc0 */);
    // 00416fb9  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00416fbb  8981c0000000           -mov dword ptr [ecx + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00416fc1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00416fc4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00416fc5:
    // 00416fc5  8d8194000000           -lea eax, [ecx + 0x94]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(148) /* 0x94 */);
    // 00416fcb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00416fcc  8d9184000000           -lea edx, [ecx + 0x84]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 00416fd2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00416fd4  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00416fd6  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00416fd9  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00416fdc  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00416fdf  897208                 -mov dword ptr [edx + 8], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00416fe2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00416fe3  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00416fe6  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00416fe9  8b81c0000000           -mov eax, dword ptr [ecx + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(192) /* 0xc0 */);
    // 00416fef  24f3                   -and al, 0xf3
    cpu.al &= x86::reg8(x86::sreg8(243 /*0xf3*/));
    // 00416ff1  8981c0000000           -mov dword ptr [ecx + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00416ff7  8b15b4c74a00           -mov edx, dword ptr [0x4ac7b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900788) /* 0x4ac7b4 */);
    // 00416ffd  81c1a4000000           -add ecx, 0xa4
    (cpu.ecx) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 00417003  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00417005  a1b8c74a00             -mov eax, dword ptr [0x4ac7b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900792) /* 0x4ac7b8 */);
    // 0041700a  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041700d  8b15bcc74a00           -mov edx, dword ptr [0x4ac7bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900796) /* 0x4ac7bc */);
    // 00417013  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00417016  a1c0c74a00             -mov eax, dword ptr [0x4ac7c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900800) /* 0x4ac7c0 */);
    // 0041701b  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041701e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00417021  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417030  f682c000000001         +test byte ptr [edx + 0xc0], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(192) /* 0xc0 */) & 1 /*0x1*/));
    // 00417037  7412                   -je 0x41704b
    if (cpu.flags.zf)
    {
        goto L_0x0041704b;
    }
    // 00417039  d98290000000           -fld dword ptr [edx + 0x90]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(144) /* 0x90 */)));
    // 0041703f  d85924                 -fcomp dword ptr [ecx + 0x24]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
    cpu.fpu.pop();
    // 00417042  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00417044  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00417049  750f                   -jne 0x41705a
    if (!cpu.flags.zf)
    {
        goto L_0x0041705a;
    }
L_0x0041704b:
    // 0041704b  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 0041704e  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00417050  898290000000           -mov dword ptr [edx + 0x90], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 00417056  894a50                 -mov dword ptr [edx + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 00417059  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041705a:
    // 0041705a  8b8290000000           -mov eax, dword ptr [edx + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(144) /* 0x90 */);
    // 00417060  894250                 -mov dword ptr [edx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00417063  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417070  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00417073  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 00417076  7432                   -je 0x4170aa
    if (cpu.flags.zf)
    {
        goto L_0x004170aa;
    }
    // 00417078  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 0041707b  7406                   -je 0x417083
    if (cpu.flags.zf)
    {
        goto L_0x00417083;
    }
    // 0041707d  83e2f7                 -and edx, 0xfffffff7
    cpu.edx &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/));
    // 00417080  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
L_0x00417083:
    // 00417083  d94124                 -fld dword ptr [ecx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
    // 00417086  d805bc764800           -fadd dword ptr [0x4876bc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748988) /* 0x4876bc */));
    // 0041708c  d95124                 -fst dword ptr [ecx + 0x24]
    app->getMemory<float>(cpu.ecx + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    // 0041708f  d85920                 -fcomp dword ptr [ecx + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 00417092  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00417094  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 00417099  7573                   -jne 0x41710e
    if (!cpu.flags.zf)
    {
        goto L_0x0041710e;
    }
    // 0041709b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0041709e  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004170a1  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004170a4  24e7                   -and al, 0xe7
    cpu.al &= x86::reg8(x86::sreg8(231 /*0xe7*/));
    // 004170a6  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004170a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004170aa:
    // 004170aa  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 004170ad  745f                   -je 0x41710e
    if (cpu.flags.zf)
    {
        goto L_0x0041710e;
    }
    // 004170af  d94120                 -fld dword ptr [ecx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
    // 004170b2  d81db8764800           -fcomp dword ptr [0x4876b8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748984) /* 0x4876b8 */)));
    cpu.fpu.pop();
    // 004170b8  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004170ba  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 004170bf  750b                   -jne 0x4170cc
    if (!cpu.flags.zf)
    {
        goto L_0x004170cc;
    }
    // 004170c1  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 004170c4  7406                   -je 0x4170cc
    if (cpu.flags.zf)
    {
        goto L_0x004170cc;
    }
    // 004170c6  83e2f7                 -and edx, 0xfffffff7
    cpu.edx &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/));
    // 004170c9  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
L_0x004170cc:
    // 004170cc  d94124                 -fld dword ptr [ecx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(36) /* 0x24 */)));
    // 004170cf  d825bc764800           -fsub dword ptr [0x4876bc]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748988) /* 0x4876bc */));
    // 004170d5  d95124                 -fst dword ptr [ecx + 0x24]
    app->getMemory<float>(cpu.ecx + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    // 004170d8  d85920                 -fcomp dword ptr [ecx + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 004170db  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004170dd  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 004170e0  7b06                   -jnp 0x4170e8
    if (!cpu.flags.pf)
    {
        goto L_0x004170e8;
    }
    // 004170e2  f6411c08               +test byte ptr [ecx + 0x1c], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(28) /* 0x1c */) & 8 /*0x8*/));
    // 004170e6  7426                   -je 0x41710e
    if (cpu.flags.zf)
    {
        goto L_0x0041710e;
    }
L_0x004170e8:
    // 004170e8  d94120                 -fld dword ptr [ecx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
    // 004170eb  d81d80764800           -fcomp dword ptr [0x487680]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748928) /* 0x487680 */)));
    cpu.fpu.pop();
    // 004170f1  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004170f4  895124                 -mov dword ptr [ecx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004170f7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004170f9  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 004170fc  7a08                   -jp 0x417106
    if (cpu.flags.pf)
    {
        goto L_0x00417106;
    }
    // 004170fe  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00417101  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00417103  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00417106:
    // 00417106  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00417109  24df                   -and al, 0xdf
    cpu.al &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 0041710b  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x0041710e:
    // 0041710e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417110  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00417112  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00417114  7402                   -je 0x417118
    if (cpu.flags.zf)
    {
        goto L_0x00417118;
    }
    // 00417116  ffe0                   -jmp eax
    return app->dynamic_call(cpu.eax, cpu);
L_0x00417118:
    // 00417118  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417120  a148845100             -mov eax, dword ptr [0x518448]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 00417125  8b1510fd4800           -mov edx, dword ptr [0x48fd10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783376) /* 0x48fd10 */);
    // 0041712b  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041712d  83f802                 +cmp eax, 2
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
    // 00417130  7e05                   -jle 0x417137
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00417137;
    }
    // 00417132  e8394e0000             -call 0x41bf70
    cpu.esp -= 4;
    sub_41bf70(app, cpu);
L_0x00417137:
    // 00417137  8b0d48845100           -mov ecx, dword ptr [0x518448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342280) /* 0x518448 */);
    // 0041713d  890d10fd4800           -mov dword ptr [0x48fd10], ecx
    app->getMemory<x86::reg32>(x86::reg32(4783376) /* 0x48fd10 */) = cpu.ecx;
    // 00417143  e858daffff             -call 0x414ba0
    cpu.esp -= 4;
    sub_414ba0(app, cpu);
    // 00417148  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041714a  7405                   -je 0x417151
    if (cpu.flags.zf)
    {
        goto L_0x00417151;
    }
    // 0041714c  e80f000000             -call 0x417160
    cpu.esp -= 4;
    sub_417160(app, cpu);
L_0x00417151:
    // 00417151  e82af8ffff             -call 0x416980
    cpu.esp -= 4;
    sub_416980(app, cpu);
    // 00417156  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00417158  e9b3f8ffff             -jmp 0x416a10
    return sub_416a10(app, cpu);
}

/* align: skip  */
void Application::asm_sub_417160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417160  b904fd4800             -mov ecx, 0x48fd04
    cpu.ecx = 4783364 /*0x48fd04*/;
    // 00417165  e9a6f8ffff             -jmp 0x416a10
    return sub_416a10(app, cpu);
}

/* align: skip  */
void Application::asm_sub_417170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417170  e85b480000             -call 0x41b9d0
    cpu.esp -= 4;
    sub_41b9d0(app, cpu);
    // 00417175  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 0041717a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041717c  750a                   -jne 0x417188
    if (!cpu.flags.zf)
    {
        goto L_0x00417188;
    }
    // 0041717e  e82de1ffff             -call 0x4152b0
    cpu.esp -= 4;
    sub_4152b0(app, cpu);
    // 00417183  a388c74a00             -mov dword ptr [0x4ac788], eax
    app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */) = cpu.eax;
L_0x00417188:
    // 00417188  e813000000             -call 0x4171a0
    cpu.esp -= 4;
    sub_4171a0(app, cpu);
    // 0041718d  e87e000000             -call 0x417210
    cpu.esp -= 4;
    sub_417210(app, cpu);
    // 00417192  e919010000             -jmp 0x4172b0
    return sub_4172b0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4171a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004171a0  a14c845100             -mov eax, dword ptr [0x51844c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342284) /* 0x51844c */);
    // 004171a5  8b0dc4e54900           -mov ecx, dword ptr [0x49e5c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4842948) /* 0x49e5c4 */);
    // 004171ab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004171ac  8b1488                 -mov edx, dword ptr [eax + ecx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 004171af  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004171b5  8b8280000000           -mov eax, dword ptr [edx + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 004171bb  8b1588c74a00           -mov edx, dword ptr [0x4ac788]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 004171c1  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004171c4  898218180000           -mov dword ptr [edx + 0x1818], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6168) /* 0x1818 */) = cpu.eax;
    // 004171ca  8b88e8020000           -mov ecx, dword ptr [eax + 0x2e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(744) /* 0x2e8 */);
    // 004171d0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004171d2  7419                   -je 0x4171ed
    if (cpu.flags.zf)
    {
        goto L_0x004171ed;
    }
    // 004171d4  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
L_0x004171d6:
    // 004171d6  8bb0ec020000           -mov esi, dword ptr [eax + 0x2ec]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 004171dc  84564a                 -test byte ptr [esi + 0x4a], dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(74) /* 0x4a */) & cpu.dl));
    // 004171df  750c                   -jne 0x4171ed
    if (!cpu.flags.zf)
    {
        goto L_0x004171ed;
    }
    // 004171e1  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004171e3  8b88e8020000           -mov ecx, dword ptr [eax + 0x2e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(744) /* 0x2e8 */);
    // 004171e9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004171eb  75e9                   -jne 0x4171d6
    if (!cpu.flags.zf)
    {
        goto L_0x004171d6;
    }
L_0x004171ed:
    // 004171ed  8b1588c74a00           -mov edx, dword ptr [0x4ac788]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 004171f3  8b88ec020000           -mov ecx, dword ptr [eax + 0x2ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 004171f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004171fa  898a14180000           -mov dword ptr [edx + 0x1814], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6164) /* 0x1814 */) = cpu.ecx;
    // 00417200  8b0d88c74a00           -mov ecx, dword ptr [0x4ac788]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00417206  898118180000           -mov dword ptr [ecx + 0x1818], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6168) /* 0x1818 */) = cpu.eax;
    // 0041720c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00417210  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 00417215  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00417217  746b                   -je 0x417284
    if (cpu.flags.zf)
    {
        goto L_0x00417284;
    }
    // 00417219  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041721c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041721e  7464                   -je 0x417284
    if (cpu.flags.zf)
    {
        goto L_0x00417284;
    }
    // 00417220  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00417226  48                     -dec eax
    (cpu.eax)--;
    // 00417227  83f816                 +cmp eax, 0x16
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
    // 0041722a  772d                   -ja 0x417259
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00417259;
    }
    // 0041722c  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0041722e  8a8898724100           -mov cl, byte ptr [eax + 0x417298]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4289176) /* 0x417298 */);
    // 00417234  ff248d88724100         -jmp dword ptr [ecx*4 + 0x417288]
    cpu.ip = app->getMemory<x86::reg32>(4289160 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0041723b:
    // 0041723b  b9fcfb4800             -mov ecx, 0x48fbfc
    cpu.ecx = 4783100 /*0x48fbfc*/;
    // 00417240  e9cbf7ffff             -jmp 0x416a10
    return sub_416a10(app, cpu);
  case 0x00417245:
    // 00417245  b9b8fb4800             -mov ecx, 0x48fbb8
    cpu.ecx = 4783032 /*0x48fbb8*/;
    // 0041724a  e9c1f7ffff             -jmp 0x416a10
    return sub_416a10(app, cpu);
  case 0x0041724f:
    // 0041724f  b9dcfb4800             -mov ecx, 0x48fbdc
    cpu.ecx = 4783068 /*0x48fbdc*/;
    // 00417254  e9b7f7ffff             -jmp 0x416a10
    return sub_416a10(app, cpu);
  case 0x00417259:
L_0x00417259:
    // 00417259  833d90c74a0001         +cmp dword ptr [0x4ac790], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4900752) /* 0x4ac790 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00417260  750a                   -jne 0x41726c
    if (!cpu.flags.zf)
    {
        goto L_0x0041726c;
    }
    // 00417262  b990fc4800             -mov ecx, 0x48fc90
    cpu.ecx = 4783248 /*0x48fc90*/;
    // 00417267  e9a4f7ffff             -jmp 0x416a10
    return sub_416a10(app, cpu);
L_0x0041726c:
    // 0041726c  a18cd34a00             -mov eax, dword ptr [0x4ad38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903820) /* 0x4ad38c */);
    // 00417271  b958fb4800             -mov ecx, 0x48fb58
    cpu.ecx = 4782936 /*0x48fb58*/;
    // 00417276  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00417278  7405                   -je 0x41727f
    if (cpu.flags.zf)
    {
        goto L_0x0041727f;
    }
    // 0041727a  b984fb4800             -mov ecx, 0x48fb84
    cpu.ecx = 4782980 /*0x48fb84*/;
L_0x0041727f:
    // 0041727f  e98cf7ffff             -jmp 0x416a10
    return sub_416a10(app, cpu);
L_0x00417284:
    // 00417284  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_4172b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004172b0  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 004172b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004172b6  8db0f0030000           -lea esi, [eax + 0x3f0]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1008) /* 0x3f0 */);
    // 004172bc  8b800c040000           -mov eax, dword ptr [eax + 0x40c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1036) /* 0x40c */);
    // 004172c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004172c4  7416                   -je 0x4172dc
    if (cpu.flags.zf)
    {
        goto L_0x004172dc;
    }
    // 004172c6  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004172c8  e843feffff             -call 0x417110
    cpu.esp -= 4;
    sub_417110(app, cpu);
    // 004172cd  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004172d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004172d2  7408                   -je 0x4172dc
    if (cpu.flags.zf)
    {
        goto L_0x004172dc;
    }
    // 004172d4  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004172d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004172d7  e994f7ffff             -jmp 0x416a70
    return sub_416a70(app, cpu);
L_0x004172dc:
    // 004172dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004172dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4172e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004172e0  e82b7dffff             -call 0x40f010
    cpu.esp -= 4;
    sub_40f010(app, cpu);
    // 004172e5  a1c8f84800             -mov eax, dword ptr [0x48f8c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4782280) /* 0x48f8c8 */);
    // 004172ea  8b0dc4f84800           -mov ecx, dword ptr [0x48f8c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4782276) /* 0x48f8c4 */);
    // 004172f0  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 004172f2  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 004172f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004172f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004172f6  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004172f8  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004172fa  e8f173ffff             -call 0x40e6f0
    cpu.esp -= 4;
    sub_40e6f0(app, cpu);
    // 004172ff  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00417304  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00417306  741b                   -je 0x417323
    if (cpu.flags.zf)
    {
        goto L_0x00417323;
    }
    // 00417308  c7800018000001000000   -mov dword ptr [eax + 0x1800], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6144) /* 0x1800 */) = 1 /*0x1*/;
    // 00417312  8b1588c74a00           -mov edx, dword ptr [0x4ac788]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00417318  8d8a00090000           -lea ecx, [edx + 0x900]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(2304) /* 0x900 */);
    // 0041731e  e92d460000             -jmp 0x41b950
    return sub_41b950(app, cpu);
L_0x00417323:
    // 00417323  680c064900             -push 0x49060c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785676 /*0x49060c*/;
    cpu.esp -= 4;
    // 00417328  e8e3d80000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041732d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041732e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417330  e89b460000             -call 0x41b9d0
    cpu.esp -= 4;
    sub_41b9d0(app, cpu);
    // 00417335  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 0041733a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041733c  750a                   -jne 0x417348
    if (!cpu.flags.zf)
    {
        goto L_0x00417348;
    }
    // 0041733e  e86ddfffff             -call 0x4152b0
    cpu.esp -= 4;
    sub_4152b0(app, cpu);
    // 00417343  a388c74a00             -mov dword ptr [0x4ac788], eax
    app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */) = cpu.eax;
L_0x00417348:
    // 00417348  833d14fd4800ff         +cmp dword ptr [0x48fd14], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4783380) /* 0x48fd14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041734f  7447                   -je 0x417398
    if (cpu.flags.zf)
    {
        goto L_0x00417398;
    }
    // 00417351  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00417352  b814fd4800             -mov eax, 0x48fd14
    cpu.eax = 4783380 /*0x48fd14*/;
    // 00417357  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00417358  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0041735a:
    // 0041735a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0041735c  8b0d88c74a00           -mov ecx, dword ptr [0x4ac788]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00417362  8d3440                 -lea esi, [eax + eax*2]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00417365  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00417368  03f1                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041736a  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041736d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041736f  7418                   -je 0x417389
    if (cpu.flags.zf)
    {
        goto L_0x00417389;
    }
    // 00417371  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00417373  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00417375  7404                   -je 0x41737b
    if (cpu.flags.zf)
    {
        goto L_0x0041737b;
    }
    // 00417377  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00417379  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0041737b:
    // 0041737b  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0041737e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00417380  7407                   -je 0x417389
    if (cpu.flags.zf)
    {
        goto L_0x00417389;
    }
    // 00417382  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00417384  e8e7f6ffff             -call 0x416a70
    cpu.esp -= 4;
    sub_416a70(app, cpu);
L_0x00417389:
    // 00417389  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0041738c  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041738f  83f9ff                 +cmp ecx, -1
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
    // 00417392  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00417394  75c4                   -jne 0x41735a
    if (!cpu.flags.zf)
    {
        goto L_0x0041735a;
    }
    // 00417396  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417397  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00417398:
    // 00417398  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4173a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004173a0  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 004173a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004173a7  750a                   -jne 0x4173b3
    if (!cpu.flags.zf)
    {
        goto L_0x004173b3;
    }
    // 004173a9  e802dfffff             -call 0x4152b0
    cpu.esp -= 4;
    sub_4152b0(app, cpu);
    // 004173ae  a388c74a00             -mov dword ptr [0x4ac788], eax
    app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */) = cpu.eax;
L_0x004173b3:
    // 004173b3  833d20fd4800ff         +cmp dword ptr [0x48fd20], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4783392) /* 0x48fd20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004173ba  7447                   -je 0x417403
    if (cpu.flags.zf)
    {
        goto L_0x00417403;
    }
    // 004173bc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004173bd  b820fd4800             -mov eax, 0x48fd20
    cpu.eax = 4783392 /*0x48fd20*/;
    // 004173c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004173c3  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004173c5:
    // 004173c5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004173c7  8b0d88c74a00           -mov ecx, dword ptr [0x4ac788]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 004173cd  8d3440                 -lea esi, [eax + eax*2]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 2);
    // 004173d0  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004173d3  03f1                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004173d5  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004173d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004173da  7418                   -je 0x4173f4
    if (cpu.flags.zf)
    {
        goto L_0x004173f4;
    }
    // 004173dc  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004173de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004173e0  7404                   -je 0x4173e6
    if (cpu.flags.zf)
    {
        goto L_0x004173e6;
    }
    // 004173e2  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004173e4  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004173e6:
    // 004173e6  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004173e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004173eb  7407                   -je 0x4173f4
    if (cpu.flags.zf)
    {
        goto L_0x004173f4;
    }
    // 004173ed  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004173ef  e87cf6ffff             -call 0x416a70
    cpu.esp -= 4;
    sub_416a70(app, cpu);
L_0x004173f4:
    // 004173f4  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004173f7  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004173fa  83f9ff                 +cmp ecx, -1
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
    // 004173fd  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004173ff  75c4                   -jne 0x4173c5
    if (!cpu.flags.zf)
    {
        goto L_0x004173c5;
    }
    // 00417401  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417402  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00417403:
    // 00417403  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417410  e80b000000             -call 0x417420
    cpu.esp -= 4;
    sub_417420(app, cpu);
    // 00417415  8b80cc000000           -mov eax, dword ptr [eax + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */);
    // 0041741b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417420  8d0449                 -lea eax, [ecx + ecx*2]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00417423  8b0d88c74a00           -mov ecx, dword ptr [0x4ac788]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00417429  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041742c  8b440828               -mov eax, dword ptr [eax + ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */ + cpu.ecx * 1);
    // 00417430  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417440  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00417445  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00417447  7501                   -jne 0x41744a
    if (!cpu.flags.zf)
    {
        goto L_0x0041744a;
    }
    // 00417449  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041744a:
    // 0041744a  8b8000180000           -mov eax, dword ptr [eax + 0x1800]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6144) /* 0x1800 */);
    // 00417450  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417460  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00417465  8b8028090000           -mov eax, dword ptr [eax + 0x928]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2344) /* 0x928 */);
    // 0041746b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041746d  7434                   -je 0x4174a3
    if (cpu.flags.zf)
    {
        goto L_0x004174a3;
    }
    // 0041746f  8b88cc000000           -mov ecx, dword ptr [eax + 0xcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */);
    // 00417475  83f906                 +cmp ecx, 6
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
    // 00417478  741d                   -je 0x417497
    if (cpu.flags.zf)
    {
        goto L_0x00417497;
    }
    // 0041747a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041747c  7419                   -je 0x417497
    if (cpu.flags.zf)
    {
        goto L_0x00417497;
    }
    // 0041747e  83f907                 +cmp ecx, 7
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00417481  7414                   -je 0x417497
    if (cpu.flags.zf)
    {
        goto L_0x00417497;
    }
    // 00417483  c780cc00000006000000   -mov dword ptr [eax + 0xcc], 6
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = 6 /*0x6*/;
    // 0041748d  c780c400000000000000   -mov dword ptr [eax + 0xc4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = 0 /*0x0*/;
L_0x00417497:
    // 00417497  e8f471ffff             -call 0x40e690
    cpu.esp -= 4;
    sub_40e690(app, cpu);
    // 0041749c  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041749e  e9dd6fffff             -jmp 0x40e480
    return sub_40e480(app, cpu);
L_0x004174a3:
    // 004174a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4174b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004174b0  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004174b3  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 004174b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004174b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004174ba  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004174bc  8bb80c180000           -mov edi, dword ptr [eax + 0x180c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6156) /* 0x180c */);
    // 004174c2  8b8010180000           -mov eax, dword ptr [eax + 0x1810]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6160) /* 0x1810 */);
    // 004174c8  8b96bc000000           -mov edx, dword ptr [esi + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 004174ce  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004174d2  8b466c                 -mov eax, dword ptr [esi + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(108) /* 0x6c */);
    // 004174d5  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004174d9  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004174db  7409                   -je 0x4174e6
    if (cpu.flags.zf)
    {
        goto L_0x004174e6;
    }
    // 004174dd  8b7e68                 -mov edi, dword ptr [esi + 0x68]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */);
    // 004174e0  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004174e4  eb08                   -jmp 0x4174ee
    goto L_0x004174ee;
L_0x004174e6:
    // 004174e6  c744240c0000803f       -mov dword ptr [esp + 0xc], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 1065353216 /*0x3f800000*/;
L_0x004174ee:
    // 004174ee  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004174f0  7405                   -je 0x4174f7
    if (cpu.flags.zf)
    {
        goto L_0x004174f7;
    }
    // 004174f2  d94668                 +fld dword ptr [esi + 0x68]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(104) /* 0x68 */)));
    // 004174f5  eb06                   -jmp 0x4174fd
    goto L_0x004174fd;
L_0x004174f7:
    // 004174f7  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
L_0x004174fd:
    // 004174fd  d94670                 -fld dword ptr [esi + 0x70]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(112) /* 0x70 */)));
    // 00417500  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00417506  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00417508  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041750a  0f844d010000           -je 0x41765d
    if (cpu.flags.zf)
    {
        goto L_0x0041765d;
    }
    // 00417510  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00417513  8d0452                 -lea eax, [edx + edx*2]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 2);
    // 00417516  7a7b                   -jp 0x417593
    if (cpu.flags.pf)
    {
        goto L_0x00417593;
    }
    // 00417518  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041751b  db8034d74800           -fild dword ptr [eax + 0x48d734]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773684) /* 0x48d734 */))));
    // 00417521  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 00417525  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00417529  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041752d  da8838d74800           -fimul dword ptr [eax + 0x48d738]
    cpu.fpu.st(0) *= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773688) /* 0x48d738 */)));
    // 00417533  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 00417537  db4660                 -fild dword ptr [esi + 0x60]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */))));
    // 0041753a  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0041753e  da4104                 -fiadd dword ptr [ecx + 4]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 00417541  db4664                 -fild dword ptr [esi + 0x64]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */))));
    // 00417544  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 00417548  da4108                 -fiadd dword ptr [ecx + 8]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
L_0x0041754b:
    // 0041754b  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041754f  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00417551  e83af80500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00417556  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0041755a  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041755d  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00417560  e82bf80500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00417565  d844240c               -fadd dword ptr [esp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 00417569  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0041756c  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0041756f  e81cf80500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00417574  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00417578  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0041757a  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041757d  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00417580  e80bf80500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00417585  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00417588  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0041758b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041758c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041758d  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041758f  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00417592  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00417593:
    // 00417593  db4660                 -fild dword ptr [esi + 0x60]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */))));
    // 00417596  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00417599  8d7e14                 -lea edi, [esi + 0x14]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0041759c  c744242400000000       -mov dword ptr [esp + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004175a4  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004175a8  da4104                 -fiadd dword ptr [ecx + 4]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004175ab  c744242800000000       -mov dword ptr [esp + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004175b3  d95c2420               -fstp dword ptr [esp + 0x20]
    app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004175b7  db4664                 -fild dword ptr [esi + 0x64]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */))));
    // 004175ba  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 004175be  da4108                 -fiadd dword ptr [ecx + 8]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 004175c1  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004175c5  d94670                 -fld dword ptr [esi + 0x70]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(112) /* 0x70 */)));
    // 004175c8  d9ff                   -fcos 
    cpu.fpu.st(0) = cpu.fpu.cos(cpu.fpu.st(0));
    // 004175ca  d95c241c               -fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004175ce  d94670                 -fld dword ptr [esi + 0x70]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(112) /* 0x70 */)));
    // 004175d1  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 004175d3  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004175d5  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004175d9  da8838d74800           -fimul dword ptr [eax + 0x48d738]
    cpu.fpu.st(0) *= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773688) /* 0x48d738 */)));
    // 004175df  d80db4754800           -fmul dword ptr [0x4875b4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748724) /* 0x4875b4 */));
    // 004175e5  d9542438               -fst dword ptr [esp + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    // 004175e9  d954243c               -fst dword ptr [esp + 0x3c]
    app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */) = float(cpu.fpu.st(0));
    // 004175ed  db8034d74800           -fild dword ptr [eax + 0x48d734]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773684) /* 0x48d734 */))));
    // 004175f3  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004175f7  d954242c               -fst dword ptr [esp + 0x2c]
    app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    // 004175fb  d95c2430               -fstp dword ptr [esp + 0x30]
    app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004175ff  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00417601  d9542434               -fst dword ptr [esp + 0x34]
    app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    // 00417605  d95c2440               -fstp dword ptr [esp + 0x40]
    app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00417609:
    // 00417609  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0041760d  d84c3430               -fmul dword ptr [esp + esi + 0x30]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */ + cpu.esi * 1));
    // 00417611  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00417615  d84c3440               -fmul dword ptr [esp + esi + 0x40]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.esi * 1));
    // 00417619  83ee04                 -sub esi, 4
    (cpu.esi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041761c  83ef04                 -sub edi, 4
    (cpu.edi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041761f  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00417621  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00417625  d8442420               -fadd dword ptr [esp + 0x20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 00417629  e862f70500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0041762e  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00417632  d84c3434               -fmul dword ptr [esp + esi + 0x34]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */ + cpu.esi * 1));
    // 00417636  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0041763a  d84c3444               -fmul dword ptr [esp + esi + 0x44]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.esi * 1));
    // 0041763e  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00417640  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00417642  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 00417646  d8442408               -fadd dword ptr [esp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0041764a  e841f70500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0041764f  83fef0                 +cmp esi, -0x10
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-16 /*-0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00417652  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00417655  75b2                   -jne 0x417609
    if (!cpu.flags.zf)
    {
        goto L_0x00417609;
    }
    // 00417657  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417658  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417659  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0041765c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041765d:
    // 0041765d  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00417660  8d0452                 -lea eax, [edx + edx*2]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 2);
    // 00417663  7a4e                   -jp 0x4176b3
    if (cpu.flags.pf)
    {
        goto L_0x004176b3;
    }
    // 00417665  c1e004                 +shl eax, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.eax);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00417668  db8034d74800           +fild dword ptr [eax + 0x48d734]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773684) /* 0x48d734 */))));
    // 0041766e  d84c240c               +fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 00417672  d84c2410               +fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00417676  d95c240c               +fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041767a  da8838d74800           +fimul dword ptr [eax + 0x48d738]
    cpu.fpu.st(0) *= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773688) /* 0x48d738 */)));
    // 00417680  d84c2414               +fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 00417684  db4660                 +fild dword ptr [esi + 0x60]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */))));
    // 00417687  d84c2410               +fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0041768b  da4104                 +fiadd dword ptr [ecx + 4]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0041768e  d944240c               +fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00417692  d80db4754800           +fmul dword ptr [0x4875b4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748724) /* 0x4875b4 */));
    // 00417698  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0041769a  db4664                 +fild dword ptr [esi + 0x64]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */))));
    // 0041769d  d84c2414               +fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 004176a1  da4108                 +fiadd dword ptr [ecx + 8]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 004176a4  d9c2                   +fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 004176a6  d80db4754800           +fmul dword ptr [0x4875b4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748724) /* 0x4875b4 */));
    // 004176ac  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004176ae  e998feffff             -jmp 0x41754b
    goto L_0x0041754b;
L_0x004176b3:
    // 004176b3  db4660                 -fild dword ptr [esi + 0x60]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */))));
    // 004176b6  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004176b9  8d7e14                 -lea edi, [esi + 0x14]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004176bc  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004176c0  da4104                 -fiadd dword ptr [ecx + 4]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004176c3  d95c2420               -fstp dword ptr [esp + 0x20]
    app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004176c7  db4664                 -fild dword ptr [esi + 0x64]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */))));
    // 004176ca  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 004176ce  da4108                 -fiadd dword ptr [ecx + 8]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 004176d1  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004176d5  d94670                 -fld dword ptr [esi + 0x70]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(112) /* 0x70 */)));
    // 004176d8  d9ff                   -fcos 
    cpu.fpu.st(0) = cpu.fpu.cos(cpu.fpu.st(0));
    // 004176da  d95c241c               -fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004176de  d94670                 -fld dword ptr [esi + 0x70]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(112) /* 0x70 */)));
    // 004176e1  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 004176e3  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004176e5  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004176e9  db8034d74800           -fild dword ptr [eax + 0x48d734]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773684) /* 0x48d734 */))));
    // 004176ef  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 004176f3  d80db4754800           -fmul dword ptr [0x4875b4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748724) /* 0x4875b4 */));
    // 004176f9  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004176fd  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00417701  da8838d74800           -fimul dword ptr [eax + 0x48d738]
    cpu.fpu.st(0) *= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773688) /* 0x48d738 */)));
    // 00417707  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00417709  894c243c               -mov dword ptr [esp + 0x3c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ecx;
    // 0041770d  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 00417711  d80db4754800           -fmul dword ptr [0x4875b4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748724) /* 0x4875b4 */));
    // 00417717  d9542428               -fst dword ptr [esp + 0x28]
    app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    // 0041771b  d954242c               -fst dword ptr [esp + 0x2c]
    app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    // 0041771f  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00417721  d9542424               -fst dword ptr [esp + 0x24]
    app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    // 00417725  d95c2430               -fstp dword ptr [esp + 0x30]
    app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417729  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0041772d  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0041772f  d9542434               -fst dword ptr [esp + 0x34]
    app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    // 00417733  d95c2438               -fstp dword ptr [esp + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00417737:
    // 00417737  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0041773b  d84c3440               -fmul dword ptr [esp + esi + 0x40]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.esi * 1));
    // 0041773f  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00417743  d84c3430               -fmul dword ptr [esp + esi + 0x30]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */ + cpu.esi * 1));
    // 00417747  83ee04                 -sub esi, 4
    (cpu.esi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041774a  83ef04                 -sub edi, 4
    (cpu.edi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041774d  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0041774f  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00417753  d8442420               -fadd dword ptr [esp + 0x20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 00417757  e834f60500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0041775c  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00417760  d84c3444               -fmul dword ptr [esp + esi + 0x44]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.esi * 1));
    // 00417764  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 00417768  d84c3434               -fmul dword ptr [esp + esi + 0x34]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */ + cpu.esi * 1));
    // 0041776c  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0041776e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00417770  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 00417774  d8442408               -fadd dword ptr [esp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00417778  e813f60500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0041777d  83fef0                 +cmp esi, -0x10
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-16 /*-0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00417780  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00417783  75b2                   -jne 0x417737
    if (!cpu.flags.zf)
    {
        goto L_0x00417737;
    }
    // 00417785  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417786  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417787  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0041778a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417790  f6416c18               +test byte ptr [ecx + 0x6c], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(108) /* 0x6c */) & 24 /*0x18*/));
    // 00417794  7569                   -jne 0x4177ff
    if (!cpu.flags.zf)
    {
        goto L_0x004177ff;
    }
    // 00417796  8b81bc000000           -mov eax, dword ptr [ecx + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */);
    // 0041779c  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041779f  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 004177a5  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 004177a8  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004177ab  d8b050d74800           -fdiv dword ptr [eax + 0x48d750]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */));
    // 004177b1  8b9054d74800           -mov edx, dword ptr [eax + 0x48d754]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */);
    // 004177b7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004177b8  8b9050d74800           -mov edx, dword ptr [eax + 0x48d750]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */);
    // 004177be  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004177bf  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004177c2  d90594744800           +fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 004177c8  d8b054d74800           +fdiv dword ptr [eax + 0x48d754]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */));
    // 004177ce  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004177d0  d88848d74800           +fmul dword ptr [eax + 0x48d748]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773704) /* 0x48d748 */));
    // 004177d6  d95c240c               +fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004177da  d9c1                   +fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 004177dc  d88844d74800           +fmul dword ptr [eax + 0x48d744]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773700) /* 0x48d744 */));
    // 004177e2  d95c2408               +fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004177e6  d88840d74800           +fmul dword ptr [eax + 0x48d740]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773696) /* 0x48d740 */));
    // 004177ec  d95c2404               +fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004177f0  d8883cd74800           +fmul dword ptr [eax + 0x48d73c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773692) /* 0x48d73c */));
    // 004177f6  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004177f9  e812000000             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 004177fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004177ff:
    // 004177ff  e96c000000             -jmp 0x417870
    return sub_417870(app, cpu);
}

/* align: skip  */
void Application::asm_sub_417810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417810  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 00417816  d8742414               -fdiv dword ptr [esp + 0x14]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0041781a  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 00417820  d8742418               -fdiv dword ptr [esp + 0x18]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 00417824  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417828  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0041782c  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0041782e  d95120                 -fst dword ptr [ecx + 0x20]
    app->getMemory<float>(cpu.ecx + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    // 00417831  d95924                 -fstp dword ptr [ecx + 0x24]
    app->getMemory<float>(cpu.ecx + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417834  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00417838  d8442408               -fadd dword ptr [esp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0041783c  d95130                 -fst dword ptr [ecx + 0x30]
    app->getMemory<float>(cpu.ecx + x86::reg32(48) /* 0x30 */) = float(cpu.fpu.st(0));
    // 0041783f  d9593c                 -fstp dword ptr [ecx + 0x3c]
    app->getMemory<float>(cpu.ecx + x86::reg32(60) /* 0x3c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417842  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00417846  d844240c               -fadd dword ptr [esp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 0041784a  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0041784c  d95128                 -fst dword ptr [ecx + 0x28]
    app->getMemory<float>(cpu.ecx + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    // 0041784f  d9592c                 -fstp dword ptr [ecx + 0x2c]
    app->getMemory<float>(cpu.ecx + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417852  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00417856  d8442410               -fadd dword ptr [esp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0041785a  d8642414               -fsub dword ptr [esp + 0x14]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0041785e  d95134                 -fst dword ptr [ecx + 0x34]
    app->getMemory<float>(cpu.ecx + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    // 00417861  d95938                 -fstp dword ptr [ecx + 0x38]
    app->getMemory<float>(cpu.ecx + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417864  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41786f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041786f  90                     -nop 
    ;
    return sub_417870(app, cpu);
}

/* align: skip  */
void Application::asm_sub_417870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417870  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00417873  8b81bc000000           -mov eax, dword ptr [ecx + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */);
    // 00417879  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 0041787f  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00417882  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00417885  d8b050d74800           -fdiv dword ptr [eax + 0x48d750]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */));
    // 0041788b  d95c2400               -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041788f  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 00417895  d8b054d74800           -fdiv dword ptr [eax + 0x48d754]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */));
    // 0041789b  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041789f  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004178a3  d8883cd74800           -fmul dword ptr [eax + 0x48d73c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773692) /* 0x48d73c */));
    // 004178a9  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004178ad  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004178b1  d88840d74800           -fmul dword ptr [eax + 0x48d740]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773696) /* 0x48d740 */));
    // 004178b7  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004178bb  d88844d74800           -fmul dword ptr [eax + 0x48d744]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773700) /* 0x48d744 */));
    // 004178c1  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004178c5  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004178c9  d88848d74800           -fmul dword ptr [eax + 0x48d748]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773704) /* 0x48d748 */));
    // 004178cf  8b416c                 -mov eax, dword ptr [ecx + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */);
    // 004178d2  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004178d4  7409                   -je 0x4178df
    if (cpu.flags.zf)
    {
        goto L_0x004178df;
    }
    // 004178d6  8b5168                 -mov edx, dword ptr [ecx + 0x68]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(104) /* 0x68 */);
    // 004178d9  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004178dd  eb08                   -jmp 0x4178e7
    goto L_0x004178e7;
L_0x004178df:
    // 004178df  c74424080000803f       -mov dword ptr [esp + 8], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1065353216 /*0x3f800000*/;
L_0x004178e7:
    // 004178e7  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004178e9  7405                   -je 0x4178f0
    if (cpu.flags.zf)
    {
        goto L_0x004178f0;
    }
    // 004178eb  d94168                 +fld dword ptr [ecx + 0x68]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(104) /* 0x68 */)));
    // 004178ee  eb06                   -jmp 0x4178f6
    goto L_0x004178f6;
L_0x004178f0:
    // 004178f0  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
L_0x004178f6:
    // 004178f6  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004178fa  d8442400               -fadd dword ptr [esp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp));
    // 004178fe  d95124                 -fst dword ptr [ecx + 0x24]
    app->getMemory<float>(cpu.ecx + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    // 00417901  d95928                 -fstp dword ptr [ecx + 0x28]
    app->getMemory<float>(cpu.ecx + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417904  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 00417906  d8442404               -fadd dword ptr [esp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 0041790a  d95134                 -fst dword ptr [ecx + 0x34]
    app->getMemory<float>(cpu.ecx + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    // 0041790d  d95940                 -fstp dword ptr [ecx + 0x40]
    app->getMemory<float>(cpu.ecx + x86::reg32(64) /* 0x40 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417910  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00417914  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00417918  d844240c               -fadd dword ptr [esp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 0041791c  d9512c                 -fst dword ptr [ecx + 0x2c]
    app->getMemory<float>(cpu.ecx + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    // 0041791f  d95930                 -fstp dword ptr [ecx + 0x30]
    app->getMemory<float>(cpu.ecx + x86::reg32(48) /* 0x30 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417922  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00417924  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00417926  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417928  d95138                 -fst dword ptr [ecx + 0x38]
    app->getMemory<float>(cpu.ecx + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    // 0041792b  d9593c                 -fstp dword ptr [ecx + 0x3c]
    app->getMemory<float>(cpu.ecx + x86::reg32(60) /* 0x3c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041792e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00417931  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417940  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00417941  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00417943  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00417944  b80000803f             -mov eax, 0x3f800000
    cpu.eax = 1065353216 /*0x3f800000*/;
    // 00417949  8b7328                 -mov esi, dword ptr [ebx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 0041794c  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041794e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041794f  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00417951  894668                 -mov dword ptr [esi + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00417954  89467c                 -mov dword ptr [esi + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 00417957  894678                 -mov dword ptr [esi + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0041795a  894674                 -mov dword ptr [esi + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 0041795d  898e80000000           -mov dword ptr [esi + 0x80], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */) = cpu.ecx;
    // 00417963  8b5674                 -mov edx, dword ptr [esi + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 00417966  8d8684000000           -lea eax, [esi + 0x84]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0041796c  c7466c03000000         -mov dword ptr [esi + 0x6c], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(108) /* 0x6c */) = 3 /*0x3*/;
    // 00417973  894e70                 -mov dword ptr [esi + 0x70], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */) = cpu.ecx;
    // 00417976  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00417978  8b5678                 -mov edx, dword ptr [esi + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0041797b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041797e  8b567c                 -mov edx, dword ptr [esi + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00417981  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00417984  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00417986  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00417989  8d047f                 -lea eax, [edi + edi*2]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 2);
    // 0041798c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041798f  8b902cd74800           -mov edx, dword ptr [eax + 0x48d72c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773676) /* 0x48d72c */);
    // 00417995  895660                 -mov dword ptr [esi + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 00417998  8b9030d74800           -mov edx, dword ptr [eax + 0x48d730]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773680) /* 0x48d730 */);
    // 0041799e  895664                 -mov dword ptr [esi + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 004179a1  89bebc000000           -mov dword ptr [esi + 0xbc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */) = cpu.edi;
    // 004179a7  8b904cd74800           -mov edx, dword ptr [eax + 0x48d74c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773708) /* 0x48d74c */);
    // 004179ad  898ecc000000           -mov dword ptr [esi + 0xcc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.ecx;
    // 004179b3  8996b8000000           -mov dword ptr [esi + 0xb8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */) = cpu.edx;
    // 004179b9  8b8028d74800           -mov eax, dword ptr [eax + 0x48d728]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773672) /* 0x48d728 */);
    // 004179bf  3808                   +cmp byte ptr [eax], cl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004179c1  741d                   -je 0x4179e0
    if (cpu.flags.zf)
    {
        goto L_0x004179e0;
    }
    // 004179c3  398eb8000000           +cmp dword ptr [esi + 0xb8], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004179c9  7515                   -jne 0x4179e0
    if (!cpu.flags.zf)
    {
        goto L_0x004179e0;
    }
    // 004179cb  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004179cd  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004179cf  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004179d5  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004179d7  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004179d9  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004179db  e810000000             -call 0x4179f0
    cpu.esp -= 4;
    sub_4179f0(app, cpu);
L_0x004179e0:
    // 004179e0  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004179e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004179e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004179e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004179e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4179f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004179f0  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004179f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004179f4  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004179f6  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 004179fc  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004179fe  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00417a01  c6425c00               -mov byte ptr [edx + 0x5c], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 00417a05  c7425800000000         -mov dword ptr [edx + 0x58], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */) = 0 /*0x0*/;
    // 00417a0c  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00417a0f  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00417a12  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00417a15  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00417a16  8bba90000000           -mov edi, dword ptr [edx + 0x90]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(144) /* 0x90 */);
    // 00417a1c  d8b050d74800           -fdiv dword ptr [eax + 0x48d750]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */));
    // 00417a22  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00417a24  d8883cd74800           -fmul dword ptr [eax + 0x48d73c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773692) /* 0x48d73c */));
    // 00417a2a  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417a2e  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 00417a34  d8b054d74800           -fdiv dword ptr [eax + 0x48d754]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */));
    // 00417a3a  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00417a3c  d88840d74800           -fmul dword ptr [eax + 0x48d740]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773696) /* 0x48d740 */));
    // 00417a42  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417a46  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00417a48  d88844d74800           -fmul dword ptr [eax + 0x48d744]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773700) /* 0x48d744 */));
    // 00417a4e  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417a52  d88848d74800           -fmul dword ptr [eax + 0x48d748]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4773704) /* 0x48d748 */));
    // 00417a58  89794c                 -mov dword ptr [ecx + 0x4c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = cpu.edi;
    // 00417a5b  8bba84000000           -mov edi, dword ptr [edx + 0x84]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */);
    // 00417a61  897940                 -mov dword ptr [ecx + 0x40], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.edi;
    // 00417a64  8bba88000000           -mov edi, dword ptr [edx + 0x88]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */);
    // 00417a6a  897944                 -mov dword ptr [ecx + 0x44], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.edi;
    // 00417a6d  8bba8c000000           -mov edi, dword ptr [edx + 0x8c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(140) /* 0x8c */);
    // 00417a73  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417a77  897948                 -mov dword ptr [ecx + 0x48], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.edi;
    // 00417a7a  8bb854d74800           -mov edi, dword ptr [eax + 0x48d754]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */);
    // 00417a80  8b8050d74800           -mov eax, dword ptr [eax + 0x48d750]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */);
    // 00417a86  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00417a87  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00417a88  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00417a8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00417a8d  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00417a91  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00417a92  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00417a96  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00417a97  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00417a9b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00417a9c  e86ffdffff             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 00417aa1  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00417aa3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417aa4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417aa5  83c410                 +add esp, 0x10
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
    // 00417aa8  e903faffff             -jmp 0x4174b0
    return sub_4174b0(app, cpu);
}

/* align: skip  */
void Application::asm_sub_417ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417ab0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00417ab1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00417ab2  8b1d88c74a00           -mov ebx, dword ptr [0x4ac788]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00417ab8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00417ab9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00417aba  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00417abc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00417abd  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00417abf  db4664                 -fild dword ptr [esi + 0x64]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */))));
    // 00417ac2  8b8ec4000000           -mov ecx, dword ptr [esi + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */);
    // 00417ac8  8d8684000000           -lea eax, [esi + 0x84]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00417ace  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00417acf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00417ad0  d88b10180000           -fmul dword ptr [ebx + 0x1810]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(6160) /* 0x1810 */));
    // 00417ad6  da4708                 -fiadd dword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 00417ad9  e8b2f20500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00417ade  8b5660                 -mov edx, dword ptr [esi + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 00417ae1  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00417ae3  83ea24                 -sub edx, 0x24
    (cpu.edx) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00417ae6  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00417aea  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00417aee  d88b0c180000           -fmul dword ptr [ebx + 0x180c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(6156) /* 0x180c */));
    // 00417af4  da4704                 -fiadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00417af7  e894f20500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00417afc  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00417afe  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00417b00  e8cbd3ffff             -call 0x414ed0
    cpu.esp -= 4;
    sub_414ed0(app, cpu);
    // 00417b05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417b06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417b07  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417b08  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417b09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417b0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417b10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00417b11  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00417b12  8b1d88c74a00           -mov ebx, dword ptr [0x4ac788]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00417b18  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00417b19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00417b1a  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00417b1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00417b1d  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00417b1f  db4664                 -fild dword ptr [esi + 0x64]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */))));
    // 00417b22  8b8ec8000000           -mov ecx, dword ptr [esi + 0xc8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */);
    // 00417b28  8d8684000000           -lea eax, [esi + 0x84]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00417b2e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00417b2f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00417b30  d88b10180000           -fmul dword ptr [ebx + 0x1810]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(6160) /* 0x1810 */));
    // 00417b36  da4708                 -fiadd dword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 00417b39  e852f20500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00417b3e  8b5660                 -mov edx, dword ptr [esi + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 00417b41  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00417b43  83ea24                 -sub edx, 0x24
    (cpu.edx) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00417b46  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00417b4a  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 00417b4e  d88b0c180000           -fmul dword ptr [ebx + 0x180c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(6156) /* 0x180c */));
    // 00417b54  da4704                 -fiadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00417b57  e834f20500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00417b5c  8bd5                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00417b5e  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00417b60  e8cbd1ffff             -call 0x414d30
    cpu.esp -= 4;
    sub_414d30(app, cpu);
    // 00417b65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417b66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417b67  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417b68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417b69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417b6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417b70  8b81c8000000           -mov eax, dword ptr [ecx + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(200) /* 0xc8 */);
    // 00417b76  c7416c05000000         -mov dword ptr [ecx + 0x6c], 5
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */) = 5 /*0x5*/;
    // 00417b7d  894168                 -mov dword ptr [ecx + 0x68], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00417b80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417b90  8b81c8000000           -mov eax, dword ptr [ecx + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(200) /* 0xc8 */);
    // 00417b96  c7416c0d000000         -mov dword ptr [ecx + 0x6c], 0xd
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */) = 13 /*0xd*/;
    // 00417b9d  894168                 -mov dword ptr [ecx + 0x68], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00417ba0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417bb0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00417bb3  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00417bb7  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00417bbb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00417bbc  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00417bc0  c744240400000000       -mov dword ptr [esp + 4], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00417bc8  c744240800000000       -mov dword ptr [esp + 8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00417bd0  c744240c00000000       -mov dword ptr [esp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00417bd8  e893000000             -call 0x417c70
    cpu.esp -= 4;
    sub_417c70(app, cpu);
    // 00417bdd  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00417bdf  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00417be1:
    // 00417be1  8b548400               -mov edx, dword ptr [esp + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 4);
    // 00417be5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00417be7  7501                   -jne 0x417bea
    if (!cpu.flags.zf)
    {
        goto L_0x00417bea;
    }
    // 00417be9  41                     -inc ecx
    (cpu.ecx)++;
L_0x00417bea:
    // 00417bea  40                     -inc eax
    (cpu.eax)++;
    // 00417beb  83f803                 +cmp eax, 3
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
    // 00417bee  7cf1                   -jl 0x417be1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00417be1;
    }
    // 00417bf0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00417bf2  83f903                 +cmp ecx, 3
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
    // 00417bf5  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00417bf8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00417bfb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417c00  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00417c05  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00417c06  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00417c07  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00417c09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00417c0b  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00417c0d  750d                   -jne 0x417c1c
    if (!cpu.flags.zf)
    {
        goto L_0x00417c1c;
    }
    // 00417c0f  6838064900             -push 0x490638
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785720 /*0x490638*/;
    cpu.esp -= 4;
    // 00417c14  e8f7cf0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00417c19  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00417c1c:
    // 00417c1c  b924000000             -mov ecx, 0x24
    cpu.ecx = 36 /*0x24*/;
    // 00417c21  e8cad5ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00417c26  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00417c29  8b88d4000000           -mov ecx, dword ptr [eax + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00417c2f  89b9c4000000           -mov dword ptr [ecx + 0xc4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */) = cpu.edi;
    // 00417c35  b925000000             -mov ecx, 0x25
    cpu.ecx = 37 /*0x25*/;
    // 00417c3a  e8b1d5ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00417c3f  8b5028                 -mov edx, dword ptr [eax + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00417c42  b926000000             -mov ecx, 0x26
    cpu.ecx = 38 /*0x26*/;
    // 00417c47  8b82d4000000           -mov eax, dword ptr [edx + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 00417c4d  89b0c4000000           -mov dword ptr [eax + 0xc4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = cpu.esi;
    // 00417c53  e898d5ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00417c58  8b4828                 -mov ecx, dword ptr [eax + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00417c5b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00417c5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417c60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417c61  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 00417c67  8982c4000000           -mov dword ptr [edx + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 00417c6d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_417c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417c70  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00417c75  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00417c76  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00417c77  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00417c79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00417c7b  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00417c7d  750d                   -jne 0x417c8c
    if (!cpu.flags.zf)
    {
        goto L_0x00417c8c;
    }
    // 00417c7f  6838064900             -push 0x490638
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785720 /*0x490638*/;
    cpu.esp -= 4;
    // 00417c84  e887cf0000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00417c89  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00417c8c:
    // 00417c8c  b924000000             -mov ecx, 0x24
    cpu.ecx = 36 /*0x24*/;
    // 00417c91  e85ad5ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00417c96  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00417c99  8b88d4000000           -mov ecx, dword ptr [eax + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00417c9f  8b91c4000000           -mov edx, dword ptr [ecx + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 00417ca5  b925000000             -mov ecx, 0x25
    cpu.ecx = 37 /*0x25*/;
    // 00417caa  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 00417cac  e83fd5ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00417cb1  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00417cb4  8b88d4000000           -mov ecx, dword ptr [eax + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00417cba  8b91c4000000           -mov edx, dword ptr [ecx + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 00417cc0  b926000000             -mov ecx, 0x26
    cpu.ecx = 38 /*0x26*/;
    // 00417cc5  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00417cc7  e824d5ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00417ccc  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00417ccf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417cd0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417cd1  8b88d4000000           -mov ecx, dword ptr [eax + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00417cd7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00417cdb  8b91c4000000           -mov edx, dword ptr [ecx + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 00417ce1  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00417ce3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_417cf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417cf0  83f901                 +cmp ecx, 1
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
    // 00417cf3  7507                   -jne 0x417cfc
    if (!cpu.flags.zf)
    {
        goto L_0x00417cfc;
    }
    // 00417cf5  b924000000             -mov ecx, 0x24
    cpu.ecx = 36 /*0x24*/;
    // 00417cfa  eb16                   -jmp 0x417d12
    goto L_0x00417d12;
L_0x00417cfc:
    // 00417cfc  83f902                 +cmp ecx, 2
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
    // 00417cff  7507                   -jne 0x417d08
    if (!cpu.flags.zf)
    {
        goto L_0x00417d08;
    }
    // 00417d01  b925000000             -mov ecx, 0x25
    cpu.ecx = 37 /*0x25*/;
    // 00417d06  eb0a                   -jmp 0x417d12
    goto L_0x00417d12;
L_0x00417d08:
    // 00417d08  83f903                 +cmp ecx, 3
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
    // 00417d0b  7505                   -jne 0x417d12
    if (!cpu.flags.zf)
    {
        goto L_0x00417d12;
    }
    // 00417d0d  b926000000             -mov ecx, 0x26
    cpu.ecx = 38 /*0x26*/;
L_0x00417d12:
    // 00417d12  e8d9d4ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00417d17  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00417d1a  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00417d20  8b88c4000000           -mov ecx, dword ptr [eax + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 00417d26  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00417d28  7e07                   -jle 0x417d31
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00417d31;
    }
    // 00417d2a  49                     -dec ecx
    (cpu.ecx)--;
    // 00417d2b  8988c4000000           -mov dword ptr [eax + 0xc4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = cpu.ecx;
L_0x00417d31:
    // 00417d31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00417d40  a1dcc74a00             -mov eax, dword ptr [0x4ac7dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900828) /* 0x4ac7dc */);
    // 00417d45  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00417d47  750a                   -jne 0x417d53
    if (!cpu.flags.zf)
    {
        goto L_0x00417d53;
    }
    // 00417d49  c705dcc74a0001000000   -mov dword ptr [0x4ac7dc], 1
    app->getMemory<x86::reg32>(x86::reg32(4900828) /* 0x4ac7dc */) = 1 /*0x1*/;
L_0x00417d53:
    // 00417d53  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00417d56  8b90cc000000           -mov edx, dword ptr [eax + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */);
    // 00417d5c  83fa03                 +cmp edx, 3
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
    // 00417d5f  0f8791000000           -ja 0x417df6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00417df6;
    }
    // 00417d65  ff2495f87d4100         -jmp dword ptr [edx*4 + 0x417df8]
    cpu.ip = app->getMemory<x86::reg32>(4292088 + cpu.edx * 4); goto dynamic_jump;
  case 0x00417d6c:
    // 00417d6c  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00417d6f  83e2df                 -and edx, 0xffffffdf
    cpu.edx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 00417d72  83ca10                 -or edx, 0x10
    cpu.edx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00417d75  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00417d78  ba0000803f             -mov edx, 0x3f800000
    cpu.edx = 1065353216 /*0x3f800000*/;
    // 00417d7d  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00417d80  899084000000           -mov dword ptr [eax + 0x84], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */) = cpu.edx;
    // 00417d86  899088000000           -mov dword ptr [eax + 0x88], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */) = cpu.edx;
    // 00417d8c  89908c000000           -mov dword ptr [eax + 0x8c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */) = cpu.edx;
    // 00417d92  899090000000           -mov dword ptr [eax + 0x90], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */) = cpu.edx;
    // 00417d98  8b88d4000000           -mov ecx, dword ptr [eax + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00417d9e  81c184000000           -add ecx, 0x84
    (cpu.ecx) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 00417da4  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00417da6  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00417da9  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00417dac  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00417daf  c780cc00000001000000   -mov dword ptr [eax + 0xcc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = 1 /*0x1*/;
    // 00417db9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00417dba:
    // 00417dba  8b88d4000000           -mov ecx, dword ptr [eax + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00417dc0  8b91c4000000           -mov edx, dword ptr [ecx + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 00417dc6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00417dc8  7f2c                   -jg 0x417df6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00417df6;
    }
    // 00417dca  c780cc00000002000000   -mov dword ptr [eax + 0xcc], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = 2 /*0x2*/;
    // 00417dd4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00417dd5:
    // 00417dd5  8b90d4000000           -mov edx, dword ptr [eax + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00417ddb  b90000803e             -mov ecx, 0x3e800000
    cpu.ecx = 1048576000 /*0x3e800000*/;
    // 00417de0  898890000000           -mov dword ptr [eax + 0x90], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */) = cpu.ecx;
    // 00417de6  898a90000000           -mov dword ptr [edx + 0x90], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(144) /* 0x90 */) = cpu.ecx;
    // 00417dec  c780cc00000003000000   -mov dword ptr [eax + 0xcc], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = 3 /*0x3*/;
  [[fallthrough]];
  case 0x00417df6:
L_0x00417df6:
    // 00417df6  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_417e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417e10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00417e11  8b7128                 -mov esi, dword ptr [ecx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00417e14  e8f7850000             -call 0x420410
    cpu.esp -= 4;
    sub_420410(app, cpu);
    // 00417e19  d80d08754800           -fmul dword ptr [0x487508]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748552) /* 0x487508 */));
    // 00417e1f  e86cef0500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00417e24  8986c4000000           -mov dword ptr [esi + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 00417e2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417e2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417e30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00417e31  8b7128                 -mov esi, dword ptr [ecx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00417e34  e8e7180100             -call 0x429720
    cpu.esp -= 4;
    sub_429720(app, cpu);
    // 00417e39  d80d08754800           -fmul dword ptr [0x487508]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748552) /* 0x487508 */));
    // 00417e3f  e84cef0500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00417e44  8986c4000000           -mov dword ptr [esi + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 00417e4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417e4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417e50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00417e51  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00417e53  e898d3ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00417e58  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00417e5b  89b0c4000000           -mov dword ptr [eax + 0xc4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = cpu.esi;
    // 00417e61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417e62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417e70  8b4928                 -mov ecx, dword ptr [ecx + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00417e73  db81c4000000           -fild dword ptr [ecx + 0xc4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */))));
    // 00417e79  8b81bc000000           -mov eax, dword ptr [ecx + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */);
    // 00417e7f  d80d4c764800           -fmul dword ptr [0x48764c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748876) /* 0x48764c */));
    // 00417e85  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00417e88  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00417e8b  8b9054d74800           -mov edx, dword ptr [eax + 0x48d754]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */);
    // 00417e91  8b8050d74800           -mov eax, dword ptr [eax + 0x48d750]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */);
    // 00417e97  d805c0764800           -fadd dword ptr [0x4876c0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748992) /* 0x4876c0 */));
    // 00417e9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00417e9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00417e9f  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 00417ea4  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 00417ea9  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 00417eaf  680000403f             -push 0x3f400000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061158912 /*0x3f400000*/;
    cpu.esp -= 4;
    // 00417eb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00417eb5  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00417eb8  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417ebb  e850f9ffff             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 00417ec0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417ed0  8b4928                 -mov ecx, dword ptr [ecx + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00417ed3  db81c4000000           -fild dword ptr [ecx + 0xc4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */))));
    // 00417ed9  8b81bc000000           -mov eax, dword ptr [ecx + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */);
    // 00417edf  d80d4c764800           -fmul dword ptr [0x48764c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748876) /* 0x48764c */));
    // 00417ee5  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00417ee8  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00417eeb  8b9054d74800           -mov edx, dword ptr [eax + 0x48d754]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */);
    // 00417ef1  8b8050d74800           -mov eax, dword ptr [eax + 0x48d750]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */);
    // 00417ef7  d80594744800           -fadd dword ptr [0x487494]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 00417efd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00417efe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00417eff  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 00417f04  680000823e             -push 0x3e820000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048707072 /*0x3e820000*/;
    cpu.esp -= 4;
    // 00417f09  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 00417f0f  680000403f             -push 0x3f400000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061158912 /*0x3f400000*/;
    cpu.esp -= 4;
    // 00417f14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00417f15  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00417f18  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00417f1b  e8f0f8ffff             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 00417f20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417f30  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00417f33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00417f34  8bb0d4000000           -mov esi, dword ptr [eax + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00417f3a  e8e1170100             -call 0x429720
    cpu.esp -= 4;
    sub_429720(app, cpu);
    // 00417f3f  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00417f45  8d0c40                 -lea ecx, [eax + eax*2]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00417f48  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00417f4b  db8130d74800           -fild dword ptr [ecx + 0x48d730]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773680) /* 0x48d730 */))));
    // 00417f51  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00417f53  d80da8764800           -fmul dword ptr [0x4876a8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748968) /* 0x4876a8 */));
    // 00417f59  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00417f5b  e830ee0500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00417f60  894664                 -mov dword ptr [esi + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00417f63  b80000803f             -mov eax, 0x3f800000
    cpu.eax = 1065353216 /*0x3f800000*/;
    // 00417f68  898684000000           -mov dword ptr [esi + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 00417f6e  c7868800000000002a3f   -mov dword ptr [esi + 0x88], 0x3f2a0000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = 1059717120 /*0x3f2a0000*/;
    // 00417f78  c7868c00000000000000   -mov dword ptr [esi + 0x8c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = 0 /*0x0*/;
    // 00417f82  898690000000           -mov dword ptr [esi + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 00417f88  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417f89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_417f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00417f90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00417f91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00417f92  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00417f94  e8177d0000             -call 0x41fcb0
    cpu.esp -= 4;
    sub_41fcb0(app, cpu);
    // 00417f99  3b0560fd4800           +cmp eax, dword ptr [0x48fd60]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4783456) /* 0x48fd60 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00417f9f  742b                   -je 0x417fcc
    if (cpu.flags.zf)
    {
        goto L_0x00417fcc;
    }
    // 00417fa1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00417fa3  7e27                   -jle 0x417fcc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00417fcc;
    }
    // 00417fa5  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00417fa8  bae8c74a00             -mov edx, 0x4ac7e8
    cpu.edx = 4900840 /*0x4ac7e8*/;
L_0x00417fad:
    // 00417fad  8bb9d4000000           -mov edi, dword ptr [ecx + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 00417fb3  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00417fb5  8b89d4000000           -mov ecx, dword ptr [ecx + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 00417fbb  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00417fbe  8b89d4000000           -mov ecx, dword ptr [ecx + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 00417fc4  81faf4c74a00           +cmp edx, 0x4ac7f4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4900852 /*0x4ac7f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00417fca  7ce1                   -jl 0x417fad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00417fad;
    }
L_0x00417fcc:
    // 00417fcc  a360fd4800             -mov dword ptr [0x48fd60], eax
    app->getMemory<x86::reg32>(x86::reg32(4783456) /* 0x48fd60 */) = cpu.eax;
    // 00417fd1  8b7628                 -mov esi, dword ptr [esi + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00417fd4  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
L_0x00417fd9:
    // 00417fd9  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00417fdb  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00417fdd  e8ae000000             -call 0x418090
    cpu.esp -= 4;
    sub_418090(app, cpu);
    // 00417fe2  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00417fe3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00417fe5  79f2                   -jns 0x417fd9
    if (!cpu.flags.sf)
    {
        goto L_0x00417fd9;
    }
    // 00417fe7  a160fd4800             -mov eax, dword ptr [0x48fd60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783456) /* 0x48fd60 */);
    // 00417fec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00417fee  7539                   -jne 0x418029
    if (!cpu.flags.zf)
    {
        goto L_0x00418029;
    }
    // 00417ff0  8b86c0000000           -mov eax, dword ptr [esi + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */);
    // 00417ff6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00417ff7  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00417ff9  8986c0000000           -mov dword ptr [esi + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00417fff  8b15f4c74a00           -mov edx, dword ptr [0x4ac7f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900852) /* 0x4ac7f4 */);
    // 00418005  81c684000000           -add esi, 0x84
    (cpu.esi) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0041800b  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0041800d  a1f8c74a00             -mov eax, dword ptr [0x4ac7f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900856) /* 0x4ac7f8 */);
    // 00418012  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00418015  8b0dfcc74a00           -mov ecx, dword ptr [0x4ac7fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900860) /* 0x4ac7fc */);
    // 0041801b  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041801e  8b1500c84a00           -mov edx, dword ptr [0x4ac800]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900864) /* 0x4ac800 */);
    // 00418024  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00418027  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418028  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00418029:
    // 00418029  e8727c0000             -call 0x41fca0
    cpu.esp -= 4;
    sub_41fca0(app, cpu);
    // 0041802e  83f8ff                 +cmp eax, -1
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
    // 00418031  750c                   -jne 0x41803f
    if (!cpu.flags.zf)
    {
        goto L_0x0041803f;
    }
    // 00418033  a1d0c44a00             -mov eax, dword ptr [0x4ac4d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900048) /* 0x4ac4d0 */);
    // 00418038  83f8ff                 +cmp eax, -1
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
    // 0041803b  7449                   -je 0x418086
    if (cpu.flags.zf)
    {
        goto L_0x00418086;
    }
    // 0041803d  eb05                   -jmp 0x418044
    goto L_0x00418044;
L_0x0041803f:
    // 0041803f  a3d0c44a00             -mov dword ptr [0x4ac4d0], eax
    app->getMemory<x86::reg32>(x86::reg32(4900048) /* 0x4ac4d0 */) = cpu.eax;
L_0x00418044:
    // 00418044  8b8ec0000000           -mov ecx, dword ptr [esi + 0xc0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */);
    // 0041804a  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0041804d  7537                   -jne 0x418086
    if (!cpu.flags.zf)
    {
        goto L_0x00418086;
    }
    // 0041804f  83c901                 -or ecx, 1
    cpu.ecx |= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00418052  898ec0000000           -mov dword ptr [esi + 0xc0], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */) = cpu.ecx;
    // 00418058  b9f0c74a00             -mov ecx, 0x4ac7f0
    cpu.ecx = 4900848 /*0x4ac7f0*/;
    // 0041805d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00418060  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00418062  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00418064  81c284000000           -add edx, 0x84
    (cpu.edx) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0041806a  81c684000000           -add esi, 0x84
    (cpu.esi) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 00418070  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00418072  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00418074  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00418077  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0041807a  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0041807d  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00418080  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00418083  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x00418086:
    // 00418086  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418087  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418088  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_418090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00418090  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00418091  d905e4c74a00           -fld dword ptr [0x4ac7e4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4900836) /* 0x4ac7e4 */)));
    // 00418097  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 00418099  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041809a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041809b  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041809d  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041809f  dc0568734800           -fadd qword ptr [0x487368]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */));
    // 004180a5  dc0d00764800           -fmul qword ptr [0x487600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748800) /* 0x487600 */));
    // 004180ab  dc05d8744800           -fadd qword ptr [0x4874d8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */));
    // 004180b1  d91de0c74a00           -fstp dword ptr [0x4ac7e0]
    app->getMemory<float>(x86::reg32(4900832) /* 0x4ac7e0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004180b7  e8741c0000             -call 0x419d30
    cpu.esp -= 4;
    sub_419d30(app, cpu);
    // 004180bc  d80d90744800           -fmul dword ptr [0x487490]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748432) /* 0x487490 */));
    // 004180c2  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004180c4  d805e4c74a00           -fadd dword ptr [0x4ac7e4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4900836) /* 0x4ac7e4 */));
    // 004180ca  d91de4c74a00           -fstp dword ptr [0x4ac7e4]
    app->getMemory<float>(x86::reg32(4900836) /* 0x4ac7e4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004180d0  e85b830000             -call 0x420430
    cpu.esp -= 4;
    sub_420430(app, cpu);
    // 004180d5  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004180d9  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004180dd  8b86c0000000           -mov eax, dword ptr [esi + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */);
    // 004180e3  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004180e9  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004180eb  8986c0000000           -mov dword ptr [esi + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 004180f1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004180f3  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 004180f8  7570                   -jne 0x41816a
    if (!cpu.flags.zf)
    {
        goto L_0x0041816a;
    }
    // 004180fa  e8a17b0000             -call 0x41fca0
    cpu.esp -= 4;
    sub_41fca0(app, cpu);
    // 004180ff  3bf8                   +cmp edi, eax
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
    // 00418101  7538                   -jne 0x41813b
    if (!cpu.flags.zf)
    {
        goto L_0x0041813b;
    }
    // 00418103  e868770000             -call 0x41f870
    cpu.esp -= 4;
    sub_41f870(app, cpu);
    // 00418108  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041810a  7468                   -je 0x418174
    if (cpu.flags.zf)
    {
        goto L_0x00418174;
    }
    // 0041810c  a1e0c74a00             -mov eax, dword ptr [0x4ac7e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900832) /* 0x4ac7e0 */);
    // 00418111  89868c000000           -mov dword ptr [esi + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 00418117  8b0de0c74a00           -mov ecx, dword ptr [0x4ac7e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900832) /* 0x4ac7e0 */);
    // 0041811d  898e88000000           -mov dword ptr [esi + 0x88], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.ecx;
    // 00418123  8b15e0c74a00           -mov edx, dword ptr [0x4ac7e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900832) /* 0x4ac7e0 */);
    // 00418129  899684000000           -mov dword ptr [esi + 0x84], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.edx;
    // 0041812f  c786900000000000803f   -mov dword ptr [esi + 0x90], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = 1065353216 /*0x3f800000*/;
    // 00418139  eb39                   -jmp 0x418174
    goto L_0x00418174;
L_0x0041813b:
    // 0041813b  8b0d30fd4800           -mov ecx, dword ptr [0x48fd30]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783408) /* 0x48fd30 */);
    // 00418141  8d8684000000           -lea eax, [esi + 0x84]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00418147  898e84000000           -mov dword ptr [esi + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 0041814d  8b1534fd4800           -mov edx, dword ptr [0x48fd34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783412) /* 0x48fd34 */);
    // 00418153  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00418156  8b0d38fd4800           -mov ecx, dword ptr [0x48fd38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783416) /* 0x48fd38 */);
    // 0041815c  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041815f  8b153cfd4800           -mov edx, dword ptr [0x48fd3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783420) /* 0x48fd3c */);
    // 00418165  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00418168  eb0a                   -jmp 0x418174
    goto L_0x00418174;
L_0x0041816a:
    // 0041816a  c7869000000000000000   -mov dword ptr [esi + 0x90], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = 0 /*0x0*/;
L_0x00418174:
    // 00418174  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041817a  8b86c0000000           -mov eax, dword ptr [esi + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */);
    // 00418180  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00418182  754a                   -jne 0x4181ce
    if (!cpu.flags.zf)
    {
        goto L_0x004181ce;
    }
    // 00418184  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00418188  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0041818e  0c05                   -or al, 5
    cpu.al |= x86::reg8(x86::sreg8(5 /*0x5*/));
    // 00418190  8986c0000000           -mov dword ptr [esi + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00418196  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00418198  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 0041819d  7525                   -jne 0x4181c4
    if (!cpu.flags.zf)
    {
        goto L_0x004181c4;
    }
    // 0041819f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004181a3  680000003f             -push 0x3f000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1056964608 /*0x3f000000*/;
    cpu.esp -= 4;
    // 004181a8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004181a9  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004181ab  e830000000             -call 0x4181e0
    cpu.esp -= 4;
    sub_4181e0(app, cpu);
    // 004181b0  8b86d4000000           -mov eax, dword ptr [esi + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 004181b6  c786b40000000ad7233c   -mov dword ptr [esi + 0xb4], 0x3c23d70a
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(180) /* 0xb4 */) = 1008981770 /*0x3c23d70a*/;
    // 004181c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004181c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004181c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004181c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004181c4:
    // 004181c4  c7869000000000000000   -mov dword ptr [esi + 0x90], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = 0 /*0x0*/;
L_0x004181ce:
    // 004181ce  8b86d4000000           -mov eax, dword ptr [esi + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 004181d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004181d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004181d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004181d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4181e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004181e0  d90594744800           -fld dword ptr [0x487494]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    // 004181e6  d8642404               -fsub dword ptr [esp + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 004181ea  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004181ee  c7819c00000000000000   -mov dword ptr [ecx + 0x9c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */) = 0 /*0x0*/;
    // 004181f8  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 004181fe  dc0dc8764800           -fmul qword ptr [0x4876c8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749000) /* 0x4876c8 */));
    // 00418204  d99994000000           -fstp dword ptr [ecx + 0x94]
    app->getMemory<float>(cpu.ecx + x86::reg32(148) /* 0x94 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041820a  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0041820e  dc0dc8764800           -fmul qword ptr [0x4876c8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749000) /* 0x4876c8 */));
    // 00418214  d99998000000           -fstp dword ptr [ecx + 0x98]
    app->getMemory<float>(cpu.ecx + x86::reg32(152) /* 0x98 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041821a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::asm_sub_418220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00418220  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00418225  e8c6cfffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041822a  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041822d  c780cc00000001000000   -mov dword ptr [eax + 0xcc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = 1 /*0x1*/;
    // 00418237  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_418240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00418240  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00418245  e8a6cfffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041824a  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041824d  c780cc00000003000000   -mov dword ptr [eax + 0xcc], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = 3 /*0x3*/;
    // 00418257  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_418260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00418260  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418261  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00418262  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00418264  8b7728                 -mov esi, dword ptr [edi + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00418267  8b86cc000000           -mov eax, dword ptr [esi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 0041826d  48                     -dec eax
    (cpu.eax)--;
    // 0041826e  83f803                 +cmp eax, 3
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
    // 00418271  0f87a0010000           -ja 0x418417
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00418417;
    }
    // 00418277  ff248528844100         -jmp dword ptr [eax*4 + 0x418428]
    cpu.ip = app->getMemory<x86::reg32>(4293672 + cpu.eax * 4); goto dynamic_jump;
  case 0x0041827e:
    // 0041827e  d90564fd4800           -fld dword ptr [0x48fd64]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4783460) /* 0x48fd64 */)));
    // 00418284  d81dec724800           -fcomp dword ptr [0x4872ec]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748012) /* 0x4872ec */)));
    cpu.fpu.pop();
    // 0041828a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041828c  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0041828f  7a0b                   -jp 0x41829c
    if (cpu.flags.pf)
    {
        goto L_0x0041829c;
    }
    // 00418291  e89ad40400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00418296  d91d64fd4800           -fstp dword ptr [0x48fd64]
    app->getMemory<float>(x86::reg32(4783460) /* 0x48fd64 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0041829c:
    // 0041829c  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0041829f  c747200000803f         -mov dword ptr [edi + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 004182a6  24df                   -and al, 0xdf
    cpu.al &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 004182a8  0c10                   -or al, 0x10
    cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004182aa  89471c                 -mov dword ptr [edi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004182ad  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 004182b3  db86c4000000           -fild dword ptr [esi + 0xc4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */))));
    // 004182b9  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 004182bc  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004182bf  d80d4c764800           -fmul dword ptr [0x48764c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748876) /* 0x48764c */));
    // 004182c5  8b8854d74800           -mov ecx, dword ptr [eax + 0x48d754]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */);
    // 004182cb  8b9050d74800           -mov edx, dword ptr [eax + 0x48d750]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */);
    // 004182d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004182d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004182d3  d8054c764800           -fadd dword ptr [0x48764c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748876) /* 0x48764c */));
    // 004182d9  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 004182de  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 004182e3  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 004182e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004182e9  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 004182ef  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004182f2  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004182f5  e816f5ffff             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 004182fa  c786cc00000002000000   -mov dword ptr [esi + 0xcc], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 2 /*0x2*/;
    // 00418304  e827d40400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00418309  d91d64fd4800           -fstp dword ptr [0x48fd64]
    app->getMemory<float>(x86::reg32(4783460) /* 0x48fd64 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041830f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418310  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418311  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00418312:
    // 00418312  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 00418315  c747200000803f         -mov dword ptr [edi + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 0041831c  24df                   -and al, 0xdf
    cpu.al &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 0041831e  0c10                   -or al, 0x10
    cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00418320  89471c                 -mov dword ptr [edi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00418323  e808d40400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00418328  d82564fd4800           -fsub dword ptr [0x48fd64]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4783460) /* 0x48fd64 */));
    // 0041832e  dc0da8744800           -fmul qword ptr [0x4874a8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748456) /* 0x4874a8 */));
    // 00418334  d886c8000000           -fadd dword ptr [esi + 0xc8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 0041833a  d996c8000000           -fst dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    // 00418340  d9ff                   -fcos 
    cpu.fpu.st(0) = cpu.fpu.cos(cpu.fpu.st(0));
    // 00418342  dc0d00764800           -fmul qword ptr [0x487600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748800) /* 0x487600 */));
    // 00418348  dc05d8764800           -fadd qword ptr [0x4876d8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4749016) /* 0x4876d8 */));
    // 0041834e  d99e90000000           -fstp dword ptr [esi + 0x90]
    app->getMemory<float>(cpu.esi + x86::reg32(144) /* 0x90 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00418354  e8d7d30400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00418359  d91d64fd4800           -fstp dword ptr [0x48fd64]
    app->getMemory<float>(x86::reg32(4783460) /* 0x48fd64 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041835f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418360  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418361  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00418362:
    // 00418362  8b4f1c                 -mov ecx, dword ptr [edi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 00418365  b80000803f             -mov eax, 0x3f800000
    cpu.eax = 1065353216 /*0x3f800000*/;
    // 0041836a  83e1df                 -and ecx, 0xffffffdf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 0041836d  894720                 -mov dword ptr [edi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00418370  83c910                 -or ecx, 0x10
    cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00418373  894f1c                 -mov dword ptr [edi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00418376  898690000000           -mov dword ptr [esi + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 0041837c  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00418382  db86c4000000           -fild dword ptr [esi + 0xc4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */))));
    // 00418388  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041838b  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041838e  d80d4c764800           -fmul dword ptr [0x48764c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748876) /* 0x48764c */));
    // 00418394  8b9054d74800           -mov edx, dword ptr [eax + 0x48d754]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */);
    // 0041839a  8b8050d74800           -mov eax, dword ptr [eax + 0x48d750]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */);
    // 004183a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004183a1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004183a2  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 004183a7  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 004183ac  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 004183b2  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 004183b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004183b8  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004183bb  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004183be  e84df4ffff             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 004183c3  c786cc00000004000000   -mov dword ptr [esi + 0xcc], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 4 /*0x4*/;
    // 004183cd  e85ed30400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004183d2  d99ec8000000           -fstp dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004183d8  e853d30400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004183dd  d91d64fd4800           -fstp dword ptr [0x48fd64]
    app->getMemory<float>(x86::reg32(4783460) /* 0x48fd64 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004183e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004183e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004183e5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004183e6:
    // 004183e6  e845d30400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004183eb  d8a6c8000000           -fsub dword ptr [esi + 0xc8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 004183f1  dc1dd0764800           -fcomp qword ptr [0x4876d0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4749008) /* 0x4876d0 */)));
    cpu.fpu.pop();
    // 004183f7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004183f9  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 004183fe  7517                   -jne 0x418417
    if (!cpu.flags.zf)
    {
        goto L_0x00418417;
    }
    // 00418400  8b4f1c                 -mov ecx, dword ptr [edi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 00418403  83e1ef                 -and ecx, 0xffffffef
    cpu.ecx &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
    // 00418406  83c920                 -or ecx, 0x20
    cpu.ecx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00418409  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041840b  894f1c                 -mov dword ptr [edi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041840e  894720                 -mov dword ptr [edi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00418411  8986cc000000           -mov dword ptr [esi + 0xcc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.eax;
L_0x00418417:
    // 00418417  e814d30400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0041841c  d91d64fd4800           -fstp dword ptr [0x48fd64]
    app->getMemory<float>(x86::reg32(4783460) /* 0x48fd64 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00418422  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418423  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418424  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_418440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00418440  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00418443  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418444  8bb0d4000000           -mov esi, dword ptr [eax + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041844a  e821720000             -call 0x41f670
    cpu.esp -= 4;
    sub_41f670(app, cpu);
    // 0041844f  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00418455  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00418457  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 0041845c  7507                   -jne 0x418465
    if (!cpu.flags.zf)
    {
        goto L_0x00418465;
    }
    // 0041845e  e80d720000             -call 0x41f670
    cpu.esp -= 4;
    sub_41f670(app, cpu);
    // 00418463  eb07                   -jmp 0x41846c
    goto L_0x0041846c;
L_0x00418465:
    // 00418465  e806720000             -call 0x41f670
    cpu.esp -= 4;
    sub_41f670(app, cpu);
    // 0041846a  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x0041846c:
    // 0041846c  d99ec8000000           -fstp dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00418472  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00418474  e8f7f6ffff             -call 0x417b70
    cpu.esp -= 4;
    sub_417b70(app, cpu);
    // 00418479  b80000803f             -mov eax, 0x3f800000
    cpu.eax = 1065353216 /*0x3f800000*/;
    // 0041847e  c7868800000000002a3f   -mov dword ptr [esi + 0x88], 0x3f2a0000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = 1059717120 /*0x3f2a0000*/;
    // 00418488  898684000000           -mov dword ptr [esi + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 0041848e  c7868c00000000000000   -mov dword ptr [esi + 0x8c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = 0 /*0x0*/;
    // 00418498  898690000000           -mov dword ptr [esi + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 0041849e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041849f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4184a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004184a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004184a1  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004184a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004184a5  8bb0d4000000           -mov esi, dword ptr [eax + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 004184ab  e810780000             -call 0x41fcc0
    cpu.esp -= 4;
    sub_41fcc0(app, cpu);
    // 004184b0  83f8ff                 +cmp eax, -1
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
    // 004184b3  7515                   -jne 0x4184ca
    if (!cpu.flags.zf)
    {
        goto L_0x004184ca;
    }
    // 004184b5  c786c800000000000000   -mov dword ptr [esi + 0xc8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */) = 0 /*0x0*/;
    // 004184bf  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004184c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004184c2  83c404                 +add esp, 4
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
    // 004184c5  e9a6f6ffff             -jmp 0x417b70
    return sub_417b70(app, cpu);
L_0x004184ca:
    // 004184ca  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 004184d0  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004184d3  e878710000             -call 0x41f650
    cpu.esp -= 4;
    sub_41f650(app, cpu);
    // 004184d8  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004184dc  e8bf710000             -call 0x41f6a0
    cpu.esp -= 4;
    sub_41f6a0(app, cpu);
    // 004184e1  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004184e7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004184e9  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 004184ee  7507                   -jne 0x4184f7
    if (!cpu.flags.zf)
    {
        goto L_0x004184f7;
    }
    // 004184f0  e8ab710000             -call 0x41f6a0
    cpu.esp -= 4;
    sub_41f6a0(app, cpu);
    // 004184f5  eb07                   -jmp 0x4184fe
    goto L_0x004184fe;
L_0x004184f7:
    // 004184f7  e8a4710000             -call 0x41f6a0
    cpu.esp -= 4;
    sub_41f6a0(app, cpu);
    // 004184fc  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x004184fe:
    // 004184fe  d8742404               -fdiv dword ptr [esp + 4]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 00418502  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00418503  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00418505  d99ec8000000           -fstp dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041850b  e860f6ffff             -call 0x417b70
    cpu.esp -= 4;
    sub_417b70(app, cpu);
    // 00418510  b80000803f             -mov eax, 0x3f800000
    cpu.eax = 1065353216 /*0x3f800000*/;
    // 00418515  c7868800000000002a3f   -mov dword ptr [esi + 0x88], 0x3f2a0000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = 1059717120 /*0x3f2a0000*/;
    // 0041851f  898684000000           -mov dword ptr [esi + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 00418525  c7868c00000000000000   -mov dword ptr [esi + 0x8c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */) = 0 /*0x0*/;
    // 0041852f  898690000000           -mov dword ptr [esi + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 00418535  8bbed4000000           -mov edi, dword ptr [esi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041853b  d987c8000000           -fld dword ptr [edi + 0xc8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(200) /* 0xc8 */)));
    // 00418541  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 00418543  dc0d70754800           -fmul qword ptr [0x487570]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748656) /* 0x487570 */));
    // 00418549  dc05e8764800           -fadd qword ptr [0x4876e8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4749032) /* 0x4876e8 */));
    // 0041854f  d95f68                 -fstp dword ptr [edi + 0x68]
    app->getMemory<float>(cpu.edi + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00418552  e8d9170000             -call 0x419d30
    cpu.esp -= 4;
    sub_419d30(app, cpu);
    // 00418557  d88ec8000000           -fmul dword ptr [esi + 0xc8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 0041855d  d80de0764800           -fmul dword ptr [0x4876e0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749024) /* 0x4876e0 */));
    // 00418563  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00418567  e8c4170000             -call 0x419d30
    cpu.esp -= 4;
    sub_419d30(app, cpu);
    // 0041856c  d8442408               -fadd dword ptr [esp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00418570  d80db8744800           -fmul dword ptr [0x4874b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 00418576  d887c8000000           -fadd dword ptr [edi + 0xc8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(200) /* 0xc8 */));
    // 0041857c  d99fc8000000           -fstp dword ptr [edi + 0xc8]
    app->getMemory<float>(cpu.edi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00418582  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418583  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418584  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418585  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_418590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00418590  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418591  8b7128                 -mov esi, dword ptr [ecx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00418594  e86748ffff             -call 0x40ce00
    cpu.esp -= 4;
    sub_40ce00(app, cpu);
    // 00418599  8986c4000000           -mov dword ptr [esi + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 0041859f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004185a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4185b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004185b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004185b1  8b7128                 -mov esi, dword ptr [ecx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004185b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004185b5  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004185b7  e8c447ffff             -call 0x40cd80
    cpu.esp -= 4;
    sub_40cd80(app, cpu);
    // 004185bc  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004185be  d8a6c8000000           -fsub dword ptr [esi + 0xc8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 004185c4  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 004185ca  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004185cc  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 004185d1  7402                   -je 0x4185d5
    if (cpu.flags.zf)
    {
        goto L_0x004185d5;
    }
    // 004185d3  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x004185d5:
    // 004185d5  d81590744800           -fcom dword ptr [0x487490]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748432) /* 0x487490 */)));
    // 004185db  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004185dd  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 004185e2  741c                   -je 0x418600
    if (cpu.flags.zf)
    {
        goto L_0x00418600;
    }
    // 004185e4  d81df0764800           -fcomp dword ptr [0x4876f0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749040) /* 0x4876f0 */)));
    cpu.fpu.pop();
    // 004185ea  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004185ec  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 004185ef  7b11                   -jnp 0x418602
    if (!cpu.flags.pf)
    {
        goto L_0x00418602;
    }
    // 004185f1  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 004185f7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004185f9  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 004185fc  7a09                   -jp 0x418607
    if (cpu.flags.pf)
    {
        goto L_0x00418607;
    }
    // 004185fe  eb02                   -jmp 0x418602
    goto L_0x00418602;
L_0x00418600:
    // 00418600  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00418602:
    // 00418602  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x00418607:
    // 00418607  d99ec8000000           -fstp dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041860d  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 00418613  d986c8000000           -fld dword ptr [esi + 0xc8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */)));
    // 00418619  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0041861b  dc0d00764800           -fmul qword ptr [0x487600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748800) /* 0x487600 */));
    // 00418621  d95e70                 -fstp dword ptr [esi + 0x70]
    app->getMemory<float>(cpu.esi + x86::reg32(112) /* 0x70 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00418624  e807170000             -call 0x419d30
    cpu.esp -= 4;
    sub_419d30(app, cpu);
    // 00418629  d80db8744800           -fmul dword ptr [0x4874b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 0041862f  83ff01                 +cmp edi, 1
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
    // 00418632  d886c8000000           +fadd dword ptr [esi + 0xc8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 00418638  d99ec8000000           +fstp dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041863e  7511                   -jne 0x418651
    if (!cpu.flags.zf)
    {
        goto L_0x00418651;
    }
    // 00418640  c7467000000000         -mov dword ptr [esi + 0x70], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
    // 00418647  c786c800000000000000   -mov dword ptr [esi + 0xc8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */) = 0 /*0x0*/;
L_0x00418651:
    // 00418651  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418652  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418653  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_418660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00418660  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00418661  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00418664  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418665  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00418666  8b88d4000000           -mov ecx, dword ptr [eax + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041866c  8b81d4000000           -mov eax, dword ptr [ecx + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 00418672  8b88bc000000           -mov ecx, dword ptr [eax + 0xbc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 00418678  8bb0d4000000           -mov esi, dword ptr [eax + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041867e  8d1449                 -lea edx, [ecx + ecx*2]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00418681  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00418684  8bba34d74800           -mov edi, dword ptr [edx + 0x48d734]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4773684) /* 0x48d734 */);
    // 0041868a  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0041868e  e8bd47ffff             -call 0x40ce50
    cpu.esp -= 4;
    sub_40ce50(app, cpu);
    // 00418693  da4c2408               -fimul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00418697  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00418699  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0041869a  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0041869c  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0041869e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004186a2  da642408               -fisub dword ptr [esp + 8]
    cpu.fpu.st(0) -= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004186a6  e8e5e60500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 004186ab  d986c8000000           -fld dword ptr [esi + 0xc8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */)));
    // 004186b1  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 004186b3  894660                 -mov dword ptr [esi + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 004186b6  c786900000000000803f   -mov dword ptr [esi + 0x90], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */) = 1065353216 /*0x3f800000*/;
    // 004186c0  dc0d70754800           -fmul qword ptr [0x487570]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748656) /* 0x487570 */));
    // 004186c6  dc05e8764800           -fadd qword ptr [0x4876e8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4749032) /* 0x4876e8 */));
    // 004186cc  d80de8724800           -fmul dword ptr [0x4872e8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748008) /* 0x4872e8 */));
    // 004186d2  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 004186d8  d99684000000           -fst dword ptr [esi + 0x84]
    app->getMemory<float>(cpu.esi + x86::reg32(132) /* 0x84 */) = float(cpu.fpu.st(0));
    // 004186de  d99688000000           -fst dword ptr [esi + 0x88]
    app->getMemory<float>(cpu.esi + x86::reg32(136) /* 0x88 */) = float(cpu.fpu.st(0));
    // 004186e4  d99e8c000000           -fstp dword ptr [esi + 0x8c]
    app->getMemory<float>(cpu.esi + x86::reg32(140) /* 0x8c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004186ea  e841160000             -call 0x419d30
    cpu.esp -= 4;
    sub_419d30(app, cpu);
    // 004186ef  d80d3c764800           -fmul dword ptr [0x48763c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748860) /* 0x48763c */));
    // 004186f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004186f6  d886c8000000           -fadd dword ptr [esi + 0xc8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 004186fc  d99ec8000000           -fstp dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00418702  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418703  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418704  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_418710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00418710  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418711  8b7128                 -mov esi, dword ptr [ecx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00418714  e8f746ffff             -call 0x40ce10
    cpu.esp -= 4;
    sub_40ce10(app, cpu);
    // 00418719  8986c4000000           -mov dword ptr [esi + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 0041871f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418720  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_418730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00418730  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00418731  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00418732  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418733  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00418734  e857750000             -call 0x41fc90
    cpu.esp -= 4;
    sub_41fc90(app, cpu);
    // 00418739  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0041873b  bf10020000             -mov edi, 0x210
    cpu.edi = 528 /*0x210*/;
    // 00418740  f7db                   +neg ebx
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
    // 00418742  1bdb                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 00418744  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 00418746  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00418748:
    // 00418748  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 0041874d  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041874f  3bd9                   +cmp ebx, ecx
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
    // 00418751  8d3407                 -lea esi, [edi + eax]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 1);
    // 00418754  7513                   -jne 0x418769
    if (!cpu.flags.zf)
    {
        goto L_0x00418769;
    }
    // 00418756  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00418759  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0041875b  757f                   -jne 0x4187dc
    if (!cpu.flags.zf)
    {
        goto L_0x004187dc;
    }
    // 0041875d  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0041875f  894e20                 -mov dword ptr [esi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00418762  0c20                   +or al, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00418764  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00418767  eb4e                   -jmp 0x4187b7
    goto L_0x004187b7;
L_0x00418769:
    // 00418769  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0041876c  c746200000803f         -mov dword ptr [esi + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 00418773  83e1df                 -and ecx, 0xffffffdf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 00418776  83c910                 -or ecx, 0x10
    cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00418779  894e1c                 -mov dword ptr [esi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041877c  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00418781  e86acaffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00418786  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00418789  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0041878c  83ca10                 -or edx, 0x10
    cpu.edx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041878f  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00418794  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00418796  e855caffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041879b  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0041879e  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004187a1  83e1df                 -and ecx, 0xffffffdf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 004187a4  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004187a6  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 004187ab  e840caffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 004187b0  c740200000803f         -mov dword ptr [eax + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
L_0x004187b7:
    // 004187b7  8b7628                 -mov esi, dword ptr [esi + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004187ba  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004187bc  e8af7b0000             -call 0x420370
    cpu.esp -= 4;
    sub_420370(app, cpu);
    // 004187c1  d99ec8000000           -fstp dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004187c7  83c730                 -add edi, 0x30
    (cpu.edi) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004187ca  45                     -inc ebp
    (cpu.ebp)++;
    // 004187cb  81ff90030000           +cmp edi, 0x390
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(912 /*0x390*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004187d1  0f8c71ffffff           -jl 0x418748
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00418748;
    }
    // 004187d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004187d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004187d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004187da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004187db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004187dc:
    // 004187dc  890d8cd34a00           -mov dword ptr [0x4ad38c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4903820) /* 0x4ad38c */) = cpu.ecx;
    // 004187e2  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 004187e7  e804caffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 004187ec  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004187ef  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004187f2  83ca20                 -or edx, 0x20
    cpu.edx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004187f5  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 004187fa  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004187fc  e8efc9ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00418801  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00418804  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00418807  83e1ef                 -and ecx, 0xffffffef
    cpu.ecx &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
    // 0041880a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0041880c  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00418811  e8dac9ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00418816  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0041881d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041881e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041881f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418820  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418821  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_418830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00418830  8b4928                 -mov ecx, dword ptr [ecx + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00418833  e958f3ffff             -jmp 0x417b90
    return sub_417b90(app, cpu);
}

/* align: skip  */
void Application::asm_sub_418840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00418840  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00418846  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00418847  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00418848  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418849  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041884a  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0041884c  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0041884f  8b6f28                 -mov ebp, dword ptr [edi + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00418852  83f808                 +cmp eax, 8
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
    // 00418855  0f8465050000           -je 0x418dc0
    if (cpu.flags.zf)
    {
        goto L_0x00418dc0;
    }
    // 0041885b  e830740000             -call 0x41fc90
    cpu.esp -= 4;
    sub_41fc90(app, cpu);
    // 00418860  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00418862  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00418864  750d                   -jne 0x418873
    if (!cpu.flags.zf)
    {
        goto L_0x00418873;
    }
    // 00418866  e895e0ffff             -call 0x416900
    cpu.esp -= 4;
    sub_416900(app, cpu);
    // 0041886b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041886d  0f844d050000           -je 0x418dc0
    if (cpu.flags.zf)
    {
        goto L_0x00418dc0;
    }
L_0x00418873:
    // 00418873  e888e0ffff             -call 0x416900
    cpu.esp -= 4;
    sub_416900(app, cpu);
    // 00418878  83f801                 +cmp eax, 1
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
    // 0041887b  741b                   -je 0x418898
    if (cpu.flags.zf)
    {
        goto L_0x00418898;
    }
    // 0041887d  e87ee0ffff             -call 0x416900
    cpu.esp -= 4;
    sub_416900(app, cpu);
    // 00418882  83f802                 +cmp eax, 2
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
    // 00418885  7411                   -je 0x418898
    if (cpu.flags.zf)
    {
        goto L_0x00418898;
    }
    // 00418887  83c606                 +add esi, 6
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041888a  c7470c00000000         -mov dword ptr [edi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00418891  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00418896  eb2c                   -jmp 0x4188c4
    goto L_0x004188c4;
L_0x00418898:
    // 00418898  e8f3130000             -call 0x419c90
    cpu.esp -= 4;
    sub_419c90(app, cpu);
    // 0041889d  83f8ff                 +cmp eax, -1
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
    // 004188a0  0f841a050000           -je 0x418dc0
    if (cpu.flags.zf)
    {
        goto L_0x00418dc0;
    }
    // 004188a6  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004188a8  e823610000             -call 0x41e9d0
    cpu.esp -= 4;
    sub_41e9d0(app, cpu);
    // 004188ad  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004188af  c7470cb2ffffff         -mov dword ptr [edi + 0xc], 0xffffffb2
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = 4294967218 /*0xffffffb2*/;
    // 004188b6  e845e0ffff             -call 0x416900
    cpu.esp -= 4;
    sub_416900(app, cpu);
    // 004188bb  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004188bd  4b                     -dec ebx
    (cpu.ebx)--;
    // 004188be  f7db                   +neg ebx
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
    // 004188c0  1bdb                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004188c2  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x004188c4:
    // 004188c4  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004188c6  e875dfffff             -call 0x416840
    cpu.esp -= 4;
    sub_416840(app, cpu);
    // 004188cb  8bbdd4000000           -mov edi, dword ptr [ebp + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(212) /* 0xd4 */);
    // 004188d1  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004188d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004188d6  6884074900             -push 0x490784
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786052 /*0x490784*/;
    cpu.esp -= 4;
    // 004188db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004188dc  e817e50500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004188e1  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004188e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004188e6  e8d5c40300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 004188eb  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004188ef  6874074900             -push 0x490774
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786036 /*0x490774*/;
    cpu.esp -= 4;
    // 004188f4  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 004188fa  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418900  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00418901  e8f2e40500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418906  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0041890a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041890b  e8b0c40300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418910  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418916  8b1568fd4800           -mov edx, dword ptr [0x48fd68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783464) /* 0x48fd68 */);
    // 0041891c  8d8f84000000           -lea ecx, [edi + 0x84]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 00418922  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418928  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418929  6864074900             -push 0x490764
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786020 /*0x490764*/;
    cpu.esp -= 4;
    // 0041892e  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00418930  a16cfd4800             -mov eax, dword ptr [0x48fd6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783468) /* 0x48fd6c */);
    // 00418935  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00418938  8b1570fd4800           -mov edx, dword ptr [0x48fd70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783472) /* 0x48fd70 */);
    // 0041893e  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00418941  a174fd4800             -mov eax, dword ptr [0x48fd74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783476) /* 0x48fd74 */);
    // 00418946  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00418949  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0041894d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041894e  e8a5e40500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418953  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00418957  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00418958  e863c40300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0041895d  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418963  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418969  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0041896d  6850074900             -push 0x490750
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786000 /*0x490750*/;
    cpu.esp -= 4;
    // 00418972  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00418973  e880e40500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418978  8d4c2444               -lea ecx, [esp + 0x44]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0041897c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041897d  e83ec40300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418982  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418988  a168fd4800             -mov eax, dword ptr [0x48fd68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783464) /* 0x48fd68 */);
    // 0041898d  8d9784000000           -lea edx, [edi + 0x84]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 00418993  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418999  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041899a  6838074900             -push 0x490738
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785976 /*0x490738*/;
    cpu.esp -= 4;
    // 0041899f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004189a1  8b0d6cfd4800           -mov ecx, dword ptr [0x48fd6c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783468) /* 0x48fd6c */);
    // 004189a7  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004189aa  a170fd4800             -mov eax, dword ptr [0x48fd70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783472) /* 0x48fd70 */);
    // 004189af  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004189b2  8b0d74fd4800           -mov ecx, dword ptr [0x48fd74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783476) /* 0x48fd74 */);
    // 004189b8  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004189bb  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004189bf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004189c0  e833e40500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004189c5  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004189c8  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004189cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004189cd  e8eec30300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 004189d2  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004189d6  6828074900             -push 0x490728
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785960 /*0x490728*/;
    cpu.esp -= 4;
    // 004189db  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 004189e1  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 004189e7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004189e8  e80be40500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004189ed  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004189f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004189f2  e8c9c30300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 004189f7  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 004189fd  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418a03  680c074900             -push 0x49070c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785932 /*0x49070c*/;
    cpu.esp -= 4;
    // 00418a08  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00418a0c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00418a0d  e8e6e30500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418a12  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00418a16  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00418a17  e8a4c30300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418a1c  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418a22  a168fd4800             -mov eax, dword ptr [0x48fd68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783464) /* 0x48fd68 */);
    // 00418a27  8d9784000000           -lea edx, [edi + 0x84]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 00418a2d  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418a33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418a34  6804074900             -push 0x490704
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785924 /*0x490704*/;
    cpu.esp -= 4;
    // 00418a39  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00418a3b  8b0d6cfd4800           -mov ecx, dword ptr [0x48fd6c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783468) /* 0x48fd6c */);
    // 00418a41  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00418a44  a170fd4800             -mov eax, dword ptr [0x48fd70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783472) /* 0x48fd70 */);
    // 00418a49  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00418a4c  8b0d74fd4800           -mov ecx, dword ptr [0x48fd74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783476) /* 0x48fd74 */);
    // 00418a52  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00418a55  8d542434               -lea edx, [esp + 0x34]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00418a59  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00418a5a  e899e30500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418a5f  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00418a63  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00418a64  e857c30300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418a69  8d4c243c               -lea ecx, [esp + 0x3c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00418a6d  68f8064900             -push 0x4906f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785912 /*0x4906f8*/;
    cpu.esp -= 4;
    // 00418a72  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418a78  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418a7e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00418a7f  e874e30500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418a84  8d542444               -lea edx, [esp + 0x44]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00418a88  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00418a89  e832c30300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418a8e  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418a94  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418a9a  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00418a9e  68ec064900             -push 0x4906ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785900 /*0x4906ec*/;
    cpu.esp -= 4;
    // 00418aa3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00418aa4  e84fe30500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418aa9  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00418aac  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00418ab0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00418ab1  e80ac30300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418ab6  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418abc  a168fd4800             -mov eax, dword ptr [0x48fd68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783464) /* 0x48fd68 */);
    // 00418ac1  8d9784000000           -lea edx, [edi + 0x84]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 00418ac7  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418acd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418ace  68e4064900             -push 0x4906e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785892 /*0x4906e4*/;
    cpu.esp -= 4;
    // 00418ad3  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00418ad5  8b0d6cfd4800           -mov ecx, dword ptr [0x48fd6c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783468) /* 0x48fd6c */);
    // 00418adb  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00418ade  a170fd4800             -mov eax, dword ptr [0x48fd70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783472) /* 0x48fd70 */);
    // 00418ae3  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00418ae6  8b0d74fd4800           -mov ecx, dword ptr [0x48fd74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783476) /* 0x48fd74 */);
    // 00418aec  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00418aef  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00418af3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00418af4  e8ffe20500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418af9  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00418afd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00418afe  e8bdc20300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418b03  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00418b07  68d8064900             -push 0x4906d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785880 /*0x4906d8*/;
    cpu.esp -= 4;
    // 00418b0c  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418b12  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418b18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00418b19  e8dae20500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418b1e  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00418b22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00418b23  e898c20300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418b28  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418b2e  8b0d68fd4800           -mov ecx, dword ptr [0x48fd68]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783464) /* 0x48fd68 */);
    // 00418b34  8d8784000000           -lea eax, [edi + 0x84]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 00418b3a  898f84000000           -mov dword ptr [edi + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 00418b40  8b156cfd4800           -mov edx, dword ptr [0x48fd6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783468) /* 0x48fd6c */);
    // 00418b46  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00418b49  8b0d70fd4800           -mov ecx, dword ptr [0x48fd70]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783472) /* 0x48fd70 */);
    // 00418b4f  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00418b52  8b1574fd4800           -mov edx, dword ptr [0x48fd74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783476) /* 0x48fd74 */);
    // 00418b58  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00418b5b  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418b61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418b62  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00418b66  68cc064900             -push 0x4906cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785868 /*0x4906cc*/;
    cpu.esp -= 4;
    // 00418b6b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00418b6c  e887e20500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418b71  8d4c243c               -lea ecx, [esp + 0x3c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00418b75  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00418b76  e845c20300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418b7b  8d542440               -lea edx, [esp + 0x40]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00418b7f  68bc064900             -push 0x4906bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785852 /*0x4906bc*/;
    cpu.esp -= 4;
    // 00418b84  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418b8a  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418b90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00418b91  e862e20500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418b96  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00418b9a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00418b9b  e820c20300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418ba0  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418ba6  8b1568fd4800           -mov edx, dword ptr [0x48fd68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783464) /* 0x48fd68 */);
    // 00418bac  8d8f84000000           -lea ecx, [edi + 0x84]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 00418bb2  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418bb8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418bb9  68b0064900             -push 0x4906b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785840 /*0x4906b0*/;
    cpu.esp -= 4;
    // 00418bbe  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00418bc0  a16cfd4800             -mov eax, dword ptr [0x48fd6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783468) /* 0x48fd6c */);
    // 00418bc5  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00418bc8  8b1570fd4800           -mov edx, dword ptr [0x48fd70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783472) /* 0x48fd70 */);
    // 00418bce  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00418bd1  a174fd4800             -mov eax, dword ptr [0x48fd74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783476) /* 0x48fd74 */);
    // 00418bd6  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00418bd9  8d4c2454               -lea ecx, [esp + 0x54]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00418bdd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00418bde  e815e20500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418be3  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00418be6  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00418bea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00418beb  e8d0c10300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418bf0  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418bf6  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418bfc  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00418c00  68a4064900             -push 0x4906a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785828 /*0x4906a4*/;
    cpu.esp -= 4;
    // 00418c05  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00418c06  e8ede10500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418c0b  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00418c0f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00418c10  e8abc10300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418c15  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418c1b  a168fd4800             -mov eax, dword ptr [0x48fd68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783464) /* 0x48fd68 */);
    // 00418c20  8d9784000000           -lea edx, [edi + 0x84]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 00418c26  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418c2c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418c2d  6898064900             -push 0x490698
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785816 /*0x490698*/;
    cpu.esp -= 4;
    // 00418c32  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00418c34  8b0d6cfd4800           -mov ecx, dword ptr [0x48fd6c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783468) /* 0x48fd6c */);
    // 00418c3a  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00418c3d  a170fd4800             -mov eax, dword ptr [0x48fd70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783472) /* 0x48fd70 */);
    // 00418c42  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00418c45  8b0d74fd4800           -mov ecx, dword ptr [0x48fd74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783476) /* 0x48fd74 */);
    // 00418c4b  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00418c4e  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00418c52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00418c53  e8a0e10500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418c58  8d44242c               -lea eax, [esp + 0x2c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00418c5c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00418c5d  e85ec10300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418c62  8d4c2430               -lea ecx, [esp + 0x30]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00418c66  6888064900             -push 0x490688
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785800 /*0x490688*/;
    cpu.esp -= 4;
    // 00418c6b  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418c71  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418c77  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00418c78  e87be10500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418c7d  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00418c81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00418c82  e839c10300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418c87  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418c8d  8b0d68fd4800           -mov ecx, dword ptr [0x48fd68]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783464) /* 0x48fd68 */);
    // 00418c93  8d8784000000           -lea eax, [edi + 0x84]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 00418c99  898f84000000           -mov dword ptr [edi + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 00418c9f  8b156cfd4800           -mov edx, dword ptr [0x48fd6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783468) /* 0x48fd6c */);
    // 00418ca5  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00418ca8  8b0d70fd4800           -mov ecx, dword ptr [0x48fd70]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783472) /* 0x48fd70 */);
    // 00418cae  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418cb4  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00418cb7  8b1574fd4800           -mov edx, dword ptr [0x48fd74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783476) /* 0x48fd74 */);
    // 00418cbd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418cbe  6880064900             -push 0x490680
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785792 /*0x490680*/;
    cpu.esp -= 4;
    // 00418cc3  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00418cc6  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00418cca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00418ccb  e828e10500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418cd0  8d4c2448               -lea ecx, [esp + 0x48]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00418cd4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00418cd5  e8e6c00300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418cda  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418ce0  a178fd4800             -mov eax, dword ptr [0x48fd78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783480) /* 0x48fd78 */);
    // 00418ce5  8d9784000000           -lea edx, [edi + 0x84]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 00418ceb  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418cf1  6870064900             -push 0x490670
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785776 /*0x490670*/;
    cpu.esp -= 4;
    // 00418cf6  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00418cf8  8b0d7cfd4800           -mov ecx, dword ptr [0x48fd7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783484) /* 0x48fd7c */);
    // 00418cfe  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00418d01  a180fd4800             -mov eax, dword ptr [0x48fd80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783488) /* 0x48fd80 */);
    // 00418d06  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00418d09  8b0d84fd4800           -mov ecx, dword ptr [0x48fd84]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783492) /* 0x48fd84 */);
    // 00418d0f  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00418d12  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00418d16  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00418d17  e8dce00500             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 00418d1c  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00418d1f  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00418d23  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00418d24  e897c00300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00418d29  8987d0000000           -mov dword ptr [edi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 00418d2f  8b1568fd4800           -mov edx, dword ptr [0x48fd68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783464) /* 0x48fd68 */);
    // 00418d35  8d8f84000000           -lea ecx, [edi + 0x84]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(132) /* 0x84 */);
    // 00418d3b  8bbfd4000000           -mov edi, dword ptr [edi + 0xd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 00418d41  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00418d44  83fb02                 +cmp ebx, 2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00418d47  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00418d49  a16cfd4800             -mov eax, dword ptr [0x48fd6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783468) /* 0x48fd6c */);
    // 00418d4e  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00418d51  8b1570fd4800           -mov edx, dword ptr [0x48fd70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783472) /* 0x48fd70 */);
    // 00418d57  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00418d5a  a174fd4800             -mov eax, dword ptr [0x48fd74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783476) /* 0x48fd74 */);
    // 00418d5f  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00418d62  7512                   -jne 0x418d76
    if (!cpu.flags.zf)
    {
        goto L_0x00418d76;
    }
    // 00418d64  e8a7760000             -call 0x420410
    cpu.esp -= 4;
    sub_420410(app, cpu);
    // 00418d69  d80d08754800           +fmul dword ptr [0x487508]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748552) /* 0x487508 */));
    // 00418d6f  e81ce00500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00418d74  eb2d                   -jmp 0x418da3
    goto L_0x00418da3;
L_0x00418d76:
    // 00418d76  83fb01                 +cmp ebx, 1
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
    // 00418d79  7523                   -jne 0x418d9e
    if (!cpu.flags.zf)
    {
        goto L_0x00418d9e;
    }
    // 00418d7b  e8a0160000             -call 0x41a420
    cpu.esp -= 4;
    sub_41a420(app, cpu);
    // 00418d80  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00418d82  e879730000             -call 0x420100
    cpu.esp -= 4;
    sub_420100(app, cpu);
    // 00418d87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00418d89  7418                   -je 0x418da3
    if (cpu.flags.zf)
    {
        goto L_0x00418da3;
    }
    // 00418d8b  d98028010000           +fld dword ptr [eax + 0x128]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(296) /* 0x128 */)));
    // 00418d91  d80d08754800           +fmul dword ptr [0x487508]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748552) /* 0x487508 */));
    // 00418d97  e8f4df0500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 00418d9c  eb05                   -jmp 0x418da3
    goto L_0x00418da3;
L_0x00418d9e:
    // 00418d9e  b832000000             -mov eax, 0x32
    cpu.eax = 50 /*0x32*/;
L_0x00418da3:
    // 00418da3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00418da4  6864064900             -push 0x490664
    app->getMemory<x86::reg32>(cpu.esp-4) = 4785764 /*0x490664*/;
    cpu.esp -= 4;
    // 00418da9  68c8bf4a00             -push 0x4abfc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4898760 /*0x4abfc8*/;
    cpu.esp -= 4;
    // 00418dae  e80bf10500             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 00418db3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00418db6  c787d0000000c8bf4a00   -mov dword ptr [edi + 0xd0], 0x4abfc8
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = 4898760 /*0x4abfc8*/;
L_0x00418dc0:
    // 00418dc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418dc1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418dc2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418dc3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418dc4  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00418dca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_418dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00418dd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418dd1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00418dd3  e8b86e0000             -call 0x41fc90
    cpu.esp -= 4;
    sub_41fc90(app, cpu);
    // 00418dd8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00418dda  751b                   -jne 0x418df7
    if (!cpu.flags.zf)
    {
        goto L_0x00418df7;
    }
    // 00418ddc  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00418ddf  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00418de1  0f8528010000           -jne 0x418f0f
    if (!cpu.flags.zf)
    {
        goto L_0x00418f0f;
    }
    // 00418de7  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00418de9  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00418df0  0c20                   +or al, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00418df2  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00418df5  eb36                   -jmp 0x418e2d
    goto L_0x00418e2d;
L_0x00418df7:
    // 00418df7  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00418dfa  c746200000803f         -mov dword ptr [esi + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 00418e01  83e1df                 -and ecx, 0xffffffdf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 00418e04  83c910                 -or ecx, 0x10
    cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00418e07  894e1c                 -mov dword ptr [esi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00418e0a  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00418e10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00418e12  7419                   -je 0x418e2d
    if (cpu.flags.zf)
    {
        goto L_0x00418e2d;
    }
L_0x00418e14:
    // 00418e14  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00418e16  b924c84a00             -mov ecx, 0x4ac824
    cpu.ecx = 4900900 /*0x4ac824*/;
    // 00418e1b  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00418e1e  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00418e20  c70101000000           -mov dword ptr [ecx], 1
    app->getMemory<x86::reg32>(cpu.ecx) = 1 /*0x1*/;
    // 00418e26  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00418e29  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00418e2b  75e7                   -jne 0x418e14
    if (!cpu.flags.zf)
    {
        goto L_0x00418e14;
    }
L_0x00418e2d:
    // 00418e2d  8b7628                 -mov esi, dword ptr [esi + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00418e30  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00418e32  0f84d7000000           -je 0x418f0f
    if (cpu.flags.zf)
    {
        goto L_0x00418f0f;
    }
    // 00418e38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00418e39  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00418e3a  bf08c84a00             -mov edi, 0x4ac808
    cpu.edi = 4900872 /*0x4ac808*/;
    // 00418e3f  bb000080bf             -mov ebx, 0xbf800000
    cpu.ebx = 3212836864 /*0xbf800000*/;
L_0x00418e44:
    // 00418e44  8b8ec0000000           -mov ecx, dword ptr [esi + 0xc0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */);
    // 00418e4a  83c901                 -or ecx, 1
    cpu.ecx |= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00418e4d  898ec0000000           -mov dword ptr [esi + 0xc0], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(192) /* 0xc0 */) = cpu.ecx;
    // 00418e53  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00418e55  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00418e57  746c                   -je 0x418ec5
    if (cpu.flags.zf)
    {
        goto L_0x00418ec5;
    }
    // 00418e59  399ec8000000           +cmp dword ptr [esi + 0xc8], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00418e5f  750a                   -jne 0x418e6b
    if (!cpu.flags.zf)
    {
        goto L_0x00418e6b;
    }
    // 00418e61  c786c800000052b89e3e   -mov dword ptr [esi + 0xc8], 0x3e9eb852
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */) = 1050589266 /*0x3e9eb852*/;
L_0x00418e6b:
    // 00418e6b  d986c8000000           +fld dword ptr [esi + 0xc8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */)));
    // 00418e71  d9fe                   +fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 00418e73  a198fd4800             -mov eax, dword ptr [0x48fd98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783512) /* 0x48fd98 */);
    // 00418e78  8d9684000000           -lea edx, [esi + 0x84]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00418e7e  dc0568734800           +fadd qword ptr [0x487368]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */));
    // 00418e84  dc0dd8744800           +fmul qword ptr [0x4874d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */));
    // 00418e8a  d91da4fd4800           +fstp dword ptr [0x48fda4]
    app->getMemory<float>(x86::reg32(4783524) /* 0x48fda4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00418e90  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00418e92  8b0d9cfd4800           -mov ecx, dword ptr [0x48fd9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783516) /* 0x48fd9c */);
    // 00418e98  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00418e9b  a1a0fd4800             -mov eax, dword ptr [0x48fda0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783520) /* 0x48fda0 */);
    // 00418ea0  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00418ea3  8b0da4fd4800           -mov ecx, dword ptr [0x48fda4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783524) /* 0x48fda4 */);
    // 00418ea9  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00418eac  e87f0e0000             -call 0x419d30
    cpu.esp -= 4;
    sub_419d30(app, cpu);
    // 00418eb1  dc0d60764800           +fmul qword ptr [0x487660]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748896) /* 0x487660 */));
    // 00418eb7  d886c8000000           +fadd dword ptr [esi + 0xc8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 00418ebd  d99ec8000000           +fstp dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00418ec3  eb31                   -jmp 0x418ef6
    goto L_0x00418ef6;
L_0x00418ec5:
    // 00418ec5  a188fd4800             -mov eax, dword ptr [0x48fd88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783496) /* 0x48fd88 */);
    // 00418eca  8d9684000000           -lea edx, [esi + 0x84]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00418ed0  898684000000           -mov dword ptr [esi + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 00418ed6  8b0d8cfd4800           -mov ecx, dword ptr [0x48fd8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783500) /* 0x48fd8c */);
    // 00418edc  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00418edf  a190fd4800             -mov eax, dword ptr [0x48fd90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783504) /* 0x48fd90 */);
    // 00418ee4  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00418ee7  8b0d94fd4800           -mov ecx, dword ptr [0x48fd94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783508) /* 0x48fd94 */);
    // 00418eed  899ec8000000           -mov dword ptr [esi + 0xc8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(200) /* 0xc8 */) = cpu.ebx;
    // 00418ef3  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x00418ef6:
    // 00418ef6  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 00418efc  8bb6d4000000           -mov esi, dword ptr [esi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 00418f02  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00418f05  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00418f07  0f8537ffffff           -jne 0x418e44
    if (!cpu.flags.zf)
    {
        goto L_0x00418e44;
    }
    // 00418f0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418f0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00418f0f:
    // 00418f0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418f10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_418f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00418f20  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00418f23  8b15a8fd4800           -mov edx, dword ptr [0x48fda8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783528) /* 0x48fda8 */);
    // 00418f29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418f2a  8d8884000000           -lea ecx, [eax + 0x84]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 00418f30  8bb0d4000000           -mov esi, dword ptr [eax + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00418f36  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00418f38  8b15acfd4800           -mov edx, dword ptr [0x48fdac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783532) /* 0x48fdac */);
    // 00418f3e  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00418f41  8b15b0fd4800           -mov edx, dword ptr [0x48fdb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783536) /* 0x48fdb0 */);
    // 00418f47  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00418f4a  8b15b4fd4800           -mov edx, dword ptr [0x48fdb4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783540) /* 0x48fdb4 */);
    // 00418f50  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00418f53  e8c8e40000             -call 0x427420
    cpu.esp -= 4;
    sub_427420(app, cpu);
    // 00418f58  8986c4000000           -mov dword ptr [esi + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 00418f5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418f5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_418f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00418f60  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00418f63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00418f64  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00418f66  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00418f67  8b7e28                 -mov edi, dword ptr [esi + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00418f6a  e871e40000             -call 0x4273e0
    cpu.esp -= 4;
    sub_4273e0(app, cpu);
    // 00418f6f  83f802                 +cmp eax, 2
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
    // 00418f72  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00418f75  741d                   -je 0x418f94
    if (cpu.flags.zf)
    {
        goto L_0x00418f94;
    }
    // 00418f77  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00418f79  0f85b0000000           -jne 0x41902f
    if (!cpu.flags.zf)
    {
        goto L_0x0041902f;
    }
    // 00418f7f  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00418f81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418f82  0c20                   -or al, 0x20
    cpu.al |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00418f84  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00418f87  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00418f89  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00418f8c  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00418f8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00418f90  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00418f93  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00418f94:
    // 00418f94  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00418f96  7412                   -je 0x418faa
    if (cpu.flags.zf)
    {
        goto L_0x00418faa;
    }
    // 00418f98  24df                   -and al, 0xdf
    cpu.al &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 00418f9a  0c10                   -or al, 0x10
    cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00418f9c  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00418f9f  b80000803f             -mov eax, 0x3f800000
    cpu.eax = 1065353216 /*0x3f800000*/;
    // 00418fa4  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00418fa7  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00418faa:
    // 00418faa  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00418fae  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00418fb2  e849e40000             -call 0x427400
    cpu.esp -= 4;
    sub_427400(app, cpu);
    // 00418fb7  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00418fbb  81c784000000           -add edi, 0x84
    (cpu.edi) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 00418fc1  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00418fc4  03c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00418fc6  8947dc                 -mov dword ptr [edi - 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00418fc9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00418fcd  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00418fd0  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00418fd3  894fe0                 -mov dword ptr [edi - 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-32) /* -0x20 */) = cpu.ecx;
    // 00418fd6  8b15b8fd4800           -mov edx, dword ptr [0x48fdb8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783544) /* 0x48fdb8 */);
    // 00418fdc  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 00418fde  a1bcfd4800             -mov eax, dword ptr [0x48fdbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783548) /* 0x48fdbc */);
    // 00418fe3  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00418fe6  8b0dc0fd4800           -mov ecx, dword ptr [0x48fdc0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4783552) /* 0x48fdc0 */);
    // 00418fec  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00418fef  8b15c4fd4800           -mov edx, dword ptr [0x48fdc4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4783556) /* 0x48fdc4 */);
    // 00418ff5  89570c                 -mov dword ptr [edi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00418ff8  d90528c84a00           -fld dword ptr [0x4ac828]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4900904) /* 0x4ac828 */)));
    // 00418ffe  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 00419000  dc0568734800           -fadd qword ptr [0x487368]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */));
    // 00419006  dc0d00764800           -fmul qword ptr [0x487600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748800) /* 0x487600 */));
    // 0041900c  dc05d8744800           -fadd qword ptr [0x4874d8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */));
    // 00419012  d91dc4fd4800           -fstp dword ptr [0x48fdc4]
    app->getMemory<float>(x86::reg32(4783556) /* 0x48fdc4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00419018  e8130d0000             -call 0x419d30
    cpu.esp -= 4;
    sub_419d30(app, cpu);
    // 0041901d  d80db8744800           -fmul dword ptr [0x4874b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 00419023  d80528c84a00           -fadd dword ptr [0x4ac828]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4900904) /* 0x4ac828 */));
    // 00419029  d91d28c84a00           -fstp dword ptr [0x4ac828]
    app->getMemory<float>(x86::reg32(4900904) /* 0x4ac828 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0041902f:
    // 0041902f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419030  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419031  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00419034  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419040  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00419042  8d0492                 -lea eax, [edx + edx*4]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 4);
    // 00419045  8d1442                 -lea edx, [edx + eax*2]
    cpu.edx = x86::reg32(cpu.edx + cpu.eax * 2);
    // 00419048  8b0495c8fd4800         -mov eax, dword ptr [edx*4 + 0x48fdc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4783560) /* 0x48fdc8 */ + cpu.edx * 4);
    // 0041904f  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00419051  c7052cc84a0001000000   -mov dword ptr [0x4ac82c], 1
    app->getMemory<x86::reg32>(x86::reg32(4900908) /* 0x4ac82c */) = 1 /*0x1*/;
    // 0041905b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419060  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 00419063  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419064  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00419068  8d0441                 -lea eax, [ecx + eax*2]
    cpu.eax = x86::reg32(cpu.ecx + cpu.eax * 2);
    // 0041906b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0041906e  8b88d4fd4800           -mov ecx, dword ptr [eax + 0x48fdd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4783572) /* 0x48fdd4 */);
    // 00419074  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00419076  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041907a  8b88d8fd4800           -mov ecx, dword ptr [eax + 0x48fdd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4783576) /* 0x48fdd8 */);
    // 00419080  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00419082  8b88ccfd4800           -mov ecx, dword ptr [eax + 0x48fdcc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4783564) /* 0x48fdcc */);
    // 00419088  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0041908a  8b90d0fd4800           -mov edx, dword ptr [eax + 0x48fdd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4783568) /* 0x48fdd0 */);
    // 00419090  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00419094  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419095  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00419097  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::asm_sub_4190a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004190a0  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 004190a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004190a4  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004190a6  8d0c41                 -lea ecx, [ecx + eax*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.eax * 2);
    // 004190a9  b867666666             -mov eax, 0x66666667
    cpu.eax = 1717986919 /*0x66666667*/;
    // 004190ae  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004190b1  8b91d4fd4800           -mov edx, dword ptr [ecx + 0x48fdd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4783572) /* 0x48fdd4 */);
    // 004190b7  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004190b9  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 004190bc  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004190be  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 004190c1  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004190c3  b889888888             -mov eax, 0x88888889
    cpu.eax = 2290649225 /*0x88888889*/;
    // 004190c8  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004190ca  8b89d8fd4800           -mov ecx, dword ptr [ecx + 0x48fdd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4783576) /* 0x48fdd8 */);
    // 004190d0  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004190d2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004190d6  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004190d8  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 004190db  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004190dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004190de  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 004190e1  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004190e3  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004190e5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_4190f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004190f0  a130c84a00             -mov eax, dword ptr [0x4ac830]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900912) /* 0x4ac830 */);
    // 004190f5  83f805                 +cmp eax, 5
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
    // 004190f8  744f                   -je 0x419149
    if (cpu.flags.zf)
    {
        goto L_0x00419149;
    }
    // 004190fa  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 004190fd  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004190ff  0528c64a00             -add eax, 0x4ac628
    (cpu.eax) += x86::reg32(x86::sreg32(4900392 /*0x4ac628*/));
    // 00419104  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00419105  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00419106  e822ee0500             -call 0x477f2d
    cpu.esp -= 4;
    sub_477f2d(app, cpu);
    // 0041910b  a130c84a00             -mov eax, dword ptr [0x4ac830]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900912) /* 0x4ac830 */);
    // 00419110  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 00419113  0528c64a00             -add eax, 0x4ac628
    (cpu.eax) += x86::reg32(x86::sreg32(4900392 /*0x4ac628*/));
    // 00419118  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00419119  e87fec0500             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 0041911e  8b1530c84a00           -mov edx, dword ptr [0x4ac830]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900912) /* 0x4ac830 */);
    // 00419124  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00419127  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00419129  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0041912c  03c8                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041912e  03c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00419130  42                     -inc edx
    (cpu.edx)++;
    // 00419131  891530c84a00           -mov dword ptr [0x4ac830], edx
    app->getMemory<x86::reg32>(x86::reg32(4900912) /* 0x4ac830 */) = cpu.edx;
    // 00419137  66c78128c64a002000     -mov word ptr [ecx + 0x4ac628], 0x20
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4900392) /* 0x4ac628 */) = 32 /*0x20*/;
    // 00419140  66c7812ac64a000000     -mov word ptr [ecx + 0x4ac62a], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4900394) /* 0x4ac62a */) = 0 /*0x0*/;
L_0x00419149:
    // 00419149  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419150  b828c64a00             -mov eax, 0x4ac628
    cpu.eax = 4900392 /*0x4ac628*/;
L_0x00419155:
    // 00419155  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 0041915a  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0041915d  3d68c74a00             +cmp eax, 0x4ac768
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4900712 /*0x4ac768*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00419162  7cf1                   -jl 0x419155
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00419155;
    }
    // 00419164  c70530c84a0000000000   -mov dword ptr [0x4ac830], 0
    app->getMemory<x86::reg32>(x86::reg32(4900912) /* 0x4ac830 */) = 0 /*0x0*/;
    // 0041916e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419170  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419171  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00419172  8b7928                 -mov edi, dword ptr [ecx + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00419175  e8d6e30000             -call 0x427550
    cpu.esp -= 4;
    sub_427550(app, cpu);
    // 0041917a  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041917c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041917e  0f8cd1000000           -jl 0x419255
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00419255;
    }
    // 00419184  3b3504004900           +cmp esi, dword ptr [0x490004]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4784132) /* 0x490004 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041918a  0f8dc5000000           -jge 0x419255
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00419255;
    }
    // 00419190  8b8fbc000000           -mov ecx, dword ptr [edi + 0xbc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(188) /* 0xbc */);
    // 00419196  8d04b6                 -lea eax, [esi + esi*4]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 4);
    // 00419199  8d0446                 -lea eax, [esi + eax*2]
    cpu.eax = x86::reg32(cpu.esi + cpu.eax * 2);
    // 0041919c  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0041919f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004191a2  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 004191a5  8b90c8fd4800           -mov edx, dword ptr [eax + 0x48fdc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4783560) /* 0x48fdc8 */);
    // 004191ab  83fe01                 +cmp esi, 1
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
    // 004191ae  899128d74800           -mov dword ptr [ecx + 0x48d728], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773672) /* 0x48d728 */) = cpu.edx;
    // 004191b4  8b8fd4000000           -mov ecx, dword ptr [edi + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 004191ba  7424                   -je 0x4191e0
    if (cpu.flags.zf)
    {
        goto L_0x004191e0;
    }
    // 004191bc  83fe07                 +cmp esi, 7
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004191bf  741f                   -je 0x4191e0
    if (cpu.flags.zf)
    {
        goto L_0x004191e0;
    }
    // 004191c1  83fe06                 +cmp esi, 6
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
    // 004191c4  741a                   -je 0x4191e0
    if (cpu.flags.zf)
    {
        goto L_0x004191e0;
    }
    // 004191c6  83fe08                 +cmp esi, 8
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
    // 004191c9  7415                   -je 0x4191e0
    if (cpu.flags.zf)
    {
        goto L_0x004191e0;
    }
    // 004191cb  83fe09                 +cmp esi, 9
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
    // 004191ce  7410                   -je 0x4191e0
    if (cpu.flags.zf)
    {
        goto L_0x004191e0;
    }
    // 004191d0  83fe0a                 +cmp esi, 0xa
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
    // 004191d3  740b                   -je 0x4191e0
    if (cpu.flags.zf)
    {
        goto L_0x004191e0;
    }
    // 004191d5  8b91c0000000           -mov edx, dword ptr [ecx + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(192) /* 0xc0 */);
    // 004191db  83e2df                 +and edx, 0xffffffdf
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/))));
    // 004191de  eb09                   -jmp 0x4191e9
    goto L_0x004191e9;
L_0x004191e0:
    // 004191e0  8b91c0000000           -mov edx, dword ptr [ecx + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(192) /* 0xc0 */);
    // 004191e6  83ca20                 -or edx, 0x20
    cpu.edx |= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004191e9:
    // 004191e9  8991c0000000           -mov dword ptr [ecx + 0xc0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(192) /* 0xc0 */) = cpu.edx;
    // 004191ef  8b90ccfd4800           -mov edx, dword ptr [eax + 0x48fdcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4783564) /* 0x48fdcc */);
    // 004191f5  895160                 -mov dword ptr [ecx + 0x60], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 004191f8  8b90d0fd4800           -mov edx, dword ptr [eax + 0x48fdd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4783568) /* 0x48fdd0 */);
    // 004191fe  895164                 -mov dword ptr [ecx + 0x64], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 00419201  8b91bc000000           -mov edx, dword ptr [ecx + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */);
    // 00419207  8bb8d4fd4800           -mov edi, dword ptr [eax + 0x48fdd4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4783572) /* 0x48fdd4 */);
    // 0041920d  8d1452                 -lea edx, [edx + edx*2]
    cpu.edx = x86::reg32(cpu.edx + cpu.edx * 2);
    // 00419210  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00419213  89ba34d74800           -mov dword ptr [edx + 0x48d734], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4773684) /* 0x48d734 */) = cpu.edi;
    // 00419219  8b91bc000000           -mov edx, dword ptr [ecx + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */);
    // 0041921f  8bb8d8fd4800           -mov edi, dword ptr [eax + 0x48fdd8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4783576) /* 0x48fdd8 */);
    // 00419225  8d80e4fd4800           -lea eax, [eax + 0x48fde4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4783588) /* 0x48fde4 */);
    // 0041922b  8d1452                 -lea edx, [edx + edx*2]
    cpu.edx = x86::reg32(cpu.edx + cpu.edx * 2);
    // 0041922e  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00419231  81c184000000           +add ecx, 0x84
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00419237  89ba38d74800           -mov dword ptr [edx + 0x48d738], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4773688) /* 0x48d738 */) = cpu.edi;
    // 0041923d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041923f  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00419241  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00419244  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00419247  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041924a  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041924d  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00419250  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00419253  eb0e                   -jmp 0x419263
    goto L_0x00419263;
L_0x00419255:
    // 00419255  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419256  6890074900             -push 0x490790
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786064 /*0x490790*/;
    cpu.esp -= 4;
    // 0041925b  e8b0b90000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00419260  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00419263:
    // 00419263  e8d8e10000             -call 0x427440
    cpu.esp -= 4;
    sub_427440(app, cpu);
    // 00419268  83fe07                 +cmp esi, 7
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041926b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041926c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041926d  7505                   -jne 0x419274
    if (!cpu.flags.zf)
    {
        goto L_0x00419274;
    }
    // 0041926f  e90c000000             -jmp 0x419280
    goto L_0x00419280;
L_0x00419274:
    // 00419274  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00419280:
    // 00419280  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419281  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00419282  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 00419287  e824de0000             -call 0x4270b0
    cpu.esp -= 4;
    sub_4270b0(app, cpu);
    // 0041928c  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041928e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00419290  0f84b7000000           -je 0x41934d
    if (cpu.flags.zf)
    {
        goto L_0x0041934d;
    }
    // 00419296  a134c84a00             -mov eax, dword ptr [0x4ac834]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900916) /* 0x4ac834 */);
    // 0041929b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041929d  751d                   -jne 0x4192bc
    if (!cpu.flags.zf)
    {
        goto L_0x004192bc;
    }
    // 0041929f  a138c84a00             -mov eax, dword ptr [0x4ac838]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900920) /* 0x4ac838 */);
    // 004192a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004192a6  7514                   -jne 0x4192bc
    if (!cpu.flags.zf)
    {
        goto L_0x004192bc;
    }
    // 004192a8  6838c84a00             -push 0x4ac838
    app->getMemory<x86::reg32>(cpu.esp-4) = 4900920 /*0x4ac838*/;
    cpu.esp -= 4;
    // 004192ad  ba34c84a00             -mov edx, 0x4ac834
    cpu.edx = 4900916 /*0x4ac834*/;
    // 004192b2  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 004192b7  e8e4fdffff             -call 0x4190a0
    cpu.esp -= 4;
    sub_4190a0(app, cpu);
L_0x004192bc:
    // 004192bc  a138c84a00             -mov eax, dword ptr [0x4ac838]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900920) /* 0x4ac838 */);
    // 004192c1  83f801                 +cmp eax, 1
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
    // 004192c4  740e                   -je 0x4192d4
    if (cpu.flags.zf)
    {
        goto L_0x004192d4;
    }
    // 004192c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004192c7  68b4074900             -push 0x4907b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786100 /*0x4907b4*/;
    cpu.esp -= 4;
    // 004192cc  e83fb90000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004192d1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004192d4:
    // 004192d4  e827030000             -call 0x419600
    cpu.esp -= 4;
    sub_419600(app, cpu);
    // 004192d9  b10e                   -mov cl, 0xe
    cpu.cl = 14 /*0xe*/;
    // 004192db  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004192dd  e8fe980400             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004192e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004192e4  742e                   -je 0x419314
    if (cpu.flags.zf)
    {
        goto L_0x00419314;
    }
    // 004192e6  be20000000             -mov esi, 0x20
    cpu.esi = 32 /*0x20*/;
L_0x004192eb:
    // 004192eb  393508004900           +cmp dword ptr [0x490008], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4784136) /* 0x490008 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004192f1  7454                   -je 0x419347
    if (cpu.flags.zf)
    {
        goto L_0x00419347;
    }
    // 004192f3  83feff                 +cmp esi, -1
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
    // 004192f6  744f                   -je 0x419347
    if (cpu.flags.zf)
    {
        goto L_0x00419347;
    }
    // 004192f8  8b1534c84a00           -mov edx, dword ptr [0x4ac834]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900916) /* 0x4ac834 */);
    // 004192fe  83fe20                 +cmp esi, 0x20
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
    // 00419301  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00419303  743d                   -je 0x419342
    if (cpu.flags.zf)
    {
        goto L_0x00419342;
    }
    // 00419305  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419306  e845000000             -call 0x419350
    cpu.esp -= 4;
    sub_419350(app, cpu);
    // 0041930b  893508004900           -mov dword ptr [0x490008], esi
    app->getMemory<x86::reg32>(x86::reg32(4784136) /* 0x490008 */) = cpu.esi;
    // 00419311  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419312  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419313  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00419314:
    // 00419314  b11c                   -mov cl, 0x1c
    cpu.cl = 28 /*0x1c*/;
    // 00419316  e8c5980400             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0041931b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041931d  74cc                   -je 0x4192eb
    if (cpu.flags.zf)
    {
        goto L_0x004192eb;
    }
    // 0041931f  a134c84a00             -mov eax, dword ptr [0x4ac834]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900916) /* 0x4ac834 */);
    // 00419324  66837c47fc20           +cmp word ptr [edi + eax*2 - 4], 0x20
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(-4) /* -0x4 */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32 /*0x20*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0041932a  7421                   -je 0x41934d
    if (cpu.flags.zf)
    {
        goto L_0x0041934d;
    }
    // 0041932c  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041932e  e88d000000             -call 0x4193c0
    cpu.esp -= 4;
    sub_4193c0(app, cpu);
    // 00419333  8b1534c84a00           -mov edx, dword ptr [0x4ac834]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900916) /* 0x4ac834 */);
    // 00419339  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0041933b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041933c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041933d  e95e000000             -jmp 0x4193a0
    return sub_4193a0(app, cpu);
L_0x00419342:
    // 00419342  e839000000             -call 0x419380
    cpu.esp -= 4;
    sub_419380(app, cpu);
L_0x00419347:
    // 00419347  893508004900           -mov dword ptr [0x490008], esi
    app->getMemory<x86::reg32>(x86::reg32(4784136) /* 0x490008 */) = cpu.esi;
L_0x0041934d:
    // 0041934d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041934e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041934f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419350  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00419352  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00419355  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00419357  7e0c                   -jle 0x419365
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00419365;
    }
    // 00419359  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041935a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041935b  8d7002                 -lea esi, [eax + 2]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0041935e  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00419360  66f3a5                 -rep movsw word ptr es:[edi], word ptr [esi]
    while (cpu.ecx)
    {
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
        --cpu.ecx;
    }
    // 00419363  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419364  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00419365:
    // 00419365  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00419369  83c130                 -add ecx, 0x30
    (cpu.ecx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0041936c  66894c50fc             -mov word ptr [eax + edx*2 - 4], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-4) /* -0x4 */ + cpu.edx * 2) = cpu.cx;
    // 00419371  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_419380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419380  8d42fd                 -lea eax, [edx - 3]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-3) /* -0x3 */);
    // 00419383  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00419385  7c0c                   -jl 0x419393
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00419393;
    }
L_0x00419387:
    // 00419387  668b1441               -mov dx, word ptr [ecx + eax*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 2);
    // 0041938b  6689544102             -mov word ptr [ecx + eax*2 + 2], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */ + cpu.eax * 2) = cpu.dx;
    // 00419390  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00419391  79f4                   -jns 0x419387
    if (!cpu.flags.sf)
    {
        goto L_0x00419387;
    }
L_0x00419393:
    // 00419393  66c7012000             -mov word ptr [ecx], 0x20
    app->getMemory<x86::reg16>(cpu.ecx) = 32 /*0x20*/;
    // 00419398  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4193a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004193a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004193a1  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004193a3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004193a5  7e10                   -jle 0x4193b7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004193b7;
    }
    // 004193a7  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004193a9  b820002000             -mov eax, 0x200020
    cpu.eax = 2097184 /*0x200020*/;
    // 004193ae  d1e9                   +shr ecx, 1
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
    // 004193b0  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 004193b2  13c9                   -adc ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004193b4  66f3ab                 -rep stosw word ptr es:[edi], ax
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
L_0x004193b7:
    // 004193b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004193b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4193c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004193c0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004193c3  a130c84a00             -mov eax, dword ptr [0x4ac830]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900912) /* 0x4ac830 */);
    // 004193c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004193c9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004193ca  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004193cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004193cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004193ce  3bc5                   +cmp eax, ebp
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
    // 004193d0  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004193d2  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 004193d6  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004193da  7e5d                   -jle 0x419439
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00419439;
    }
    // 004193dc  bb28c64a00             -mov ebx, 0x4ac628
    cpu.ebx = 4900392 /*0x4ac628*/;
L_0x004193e1:
    // 004193e1  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004193e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004193e7  754c                   -jne 0x419435
    if (!cpu.flags.zf)
    {
        goto L_0x00419435;
    }
    // 004193e9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004193eb:
    // 004193eb  668b0c47               -mov cx, word ptr [edi + eax*2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi + cpu.eax * 2);
    // 004193ef  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 004193f2  7434                   -je 0x419428
    if (cpu.flags.zf)
    {
        goto L_0x00419428;
    }
    // 004193f4  6683f920               +cmp cx, 0x20
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32 /*0x20*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004193f8  7508                   -jne 0x419402
    if (!cpu.flags.zf)
    {
        goto L_0x00419402;
    }
    // 004193fa  40                     -inc eax
    (cpu.eax)++;
    // 004193fb  83f820                 +cmp eax, 0x20
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
    // 004193fe  7ceb                   -jl 0x4193eb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004193eb;
    }
    // 00419400  eb26                   -jmp 0x419428
    goto L_0x00419428;
L_0x00419402:
    // 00419402  8d3447                 -lea esi, [edi + eax*2]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 2);
    // 00419405  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00419406  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00419407  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419408  68f4074900             -push 0x4907f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786164 /*0x4907f4*/;
    cpu.esp -= 4;
    // 0041940d  e878ec0500             -call 0x47808a
    cpu.esp -= 4;
    sub_47808a(app, cpu);
    // 00419412  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00419413  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419414  e87dc20600             -call 0x485696
    cpu.esp -= 4;
    sub_485696(app, cpu);
    // 00419419  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0041941c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041941e  7508                   -jne 0x419428
    if (!cpu.flags.zf)
    {
        goto L_0x00419428;
    }
    // 00419420  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
L_0x00419428:
    // 00419428  a130c84a00             -mov eax, dword ptr [0x4ac830]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900912) /* 0x4ac830 */);
    // 0041942d  45                     -inc ebp
    (cpu.ebp)++;
    // 0041942e  83c340                 -add ebx, 0x40
    (cpu.ebx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00419431  3be8                   +cmp ebp, eax
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
    // 00419433  7cac                   -jl 0x4193e1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004193e1;
    }
L_0x00419435:
    // 00419435  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
L_0x00419439:
    // 00419439  b9ec074900             -mov ecx, 0x4907ec
    cpu.ecx = 4786156 /*0x4907ec*/;
    // 0041943e  e84d950100             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 00419443  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00419445  83feff                 +cmp esi, -1
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
    // 00419448  7443                   -je 0x41948d
    if (cpu.flags.zf)
    {
        goto L_0x0041948d;
    }
    // 0041944a  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 0041944f  e80ce30000             -call 0x427760
    cpu.esp -= 4;
    sub_427760(app, cpu);
    // 00419454  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 00419459  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0041945c  8bb118030000           -mov esi, dword ptr [ecx + 0x318]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(792) /* 0x318 */);
    // 00419462  b9d8074900             -mov ecx, 0x4907d8
    cpu.ecx = 4786136 /*0x4907d8*/;
    // 00419467  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00419469  e8a2d70400             -call 0x466c10
    cpu.esp -= 4;
    sub_466c10(app, cpu);
    // 0041946e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00419470  741b                   -je 0x41948d
    if (cpu.flags.zf)
    {
        goto L_0x0041948d;
    }
    // 00419472  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 00419476  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00419479  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041947b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041947d  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00419481  db44241c               -fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 00419485  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00419488  e8b3e40400             -call 0x467940
    cpu.esp -= 4;
    sub_467940(app, cpu);
L_0x0041948d:
    // 0041948d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041948e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041948f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419490  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419491  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00419494  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4194a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004194a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004194a1  8b7928                 -mov edi, dword ptr [ecx + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004194a4  e837df0000             -call 0x4273e0
    cpu.esp -= 4;
    sub_4273e0(app, cpu);
    // 004194a9  83f8ff                 +cmp eax, -1
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
    // 004194ac  7546                   -jne 0x4194f4
    if (!cpu.flags.zf)
    {
        goto L_0x004194f4;
    }
    // 004194ae  e8cd670100             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 004194b3  83f817                 +cmp eax, 0x17
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
    // 004194b6  0f8503010000           -jne 0x4195bf
    if (!cpu.flags.zf)
    {
        goto L_0x004195bf;
    }
    // 004194bc  8b87bc000000           -mov eax, dword ptr [edi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(188) /* 0xbc */);
    // 004194c2  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 004194c5  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004194c8  c7803cd7480000008042   -mov dword ptr [eax + 0x48d73c], 0x42800000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773692) /* 0x48d73c */) = 1115684864 /*0x42800000*/;
    // 004194d2  8bbfbc000000           -mov edi, dword ptr [edi + 0xbc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(188) /* 0xbc */);
    // 004194d8  c7050c004900feffffff   -mov dword ptr [0x49000c], 0xfffffffe
    app->getMemory<x86::reg32>(x86::reg32(4784140) /* 0x49000c */) = 4294967294 /*0xfffffffe*/;
    // 004194e2  8d0c7f                 -lea ecx, [edi + edi*2]
    cpu.ecx = x86::reg32(cpu.edi + cpu.edi * 2);
    // 004194e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004194e6  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 004194e9  c78140d7480000000043   -mov dword ptr [ecx + 0x48d740], 0x43000000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773696) /* 0x48d740 */) = 1124073472 /*0x43000000*/;
    // 004194f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004194f4:
    // 004194f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004194f5  e856e00000             -call 0x427550
    cpu.esp -= 4;
    sub_427550(app, cpu);
    // 004194fa  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004194fc  a10c004900             -mov eax, dword ptr [0x49000c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784140) /* 0x49000c */);
    // 00419501  3bc6                   +cmp eax, esi
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
    // 00419503  745b                   -je 0x419560
    if (cpu.flags.zf)
    {
        goto L_0x00419560;
    }
    // 00419505  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00419507  7c49                   -jl 0x419552
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00419552;
    }
    // 00419509  3b3504004900           +cmp esi, dword ptr [0x490004]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4784132) /* 0x490004 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041950f  7d41                   -jge 0x419552
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00419552;
    }
    // 00419511  8b8fbc000000           -mov ecx, dword ptr [edi + 0xbc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(188) /* 0xbc */);
    // 00419517  8d14b6                 -lea edx, [esi + esi*4]
    cpu.edx = x86::reg32(cpu.esi + cpu.esi * 4);
    // 0041951a  8d0456                 -lea eax, [esi + edx*2]
    cpu.eax = x86::reg32(cpu.esi + cpu.edx * 2);
    // 0041951d  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00419520  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00419523  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00419526  8b90dcfd4800           -mov edx, dword ptr [eax + 0x48fddc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4783580) /* 0x48fddc */);
    // 0041952c  89913cd74800           -mov dword ptr [ecx + 0x48d73c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773692) /* 0x48d73c */) = cpu.edx;
    // 00419532  8b8fbc000000           -mov ecx, dword ptr [edi + 0xbc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(188) /* 0xbc */);
    // 00419538  8b90e0fd4800           -mov edx, dword ptr [eax + 0x48fde0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4783584) /* 0x48fde0 */);
    // 0041953e  89350c004900           -mov dword ptr [0x49000c], esi
    app->getMemory<x86::reg32>(x86::reg32(4784140) /* 0x49000c */) = cpu.esi;
    // 00419544  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00419547  c1e104                 +shl ecx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.ecx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0041954a  899140d74800           -mov dword ptr [ecx + 0x48d740], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773696) /* 0x48d740 */) = cpu.edx;
    // 00419550  eb0e                   -jmp 0x419560
    goto L_0x00419560;
L_0x00419552:
    // 00419552  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419553  6890074900             -push 0x490790
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786064 /*0x490790*/;
    cpu.esp -= 4;
    // 00419558  e8b3b60000             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0041955d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00419560:
    // 00419560  8b87c0000000           -mov eax, dword ptr [edi + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(192) /* 0xc0 */);
    // 00419566  83fe03                 +cmp esi, 3
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
    // 00419569  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041956a  7441                   -je 0x4195ad
    if (cpu.flags.zf)
    {
        goto L_0x004195ad;
    }
    // 0041956c  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0041956e  8987c0000000           -mov dword ptr [edi + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00419574  d9053cc84a00           -fld dword ptr [0x4ac83c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4900924) /* 0x4ac83c */)));
    // 0041957a  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0041957c  dc0568734800           -fadd qword ptr [0x487368]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */));
    // 00419582  dc0d00764800           -fmul qword ptr [0x487600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748800) /* 0x487600 */));
    // 00419588  dc05d8744800           -fadd qword ptr [0x4874d8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748504) /* 0x4874d8 */));
    // 0041958e  d99f90000000           -fstp dword ptr [edi + 0x90]
    app->getMemory<float>(cpu.edi + x86::reg32(144) /* 0x90 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00419594  e897070000             -call 0x419d30
    cpu.esp -= 4;
    sub_419d30(app, cpu);
    // 00419599  d80db8744800           -fmul dword ptr [0x4874b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 0041959f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004195a0  d8053cc84a00           -fadd dword ptr [0x4ac83c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4900924) /* 0x4ac83c */));
    // 004195a6  d91d3cc84a00           -fstp dword ptr [0x4ac83c]
    app->getMemory<float>(x86::reg32(4900924) /* 0x4ac83c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004195ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004195ad:
    // 004195ad  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004195af  c7879000000000000000   -mov dword ptr [edi + 0x90], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */) = 0 /*0x0*/;
    // 004195b9  8987c0000000           -mov dword ptr [edi + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(192) /* 0xc0 */) = cpu.eax;
L_0x004195bf:
    // 004195bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004195c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4195d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004195d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004195d1  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004195d3:
    // 004195d3  8a0cb510004900         -mov cl, byte ptr [esi*4 + 0x490010]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(4784144) /* 0x490010 */ + cpu.esi * 4);
    // 004195da  e801960400             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 004195df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004195e1  750b                   -jne 0x4195ee
    if (!cpu.flags.zf)
    {
        goto L_0x004195ee;
    }
    // 004195e3  46                     -inc esi
    (cpu.esi)++;
    // 004195e4  83fe14                 +cmp esi, 0x14
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004195e7  7cea                   -jl 0x4195d3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004195d3;
    }
    // 004195e9  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004195ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004195ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004195ee:
    // 004195ee  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004195f0  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 004195f5  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004195f6  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004195f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004195f9  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004195fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419600  0fbe0560004900         -movsx eax, byte ptr [0x490060]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(4784224) /* 0x490060 */)));
    // 00419607  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419610  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419611  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00419613  d94624                 -fld dword ptr [esi + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(36) /* 0x24 */)));
    // 00419616  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 0041961c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041961e  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00419621  7a1b                   -jp 0x41963e
    if (cpu.flags.pf)
    {
        goto L_0x0041963e;
    }
    // 00419623  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00419626  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00419628  3bc6                   +cmp eax, esi
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
    // 0041962a  7460                   -je 0x41968c
    if (cpu.flags.zf)
    {
        goto L_0x0041968c;
    }
L_0x0041962c:
    // 0041962c  89b090000000           -mov dword ptr [eax + 0x90], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */) = cpu.esi;
    // 00419632  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00419638  3bc6                   +cmp eax, esi
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
    // 0041963a  75f0                   -jne 0x41962c
    if (!cpu.flags.zf)
    {
        goto L_0x0041962c;
    }
    // 0041963c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041963d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041963e:
    // 0041963e  e88dffffff             -call 0x4195d0
    cpu.esp -= 4;
    sub_4195d0(app, cpu);
    // 00419643  a364004900             -mov dword ptr [0x490064], eax
    app->getMemory<x86::reg32>(x86::reg32(4784228) /* 0x490064 */) = cpu.eax;
    // 00419648  a260004900             -mov byte ptr [0x490060], al
    app->getMemory<x86::reg8>(x86::reg32(4784224) /* 0x490060 */) = cpu.al;
    // 0041964d  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00419650  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00419652  3bce                   +cmp ecx, esi
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
    // 00419654  7436                   -je 0x41968c
    if (cpu.flags.zf)
    {
        goto L_0x0041968c;
    }
    // 00419656  ba0b000000             -mov edx, 0xb
    cpu.edx = 11 /*0xb*/;
    // 0041965b  eb05                   -jmp 0x419662
    goto L_0x00419662;
L_0x0041965d:
    // 0041965d  a164004900             -mov eax, dword ptr [0x490064]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784228) /* 0x490064 */);
L_0x00419662:
    // 00419662  83fa0a                 +cmp edx, 0xa
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
    // 00419665  7d14                   -jge 0x41967b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041967b;
    }
    // 00419667  3bd6                   +cmp edx, esi
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
    // 00419669  7c10                   -jl 0x41967b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041967b;
    }
    // 0041966b  3bd0                   +cmp edx, eax
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
    // 0041966d  750c                   -jne 0x41967b
    if (!cpu.flags.zf)
    {
        goto L_0x0041967b;
    }
    // 0041966f  c781900000000000803f   -mov dword ptr [ecx + 0x90], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = 1065353216 /*0x3f800000*/;
    // 00419679  eb06                   -jmp 0x419681
    goto L_0x00419681;
L_0x0041967b:
    // 0041967b  89b190000000           -mov dword ptr [ecx + 0x90], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.esi;
L_0x00419681:
    // 00419681  8b89d4000000           -mov ecx, dword ptr [ecx + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 00419687  4a                     -dec edx
    (cpu.edx)--;
    // 00419688  3bce                   +cmp ecx, esi
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
    // 0041968a  75d1                   -jne 0x41965d
    if (!cpu.flags.zf)
    {
        goto L_0x0041965d;
    }
L_0x0041968c:
    // 0041968c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041968d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419690  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 00419695  8b8068050000           -mov eax, dword ptr [eax + 0x568]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1384) /* 0x568 */);
    // 0041969b  8b88d0000000           -mov ecx, dword ptr [eax + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */);
    // 004196a1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004196a3  7407                   -je 0x4196ac
    if (cpu.flags.zf)
    {
        goto L_0x004196ac;
    }
    // 004196a5  8b80c4000000           -mov eax, dword ptr [eax + 0xc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 004196ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004196ac:
    // 004196ac  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004196af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4196b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004196b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004196b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004196b2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004196b3  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004196b5  e806b70300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 004196ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004196bb  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004196bd  e8feb60300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 004196c2  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004196c4  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004196c8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004196c9  e8f2b60300             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 004196ce  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004196d1  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004196d3  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004196d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004196d6  e805000000             -call 0x4196e0
    cpu.esp -= 4;
    sub_4196e0(app, cpu);
    // 004196db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004196dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004196dd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_4196e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004196e0  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004196e3  a188c74a00             -mov eax, dword ptr [0x4ac788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 004196e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004196e9  0540050000             -add eax, 0x540
    (cpu.eax) += x86::reg32(x86::sreg32(1344 /*0x540*/));
    // 004196ee  c74424040000803f       -mov dword ptr [esp + 4], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 1065353216 /*0x3f800000*/;
    // 004196f6  c7442408abaa2a3f       -mov dword ptr [esp + 8], 0x3f2aaaab
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1059760811 /*0x3f2aaaab*/;
    // 004196fe  c744240c00000000       -mov dword ptr [esp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00419706  8b701c                 -mov esi, dword ptr [eax + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00419709  c740200000803f         -mov dword ptr [eax + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 00419710  83e6df                 -and esi, 0xffffffdf
    cpu.esi &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 00419713  c74424100000803f       -mov dword ptr [esp + 0x10], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1065353216 /*0x3f800000*/;
    // 0041971b  83ce10                 -or esi, 0x10
    cpu.esi |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041971e  89701c                 -mov dword ptr [eax + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 00419721  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00419724  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00419726  c780cc00000001000000   -mov dword ptr [eax + 0xcc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = 1 /*0x1*/;
    // 00419730  89b0d0000000           -mov dword ptr [eax + 0xd0], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */) = cpu.esi;
    // 00419736  89b0c4000000           -mov dword ptr [eax + 0xc4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = cpu.esi;
    // 0041973c  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00419742  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00419746  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041974c  8988d0000000           -mov dword ptr [eax + 0xd0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */) = cpu.ecx;
    // 00419752  8d8884000000           -lea ecx, [eax + 0x84]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 00419758  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 0041975e  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 00419760  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00419764  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00419767  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041976b  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0041976e  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00419772  89710c                 -mov dword ptr [ecx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00419775  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00419779  8988d0000000           -mov dword ptr [eax + 0xd0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */) = cpu.ecx;
    // 0041977f  8b80d4000000           -mov eax, dword ptr [eax + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00419785  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419786  8990d0000000           -mov dword ptr [eax + 0xd0], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */) = cpu.edx;
    // 0041978c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041978f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_4197a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004197a0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004197a3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004197a7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004197a8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004197a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004197aa  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004197ac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004197ad  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004197ae  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004197b0  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004197b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004197b3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004197b5  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004197b9  e8dfe50500             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 004197be  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004197c0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004197c3  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004197c5  3bc1                   +cmp eax, ecx
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
    // 004197c7  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004197cb  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004197cf  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004197d3  0f8ea6000000           -jle 0x41987f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041987f;
    }
    // 004197d9  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x004197dd:
    // 004197dd  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 004197e0  663d0d00               +cmp ax, 0xd
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
    // 004197e4  7473                   -je 0x419859
    if (cpu.flags.zf)
    {
        goto L_0x00419859;
    }
    // 004197e6  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 004197e9  0f8482000000           -je 0x419871
    if (cpu.flags.zf)
    {
        goto L_0x00419871;
    }
    // 004197ef  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004197f1  e81a47ffff             -call 0x40df10
    cpu.esp -= 4;
    sub_40df10(app, cpu);
    // 004197f6  3bc6                   +cmp eax, esi
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
    // 004197f8  7d0f                   -jge 0x419809
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00419809;
    }
    // 004197fa  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 004197fd  663d0a00               +cmp ax, 0xa
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
    // 00419801  7406                   -je 0x419809
    if (cpu.flags.zf)
    {
        goto L_0x00419809;
    }
    // 00419803  663d4000               +cmp ax, 0x40
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(64 /*0x40*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00419807  7524                   -jne 0x41982d
    if (!cpu.flags.zf)
    {
        goto L_0x0041982d;
    }
L_0x00419809:
    // 00419809  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041980d  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 00419810  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00419814  42                     -inc edx
    (cpu.edx)++;
    // 00419815  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00419817  663d0a00               +cmp ax, 0xa
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
    // 0041981b  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0041981f  7504                   -jne 0x419825
    if (!cpu.flags.zf)
    {
        goto L_0x00419825;
    }
    // 00419821  33ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00419823  eb08                   -jmp 0x41982d
    goto L_0x0041982d;
L_0x00419825:
    // 00419825  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00419827  7404                   -je 0x41982d
    if (cpu.flags.zf)
    {
        goto L_0x0041982d;
    }
    // 00419829  8bdd                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0041982b  2bf5                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0041982d:
    // 0041982d  663d0a00               +cmp ax, 0xa
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
    // 00419831  7408                   -je 0x41983b
    if (cpu.flags.zf)
    {
        goto L_0x0041983b;
    }
    // 00419833  663d2200               +cmp ax, 0x22
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
    // 00419837  7402                   -je 0x41983b
    if (cpu.flags.zf)
    {
        goto L_0x0041983b;
    }
    // 00419839  43                     -inc ebx
    (cpu.ebx)++;
    // 0041983a  4e                     -dec esi
    (cpu.esi)--;
L_0x0041983b:
    // 0041983b  663d0100               +cmp ax, 1
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0041983f  740c                   -je 0x41984d
    if (cpu.flags.zf)
    {
        goto L_0x0041984d;
    }
    // 00419841  663d0200               +cmp ax, 2
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00419845  7406                   -je 0x41984d
    if (cpu.flags.zf)
    {
        goto L_0x0041984d;
    }
    // 00419847  663dcf00               +cmp ax, 0xcf
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(207 /*0xcf*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0041984b  750c                   -jne 0x419859
    if (!cpu.flags.zf)
    {
        goto L_0x00419859;
    }
L_0x0041984d:
    // 0041984d  8d4f02                 -lea ecx, [edi + 2]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00419850  e88b46ffff             -call 0x40dee0
    cpu.esp -= 4;
    sub_40dee0(app, cpu);
    // 00419855  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00419857  03eb                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00419859:
    // 00419859  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041985d  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00419861  40                     -inc eax
    (cpu.eax)++;
    // 00419862  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00419865  3bc1                   +cmp eax, ecx
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
    // 00419867  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0041986b  0f8c6cffffff           -jl 0x4197dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004197dd;
    }
L_0x00419871:
    // 00419871  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00419875  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419876  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419877  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419878  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419879  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041987c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0041987f:
    // 0041987f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419880  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419881  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419882  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00419884  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419885  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00419888  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_419890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00419890  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00419893  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00419894  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00419895  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419896  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00419897  8b7928                 -mov edi, dword ptr [ecx + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0041989a  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0041989e  8b87cc000000           -mov eax, dword ptr [edi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */);
    // 004198a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004198a6  0f8452020000           -je 0x419afe
    if (cpu.flags.zf)
    {
        goto L_0x00419afe;
    }
    // 004198ac  e87fbe0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004198b1  d82548c84a00           -fsub dword ptr [0x4ac848]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4900936) /* 0x4ac848 */));
    // 004198b7  d915ecbf4a00           -fst dword ptr [0x4abfec]
    app->getMemory<float>(x86::reg32(4898796) /* 0x4abfec */) = float(cpu.fpu.st(0));
    // 004198bd  dc1d28754800           -fcomp qword ptr [0x487528]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748584) /* 0x487528 */)));
    cpu.fpu.pop();
    // 004198c3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004198c5  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 004198c8  0f8b30020000           -jnp 0x419afe
    if (!cpu.flags.pf)
    {
        goto L_0x00419afe;
    }
    // 004198ce  8bb7d4000000           -mov esi, dword ptr [edi + 0xd4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(212) /* 0xd4 */);
    // 004198d4  e857be0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 004198d9  d91d48c84a00           -fstp dword ptr [0x4ac848]
    app->getMemory<float>(x86::reg32(4900936) /* 0x4ac848 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004198df  d905ecbf4a00           -fld dword ptr [0x4abfec]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4898796) /* 0x4abfec */)));
    // 004198e5  dc0df8764800           -fmul qword ptr [0x4876f8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749048) /* 0x4876f8 */));
    // 004198eb  d80544c84a00           -fadd dword ptr [0x4ac844]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4900932) /* 0x4ac844 */));
    // 004198f1  8b0d68004900           -mov ecx, dword ptr [0x490068]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784232) /* 0x490068 */);
    // 004198f7  8d8684000000           -lea eax, [esi + 0x84]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004198fd  d91544c84a00           -fst dword ptr [0x4ac844]
    app->getMemory<float>(x86::reg32(4900932) /* 0x4ac844 */) = float(cpu.fpu.st(0));
    // 00419903  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 00419905  dc0d00764800           -fmul qword ptr [0x487600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748800) /* 0x487600 */));
    // 0041990b  dc05d8764800           -fadd qword ptr [0x4876d8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4749016) /* 0x4876d8 */));
    // 00419911  d91d74004900           -fstp dword ptr [0x490074]
    app->getMemory<float>(x86::reg32(4784244) /* 0x490074 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00419917  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00419919  8b156c004900           -mov edx, dword ptr [0x49006c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784236) /* 0x49006c */);
    // 0041991f  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00419922  8b0d70004900           -mov ecx, dword ptr [0x490070]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784240) /* 0x490070 */);
    // 00419928  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041992b  8b1574004900           -mov edx, dword ptr [0x490074]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784244) /* 0x490074 */);
    // 00419931  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00419935  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00419938  8b86d4000000           -mov eax, dword ptr [esi + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */);
    // 0041993e  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00419942  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00419943  8ba8d4000000           -mov ebp, dword ptr [eax + 0xd4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
    // 00419949  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0041994d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041994e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041994f  8b9dd4000000           -mov ebx, dword ptr [ebp + 0xd4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(212) /* 0xd4 */);
    // 00419955  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00419959  8d4c2430               -lea ecx, [esp + 0x30]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0041995d  e83e940000             -call 0x422da0
    cpu.esp -= 4;
    sub_422da0(app, cpu);
    // 00419962  8b87cc000000           -mov eax, dword ptr [edi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */);
    // 00419968  48                     -dec eax
    (cpu.eax)--;
    // 00419969  83f805                 +cmp eax, 5
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
    // 0041996c  0f878c010000           -ja 0x419afe
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00419afe;
    }
    // 00419972  ff2485209c4100         -jmp dword ptr [eax*4 + 0x419c20]
    cpu.ip = app->getMemory<x86::reg32>(4299808 + cpu.eax * 4); goto dynamic_jump;
  case 0x00419979:
    // 00419979  f644241002             +test byte ptr [esp + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0041997e  0f857a010000           -jne 0x419afe
    if (!cpu.flags.zf)
    {
        goto L_0x00419afe;
    }
    // 00419984  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0041998a  8d0c40                 -lea ecx, [eax + eax*2]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041998d  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00419990  8b9130d74800           -mov edx, dword ptr [ecx + 0x48d730]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773680) /* 0x48d730 */);
    // 00419996  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00419998  895664                 -mov dword ptr [esi + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 0041999b  c787c400000001000000   -mov dword ptr [edi + 0xc4], 1
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(196) /* 0xc4 */) = 1 /*0x1*/;
    // 004199a5  8b93d0000000           -mov edx, dword ptr [ebx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(208) /* 0xd0 */);
    // 004199ab  89154cc84a00           -mov dword ptr [0x4ac84c], edx
    app->getMemory<x86::reg32>(x86::reg32(4900940) /* 0x4ac84c */) = cpu.edx;
    // 004199b1  e88a020000             -call 0x419c40
    cpu.esp -= 4;
    sub_419c40(app, cpu);
    // 004199b6  a178004900             -mov eax, dword ptr [0x490078]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784248) /* 0x490078 */);
    // 004199bb  81c384000000           -add ebx, 0x84
    (cpu.ebx) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 004199c1  81c584000000           -add ebp, 0x84
    (cpu.ebp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 004199c7  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004199c9  8b0d7c004900           -mov ecx, dword ptr [0x49007c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784252) /* 0x49007c */);
    // 004199cf  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004199d2  8b1580004900           -mov edx, dword ptr [0x490080]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784256) /* 0x490080 */);
    // 004199d8  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004199db  a184004900             -mov eax, dword ptr [0x490084]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784260) /* 0x490084 */);
    // 004199e0  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004199e3  8b0d88004900           -mov ecx, dword ptr [0x490088]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784264) /* 0x490088 */);
    // 004199e9  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 004199ec  8b158c004900           -mov edx, dword ptr [0x49008c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784268) /* 0x49008c */);
    // 004199f2  895504                 -mov dword ptr [ebp + 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004199f5  a190004900             -mov eax, dword ptr [0x490090]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784272) /* 0x490090 */);
    // 004199fa  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004199fd  8b0d94004900           -mov ecx, dword ptr [0x490094]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784276) /* 0x490094 */);
    // 00419a03  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00419a06  c787cc00000002000000   -mov dword ptr [edi + 0xcc], 2
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 2 /*0x2*/;
    // 00419a10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419a11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419a12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419a13  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419a14  83c418                 +add esp, 0x18
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
    // 00419a17  e9640c0400             -jmp 0x45a680
    return sub_45a680(app, cpu);
  case 0x00419a1c:
    // 00419a1c  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00419a20  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00419a26  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00419a28  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00419a2d  750a                   -jne 0x419a39
    if (!cpu.flags.zf)
    {
        goto L_0x00419a39;
    }
    // 00419a2f  c787cc00000003000000   -mov dword ptr [edi + 0xcc], 3
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 3 /*0x3*/;
L_0x00419a39:
    // 00419a39  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00419a3d  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00419a43  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00419a45  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00419a48  7a0a                   -jp 0x419a54
    if (cpu.flags.pf)
    {
        goto L_0x00419a54;
    }
    // 00419a4a  c787cc00000004000000   -mov dword ptr [edi + 0xcc], 4
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 4 /*0x4*/;
L_0x00419a54:
    // 00419a54  f644241002             +test byte ptr [esp + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 00419a59  0f849f000000           -je 0x419afe
    if (cpu.flags.zf)
    {
        goto L_0x00419afe;
    }
    // 00419a5f  c787cc00000005000000   -mov dword ptr [edi + 0xcc], 5
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 5 /*0x5*/;
    // 00419a69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419a6a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419a6b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419a6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419a6d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00419a70  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00419a71:
    // 00419a71  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00419a77  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00419a79  8d1440                 -lea edx, [eax + eax*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00419a7c  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00419a7f  8b8230d74800           -mov eax, dword ptr [edx + 0x48d730]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4773680) /* 0x48d730 */);
    // 00419a85  894664                 -mov dword ptr [esi + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00419a88  c787c400000001000000   -mov dword ptr [edi + 0xc4], 1
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(196) /* 0xc4 */) = 1 /*0x1*/;
    // 00419a92  8b93d0000000           -mov edx, dword ptr [ebx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(208) /* 0xd0 */);
    // 00419a98  89154cc84a00           -mov dword ptr [0x4ac84c], edx
    app->getMemory<x86::reg32>(x86::reg32(4900940) /* 0x4ac84c */) = cpu.edx;
    // 00419a9e  e89d010000             -call 0x419c40
    cpu.esp -= 4;
    sub_419c40(app, cpu);
    // 00419aa3  8b0d78004900           -mov ecx, dword ptr [0x490078]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784248) /* 0x490078 */);
    // 00419aa9  81c384000000           -add ebx, 0x84
    (cpu.ebx) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 00419aaf  81c584000000           -add ebp, 0x84
    (cpu.ebp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 00419ab5  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 00419ab7  8b157c004900           -mov edx, dword ptr [0x49007c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784252) /* 0x49007c */);
    // 00419abd  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00419ac0  a180004900             -mov eax, dword ptr [0x490080]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784256) /* 0x490080 */);
    // 00419ac5  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00419ac8  8b0d84004900           -mov ecx, dword ptr [0x490084]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784260) /* 0x490084 */);
    // 00419ace  894b0c                 -mov dword ptr [ebx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00419ad1  8b1588004900           -mov edx, dword ptr [0x490088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784264) /* 0x490088 */);
    // 00419ad7  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
    // 00419ada  a18c004900             -mov eax, dword ptr [0x49008c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784268) /* 0x49008c */);
    // 00419adf  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00419ae2  8b0d90004900           -mov ecx, dword ptr [0x490090]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784272) /* 0x490090 */);
    // 00419ae8  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00419aeb  8b1594004900           -mov edx, dword ptr [0x490094]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784276) /* 0x490094 */);
    // 00419af1  89550c                 -mov dword ptr [ebp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00419af4  c787cc00000002000000   -mov dword ptr [edi + 0xcc], 2
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 2 /*0x2*/;
L_0x00419afe:
    // 00419afe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419aff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419b00  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419b01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419b02  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00419b05  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00419b06:
    // 00419b06  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00419b0c  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00419b0f  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00419b12  8b8830d74800           -mov ecx, dword ptr [eax + 0x48d730]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773680) /* 0x48d730 */);
    // 00419b18  83c120                 -add ecx, 0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00419b1b  894e64                 -mov dword ptr [esi + 0x64], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */) = cpu.ecx;
    // 00419b1e  c787c400000000000000   -mov dword ptr [edi + 0xc4], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(196) /* 0xc4 */) = 0 /*0x0*/;
    // 00419b28  8b95d0000000           -mov edx, dword ptr [ebp + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(208) /* 0xd0 */);
    // 00419b2e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00419b30  89154cc84a00           -mov dword ptr [0x4ac84c], edx
    app->getMemory<x86::reg32>(x86::reg32(4900940) /* 0x4ac84c */) = cpu.edx;
    // 00419b36  e805010000             -call 0x419c40
    cpu.esp -= 4;
    sub_419c40(app, cpu);
    // 00419b3b  8b1578004900           -mov edx, dword ptr [0x490078]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784248) /* 0x490078 */);
    // 00419b41  81c584000000           -add ebp, 0x84
    (cpu.ebp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 00419b47  81c384000000           -add ebx, 0x84
    (cpu.ebx) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 00419b4d  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
    // 00419b50  a17c004900             -mov eax, dword ptr [0x49007c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784252) /* 0x49007c */);
    // 00419b55  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00419b58  8b0d80004900           -mov ecx, dword ptr [0x490080]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784256) /* 0x490080 */);
    // 00419b5e  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00419b61  8b1584004900           -mov edx, dword ptr [0x490084]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784260) /* 0x490084 */);
    // 00419b67  89550c                 -mov dword ptr [ebp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00419b6a  a188004900             -mov eax, dword ptr [0x490088]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784264) /* 0x490088 */);
    // 00419b6f  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00419b71  8b0d8c004900           -mov ecx, dword ptr [0x49008c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784268) /* 0x49008c */);
    // 00419b77  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00419b7a  8b1590004900           -mov edx, dword ptr [0x490090]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784272) /* 0x490090 */);
    // 00419b80  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00419b83  a194004900             -mov eax, dword ptr [0x490094]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784276) /* 0x490094 */);
    // 00419b88  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00419b8b  c787cc00000002000000   -mov dword ptr [edi + 0xcc], 2
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 2 /*0x2*/;
    // 00419b95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419b96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419b97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419b98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419b99  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00419b9c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00419b9d:
    // 00419b9d  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00419ba1  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00419ba4  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00419bab  83e1ef                 -and ecx, 0xffffffef
    cpu.ecx &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
    // 00419bae  83c920                 -or ecx, 0x20
    cpu.ecx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00419bb1  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00419bb4  c787cc00000006000000   -mov dword ptr [edi + 0xcc], 6
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 6 /*0x6*/;
    // 00419bbe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419bbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419bc0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419bc1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419bc2  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00419bc5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00419bc6:
    // 00419bc6  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00419bca  d94224                 -fld dword ptr [edx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */)));
    // 00419bcd  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00419bd3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00419bd5  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00419bd8  0f8a20ffffff           -jp 0x419afe
    if (cpu.flags.pf)
    {
        goto L_0x00419afe;
    }
    // 00419bde  f644241002             +test byte ptr [esp + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 00419be3  0f8515ffffff           -jne 0x419afe
    if (!cpu.flags.zf)
    {
        goto L_0x00419afe;
    }
    // 00419be9  c787cc00000000000000   -mov dword ptr [edi + 0xcc], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(204) /* 0xcc */) = 0 /*0x0*/;
    // 00419bf3  a14cc84a00             -mov eax, dword ptr [0x4ac84c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900940) /* 0x4ac84c */);
    // 00419bf8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00419bf9  6830084900             -push 0x490830
    app->getMemory<x86::reg32>(cpu.esp-4) = 4786224 /*0x490830*/;
    cpu.esp -= 4;
    // 00419bfe  e887e40500             -call 0x47808a
    cpu.esp -= 4;
    sub_47808a(app, cpu);
    // 00419c03  8b0d4cc84a00           -mov ecx, dword ptr [0x4ac84c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900940) /* 0x4ac84c */);
    // 00419c09  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00419c0c  898fd0000000           -mov dword ptr [edi + 0xd0], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */) = cpu.ecx;
    // 00419c12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419c13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419c14  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419c15  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419c16  83c418                 +add esp, 0x18
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
    // 00419c19  e9920a0400             -jmp 0x45a6b0
    return sub_45a6b0(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_419c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419c40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419c41  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00419c43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00419c44  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00419c46  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00419c4c  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 00419c51  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00419c54  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00419c57  8b8834d74800           -mov ecx, dword ptr [eax + 0x48d734]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773684) /* 0x48d734 */);
    // 00419c5d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00419c5e  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00419c60  e83bfbffff             -call 0x4197a0
    cpu.esp -= 4;
    sub_4197a0(app, cpu);
    // 00419c65  8d0c40                 -lea ecx, [eax + eax*2]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00419c68  8d548917               -lea edx, [ecx + ecx*4 + 0x17]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(23) /* 0x17 */ + cpu.ecx * 4);
    // 00419c6c  8b8ebc000000           -mov ecx, dword ptr [esi + 0xbc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00419c72  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00419c75  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00419c78  83f801                 +cmp eax, 1
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
    // 00419c7b  899138d74800           -mov dword ptr [ecx + 0x48d738], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4773688) /* 0x48d738 */) = cpu.edx;
    // 00419c81  7c04                   -jl 0x419c87
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00419c87;
    }
    // 00419c83  83466407               -add dword ptr [esi + 0x64], 7
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */)) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x00419c87:
    // 00419c87  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419c88  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419c89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419c90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419c91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00419c92  b91d000000             -mov ecx, 0x1d
    cpu.ecx = 29 /*0x1d*/;
    // 00419c97  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00419c99  e852b5ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00419c9e  8b7828                 -mov edi, dword ptr [eax + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00419ca1  b91e000000             -mov ecx, 0x1e
    cpu.ecx = 30 /*0x1e*/;
    // 00419ca6  e845b5ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00419cab  8b8fd0000000           -mov ecx, dword ptr [edi + 0xd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(208) /* 0xd0 */);
    // 00419cb1  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00419cb4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00419cb6  7506                   -jne 0x419cbe
    if (!cpu.flags.zf)
    {
        goto L_0x00419cbe;
    }
    // 00419cb8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419cb9  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00419cbc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419cbd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00419cbe:
    // 00419cbe  8339ff                 +cmp dword ptr [ecx], -1
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
    // 00419cc1  740a                   -je 0x419ccd
    if (cpu.flags.zf)
    {
        goto L_0x00419ccd;
    }
L_0x00419cc3:
    // 00419cc3  8b54b104               -mov edx, dword ptr [ecx + esi*4 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 4);
    // 00419cc7  46                     -inc esi
    (cpu.esi)++;
    // 00419cc8  83faff                 +cmp edx, -1
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
    // 00419ccb  75f6                   -jne 0x419cc3
    if (!cpu.flags.zf)
    {
        goto L_0x00419cc3;
    }
L_0x00419ccd:
    // 00419ccd  8b80c4000000           -mov eax, dword ptr [eax + 0xc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 00419cd3  3bc6                   +cmp eax, esi
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
    // 00419cd5  7c06                   -jl 0x419cdd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00419cdd;
    }
    // 00419cd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419cd8  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00419cdb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419cdc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00419cdd:
    // 00419cdd  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 00419ce0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419ce1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419ce2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419cf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419cf0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419cf1  b91d000000             -mov ecx, 0x1d
    cpu.ecx = 29 /*0x1d*/;
    // 00419cf6  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00419cf8  e8f3b4ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00419cfd  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00419d00  8b80d0000000           -mov eax, dword ptr [eax + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */);
    // 00419d06  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00419d08  7502                   -jne 0x419d0c
    if (!cpu.flags.zf)
    {
        goto L_0x00419d0c;
    }
    // 00419d0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419d0b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00419d0c:
    // 00419d0c  8338ff                 +cmp dword ptr [eax], -1
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
    // 00419d0f  740a                   -je 0x419d1b
    if (cpu.flags.zf)
    {
        goto L_0x00419d1b;
    }
L_0x00419d11:
    // 00419d11  8b4cb004               -mov ecx, dword ptr [eax + esi*4 + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.esi * 4);
    // 00419d15  46                     -inc esi
    (cpu.esi)++;
    // 00419d16  83f9ff                 +cmp ecx, -1
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
    // 00419d19  75f6                   -jne 0x419d11
    if (!cpu.flags.zf)
    {
        goto L_0x00419d11;
    }
L_0x00419d1b:
    // 00419d1b  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00419d1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419d1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419d20  e80bba0400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00419d25  d91d98004900           -fstp dword ptr [0x490098]
    app->getMemory<float>(x86::reg32(4784280) /* 0x490098 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00419d2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419d30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00419d31  e8fab90400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00419d36  d82598004900           -fsub dword ptr [0x490098]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4784280) /* 0x490098 */));
    // 00419d3c  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 00419d42  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00419d44  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00419d47  7a15                   -jp 0x419d5e
    if (cpu.flags.pf)
    {
        goto L_0x00419d5e;
    }
    // 00419d49  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00419d4b  c744240000000000       -mov dword ptr [esp], 0
    app->getMemory<x86::reg32>(cpu.esp) = 0 /*0x0*/;
    // 00419d53  e8c8ffffff             -call 0x419d20
    cpu.esp -= 4;
    sub_419d20(app, cpu);
    // 00419d58  d9442400               -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00419d5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419d5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00419d5e:
    // 00419d5e  d815e4754800           -fcom dword ptr [0x4875e4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748772) /* 0x4875e4 */)));
    // 00419d64  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00419d66  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00419d6b  7508                   -jne 0x419d75
    if (!cpu.flags.zf)
    {
        goto L_0x00419d75;
    }
    // 00419d6d  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00419d6f  d905e4754800           -fld dword ptr [0x4875e4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748772) /* 0x4875e4 */)));
L_0x00419d75:
    // 00419d75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419d76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00419d80  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00419d82  7c0d                   -jl 0x419d91
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00419d91;
    }
    // 00419d84  83f919                 +cmp ecx, 0x19
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00419d87  7d08                   -jge 0x419d91
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00419d91;
    }
    // 00419d89  8b048da0004900         -mov eax, dword ptr [ecx*4 + 0x4900a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4784288) /* 0x4900a0 */ + cpu.ecx * 4);
    // 00419d90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00419d91:
    // 00419d91  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00419d94  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_419da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00419da0  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00419da3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00419da4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00419da5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00419da6  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00419da8  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00419daa  8b7728                 -mov esi, dword ptr [edi + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00419dad  39aecc000000           +cmp dword ptr [esi + 0xcc], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00419db3  0f845f020000           -je 0x41a018
    if (cpu.flags.zf)
    {
        goto L_0x0041a018;
    }
    // 00419db9  d986c8000000           -fld dword ptr [esi + 0xc8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */)));
    // 00419dbf  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 00419dc1  8b0d04014900           -mov ecx, dword ptr [0x490104]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784388) /* 0x490104 */);
    // 00419dc7  8d8684000000           -lea eax, [esi + 0x84]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00419dcd  dc0d00764800           -fmul qword ptr [0x487600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748800) /* 0x487600 */));
    // 00419dd3  dc05d8764800           -fadd qword ptr [0x4876d8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4749016) /* 0x4876d8 */));
    // 00419dd9  d91d08014900           -fstp dword ptr [0x490108]
    app->getMemory<float>(x86::reg32(4784392) /* 0x490108 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00419ddf  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00419de1  8b1508014900           -mov edx, dword ptr [0x490108]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784392) /* 0x490108 */);
    // 00419de7  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00419dea  8b0d0c014900           -mov ecx, dword ptr [0x49010c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4784396) /* 0x49010c */);
    // 00419df0  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00419df3  8b1510014900           -mov edx, dword ptr [0x490110]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4784400) /* 0x490110 */);
    // 00419df9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00419dfc  e82fb90400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00419e01  d8256cc84a00           -fsub dword ptr [0x4ac86c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4900972) /* 0x4ac86c */));
    // 00419e07  d91538c44a00           -fst dword ptr [0x4ac438]
    app->getMemory<float>(x86::reg32(4899896) /* 0x4ac438 */) = float(cpu.fpu.st(0));
    // 00419e0d  dc1d00774800           -fcomp qword ptr [0x487700]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4749056) /* 0x487700 */)));
    cpu.fpu.pop();
    // 00419e13  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00419e15  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00419e1a  7523                   -jne 0x419e3f
    if (!cpu.flags.zf)
    {
        goto L_0x00419e3f;
    }
    // 00419e1c  d90538c44a00           -fld dword ptr [0x4ac438]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4899896) /* 0x4ac438 */)));
    // 00419e22  dc0da8744800           -fmul qword ptr [0x4874a8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748456) /* 0x4874a8 */));
    // 00419e28  d886c8000000           -fadd dword ptr [esi + 0xc8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */));
    // 00419e2e  d99ec8000000           -fstp dword ptr [esi + 0xc8]
    app->getMemory<float>(cpu.esi + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00419e34  e8f7b80400             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00419e39  d91d6cc84a00           -fstp dword ptr [0x4ac86c]
    app->getMemory<float>(x86::reg32(4900972) /* 0x4ac86c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00419e3f:
    // 00419e3f  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00419e43  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00419e47  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00419e48  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00419e4c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00419e4d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00419e4e  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00419e52  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00419e56  e8458f0000             -call 0x422da0
    cpu.esp -= 4;
    sub_422da0(app, cpu);
    // 00419e5b  8b86cc000000           -mov eax, dword ptr [esi + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */);
    // 00419e61  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 00419e66  48                     -dec eax
    (cpu.eax)--;
    // 00419e67  3bc1                   +cmp eax, ecx
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
    // 00419e69  0f87a9010000           -ja 0x41a018
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041a018;
    }
    // 00419e6f  ff248520a04100         -jmp dword ptr [eax*4 + 0x41a020]
    cpu.ip = app->getMemory<x86::reg32>(4300832 + cpu.eax * 4); goto dynamic_jump;
  case 0x00419e76:
    // 00419e76  f644241002             +test byte ptr [esp + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 00419e7b  0f8597010000           -jne 0x41a018
    if (!cpu.flags.zf)
    {
        goto L_0x0041a018;
    }
    // 00419e81  e8ba010000             -call 0x41a040
    cpu.esp -= 4;
    sub_41a040(app, cpu);
    // 00419e86  e865feffff             -call 0x419cf0
    cpu.esp -= 4;
    sub_419cf0(app, cpu);
    // 00419e8b  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00419e8d  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00419e8f  a368c74a00             -mov dword ptr [0x4ac768], eax
    app->getMemory<x86::reg32>(x86::reg32(4900712) /* 0x4ac768 */) = cpu.eax;
    // 00419e94  e827030000             -call 0x41a1c0
    cpu.esp -= 4;
    sub_41a1c0(app, cpu);
    // 00419e99  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 00419e9c  c747200000803f         -mov dword ptr [edi + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 00419ea3  24df                   -and al, 0xdf
    cpu.al &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 00419ea5  0c10                   -or al, 0x10
    cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00419ea7  89471c                 -mov dword ptr [edi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00419eaa  8b0d2cec4800           -mov ecx, dword ptr [0x48ec2c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4779052) /* 0x48ec2c */);
    // 00419eb0  894e60                 -mov dword ptr [esi + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 00419eb3  89aec4000000           -mov dword ptr [esi + 0xc4], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */) = cpu.ebp;
    // 00419eb9  c786cc00000002000000   -mov dword ptr [esi + 0xcc], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 2 /*0x2*/;
    // 00419ec3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419ec4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419ec5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419ec6  83c414                 +add esp, 0x14
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
    // 00419ec9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00419eca:
    // 00419eca  8b1568c74a00           -mov edx, dword ptr [0x4ac768]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900712) /* 0x4ac768 */);
    // 00419ed0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00419ed2  e8f9010000             -call 0x41a0d0
    cpu.esp -= 4;
    sub_41a0d0(app, cpu);
    // 00419ed7  d81d94744800           +fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 00419edd  e9f1000000             -jmp 0x419fd3
    goto L_0x00419fd3;
  case 0x00419ee2:
    // 00419ee2  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00419ee6  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00419eec  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00419eee  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 00419ef3  750a                   -jne 0x419eff
    if (!cpu.flags.zf)
    {
        goto L_0x00419eff;
    }
    // 00419ef5  c786cc00000004000000   -mov dword ptr [esi + 0xcc], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 4 /*0x4*/;
L_0x00419eff:
    // 00419eff  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00419f03  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00419f09  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00419f0b  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00419f0e  7a0a                   -jp 0x419f1a
    if (cpu.flags.pf)
    {
        goto L_0x00419f1a;
    }
    // 00419f10  c786cc00000005000000   -mov dword ptr [esi + 0xcc], 5
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 5 /*0x5*/;
L_0x00419f1a:
    // 00419f1a  f644241002             +test byte ptr [esp + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 00419f1f  0f84f3000000           -je 0x41a018
    if (cpu.flags.zf)
    {
        goto L_0x0041a018;
    }
    // 00419f25  c786cc00000006000000   -mov dword ptr [esi + 0xcc], 6
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 6 /*0x6*/;
    // 00419f2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419f30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419f31  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419f32  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00419f35  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00419f36:
    // 00419f36  898ecc000000           -mov dword ptr [esi + 0xcc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.ecx;
    // 00419f3c  8b1568c74a00           -mov edx, dword ptr [0x4ac768]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900712) /* 0x4ac768 */);
    // 00419f42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00419f43  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00419f45  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00419f47  e814010000             -call 0x41a060
    cpu.esp -= 4;
    sub_41a060(app, cpu);
    // 00419f4c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419f4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419f4e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419f4f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00419f52  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00419f53:
    // 00419f53  898ecc000000           -mov dword ptr [esi + 0xcc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.ecx;
    // 00419f59  a168c74a00             -mov eax, dword ptr [0x4ac768]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900712) /* 0x4ac768 */);
    // 00419f5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00419f5f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00419f64  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00419f66  e8f5000000             -call 0x41a060
    cpu.esp -= 4;
    sub_41a060(app, cpu);
    // 00419f6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419f6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419f6d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419f6e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00419f71  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00419f72:
    // 00419f72  8b4f1c                 -mov ecx, dword ptr [edi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 00419f75  896f20                 -mov dword ptr [edi + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00419f78  83e1ef                 -and ecx, 0xffffffef
    cpu.ecx &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
    // 00419f7b  83c920                 -or ecx, 0x20
    cpu.ecx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00419f7e  894f1c                 -mov dword ptr [edi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00419f81  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00419f86  e865b2ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00419f8b  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00419f8e  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00419f91  83ca20                 -or edx, 0x20
    cpu.edx |= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00419f94  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00419f99  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00419f9b  e850b2ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00419fa0  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00419fa3  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00419fa6  83e1ef                 -and ecx, 0xffffffef
    cpu.ecx &= x86::reg32(x86::sreg32(4294967279 /*0xffffffef*/));
    // 00419fa9  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00419fab  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00419fb0  e83bb2ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 00419fb5  896820                 -mov dword ptr [eax + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00419fb8  c786cc00000008000000   -mov dword ptr [esi + 0xcc], 8
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 8 /*0x8*/;
    // 00419fc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419fc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419fc4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419fc5  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00419fc8  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00419fc9:
    // 00419fc9  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00419fcd  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
L_0x00419fd3:
    // 00419fd3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00419fd5  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00419fd8  7a3e                   -jp 0x41a018
    if (cpu.flags.pf)
    {
        goto L_0x0041a018;
    }
    // 00419fda  c786cc00000003000000   -mov dword ptr [esi + 0xcc], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = 3 /*0x3*/;
    // 00419fe4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419fe5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419fe6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00419fe7  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00419fea  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00419feb:
    // 00419feb  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00419fef  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 00419ff5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00419ff7  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 00419ffa  7a1c                   -jp 0x41a018
    if (cpu.flags.pf)
    {
        goto L_0x0041a018;
    }
    // 00419ffc  396c2410               +cmp dword ptr [esp + 0x10], ebp
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041a000  7516                   -jne 0x41a018
    if (!cpu.flags.zf)
    {
        goto L_0x0041a018;
    }
    // 0041a002  d94724                 -fld dword ptr [edi + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(36) /* 0x24 */)));
    // 0041a005  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0041a00b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041a00d  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0041a010  7a06                   -jp 0x41a018
    if (cpu.flags.pf)
    {
        goto L_0x0041a018;
    }
    // 0041a012  89aecc000000           -mov dword ptr [esi + 0xcc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(204) /* 0xcc */) = cpu.ebp;
L_0x0041a018:
    // 0041a018  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a019  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a01a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a01b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041a01e  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_41a040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a040  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 0041a045  e8a6b1ffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041a04a  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0041a04d  c740200000803f         -mov dword ptr [eax + 0x20], 0x3f800000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 1065353216 /*0x3f800000*/;
    // 0041a054  83e1df                 -and ecx, 0xffffffdf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 0041a057  83c910                 -or ecx, 0x10
    cpu.ecx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041a05a  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0041a05d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41a060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a060  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041a064  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041a065  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041a067  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041a068  745f                   -je 0x41a0c9
    if (cpu.flags.zf)
    {
        goto L_0x0041a0c9;
    }
    // 0041a06a  8b352cec4800           -mov esi, dword ptr [0x48ec2c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4779052) /* 0x48ec2c */);
    // 0041a070  8d3c40                 -lea edi, [eax + eax*2]
    cpu.edi = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041a073  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 0041a076  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041a078  8bbffceb4800           -mov edi, dword ptr [edi + 0x48ebfc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4779004) /* 0x48ebfc */);
    // 0041a07e  8b5160                 -mov edx, dword ptr [ecx + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */);
    // 0041a081  750f                   -jne 0x41a092
    if (!cpu.flags.zf)
    {
        goto L_0x0041a092;
    }
    // 0041a083  83c2a0                 +add edx, -0x60
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-96 /*-0x60*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041a086  895160                 -mov dword ptr [ecx + 0x60], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 0041a089  8b91c4000000           -mov edx, dword ptr [ecx + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 0041a08f  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041a090  eb0d                   -jmp 0x41a09f
    goto L_0x0041a09f;
L_0x0041a092:
    // 0041a092  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0041a095  895160                 -mov dword ptr [ecx + 0x60], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 0041a098  8b91c4000000           -mov edx, dword ptr [ecx + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 0041a09e  42                     -inc edx
    (cpu.edx)++;
L_0x0041a09f:
    // 0041a09f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041a0a1  8991c4000000           -mov dword ptr [ecx + 0xc4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */) = cpu.edx;
    // 0041a0a7  7d12                   -jge 0x41a0bb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041a0bb;
    }
    // 0041a0a9  897160                 -mov dword ptr [ecx + 0x60], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */) = cpu.esi;
    // 0041a0ac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a0ad  c781c400000000000000   -mov dword ptr [ecx + 0xc4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */) = 0 /*0x0*/;
    // 0041a0b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a0b8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0041a0bb:
    // 0041a0bb  3bd0                   +cmp edx, eax
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
    // 0041a0bd  7c0a                   -jl 0x41a0c9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041a0c9;
    }
    // 0041a0bf  48                     -dec eax
    (cpu.eax)--;
    // 0041a0c0  897960                 -mov dword ptr [ecx + 0x60], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */) = cpu.edi;
    // 0041a0c3  8981c4000000           -mov dword ptr [ecx + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */) = cpu.eax;
L_0x0041a0c9:
    // 0041a0c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a0ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a0cb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_41a0d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a0d0  a150c84a00             -mov eax, dword ptr [0x4ac850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900944) /* 0x4ac850 */);
    // 0041a0d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041a0d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041a0d7  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041a0d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041a0db  be0000803f             -mov esi, 0x3f800000
    cpu.esi = 1065353216 /*0x3f800000*/;
    // 0041a0e0  752d                   -jne 0x41a10f
    if (!cpu.flags.zf)
    {
        goto L_0x0041a10f;
    }
    // 0041a0e2  b86cc84a00             -mov eax, 0x4ac86c
    cpu.eax = 4900972 /*0x4ac86c*/;
L_0x0041a0e7:
    // 0041a0e7  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041a0ea  3d50c84a00             +cmp eax, 0x4ac850
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4900944 /*0x4ac850*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041a0ef  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0041a0f1  89b18c000000           -mov dword ptr [ecx + 0x8c], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */) = cpu.esi;
    // 0041a0f7  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041a0f9  89b288000000           -mov dword ptr [edx + 0x88], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */) = cpu.esi;
    // 0041a0ff  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0041a101  89b284000000           -mov dword ptr [edx + 0x84], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */) = cpu.esi;
    // 0041a107  8b89d4000000           -mov ecx, dword ptr [ecx + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0041a10d  7fd8                   -jg 0x41a0e7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0041a0e7;
    }
L_0x0041a10f:
    // 0041a10f  e81cfcffff             -call 0x419d30
    cpu.esp -= 4;
    sub_419d30(app, cpu);
    // 0041a114  d80d04754800           -fmul dword ptr [0x487504]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748548) /* 0x487504 */));
    // 0041a11a  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041a11c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041a11e  7e46                   -jle 0x41a166
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041a166;
    }
    // 0041a120  d90558744800           -fld dword ptr [0x487458]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748376) /* 0x487458 */)));
    // 0041a126  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
L_0x0041a128:
    // 0041a128  8b048d50c84a00         -mov eax, dword ptr [ecx*4 + 0x4ac850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900944) /* 0x4ac850 */ + cpu.ecx * 4);
    // 0041a12f  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0041a131  d88090000000           -fadd dword ptr [eax + 0x90]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(144) /* 0x90 */));
    // 0041a137  d99890000000           -fstp dword ptr [eax + 0x90]
    app->getMemory<float>(cpu.eax + x86::reg32(144) /* 0x90 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041a13d  8b148d50c84a00         -mov edx, dword ptr [ecx*4 + 0x4ac850]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900944) /* 0x4ac850 */ + cpu.ecx * 4);
    // 0041a144  d98290000000           -fld dword ptr [edx + 0x90]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(144) /* 0x90 */)));
    // 0041a14a  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 0041a150  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041a152  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 0041a157  7506                   -jne 0x41a15f
    if (!cpu.flags.zf)
    {
        goto L_0x0041a15f;
    }
    // 0041a159  89b290000000           -mov dword ptr [edx + 0x90], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(144) /* 0x90 */) = cpu.esi;
L_0x0041a15f:
    // 0041a15f  41                     -inc ecx
    (cpu.ecx)++;
    // 0041a160  3bcf                   +cmp ecx, edi
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
    // 0041a162  7cc4                   -jl 0x41a128
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041a128;
    }
    // 0041a164  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0041a166:
    // 0041a166  d80d58744800           -fmul dword ptr [0x487458]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748376) /* 0x487458 */));
    // 0041a16c  a168c84a00             -mov eax, dword ptr [0x4ac868]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900968) /* 0x4ac868 */);
    // 0041a171  d88090000000           -fadd dword ptr [eax + 0x90]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(144) /* 0x90 */));
    // 0041a177  d99890000000           -fstp dword ptr [eax + 0x90]
    app->getMemory<float>(cpu.eax + x86::reg32(144) /* 0x90 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041a17d  8b0d68c84a00           -mov ecx, dword ptr [0x4ac868]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900968) /* 0x4ac868 */);
    // 0041a183  d98190000000           -fld dword ptr [ecx + 0x90]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(144) /* 0x90 */)));
    // 0041a189  d81d94744800           -fcomp dword ptr [0x487494]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)));
    cpu.fpu.pop();
    // 0041a18f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0041a191  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 0041a196  7514                   -jne 0x41a1ac
    if (!cpu.flags.zf)
    {
        goto L_0x0041a1ac;
    }
    // 0041a198  89b190000000           -mov dword ptr [ecx + 0x90], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.esi;
    // 0041a19e  a150c84a00             -mov eax, dword ptr [0x4ac850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4900944) /* 0x4ac850 */);
    // 0041a1a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a1a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a1a5  d98090000000           -fld dword ptr [eax + 0x90]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(144) /* 0x90 */)));
    // 0041a1ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041a1ac:
    // 0041a1ac  8b0d50c84a00           -mov ecx, dword ptr [0x4ac850]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4900944) /* 0x4ac850 */);
    // 0041a1b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a1b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a1b4  d98190000000           -fld dword ptr [ecx + 0x90]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(144) /* 0x90 */)));
    // 0041a1ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_41a1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041a1c0  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041a1c3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041a1c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041a1c5  8d0452                 -lea eax, [edx + edx*2]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 2);
    // 0041a1c8  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0041a1ca  8b1588c74a00           -mov edx, dword ptr [0x4ac788]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4900744) /* 0x4ac788 */);
    // 0041a1d0  b960020000             -mov ecx, 0x260
    cpu.ecx = 608 /*0x260*/;
    // 0041a1d5  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041a1d8  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0041a1da  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041a1de  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 0041a1e2  d88a0c180000           -fmul dword ptr [edx + 0x180c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(6156) /* 0x180c */));
    // 0041a1e8  e8a3cb0500             -call 0x476d90
    cpu.esp -= 4;
    sub_476d90(app, cpu);
    // 0041a1ed  b91d000000             -mov ecx, 0x1d
    cpu.ecx = 29 /*0x1d*/;
    // 0041a1f2  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041a1f5  e8f6afffff             -call 0x4151f0
    cpu.esp -= 4;
    sub_4151f0(app, cpu);
    // 0041a1fa  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0041a1fd  8b98d0000000           -mov ebx, dword ptr [eax + 0xd0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */);
    // 0041a203  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0041a205  0f84dd000000           -je 0x41a2e8
    if (cpu.flags.zf)
    {
        goto L_0x0041a2e8;
    }
    // 0041a20b  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0041a20d  e8de000000             -call 0x41a2f0
    cpu.esp -= 4;
    sub_41a2f0(app, cpu);
    // 0041a212  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0041a215  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0041a219  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 0041a21e  8b89d4000000           -mov ecx, dword ptr [ecx + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
L_0x0041a224:
    // 0041a224  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0041a226  8b89d4000000           -mov ecx, dword ptr [ecx + 0xd4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0041a22c  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041a22f  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041a230  75f2                   -jne 0x41a224
    if (!cpu.flags.zf)
    {
        goto L_0x0041a224;
    }
    // 0041a232  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041a234  0f8eae000000           -jle 0x41a2e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041a2e8;
    }
    // 0041a23a  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041a23e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041a23f  2bcb                   +sub ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041a241  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041a242  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0041a246  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0041a248  eb04                   -jmp 0x41a24e
    goto L_0x0041a24e;
L_0x0041a24a:
    // 0041a24a  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0041a24e:
    // 0041a24e  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0041a250  8b3c19                 -mov edi, dword ptr [ecx + ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + cpu.ebx * 1);
    // 0041a253  b958084900             -mov ecx, 0x490858
    cpu.ecx = 4786264 /*0x490858*/;
    // 0041a258  8b3495a0004900         -mov esi, dword ptr [edx*4 + 0x4900a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4784288) /* 0x4900a0 */ + cpu.edx * 4);
    // 0041a25f  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041a261  83fe10                 +cmp esi, 0x10
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041a264  7c05                   -jl 0x41a26b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041a26b;
    }
    // 0041a266  b948084900             -mov ecx, 0x490848
    cpu.ecx = 4786248 /*0x490848*/;
L_0x0041a26b:
    // 0041a26b  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0041a271  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0041a273  8b87bc000000           -mov eax, dword ptr [edi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(188) /* 0xbc */);
    // 0041a279  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0041a27c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0041a27f  8b8854d74800           -mov ecx, dword ptr [eax + 0x48d754]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773716) /* 0x48d754 */);
    // 0041a285  8b9050d74800           -mov edx, dword ptr [eax + 0x48d750]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4773712) /* 0x48d750 */);
    // 0041a28b  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041a28d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041a28e  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0041a291  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0041a294  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041a295  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0041a299  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041a29e  db442420               -fild dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 0041a2a2  680000803e             -push 0x3e800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0041a2a7  83e603                 -and esi, 3
    cpu.esi &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0041a2aa  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0041a2ad  8974242c               -mov dword ptr [esp + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.esi;
    // 0041a2b1  d80d4c764800           -fmul dword ptr [0x48764c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748876) /* 0x48764c */));
    // 0041a2b7  8d4f04                 -lea ecx, [edi + 4]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0041a2ba  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041a2c0  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041a2c4  db44242c               -fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0041a2c8  d80d4c764800           -fmul dword ptr [0x48764c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748876) /* 0x48764c */));
    // 0041a2ce  d80d10764800           -fmul dword ptr [0x487610]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748816) /* 0x487610 */));
    // 0041a2d4  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0041a2d7  e834d5ffff             -call 0x417810
    cpu.esp -= 4;
    sub_417810(app, cpu);
    // 0041a2dc  83c304                 +add ebx, 4
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
    // 0041a2df  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041a2e0  0f8564ffffff           -jne 0x41a24a
    if (!cpu.flags.zf)
    {
        goto L_0x0041a24a;
    }
    // 0041a2e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a2e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041a2e8:
    // 0041a2e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a2e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041a2ea  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0041a2ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
