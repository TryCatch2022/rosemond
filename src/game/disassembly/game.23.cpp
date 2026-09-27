#include "game.h"
namespace game
{

/* align: skip  */
void Application::sub_4842bd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004842bd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004842be  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004842c0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004842c3  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004842c6  8365fc00               +and dword ptr [ebp - 4], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 004842ca  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004842cb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004842cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004842cd  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004842ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004842cf  7467                   -je 0x484338
    if (cpu.flags.zf)
    {
        goto L_0x00484338;
    }
    // 004842d1  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004842d2  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004842d3  7446                   -je 0x48431b
    if (cpu.flags.zf)
    {
        goto L_0x0048431b;
    }
    // 004842d5  83e804                 +sub eax, 4
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
    // 004842d8  7441                   -je 0x48431b
    if (cpu.flags.zf)
    {
        goto L_0x0048431b;
    }
    // 004842da  83e803                 +sub eax, 3
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
    // 004842dd  743c                   -je 0x48431b
    if (cpu.flags.zf)
    {
        goto L_0x0048431b;
    }
    // 004842df  83e804                 +sub eax, 4
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
    // 004842e2  742a                   -je 0x48430e
    if (cpu.flags.zf)
    {
        goto L_0x0048430e;
    }
    // 004842e4  83e806                 +sub eax, 6
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
    // 004842e7  7418                   -je 0x484301
    if (cpu.flags.zf)
    {
        goto L_0x00484301;
    }
    // 004842e9  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004842ea  7408                   -je 0x4842f4
    if (cpu.flags.zf)
    {
        goto L_0x004842f4;
    }
    // 004842ec  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004842ef  e946010000             -jmp 0x48443a
    goto L_0x0048443a;
L_0x004842f4:
    // 004842f4  8b1d38ee5100           -mov ebx, dword ptr [0x51ee38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5369400) /* 0x51ee38 */);
    // 004842fa  bf38ee5100             -mov edi, 0x51ee38
    cpu.edi = 5369400 /*0x51ee38*/;
    // 004842ff  eb42                   -jmp 0x484343
    goto L_0x00484343;
L_0x00484301:
    // 00484301  8b1d34ee5100           -mov ebx, dword ptr [0x51ee34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5369396) /* 0x51ee34 */);
    // 00484307  bf34ee5100             -mov edi, 0x51ee34
    cpu.edi = 5369396 /*0x51ee34*/;
    // 0048430c  eb35                   -jmp 0x484343
    goto L_0x00484343;
L_0x0048430e:
    // 0048430e  8b1d3cee5100           -mov ebx, dword ptr [0x51ee3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5369404) /* 0x51ee3c */);
    // 00484314  bf3cee5100             -mov edi, 0x51ee3c
    cpu.edi = 5369404 /*0x51ee3c*/;
    // 00484319  eb28                   -jmp 0x484343
    goto L_0x00484343;
L_0x0048431b:
    // 0048431b  e84771ffff             -call 0x47b467
    cpu.esp -= 4;
    sub_47b467(app, cpu);
    // 00484320  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484322  ff7650                 -push dword ptr [esi + 0x50]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    // 00484325  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00484328  e812010000             -call 0x48443f
    cpu.esp -= 4;
    sub_48443f(app, cpu);
    // 0048432d  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048432f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484330  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00484333  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484334  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 00484336  eb1d                   -jmp 0x484355
    goto L_0x00484355;
L_0x00484338:
    // 00484338  8b1d30ee5100           -mov ebx, dword ptr [0x51ee30]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5369392) /* 0x51ee30 */);
    // 0048433e  bf30ee5100             -mov edi, 0x51ee30
    cpu.edi = 5369392 /*0x51ee30*/;
L_0x00484343:
    // 00484343  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484345  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0048434c  e87887ffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00484351  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00484354  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484355:
    // 00484355  83fb01                 +cmp ebx, 1
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
    // 00484358  7516                   -jne 0x484370
    if (!cpu.flags.zf)
    {
        goto L_0x00484370;
    }
    // 0048435a  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 0048435e  0f84d4000000           -je 0x484438
    if (cpu.flags.zf)
    {
        goto L_0x00484438;
    }
    // 00484364  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484365  e8c087ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0048436a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048436b  e9c8000000             -jmp 0x484438
    goto L_0x00484438;
L_0x00484370:
    // 00484370  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484372  3bd9                   +cmp ebx, ecx
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
    // 00484374  7514                   -jne 0x48438a
    if (!cpu.flags.zf)
    {
        goto L_0x0048438a;
    }
    // 00484376  394dfc                 +cmp dword ptr [ebp - 4], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484379  7408                   -je 0x484383
    if (cpu.flags.zf)
    {
        goto L_0x00484383;
    }
    // 0048437b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048437d  e8a887ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00484382  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484383:
    // 00484383  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00484385  e8e642ffff             -call 0x478670
    cpu.esp -= 4;
    __exit(app, cpu);
L_0x0048438a:
    // 0048438a  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048438d  83f808                 +cmp eax, 8
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
    // 00484390  740a                   -je 0x48439c
    if (cpu.flags.zf)
    {
        goto L_0x0048439c;
    }
    // 00484392  83f80b                 +cmp eax, 0xb
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
    // 00484395  7405                   -je 0x48439c
    if (cpu.flags.zf)
    {
        goto L_0x0048439c;
    }
    // 00484397  83f804                 +cmp eax, 4
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
    // 0048439a  751b                   -jne 0x4843b7
    if (!cpu.flags.zf)
    {
        goto L_0x004843b7;
    }
L_0x0048439c:
    // 0048439c  8b5654                 -mov edx, dword ptr [esi + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 0048439f  83f808                 +cmp eax, 8
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
    // 004843a2  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004843a5  894e54                 -mov dword ptr [esi + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = cpu.ecx;
    // 004843a8  7549                   -jne 0x4843f3
    if (!cpu.flags.zf)
    {
        goto L_0x004843f3;
    }
    // 004843aa  8b5658                 -mov edx, dword ptr [esi + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004843ad  c746588c000000         -mov dword ptr [esi + 0x58], 0x8c
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = 140 /*0x8c*/;
    // 004843b4  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
L_0x004843b7:
    // 004843b7  83f808                 +cmp eax, 8
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
    // 004843ba  7537                   -jne 0x4843f3
    if (!cpu.flags.zf)
    {
        goto L_0x004843f3;
    }
    // 004843bc  8b0d20684a00           -mov ecx, dword ptr [0x4a6820]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4876320) /* 0x4a6820 */);
    // 004843c2  a124684a00             -mov eax, dword ptr [0x4a6824]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4876324) /* 0x4a6824 */);
    // 004843c7  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004843c9  3bc8                   +cmp ecx, eax
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
    // 004843cb  7d28                   -jge 0x4843f5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004843f5;
    }
    // 004843cd  8d0449                 -lea eax, [ecx + ecx*2]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 004843d0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
L_0x004843d3:
    // 004843d3  8b5650                 -mov edx, dword ptr [esi + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 004843d6  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004843d9  836402fc00             -and dword ptr [edx + eax - 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004843de  8b1520684a00           -mov edx, dword ptr [0x4a6820]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4876320) /* 0x4a6820 */);
    // 004843e4  8b3d24684a00           -mov edi, dword ptr [0x4a6824]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4876324) /* 0x4a6824 */);
    // 004843ea  41                     -inc ecx
    (cpu.ecx)++;
    // 004843eb  03fa                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004843ed  3bcf                   +cmp ecx, edi
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
    // 004843ef  7ce2                   -jl 0x4843d3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004843d3;
    }
    // 004843f1  eb02                   -jmp 0x4843f5
    goto L_0x004843f5;
L_0x004843f3:
    // 004843f3  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
L_0x004843f5:
    // 004843f5  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 004843f9  7408                   -je 0x484403
    if (cpu.flags.zf)
    {
        goto L_0x00484403;
    }
    // 004843fb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004843fd  e82887ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00484402  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484403:
    // 00484403  837d0808               +cmp dword ptr [ebp + 8], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484407  750b                   -jne 0x484414
    if (!cpu.flags.zf)
    {
        goto L_0x00484414;
    }
    // 00484409  ff7658                 -push dword ptr [esi + 0x58]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    // 0048440c  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0048440e  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484410  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484411  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484412  eb12                   -jmp 0x484426
    goto L_0x00484426;
L_0x00484414:
    // 00484414  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00484417  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484419  837d080b               +cmp dword ptr [ebp + 8], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048441d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048441e  7406                   -je 0x484426
    if (cpu.flags.zf)
    {
        goto L_0x00484426;
    }
    // 00484420  837d0804               +cmp dword ptr [ebp + 8], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484424  7512                   -jne 0x484438
    if (!cpu.flags.zf)
    {
        goto L_0x00484438;
    }
L_0x00484426:
    // 00484426  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00484429  837d0808               +cmp dword ptr [ebp + 8], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048442d  894654                 -mov dword ptr [esi + 0x54], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 00484430  7506                   -jne 0x484438
    if (!cpu.flags.zf)
    {
        goto L_0x00484438;
    }
    // 00484432  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00484435  894658                 -mov dword ptr [esi + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = cpu.eax;
L_0x00484438:
    // 00484438  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048443a:
    // 0048443a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048443b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048443c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048443d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048443e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48443f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048443f  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00484443  8b0d2c684a00           -mov ecx, dword ptr [0x4a682c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4876332) /* 0x4a682c */);
    // 00484449  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048444a  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048444e  397204                 +cmp dword ptr [edx + 4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484451  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484452  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484454  7412                   -je 0x484468
    if (cpu.flags.zf)
    {
        goto L_0x00484468;
    }
    // 00484456  8d3c49                 -lea edi, [ecx + ecx*2]
    cpu.edi = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00484459  8d3cba                 -lea edi, [edx + edi*4]
    cpu.edi = x86::reg32(cpu.edx + cpu.edi * 4);
L_0x0048445c:
    // 0048445c  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048445f  3bc7                   +cmp eax, edi
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
    // 00484461  7305                   -jae 0x484468
    if (!cpu.flags.cf)
    {
        goto L_0x00484468;
    }
    // 00484463  397004                 +cmp dword ptr [eax + 4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484466  75f4                   -jne 0x48445c
    if (!cpu.flags.zf)
    {
        goto L_0x0048445c;
    }
L_0x00484468:
    // 00484468  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0048446b  8d0c8a                 -lea ecx, [edx + ecx*4]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ecx * 4);
    // 0048446e  3bc1                   +cmp eax, ecx
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
    // 00484470  7305                   -jae 0x484477
    if (!cpu.flags.cf)
    {
        goto L_0x00484477;
    }
    // 00484472  397004                 +cmp dword ptr [eax + 4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484475  7402                   -je 0x484479
    if (cpu.flags.zf)
    {
        goto L_0x00484479;
    }
L_0x00484477:
    // 00484477  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00484479:
    // 00484479  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048447a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048447b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48447c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048447c  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00484480  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484481  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00484485  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484487  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 0048448a  3bca                   +cmp ecx, edx
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
    // 0048448c  7204                   -jb 0x484492
    if (cpu.flags.cf)
    {
        goto L_0x00484492;
    }
    // 0048448e  3bce                   +cmp ecx, esi
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
    // 00484490  7303                   -jae 0x484495
    if (!cpu.flags.cf)
    {
        goto L_0x00484495;
    }
L_0x00484492:
    // 00484492  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484494  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484495:
    // 00484495  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00484499  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048449a  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048449c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::___add_12(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048449d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048449e  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004844a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004844a3  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004844a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004844a8  ff37                   -push dword ptr [edi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi);
    cpu.esp -= 4;
    // 004844aa  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 004844ac  e8cbffffff             -call 0x48447c
    cpu.esp -= 4;
    sub_48447c(app, cpu);
    // 004844b1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004844b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004844b6  7417                   -je 0x4844cf
    if (cpu.flags.zf)
    {
        goto L_0x004844cf;
    }
    // 004844b8  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004844bb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004844bc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004844be  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 004844c0  e8b7ffffff             -call 0x48447c
    cpu.esp -= 4;
    sub_48447c(app, cpu);
    // 004844c5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004844c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004844ca  7403                   -je 0x4844cf
    if (cpu.flags.zf)
    {
        goto L_0x004844cf;
    }
    // 004844cc  ff4608                 -inc dword ptr [esi + 8]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */))++;
L_0x004844cf:
    // 004844cf  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004844d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004844d3  ff7704                 -push dword ptr [edi + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004844d6  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 004844d8  e89fffffff             -call 0x48447c
    cpu.esp -= 4;
    sub_48447c(app, cpu);
    // 004844dd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004844e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004844e2  7403                   -je 0x4844e7
    if (cpu.flags.zf)
    {
        goto L_0x004844e7;
    }
    // 004844e4  ff4608                 -inc dword ptr [esi + 8]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */))++;
L_0x004844e7:
    // 004844e7  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004844ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004844eb  ff7708                 -push dword ptr [edi + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004844ee  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 004844f0  e887ffffff             -call 0x48447c
    cpu.esp -= 4;
    sub_48447c(app, cpu);
    // 004844f5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004844f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004844f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004844fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4844fb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004844fb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004844ff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484500  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484501  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00484503  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00484506  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00484508  03f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048450a  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0048450c  8d343f                 -lea esi, [edi + edi]
    cpu.esi = x86::reg32(cpu.edi + cpu.edi * 1);
    // 0048450f  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 00484512  0bf1                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484514  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00484517  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00484519  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0048451c  c1ea1f                 -shr edx, 0x1f
    cpu.edx >>= 31 /*0x1f*/ % 32;
    // 0048451f  d1e1                   -shl ecx, 1
    cpu.ecx <<= 1 /*0x1*/ % 32;
    // 00484521  0bca                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00484523  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484524  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00484527  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484528  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484529(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484529  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048452d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048452e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048452f  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00484532  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00484535  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00484537  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00484539  c1e61f                 -shl esi, 0x1f
    cpu.esi <<= 31 /*0x1f*/ % 32;
    // 0048453c  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 0048453e  0bce                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00484540  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00484543  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00484545  c1e71f                 -shl edi, 0x1f
    cpu.edi <<= 31 /*0x1f*/ % 32;
    // 00484548  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 0048454a  d1ea                   -shr edx, 1
    cpu.edx >>= 1 /*0x1*/ % 32;
    // 0048454c  0bcf                   -or ecx, edi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0048454e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048454f  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00484552  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00484554  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484555  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484556(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484556  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484557  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00484559  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048455c  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048455f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484560  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00484563  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00484565  3bc2                   +cmp eax, edx
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
    // 00484567  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484568  c745fc4e400000         -mov dword ptr [ebp - 4], 0x404e
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 16462 /*0x404e*/;
    // 0048456f  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00484571  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00484574  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00484577  7651                   -jbe 0x4845ca
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004845ca;
    }
    // 00484579  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048457a  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0048457d:
    // 0048457d  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048457f  8d7df0                 -lea edi, [ebp - 0x10]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484582  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484583  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484584  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484585  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484586  e870ffffff             -call 0x4844fb
    cpu.esp -= 4;
    sub_4844fb(app, cpu);
    // 0048458b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048458c  e86affffff             -call 0x4844fb
    cpu.esp -= 4;
    sub_4844fb(app, cpu);
    // 00484591  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484594  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484595  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484596  e802ffffff             -call 0x48449d
    cpu.esp -= 4;
    ___add_12(app, cpu);
    // 0048459b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048459c  e85affffff             -call 0x4844fb
    cpu.esp -= 4;
    sub_4844fb(app, cpu);
    // 004845a1  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004845a4  8365f400               -and dword ptr [ebp - 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004845a8  8365f800               -and dword ptr [ebp - 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004845ac  0fbe00                 -movsx eax, byte ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 004845af  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004845b2  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004845b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004845b6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004845b7  e8e1feffff             -call 0x48449d
    cpu.esp -= 4;
    ___add_12(app, cpu);
    // 004845bc  83c41c                 +add esp, 0x1c
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
    // 004845bf  ff4508                 +inc dword ptr [ebp + 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004845c2  ff4d10                 +dec dword ptr [ebp + 0x10]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004845c5  75b6                   -jne 0x48457d
    if (!cpu.flags.zf)
    {
        goto L_0x0048457d;
    }
    // 004845c7  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004845c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004845ca:
    // 004845ca  395308                 +cmp dword ptr [ebx + 8], edx
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
    // 004845cd  7528                   -jne 0x4845f7
    if (!cpu.flags.zf)
    {
        goto L_0x004845f7;
    }
    // 004845cf  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004845d2  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004845d4  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004845d7  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004845da  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004845dc  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004845de  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 004845e1  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004845e4  0bf1                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004845e6  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004845e9  8145fcf0ff0000         +add dword ptr [ebp - 4], 0xfff0
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
    // 004845f0  897304                 -mov dword ptr [ebx + 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004845f3  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004845f5  ebd3                   -jmp 0x4845ca
    goto L_0x004845ca;
L_0x004845f7:
    // 004845f7  be00800000             -mov esi, 0x8000
    cpu.esi = 32768 /*0x8000*/;
L_0x004845fc:
    // 004845fc  857308                 -test dword ptr [ebx + 8], esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) & cpu.esi));
    // 004845ff  7510                   -jne 0x484611
    if (!cpu.flags.zf)
    {
        goto L_0x00484611;
    }
    // 00484601  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484602  e8f4feffff             -call 0x4844fb
    cpu.esp -= 4;
    sub_4844fb(app, cpu);
    // 00484607  8145fcffff0000         +add dword ptr [ebp - 4], 0xffff
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
    // 0048460e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048460f  ebeb                   -jmp 0x4845fc
    goto L_0x004845fc;
L_0x00484611:
    // 00484611  668b45fc               -mov ax, word ptr [ebp - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00484615  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484616  6689430a               -mov word ptr [ebx + 0xa], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 0048461a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048461b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048461c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48461d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048461d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048461e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00484620  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00484623  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00484626  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484627  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048462a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048462b  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048462d  beff7f0000             -mov esi, 0x7fff
    cpu.esi = 32767 /*0x7fff*/;
    // 00484632  81e100800000           -and ecx, 0x8000
    cpu.ecx &= x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00484638  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 0048463a  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0048463d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048463e  c645e4cc               -mov byte ptr [ebp - 0x1c], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 204 /*0xcc*/;
    // 00484642  c645e5cc               -mov byte ptr [ebp - 0x1b], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-27) /* -0x1b */) = 204 /*0xcc*/;
    // 00484646  c645e6cc               -mov byte ptr [ebp - 0x1a], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-26) /* -0x1a */) = 204 /*0xcc*/;
    // 0048464a  c645e7cc               -mov byte ptr [ebp - 0x19], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-25) /* -0x19 */) = 204 /*0xcc*/;
    // 0048464e  c645e8cc               -mov byte ptr [ebp - 0x18], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = 204 /*0xcc*/;
    // 00484652  c645e9cc               -mov byte ptr [ebp - 0x17], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-23) /* -0x17 */) = 204 /*0xcc*/;
    // 00484656  c645eacc               -mov byte ptr [ebp - 0x16], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = 204 /*0xcc*/;
    // 0048465a  c645ebcc               -mov byte ptr [ebp - 0x15], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-21) /* -0x15 */) = 204 /*0xcc*/;
    // 0048465e  c645eccc               -mov byte ptr [ebp - 0x14], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 204 /*0xcc*/;
    // 00484662  c645edcc               -mov byte ptr [ebp - 0x13], 0xcc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-19) /* -0x13 */) = 204 /*0xcc*/;
    // 00484666  c645eefb               -mov byte ptr [ebp - 0x12], 0xfb
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-18) /* -0x12 */) = 251 /*0xfb*/;
    // 0048466a  c645ef3f               -mov byte ptr [ebp - 0x11], 0x3f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-17) /* -0x11 */) = 63 /*0x3f*/;
    // 0048466e  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00484675  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484677  7406                   -je 0x48467f
    if (cpu.flags.zf)
    {
        goto L_0x0048467f;
    }
    // 00484679  c643022d               -mov byte ptr [ebx + 2], 0x2d
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 45 /*0x2d*/;
    // 0048467d  eb04                   -jmp 0x484683
    goto L_0x00484683;
L_0x0048467f:
    // 0048467f  c6430220               -mov byte ptr [ebx + 2], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32 /*0x20*/;
L_0x00484683:
    // 00484683  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00484686  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 00484689  751e                   -jne 0x4846a9
    if (!cpu.flags.zf)
    {
        goto L_0x004846a9;
    }
    // 0048468b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048468d  751a                   -jne 0x4846a9
    if (!cpu.flags.zf)
    {
        goto L_0x004846a9;
    }
    // 0048468f  397d08                 +cmp dword ptr [ebp + 8], edi
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
    // 00484692  7515                   -jne 0x4846a9
    if (!cpu.flags.zf)
    {
        goto L_0x004846a9;
    }
L_0x00484694:
    // 00484694  66832300               +and word ptr [ebx], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.ebx) &= x86::reg16(x86::sreg16(0 /*0x0*/))));
    // 00484698  c6430220               -mov byte ptr [ebx + 2], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32 /*0x20*/;
    // 0048469c  c6430301               -mov byte ptr [ebx + 3], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = 1 /*0x1*/;
    // 004846a0  c6430430               -mov byte ptr [ebx + 4], 0x30
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 48 /*0x30*/;
    // 004846a4  e9fe010000             -jmp 0x4848a7
    goto L_0x004848a7;
L_0x004846a9:
    // 004846a9  663bd6                 +cmp dx, si
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
    // 004846ac  757a                   -jne 0x484728
    if (!cpu.flags.zf)
    {
        goto L_0x00484728;
    }
    // 004846ae  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 004846b3  66c7030100             -mov word ptr [ebx], 1
    app->getMemory<x86::reg16>(cpu.ebx) = 1 /*0x1*/;
    // 004846b8  3bf8                   +cmp edi, eax
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
    // 004846ba  7506                   -jne 0x4846c2
    if (!cpu.flags.zf)
    {
        goto L_0x004846c2;
    }
    // 004846bc  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 004846c0  740f                   -je 0x4846d1
    if (cpu.flags.zf)
    {
        goto L_0x004846d1;
    }
L_0x004846c2:
    // 004846c2  f7c700000040           +test edi, 0x40000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 1073741824 /*0x40000000*/));
    // 004846c8  7507                   -jne 0x4846d1
    if (!cpu.flags.zf)
    {
        goto L_0x004846d1;
    }
    // 004846ca  689c864800             -push 0x48869c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4753052 /*0x48869c*/;
    cpu.esp -= 4;
    // 004846cf  eb46                   -jmp 0x484717
    goto L_0x00484717;
L_0x004846d1:
    // 004846d1  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 004846d4  7415                   -je 0x4846eb
    if (cpu.flags.zf)
    {
        goto L_0x004846eb;
    }
    // 004846d6  81ff000000c0           +cmp edi, 0xc0000000
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
    // 004846dc  750d                   -jne 0x4846eb
    if (!cpu.flags.zf)
    {
        goto L_0x004846eb;
    }
    // 004846de  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 004846e2  752e                   -jne 0x484712
    if (!cpu.flags.zf)
    {
        goto L_0x00484712;
    }
    // 004846e4  6894864800             -push 0x488694
    app->getMemory<x86::reg32>(cpu.esp-4) = 4753044 /*0x488694*/;
    cpu.esp -= 4;
    // 004846e9  eb0f                   -jmp 0x4846fa
    goto L_0x004846fa;
L_0x004846eb:
    // 004846eb  3bf8                   +cmp edi, eax
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
    // 004846ed  7523                   -jne 0x484712
    if (!cpu.flags.zf)
    {
        goto L_0x00484712;
    }
    // 004846ef  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 004846f3  751d                   -jne 0x484712
    if (!cpu.flags.zf)
    {
        goto L_0x00484712;
    }
    // 004846f5  688c864800             -push 0x48868c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4753036 /*0x48868c*/;
    cpu.esp -= 4;
L_0x004846fa:
    // 004846fa  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004846fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004846fe  e82dabffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 00484703  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484704  c6430305               -mov byte ptr [ebx + 3], 5
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = 5 /*0x5*/;
    // 00484708  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484709:
    // 00484709  8365fc00               +and dword ptr [ebp - 4], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 0048470d  e96e010000             -jmp 0x484880
    goto L_0x00484880;
L_0x00484712:
    // 00484712  6884864800             -push 0x488684
    app->getMemory<x86::reg32>(cpu.esp-4) = 4753028 /*0x488684*/;
    cpu.esp -= 4;
L_0x00484717:
    // 00484717  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048471a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048471b  e810abffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 00484720  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484721  c6430306               -mov byte ptr [ebx + 3], 6
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = 6 /*0x6*/;
    // 00484725  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484726  ebe1                   -jmp 0x484709
    goto L_0x00484709;
L_0x00484728:
    // 00484728  0fb7c2                 -movzx eax, dx
    cpu.eax = x86::reg32(cpu.dx);
    // 0048472b  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0048472d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048472f  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00484732  69c0104d0000           -imul eax, eax, 0x4d10
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(19728 /*0x4d10*/)));
    // 00484738  c1ee08                 -shr esi, 8
    cpu.esi >>= 8 /*0x8*/ % 32;
    // 0048473b  668365f000             -and word ptr [ebp - 0x10], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */) &= x86::reg16(x86::sreg16(0 /*0x0*/));
    // 00484740  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484742  8d0c4e                 -lea ecx, [esi + ecx*2]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ecx * 2);
    // 00484745  668955fa               -mov word ptr [ebp - 6], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */) = cpu.dx;
    // 00484749  6bc94d                 -imul ecx, ecx, 0x4d
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(77 /*0x4d*/)));
    // 0048474c  897df6                 -mov dword ptr [ebp - 0xa], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */) = cpu.edi;
    // 0048474f  8db4010cedbcec         -lea esi, [ecx + eax - 0x134312f4]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-323162868) /* -0x134312f4 */ + cpu.eax * 1);
    // 00484756  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00484759  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0048475c  8945f2                 -mov dword ptr [ebp - 0xe], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */) = cpu.eax;
    // 0048475f  0fbfc6                 -movsx eax, si
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 00484762  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00484764  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484765  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484768  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484769  e8990b0000             -call 0x485307
    cpu.esp -= 4;
    sub_485307(app, cpu);
    // 0048476e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00484771  66817dfaff3f           +cmp word ptr [ebp - 6], 0x3fff
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
    // 00484777  7210                   -jb 0x484789
    if (cpu.flags.cf)
    {
        goto L_0x00484789;
    }
    // 00484779  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0048477c  46                     -inc esi
    (cpu.esi)++;
    // 0048477d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048477e  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484781  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484782  e860090000             -call 0x4850e7
    cpu.esp -= 4;
    sub_4850e7(app, cpu);
    // 00484787  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484788  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484789:
    // 00484789  f6451801               +test byte ptr [ebp + 0x18], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(24) /* 0x18 */) & 1 /*0x1*/));
    // 0048478d  668933                 -mov word ptr [ebx], si
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.si;
    // 00484790  7411                   -je 0x4847a3
    if (cpu.flags.zf)
    {
        goto L_0x004847a3;
    }
    // 00484792  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00484795  0fbfc6                 -movsx eax, si
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 00484798  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048479a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048479c  7f08                   -jg 0x4847a6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004847a6;
    }
    // 0048479e  e9f1feffff             -jmp 0x484694
    goto L_0x00484694;
L_0x004847a3:
    // 004847a3  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
L_0x004847a6:
    // 004847a6  83ff15                 +cmp edi, 0x15
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
    // 004847a9  7e03                   -jle 0x4847ae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004847ae;
    }
    // 004847ab  6a15                   -push 0x15
    app->getMemory<x86::reg32>(cpu.esp-4) = 21 /*0x15*/;
    cpu.esp -= 4;
    // 004847ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004847ae:
    // 004847ae  0fb775fa               -movzx esi, word ptr [ebp - 6]
    cpu.esi = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */));
    // 004847b2  81eefe3f0000           -sub esi, 0x3ffe
    (cpu.esi) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 004847b8  668365fa00             +and word ptr [ebp - 6], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */) &= x86::reg16(x86::sreg16(0 /*0x0*/))));
    // 004847bd  c7451c08000000         -mov dword ptr [ebp + 0x1c], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = 8 /*0x8*/;
L_0x004847c4:
    // 004847c4  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004847c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004847c8  e82efdffff             -call 0x4844fb
    cpu.esp -= 4;
    sub_4844fb(app, cpu);
    // 004847cd  ff4d1c                 +dec dword ptr [ebp + 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004847d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004847d1  75f1                   -jne 0x4847c4
    if (!cpu.flags.zf)
    {
        goto L_0x004847c4;
    }
    // 004847d3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004847d5  7d17                   -jge 0x4847ee
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004847ee;
    }
    // 004847d7  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 004847d9  81e6ff000000           +and esi, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004847df  7e0d                   -jle 0x4847ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004847ee;
    }
L_0x004847e1:
    // 004847e1  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004847e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004847e5  e83ffdffff             -call 0x484529
    cpu.esp -= 4;
    sub_484529(app, cpu);
    // 004847ea  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004847eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004847ec  75f3                   -jne 0x4847e1
    if (!cpu.flags.zf)
    {
        goto L_0x004847e1;
    }
L_0x004847ee:
    // 004847ee  8d4f01                 -lea ecx, [edi + 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004847f1  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004847f4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004847f6  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004847f9  7e50                   -jle 0x48484b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048484b;
    }
    // 004847fb  894d14                 -mov dword ptr [ebp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x004847fe:
    // 004847fe  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484801  8d7d08                 -lea edi, [ebp + 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00484804  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484805  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484806  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484809  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048480a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048480b  e8ebfcffff             -call 0x4844fb
    cpu.esp -= 4;
    sub_4844fb(app, cpu);
    // 00484810  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484813  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484814  e8e2fcffff             -call 0x4844fb
    cpu.esp -= 4;
    sub_4844fb(app, cpu);
    // 00484819  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048481c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048481d  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484820  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484821  e877fcffff             -call 0x48449d
    cpu.esp -= 4;
    ___add_12(app, cpu);
    // 00484826  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484829  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048482a  e8ccfcffff             -call 0x4844fb
    cpu.esp -= 4;
    sub_4844fb(app, cpu);
    // 0048482f  8a45fb                 -mov al, byte ptr [ebp - 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
    // 00484832  8b4d1c                 -mov ecx, dword ptr [ebp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00484835  8065fb00               -and byte ptr [ebp - 5], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00484839  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048483c  0430                   +add al, 0x30
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
    // 0048483e  ff451c                 +inc dword ptr [ebp + 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00484841  ff4d14                 +dec dword ptr [ebp + 0x14]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00484844  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 00484846  75b6                   -jne 0x4847fe
    if (!cpu.flags.zf)
    {
        goto L_0x004847fe;
    }
    // 00484848  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
L_0x0048484b:
    // 0048484b  8a48ff                 -mov cl, byte ptr [eax - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0048484e  48                     -dec eax
    (cpu.eax)--;
    // 0048484f  48                     -dec eax
    (cpu.eax)--;
    // 00484850  80f935                 +cmp cl, 0x35
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
    // 00484853  8d4b04                 -lea ecx, [ebx + 4]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00484856  7c30                   -jl 0x484888
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484888;
    }
L_0x00484858:
    // 00484858  3bc1                   +cmp eax, ecx
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
    // 0048485a  720f                   -jb 0x48486b
    if (cpu.flags.cf)
    {
        goto L_0x0048486b;
    }
    // 0048485c  803839                 +cmp byte ptr [eax], 0x39
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
    // 0048485f  7506                   -jne 0x484867
    if (!cpu.flags.zf)
    {
        goto L_0x00484867;
    }
    // 00484861  c60030                 -mov byte ptr [eax], 0x30
    app->getMemory<x86::reg8>(cpu.eax) = 48 /*0x30*/;
    // 00484864  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00484865  ebf1                   -jmp 0x484858
    goto L_0x00484858;
L_0x00484867:
    // 00484867  3bc1                   +cmp eax, ecx
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
    // 00484869  7304                   -jae 0x48486f
    if (!cpu.flags.cf)
    {
        goto L_0x0048486f;
    }
L_0x0048486b:
    // 0048486b  40                     -inc eax
    (cpu.eax)++;
    // 0048486c  66ff03                 -inc word ptr [ebx]
    (app->getMemory<x86::reg16>(cpu.ebx))++;
L_0x0048486f:
    // 0048486f  fe00                   -inc byte ptr [eax]
    (app->getMemory<x86::reg8>(cpu.eax))++;
L_0x00484871:
    // 00484871  2ac3                   -sub al, bl
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.bl));
    // 00484873  2c03                   -sub al, 3
    (cpu.al) -= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00484875  884303                 -mov byte ptr [ebx + 3], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00484878  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0048487b  8064180400             -and byte ptr [eax + ebx + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebx * 1) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x00484880:
    // 00484880  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x00484883:
    // 00484883  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484884  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484885  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484886  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484887  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484888:
    // 00484888  3bc1                   +cmp eax, ecx
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
    // 0048488a  720c                   -jb 0x484898
    if (cpu.flags.cf)
    {
        goto L_0x00484898;
    }
    // 0048488c  803830                 +cmp byte ptr [eax], 0x30
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
    // 0048488f  7503                   -jne 0x484894
    if (!cpu.flags.zf)
    {
        goto L_0x00484894;
    }
    // 00484891  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00484892  ebf4                   -jmp 0x484888
    goto L_0x00484888;
L_0x00484894:
    // 00484894  3bc1                   +cmp eax, ecx
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
    // 00484896  73d9                   -jae 0x484871
    if (!cpu.flags.cf)
    {
        goto L_0x00484871;
    }
L_0x00484898:
    // 00484898  66832300               -and word ptr [ebx], 0
    app->getMemory<x86::reg16>(cpu.ebx) &= x86::reg16(x86::sreg16(0 /*0x0*/));
    // 0048489c  c6430220               -mov byte ptr [ebx + 2], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32 /*0x20*/;
    // 004848a0  c6430301               -mov byte ptr [ebx + 3], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = 1 /*0x1*/;
    // 004848a4  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
L_0x004848a7:
    // 004848a7  80630500               +and byte ptr [ebx + 5], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 004848ab  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004848ad  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848ae  ebd3                   -jmp 0x484883
    goto L_0x00484883;
}

/* align: skip  */
void Application::sub_4848b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004848b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004848b1  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004848b3  391dc4eb5100           +cmp dword ptr [0x51ebc4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004848b9  7513                   -jne 0x4848ce
    if (!cpu.flags.zf)
    {
        goto L_0x004848ce;
    }
    // 004848bb  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004848bf  83f861                 +cmp eax, 0x61
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004848c2  7c59                   -jl 0x48491d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048491d;
    }
    // 004848c4  83f87a                 +cmp eax, 0x7a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004848c7  7f54                   -jg 0x48491d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048491d;
    }
    // 004848c9  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004848cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004848ce:
    // 004848ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004848cf  bee81f5200             -mov esi, 0x521fe8
    cpu.esi = 5382120 /*0x521fe8*/;
    // 004848d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004848d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004848d6  ff15ac714800           -call dword ptr [0x4871ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747692) /* 0x4871ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004848dc  391de41f5200           +cmp dword ptr [0x521fe4], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382116) /* 0x521fe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004848e2  8b3d8c714800           -mov edi, dword ptr [0x48718c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747660) /* 0x48718c */);
    // 004848e8  740e                   -je 0x4848f8
    if (cpu.flags.zf)
    {
        goto L_0x004848f8;
    }
    // 004848ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004848eb  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004848ed  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 004848ef  e8d581ffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 004848f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848f5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004848f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004848f8:
    // 004848f8  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004848fc  e81e000000             -call 0x48491f
    cpu.esp -= 4;
    sub_48491f(app, cpu);
    // 00484901  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00484903  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484904  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00484908  740a                   -je 0x484914
    if (cpu.flags.zf)
    {
        goto L_0x00484914;
    }
    // 0048490a  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 0048490c  e81982ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00484911  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484912  eb03                   -jmp 0x484917
    goto L_0x00484917;
L_0x00484914:
    // 00484914  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484915  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00484917:
    // 00484917  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048491b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048491c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048491d:
    // 0048491d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048491e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48491f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048491f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484920  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00484922  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484923  833dc4eb510000         +cmp dword ptr [0x51ebc4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048492a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048492b  751d                   -jne 0x48494a
    if (!cpu.flags.zf)
    {
        goto L_0x0048494a;
    }
    // 0048492d  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00484930  83f861                 +cmp eax, 0x61
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484933  0f8caf000000           -jl 0x4849e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004849e8;
    }
    // 00484939  83f87a                 +cmp eax, 0x7a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048493c  0f8fa6000000           -jg 0x4849e8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004849e8;
    }
    // 00484942  83e820                 +sub eax, 0x20
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
    // 00484945  e99e000000             -jmp 0x4849e8
    goto L_0x004849e8;
L_0x0048494a:
    // 0048494a  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048494d  81fb00010000           +cmp ebx, 0x100
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484953  7d28                   -jge 0x48497d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048497d;
    }
    // 00484955  833d18644a0001         +cmp dword ptr [0x4a6418], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4875288) /* 0x4a6418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048495c  7e0c                   -jle 0x48496a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048496a;
    }
    // 0048495e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00484960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484961  e82389ffff             -call 0x47d289
    cpu.esp -= 4;
    sub_47d289(app, cpu);
    // 00484966  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484967  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484968  eb0b                   -jmp 0x484975
    goto L_0x00484975;
L_0x0048496a:
    // 0048496a  a10c624a00             -mov eax, dword ptr [0x4a620c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 0048496f  8a0458                 -mov al, byte ptr [eax + ebx*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 2);
    // 00484972  83e002                 -and eax, 2
    cpu.eax &= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00484975:
    // 00484975  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484977  7504                   -jne 0x48497d
    if (!cpu.flags.zf)
    {
        goto L_0x0048497d;
    }
L_0x00484979:
    // 00484979  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048497b  eb6b                   -jmp 0x4849e8
    goto L_0x004849e8;
L_0x0048497d:
    // 0048497d  8b150c624a00           -mov edx, dword ptr [0x4a620c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4874764) /* 0x4a620c */);
    // 00484983  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484985  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00484988  0fb6c8                 -movzx ecx, al
    cpu.ecx = x86::reg32(cpu.al);
    // 0048498b  f6444a0180             +test byte ptr [edx + ecx*2 + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.ecx * 2) & 128 /*0x80*/));
    // 00484990  740e                   -je 0x4849a0
    if (cpu.flags.zf)
    {
        goto L_0x004849a0;
    }
    // 00484992  80650a00               +and byte ptr [ebp + 0xa], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(10) /* 0xa */) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 00484996  884508                 -mov byte ptr [ebp + 8], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 00484999  885d09                 -mov byte ptr [ebp + 9], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(9) /* 0x9 */) = cpu.bl;
    // 0048499c  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0048499e  eb09                   -jmp 0x4849a9
    goto L_0x004849a9;
L_0x004849a0:
    // 004849a0  80650900               -and byte ptr [ebp + 9], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(9) /* 0x9 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 004849a4  885d08                 -mov byte ptr [ebp + 8], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.bl;
    // 004849a7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
L_0x004849a9:
    // 004849a9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849aa  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004849ad  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004849af  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004849b1  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004849b3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004849b4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004849b5  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004849b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004849b9  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 004849be  ff35c4eb5100           -push dword ptr [0x51ebc4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
    cpu.esp -= 4;
    // 004849c4  e89c86ffff             -call 0x47d065
    cpu.esp -= 4;
    sub_47d065(app, cpu);
    // 004849c9  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004849cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004849ce  74a9                   -je 0x484979
    if (cpu.flags.zf)
    {
        goto L_0x00484979;
    }
    // 004849d0  83f801                 +cmp eax, 1
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
    // 004849d3  7506                   -jne 0x4849db
    if (!cpu.flags.zf)
    {
        goto L_0x004849db;
    }
    // 004849d5  0fb645fc               -movzx eax, byte ptr [ebp - 4]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 004849d9  eb0d                   -jmp 0x4849e8
    goto L_0x004849e8;
L_0x004849db:
    // 004849db  0fb645fd               -movzx eax, byte ptr [ebp - 3]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */));
    // 004849df  0fb64dfc               -movzx ecx, byte ptr [ebp - 4]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 004849e3  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004849e6  0bc1                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004849e8:
    // 004849e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849e9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4849eb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004849eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004849ec  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004849ee  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004849f0  68c8874800             -push 0x4887c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4753352 /*0x4887c8*/;
    cpu.esp -= 4;
    // 004849f5  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 004849fa  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00484a00  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484a01  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00484a08  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00484a0b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484a0c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484a0d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484a0e  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00484a11  a150ee5100             -mov eax, dword ptr [0x51ee50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369424) /* 0x51ee50 */);
    // 00484a16  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484a18  3bc7                   +cmp eax, edi
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
    // 00484a1a  753e                   -jne 0x484a5a
    if (!cpu.flags.zf)
    {
        goto L_0x00484a5a;
    }
    // 00484a1c  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00484a1f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484a20  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484a22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484a24  68487e4800             -push 0x487e48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750920 /*0x487e48*/;
    cpu.esp -= 4;
    // 00484a29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484a2a  ff1584714800           -call dword ptr [0x487184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747652) /* 0x487184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484a30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484a32  7404                   -je 0x484a38
    if (cpu.flags.zf)
    {
        goto L_0x00484a38;
    }
    // 00484a34  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00484a36  eb1d                   -jmp 0x484a55
    goto L_0x00484a55;
L_0x00484a38:
    // 00484a38  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00484a3b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484a3c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484a3d  68447e4800             -push 0x487e44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750916 /*0x487e44*/;
    cpu.esp -= 4;
    // 00484a42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484a43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484a44  ff15e4704800           -call dword ptr [0x4870e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747492) /* 0x4870e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484a4a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484a4c  0f844a010000           -je 0x484b9c
    if (cpu.flags.zf)
    {
        return sub_484b9c(app, cpu);
    }
    // 00484a52  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00484a54  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484a55:
    // 00484a55  a350ee5100             -mov dword ptr [0x51ee50], eax
    app->getMemory<x86::reg32>(x86::reg32(5369424) /* 0x51ee50 */) = cpu.eax;
L_0x00484a5a:
    // 00484a5a  83f801                 +cmp eax, 1
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
    // 00484a5d  7517                   -jne 0x484a76
    if (!cpu.flags.zf)
    {
        goto L_0x00484a76;
    }
    // 00484a5f  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00484a62  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00484a65  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00484a68  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00484a6b  ff1584714800           -call dword ptr [0x487184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747652) /* 0x487184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484a71  e928010000             -jmp 0x484b9e
    return sub_484b9e(app, cpu);
L_0x00484a76:
    // 00484a76  83f802                 +cmp eax, 2
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
    // 00484a79  0f851d010000           -jne 0x484b9c
    if (!cpu.flags.zf)
    {
        return sub_484b9c(app, cpu);
    }
    // 00484a7f  397d18                 +cmp dword ptr [ebp + 0x18], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484a82  7508                   -jne 0x484a8c
    if (!cpu.flags.zf)
    {
        goto L_0x00484a8c;
    }
    // 00484a84  a1d4eb5100             -mov eax, dword ptr [0x51ebd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    // 00484a89  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00484a8c:
    // 00484a8c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484a8d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484a8e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484a8f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484a90  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00484a93  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00484a96  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 00484a9b  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00484a9e  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484aa4  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484aa6  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 00484aa9  3bf7                   +cmp esi, edi
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
    // 00484aab  0f84eb000000           -je 0x484b9c
    if (cpu.flags.zf)
    {
        return sub_484b9c(app, cpu);
    }
    // 00484ab1  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00484ab4  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00484ab7  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00484ab9  e87232ffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 00484abe  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00484ac1  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00484ac3  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 00484ac6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484ac7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484ac8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484ac9  e852ccffff             -call 0x481720
    cpu.esp -= 4;
    _memset(app, cpu);
    // 00484ace  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00484ad1  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00484ad5  eb13                   -jmp 0x484aea
    return sub_484aea(app, cpu);
}

/* align: skip  */
void Application::sub_484ad7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484ad7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484ad9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ada  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484adb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484adb  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00484ade  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484ae0  897dd4                 -mov dword ptr [ebp - 0x2c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.edi;
    // 00484ae3  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00484ae7  8b75d8                 -mov esi, dword ptr [ebp - 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00484aea  397dd4                 +cmp dword ptr [ebp - 0x2c], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484aed  0f84a9000000           -je 0x484b9c
    if (cpu.flags.zf)
    {
        return sub_484b9c(app, cpu);
    }
    // 00484af3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484af4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484af5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484af6  ff75d4                 -push dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    cpu.esp -= 4;
    // 00484af9  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00484afc  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00484aff  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 00484b04  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00484b07  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484b0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484b0f  0f8487000000           -je 0x484b9c
    if (cpu.flags.zf)
    {
        return sub_484b9c(app, cpu);
    }
    // 00484b15  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00484b1c  8d443602               -lea eax, [esi + esi + 2]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.esi * 1);
    // 00484b20  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00484b23  24fc                   +and al, 0xfc
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/))));
    // 00484b25  e80632ffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 00484b2a  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00484b2d  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00484b2f  895ddc                 -mov dword ptr [ebp - 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ebx;
    // 00484b32  eb0b                   -jmp 0x484b3f
    return sub_484b3f(app, cpu);
}

/* align: skip  */
void Application::sub_484aea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00484aea;
    // 00484adb  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00484ade  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484ae0  897dd4                 -mov dword ptr [ebp - 0x2c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.edi;
    // 00484ae3  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00484ae7  8b75d8                 -mov esi, dword ptr [ebp - 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
L_entry_0x00484aea:
    // 00484aea  397dd4                 +cmp dword ptr [ebp - 0x2c], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484aed  0f84a9000000           -je 0x484b9c
    if (cpu.flags.zf)
    {
        return sub_484b9c(app, cpu);
    }
    // 00484af3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484af4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484af5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484af6  ff75d4                 -push dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    cpu.esp -= 4;
    // 00484af9  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00484afc  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00484aff  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 00484b04  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00484b07  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484b0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484b0f  0f8487000000           -je 0x484b9c
    if (cpu.flags.zf)
    {
        return sub_484b9c(app, cpu);
    }
    // 00484b15  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00484b1c  8d443602               -lea eax, [esi + esi + 2]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.esi * 1);
    // 00484b20  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00484b23  24fc                   +and al, 0xfc
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/))));
    // 00484b25  e80632ffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 00484b2a  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00484b2d  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00484b2f  895ddc                 -mov dword ptr [ebp - 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ebx;
    // 00484b32  eb0b                   -jmp 0x484b3f
    return sub_484b3f(app, cpu);
}

/* align: skip  */
void Application::sub_484b34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484b34  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484b36  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484b38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484b38  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00484b3b  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484b3d  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484b3f  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00484b43  3bdf                   +cmp ebx, edi
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
    // 00484b45  7455                   -je 0x484b9c
    if (cpu.flags.zf)
    {
        goto L_0x00484b9c;
    }
    // 00484b47  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00484b4a  3bc7                   +cmp eax, edi
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
    // 00484b4c  7505                   -jne 0x484b53
    if (!cpu.flags.zf)
    {
        goto L_0x00484b53;
    }
    // 00484b4e  a1c4eb5100             -mov eax, dword ptr [0x51ebc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
L_0x00484b53:
    // 00484b53  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00484b56  8d3c09                 -lea edi, [ecx + ecx]
    cpu.edi = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 00484b59  8d341f                 -lea esi, [edi + ebx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 00484b5c  66810effff             -or word ptr [esi], 0xffff
    app->getMemory<x86::reg16>(cpu.esi) |= x86::reg16(x86::sreg16(65535 /*0xffff*/));
    // 00484b61  66814efeffff           -or word ptr [esi - 2], 0xffff
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) |= x86::reg16(x86::sreg16(65535 /*0xffff*/));
    // 00484b67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484b68  ff75d8                 -push dword ptr [ebp - 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    cpu.esp -= 4;
    // 00484b6b  ff75d4                 -push dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    cpu.esp -= 4;
    // 00484b6e  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00484b71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484b72  ff15e4704800           -call dword ptr [0x4870e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747492) /* 0x4870e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484b78  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00484b7b  66817efeffff           +cmp word ptr [esi - 2], 0xffff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65535 /*0xffff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00484b81  7419                   -je 0x484b9c
    if (cpu.flags.zf)
    {
        goto L_0x00484b9c;
    }
    // 00484b83  66813effff             +cmp word ptr [esi], 0xffff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65535 /*0xffff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00484b88  7512                   -jne 0x484b9c
    if (!cpu.flags.zf)
    {
        goto L_0x00484b9c;
    }
    // 00484b8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484b8b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484b8c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00484b8f  e8ccd2ffff             -call 0x481e60
    cpu.esp -= 4;
    sub_481e60(app, cpu);
    // 00484b94  83c40c                 +add esp, 0xc
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
    // 00484b97  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00484b9a  eb02                   -jmp 0x484b9e
    goto L_0x00484b9e;
L_0x00484b9c:
    // 00484b9c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00484b9e:
    // 00484b9e  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 00484ba1  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484ba4  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00484bab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bae  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484baf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484b3f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00484b3f;
    // 00484b38  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00484b3b  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484b3d  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_entry_0x00484b3f:
    // 00484b3f  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00484b43  3bdf                   +cmp ebx, edi
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
    // 00484b45  7455                   -je 0x484b9c
    if (cpu.flags.zf)
    {
        goto L_0x00484b9c;
    }
    // 00484b47  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00484b4a  3bc7                   +cmp eax, edi
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
    // 00484b4c  7505                   -jne 0x484b53
    if (!cpu.flags.zf)
    {
        goto L_0x00484b53;
    }
    // 00484b4e  a1c4eb5100             -mov eax, dword ptr [0x51ebc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
L_0x00484b53:
    // 00484b53  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00484b56  8d3c09                 -lea edi, [ecx + ecx]
    cpu.edi = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 00484b59  8d341f                 -lea esi, [edi + ebx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 00484b5c  66810effff             -or word ptr [esi], 0xffff
    app->getMemory<x86::reg16>(cpu.esi) |= x86::reg16(x86::sreg16(65535 /*0xffff*/));
    // 00484b61  66814efeffff           -or word ptr [esi - 2], 0xffff
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) |= x86::reg16(x86::sreg16(65535 /*0xffff*/));
    // 00484b67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484b68  ff75d8                 -push dword ptr [ebp - 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    cpu.esp -= 4;
    // 00484b6b  ff75d4                 -push dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    cpu.esp -= 4;
    // 00484b6e  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00484b71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484b72  ff15e4704800           -call dword ptr [0x4870e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747492) /* 0x4870e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484b78  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00484b7b  66817efeffff           +cmp word ptr [esi - 2], 0xffff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65535 /*0xffff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00484b81  7419                   -je 0x484b9c
    if (cpu.flags.zf)
    {
        goto L_0x00484b9c;
    }
    // 00484b83  66813effff             +cmp word ptr [esi], 0xffff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65535 /*0xffff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00484b88  7512                   -jne 0x484b9c
    if (!cpu.flags.zf)
    {
        goto L_0x00484b9c;
    }
    // 00484b8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484b8b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484b8c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00484b8f  e8ccd2ffff             -call 0x481e60
    cpu.esp -= 4;
    sub_481e60(app, cpu);
    // 00484b94  83c40c                 +add esp, 0xc
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
    // 00484b97  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00484b9a  eb02                   -jmp 0x484b9e
    goto L_0x00484b9e;
L_0x00484b9c:
    // 00484b9c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00484b9e:
    // 00484b9e  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 00484ba1  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484ba4  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00484bab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bae  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484baf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484b9e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00484b9e;
    // 00484b38  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00484b3b  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484b3d  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484b3f  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00484b43  3bdf                   +cmp ebx, edi
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
    // 00484b45  7455                   -je 0x484b9c
    if (cpu.flags.zf)
    {
        goto L_0x00484b9c;
    }
    // 00484b47  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00484b4a  3bc7                   +cmp eax, edi
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
    // 00484b4c  7505                   -jne 0x484b53
    if (!cpu.flags.zf)
    {
        goto L_0x00484b53;
    }
    // 00484b4e  a1c4eb5100             -mov eax, dword ptr [0x51ebc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
L_0x00484b53:
    // 00484b53  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00484b56  8d3c09                 -lea edi, [ecx + ecx]
    cpu.edi = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 00484b59  8d341f                 -lea esi, [edi + ebx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 00484b5c  66810effff             -or word ptr [esi], 0xffff
    app->getMemory<x86::reg16>(cpu.esi) |= x86::reg16(x86::sreg16(65535 /*0xffff*/));
    // 00484b61  66814efeffff           -or word ptr [esi - 2], 0xffff
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) |= x86::reg16(x86::sreg16(65535 /*0xffff*/));
    // 00484b67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484b68  ff75d8                 -push dword ptr [ebp - 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    cpu.esp -= 4;
    // 00484b6b  ff75d4                 -push dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    cpu.esp -= 4;
    // 00484b6e  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00484b71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484b72  ff15e4704800           -call dword ptr [0x4870e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747492) /* 0x4870e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484b78  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00484b7b  66817efeffff           +cmp word ptr [esi - 2], 0xffff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65535 /*0xffff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00484b81  7419                   -je 0x484b9c
    if (cpu.flags.zf)
    {
        goto L_0x00484b9c;
    }
    // 00484b83  66813effff             +cmp word ptr [esi], 0xffff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65535 /*0xffff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00484b88  7512                   -jne 0x484b9c
    if (!cpu.flags.zf)
    {
        goto L_0x00484b9c;
    }
    // 00484b8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484b8b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484b8c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00484b8f  e8ccd2ffff             -call 0x481e60
    cpu.esp -= 4;
    sub_481e60(app, cpu);
    // 00484b94  83c40c                 +add esp, 0xc
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
    // 00484b97  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00484b9a  eb02                   -jmp 0x484b9e
    goto L_0x00484b9e;
L_0x00484b9c:
    // 00484b9c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00484b9e:
L_entry_0x00484b9e:
    // 00484b9e  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 00484ba1  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484ba4  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00484bab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bae  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484baf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484b9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00484b9c;
    // 00484b38  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00484b3b  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484b3d  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484b3f  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00484b43  3bdf                   +cmp ebx, edi
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
    // 00484b45  7455                   -je 0x484b9c
    if (cpu.flags.zf)
    {
        goto L_0x00484b9c;
    }
    // 00484b47  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00484b4a  3bc7                   +cmp eax, edi
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
    // 00484b4c  7505                   -jne 0x484b53
    if (!cpu.flags.zf)
    {
        goto L_0x00484b53;
    }
    // 00484b4e  a1c4eb5100             -mov eax, dword ptr [0x51ebc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
L_0x00484b53:
    // 00484b53  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00484b56  8d3c09                 -lea edi, [ecx + ecx]
    cpu.edi = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 00484b59  8d341f                 -lea esi, [edi + ebx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 00484b5c  66810effff             -or word ptr [esi], 0xffff
    app->getMemory<x86::reg16>(cpu.esi) |= x86::reg16(x86::sreg16(65535 /*0xffff*/));
    // 00484b61  66814efeffff           -or word ptr [esi - 2], 0xffff
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) |= x86::reg16(x86::sreg16(65535 /*0xffff*/));
    // 00484b67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484b68  ff75d8                 -push dword ptr [ebp - 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    cpu.esp -= 4;
    // 00484b6b  ff75d4                 -push dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    cpu.esp -= 4;
    // 00484b6e  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00484b71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484b72  ff15e4704800           -call dword ptr [0x4870e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747492) /* 0x4870e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484b78  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00484b7b  66817efeffff           +cmp word ptr [esi - 2], 0xffff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65535 /*0xffff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00484b81  7419                   -je 0x484b9c
    if (cpu.flags.zf)
    {
        goto L_0x00484b9c;
    }
    // 00484b83  66813effff             +cmp word ptr [esi], 0xffff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65535 /*0xffff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00484b88  7512                   -jne 0x484b9c
    if (!cpu.flags.zf)
    {
        goto L_0x00484b9c;
    }
    // 00484b8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484b8b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484b8c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00484b8f  e8ccd2ffff             -call 0x481e60
    cpu.esp -= 4;
    sub_481e60(app, cpu);
    // 00484b94  83c40c                 +add esp, 0xc
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
    // 00484b97  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00484b9a  eb02                   -jmp 0x484b9e
    goto L_0x00484b9e;
L_0x00484b9c:
L_entry_0x00484b9c:
    // 00484b9c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00484b9e:
    // 00484b9e  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 00484ba1  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484ba4  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00484bab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bae  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484baf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484bb0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484bb1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00484bb3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484bb4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484bb5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484bb6  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00484bb9  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00484bbc  8d05bceb5100           -lea eax, [0x51ebbc]
    cpu.eax = x86::reg32(x86::reg32(5368764) /* 0x51ebbc */);
    // 00484bc2  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00484bc6  753b                   -jne 0x484c03
    if (!cpu.flags.zf)
    {
        goto L_0x00484c03;
    }
    // 00484bc8  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 00484bca  8bff                   -mov edi, edi
    cpu.edi = cpu.edi;
L_0x00484bcc:
    // 00484bcc  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 00484bce  742e                   -je 0x484bfe
    if (cpu.flags.zf)
    {
        goto L_0x00484bfe;
    }
    // 00484bd0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00484bd2  46                     -inc esi
    (cpu.esi)++;
    // 00484bd3  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 00484bd5  47                     -inc edi
    (cpu.edi)++;
    // 00484bd6  38c4                   +cmp ah, al
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
    // 00484bd8  74f2                   -je 0x484bcc
    if (cpu.flags.zf)
    {
        goto L_0x00484bcc;
    }
    // 00484bda  2c41                   -sub al, 0x41
    (cpu.al) -= x86::reg8(x86::sreg8(65 /*0x41*/));
    // 00484bdc  3c1a                   +cmp al, 0x1a
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
    // 00484bde  1ac9                   -sbb cl, cl
    (cpu.cl) -= x86::reg8(x86::sreg8(cpu.cl) + cpu.flags.cf);
    // 00484be0  80e120                 -and cl, 0x20
    cpu.cl &= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00484be3  02c1                   -add al, cl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.cl));
    // 00484be5  0441                   -add al, 0x41
    (cpu.al) += x86::reg8(x86::sreg8(65 /*0x41*/));
    // 00484be7  86e0                   -xchg al, ah
    {
        x86::reg8 tmp = cpu.al;
        cpu.al = cpu.ah;
        cpu.ah = tmp;
    }
    // 00484be9  2c41                   -sub al, 0x41
    (cpu.al) -= x86::reg8(x86::sreg8(65 /*0x41*/));
    // 00484beb  3c1a                   +cmp al, 0x1a
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
    // 00484bed  1ac9                   -sbb cl, cl
    (cpu.cl) -= x86::reg8(x86::sreg8(cpu.cl) + cpu.flags.cf);
    // 00484bef  80e120                 -and cl, 0x20
    cpu.cl &= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00484bf2  02c1                   -add al, cl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.cl));
    // 00484bf4  0441                   -add al, 0x41
    (cpu.al) += x86::reg8(x86::sreg8(65 /*0x41*/));
    // 00484bf6  38e0                   +cmp al, ah
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
    // 00484bf8  74d2                   -je 0x484bcc
    if (cpu.flags.zf)
    {
        goto L_0x00484bcc;
    }
    // 00484bfa  1ac0                   +sbb al, al
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
    // 00484bfc  1cff                   +sbb al, 0xff
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
L_0x00484bfe:
    // 00484bfe  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00484c01  eb78                   -jmp 0x484c7b
    goto L_0x00484c7b;
L_0x00484c03:
    // 00484c03  f0ff05e81f5200         -lock inc dword ptr [0x521fe8]
    x86::atomic_increment(reinterpret_cast<x86::reg32 *>(x86::reg32(5382120) /* 0x521fe8 */));
    // 00484c0a  833de41f520000         +cmp dword ptr [0x521fe4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382116) /* 0x521fe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484c11  7f04                   -jg 0x484c17
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00484c17;
    }
    // 00484c13  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484c15  eb15                   -jmp 0x484c2c
    goto L_0x00484c2c;
L_0x00484c17:
    // 00484c17  f0ff0de81f5200         -lock dec dword ptr [0x521fe8]
    x86::atomic_decrement(reinterpret_cast<x86::reg32 *>(x86::reg32(5382120) /* 0x521fe8 */));
    // 00484c1e  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00484c20  e8a47effff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00484c25  c7042401000000         -mov dword ptr [esp], 1
    app->getMemory<x86::reg32>(cpu.esp) = 1 /*0x1*/;
L_0x00484c2c:
    // 00484c2c  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00484c31  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484c33  90                     -nop 
    ;
L_0x00484c34:
    // 00484c34  0ac0                   +or al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(cpu.al))));
    // 00484c36  7427                   -je 0x484c5f
    if (cpu.flags.zf)
    {
        goto L_0x00484c5f;
    }
    // 00484c38  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00484c3a  46                     -inc esi
    (cpu.esi)++;
    // 00484c3b  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00484c3d  47                     -inc edi
    (cpu.edi)++;
    // 00484c3e  38d8                   +cmp al, bl
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
    // 00484c40  74f2                   -je 0x484c34
    if (cpu.flags.zf)
    {
        goto L_0x00484c34;
    }
    // 00484c42  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484c43  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484c44  e8c328ffff             -call 0x47750c
    cpu.esp -= 4;
    sub_47750c(app, cpu);
    // 00484c49  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00484c4b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484c4e  e8b928ffff             -call 0x47750c
    cpu.esp -= 4;
    sub_47750c(app, cpu);
    // 00484c53  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484c56  38c3                   +cmp bl, al
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
    // 00484c58  74da                   -je 0x484c34
    if (cpu.flags.zf)
    {
        goto L_0x00484c34;
    }
    // 00484c5a  1bc0                   +sbb eax, eax
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
    // 00484c5c  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x00484c5f:
    // 00484c5f  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00484c61  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c62  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00484c64  7509                   -jne 0x484c6f
    if (!cpu.flags.zf)
    {
        goto L_0x00484c6f;
    }
    // 00484c66  f0ff0de81f5200         +lock dec dword ptr [0x521fe8]
    {
        x86::reg32 tmp = x86::atomic_decrement(reinterpret_cast<x86::reg32 *>(x86::reg32(5382120) /* 0x521fe8 */));
        cpu.flags.of = (tmp == 0x7fffffff);
        cpu.set_szp(tmp);
    }
    // 00484c6d  eb0a                   -jmp 0x484c79
    goto L_0x00484c79;
L_0x00484c6f:
    // 00484c6f  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00484c71  e8b47effff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00484c76  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00484c79:
    // 00484c79  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00484c7b:
    // 00484c7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c7d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c7e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484c80  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484c81  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00484c83  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484c84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484c85  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484c86  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00484c89  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00484c8c  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00484c8f  a882                   +test al, 0x82
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 130 /*0x82*/));
    // 00484c91  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00484c94  0f84ff000000           -je 0x484d99
    if (cpu.flags.zf)
    {
        goto L_0x00484d99;
    }
    // 00484c9a  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00484c9c  0f85f7000000           -jne 0x484d99
    if (!cpu.flags.zf)
    {
        goto L_0x00484d99;
    }
    // 00484ca2  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484ca4  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00484ca6  7415                   -je 0x484cbd
    if (cpu.flags.zf)
    {
        goto L_0x00484cbd;
    }
    // 00484ca8  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00484caa  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00484cad  0f84e6000000           -je 0x484d99
    if (cpu.flags.zf)
    {
        goto L_0x00484d99;
    }
    // 00484cb3  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00484cb6  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00484cb8  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00484cba  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00484cbd:
    // 00484cbd  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00484cc0  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00484cc3  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00484cc5  895d0c                 -mov dword ptr [ebp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00484cc8  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00484cca  66a90c01               +test ax, 0x10c
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 268 /*0x10c*/));
    // 00484cce  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00484cd1  7525                   -jne 0x484cf8
    if (!cpu.flags.zf)
    {
        goto L_0x00484cf8;
    }
    // 00484cd3  81fe283d4a00           +cmp esi, 0x4a3d28
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4865320 /*0x4a3d28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484cd9  7408                   -je 0x484ce3
    if (cpu.flags.zf)
    {
        goto L_0x00484ce3;
    }
    // 00484cdb  81fe483d4a00           +cmp esi, 0x4a3d48
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4865352 /*0x4a3d48*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484ce1  750b                   -jne 0x484cee
    if (!cpu.flags.zf)
    {
        goto L_0x00484cee;
    }
L_0x00484ce3:
    // 00484ce3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484ce4  e8b5d4ffff             -call 0x48219e
    cpu.esp -= 4;
    sub_48219e(app, cpu);
    // 00484ce9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484ceb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484cec  7507                   -jne 0x484cf5
    if (!cpu.flags.zf)
    {
        goto L_0x00484cf5;
    }
L_0x00484cee:
    // 00484cee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484cef  e881d6ffff             -call 0x482375
    cpu.esp -= 4;
    sub_482375(app, cpu);
    // 00484cf4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484cf5:
    // 00484cf5  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x00484cf8:
    // 00484cf8  66f7460c0801           +test word ptr [esi + 0xc], 0x108
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) & 264 /*0x108*/));
    // 00484cfe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484cff  7468                   -je 0x484d69
    if (cpu.flags.zf)
    {
        goto L_0x00484d69;
    }
    // 00484d01  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00484d04  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00484d06  2bf8                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00484d08  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00484d0b  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00484d0d  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00484d10  4a                     -dec edx
    (cpu.edx)--;
    // 00484d11  4a                     -dec edx
    (cpu.edx)--;
    // 00484d12  3bfb                   +cmp edi, ebx
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
    // 00484d14  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00484d17  7e10                   -jle 0x484d29
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484d29;
    }
    // 00484d19  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484d1a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484d1b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484d1c  e8fe4bffff             -call 0x47991f
    cpu.esp -= 4;
    sub_47991f(app, cpu);
    // 00484d21  83c40c                 +add esp, 0xc
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
    // 00484d24  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00484d27  eb35                   -jmp 0x484d5e
    goto L_0x00484d5e;
L_0x00484d29:
    // 00484d29  83f9ff                 +cmp ecx, -1
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
    // 00484d2c  7419                   -je 0x484d47
    if (cpu.flags.zf)
    {
        goto L_0x00484d47;
    }
    // 00484d2e  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00484d30  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484d32  c1fa05                 -sar edx, 5
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (5 /*0x5*/ % 32));
    // 00484d35  83e01f                 +and eax, 0x1f
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/))));
    // 00484d38  8b1495e01e5200         -mov edx, dword ptr [edx*4 + 0x521ee0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5381856) /* 0x521ee0 */ + cpu.edx * 4);
    // 00484d3f  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 00484d42  8d0482                 -lea eax, [edx + eax*4]
    cpu.eax = x86::reg32(cpu.edx + cpu.eax * 4);
    // 00484d45  eb05                   -jmp 0x484d4c
    goto L_0x00484d4c;
L_0x00484d47:
    // 00484d47  b830644a00             -mov eax, 0x4a6430
    cpu.eax = 4875312 /*0x4a6430*/;
L_0x00484d4c:
    // 00484d4c  f6400420               +test byte ptr [eax + 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) & 32 /*0x20*/));
    // 00484d50  740c                   -je 0x484d5e
    if (cpu.flags.zf)
    {
        goto L_0x00484d5e;
    }
    // 00484d52  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00484d54  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484d55  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484d56  e86997ffff             -call 0x47e4c4
    cpu.esp -= 4;
    sub_47e4c4(app, cpu);
    // 00484d5b  83c40c                 +add esp, 0xc
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
L_0x00484d5e:
    // 00484d5e  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00484d61  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00484d64  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 00484d67  eb1b                   -jmp 0x484d84
    goto L_0x00484d84;
L_0x00484d69:
    // 00484d69  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00484d6c  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00484d6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d6f  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00484d72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484d73  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484d74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484d75  66895d08               -mov word ptr [ebp + 8], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.bx;
    // 00484d79  e8a14bffff             -call 0x47991f
    cpu.esp -= 4;
    sub_47991f(app, cpu);
    // 00484d7e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00484d81  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00484d84:
    // 00484d84  397d0c                 +cmp dword ptr [ebp + 0xc], edi
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
    // 00484d87  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d88  7406                   -je 0x484d90
    if (cpu.flags.zf)
    {
        goto L_0x00484d90;
    }
    // 00484d8a  834e0c20               +or dword ptr [esi + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(32 /*0x20*/))));
    // 00484d8e  eb0e                   -jmp 0x484d9e
    goto L_0x00484d9e;
L_0x00484d90:
    // 00484d90  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484d92  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00484d97  eb0a                   -jmp 0x484da3
    goto L_0x00484da3;
L_0x00484d99:
    // 00484d99  0c20                   -or al, 0x20
    cpu.al |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00484d9b  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00484d9e:
    // 00484d9e  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
L_0x00484da3:
    // 00484da3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484da4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484da5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484da6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484da7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484da7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484da8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00484daa  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00484dac  68e0874800             -push 0x4887e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4753376 /*0x4887e0*/;
    cpu.esp -= 4;
    // 00484db1  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 00484db6  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00484dbc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484dbd  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00484dc4  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00484dc7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484dc8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484dc9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484dca  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00484dcd  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484dcf  393d54ee5100           +cmp dword ptr [0x51ee54], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5369428) /* 0x51ee54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484dd5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484dd7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484dd8  751b                   -jne 0x484df5
    if (!cpu.flags.zf)
    {
        goto L_0x00484df5;
    }
    // 00484dda  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484ddb  b8487e4800             -mov eax, 0x487e48
    cpu.eax = 4750920 /*0x487e48*/;
    // 00484de0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484de1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484de2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484de3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484de4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484de5  ff151c714800           -call dword ptr [0x48711c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747548) /* 0x48711c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484deb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484ded  7467                   -je 0x484e56
    if (cpu.flags.zf)
    {
        goto L_0x00484e56;
    }
    // 00484def  893554ee5100           -mov dword ptr [0x51ee54], esi
    app->getMemory<x86::reg32>(x86::reg32(5369428) /* 0x51ee54 */) = cpu.esi;
L_0x00484df5:
    // 00484df5  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00484df8  3bdf                   +cmp ebx, edi
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
    // 00484dfa  7e10                   -jle 0x484e0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484e0c;
    }
    // 00484dfc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484dfd  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00484e00  e8fc070000             -call 0x485601
    cpu.esp -= 4;
    sub_485601(app, cpu);
    // 00484e05  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e07  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00484e09  895d14                 -mov dword ptr [ebp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
L_0x00484e0c:
    // 00484e0c  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 00484e0f  7e10                   -jle 0x484e21
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484e21;
    }
    // 00484e11  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00484e14  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00484e17  e8e5070000             -call 0x485601
    cpu.esp -= 4;
    sub_485601(app, cpu);
    // 00484e1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e1e  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00484e21:
    // 00484e21  3bdf                   +cmp ebx, edi
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
    // 00484e23  0f846b010000           -je 0x484f94
    if (cpu.flags.zf)
    {
        return sub_484f94(app, cpu);
    }
    // 00484e29  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 00484e2c  0f8462010000           -je 0x484f94
    if (cpu.flags.zf)
    {
        return sub_484f94(app, cpu);
    }
    // 00484e32  a154ee5100             -mov eax, dword ptr [0x51ee54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369428) /* 0x51ee54 */);
    // 00484e37  3bc6                   +cmp eax, esi
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
    // 00484e39  7546                   -jne 0x484e81
    if (!cpu.flags.zf)
    {
        goto L_0x00484e81;
    }
    // 00484e3b  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00484e3e  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00484e41  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484e42  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00484e45  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00484e48  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00484e4b  ff151c714800           -call dword ptr [0x48711c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747548) /* 0x48711c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484e51  e95a010000             -jmp 0x484fb0
    return sub_484fb0(app, cpu);
L_0x00484e56:
    // 00484e56  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484e57  b8447e4800             -mov eax, 0x487e44
    cpu.eax = 4750916 /*0x487e44*/;
    // 00484e5c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484e5d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484e5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484e5f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e60  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e61  ff1520714800           -call dword ptr [0x487120]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747552) /* 0x487120 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484e67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484e69  740f                   -je 0x484e7a
    if (cpu.flags.zf)
    {
        goto L_0x00484e7a;
    }
    // 00484e6b  c70554ee510002000000   -mov dword ptr [0x51ee54], 2
    app->getMemory<x86::reg32>(x86::reg32(5369428) /* 0x51ee54 */) = 2 /*0x2*/;
    // 00484e75  e97bffffff             -jmp 0x484df5
    goto L_0x00484df5;
L_0x00484e7a:
    // 00484e7a  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00484e7c  e92f010000             -jmp 0x484fb0
    return sub_484fb0(app, cpu);
L_0x00484e81:
    // 00484e81  83f802                 +cmp eax, 2
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
    // 00484e84  75f4                   -jne 0x484e7a
    if (!cpu.flags.zf)
    {
        goto L_0x00484e7a;
    }
    // 00484e86  397d20                 +cmp dword ptr [ebp + 0x20], edi
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
    // 00484e89  7508                   -jne 0x484e93
    if (!cpu.flags.zf)
    {
        goto L_0x00484e93;
    }
    // 00484e8b  a1d4eb5100             -mov eax, dword ptr [0x51ebd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    // 00484e90  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x00484e93:
    // 00484e93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e95  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e97  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484e98  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00484e9b  be20020000             -mov esi, 0x220
    cpu.esi = 544 /*0x220*/;
    // 00484ea0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484ea1  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00484ea4  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484eaa  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00484ead  3bc7                   +cmp eax, edi
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
    // 00484eaf  74c9                   -je 0x484e7a
    if (cpu.flags.zf)
    {
        goto L_0x00484e7a;
    }
    // 00484eb1  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00484eb4  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00484eb7  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00484eb9  e8722effff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 00484ebe  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00484ec1  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00484ec3  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00484ec6  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00484eca  eb15                   -jmp 0x484ee1
    return sub_484ee1(app, cpu);
}

/* align: skip  */
void Application::sub_484e7a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00484e7a;
    // 00484da7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484da8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00484daa  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00484dac  68e0874800             -push 0x4887e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4753376 /*0x4887e0*/;
    cpu.esp -= 4;
    // 00484db1  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 00484db6  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 00484dbc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484dbd  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00484dc4  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00484dc7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484dc8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484dc9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484dca  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00484dcd  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484dcf  393d54ee5100           +cmp dword ptr [0x51ee54], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5369428) /* 0x51ee54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484dd5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484dd7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484dd8  751b                   -jne 0x484df5
    if (!cpu.flags.zf)
    {
        goto L_0x00484df5;
    }
    // 00484dda  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484ddb  b8487e4800             -mov eax, 0x487e48
    cpu.eax = 4750920 /*0x487e48*/;
    // 00484de0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484de1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484de2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484de3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484de4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484de5  ff151c714800           -call dword ptr [0x48711c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747548) /* 0x48711c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484deb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484ded  7467                   -je 0x484e56
    if (cpu.flags.zf)
    {
        goto L_0x00484e56;
    }
    // 00484def  893554ee5100           -mov dword ptr [0x51ee54], esi
    app->getMemory<x86::reg32>(x86::reg32(5369428) /* 0x51ee54 */) = cpu.esi;
L_0x00484df5:
    // 00484df5  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00484df8  3bdf                   +cmp ebx, edi
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
    // 00484dfa  7e10                   -jle 0x484e0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484e0c;
    }
    // 00484dfc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484dfd  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00484e00  e8fc070000             -call 0x485601
    cpu.esp -= 4;
    sub_485601(app, cpu);
    // 00484e05  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e07  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00484e09  895d14                 -mov dword ptr [ebp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
L_0x00484e0c:
    // 00484e0c  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 00484e0f  7e10                   -jle 0x484e21
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484e21;
    }
    // 00484e11  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00484e14  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00484e17  e8e5070000             -call 0x485601
    cpu.esp -= 4;
    sub_485601(app, cpu);
    // 00484e1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e1e  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00484e21:
    // 00484e21  3bdf                   +cmp ebx, edi
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
    // 00484e23  0f846b010000           -je 0x484f94
    if (cpu.flags.zf)
    {
        return sub_484f94(app, cpu);
    }
    // 00484e29  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 00484e2c  0f8462010000           -je 0x484f94
    if (cpu.flags.zf)
    {
        return sub_484f94(app, cpu);
    }
    // 00484e32  a154ee5100             -mov eax, dword ptr [0x51ee54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369428) /* 0x51ee54 */);
    // 00484e37  3bc6                   +cmp eax, esi
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
    // 00484e39  7546                   -jne 0x484e81
    if (!cpu.flags.zf)
    {
        goto L_0x00484e81;
    }
    // 00484e3b  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00484e3e  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00484e41  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484e42  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00484e45  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00484e48  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00484e4b  ff151c714800           -call dword ptr [0x48711c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747548) /* 0x48711c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484e51  e95a010000             -jmp 0x484fb0
    return sub_484fb0(app, cpu);
L_0x00484e56:
    // 00484e56  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484e57  b8447e4800             -mov eax, 0x487e44
    cpu.eax = 4750916 /*0x487e44*/;
    // 00484e5c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484e5d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484e5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484e5f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e60  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e61  ff1520714800           -call dword ptr [0x487120]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747552) /* 0x487120 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484e67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484e69  740f                   -je 0x484e7a
    if (cpu.flags.zf)
    {
        goto L_0x00484e7a;
    }
    // 00484e6b  c70554ee510002000000   -mov dword ptr [0x51ee54], 2
    app->getMemory<x86::reg32>(x86::reg32(5369428) /* 0x51ee54 */) = 2 /*0x2*/;
    // 00484e75  e97bffffff             -jmp 0x484df5
    goto L_0x00484df5;
L_0x00484e7a:
L_entry_0x00484e7a:
    // 00484e7a  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00484e7c  e92f010000             -jmp 0x484fb0
    return sub_484fb0(app, cpu);
L_0x00484e81:
    // 00484e81  83f802                 +cmp eax, 2
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
    // 00484e84  75f4                   -jne 0x484e7a
    if (!cpu.flags.zf)
    {
        goto L_0x00484e7a;
    }
    // 00484e86  397d20                 +cmp dword ptr [ebp + 0x20], edi
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
    // 00484e89  7508                   -jne 0x484e93
    if (!cpu.flags.zf)
    {
        goto L_0x00484e93;
    }
    // 00484e8b  a1d4eb5100             -mov eax, dword ptr [0x51ebd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    // 00484e90  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x00484e93:
    // 00484e93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e95  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e97  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484e98  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00484e9b  be20020000             -mov esi, 0x220
    cpu.esi = 544 /*0x220*/;
    // 00484ea0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484ea1  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00484ea4  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484eaa  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00484ead  3bc7                   +cmp eax, edi
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
    // 00484eaf  74c9                   -je 0x484e7a
    if (cpu.flags.zf)
    {
        goto L_0x00484e7a;
    }
    // 00484eb1  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00484eb4  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00484eb7  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00484eb9  e8722effff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 00484ebe  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00484ec1  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00484ec3  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00484ec6  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00484eca  eb15                   -jmp 0x484ee1
    return sub_484ee1(app, cpu);
}

/* align: skip  */
void Application::sub_484ecc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484ecc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484ece  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ecf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484ed0  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00484ed3  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484ed5  897de0                 -mov dword ptr [ebp - 0x20], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
    // 00484ed8  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00484edc  be20020000             -mov esi, 0x220
    cpu.esi = 544 /*0x220*/;
    // 00484ee1  397de0                 +cmp dword ptr [ebp - 0x20], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484ee4  7494                   -je 0x484e7a
    if (cpu.flags.zf)
    {
        return sub_484e7a(app, cpu);
    }
    // 00484ee6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484ee7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484ee8  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 00484eeb  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00484eee  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00484ef1  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00484ef4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484ef5  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00484ef8  8b1da8714800           -mov ebx, dword ptr [0x4871a8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    // 00484efe  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484f00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484f02  0f8472ffffff           -je 0x484e7a
    if (cpu.flags.zf)
    {
        return sub_484e7a(app, cpu);
    }
    // 00484f08  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f09  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f0b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f0c  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00484f0f  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00484f12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484f13  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00484f16  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484f18  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 00484f1b  3bc7                   +cmp eax, edi
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
    // 00484f1d  0f8457ffffff           -je 0x484e7a
    if (cpu.flags.zf)
    {
        return sub_484e7a(app, cpu);
    }
    // 00484f23  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00484f2a  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00484f2d  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00484f2f  e8fc2dffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 00484f34  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00484f37  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00484f39  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 00484f3c  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00484f40  eb14                   -jmp 0x484f56
    return sub_484f56(app, cpu);
}

/* align: skip  */
void Application::sub_484ee1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00484ee1;
    // 00484ed0  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00484ed3  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484ed5  897de0                 -mov dword ptr [ebp - 0x20], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
    // 00484ed8  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00484edc  be20020000             -mov esi, 0x220
    cpu.esi = 544 /*0x220*/;
L_entry_0x00484ee1:
    // 00484ee1  397de0                 +cmp dword ptr [ebp - 0x20], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484ee4  7494                   -je 0x484e7a
    if (cpu.flags.zf)
    {
        return sub_484e7a(app, cpu);
    }
    // 00484ee6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484ee7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484ee8  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 00484eeb  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00484eee  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00484ef1  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00484ef4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484ef5  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00484ef8  8b1da8714800           -mov ebx, dword ptr [0x4871a8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    // 00484efe  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484f00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484f02  0f8472ffffff           -je 0x484e7a
    if (cpu.flags.zf)
    {
        return sub_484e7a(app, cpu);
    }
    // 00484f08  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f09  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f0b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f0c  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00484f0f  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00484f12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484f13  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00484f16  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484f18  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 00484f1b  3bc7                   +cmp eax, edi
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
    // 00484f1d  0f8457ffffff           -je 0x484e7a
    if (cpu.flags.zf)
    {
        return sub_484e7a(app, cpu);
    }
    // 00484f23  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00484f2a  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00484f2d  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00484f2f  e8fc2dffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 00484f34  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00484f37  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00484f39  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 00484f3c  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00484f40  eb14                   -jmp 0x484f56
    return sub_484f56(app, cpu);
}

/* align: skip  */
void Application::sub_484f42(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484f42  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484f44  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484f46(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484f46  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00484f49  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484f4b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484f4d  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00484f51  be20020000             -mov esi, 0x220
    cpu.esi = 544 /*0x220*/;
    // 00484f56  3bdf                   +cmp ebx, edi
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
    // 00484f58  0f841cffffff           -je 0x484e7a
    if (cpu.flags.zf)
    {
        return sub_484e7a(app, cpu);
    }
    // 00484f5e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f5f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f60  ff75d8                 -push dword ptr [ebp - 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    cpu.esp -= 4;
    // 00484f63  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484f64  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00484f67  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00484f6a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484f6b  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00484f6e  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484f74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484f76  0f84fefeffff           -je 0x484e7a
    if (cpu.flags.zf)
    {
        return sub_484e7a(app, cpu);
    }
    // 00484f7c  ff75d8                 -push dword ptr [ebp - 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    cpu.esp -= 4;
    // 00484f7f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484f80  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 00484f83  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00484f86  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00484f89  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00484f8c  ff1520714800           -call dword ptr [0x487120]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747552) /* 0x487120 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484f92  eb1c                   -jmp 0x484fb0
    return sub_484fb0(app, cpu);
}

/* align: skip  */
void Application::sub_484f56(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00484f56;
    // 00484f46  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00484f49  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484f4b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484f4d  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00484f51  be20020000             -mov esi, 0x220
    cpu.esi = 544 /*0x220*/;
L_entry_0x00484f56:
    // 00484f56  3bdf                   +cmp ebx, edi
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
    // 00484f58  0f841cffffff           -je 0x484e7a
    if (cpu.flags.zf)
    {
        return sub_484e7a(app, cpu);
    }
    // 00484f5e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f5f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f60  ff75d8                 -push dword ptr [ebp - 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    cpu.esp -= 4;
    // 00484f63  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484f64  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00484f67  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00484f6a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484f6b  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00484f6e  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484f74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484f76  0f84fefeffff           -je 0x484e7a
    if (cpu.flags.zf)
    {
        return sub_484e7a(app, cpu);
    }
    // 00484f7c  ff75d8                 -push dword ptr [ebp - 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    cpu.esp -= 4;
    // 00484f7f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484f80  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 00484f83  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00484f86  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00484f89  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00484f8c  ff1520714800           -call dword ptr [0x487120]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747552) /* 0x487120 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00484f92  eb1c                   -jmp 0x484fb0
    return sub_484fb0(app, cpu);
}

/* align: skip  */
void Application::sub_484f94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484f94  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484f96  2b451c                 +sub eax, dword ptr [ebp + 0x1c]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00484f99  7505                   -jne 0x484fa0
    if (!cpu.flags.zf)
    {
        goto L_0x00484fa0;
    }
    // 00484f9b  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00484f9d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f9e  eb10                   -jmp 0x484fb0
    goto L_0x00484fb0;
L_0x00484fa0:
    // 00484fa0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484fa2  3bc7                   +cmp eax, edi
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
    // 00484fa4  0f9dc1                 -setge cl
    cpu.cl = (cpu.flags.sf == cpu.flags.of);
    // 00484fa7  49                     -dec ecx
    (cpu.ecx)--;
    // 00484fa8  83e1fe                 -and ecx, 0xfffffffe
    cpu.ecx &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/));
    // 00484fab  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00484fae  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00484fb0:
    // 00484fb0  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00484fb3  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484fb6  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00484fbd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484fbe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484fbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484fc0  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484fc1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00484fb0;
    // 00484f94  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484f96  2b451c                 +sub eax, dword ptr [ebp + 0x1c]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00484f99  7505                   -jne 0x484fa0
    if (!cpu.flags.zf)
    {
        goto L_0x00484fa0;
    }
    // 00484f9b  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00484f9d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f9e  eb10                   -jmp 0x484fb0
    goto L_0x00484fb0;
L_0x00484fa0:
    // 00484fa0  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484fa2  3bc7                   +cmp eax, edi
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
    // 00484fa4  0f9dc1                 -setge cl
    cpu.cl = (cpu.flags.sf == cpu.flags.of);
    // 00484fa7  49                     -dec ecx
    (cpu.ecx)--;
    // 00484fa8  83e1fe                 -and ecx, 0xfffffffe
    cpu.ecx &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/));
    // 00484fab  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00484fae  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00484fb0:
L_entry_0x00484fb0:
    // 00484fb0  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00484fb3  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00484fb6  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00484fbd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484fbe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484fbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484fc0  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484fc1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484fc2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484fc2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484fc3  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00484fc5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484fc6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484fc7  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00484fc9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484fcb  397510                 +cmp dword ptr [ebp + 0x10], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484fce  0f84e3000000           -je 0x4850b7
    if (cpu.flags.zf)
    {
        goto L_0x004850b7;
    }
    // 00484fd4  3935c4eb5100           +cmp dword ptr [0x51ebc4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484fda  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484fdb  7551                   -jne 0x48502e
    if (!cpu.flags.zf)
    {
        goto L_0x0048502e;
    }
    // 00484fdd  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00484fe0  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x00484fe3:
    // 00484fe3  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00484fe6  663d5a00               +cmp ax, 0x5a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(90 /*0x5a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00484fea  7709                   -ja 0x484ff5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00484ff5;
    }
    // 00484fec  663d4100               +cmp ax, 0x41
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65 /*0x41*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00484ff0  7203                   -jb 0x484ff5
    if (cpu.flags.cf)
    {
        goto L_0x00484ff5;
    }
    // 00484ff2  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00484ff5:
    // 00484ff5  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00484ff8  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 00484ffb  663d5a00               +cmp ax, 0x5a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(90 /*0x5a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00484fff  7709                   -ja 0x48500a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048500a;
    }
    // 00485001  663d4100               +cmp ax, 0x41
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65 /*0x41*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00485005  7203                   -jb 0x48500a
    if (cpu.flags.cf)
    {
        goto L_0x0048500a;
    }
    // 00485007  83c020                 +add eax, 0x20
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0048500a:
    // 0048500a  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048500b  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048500e  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048500f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485010  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485011  ff4d10                 +dec dword ptr [ebp + 0x10]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00485014  0f8492000000           -je 0x4850ac
    if (cpu.flags.zf)
    {
        goto L_0x004850ac;
    }
    // 0048501a  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048501d  663bc6                 +cmp ax, si
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.si));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00485020  0f8486000000           -je 0x4850ac
    if (cpu.flags.zf)
    {
        goto L_0x004850ac;
    }
    // 00485026  663b4508               +cmp ax, word ptr [ebp + 8]
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0048502a  74b7                   -je 0x484fe3
    if (cpu.flags.zf)
    {
        goto L_0x00484fe3;
    }
    // 0048502c  eb7e                   -jmp 0x4850ac
    goto L_0x004850ac;
L_0x0048502e:
    // 0048502e  bbe81f5200             -mov ebx, 0x521fe8
    cpu.ebx = 5382120 /*0x521fe8*/;
    // 00485033  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485034  ff15ac714800           -call dword ptr [0x4871ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747692) /* 0x4871ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048503a  3935e41f5200           +cmp dword ptr [0x521fe4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382116) /* 0x521fe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485040  7418                   -je 0x48505a
    if (cpu.flags.zf)
    {
        goto L_0x0048505a;
    }
    // 00485042  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485043  ff158c714800           -call dword ptr [0x48718c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747660) /* 0x48718c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00485049  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 0048504b  e8797affff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00485050  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485051  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00485058  eb03                   -jmp 0x48505d
    goto L_0x0048505d;
L_0x0048505a:
    // 0048505a  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
L_0x0048505d:
    // 0048505d  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485060  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485061  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x00485064:
    // 00485064  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00485067  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485068  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485069  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048506a  e814030000             -call 0x485383
    cpu.esp -= 4;
    sub_485383(app, cpu);
    // 0048506f  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00485072  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 00485075  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485076  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485077  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485078  e806030000             -call 0x485383
    cpu.esp -= 4;
    sub_485383(app, cpu);
    // 0048507d  ff4d10                 +dec dword ptr [ebp + 0x10]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00485080  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485081  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485082  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00485085  740d                   -je 0x485094
    if (cpu.flags.zf)
    {
        goto L_0x00485094;
    }
    // 00485087  66837d0c00             +cmp word ptr [ebp + 0xc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0048508c  7406                   -je 0x485094
    if (cpu.flags.zf)
    {
        goto L_0x00485094;
    }
    // 0048508e  6639450c               +cmp word ptr [ebp + 0xc], ax
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.ax));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00485092  74d0                   -je 0x485064
    if (cpu.flags.zf)
    {
        goto L_0x00485064;
    }
L_0x00485094:
    // 00485094  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 00485098  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485099  740a                   -je 0x4850a5
    if (cpu.flags.zf)
    {
        goto L_0x004850a5;
    }
    // 0048509b  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 0048509d  e8887affff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 004850a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850a3  eb07                   -jmp 0x4850ac
    goto L_0x004850ac;
L_0x004850a5:
    // 004850a5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004850a6  ff158c714800           -call dword ptr [0x48718c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747660) /* 0x48718c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004850ac:
    // 004850ac  0fb74d08               -movzx ecx, word ptr [ebp + 8]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004850b0  0fb7450c               -movzx eax, word ptr [ebp + 0xc]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004850b4  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004850b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004850b7:
    // 004850b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850b8  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::_strrchr(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004850c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004850c1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004850c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004850c4  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004850c7  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004850c9  83c9ff                 +or ecx, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 004850cc  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004850ce  41                     -inc ecx
    (cpu.ecx)++;
    // 004850cf  f7d9                   +neg ecx
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
    // 004850d1  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004850d2  8a450c                 -mov al, byte ptr [ebp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004850d5  fd                     -std 
    cpu.flags.df = 1;
    // 004850d6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004850d8  47                     -inc edi
    (cpu.edi)++;
    // 004850d9  3807                   +cmp byte ptr [edi], al
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
    // 004850db  7404                   -je 0x4850e1
    if (cpu.flags.zf)
    {
        goto L_0x004850e1;
    }
    // 004850dd  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004850df  eb02                   -jmp 0x4850e3
    goto L_0x004850e3;
L_0x004850e1:
    // 004850e1  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004850e3:
    // 004850e3  fc                     -cld 
    cpu.flags.df = 0;
    // 004850e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850e5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4850e7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004850e7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004850e8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004850ea  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004850ed  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004850ee  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004850f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004850f2  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004850f5  668b4b0a               -mov cx, word ptr [ebx + 0xa]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 004850f9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004850fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004850fc  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004850ff  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00485102  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00485105  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00485108  668b460a               -mov ax, word ptr [esi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0048510c  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048510e  baff7f0000             -mov edx, 0x7fff
    cpu.edx = 32767 /*0x7fff*/;
    // 00485113  33f8                   -xor edi, eax
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485115  23c2                   -and eax, edx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edx));
    // 00485117  23ca                   -and ecx, edx
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.edx));
    // 00485119  81e700800000           -and edi, 0x8000
    cpu.edi &= x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048511f  663dff7f               +cmp ax, 0x7fff
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
    // 00485123  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00485126  895508                 -mov dword ptr [ebp + 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00485129  0f83b8010000           -jae 0x4852e7
    if (!cpu.flags.cf)
    {
        goto L_0x004852e7;
    }
    // 0048512f  6681f9ff7f             +cmp cx, 0x7fff
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
    // 00485134  0f83ad010000           -jae 0x4852e7
    if (!cpu.flags.cf)
    {
        goto L_0x004852e7;
    }
    // 0048513a  6681fafdbf             +cmp dx, 0xbffd
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
    // 0048513f  0f87a2010000           -ja 0x4852e7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004852e7;
    }
    // 00485145  6681fabf3f             +cmp dx, 0x3fbf
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
    // 0048514a  7704                   -ja 0x485150
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00485150;
    }
    // 0048514c  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048514e  eb3a                   -jmp 0x48518a
    goto L_0x0048518a;
L_0x00485150:
    // 00485150  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00485153  baffffff7f             -mov edx, 0x7fffffff
    cpu.edx = 2147483647 /*0x7fffffff*/;
    // 00485158  7518                   -jne 0x485172
    if (!cpu.flags.zf)
    {
        goto L_0x00485172;
    }
    // 0048515a  ff4508                 +inc dword ptr [ebp + 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048515d  855608                 -test dword ptr [esi + 8], edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) & cpu.edx));
    // 00485160  7510                   -jne 0x485172
    if (!cpu.flags.zf)
    {
        goto L_0x00485172;
    }
    // 00485162  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485164  394604                 +cmp dword ptr [esi + 4], eax
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
    // 00485167  750b                   -jne 0x485174
    if (!cpu.flags.zf)
    {
        goto L_0x00485174;
    }
    // 00485169  3906                   +cmp dword ptr [esi], eax
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
    // 0048516b  7507                   -jne 0x485174
    if (!cpu.flags.zf)
    {
        goto L_0x00485174;
    }
    // 0048516d  e96f010000             -jmp 0x4852e1
    goto L_0x004852e1;
L_0x00485172:
    // 00485172  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00485174:
    // 00485174  663bc8                 +cmp cx, ax
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
    // 00485177  751e                   -jne 0x485197
    if (!cpu.flags.zf)
    {
        goto L_0x00485197;
    }
    // 00485179  ff4508                 +inc dword ptr [ebp + 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048517c  855308                 -test dword ptr [ebx + 8], edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) & cpu.edx));
    // 0048517f  7516                   -jne 0x485197
    if (!cpu.flags.zf)
    {
        goto L_0x00485197;
    }
    // 00485181  394304                 +cmp dword ptr [ebx + 4], eax
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
    // 00485184  7511                   -jne 0x485197
    if (!cpu.flags.zf)
    {
        goto L_0x00485197;
    }
    // 00485186  3903                   +cmp dword ptr [ebx], eax
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
    // 00485188  750d                   -jne 0x485197
    if (!cpu.flags.zf)
    {
        goto L_0x00485197;
    }
L_0x0048518a:
    // 0048518a  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048518d  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00485190  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00485192  e96b010000             -jmp 0x485302
    goto L_0x00485302;
L_0x00485197:
    // 00485197  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0048519a  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0048519d  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004851a0  c7450c05000000         -mov dword ptr [ebp + 0xc], 5
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 5 /*0x5*/;
L_0x004851a7:
    // 004851a7  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004851aa  03c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004851ac  837d0c00               +cmp dword ptr [ebp + 0xc], 0
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
    // 004851b0  7e49                   -jle 0x4851fb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004851fb;
    }
    // 004851b2  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004851b4  8d4b08                 -lea ecx, [ebx + 8]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004851b7  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004851ba  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004851bd  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004851c0  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004851c3:
    // 004851c3  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004851c6  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004851c9  0fb700                 -movzx eax, word ptr [eax]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.eax));
    // 004851cc  0fb709                 -movzx ecx, word ptr [ecx]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(cpu.ecx));
    // 004851cf  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004851d2  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004851d5  83c1fc                 -add ecx, -4
    (cpu.ecx) += x86::reg32(x86::sreg32(-4 /*-0x4*/));
    // 004851d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004851d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004851da  ff31                   -push dword ptr [ecx]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    // 004851dc  e89bf2ffff             -call 0x48447c
    cpu.esp -= 4;
    sub_48447c(app, cpu);
    // 004851e1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004851e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004851e6  7406                   -je 0x4851ee
    if (cpu.flags.zf)
    {
        goto L_0x004851ee;
    }
    // 004851e8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004851eb  66ff00                 -inc word ptr [eax]
    (app->getMemory<x86::reg16>(cpu.eax))++;
L_0x004851ee:
    // 004851ee  8345f802               -add dword ptr [ebp - 8], 2
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004851f2  836df402               +sub dword ptr [ebp - 0xc], 2
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
    // 004851f6  ff4de8                 +dec dword ptr [ebp - 0x18]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004851f9  75c8                   -jne 0x4851c3
    if (!cpu.flags.zf)
    {
        goto L_0x004851c3;
    }
L_0x004851fb:
    // 004851fb  8345fc02               -add dword ptr [ebp - 4], 2
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004851ff  ff45f0                 -inc dword ptr [ebp - 0x10]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))++;
    // 00485202  ff4d0c                 -dec dword ptr [ebp + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))--;
    // 00485205  837d0c00               +cmp dword ptr [ebp + 0xc], 0
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
    // 00485209  7f9c                   -jg 0x4851a7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004851a7;
    }
    // 0048520b  81450802c00000         -add dword ptr [ebp + 8], 0xc002
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(49154 /*0xc002*/));
    // 00485212  66837d0800             +cmp word ptr [ebp + 8], 0
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
    // 00485217  7e25                   -jle 0x48523e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048523e;
    }
L_0x00485219:
    // 00485219  f645e780               +test byte ptr [ebp - 0x19], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-25) /* -0x19 */) & 128 /*0x80*/));
    // 0048521d  7518                   -jne 0x485237
    if (!cpu.flags.zf)
    {
        goto L_0x00485237;
    }
    // 0048521f  8d45dc                 -lea eax, [ebp - 0x24]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00485222  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485223  e8d3f2ffff             -call 0x4844fb
    cpu.esp -= 4;
    sub_4844fb(app, cpu);
    // 00485228  814508ffff0000         -add dword ptr [ebp + 8], 0xffff
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048522f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485230  66837d0800             +cmp word ptr [ebp + 8], 0
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
    // 00485235  7fe2                   -jg 0x485219
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00485219;
    }
L_0x00485237:
    // 00485237  66837d0800             +cmp word ptr [ebp + 8], 0
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
    // 0048523c  7f39                   -jg 0x485277
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00485277;
    }
L_0x0048523e:
    // 0048523e  814508ffff0000         -add dword ptr [ebp + 8], 0xffff
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00485245  66837d0800             +cmp word ptr [ebp + 8], 0
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
    // 0048524a  7d2b                   -jge 0x485277
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00485277;
    }
    // 0048524c  0fbf4508               -movsx eax, word ptr [ebp + 8]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00485250  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00485252  014508                 -add dword ptr [ebp + 8], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00485255  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00485257:
    // 00485257  f645dc01               +test byte ptr [ebp - 0x24], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-36) /* -0x24 */) & 1 /*0x1*/));
    // 0048525b  7403                   -je 0x485260
    if (cpu.flags.zf)
    {
        goto L_0x00485260;
    }
    // 0048525d  ff45ec                 +inc dword ptr [ebp - 0x14]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x00485260:
    // 00485260  8d45dc                 -lea eax, [ebp - 0x24]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00485263  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485264  e8c0f2ffff             -call 0x484529
    cpu.esp -= 4;
    sub_484529(app, cpu);
    // 00485269  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048526a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048526b  75ea                   -jne 0x485257
    if (!cpu.flags.zf)
    {
        goto L_0x00485257;
    }
    // 0048526d  837dec00               +cmp dword ptr [ebp - 0x14], 0
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
    // 00485271  7404                   -je 0x485277
    if (cpu.flags.zf)
    {
        goto L_0x00485277;
    }
    // 00485273  804ddc01               -or byte ptr [ebp - 0x24], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-36) /* -0x24 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00485277:
    // 00485277  66817ddc0080           +cmp word ptr [ebp - 0x24], 0x8000
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
    // 0048527d  770f                   -ja 0x48528e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048528e;
    }
    // 0048527f  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00485282  25ffff0100             -and eax, 0x1ffff
    cpu.eax &= x86::reg32(x86::sreg32(131071 /*0x1ffff*/));
    // 00485287  3d00800100             +cmp eax, 0x18000
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
    // 0048528c  7535                   -jne 0x4852c3
    if (!cpu.flags.zf)
    {
        goto L_0x004852c3;
    }
L_0x0048528e:
    // 0048528e  837ddeff               +cmp dword ptr [ebp - 0x22], -1
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
    // 00485292  752c                   -jne 0x4852c0
    if (!cpu.flags.zf)
    {
        goto L_0x004852c0;
    }
    // 00485294  8365de00               -and dword ptr [ebp - 0x22], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-34) /* -0x22 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00485298  837de2ff               +cmp dword ptr [ebp - 0x1e], -1
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
    // 0048529c  751d                   -jne 0x4852bb
    if (!cpu.flags.zf)
    {
        goto L_0x004852bb;
    }
    // 0048529e  8365e200               -and dword ptr [ebp - 0x1e], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-30) /* -0x1e */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004852a2  66817de6ffff           +cmp word ptr [ebp - 0x1a], 0xffff
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
    // 004852a8  750b                   -jne 0x4852b5
    if (!cpu.flags.zf)
    {
        goto L_0x004852b5;
    }
    // 004852aa  ff4508                 +inc dword ptr [ebp + 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004852ad  66c745e60080           -mov word ptr [ebp - 0x1a], 0x8000
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */) = 32768 /*0x8000*/;
    // 004852b3  eb0e                   -jmp 0x4852c3
    goto L_0x004852c3;
L_0x004852b5:
    // 004852b5  66ff45e6               +inc word ptr [ebp - 0x1a]
    {
        auto tmp = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */);
        cpu.flags.of = ~(1 & (tmp >> 15));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 15);
        cpu.set_szp(tmp);
    }
    // 004852b9  eb08                   -jmp 0x4852c3
    goto L_0x004852c3;
L_0x004852bb:
    // 004852bb  ff45e2                 +inc dword ptr [ebp - 0x1e]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-30) /* -0x1e */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004852be  eb03                   -jmp 0x4852c3
    goto L_0x004852c3;
L_0x004852c0:
    // 004852c0  ff45de                 -inc dword ptr [ebp - 0x22]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-34) /* -0x22 */))++;
L_0x004852c3:
    // 004852c3  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004852c6  663dff7f               +cmp ax, 0x7fff
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
    // 004852ca  731b                   -jae 0x4852e7
    if (!cpu.flags.cf)
    {
        goto L_0x004852e7;
    }
    // 004852cc  668b4dde               -mov cx, word ptr [ebp - 0x22]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-34) /* -0x22 */);
    // 004852d0  0bc7                   +or eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edi))));
    // 004852d2  66890e                 -mov word ptr [esi], cx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.cx;
    // 004852d5  8b4de0                 -mov ecx, dword ptr [ebp - 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004852d8  894e02                 -mov dword ptr [esi + 2], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.ecx;
    // 004852db  8b4de4                 -mov ecx, dword ptr [ebp - 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004852de  894e06                 -mov dword ptr [esi + 6], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ecx;
L_0x004852e1:
    // 004852e1  6689460a               -mov word ptr [esi + 0xa], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 004852e5  eb1b                   -jmp 0x485302
    goto L_0x00485302;
L_0x004852e7:
    // 004852e7  66f7df                 +neg di
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
    // 004852ea  1bff                   -sbb edi, edi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edi) + cpu.flags.cf);
    // 004852ec  83660400               -and dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004852f0  81e700000080           -and edi, 0x80000000
    cpu.edi &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 004852f6  81c70080ff7f           -add edi, 0x7fff8000
    (cpu.edi) += x86::reg32(x86::sreg32(2147450880 /*0x7fff8000*/));
    // 004852fc  832600                 -and dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004852ff  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
L_0x00485302:
    // 00485302  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485303  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485304  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485305  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485306  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485307(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485307  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485308  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048530a  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048530d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048530e  bb206c4a00             -mov ebx, 0x4a6c20
    cpu.ebx = 4877344 /*0x4a6c20*/;
    // 00485313  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485315  83eb60                 -sub ebx, 0x60
    (cpu.ebx) -= x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00485318  394d0c                 +cmp dword ptr [ebp + 0xc], ecx
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
    // 0048531b  7463                   -je 0x485380
    if (cpu.flags.zf)
    {
        goto L_0x00485380;
    }
    // 0048531d  7d10                   -jge 0x48532f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048532f;
    }
    // 0048531f  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00485322  bb806d4a00             -mov ebx, 0x4a6d80
    cpu.ebx = 4877696 /*0x4a6d80*/;
    // 00485327  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00485329  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048532c  83eb60                 -sub ebx, 0x60
    (cpu.ebx) -= x86::reg32(x86::sreg32(96 /*0x60*/));
L_0x0048532f:
    // 0048532f  394d10                 +cmp dword ptr [ebp + 0x10], ecx
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
    // 00485332  7506                   -jne 0x48533a
    if (!cpu.flags.zf)
    {
        goto L_0x0048533a;
    }
    // 00485334  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485337  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
L_0x0048533a:
    // 0048533a  394d0c                 +cmp dword ptr [ebp + 0xc], ecx
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
    // 0048533d  7441                   -je 0x485380
    if (cpu.flags.zf)
    {
        goto L_0x00485380;
    }
    // 0048533f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485340  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00485341:
    // 00485341  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00485344  83c354                 -add ebx, 0x54
    (cpu.ebx) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00485347  c17d0c03               -sar dword ptr [ebp + 0xc], 3
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)) >> (3 /*0x3*/ % 32));
    // 0048534b  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0048534e  3bc1                   +cmp eax, ecx
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
    // 00485350  7427                   -je 0x485379
    if (cpu.flags.zf)
    {
        goto L_0x00485379;
    }
    // 00485352  8d0440                 -lea eax, [eax + eax*2]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 2);
    // 00485355  66813c830080           +cmp word ptr [ebx + eax*4], 0x8000
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
    // 0048535b  8d3483                 -lea esi, [ebx + eax*4]
    cpu.esi = x86::reg32(cpu.ebx + cpu.eax * 4);
    // 0048535e  720c                   -jb 0x48536c
    if (cpu.flags.cf)
    {
        goto L_0x0048536c;
    }
    // 00485360  8d7df4                 -lea edi, [ebp - 0xc]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00485363  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485364  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485365  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485366  ff4df6                 -dec dword ptr [ebp - 0xa]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */))--;
    // 00485369  8d75f4                 -lea esi, [ebp - 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
L_0x0048536c:
    // 0048536c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048536d  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00485370  e872fdffff             -call 0x4850e7
    cpu.esp -= 4;
    sub_4850e7(app, cpu);
    // 00485375  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485376  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485377  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00485379:
    // 00485379  394d0c                 +cmp dword ptr [ebp + 0xc], ecx
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
    // 0048537c  75c3                   -jne 0x485341
    if (!cpu.flags.zf)
    {
        goto L_0x00485341;
    }
    // 0048537e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048537f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00485380:
    // 00485380  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485381  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485382  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485383(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485383  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485384  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00485386  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485387  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048538a  663dffff               +cmp ax, 0xffff
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
    // 0048538e  7505                   -jne 0x485395
    if (!cpu.flags.zf)
    {
        goto L_0x00485395;
    }
    // 00485390  660bc0                 -or ax, ax
    cpu.ax |= x86::reg16(x86::sreg16(cpu.ax));
    // 00485393  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485394  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485395:
    // 00485395  833dc4eb510000         +cmp dword ptr [0x51ebc4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048539c  7511                   -jne 0x4853af
    if (!cpu.flags.zf)
    {
        goto L_0x004853af;
    }
    // 0048539e  663d4100               +cmp ax, 0x41
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65 /*0x41*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004853a2  7252                   -jb 0x4853f6
    if (cpu.flags.cf)
    {
        goto L_0x004853f6;
    }
    // 004853a4  663d5a00               +cmp ax, 0x5a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(90 /*0x5a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004853a8  774c                   -ja 0x4853f6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004853f6;
    }
    // 004853aa  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004853ad  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004853af:
    // 004853af  663d0001               +cmp ax, 0x100
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(256 /*0x100*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004853b3  7314                   -jae 0x4853c9
    if (!cpu.flags.cf)
    {
        goto L_0x004853c9;
    }
    // 004853b5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004853b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004853b8  e874020000             -call 0x485631
    cpu.esp -= 4;
    sub_485631(app, cpu);
    // 004853bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004853c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853c1  7506                   -jne 0x4853c9
    if (!cpu.flags.zf)
    {
        goto L_0x004853c9;
    }
    // 004853c3  668b4508               -mov ax, word ptr [ebp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004853c7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004853c9:
    // 004853c9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004853cb  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 004853ce  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004853d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004853d1  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004853d4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004853d6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004853d7  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004853dc  ff35c4eb5100           -push dword ptr [0x51ebc4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
    cpu.esp -= 4;
    // 004853e2  e811000000             -call 0x4853f8
    cpu.esp -= 4;
    sub_4853f8(app, cpu);
    // 004853e7  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004853ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004853ec  668b4508               -mov ax, word ptr [ebp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004853f0  7404                   -je 0x4853f6
    if (cpu.flags.zf)
    {
        goto L_0x004853f6;
    }
    // 004853f2  668b45fe               -mov ax, word ptr [ebp - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */);
L_0x004853f6:
    // 004853f6  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4853f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004853f8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004853f9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004853fb  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004853fd  68f8874800             -push 0x4887f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4753400 /*0x4887f8*/;
    cpu.esp -= 4;
    // 00485402  68509c4700             -push 0x479c50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4693072 /*0x479c50*/;
    cpu.esp -= 4;
    // 00485407  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 0048540d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048540e  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 00485415  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00485418  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485419  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048541a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048541b  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0048541e  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00485420  393560ee5100           +cmp dword ptr [0x51ee60], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5369440) /* 0x51ee60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485426  7546                   -jne 0x48546e
    if (!cpu.flags.zf)
    {
        goto L_0x0048546e;
    }
    // 00485428  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485429  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048542a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048542c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048542d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048542e  68487e4800             -push 0x487e48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750920 /*0x487e48*/;
    cpu.esp -= 4;
    // 00485433  bf00010000             -mov edi, 0x100
    cpu.edi = 256 /*0x100*/;
    // 00485438  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485439  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048543a  ff154c714800           -call dword ptr [0x48714c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747596) /* 0x48714c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00485440  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485442  7408                   -je 0x48544c
    if (cpu.flags.zf)
    {
        goto L_0x0048544c;
    }
    // 00485444  891d60ee5100           -mov dword ptr [0x51ee60], ebx
    app->getMemory<x86::reg32>(x86::reg32(5369440) /* 0x51ee60 */) = cpu.ebx;
    // 0048544a  eb22                   -jmp 0x48546e
    goto L_0x0048546e;
L_0x0048544c:
    // 0048544c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048544d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048544e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048544f  68447e4800             -push 0x487e44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750916 /*0x487e44*/;
    cpu.esp -= 4;
    // 00485454  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485455  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485456  ff1550714800           -call dword ptr [0x487150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747600) /* 0x487150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048545c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048545e  0f8489010000           -je 0x4855ed
    if (cpu.flags.zf)
    {
        return sub_4855ed(app, cpu);
    }
    // 00485464  c70560ee510002000000   -mov dword ptr [0x51ee60], 2
    app->getMemory<x86::reg32>(x86::reg32(5369440) /* 0x51ee60 */) = 2 /*0x2*/;
L_0x0048546e:
    // 0048546e  397514                 +cmp dword ptr [ebp + 0x14], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485471  7e10                   -jle 0x485483
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00485483;
    }
    // 00485473  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00485476  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00485479  e883010000             -call 0x485601
    cpu.esp -= 4;
    sub_485601(app, cpu);
    // 0048547e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048547f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485480  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x00485483:
    // 00485483  a160ee5100             -mov eax, dword ptr [0x51ee60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5369440) /* 0x51ee60 */);
    // 00485488  83f801                 +cmp eax, 1
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
    // 0048548b  751d                   -jne 0x4854aa
    if (!cpu.flags.zf)
    {
        goto L_0x004854aa;
    }
    // 0048548d  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00485490  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00485493  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00485496  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00485499  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0048549c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0048549f  ff154c714800           -call dword ptr [0x48714c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747596) /* 0x48714c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004854a5  e945010000             -jmp 0x4855ef
    return sub_4855ef(app, cpu);
L_0x004854aa:
    // 004854aa  83f802                 +cmp eax, 2
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
    // 004854ad  0f853a010000           -jne 0x4855ed
    if (!cpu.flags.zf)
    {
        return sub_4855ed(app, cpu);
    }
    // 004854b3  397520                 +cmp dword ptr [ebp + 0x20], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004854b6  7508                   -jne 0x4854c0
    if (!cpu.flags.zf)
    {
        goto L_0x004854c0;
    }
    // 004854b8  a1d4eb5100             -mov eax, dword ptr [0x51ebd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5368788) /* 0x51ebd4 */);
    // 004854bd  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x004854c0:
    // 004854c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004854c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004854c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004854c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004854c4  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004854c7  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004854ca  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 004854cf  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004854d2  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004854d8  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004854db  3bc6                   +cmp eax, esi
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
    // 004854dd  0f840a010000           -je 0x4855ed
    if (cpu.flags.zf)
    {
        return sub_4855ed(app, cpu);
    }
    // 004854e3  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004854e6  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004854e9  24fc                   +and al, 0xfc
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/))));
    // 004854eb  e84028ffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 004854f0  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 004854f3  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004854f5  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004854f8  eb0c                   -jmp 0x485506
    return sub_485506(app, cpu);
}

/* align: skip  */
void Application::sub_4854fa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004854fa  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004854fc  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4854fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004854fe  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00485501  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00485503  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 00485506  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0048550a  3975e4                 +cmp dword ptr [ebp - 0x1c], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048550d  0f84da000000           -je 0x4855ed
    if (cpu.flags.zf)
    {
        return sub_4855ed(app, cpu);
    }
    // 00485513  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485514  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485515  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00485518  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0048551b  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0048551e  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00485521  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 00485526  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00485529  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048552f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485531  0f84b6000000           -je 0x4855ed
    if (cpu.flags.zf)
    {
        return sub_4855ed(app, cpu);
    }
    // 00485537  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485538  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485539  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 0048553c  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0048553f  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00485542  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00485545  ff1550714800           -call dword ptr [0x487150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747600) /* 0x487150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048554b  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048554d  897dd4                 -mov dword ptr [ebp - 0x2c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.edi;
    // 00485550  3bfe                   +cmp edi, esi
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
    // 00485552  0f8495000000           -je 0x4855ed
    if (cpu.flags.zf)
    {
        return sub_4855ed(app, cpu);
    }
    // 00485558  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0048555f  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00485562  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00485564  e8c727ffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 00485569  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0048556c  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048556e  895ddc                 -mov dword ptr [ebp - 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ebx;
    // 00485571  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00485575  eb12                   -jmp 0x485589
    return sub_485589(app, cpu);
}

/* align: skip  */
void Application::sub_485506(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00485506;
    // 004854fe  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00485501  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00485503  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
L_entry_0x00485506:
    // 00485506  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0048550a  3975e4                 +cmp dword ptr [ebp - 0x1c], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048550d  0f84da000000           -je 0x4855ed
    if (cpu.flags.zf)
    {
        return sub_4855ed(app, cpu);
    }
    // 00485513  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485514  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485515  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00485518  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0048551b  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0048551e  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00485521  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 00485526  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00485529  ff15a8714800           -call dword ptr [0x4871a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747688) /* 0x4871a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048552f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485531  0f84b6000000           -je 0x4855ed
    if (cpu.flags.zf)
    {
        return sub_4855ed(app, cpu);
    }
    // 00485537  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485538  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485539  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 0048553c  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0048553f  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00485542  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00485545  ff1550714800           -call dword ptr [0x487150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747600) /* 0x487150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048554b  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048554d  897dd4                 -mov dword ptr [ebp - 0x2c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.edi;
    // 00485550  3bfe                   +cmp edi, esi
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
    // 00485552  0f8495000000           -je 0x4855ed
    if (cpu.flags.zf)
    {
        return sub_4855ed(app, cpu);
    }
    // 00485558  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 0048555f  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00485562  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00485564  e8c727ffff             -call 0x477d30
    cpu.esp -= 4;
    sub_477d30(app, cpu);
    // 00485569  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 0048556c  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048556e  895ddc                 -mov dword ptr [ebp - 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ebx;
    // 00485571  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00485575  eb12                   -jmp 0x485589
    return sub_485589(app, cpu);
}

/* align: skip  */
void Application::sub_485577(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485577  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00485579  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048557a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48557b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048557b  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0048557e  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00485580  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485582  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00485586  8b7dd4                 -mov edi, dword ptr [ebp - 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00485589  3bde                   +cmp ebx, esi
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
    // 0048558b  7460                   -je 0x4855ed
    if (cpu.flags.zf)
    {
        goto L_0x004855ed;
    }
    // 0048558d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048558e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048558f  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00485592  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 00485595  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00485598  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0048559b  ff1550714800           -call dword ptr [0x487150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747600) /* 0x487150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004855a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004855a3  7448                   -je 0x4855ed
    if (cpu.flags.zf)
    {
        goto L_0x004855ed;
    }
    // 004855a5  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004855a9  741c                   -je 0x4855c7
    if (cpu.flags.zf)
    {
        goto L_0x004855c7;
    }
    // 004855ab  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004855ae  3bc6                   +cmp eax, esi
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
    // 004855b0  7437                   -je 0x4855e9
    if (cpu.flags.zf)
    {
        goto L_0x004855e9;
    }
    // 004855b2  3bc7                   +cmp eax, edi
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
    // 004855b4  7c02                   -jl 0x4855b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004855b8;
    }
    // 004855b6  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004855b8:
    // 004855b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004855b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004855ba  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004855bd  e8fe27ffff             -call 0x477dc0
    cpu.esp -= 4;
    _strncpy(app, cpu);
    // 004855c2  83c40c                 +add esp, 0xc
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
    // 004855c5  eb22                   -jmp 0x4855e9
    goto L_0x004855e9;
L_0x004855c7:
    // 004855c7  39751c                 +cmp dword ptr [ebp + 0x1c], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004855ca  7504                   -jne 0x4855d0
    if (!cpu.flags.zf)
    {
        goto L_0x004855d0;
    }
    // 004855cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004855cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004855ce  eb06                   -jmp 0x4855d6
    goto L_0x004855d6;
L_0x004855d0:
    // 004855d0  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004855d3  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
L_0x004855d6:
    // 004855d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004855d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004855d8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004855da  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004855dd  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004855e3  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004855e5  3bfe                   +cmp edi, esi
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
    // 004855e7  7404                   -je 0x4855ed
    if (cpu.flags.zf)
    {
        goto L_0x004855ed;
    }
L_0x004855e9:
    // 004855e9  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004855eb  eb02                   -jmp 0x4855ef
    goto L_0x004855ef;
L_0x004855ed:
    // 004855ed  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004855ef:
    // 004855ef  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004855f2  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004855f5  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004855fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855ff  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485600  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4855ef(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004855ef;
    // 0048557b  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0048557e  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00485580  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485582  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00485586  8b7dd4                 -mov edi, dword ptr [ebp - 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00485589  3bde                   +cmp ebx, esi
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
    // 0048558b  7460                   -je 0x4855ed
    if (cpu.flags.zf)
    {
        goto L_0x004855ed;
    }
    // 0048558d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048558e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048558f  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00485592  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 00485595  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00485598  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0048559b  ff1550714800           -call dword ptr [0x487150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747600) /* 0x487150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004855a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004855a3  7448                   -je 0x4855ed
    if (cpu.flags.zf)
    {
        goto L_0x004855ed;
    }
    // 004855a5  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004855a9  741c                   -je 0x4855c7
    if (cpu.flags.zf)
    {
        goto L_0x004855c7;
    }
    // 004855ab  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004855ae  3bc6                   +cmp eax, esi
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
    // 004855b0  7437                   -je 0x4855e9
    if (cpu.flags.zf)
    {
        goto L_0x004855e9;
    }
    // 004855b2  3bc7                   +cmp eax, edi
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
    // 004855b4  7c02                   -jl 0x4855b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004855b8;
    }
    // 004855b6  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004855b8:
    // 004855b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004855b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004855ba  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004855bd  e8fe27ffff             -call 0x477dc0
    cpu.esp -= 4;
    _strncpy(app, cpu);
    // 004855c2  83c40c                 +add esp, 0xc
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
    // 004855c5  eb22                   -jmp 0x4855e9
    goto L_0x004855e9;
L_0x004855c7:
    // 004855c7  39751c                 +cmp dword ptr [ebp + 0x1c], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004855ca  7504                   -jne 0x4855d0
    if (!cpu.flags.zf)
    {
        goto L_0x004855d0;
    }
    // 004855cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004855cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004855ce  eb06                   -jmp 0x4855d6
    goto L_0x004855d6;
L_0x004855d0:
    // 004855d0  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004855d3  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
L_0x004855d6:
    // 004855d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004855d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004855d8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004855da  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004855dd  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004855e3  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004855e5  3bfe                   +cmp edi, esi
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
    // 004855e7  7404                   -je 0x4855ed
    if (cpu.flags.zf)
    {
        goto L_0x004855ed;
    }
L_0x004855e9:
    // 004855e9  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004855eb  eb02                   -jmp 0x4855ef
    goto L_0x004855ef;
L_0x004855ed:
    // 004855ed  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004855ef:
L_entry_0x004855ef:
    // 004855ef  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004855f2  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004855f5  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004855fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855ff  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485600  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4855ed(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004855ed;
    // 0048557b  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0048557e  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00485580  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485582  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00485586  8b7dd4                 -mov edi, dword ptr [ebp - 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00485589  3bde                   +cmp ebx, esi
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
    // 0048558b  7460                   -je 0x4855ed
    if (cpu.flags.zf)
    {
        goto L_0x004855ed;
    }
    // 0048558d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048558e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048558f  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00485592  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 00485595  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00485598  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0048559b  ff1550714800           -call dword ptr [0x487150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747600) /* 0x487150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004855a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004855a3  7448                   -je 0x4855ed
    if (cpu.flags.zf)
    {
        goto L_0x004855ed;
    }
    // 004855a5  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004855a9  741c                   -je 0x4855c7
    if (cpu.flags.zf)
    {
        goto L_0x004855c7;
    }
    // 004855ab  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004855ae  3bc6                   +cmp eax, esi
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
    // 004855b0  7437                   -je 0x4855e9
    if (cpu.flags.zf)
    {
        goto L_0x004855e9;
    }
    // 004855b2  3bc7                   +cmp eax, edi
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
    // 004855b4  7c02                   -jl 0x4855b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004855b8;
    }
    // 004855b6  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004855b8:
    // 004855b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004855b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004855ba  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004855bd  e8fe27ffff             -call 0x477dc0
    cpu.esp -= 4;
    _strncpy(app, cpu);
    // 004855c2  83c40c                 +add esp, 0xc
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
    // 004855c5  eb22                   -jmp 0x4855e9
    goto L_0x004855e9;
L_0x004855c7:
    // 004855c7  39751c                 +cmp dword ptr [ebp + 0x1c], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004855ca  7504                   -jne 0x4855d0
    if (!cpu.flags.zf)
    {
        goto L_0x004855d0;
    }
    // 004855cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004855cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004855ce  eb06                   -jmp 0x4855d6
    goto L_0x004855d6;
L_0x004855d0:
    // 004855d0  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004855d3  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
L_0x004855d6:
    // 004855d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004855d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004855d8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004855da  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004855dd  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004855e3  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004855e5  3bfe                   +cmp edi, esi
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
    // 004855e7  7404                   -je 0x4855ed
    if (cpu.flags.zf)
    {
        goto L_0x004855ed;
    }
L_0x004855e9:
    // 004855e9  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004855eb  eb02                   -jmp 0x4855ef
    goto L_0x004855ef;
L_0x004855ed:
L_entry_0x004855ed:
    // 004855ed  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004855ef:
    // 004855ef  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004855f2  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004855f5  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004855fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855ff  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485600  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485589(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00485589;
    // 0048557b  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0048557e  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00485580  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485582  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00485586  8b7dd4                 -mov edi, dword ptr [ebp - 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
L_entry_0x00485589:
    // 00485589  3bde                   +cmp ebx, esi
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
    // 0048558b  7460                   -je 0x4855ed
    if (cpu.flags.zf)
    {
        goto L_0x004855ed;
    }
    // 0048558d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048558e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048558f  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 00485592  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 00485595  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00485598  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0048559b  ff1550714800           -call dword ptr [0x487150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747600) /* 0x487150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004855a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004855a3  7448                   -je 0x4855ed
    if (cpu.flags.zf)
    {
        goto L_0x004855ed;
    }
    // 004855a5  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004855a9  741c                   -je 0x4855c7
    if (cpu.flags.zf)
    {
        goto L_0x004855c7;
    }
    // 004855ab  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004855ae  3bc6                   +cmp eax, esi
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
    // 004855b0  7437                   -je 0x4855e9
    if (cpu.flags.zf)
    {
        goto L_0x004855e9;
    }
    // 004855b2  3bc7                   +cmp eax, edi
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
    // 004855b4  7c02                   -jl 0x4855b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004855b8;
    }
    // 004855b6  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004855b8:
    // 004855b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004855b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004855ba  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004855bd  e8fe27ffff             -call 0x477dc0
    cpu.esp -= 4;
    _strncpy(app, cpu);
    // 004855c2  83c40c                 +add esp, 0xc
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
    // 004855c5  eb22                   -jmp 0x4855e9
    goto L_0x004855e9;
L_0x004855c7:
    // 004855c7  39751c                 +cmp dword ptr [ebp + 0x1c], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004855ca  7504                   -jne 0x4855d0
    if (!cpu.flags.zf)
    {
        goto L_0x004855d0;
    }
    // 004855cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004855cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004855ce  eb06                   -jmp 0x4855d6
    goto L_0x004855d6;
L_0x004855d0:
    // 004855d0  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004855d3  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
L_0x004855d6:
    // 004855d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004855d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004855d8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004855da  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004855dd  ff15bc714800           -call dword ptr [0x4871bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747708) /* 0x4871bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004855e3  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004855e5  3bfe                   +cmp edi, esi
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
    // 004855e7  7404                   -je 0x4855ed
    if (cpu.flags.zf)
    {
        goto L_0x004855ed;
    }
L_0x004855e9:
    // 004855e9  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004855eb  eb02                   -jmp 0x4855ef
    goto L_0x004855ef;
L_0x004855ed:
    // 004855ed  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004855ef:
    // 004855ef  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004855f2  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004855f5  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 004855fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855ff  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485600  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485601(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485601  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485605  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00485609  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048560b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048560c  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0048560f  740f                   -je 0x485620
    if (cpu.flags.zf)
    {
        goto L_0x00485620;
    }
L_0x00485611:
    // 00485611  66833800               +cmp word ptr [eax], 0
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
    // 00485615  7409                   -je 0x485620
    if (cpu.flags.zf)
    {
        goto L_0x00485620;
    }
    // 00485617  40                     -inc eax
    (cpu.eax)++;
    // 00485618  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048561a  40                     -inc eax
    (cpu.eax)++;
    // 0048561b  49                     -dec ecx
    (cpu.ecx)--;
    // 0048561c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048561e  75f1                   -jne 0x485611
    if (!cpu.flags.zf)
    {
        goto L_0x00485611;
    }
L_0x00485620:
    // 00485620  66833800               +cmp word ptr [eax], 0
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
    // 00485624  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485625  7507                   -jne 0x48562e
    if (!cpu.flags.zf)
    {
        goto L_0x0048562e;
    }
    // 00485627  2b442404               -sub eax, dword ptr [esp + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0048562b  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048562d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048562e:
    // 0048562e  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485630  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485631(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485631  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485632  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00485634  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485635  66817d08ffff           +cmp word ptr [ebp + 8], 0xffff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65535 /*0xffff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0048563b  7434                   -je 0x485671
    if (cpu.flags.zf)
    {
        goto L_0x00485671;
    }
    // 0048563d  66817d080001           +cmp word ptr [ebp + 8], 0x100
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(256 /*0x100*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00485643  7310                   -jae 0x485655
    if (!cpu.flags.cf)
    {
        goto L_0x00485655;
    }
    // 00485645  0fb74508               -movzx eax, word ptr [ebp + 8]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 00485649  8b0d10624a00           -mov ecx, dword ptr [0x4a6210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4874768) /* 0x4a6210 */);
    // 0048564f  668b0441               -mov ax, word ptr [ecx + eax*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 2);
    // 00485653  eb23                   -jmp 0x485678
    goto L_0x00485678;
L_0x00485655:
    // 00485655  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00485657  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048565a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048565c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048565d  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485660  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00485662  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485663  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00485665  e881f3ffff             -call 0x4849eb
    cpu.esp -= 4;
    sub_4849eb(app, cpu);
    // 0048566a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048566d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048566f  7504                   -jne 0x485675
    if (!cpu.flags.zf)
    {
        goto L_0x00485675;
    }
L_0x00485671:
    // 00485671  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485673  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485674  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485675:
    // 00485675  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x00485678:
    // 00485678  0fb74d0c               -movzx ecx, word ptr [ebp + 0xc]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 0048567c  0fb7c0                 -movzx eax, ax
    cpu.eax = x86::reg32(cpu.ax);
    // 0048567f  23c1                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485681  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485682  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485690  ff2588714800           -jmp dword ptr [0x487188]
    return app->dynamic_call(app->getMemory<x86::reg32>(4747656), cpu);
}

/* align: skip  */
void Application::sub_485696(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485696  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485697  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00485699  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048569a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048569b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048569c  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048569e  3935c4eb5100           +cmp dword ptr [0x51ebc4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5368772) /* 0x51ebc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004856a4  7548                   -jne 0x4856ee
    if (!cpu.flags.zf)
    {
        goto L_0x004856ee;
    }
    // 004856a6  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004856a9  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x004856ac:
    // 004856ac  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 004856af  663d5a00               +cmp ax, 0x5a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(90 /*0x5a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004856b3  7709                   -ja 0x4856be
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004856be;
    }
    // 004856b5  663d4100               +cmp ax, 0x41
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65 /*0x41*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004856b9  7203                   -jb 0x4856be
    if (cpu.flags.cf)
    {
        goto L_0x004856be;
    }
    // 004856bb  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004856be:
    // 004856be  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004856c1  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 004856c4  663d5a00               +cmp ax, 0x5a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(90 /*0x5a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004856c8  7709                   -ja 0x4856d3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004856d3;
    }
    // 004856ca  663d4100               +cmp ax, 0x41
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65 /*0x41*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004856ce  7203                   -jb 0x4856d3
    if (cpu.flags.cf)
    {
        goto L_0x004856d3;
    }
    // 004856d0  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004856d3:
    // 004856d3  41                     -inc ecx
    (cpu.ecx)++;
    // 004856d4  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004856d7  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004856da  41                     -inc ecx
    (cpu.ecx)++;
    // 004856db  42                     -inc edx
    (cpu.edx)++;
    // 004856dc  42                     -inc edx
    (cpu.edx)++;
    // 004856dd  663bc6                 +cmp ax, si
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.si));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004856e0  0f8481000000           -je 0x485767
    if (cpu.flags.zf)
    {
        goto L_0x00485767;
    }
    // 004856e6  663b4508               +cmp ax, word ptr [ebp + 8]
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004856ea  74c0                   -je 0x4856ac
    if (cpu.flags.zf)
    {
        goto L_0x004856ac;
    }
    // 004856ec  eb79                   -jmp 0x485767
    goto L_0x00485767;
L_0x004856ee:
    // 004856ee  bbe81f5200             -mov ebx, 0x521fe8
    cpu.ebx = 5382120 /*0x521fe8*/;
    // 004856f3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004856f4  ff15ac714800           -call dword ptr [0x4871ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747692) /* 0x4871ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004856fa  3935e41f5200           +cmp dword ptr [0x521fe4], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5382116) /* 0x521fe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485700  7418                   -je 0x48571a
    if (cpu.flags.zf)
    {
        goto L_0x0048571a;
    }
    // 00485702  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485703  ff158c714800           -call dword ptr [0x48718c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747660) /* 0x48718c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00485709  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 0048570b  e8b973ffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00485710  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485711  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00485718  eb03                   -jmp 0x48571d
    goto L_0x0048571d;
L_0x0048571a:
    // 0048571a  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
L_0x0048571d:
    // 0048571d  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485720  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485721  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x00485724:
    // 00485724  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00485727  46                     -inc esi
    (cpu.esi)++;
    // 00485728  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485729  46                     -inc esi
    (cpu.esi)++;
    // 0048572a  e854fcffff             -call 0x485383
    cpu.esp -= 4;
    sub_485383(app, cpu);
    // 0048572f  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00485732  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 00485735  47                     -inc edi
    (cpu.edi)++;
    // 00485736  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485737  47                     -inc edi
    (cpu.edi)++;
    // 00485738  e846fcffff             -call 0x485383
    cpu.esp -= 4;
    sub_485383(app, cpu);
    // 0048573d  66837d0c00             +cmp word ptr [ebp + 0xc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00485742  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485743  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485744  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00485747  7406                   -je 0x48574f
    if (cpu.flags.zf)
    {
        goto L_0x0048574f;
    }
    // 00485749  6639450c               +cmp word ptr [ebp + 0xc], ax
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.ax));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0048574d  74d5                   -je 0x485724
    if (cpu.flags.zf)
    {
        goto L_0x00485724;
    }
L_0x0048574f:
    // 0048574f  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 00485753  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485754  740a                   -je 0x485760
    if (cpu.flags.zf)
    {
        goto L_0x00485760;
    }
    // 00485756  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00485758  e8cd73ffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 0048575d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048575e  eb07                   -jmp 0x485767
    goto L_0x00485767;
L_0x00485760:
    // 00485760  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485761  ff158c714800           -call dword ptr [0x48718c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747660) /* 0x48718c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00485767:
    // 00485767  0fb74d08               -movzx ecx, word ptr [ebp + 8]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 0048576b  0fb7450c               -movzx eax, word ptr [ebp + 0xc]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 0048576f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485770  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485772  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485773  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485774  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485775(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485775  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00485779  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048577a  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048577e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00485783  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485784  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00485786  807e013a               +cmp byte ptr [esi + 1], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048578a  7503                   -jne 0x48578f
    if (!cpu.flags.zf)
    {
        goto L_0x0048578f;
    }
    // 0048578c  8d4e02                 -lea ecx, [esi + 2]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
L_0x0048578f:
    // 0048578f  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00485791  80fa5c                 +cmp dl, 0x5c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485794  7405                   -je 0x48579b
    if (cpu.flags.zf)
    {
        goto L_0x0048579b;
    }
    // 00485796  80fa2f                 +cmp dl, 0x2f
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485799  7506                   -jne 0x4857a1
    if (!cpu.flags.zf)
    {
        goto L_0x004857a1;
    }
L_0x0048579b:
    // 0048579b  80790100               +cmp byte ptr [ecx + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048579f  740d                   -je 0x4857ae
    if (cpu.flags.zf)
    {
        goto L_0x004857ae;
    }
L_0x004857a1:
    // 004857a1  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004857a3  7509                   -jne 0x4857ae
    if (!cpu.flags.zf)
    {
        goto L_0x004857ae;
    }
    // 004857a5  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004857a7  bf00800000             -mov edi, 0x8000
    cpu.edi = 32768 /*0x8000*/;
    // 004857ac  7505                   -jne 0x4857b3
    if (!cpu.flags.zf)
    {
        goto L_0x004857b3;
    }
L_0x004857ae:
    // 004857ae  bf40400000             -mov edi, 0x4040
    cpu.edi = 16448 /*0x4040*/;
L_0x004857b3:
    // 004857b3  f6d0                   -not al
    cpu.al = ~cpu.al;
    // 004857b5  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004857b8  6a2e                   -push 0x2e
    app->getMemory<x86::reg32>(cpu.esp-4) = 46 /*0x2e*/;
    cpu.esp -= 4;
    // 004857ba  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004857bc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004857bd  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004857c0  0bf8                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004857c2  e878d6ffff             -call 0x482e3f
    cpu.esp -= 4;
    sub_482e3f(app, cpu);
    // 004857c7  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004857c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857ca  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004857cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857cd  7447                   -je 0x485816
    if (cpu.flags.zf)
    {
        goto L_0x00485816;
    }
    // 004857cf  68707e4800             -push 0x487e70
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750960 /*0x487e70*/;
    cpu.esp -= 4;
    // 004857d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004857d5  e87e030000             -call 0x485b58
    cpu.esp -= 4;
    sub_485b58(app, cpu);
    // 004857da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004857dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857de  7433                   -je 0x485813
    if (cpu.flags.zf)
    {
        goto L_0x00485813;
    }
    // 004857e0  68807e4800             -push 0x487e80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750976 /*0x487e80*/;
    cpu.esp -= 4;
    // 004857e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004857e6  e86d030000             -call 0x485b58
    cpu.esp -= 4;
    sub_485b58(app, cpu);
    // 004857eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004857ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857ef  7422                   -je 0x485813
    if (cpu.flags.zf)
    {
        goto L_0x00485813;
    }
    // 004857f1  68787e4800             -push 0x487e78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750968 /*0x487e78*/;
    cpu.esp -= 4;
    // 004857f6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004857f7  e85c030000             -call 0x485b58
    cpu.esp -= 4;
    sub_485b58(app, cpu);
    // 004857fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004857ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485800  7411                   -je 0x485813
    if (cpu.flags.zf)
    {
        goto L_0x00485813;
    }
    // 00485802  68687e4800             -push 0x487e68
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750952 /*0x487e68*/;
    cpu.esp -= 4;
    // 00485807  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485808  e84b030000             -call 0x485b58
    cpu.esp -= 4;
    sub_485b58(app, cpu);
    // 0048580d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048580e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485810  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485811  7503                   -jne 0x485816
    if (!cpu.flags.zf)
    {
        goto L_0x00485816;
    }
L_0x00485813:
    // 00485813  83cf40                 -or edi, 0x40
    cpu.edi |= x86::reg32(x86::sreg32(64 /*0x40*/));
L_0x00485816:
    // 00485816  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00485818  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0048581b  83e038                 -and eax, 0x38
    cpu.eax &= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0048581e  0bf8                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00485820  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00485822  c1e806                 -shr eax, 6
    cpu.eax >>= 6 /*0x6*/ % 32;
    // 00485825  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00485828  0bc7                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 0048582a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048582b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048582c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48582d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048582d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048582e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00485830  81ec64020000           -sub esp, 0x264
    (cpu.esp) -= x86::reg32(x86::sreg32(612 /*0x264*/));
    // 00485836  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485837  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485838  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048583b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048583c  6814884800             -push 0x488814
    app->getMemory<x86::reg32>(cpu.esp-4) = 4753428 /*0x488814*/;
    cpu.esp -= 4;
    // 00485841  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485842  e809060000             -call 0x485e50
    cpu.esp -= 4;
    sub_485e50(app, cpu);
    // 00485847  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485848  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048584a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048584b  7513                   -jne 0x485860
    if (!cpu.flags.zf)
    {
        goto L_0x00485860;
    }
    // 0048584d  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048584f  807e013a               +cmp byte ptr [esi + 1], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485853  7533                   -jne 0x485888
    if (!cpu.flags.zf)
    {
        goto L_0x00485888;
    }
    // 00485855  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00485857  3ac3                   +cmp al, bl
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
    // 00485859  741e                   -je 0x485879
    if (cpu.flags.zf)
    {
        goto L_0x00485879;
    }
    // 0048585b  385e02                 +cmp byte ptr [esi + 2], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048585e  7519                   -jne 0x485879
    if (!cpu.flags.zf)
    {
        goto L_0x00485879;
    }
L_0x00485860:
    // 00485860  e84d8cffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00485865  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00485867  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485868  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0048586a  e84c8cffff             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 0048586f  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 00485871  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00485874  e96a020000             -jmp 0x485ae3
    goto L_0x00485ae3;
L_0x00485879:
    // 00485879  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0048587c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048587d  e853050000             -call 0x485dd5
    cpu.esp -= 4;
    sub_485dd5(app, cpu);
    // 00485882  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485883  83e860                 +sub eax, 0x60
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00485886  eb05                   -jmp 0x48588d
    goto L_0x0048588d;
L_0x00485888:
    // 00485888  e805050000             -call 0x485d92
    cpu.esp -= 4;
    sub_485d92(app, cpu);
L_0x0048588d:
    // 0048588d  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00485890  8d85a0feffff           -lea eax, [ebp - 0x160]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-352) /* -0x160 */);
    // 00485896  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485897  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485898  ff1578714800           -call dword ptr [0x487178]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747640) /* 0x487178 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048589e  83cfff                 -or edi, 0xffffffff
    cpu.edi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004858a1  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004858a4  3bc7                   +cmp eax, edi
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
    // 004858a6  0f85ab000000           -jne 0x485957
    if (!cpu.flags.zf)
    {
        goto L_0x00485957;
    }
    // 004858ac  6810884800             -push 0x488810
    app->getMemory<x86::reg32>(cpu.esp-4) = 4753424 /*0x488810*/;
    cpu.esp -= 4;
    // 004858b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004858b2  e899050000             -call 0x485e50
    cpu.esp -= 4;
    sub_485e50(app, cpu);
    // 004858b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004858b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004858ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004858bb  0f8480000000           -je 0x485941
    if (cpu.flags.zf)
    {
        goto L_0x00485941;
    }
    // 004858c1  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 004858c6  8d859cfdffff           -lea eax, [ebp - 0x264]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-612) /* -0x264 */);
    // 004858cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004858cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004858ce  e81a040000             -call 0x485ced
    cpu.esp -= 4;
    sub_485ced(app, cpu);
    // 004858d3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004858d5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004858d8  3bf3                   +cmp esi, ebx
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
    // 004858da  7465                   -je 0x485941
    if (cpu.flags.zf)
    {
        goto L_0x00485941;
    }
    // 004858dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004858dd  e8fe84ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 004858e2  83f803                 +cmp eax, 3
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
    // 004858e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004858e6  740b                   -je 0x4858f3
    if (cpu.flags.zf)
    {
        goto L_0x004858f3;
    }
    // 004858e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004858e9  e8fa010000             -call 0x485ae8
    cpu.esp -= 4;
    sub_485ae8(app, cpu);
    // 004858ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004858f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004858f1  744e                   -je 0x485941
    if (cpu.flags.zf)
    {
        goto L_0x00485941;
    }
L_0x004858f3:
    // 004858f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004858f4  ff1548704800           -call dword ptr [0x487048]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747336) /* 0x487048 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004858fa  83f801                 +cmp eax, 1
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
    // 004858fd  7642                   -jbe 0x485941
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00485941;
    }
    // 004858ff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485901  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485902  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485903  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00485905  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00485907  68bc070000             -push 0x7bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 1980 /*0x7bc*/;
    cpu.esp -= 4;
    // 0048590c  c785a0feffff10000000   -mov dword ptr [ebp - 0x160], 0x10
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-352) /* -0x160 */) = 16 /*0x10*/;
    // 00485916  899dbcfeffff           -mov dword ptr [ebp - 0x144], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-324) /* -0x144 */) = cpu.ebx;
    // 0048591c  899dc0feffff           -mov dword ptr [ebp - 0x140], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-320) /* -0x140 */) = cpu.ebx;
    // 00485922  889dccfeffff           -mov byte ptr [ebp - 0x134], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-308) /* -0x134 */) = cpu.bl;
    // 00485928  e8939fffff             -call 0x47f8c0
    cpu.esp -= 4;
    sub_47f8c0(app, cpu);
    // 0048592d  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00485930  83c41c                 +add esp, 0x1c
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
    // 00485933  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00485936  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00485939  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048593c  e94e010000             -jmp 0x485a8f
    goto L_0x00485a8f;
L_0x00485941:
    // 00485941  e86c8bffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00485946  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00485948  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485949  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0048594b  e86b8bffff             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 00485950  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 00485952  e98a010000             -jmp 0x485ae1
    goto L_0x00485ae1;
L_0x00485957:
    // 00485957  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0048595a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048595b  8d85b4feffff           -lea eax, [ebp - 0x14c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00485961  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485962  ff157c714800           -call dword ptr [0x48717c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747644) /* 0x48717c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00485968  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048596a  0f845b010000           -je 0x485acb
    if (cpu.flags.zf)
    {
        goto L_0x00485acb;
    }
    // 00485970  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00485973  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485974  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00485977  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485978  ff15d0714800           -call dword ptr [0x4871d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747728) /* 0x4871d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0048597e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485980  0f8445010000           -je 0x485acb
    if (cpu.flags.zf)
    {
        goto L_0x00485acb;
    }
    // 00485986  0fb745fc               -movzx eax, word ptr [ebp - 4]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 0048598a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048598b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048598c  0fb745fa               -movzx eax, word ptr [ebp - 6]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */));
    // 00485990  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485991  0fb745f8               -movzx eax, word ptr [ebp - 8]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 00485995  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485996  0fb745f6               -movzx eax, word ptr [ebp - 0xa]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-10) /* -0xa */));
    // 0048599a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048599b  0fb745f2               -movzx eax, word ptr [ebp - 0xe]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-14) /* -0xe */));
    // 0048599f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004859a0  0fb745f0               -movzx eax, word ptr [ebp - 0x10]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    // 004859a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004859a5  e8169fffff             -call 0x47f8c0
    cpu.esp -= 4;
    sub_47f8c0(app, cpu);
    // 004859aa  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004859ad  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004859b0  399dacfeffff           +cmp dword ptr [ebp - 0x154], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004859b6  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004859b9  7508                   -jne 0x4859c3
    if (!cpu.flags.zf)
    {
        goto L_0x004859c3;
    }
    // 004859bb  399db0feffff           +cmp dword ptr [ebp - 0x150], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004859c1  7456                   -je 0x485a19
    if (cpu.flags.zf)
    {
        goto L_0x00485a19;
    }
L_0x004859c3:
    // 004859c3  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004859c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004859c7  8d85acfeffff           -lea eax, [ebp - 0x154]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004859cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004859ce  ff157c714800           -call dword ptr [0x48717c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747644) /* 0x48717c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004859d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004859d6  0f84ef000000           -je 0x485acb
    if (cpu.flags.zf)
    {
        goto L_0x00485acb;
    }
    // 004859dc  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004859df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004859e0  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004859e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004859e4  ff15d0714800           -call dword ptr [0x4871d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747728) /* 0x4871d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004859ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004859ec  0f84d9000000           -je 0x485acb
    if (cpu.flags.zf)
    {
        goto L_0x00485acb;
    }
    // 004859f2  0fb745fc               -movzx eax, word ptr [ebp - 4]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 004859f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004859f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004859f8  0fb745fa               -movzx eax, word ptr [ebp - 6]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */));
    // 004859fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004859fd  0fb745f8               -movzx eax, word ptr [ebp - 8]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 00485a01  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a02  0fb745f6               -movzx eax, word ptr [ebp - 0xa]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-10) /* -0xa */));
    // 00485a06  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a07  0fb745f2               -movzx eax, word ptr [ebp - 0xe]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-14) /* -0xe */));
    // 00485a0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a0c  0fb745f0               -movzx eax, word ptr [ebp - 0x10]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    // 00485a10  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a11  e8aa9effff             -call 0x47f8c0
    cpu.esp -= 4;
    sub_47f8c0(app, cpu);
    // 00485a16  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x00485a19:
    // 00485a19  399da4feffff           +cmp dword ptr [ebp - 0x15c], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-348) /* -0x15c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485a1f  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00485a22  750d                   -jne 0x485a31
    if (!cpu.flags.zf)
    {
        goto L_0x00485a31;
    }
    // 00485a24  399da8feffff           +cmp dword ptr [ebp - 0x158], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-344) /* -0x158 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485a2a  7505                   -jne 0x485a31
    if (!cpu.flags.zf)
    {
        goto L_0x00485a31;
    }
    // 00485a2c  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00485a2f  eb52                   -jmp 0x485a83
    goto L_0x00485a83;
L_0x00485a31:
    // 00485a31  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00485a34  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a35  8d85a4feffff           -lea eax, [ebp - 0x15c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-348) /* -0x15c */);
    // 00485a3b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a3c  ff157c714800           -call dword ptr [0x48717c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747644) /* 0x48717c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00485a42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485a44  0f8481000000           -je 0x485acb
    if (cpu.flags.zf)
    {
        goto L_0x00485acb;
    }
    // 00485a4a  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00485a4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a4e  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00485a51  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a52  ff15d0714800           -call dword ptr [0x4871d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747728) /* 0x4871d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00485a58  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485a5a  746f                   -je 0x485acb
    if (cpu.flags.zf)
    {
        goto L_0x00485acb;
    }
    // 00485a5c  0fb745fc               -movzx eax, word ptr [ebp - 4]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 00485a60  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485a61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a62  0fb745fa               -movzx eax, word ptr [ebp - 6]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-6) /* -0x6 */));
    // 00485a66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a67  0fb745f8               -movzx eax, word ptr [ebp - 8]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 00485a6b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a6c  0fb745f6               -movzx eax, word ptr [ebp - 0xa]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-10) /* -0xa */));
    // 00485a70  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a71  0fb745f2               -movzx eax, word ptr [ebp - 0xe]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-14) /* -0xe */));
    // 00485a75  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a76  0fb745f0               -movzx eax, word ptr [ebp - 0x10]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    // 00485a7a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485a7b  e8409effff             -call 0x47f8c0
    cpu.esp -= 4;
    sub_47f8c0(app, cpu);
    // 00485a80  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x00485a83:
    // 00485a83  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 00485a86  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00485a89  ff1570714800           -call dword ptr [0x487170]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747632) /* 0x487170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00485a8f:
    // 00485a8f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00485a92  ffb5a0feffff           -push dword ptr [ebp - 0x160]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-352) /* -0x160 */);
    cpu.esp -= 4;
    // 00485a98  e8d8fcffff             -call 0x485775
    cpu.esp -= 4;
    sub_485775(app, cpu);
    // 00485a9d  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 00485aa1  8b85c0feffff           -mov eax, dword ptr [ebp - 0x140]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-320) /* -0x140 */);
    // 00485aa7  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00485aaa  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00485aad  48                     -dec eax
    (cpu.eax)--;
    // 00485aae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485aaf  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00485ab1  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00485ab4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ab5  66c746080100           -mov word ptr [esi + 8], 1
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 00485abb  66895e04               -mov word ptr [esi + 4], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.bx;
    // 00485abf  66895e0c               -mov word ptr [esi + 0xc], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.bx;
    // 00485ac3  66895e0a               -mov word ptr [esi + 0xa], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.bx;
    // 00485ac7  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00485ac9  eb18                   -jmp 0x485ae3
    goto L_0x00485ae3;
L_0x00485acb:
    // 00485acb  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00485ad1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485ad2  e86889ffff             -call 0x47e43f
    cpu.esp -= 4;
    sub_47e43f(app, cpu);
    // 00485ad7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ad8  ff75ec                 -push dword ptr [ebp - 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    // 00485adb  ff1570714800           -call dword ptr [0x487170]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747632) /* 0x487170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00485ae1:
    // 00485ae1  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00485ae3:
    // 00485ae3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ae4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ae5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ae6  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ae7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485ae8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485ae8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485ae9  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485aed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485aee  e8ed82ffff             -call 0x47dde0
    cpu.esp -= 4;
    _strlen(app, cpu);
    // 00485af3  83f805                 +cmp eax, 5
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
    // 00485af6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485af7  725b                   -jb 0x485b54
    if (cpu.flags.cf)
    {
        goto L_0x00485b54;
    }
    // 00485af9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00485afb  3c5c                   +cmp al, 0x5c
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485afd  7404                   -je 0x485b03
    if (cpu.flags.zf)
    {
        goto L_0x00485b03;
    }
    // 00485aff  3c2f                   +cmp al, 0x2f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485b01  7551                   -jne 0x485b54
    if (!cpu.flags.zf)
    {
        goto L_0x00485b54;
    }
L_0x00485b03:
    // 00485b03  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00485b06  3c5c                   +cmp al, 0x5c
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485b08  7404                   -je 0x485b0e
    if (cpu.flags.zf)
    {
        goto L_0x00485b0e;
    }
    // 00485b0a  3c2f                   +cmp al, 0x2f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485b0c  7546                   -jne 0x485b54
    if (!cpu.flags.zf)
    {
        goto L_0x00485b54;
    }
L_0x00485b0e:
    // 00485b0e  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00485b11  8d4603                 -lea eax, [esi + 3]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00485b14  32d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
L_0x00485b16:
    // 00485b16  3aca                   +cmp cl, dl
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
    // 00485b18  7410                   -je 0x485b2a
    if (cpu.flags.zf)
    {
        goto L_0x00485b2a;
    }
    // 00485b1a  80f95c                 +cmp cl, 0x5c
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485b1d  740b                   -je 0x485b2a
    if (cpu.flags.zf)
    {
        goto L_0x00485b2a;
    }
    // 00485b1f  80f92f                 +cmp cl, 0x2f
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485b22  7406                   -je 0x485b2a
    if (cpu.flags.zf)
    {
        goto L_0x00485b2a;
    }
    // 00485b24  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00485b27  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485b28  ebec                   -jmp 0x485b16
    goto L_0x00485b16;
L_0x00485b2a:
    // 00485b2a  3810                   +cmp byte ptr [eax], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485b2c  7426                   -je 0x485b54
    if (cpu.flags.zf)
    {
        goto L_0x00485b54;
    }
    // 00485b2e  40                     -inc eax
    (cpu.eax)++;
    // 00485b2f  3810                   +cmp byte ptr [eax], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485b31  7421                   -je 0x485b54
    if (cpu.flags.zf)
    {
        goto L_0x00485b54;
    }
L_0x00485b33:
    // 00485b33  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00485b35  3aca                   +cmp cl, dl
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
    // 00485b37  740d                   -je 0x485b46
    if (cpu.flags.zf)
    {
        goto L_0x00485b46;
    }
    // 00485b39  80f95c                 +cmp cl, 0x5c
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485b3c  7408                   -je 0x485b46
    if (cpu.flags.zf)
    {
        goto L_0x00485b46;
    }
    // 00485b3e  80f92f                 +cmp cl, 0x2f
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485b41  7403                   -je 0x485b46
    if (cpu.flags.zf)
    {
        goto L_0x00485b46;
    }
    // 00485b43  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485b44  ebed                   -jmp 0x485b33
    goto L_0x00485b33;
L_0x00485b46:
    // 00485b46  3810                   +cmp byte ptr [eax], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485b48  7405                   -je 0x485b4f
    if (cpu.flags.zf)
    {
        goto L_0x00485b4f;
    }
    // 00485b4a  385001                 +cmp byte ptr [eax + 1], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485b4d  7505                   -jne 0x485b54
    if (!cpu.flags.zf)
    {
        goto L_0x00485b54;
    }
L_0x00485b4f:
    // 00485b4f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00485b51  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b52  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485b54:
    // 00485b54  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485b56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485b58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485b58  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485b59  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00485b5b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00485b5e  833dbc1c520000         +cmp dword ptr [0x521cbc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5381308) /* 0x521cbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485b65  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485b66  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485b67  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485b68  7512                   -jne 0x485b7c
    if (!cpu.flags.zf)
    {
        goto L_0x00485b7c;
    }
    // 00485b6a  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00485b6d  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00485b70  e83bf0ffff             -call 0x484bb0
    cpu.esp -= 4;
    sub_484bb0(app, cpu);
    // 00485b75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b77  e96c010000             -jmp 0x485ce8
    goto L_0x00485ce8;
L_0x00485b7c:
    // 00485b7c  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00485b7e  e8466fffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00485b83  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00485b86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b87  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485b8a  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 00485b8f  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00485b92  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00485b95  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00485b98  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x00485b9b:
    // 00485b9b  660fb601               -movzx ax, byte ptr [ecx]
    cpu.ax = x86::reg16(app->getMemory<x86::reg8>(cpu.ecx));
    // 00485b9f  0fb6d0                 -movzx edx, al
    cpu.edx = x86::reg32(cpu.al);
    // 00485ba2  41                     -inc ecx
    (cpu.ecx)++;
    // 00485ba3  ff45f8                 -inc dword ptr [ebp - 8]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))++;
    // 00485ba6  f682c11d520004         +test byte ptr [edx + 0x521dc1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5381569) /* 0x521dc1 */) & 4 /*0x4*/));
    // 00485bad  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00485bb0  7457                   -je 0x485c09
    if (cpu.flags.zf)
    {
        goto L_0x00485c09;
    }
    // 00485bb2  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485bb5  7504                   -jne 0x485bbb
    if (!cpu.flags.zf)
    {
        goto L_0x00485bbb;
    }
    // 00485bb7  33ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00485bb9  eb6b                   -jmp 0x485c26
    goto L_0x00485c26;
L_0x00485bbb:
    // 00485bbb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00485bbd  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00485bc0  ff35a81c5200           -push dword ptr [0x521ca8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381288) /* 0x521ca8 */);
    cpu.esp -= 4;
    // 00485bc6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00485bc8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485bc9  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00485bcb  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 00485bce  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485bcf  ff35c41e5200           -push dword ptr [0x521ec4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381828) /* 0x521ec4 */);
    cpu.esp -= 4;
    // 00485bd5  e88b74ffff             -call 0x47d065
    cpu.esp -= 4;
    sub_47d065(app, cpu);
    // 00485bda  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00485bdd  83f801                 +cmp eax, 1
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
    // 00485be0  7507                   -jne 0x485be9
    if (!cpu.flags.zf)
    {
        goto L_0x00485be9;
    }
    // 00485be2  660fb67dfc             -movzx di, byte ptr [ebp - 4]
    cpu.di = x86::reg16(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 00485be7  eb18                   -jmp 0x485c01
    goto L_0x00485c01;
L_0x00485be9:
    // 00485be9  83f802                 +cmp eax, 2
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
    // 00485bec  0f85ca000000           -jne 0x485cbc
    if (!cpu.flags.zf)
    {
        goto L_0x00485cbc;
    }
    // 00485bf2  660fb67dfc             -movzx di, byte ptr [ebp - 4]
    cpu.di = x86::reg16(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 00485bf7  660fb645fd             -movzx ax, byte ptr [ebp - 3]
    cpu.ax = x86::reg16(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */));
    // 00485bfc  c1e708                 -shl edi, 8
    cpu.edi <<= 8 /*0x8*/ % 32;
    // 00485bff  03f8                   +add edi, eax
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
L_0x00485c01:
    // 00485c01  ff4508                 +inc dword ptr [ebp + 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485c04  ff45f8                 +inc dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485c07  eb1d                   -jmp 0x485c26
    goto L_0x00485c26;
L_0x00485c09:
    // 00485c09  0fb7c0                 -movzx eax, ax
    cpu.eax = x86::reg32(cpu.ax);
    // 00485c0c  8a88c11d5200           -mov cl, byte ptr [eax + 0x521dc1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381569) /* 0x521dc1 */);
    // 00485c12  80e110                 -and cl, 0x10
    cpu.cl &= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00485c15  80f910                 +cmp cl, 0x10
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485c18  750a                   -jne 0x485c24
    if (!cpu.flags.zf)
    {
        goto L_0x00485c24;
    }
    // 00485c1a  660fb6b8c01c5200       -movzx di, byte ptr [eax + 0x521cc0]
    cpu.di = x86::reg16(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381312) /* 0x521cc0 */));
    // 00485c22  eb02                   -jmp 0x485c26
    goto L_0x00485c26;
L_0x00485c24:
    // 00485c24  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00485c26:
    // 00485c26  660fb606               -movzx ax, byte ptr [esi]
    cpu.ax = x86::reg16(app->getMemory<x86::reg8>(cpu.esi));
    // 00485c2a  0fb6c8                 -movzx ecx, al
    cpu.ecx = x86::reg32(cpu.al);
    // 00485c2d  46                     -inc esi
    (cpu.esi)++;
    // 00485c2e  ff45f4                 -inc dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))++;
    // 00485c31  f681c11d520004         +test byte ptr [ecx + 0x521dc1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5381569) /* 0x521dc1 */) & 4 /*0x4*/));
    // 00485c38  89750c                 -mov dword ptr [ebp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00485c3b  7453                   -je 0x485c90
    if (cpu.flags.zf)
    {
        goto L_0x00485c90;
    }
    // 00485c3d  803e00                 +cmp byte ptr [esi], 0
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
    // 00485c40  7504                   -jne 0x485c46
    if (!cpu.flags.zf)
    {
        goto L_0x00485c46;
    }
    // 00485c42  33f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00485c44  eb61                   -jmp 0x485ca7
    goto L_0x00485ca7;
L_0x00485c46:
    // 00485c46  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00485c48  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00485c4b  ff35a81c5200           -push dword ptr [0x521ca8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381288) /* 0x521ca8 */);
    cpu.esp -= 4;
    // 00485c51  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00485c53  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485c54  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00485c56  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 00485c59  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485c5a  ff35c41e5200           -push dword ptr [0x521ec4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381828) /* 0x521ec4 */);
    cpu.esp -= 4;
    // 00485c60  e80074ffff             -call 0x47d065
    cpu.esp -= 4;
    sub_47d065(app, cpu);
    // 00485c65  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00485c68  83f801                 +cmp eax, 1
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
    // 00485c6b  7507                   -jne 0x485c74
    if (!cpu.flags.zf)
    {
        goto L_0x00485c74;
    }
    // 00485c6d  660fb675fc             -movzx si, byte ptr [ebp - 4]
    cpu.si = x86::reg16(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 00485c72  eb14                   -jmp 0x485c88
    goto L_0x00485c88;
L_0x00485c74:
    // 00485c74  83f802                 +cmp eax, 2
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
    // 00485c77  7543                   -jne 0x485cbc
    if (!cpu.flags.zf)
    {
        goto L_0x00485cbc;
    }
    // 00485c79  660fb675fc             -movzx si, byte ptr [ebp - 4]
    cpu.si = x86::reg16(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 00485c7e  660fb645fd             -movzx ax, byte ptr [ebp - 3]
    cpu.ax = x86::reg16(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */));
    // 00485c83  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 00485c86  03f0                   +add esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00485c88:
    // 00485c88  ff450c                 +inc dword ptr [ebp + 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485c8b  ff45f4                 +inc dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485c8e  eb17                   -jmp 0x485ca7
    goto L_0x00485ca7;
L_0x00485c90:
    // 00485c90  0fb7f0                 -movzx esi, ax
    cpu.esi = x86::reg32(cpu.ax);
    // 00485c93  8a86c11d5200           -mov al, byte ptr [esi + 0x521dc1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5381569) /* 0x521dc1 */);
    // 00485c99  2410                   -and al, 0x10
    cpu.al &= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00485c9b  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485c9d  7508                   -jne 0x485ca7
    if (!cpu.flags.zf)
    {
        goto L_0x00485ca7;
    }
    // 00485c9f  660fb6b6c01c5200       -movzx si, byte ptr [esi + 0x521cc0]
    cpu.si = x86::reg16(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5381312) /* 0x521cc0 */));
L_0x00485ca7:
    // 00485ca7  663bfe                 +cmp di, si
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.si));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00485caa  751f                   -jne 0x485ccb
    if (!cpu.flags.zf)
    {
        goto L_0x00485ccb;
    }
    // 00485cac  6685ff                 +test di, di
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & cpu.di));
    // 00485caf  742d                   -je 0x485cde
    if (cpu.flags.zf)
    {
        goto L_0x00485cde;
    }
    // 00485cb1  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00485cb4  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485cb7  e9dffeffff             -jmp 0x485b9b
    goto L_0x00485b9b;
L_0x00485cbc:
    // 00485cbc  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00485cbe  e8676effff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00485cc3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485cc4  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 00485cc9  eb1d                   -jmp 0x485ce8
    goto L_0x00485ce8;
L_0x00485ccb:
    // 00485ccb  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00485ccd  e8586effff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00485cd2  663bf7                 +cmp si, di
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00485cd5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485cd6  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00485cd8  83e002                 +and eax, 2
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 00485cdb  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00485cdc  eb0a                   -jmp 0x485ce8
    goto L_0x00485ce8;
L_0x00485cde:
    // 00485cde  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00485ce0  e8456effff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00485ce5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ce6  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00485ce8:
    // 00485ce8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ce9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485cea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ceb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485cec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485ced(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485ced  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485cee  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00485cf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485cf1  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00485cf4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00485cf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485cf7  0f8484000000           -je 0x485d81
    if (cpu.flags.zf)
    {
        goto L_0x00485d81;
    }
    // 00485cfd  803b00                 +cmp byte ptr [ebx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485d00  747f                   -je 0x485d81
    if (cpu.flags.zf)
    {
        goto L_0x00485d81;
    }
    // 00485d02  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485d05  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00485d07  7525                   -jne 0x485d2e
    if (!cpu.flags.zf)
    {
        goto L_0x00485d2e;
    }
    // 00485d09  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00485d0e  e86715ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00485d13  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00485d15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d16  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00485d18  750d                   -jne 0x485d27
    if (!cpu.flags.zf)
    {
        goto L_0x00485d27;
    }
    // 00485d1a  e89387ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00485d1f  c7000c000000           -mov dword ptr [eax], 0xc
    app->getMemory<x86::reg32>(cpu.eax) = 12 /*0xc*/;
    // 00485d25  eb52                   -jmp 0x485d79
    goto L_0x00485d79;
L_0x00485d27:
    // 00485d27  c7451004010000         -mov dword ptr [ebp + 0x10], 0x104
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 260 /*0x104*/;
L_0x00485d2e:
    // 00485d2e  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00485d31  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485d32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485d33  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00485d36  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485d37  ff15ac704800           -call dword ptr [0x4870ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747436) /* 0x4870ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00485d3d  3b4510                 +cmp eax, dword ptr [ebp + 0x10]
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
    // 00485d40  721a                   -jb 0x485d5c
    if (cpu.flags.cf)
    {
        goto L_0x00485d5c;
    }
    // 00485d42  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 00485d46  7507                   -jne 0x485d4f
    if (!cpu.flags.zf)
    {
        goto L_0x00485d4f;
    }
    // 00485d48  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485d49  e86616ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00485d4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00485d4f:
    // 00485d4f  e85e87ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00485d54  c70022000000           -mov dword ptr [eax], 0x22
    app->getMemory<x86::reg32>(cpu.eax) = 34 /*0x22*/;
    // 00485d5a  eb1d                   -jmp 0x485d79
    goto L_0x00485d79;
L_0x00485d5c:
    // 00485d5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485d5e  751d                   -jne 0x485d7d
    if (!cpu.flags.zf)
    {
        goto L_0x00485d7d;
    }
    // 00485d60  394508                 +cmp dword ptr [ebp + 8], eax
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
    // 00485d63  7507                   -jne 0x485d6c
    if (!cpu.flags.zf)
    {
        goto L_0x00485d6c;
    }
    // 00485d65  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485d66  e84916ffff             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00485d6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00485d6c:
    // 00485d6c  ff15b8714800           -call dword ptr [0x4871b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747704) /* 0x4871b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00485d72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485d73  e8c786ffff             -call 0x47e43f
    cpu.esp -= 4;
    sub_47e43f(app, cpu);
    // 00485d78  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00485d79:
    // 00485d79  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00485d7b  eb11                   -jmp 0x485d8e
    goto L_0x00485d8e;
L_0x00485d7d:
    // 00485d7d  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00485d7f  eb0d                   -jmp 0x485d8e
    goto L_0x00485d8e;
L_0x00485d81:
    // 00485d81  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00485d84  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00485d87  e859010000             -call 0x485ee5
    cpu.esp -= 4;
    sub_485ee5(app, cpu);
    // 00485d8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00485d8e:
    // 00485d8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d8f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485d92(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485d92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485d93  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00485d95  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00485d9b  8d85fcfeffff           -lea eax, [ebp - 0x104]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-260) /* -0x104 */);
    // 00485da1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485da2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485da3  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00485da8  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00485daa  ff15b0704800           -call dword ptr [0x4870b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747440) /* 0x4870b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00485db0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485db2  741c                   -je 0x485dd0
    if (cpu.flags.zf)
    {
        goto L_0x00485dd0;
    }
    // 00485db4  80bdfdfeffff3a         +cmp byte ptr [ebp - 0x103], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-259) /* -0x103 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485dbb  7513                   -jne 0x485dd0
    if (!cpu.flags.zf)
    {
        goto L_0x00485dd0;
    }
    // 00485dbd  0fb685fcfeffff         -movzx eax, byte ptr [ebp - 0x104]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-260) /* -0x104 */));
    // 00485dc4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485dc5  e8e6eaffff             -call 0x4848b0
    cpu.esp -= 4;
    sub_4848b0(app, cpu);
    // 00485dca  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00485dcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485dcd  83ee40                 -sub esi, 0x40
    (cpu.esi) -= x86::reg32(x86::sreg32(64 /*0x40*/));
L_0x00485dd0:
    // 00485dd0  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00485dd2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485dd3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485dd4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485dd5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485dd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485dd6  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00485dd8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485dd9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485dda  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485ddd  81fbff000000           +cmp ebx, 0xff
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485de3  7651                   -jbe 0x485e36
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00485e36;
    }
    // 00485de5  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00485de7  885d0b                 -mov byte ptr [ebp + 0xb], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(11) /* 0xb */) = cpu.bl;
    // 00485dea  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 00485ded  88450a                 -mov byte ptr [ebp + 0xa], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(10) /* 0xa */) = cpu.al;
    // 00485df0  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 00485df3  f680c11d520004         +test byte ptr [eax + 0x521dc1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381569) /* 0x521dc1 */) & 4 /*0x4*/));
    // 00485dfa  744f                   -je 0x485e4b
    if (cpu.flags.zf)
    {
        goto L_0x00485e4b;
    }
    // 00485dfc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00485dfe  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00485e01  ff35a81c5200           -push dword ptr [0x521ca8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381288) /* 0x521ca8 */);
    cpu.esp -= 4;
    // 00485e07  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00485e09  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485e0a  8d450a                 -lea eax, [ebp + 0xa]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(10) /* 0xa */);
    // 00485e0d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00485e0f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485e10  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00485e15  ff35c41e5200           -push dword ptr [0x521ec4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5381828) /* 0x521ec4 */);
    cpu.esp -= 4;
    // 00485e1b  e84572ffff             -call 0x47d065
    cpu.esp -= 4;
    sub_47d065(app, cpu);
    // 00485e20  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00485e23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485e25  7424                   -je 0x485e4b
    if (cpu.flags.zf)
    {
        goto L_0x00485e4b;
    }
    // 00485e27  0fb645fc               -movzx eax, byte ptr [ebp - 4]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 00485e2b  0fb64dfd               -movzx ecx, byte ptr [ebp - 3]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-3) /* -0x3 */));
    // 00485e2f  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00485e32  03c1                   +add eax, ecx
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
    // 00485e34  eb17                   -jmp 0x485e4d
    goto L_0x00485e4d;
L_0x00485e36:
    // 00485e36  8a83c11d5200           -mov al, byte ptr [ebx + 0x521dc1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5381569) /* 0x521dc1 */);
    // 00485e3c  2410                   -and al, 0x10
    cpu.al &= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00485e3e  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485e40  7509                   -jne 0x485e4b
    if (!cpu.flags.zf)
    {
        goto L_0x00485e4b;
    }
    // 00485e42  0fb683c01c5200         -movzx eax, byte ptr [ebx + 0x521cc0]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5381312) /* 0x521cc0 */));
    // 00485e49  eb02                   -jmp 0x485e4d
    goto L_0x00485e4d;
L_0x00485e4b:
    // 00485e4b  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00485e4d:
    // 00485e4d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e4e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485e50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485e51  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485e53  391dbc1c5200           +cmp dword ptr [0x521cbc], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5381308) /* 0x521cbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485e59  7511                   -jne 0x485e6c
    if (!cpu.flags.zf)
    {
        goto L_0x00485e6c;
    }
    // 00485e5b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00485e5f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00485e63  e898c9ffff             -call 0x482800
    cpu.esp -= 4;
    sub_482800(app, cpu);
    // 00485e68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e6a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485e6c:
    // 00485e6c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485e6d  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00485e6f  e8556cffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00485e74  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00485e78  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e79  381e                   +cmp byte ptr [esi], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485e7b  7455                   -je 0x485ed2
    if (cpu.flags.zf)
    {
        goto L_0x00485ed2;
    }
    // 00485e7d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485e7e  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
L_0x00485e82:
    // 00485e82  381f                   +cmp byte ptr [edi], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485e84  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00485e86  742f                   -je 0x485eb7
    if (cpu.flags.zf)
    {
        goto L_0x00485eb7;
    }
L_0x00485e88:
    // 00485e88  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00485e8a  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 00485e8d  f682c11d520004         +test byte ptr [edx + 0x521dc1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5381569) /* 0x521dc1 */) & 4 /*0x4*/));
    // 00485e94  7418                   -je 0x485eae
    if (cpu.flags.zf)
    {
        goto L_0x00485eae;
    }
    // 00485e96  3a0e                   +cmp cl, byte ptr [esi]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485e98  7508                   -jne 0x485ea2
    if (!cpu.flags.zf)
    {
        goto L_0x00485ea2;
    }
    // 00485e9a  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00485e9d  3a4e01                 +cmp cl, byte ptr [esi + 1]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485ea0  7415                   -je 0x485eb7
    if (cpu.flags.zf)
    {
        goto L_0x00485eb7;
    }
L_0x00485ea2:
    // 00485ea2  385801                 +cmp byte ptr [eax + 1], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485ea5  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00485ea8  740d                   -je 0x485eb7
    if (cpu.flags.zf)
    {
        goto L_0x00485eb7;
    }
    // 00485eaa  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485eac  eb04                   -jmp 0x485eb2
    goto L_0x00485eb2;
L_0x00485eae:
    // 00485eae  3a0e                   +cmp cl, byte ptr [esi]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485eb0  7405                   -je 0x485eb7
    if (cpu.flags.zf)
    {
        goto L_0x00485eb7;
    }
L_0x00485eb2:
    // 00485eb2  40                     -inc eax
    (cpu.eax)++;
    // 00485eb3  3818                   +cmp byte ptr [eax], bl
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
    // 00485eb5  75d1                   -jne 0x485e88
    if (!cpu.flags.zf)
    {
        goto L_0x00485e88;
    }
L_0x00485eb7:
    // 00485eb7  3818                   +cmp byte ptr [eax], bl
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
    // 00485eb9  7516                   -jne 0x485ed1
    if (!cpu.flags.zf)
    {
        goto L_0x00485ed1;
    }
    // 00485ebb  0fb606                 -movzx eax, byte ptr [esi]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 00485ebe  f680c11d520004         +test byte ptr [eax + 0x521dc1], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5381569) /* 0x521dc1 */) & 4 /*0x4*/));
    // 00485ec5  7405                   -je 0x485ecc
    if (cpu.flags.zf)
    {
        goto L_0x00485ecc;
    }
    // 00485ec7  46                     -inc esi
    (cpu.esi)++;
    // 00485ec8  381e                   +cmp byte ptr [esi], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485eca  7405                   -je 0x485ed1
    if (cpu.flags.zf)
    {
        goto L_0x00485ed1;
    }
L_0x00485ecc:
    // 00485ecc  46                     -inc esi
    (cpu.esi)++;
    // 00485ecd  381e                   +cmp byte ptr [esi], bl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485ecf  75b1                   -jne 0x485e82
    if (!cpu.flags.zf)
    {
        goto L_0x00485e82;
    }
L_0x00485ed1:
    // 00485ed1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00485ed2:
    // 00485ed2  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00485ed4  e8516cffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00485ed9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00485edb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485edc  f6d8                   +neg al
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
    // 00485ede  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00485ee0  23c6                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 00485ee2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ee3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ee4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485ee5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485ee5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485ee6  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00485ee8  e8dc6bffff             -call 0x47cac9
    cpu.esp -= 4;
    sub_47cac9(app, cpu);
    // 00485eed  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00485ef1  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00485ef5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00485ef7  e810000000             -call 0x485f0c
    cpu.esp -= 4;
    sub_485f0c(app, cpu);
    // 00485efc  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00485efe  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00485f00  e8256cffff             -call 0x47cb2a
    cpu.esp -= 4;
    sub_47cb2a(app, cpu);
    // 00485f05  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00485f08  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00485f0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485f0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485f0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485f0c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485f0d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00485f0f  81ec08010000           -sub esp, 0x108
    (cpu.esp) -= x86::reg32(x86::sreg32(264 /*0x108*/));
    // 00485f15  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485f16  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485f19  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00485f1b  7454                   -je 0x485f71
    if (cpu.flags.zf)
    {
        goto L_0x00485f71;
    }
    // 00485f1d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485f1e  e8be000000             -call 0x485fe1
    cpu.esp -= 4;
    sub_485fe1(app, cpu);
    // 00485f23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485f25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485f26  751b                   -jne 0x485f43
    if (!cpu.flags.zf)
    {
        goto L_0x00485f43;
    }
    // 00485f28  e88e85ffff             -call 0x47e4bb
    cpu.esp -= 4;
    sub_47e4bb(app, cpu);
    // 00485f2d  c7000f000000           -mov dword ptr [eax], 0xf
    app->getMemory<x86::reg32>(cpu.eax) = 15 /*0xf*/;
    // 00485f33  e87a85ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00485f38  c7000d000000           -mov dword ptr [eax], 0xd
    app->getMemory<x86::reg32>(cpu.eax) = 13 /*0xd*/;
L_0x00485f3e:
    // 00485f3e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00485f40:
    // 00485f40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485f41  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485f42  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485f43:
    // 00485f43  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00485f46  80650b00               -and byte ptr [ebp + 0xb], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(11) /* 0xb */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00485f4a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485f4b  8d85f8feffff           -lea eax, [ebp - 0x108]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-264) /* -0x108 */);
    // 00485f51  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485f52  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485f55  80c340                 +add bl, 0x40
    {
        x86::reg8& tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(64 /*0x40*/));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00485f58  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00485f5d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485f5e  885d08                 -mov byte ptr [ebp + 8], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.bl;
    // 00485f61  c645093a               -mov byte ptr [ebp + 9], 0x3a
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(9) /* 0x9 */) = 58 /*0x3a*/;
    // 00485f65  c6450a2e               -mov byte ptr [ebp + 0xa], 0x2e
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(10) /* 0xa */) = 46 /*0x2e*/;
    // 00485f69  ff15ac704800           -call dword ptr [0x4870ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747436) /* 0x4870ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00485f6f  eb12                   -jmp 0x485f83
    goto L_0x00485f83;
L_0x00485f71:
    // 00485f71  8d85f8feffff           -lea eax, [ebp - 0x108]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-264) /* -0x108 */);
    // 00485f77  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485f78  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00485f7d  ff15b0704800           -call dword ptr [0x4870b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747440) /* 0x4870b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00485f83:
    // 00485f83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485f85  74b7                   -je 0x485f3e
    if (cpu.flags.zf)
    {
        goto L_0x00485f3e;
    }
    // 00485f87  40                     -inc eax
    (cpu.eax)++;
    // 00485f88  3d04010000             +cmp eax, 0x104
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485f8d  77af                   -ja 0x485f3e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00485f3e;
    }
    // 00485f8f  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00485f92  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485f94  7522                   -jne 0x485fb8
    if (!cpu.flags.zf)
    {
        goto L_0x00485fb8;
    }
    // 00485f96  3b4510                 +cmp eax, dword ptr [ebp + 0x10]
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
    // 00485f99  7f03                   -jg 0x485f9e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00485f9e;
    }
    // 00485f9b  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
L_0x00485f9e:
    // 00485f9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485f9f  e8d612ffff             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 00485fa4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485fa5  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485fa7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485fa9  7522                   -jne 0x485fcd
    if (!cpu.flags.zf)
    {
        goto L_0x00485fcd;
    }
    // 00485fab  e80285ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00485fb0  c7000c000000           -mov dword ptr [eax], 0xc
    app->getMemory<x86::reg32>(cpu.eax) = 12 /*0xc*/;
    // 00485fb6  eb86                   -jmp 0x485f3e
    goto L_0x00485f3e;
L_0x00485fb8:
    // 00485fb8  3b4510                 +cmp eax, dword ptr [ebp + 0x10]
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
    // 00485fbb  7e10                   -jle 0x485fcd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00485fcd;
    }
    // 00485fbd  e8f084ffff             -call 0x47e4b2
    cpu.esp -= 4;
    sub_47e4b2(app, cpu);
    // 00485fc2  c70022000000           -mov dword ptr [eax], 0x22
    app->getMemory<x86::reg32>(cpu.eax) = 34 /*0x22*/;
    // 00485fc8  e971ffffff             -jmp 0x485f3e
    goto L_0x00485f3e;
L_0x00485fcd:
    // 00485fcd  8d85f8feffff           -lea eax, [ebp - 0x108]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-264) /* -0x108 */);
    // 00485fd3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485fd4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485fd5  e85692ffff             -call 0x47f230
    cpu.esp -= 4;
    sub_47f230(app, cpu);
    // 00485fda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485fdb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485fdc  e95fffffff             -jmp 0x485f40
    goto L_0x00485f40;
}

/* align: skip  */
void Application::sub_485fe1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485fe1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485fe2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00485fe4  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485fe7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485fe9  7424                   -je 0x48600f
    if (cpu.flags.zf)
    {
        goto L_0x0048600f;
    }
    // 00485feb  80650b00               -and byte ptr [ebp + 0xb], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(11) /* 0xb */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00485fef  0440                   -add al, 0x40
    (cpu.al) += x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00485ff1  884508                 -mov byte ptr [ebp + 8], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 00485ff4  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485ff7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485ff8  c645093a               -mov byte ptr [ebp + 9], 0x3a
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(9) /* 0x9 */) = 58 /*0x3a*/;
    // 00485ffc  c6450a5c               -mov byte ptr [ebp + 0xa], 0x5c
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(10) /* 0xa */) = 92 /*0x5c*/;
    // 00486000  ff1548704800           -call dword ptr [0x487048]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747336) /* 0x487048 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00486006  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486008  740a                   -je 0x486014
    if (cpu.flags.zf)
    {
        goto L_0x00486014;
    }
    // 0048600a  83f801                 +cmp eax, 1
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
    // 0048600d  7405                   -je 0x486014
    if (cpu.flags.zf)
    {
        goto L_0x00486014;
    }
L_0x0048600f:
    // 0048600f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00486011  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486012  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486013  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486014:
    // 00486014  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486016  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486017  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::Unwind_00486020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486020  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00486023  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486024  e8441dffff             -call 0x477d6d
    cpu.esp -= 4;
    sub_477d6d(app, cpu);
    // 00486029  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048602a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48602b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048602b  b820884800             -mov eax, 0x488820
    cpu.eax = 4753440 /*0x488820*/;
    // 00486030  e9de41ffff             -jmp 0x47a213
    return sub_47a213(app, cpu);
}

/* align: skip  */
void Application::Unwind_00486040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486040  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00486043  e9b89cfeff             -jmp 0x46fd00
    return sub_46fd00(app, cpu);
}

/* align: skip  */
void Application::sub_486048(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486048  b844884800             -mov eax, 0x488844
    cpu.eax = 4753476 /*0x488844*/;
    // 0048604d  e9c141ffff             -jmp 0x47a213
    return sub_47a213(app, cpu);
}

/* align: skip  */
void Application::Unwind_00486060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486060  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00486063  e9288efeff             -jmp 0x46ee90
    return sub_46ee90(app, cpu);
}

/* align: skip  */
void Application::sub_486068(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486068  b868884800             -mov eax, 0x488868
    cpu.eax = 4753512 /*0x488868*/;
    // 0048606d  e9a141ffff             -jmp 0x47a213
    return sub_47a213(app, cpu);
}

/* align: skip  */
void Application::Unwind_00486080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486080  8b4de4                 -mov ecx, dword ptr [ebp - 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00486083  e9088efeff             -jmp 0x46ee90
    return sub_46ee90(app, cpu);
}

/* align: skip  */
void Application::sub_486088(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486088  b88c884800             -mov eax, 0x48888c
    cpu.eax = 4753548 /*0x48888c*/;
    // 0048608d  e98141ffff             -jmp 0x47a213
    return sub_47a213(app, cpu);
}

/* align: skip  */
void Application::Unwind_004860a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004860a0  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004860a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004860a4  e8c41cffff             -call 0x477d6d
    cpu.esp -= 4;
    sub_477d6d(app, cpu);
    // 004860a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::Unwind_004860ab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004860ab  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004860ae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004860af  e8b91cffff             -call 0x477d6d
    cpu.esp -= 4;
    sub_477d6d(app, cpu);
    // 004860b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::Unwind_004860b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004860b6  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004860b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004860ba  e8ae1cffff             -call 0x477d6d
    cpu.esp -= 4;
    sub_477d6d(app, cpu);
    // 004860bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::Unwind_004860c1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004860c1  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004860c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004860c5  e8a31cffff             -call 0x477d6d
    cpu.esp -= 4;
    sub_477d6d(app, cpu);
    // 004860ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::Unwind_004860cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004860cc  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004860cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004860d0  e8981cffff             -call 0x477d6d
    cpu.esp -= 4;
    sub_477d6d(app, cpu);
    // 004860d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4860d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004860d7  b8d0884800             -mov eax, 0x4888d0
    cpu.eax = 4753616 /*0x4888d0*/;
    // 004860dc  e93241ffff             -jmp 0x47a213
    return sub_47a213(app, cpu);
}

}
