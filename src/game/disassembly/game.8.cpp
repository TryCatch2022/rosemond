#include "game.h"
namespace game
{

/* align: skip  */
void Application::sub_4291a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004291a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004291a1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004291a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004291a4  6838424900             -push 0x494238
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801080 /*0x494238*/;
    cpu.esp -= 4;
    // 004291a9  e809dc0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004291ae  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004291b1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004291b3  7507                   -jne 0x4291bc
    if (!cpu.flags.zf)
    {
        goto L_0x004291bc;
    }
    // 004291b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004291ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004291bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004291bc:
    // 004291bc  d94608                 -fld dword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 004291bf  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004291c2  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004291c5  6828424900             -push 0x494228
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801064 /*0x494228*/;
    cpu.esp -= 4;
    // 004291ca  e8e8db0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004291cf  d94608                 -fld dword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 004291d2  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 004291d8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004291db  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004291dd  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 004291e0  7a07                   -jp 0x4291e9
    if (cpu.flags.pf)
    {
        goto L_0x004291e9;
    }
    // 004291e2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004291e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004291e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004291e9:
    // 004291e9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004291eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004291ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4291f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004291f0  a16c125200             -mov eax, dword ptr [0x52126c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */);
    // 004291f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004291f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004291f7  6864424900             -push 0x494264
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801124 /*0x494264*/;
    cpu.esp -= 4;
    // 004291fc  e8b6db0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429201  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00429204  e837000000             -call 0x429240
    cpu.esp -= 4;
    sub_429240(app, cpu);
    // 00429209  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042920b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042920c  6854424900             -push 0x494254
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801108 /*0x494254*/;
    cpu.esp -= 4;
    // 00429211  e8a1db0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429216  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00429219  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042921b  7416                   -je 0x429233
    if (cpu.flags.zf)
    {
        goto L_0x00429233;
    }
    // 0042921d  d94608                 -fld dword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00429220  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00429223  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00429226  6840424900             -push 0x494240
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801088 /*0x494240*/;
    cpu.esp -= 4;
    // 0042922b  e887db0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429230  83c40c                 +add esp, 0xc
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
L_0x00429233:
    // 00429233  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00429235  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429236  e965ffffff             -jmp 0x4291a0
    return sub_4291a0(app, cpu);
}

/* align: skip  */
void Application::sub_429240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429240  a16c125200             -mov eax, dword ptr [0x52126c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */);
    // 00429245  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429247  7414                   -je 0x42925d
    if (cpu.flags.zf)
    {
        goto L_0x0042925d;
    }
    // 00429249  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042924a  6884424900             -push 0x494284
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801156 /*0x494284*/;
    cpu.esp -= 4;
    // 0042924f  e863db0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429254  a16c125200             -mov eax, dword ptr [0x52126c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */);
    // 00429259  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042925c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042925d:
    // 0042925d  6870424900             -push 0x494270
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801136 /*0x494270*/;
    cpu.esp -= 4;
    // 00429262  e850db0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429267  a168125200             -mov eax, dword ptr [0x521268]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378664) /* 0x521268 */);
    // 0042926c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042926f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429271  740d                   -je 0x429280
    if (cpu.flags.zf)
    {
        goto L_0x00429280;
    }
L_0x00429273:
    // 00429273  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00429276  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00429278  7408                   -je 0x429282
    if (cpu.flags.zf)
    {
        goto L_0x00429282;
    }
    // 0042927a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0042927c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042927e  75f3                   -jne 0x429273
    if (!cpu.flags.zf)
    {
        goto L_0x00429273;
    }
L_0x00429280:
    // 00429280  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00429282:
    // 00429282  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429290  81ec88010000           -sub esp, 0x188
    (cpu.esp) -= x86::reg32(x86::sreg32(392 /*0x188*/));
    // 00429296  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429297  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429298  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0042929a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042929b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042929c  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0042929e  e8faea0400             -call 0x477d9d
    cpu.esp -= 4;
    sub_477d9d(app, cpu);
    // 004292a3  8b84249c010000         -mov eax, dword ptr [esp + 0x19c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(412) /* 0x19c */);
    // 004292aa  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004292ad  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004292af  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004292b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004292b2  e819f3ffff             -call 0x4285d0
    cpu.esp -= 4;
    sub_4285d0(app, cpu);
    // 004292b7  68a8424900             -push 0x4942a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801192 /*0x4942a8*/;
    cpu.esp -= 4;
    // 004292bc  e8ffba0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 004292c1  8b8c24a0010000         -mov ecx, dword ptr [esp + 0x1a0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(416) /* 0x1a0 */);
    // 004292c8  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004292cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004292cd  6830414900             -push 0x494130
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800816 /*0x494130*/;
    cpu.esp -= 4;
    // 004292d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004292d3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004292d5  e81edb0400             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 004292da  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004292de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004292df  e8dcba0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 004292e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004292e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004292e6  8d4c2470               -lea ecx, [esp + 0x70]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004292ea  6818414900             -push 0x494118
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800792 /*0x494118*/;
    cpu.esp -= 4;
    // 004292ef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004292f0  e8c9eb0400             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 004292f5  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004292f8  8d542454               -lea edx, [esp + 0x54]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004292fc  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004292fe  e89d4bfeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00429303  8d349d00000000         -lea esi, [ebx*4]
    cpu.esi = x86::reg32(cpu.ebx * 4);
    // 0042930a  6810424900             -push 0x494210
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801040 /*0x494210*/;
    cpu.esp -= 4;
    // 0042930f  e8acba0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00429314  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00429317  8d4c7502               -lea ecx, [ebp + esi*2 + 2]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */ + cpu.esi * 2);
    // 0042931b  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042931d  e87e4bfeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00429322  68f0404900             -push 0x4940f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800752 /*0x4940f0*/;
    cpu.esp -= 4;
    // 00429327  e894ba0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0042932c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042932f  8d4c752c               -lea ecx, [ebp + esi*2 + 0x2c]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(44) /* 0x2c */ + cpu.esi * 2);
    // 00429333  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00429335  e8664bfeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 0042933a  68e0404900             -push 0x4940e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800736 /*0x4940e0*/;
    cpu.esp -= 4;
    // 0042933f  e87cba0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00429344  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00429347  8d4c753c               -lea ecx, [ebp + esi*2 + 0x3c]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(60) /* 0x3c */ + cpu.esi * 2);
    // 0042934b  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042934d  e84e4bfeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00429352  6804424900             -push 0x494204
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801028 /*0x494204*/;
    cpu.esp -= 4;
    // 00429357  e864ba0200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 0042935c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042935f  8d4c754e               -lea ecx, [ebp + esi*2 + 0x4e]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(78) /* 0x4e */ + cpu.esi * 2);
    // 00429363  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00429365  e8364bfeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 0042936a  a198125200             -mov eax, dword ptr [0x521298]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378712) /* 0x521298 */);
    // 0042936f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429371  0f8431010000           -je 0x4294a8
    if (cpu.flags.zf)
    {
        goto L_0x004294a8;
    }
    // 00429377  8d045b                 -lea eax, [ebx + ebx*2]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 2);
    // 0042937a  8d145b                 -lea edx, [ebx + ebx*2]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ebx * 2);
    // 0042937d  be60125200             -mov esi, 0x521260
    cpu.esi = 5378656 /*0x521260*/;
    // 00429382  03c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00429384  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429385  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00429389  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042938d  8d7c952c               -lea edi, [ebp + edx*4 + 0x2c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(44) /* 0x2c */ + cpu.edx * 4);
L_0x00429391:
    // 00429391  8b8424a0010000         -mov eax, dword ptr [esp + 0x1a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(416) /* 0x1a0 */);
    // 00429398  8b4e34                 -mov ecx, dword ptr [esi + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0042939b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042939c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042939d  68e8414900             -push 0x4941e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801000 /*0x4941e8*/;
    cpu.esp -= 4;
    // 004293a2  e810da0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004293a7  8b9424ac010000         -mov edx, dword ptr [esp + 0x1ac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(428) /* 0x1ac */);
    // 004293ae  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004293b1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004293b4  3bc2                   +cmp eax, edx
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
    // 004293b6  0f85c6000000           -jne 0x429482
    if (!cpu.flags.zf)
    {
        goto L_0x00429482;
    }
    // 004293bc  8b5638                 -mov edx, dword ptr [esi + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004293bf  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004293c1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004293c3  8d4c2460               -lea ecx, [esp + 0x60]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004293c7  e844f6ffff             -call 0x428a10
    cpu.esp -= 4;
    sub_428a10(app, cpu);
    // 004293cc  8d4fd4                 -lea ecx, [edi - 0x2c]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-44) /* -0x2c */);
    // 004293cf  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004293d3  e8c84afeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 004293d8  8b5638                 -mov edx, dword ptr [esi + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004293db  8d4c2458               -lea ecx, [esp + 0x58]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004293df  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 004293e1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004293e3  e828f6ffff             -call 0x428a10
    cpu.esp -= 4;
    sub_428a10(app, cpu);
    // 004293e8  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004293ec  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004293f0  03c3                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004293f2  8d4c45fc               -lea ecx, [ebp + eax*2 - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 2);
    // 004293f6  e8a54afeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 004293fb  8b4e30                 -mov ecx, dword ptr [esi + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004293fe  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00429402  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429403  6848414900             -push 0x494148
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800840 /*0x494148*/;
    cpu.esp -= 4;
    // 00429408  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00429409  e8ead90400             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0042940e  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00429412  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429413  e8a8b90200             -call 0x454dc0
    cpu.esp -= 4;
    sub_454dc0(app, cpu);
    // 00429418  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042941b  8d4fd6                 -lea ecx, [edi - 0x2a]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-42) /* -0x2a */);
    // 0042941e  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00429420  e87b4afeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00429425  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00429428  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429429  8d8c245c010000         -lea ecx, [esp + 0x15c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(348) /* 0x15c */);
    // 00429430  e85beaffff             -call 0x427e90
    cpu.esp -= 4;
    sub_427e90(app, cpu);
    // 00429435  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00429437  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00429439  e8624afeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 0042943e  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00429441  8d442458               -lea eax, [esp + 0x58]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00429445  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00429446  6898404900             -push 0x494098
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800664 /*0x494098*/;
    cpu.esp -= 4;
    // 0042944b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042944c  e86dea0400             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 00429451  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00429454  8d4f16                 -lea ecx, [edi + 0x16]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 00429457  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0042945b  e8404afeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
    // 00429460  8b4e2c                 -mov ecx, dword ptr [esi + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00429463  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00429467  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429468  6898404900             -push 0x494098
    app->getMemory<x86::reg32>(cpu.esp-4) = 4800664 /*0x494098*/;
    cpu.esp -= 4;
    // 0042946d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042946e  e84bea0400             -call 0x477ebe
    cpu.esp -= 4;
    sub_477ebe(app, cpu);
    // 00429473  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00429476  8d4f26                 -lea ecx, [edi + 0x26]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(38) /* 0x26 */);
    // 00429479  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0042947d  e81e4afeff             -call 0x40dea0
    cpu.esp -= 4;
    sub_40dea0(app, cpu);
L_0x00429482:
    // 00429482  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00429486  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042948a  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 0042948d  83c620                 -add esi, 0x20
    (cpu.esi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00429490  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00429492  03d3                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00429494  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00429497  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042949b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042949d  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 004294a1  0f85eafeffff           -jne 0x429391
    if (!cpu.flags.zf)
    {
        goto L_0x00429391;
    }
    // 004294a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004294a8:
    // 004294a8  8b0ddc125200           -mov ecx, dword ptr [0x5212dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378780) /* 0x5212dc */);
    // 004294ae  e81d000000             -call 0x4294d0
    cpu.esp -= 4;
    sub_4294d0(app, cpu);
    // 004294b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004294b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004294b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004294b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004294b8  740a                   -je 0x4294c4
    if (cpu.flags.zf)
    {
        goto L_0x004294c4;
    }
    // 004294ba  b960125200             -mov ecx, 0x521260
    cpu.ecx = 5378656 /*0x521260*/;
    // 004294bf  e88c010000             -call 0x429650
    cpu.esp -= 4;
    sub_429650(app, cpu);
L_0x004294c4:
    // 004294c4  81c488010000           -add esp, 0x188
    (cpu.esp) += x86::reg32(x86::sreg32(392 /*0x188*/));
    // 004294ca  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4294d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004294d0  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004294d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004294d4  740d                   -je 0x4294e3
    if (cpu.flags.zf)
    {
        goto L_0x004294e3;
    }
L_0x004294d6:
    // 004294d6  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004294d9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004294db  7408                   -je 0x4294e5
    if (cpu.flags.zf)
    {
        goto L_0x004294e5;
    }
    // 004294dd  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004294df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004294e1  75f3                   -jne 0x4294d6
    if (!cpu.flags.zf)
    {
        goto L_0x004294d6;
    }
L_0x004294e3:
    // 004294e3  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004294e5:
    // 004294e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4294f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004294f0  a110155200             -mov eax, dword ptr [0x521510]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5379344) /* 0x521510 */);
    // 004294f5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004294fa  83f807                 +cmp eax, 7
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
    // 004294fd  7f05                   -jg 0x429504
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00429504;
    }
    // 004294ff  83f801                 +cmp eax, 1
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
    // 00429502  7d74                   -jge 0x429578
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00429578;
    }
L_0x00429504:
    // 00429504  83f84c                 +cmp eax, 0x4c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429507  7c06                   -jl 0x42950f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042950f;
    }
    // 00429509  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0042950e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042950f:
    // 0042950f  83f849                 +cmp eax, 0x49
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(73 /*0x49*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429512  7c06                   -jl 0x42951a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042951a;
    }
    // 00429514  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00429519  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042951a:
    // 0042951a  83f846                 +cmp eax, 0x46
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(70 /*0x46*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042951d  7c06                   -jl 0x429525
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00429525;
    }
    // 0042951f  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00429524  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429525:
    // 00429525  83f843                 +cmp eax, 0x43
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
    // 00429528  7c06                   -jl 0x429530
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00429530;
    }
    // 0042952a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0042952f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429530:
    // 00429530  83f840                 +cmp eax, 0x40
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
    // 00429533  7d3e                   -jge 0x429573
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00429573;
    }
    // 00429535  83f820                 +cmp eax, 0x20
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
    // 00429538  7439                   -je 0x429573
    if (cpu.flags.zf)
    {
        goto L_0x00429573;
    }
    // 0042953a  83f821                 +cmp eax, 0x21
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042953d  7506                   -jne 0x429545
    if (!cpu.flags.zf)
    {
        goto L_0x00429545;
    }
    // 0042953f  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00429544  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429545:
    // 00429545  83f822                 +cmp eax, 0x22
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429548  7506                   -jne 0x429550
    if (!cpu.flags.zf)
    {
        goto L_0x00429550;
    }
    // 0042954a  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0042954f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429550:
    // 00429550  83f823                 +cmp eax, 0x23
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429553  7506                   -jne 0x42955b
    if (!cpu.flags.zf)
    {
        goto L_0x0042955b;
    }
    // 00429555  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0042955a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042955b:
    // 0042955b  83f824                 +cmp eax, 0x24
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042955e  7506                   -jne 0x429566
    if (!cpu.flags.zf)
    {
        goto L_0x00429566;
    }
    // 00429560  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00429565  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429566:
    // 00429566  68b8424900             -push 0x4942b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801208 /*0x4942b8*/;
    cpu.esp -= 4;
    // 0042956b  e847d80400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429570  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00429573:
    // 00429573  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00429578:
    // 00429578  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429580  e8fb660000             -call 0x42fc80
    cpu.esp -= 4;
    sub_42fc80(app, cpu);
    // 00429585  83e802                 +sub eax, 2
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
    // 00429588  740f                   -je 0x429599
    if (cpu.flags.zf)
    {
        goto L_0x00429599;
    }
    // 0042958a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042958b  7406                   -je 0x429593
    if (cpu.flags.zf)
    {
        goto L_0x00429593;
    }
    // 0042958d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00429592  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429593:
    // 00429593  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00429598  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429599:
    // 00429599  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0042959e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4295a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004295a0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004295a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004295a5  48                     -dec eax
    (cpu.eax)--;
    // 004295a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004295a7  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004295aa  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004295ac  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004295b1  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004295b3  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004295b5  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004295b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004295b8  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004295be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004295bf  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4295d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004295d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004295d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004295d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004295d3  c744240800000000       -mov dword ptr [esp + 8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004295db  8d710c                 -lea esi, [ecx + 0xc]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004295de  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
L_0x004295e3:
    // 004295e3  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004295e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004295e8  740d                   -je 0x4295f7
    if (cpu.flags.zf)
    {
        goto L_0x004295f7;
    }
    // 004295ea  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004295ec  83f81e                 +cmp eax, 0x1e
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
    // 004295ef  7d06                   -jge 0x4295f7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004295f7;
    }
    // 004295f1  01442408               +add dword ptr [esp + 8], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004295f5  eb13                   -jmp 0x42960a
    goto L_0x0042960a;
L_0x004295f7:
    // 004295f7  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 004295fb  d80520744800           -fadd dword ptr [0x487420]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748320) /* 0x487420 */));
    // 00429601  e88ad70400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 00429606  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0042960a:
    // 0042960a  83c620                 +add esi, 0x20
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042960d  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042960e  75d3                   -jne 0x4295e3
    if (!cpu.flags.zf)
    {
        goto L_0x004295e3;
    }
    // 00429610  db442408               -fild dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */))));
    // 00429614  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429615  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429616  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429617  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429620  e8abffffff             -call 0x4295d0
    cpu.esp -= 4;
    sub_4295d0(app, cpu);
    // 00429625  d80dc4784800           -fmul dword ptr [0x4878c4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749508) /* 0x4878c4 */));
    // 0042962b  d80dc0784800           -fmul dword ptr [0x4878c0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749504) /* 0x4878c0 */));
    // 00429631  d82d94744800           -fsubr dword ptr [0x487494]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */)) - cpu.fpu.st(0);
    // 00429637  d81534734800           -fcom dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 0042963d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042963f  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 00429642  7a08                   -jp 0x42964c
    if (cpu.flags.pf)
    {
        goto L_0x0042964c;
    }
    // 00429644  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00429646  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
L_0x0042964c:
    // 0042964c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429650  83c11c                 -add ecx, 0x1c
    (cpu.ecx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00429653  e8c8ffffff             -call 0x429620
    cpu.esp -= 4;
    sub_429620(app, cpu);
    // 00429658  d91d0c125200           -fstp dword ptr [0x52120c]
    app->getMemory<float>(x86::reg32(5378572) /* 0x52120c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042965e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429660  8d0449                 -lea eax, [ecx + ecx*2]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00429663  ff048520125200         -inc dword ptr [eax*4 + 0x521220]
    (app->getMemory<x86::reg32>(x86::reg32(5378592) /* 0x521220 */ + cpu.eax * 4))++;
    // 0042966a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429670  8d0449                 -lea eax, [ecx + ecx*2]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00429673  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00429676  8b8824125200           -mov ecx, dword ptr [eax + 0x521224]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5378596) /* 0x521224 */);
    // 0042967c  8b9020125200           -mov edx, dword ptr [eax + 0x521220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5378592) /* 0x521220 */);
    // 00429682  3bd1                   +cmp edx, ecx
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
    // 00429684  7e07                   -jle 0x42968d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042968d;
    }
    // 00429686  41                     -inc ecx
    (cpu.ecx)++;
    // 00429687  898824125200           -mov dword ptr [eax + 0x521224], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5378596) /* 0x521224 */) = cpu.ecx;
L_0x0042968d:
    // 0042968d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429690  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429691  8d0449                 -lea eax, [ecx + ecx*2]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00429694  8b0c8524125200         -mov ecx, dword ptr [eax*4 + 0x521224]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378596) /* 0x521224 */ + cpu.eax * 4);
    // 0042969b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042969d  8d048520125200         -lea eax, [eax*4 + 0x521220]
    cpu.eax = x86::reg32(x86::reg32(5378592) /* 0x521220 */ + cpu.eax * 4);
    // 004296a4  894c2400               -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004296a8  7517                   -jne 0x4296c1
    if (!cpu.flags.zf)
    {
        goto L_0x004296c1;
    }
    // 004296aa  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004296ad  7509                   -jne 0x4296b8
    if (!cpu.flags.zf)
    {
        goto L_0x004296b8;
    }
    // 004296af  c740080000803f         -mov dword ptr [eax + 8], 0x3f800000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 1065353216 /*0x3f800000*/;
    // 004296b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004296b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004296b8:
    // 004296b8  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004296bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004296c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004296c1:
    // 004296c1  db442400               -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004296c5  da30                   -fidiv dword ptr [eax]
    cpu.fpu.st(0) /= x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 004296c7  d95808                 -fstp dword ptr [eax + 8]
    app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004296ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004296cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4296d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004296d0  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004296d2  e8b9ffffff             -call 0x429690
    cpu.esp -= 4;
    sub_429690(app, cpu);
    // 004296d7  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004296dc  e8afffffff             -call 0x429690
    cpu.esp -= 4;
    sub_429690(app, cpu);
    // 004296e1  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004296e6  e9a5ffffff             -jmp 0x429690
    return sub_429690(app, cpu);
}

/* align: skip  */
void Application::sub_4296f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004296f0  d90534125200           -fld dword ptr [0x521234]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5378612) /* 0x521234 */)));
    // 004296f6  d80528125200           -fadd dword ptr [0x521228]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5378600) /* 0x521228 */));
    // 004296fc  d80db4754800           -fmul dword ptr [0x4875b4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748724) /* 0x4875b4 */));
    // 00429702  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429710  d90540125200           -fld dword ptr [0x521240]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5378624) /* 0x521240 */)));
    // 00429716  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429720  e8abffffff             -call 0x4296d0
    cpu.esp -= 4;
    sub_4296d0(app, cpu);
    // 00429725  e8e6ffffff             -call 0x429710
    cpu.esp -= 4;
    sub_429710(app, cpu);
    // 0042972a  d91d10125200           -fstp dword ptr [0x521210]
    app->getMemory<float>(x86::reg32(5378576) /* 0x521210 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00429730  e8bbffffff             -call 0x4296f0
    cpu.esp -= 4;
    sub_4296f0(app, cpu);
    // 00429735  d91d08125200           -fstp dword ptr [0x521208]
    app->getMemory<float>(x86::reg32(5378568) /* 0x521208 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042973b  e8a06fffff             -call 0x4206e0
    cpu.esp -= 4;
    sub_4206e0(app, cpu);
    // 00429740  d91504125200           -fst dword ptr [0x521204]
    app->getMemory<float>(x86::reg32(5378564) /* 0x521204 */) = float(cpu.fpu.st(0));
    // 00429746  d80d58744800           -fmul dword ptr [0x487458]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748376) /* 0x487458 */));
    // 0042974c  d80514125200           -fadd dword ptr [0x521214]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5378580) /* 0x521214 */));
    // 00429752  d80508125200           -fadd dword ptr [0x521208]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5378568) /* 0x521208 */));
    // 00429758  d80510125200           -fadd dword ptr [0x521210]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5378576) /* 0x521210 */));
    // 0042975e  d80dc8784800           -fmul dword ptr [0x4878c8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749512) /* 0x4878c8 */));
    // 00429764  d91500125200           -fst dword ptr [0x521200]
    app->getMemory<float>(x86::reg32(5378560) /* 0x521200 */) = float(cpu.fpu.st(0));
    // 0042976a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429770  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429771  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00429773  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429774  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429776  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00429778  6878125200             -push 0x521278
    app->getMemory<x86::reg32>(cpu.esp-4) = 5378680 /*0x521278*/;
    cpu.esp -= 4;
    // 0042977d  e81de00400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00429782  a178125200             -mov eax, dword ptr [0x521278]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378680) /* 0x521278 */);
    // 00429787  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042978a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042978c  743b                   -je 0x4297c9
    if (cpu.flags.zf)
    {
        goto L_0x004297c9;
    }
    // 0042978e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042978f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429790  8b3574125200           -mov esi, dword ptr [0x521274]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5378676) /* 0x521274 */);
    // 00429796  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00429798  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042979a  7415                   -je 0x4297b1
    if (cpu.flags.zf)
    {
        goto L_0x004297b1;
    }
L_0x0042979c:
    // 0042979c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042979d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042979f  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004297a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004297a2  e8f8df0400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 004297a7  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004297a9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004297ac  43                     -inc ebx
    (cpu.ebx)++;
    // 004297ad  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004297af  75eb                   -jne 0x42979c
    if (!cpu.flags.zf)
    {
        goto L_0x0042979c;
    }
L_0x004297b1:
    // 004297b1  a178125200             -mov eax, dword ptr [0x521278]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378680) /* 0x521278 */);
    // 004297b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004297b7  3bd8                   +cmp ebx, eax
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
    // 004297b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004297ba  740d                   -je 0x4297c9
    if (cpu.flags.zf)
    {
        goto L_0x004297c9;
    }
    // 004297bc  68d4424900             -push 0x4942d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801236 /*0x4942d4*/;
    cpu.esp -= 4;
    // 004297c1  e84ab4ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004297c6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004297c9:
    // 004297c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004297ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4297d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004297d0  a178125200             -mov eax, dword ptr [0x521278]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378680) /* 0x521278 */);
    // 004297d5  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004297d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004297da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004297db  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004297dd  740d                   -je 0x4297ec
    if (cpu.flags.zf)
    {
        goto L_0x004297ec;
    }
    // 004297df  6810434900             -push 0x494310
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801296 /*0x494310*/;
    cpu.esp -= 4;
    // 004297e4  e827b4ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 004297e9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004297ec:
    // 004297ec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004297ed  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004297ef  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004297f3  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004297f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004297f6  e88dde0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 004297fb  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004297ff  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429802  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429804  7512                   -jne 0x429818
    if (!cpu.flags.zf)
    {
        goto L_0x00429818;
    }
    // 00429806  68f8424900             -push 0x4942f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801272 /*0x4942f8*/;
    cpu.esp -= 4;
    // 0042980b  e8a7d50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429810  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00429813  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429814  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00429817  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429818:
    // 00429818  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429819  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042981b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042981d  7e30                   -jle 0x42984f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042984f;
    }
L_0x0042981f:
    // 0042981f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429820  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429822  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00429826  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00429828  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429829  e85ade0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0042982e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429831  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00429835  e846f3ffff             -call 0x428b80
    cpu.esp -= 4;
    sub_428b80(app, cpu);
    // 0042983a  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042983c  b960125200             -mov ecx, 0x521260
    cpu.ecx = 5378656 /*0x521260*/;
    // 00429841  e85af3ffff             -call 0x428ba0
    cpu.esp -= 4;
    sub_428ba0(app, cpu);
    // 00429846  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042984a  46                     -inc esi
    (cpu.esi)++;
    // 0042984b  3bf0                   +cmp esi, eax
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
    // 0042984d  7cd0                   -jl 0x42981f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042981f;
    }
L_0x0042984f:
    // 0042984f  8b0d74125200           -mov ecx, dword ptr [0x521274]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378676) /* 0x521274 */);
    // 00429855  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0042985a  e891edffff             -call 0x4285f0
    cpu.esp -= 4;
    sub_4285f0(app, cpu);
    // 0042985f  8b3574125200           -mov esi, dword ptr [0x521274]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5378676) /* 0x521274 */);
    // 00429865  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00429867  e8f4f3ffff             -call 0x428c60
    cpu.esp -= 4;
    sub_428c60(app, cpu);
    // 0042986c  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042986e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00429870  a378125200             -mov dword ptr [0x521278], eax
    app->getMemory<x86::reg32>(x86::reg32(5378680) /* 0x521278 */) = cpu.eax;
    // 00429875  e8d6f3ffff             -call 0x428c50
    cpu.esp -= 4;
    sub_428c50(app, cpu);
    // 0042987a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042987b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042987c  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0042987f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429880  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429881  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 00429886  b9f82c4900             -mov ecx, 0x492cf8
    cpu.ecx = 4795640 /*0x492cf8*/;
    // 0042988b  e8b0310200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 00429890  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00429892  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429894  7515                   -jne 0x4298ab
    if (!cpu.flags.zf)
    {
        goto L_0x004298ab;
    }
    // 00429896  683c434900             -push 0x49433c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801340 /*0x49433c*/;
    cpu.esp -= 4;
    // 0042989b  e817d50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004298a0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004298a3  8935dc125200           -mov dword ptr [0x5212dc], esi
    app->getMemory<x86::reg32>(x86::reg32(5378780) /* 0x5212dc */) = cpu.esi;
    // 004298a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004298aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004298ab:
    // 004298ab  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004298ad  e81effffff             -call 0x4297d0
    cpu.esp -= 4;
    sub_4297d0(app, cpu);
    // 004298b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004298b3  e81fdd0400             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 004298b8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004298bb  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 004298c0  b9a02d4900             -mov ecx, 0x492da0
    cpu.ecx = 4795808 /*0x492da0*/;
    // 004298c5  e876310200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 004298ca  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004298cc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004298ce  750f                   -jne 0x4298df
    if (!cpu.flags.zf)
    {
        goto L_0x004298df;
    }
    // 004298d0  683c434900             -push 0x49433c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801340 /*0x49433c*/;
    cpu.esp -= 4;
    // 004298d5  e8ddd40400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004298da  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004298dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004298de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004298df:
    // 004298df  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004298e1  e82a000000             -call 0x429910
    cpu.esp -= 4;
    sub_429910(app, cpu);
    // 004298e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004298e8  a3dc125200             -mov dword ptr [0x5212dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5378780) /* 0x5212dc */) = cpu.eax;
    // 004298ed  7407                   -je 0x4298f6
    if (cpu.flags.zf)
    {
        goto L_0x004298f6;
    }
    // 004298ef  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004298f1  e8aa020000             -call 0x429ba0
    cpu.esp -= 4;
    sub_429ba0(app, cpu);
L_0x004298f6:
    // 004298f6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004298f7  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004298f9  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004298fb  687c125200             -push 0x52127c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5378684 /*0x52127c*/;
    cpu.esp -= 4;
    // 00429900  e883dd0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00429905  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429906  e8ccdc0400             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0042990b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0042990e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042990f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429910  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00429913  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00429917  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429918  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429919  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042991b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042991c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042991d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042991f  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00429921  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429922  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00429924  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00429926  e85ddd0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0042992b  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042992f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429932  3bc5                   +cmp eax, ebp
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
    // 00429934  7509                   -jne 0x42993f
    if (!cpu.flags.zf)
    {
        goto L_0x0042993f;
    }
    // 00429936  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429937  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429938  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042993a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042993b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042993e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042993f:
    // 0042993f  3bc5                   +cmp eax, ebp
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
    // 00429941  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00429945  7e44                   -jle 0x42998b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042998b;
    }
    // 00429947  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x00429948:
    // 00429948  e863e9ffff             -call 0x4282b0
    cpu.esp -= 4;
    sub_4282b0(app, cpu);
    // 0042994d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042994f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429950  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429952  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00429954  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429955  e82edd0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0042995a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042995d  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042995f  e80c020000             -call 0x429b70
    cpu.esp -= 4;
    sub_429b70(app, cpu);
    // 00429964  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00429966  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0042996c  7502                   -jne 0x429970
    if (!cpu.flags.zf)
    {
        goto L_0x00429970;
    }
    // 0042996e  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x00429970:
    // 00429970  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00429972  7403                   -je 0x429977
    if (cpu.flags.zf)
    {
        goto L_0x00429977;
    }
    // 00429974  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
L_0x00429977:
    // 00429977  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042997b  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042997f  40                     -inc eax
    (cpu.eax)++;
    // 00429980  8bee                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00429982  3bc1                   +cmp eax, ecx
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
    // 00429984  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00429988  7cbe                   -jl 0x429948
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00429948;
    }
    // 0042998a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042998b:
    // 0042998b  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042998d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042998e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042998f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429990  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00429993  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4299a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004299a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004299a1  ba24c74800             -mov edx, 0x48c724
    cpu.edx = 4769572 /*0x48c724*/;
    // 004299a6  b9f82c4900             -mov ecx, 0x492cf8
    cpu.ecx = 4795640 /*0x492cf8*/;
    // 004299ab  e890300200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 004299b0  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004299b2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004299b4  750f                   -jne 0x4299c5
    if (!cpu.flags.zf)
    {
        goto L_0x004299c5;
    }
    // 004299b6  6858434900             -push 0x494358
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801368 /*0x494358*/;
    cpu.esp -= 4;
    // 004299bb  e8f7d30400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004299c0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004299c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004299c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004299c5:
    // 004299c5  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004299c7  e8a4fdffff             -call 0x429770
    cpu.esp -= 4;
    sub_429770(app, cpu);
    // 004299cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004299cd  e805dc0400             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 004299d2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004299d5  ba24c74800             -mov edx, 0x48c724
    cpu.edx = 4769572 /*0x48c724*/;
    // 004299da  b9a02d4900             -mov ecx, 0x492da0
    cpu.ecx = 4795808 /*0x492da0*/;
    // 004299df  e85c300200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 004299e4  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004299e6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004299e8  750f                   -jne 0x4299f9
    if (!cpu.flags.zf)
    {
        goto L_0x004299f9;
    }
    // 004299ea  6858434900             -push 0x494358
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801368 /*0x494358*/;
    cpu.esp -= 4;
    // 004299ef  e8c3d30400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 004299f4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004299f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004299f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004299f9:
    // 004299f9  8b15dc125200           -mov edx, dword ptr [0x5212dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5378780) /* 0x5212dc */);
    // 004299ff  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00429a01  e81a000000             -call 0x429a20
    cpu.esp -= 4;
    sub_429a20(app, cpu);
    // 00429a06  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429a07  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00429a09  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00429a0b  687c125200             -push 0x52127c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5378684 /*0x52127c*/;
    cpu.esp -= 4;
    // 00429a10  e88add0400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00429a15  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429a16  e8bcdb0400             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 00429a1b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00429a1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429a20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429a21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429a22  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00429a24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429a25  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00429a27  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429a29  c744240800000000       -mov dword ptr [esp + 8], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00429a31  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00429a33  740f                   -je 0x429a44
    if (cpu.flags.zf)
    {
        goto L_0x00429a44;
    }
L_0x00429a35:
    // 00429a35  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00429a39  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00429a3b  42                     -inc edx
    (cpu.edx)++;
    // 00429a3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429a3e  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00429a42  75f1                   -jne 0x429a35
    if (!cpu.flags.zf)
    {
        goto L_0x00429a35;
    }
L_0x00429a44:
    // 00429a44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429a45  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429a47  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00429a4b  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00429a4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429a4e  e84cdd0400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00429a53  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00429a57  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429a5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429a5c  7418                   -je 0x429a76
    if (cpu.flags.zf)
    {
        goto L_0x00429a76;
    }
    // 00429a5e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429a60  7414                   -je 0x429a76
    if (cpu.flags.zf)
    {
        goto L_0x00429a76;
    }
L_0x00429a62:
    // 00429a62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429a63  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429a65  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00429a67  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429a68  e832dd0400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00429a6d  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00429a6f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429a72  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429a74  75ec                   -jne 0x429a62
    if (!cpu.flags.zf)
    {
        goto L_0x00429a62;
    }
L_0x00429a76:
    // 00429a76  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a78  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429a79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429a80  8b0ddc125200           -mov ecx, dword ptr [0x5212dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378780) /* 0x5212dc */);
    // 00429a86  e905000000             -jmp 0x429a90
    return sub_429a90(app, cpu);
}

/* align: skip  */
void Application::sub_429a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429a90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429a91  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00429a93  740d                   -je 0x429aa2
    if (cpu.flags.zf)
    {
        goto L_0x00429aa2;
    }
L_0x00429a95:
    // 00429a95  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00429a98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429a9a  7413                   -je 0x429aaf
    if (cpu.flags.zf)
    {
        goto L_0x00429aaf;
    }
    // 00429a9c  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00429a9e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00429aa0  75f3                   -jne 0x429a95
    if (!cpu.flags.zf)
    {
        goto L_0x00429a95;
    }
L_0x00429aa2:
    // 00429aa2  8b442400               -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x00429aa6:
    // 00429aa6  83f80a                 +cmp eax, 0xa
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
    // 00429aa9  7e02                   -jle 0x429aad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00429aad;
    }
    // 00429aab  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
L_0x00429aad:
    // 00429aad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429aae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429aaf:
    // 00429aaf  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00429ab2  ebf2                   -jmp 0x429aa6
    goto L_0x00429aa6;
}

/* align: skip  */
void Application::sub_429ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429ac0  8b0d68125200           -mov ecx, dword ptr [0x521268]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378664) /* 0x521268 */);
    // 00429ac6  e9c5ffffff             -jmp 0x429a90
    return sub_429a90(app, cpu);
}

/* align: skip  */
void Application::sub_429ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429ad0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429ad1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00429ad3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429ad4  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00429ad6  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00429ad9  3bcf                   +cmp ecx, edi
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
    // 00429adb  740b                   -je 0x429ae8
    if (cpu.flags.zf)
    {
        goto L_0x00429ae8;
    }
    // 00429add  e87ee5ffff             -call 0x428060
    cpu.esp -= 4;
    sub_428060(app, cpu);
    // 00429ae2  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00429ae5  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x00429ae8:
    // 00429ae8  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00429aeb  3bcf                   +cmp ecx, edi
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
    // 00429aed  740b                   -je 0x429afa
    if (cpu.flags.zf)
    {
        goto L_0x00429afa;
    }
    // 00429aef  e86ce5ffff             -call 0x428060
    cpu.esp -= 4;
    sub_428060(app, cpu);
    // 00429af4  897e14                 -mov dword ptr [esi + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 00429af7  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
L_0x00429afa:
    // 00429afa  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00429afd  3bc7                   +cmp eax, edi
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
    // 00429aff  740c                   -je 0x429b0d
    if (cpu.flags.zf)
    {
        goto L_0x00429b0d;
    }
    // 00429b01  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429b02  e8add80400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 00429b07  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00429b0a  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x00429b0d:
    // 00429b0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429b0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429b0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429b10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429b11  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00429b13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429b14  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429b16  68e4000000             -push 0xe4
    app->getMemory<x86::reg32>(cpu.esp-4) = 228 /*0xe4*/;
    cpu.esp -= 4;
    // 00429b1b  6860125200             -push 0x521260
    app->getMemory<x86::reg32>(cpu.esp-4) = 5378656 /*0x521260*/;
    cpu.esp -= 4;
    // 00429b20  e87adc0400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00429b25  a16c125200             -mov eax, dword ptr [0x52126c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */);
    // 00429b2a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429b2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429b2f  7412                   -je 0x429b43
    if (cpu.flags.zf)
    {
        goto L_0x00429b43;
    }
    // 00429b31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429b32  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429b34  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00429b36  686c125200             -push 0x52126c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5378668 /*0x52126c*/;
    cpu.esp -= 4;
    // 00429b3b  e85fdc0400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00429b40  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00429b43:
    // 00429b43  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00429b45  e826fcffff             -call 0x429770
    cpu.esp -= 4;
    sub_429770(app, cpu);
    // 00429b4a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429b4b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429b4d  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 00429b4f  6800125200             -push 0x521200
    app->getMemory<x86::reg32>(cpu.esp-4) = 5378560 /*0x521200*/;
    cpu.esp -= 4;
    // 00429b54  e846dc0400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00429b59  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429b5a  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00429b5c  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00429b5e  6820125200             -push 0x521220
    app->getMemory<x86::reg32>(cpu.esp-4) = 5378592 /*0x521220*/;
    cpu.esp -= 4;
    // 00429b63  e837dc0400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00429b68  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00429b6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429b6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429b70  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00429b73  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00429b76  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 00429b79  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429b7a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00429b7d  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00429b80  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00429b83  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00429b84  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00429b87  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429b88  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00429b8b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00429b8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429b8d  6878434900             -push 0x494378
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801400 /*0x494378*/;
    cpu.esp -= 4;
    // 00429b92  e820d20400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429b97  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00429b9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429ba0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429ba1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00429ba3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429ba5  740d                   -je 0x429bb4
    if (cpu.flags.zf)
    {
        goto L_0x00429bb4;
    }
L_0x00429ba7:
    // 00429ba7  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00429ba9  e8c2ffffff             -call 0x429b70
    cpu.esp -= 4;
    sub_429b70(app, cpu);
    // 00429bae  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00429bb0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429bb2  75f3                   -jne 0x429ba7
    if (!cpu.flags.zf)
    {
        goto L_0x00429ba7;
    }
L_0x00429bb4:
    // 00429bb4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429bb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429bc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429bc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429bc1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429bc2  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00429bc4  b960125200             -mov ecx, 0x521260
    cpu.ecx = 5378656 /*0x521260*/;
    // 00429bc9  e802ffffff             -call 0x429ad0
    cpu.esp -= 4;
    sub_429ad0(app, cpu);
    // 00429bce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429bcf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429bd1  68e4000000             -push 0xe4
    app->getMemory<x86::reg32>(cpu.esp-4) = 228 /*0xe4*/;
    cpu.esp -= 4;
    // 00429bd6  6860125200             -push 0x521260
    app->getMemory<x86::reg32>(cpu.esp-4) = 5378656 /*0x521260*/;
    cpu.esp -= 4;
    // 00429bdb  e8a8da0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00429be0  a16c125200             -mov eax, dword ptr [0x52126c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */);
    // 00429be5  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00429be7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429bea  3bc3                   +cmp eax, ebx
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
    // 00429bec  741d                   -je 0x429c0b
    if (cpu.flags.zf)
    {
        goto L_0x00429c0b;
    }
    // 00429bee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429bef  e8bce6ffff             -call 0x4282b0
    cpu.esp -= 4;
    sub_4282b0(app, cpu);
    // 00429bf4  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00429bf6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429bf7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429bf9  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00429bfb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429bfc  e887da0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00429c01  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429c04  893d6c125200           -mov dword ptr [0x52126c], edi
    app->getMemory<x86::reg32>(x86::reg32(5378668) /* 0x52126c */) = cpu.edi;
    // 00429c0a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00429c0b:
    // 00429c0b  391d68125200           +cmp dword ptr [0x521268], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5378664) /* 0x521268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429c11  7413                   -je 0x429c26
    if (cpu.flags.zf)
    {
        goto L_0x00429c26;
    }
    // 00429c13  a170125200             -mov eax, dword ptr [0x521270]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378672) /* 0x521270 */);
    // 00429c18  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429c19  68c0434900             -push 0x4943c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801472 /*0x4943c0*/;
    cpu.esp -= 4;
    // 00429c1e  e894d10400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429c23  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00429c26:
    // 00429c26  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00429c28  891d68125200           -mov dword ptr [0x521268], ebx
    app->getMemory<x86::reg32>(x86::reg32(5378664) /* 0x521268 */) = cpu.ebx;
    // 00429c2e  891d70125200           -mov dword ptr [0x521270], ebx
    app->getMemory<x86::reg32>(x86::reg32(5378672) /* 0x521270 */) = cpu.ebx;
    // 00429c34  891d74125200           -mov dword ptr [0x521274], ebx
    app->getMemory<x86::reg32>(x86::reg32(5378676) /* 0x521274 */) = cpu.ebx;
    // 00429c3a  891d78125200           -mov dword ptr [0x521278], ebx
    app->getMemory<x86::reg32>(x86::reg32(5378680) /* 0x521278 */) = cpu.ebx;
    // 00429c40  e88bfbffff             -call 0x4297d0
    cpu.esp -= 4;
    sub_4297d0(app, cpu);
    // 00429c45  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429c46  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429c48  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 00429c4a  6800125200             -push 0x521200
    app->getMemory<x86::reg32>(cpu.esp-4) = 5378560 /*0x521200*/;
    cpu.esp -= 4;
    // 00429c4f  e834da0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00429c54  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429c55  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00429c57  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00429c59  6820125200             -push 0x521220
    app->getMemory<x86::reg32>(cpu.esp-4) = 5378592 /*0x521220*/;
    cpu.esp -= 4;
    // 00429c5e  e825da0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00429c63  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00429c66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429c67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429c68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429c70  a100125200             -mov eax, dword ptr [0x521200]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378560) /* 0x521200 */);
    // 00429c75  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429c76  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429c78  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00429c7a  6858d44a00             -push 0x4ad458
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904024 /*0x4ad458*/;
    cpu.esp -= 4;
    // 00429c7f  a358d44a00             -mov dword ptr [0x4ad458], eax
    app->getMemory<x86::reg32>(x86::reg32(4904024) /* 0x4ad458 */) = cpu.eax;
    // 00429c84  e816db0400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 00429c89  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429c8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429c90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429c91  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429c93  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00429c95  6858d44a00             -push 0x4ad458
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904024 /*0x4ad458*/;
    cpu.esp -= 4;
    // 00429c9a  e8e9d90400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 00429c9f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00429ca2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_46e520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0046e520;
L_0x00429cb0:
    // 00429cb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429cb1  ba24c74800             -mov edx, 0x48c724
    cpu.edx = 4769572 /*0x48c724*/;
    // 00429cb6  b91c444900             -mov ecx, 0x49441c
    cpu.ecx = 4801564 /*0x49441c*/;
    // 00429cbb  e8802d0200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 00429cc0  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00429cc2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429cc4  750f                   -jne 0x429cd5
    if (!cpu.flags.zf)
    {
        goto L_0x00429cd5;
    }
    // 00429cc6  68f0434900             -push 0x4943f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801520 /*0x4943f0*/;
    cpu.esp -= 4;
    // 00429ccb  e8e7d00400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429cd0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00429cd3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429cd4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429cd5:
    // 00429cd5  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00429cd7  e894ffffff             -call 0x429c70
    cpu.esp -= 4;
    sub_429c70(app, cpu);
    // 00429cdc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429cdd  e8f5d80400             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 00429ce2  83c404                 +add esp, 4
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
    // 00429ce5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429ce6  c3                     -ret 
    cpu.esp += 4;
    return;
L_entry_0x0046e520:
    // 0046e520  e85b07fbff             -call 0x41ec80
    cpu.esp -= 4;
    sub_41ec80(app, cpu);
    // 0046e525  e986b7fbff             -jmp 0x429cb0
    goto L_0x00429cb0;
}

/* align: skip  */
void Application::sub_429cf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429cf0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429cf1  ba08c74800             -mov edx, 0x48c708
    cpu.edx = 4769544 /*0x48c708*/;
    // 00429cf6  b91c444900             -mov ecx, 0x49441c
    cpu.ecx = 4801564 /*0x49441c*/;
    // 00429cfb  e8402d0200             -call 0x44ca40
    cpu.esp -= 4;
    sub_44ca40(app, cpu);
    // 00429d00  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00429d02  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429d04  750f                   -jne 0x429d15
    if (!cpu.flags.zf)
    {
        goto L_0x00429d15;
    }
    // 00429d06  682c444900             -push 0x49442c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801580 /*0x49442c*/;
    cpu.esp -= 4;
    // 00429d0b  e8a7d00400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429d10  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00429d13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429d14  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00429d15:
    // 00429d15  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00429d17  e874ffffff             -call 0x429c90
    cpu.esp -= 4;
    sub_429c90(app, cpu);
    // 00429d1c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429d1d  e8b5d80400             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 00429d22  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00429d25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429d26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00429d30  a190d34a00             -mov eax, dword ptr [0x4ad390]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4903824) /* 0x4ad390 */);
    // 00429d35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429d37  0f85b8000000           -jne 0x429df5
    if (!cpu.flags.zf)
    {
        goto L_0x00429df5;
    }
    // 00429d3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429d3e  e8adf4ffff             -call 0x4291f0
    cpu.esp -= 4;
    sub_4291f0(app, cpu);
    // 00429d43  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00429d45  e8a6f7ffff             -call 0x4294f0
    cpu.esp -= 4;
    sub_4294f0(app, cpu);
    // 00429d4a  48                     -dec eax
    (cpu.eax)--;
    // 00429d4b  83f804                 +cmp eax, 4
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
    // 00429d4e  7732                   -ja 0x429d82
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00429d82;
    }
    // 00429d50  ff2485f89d4200         -jmp dword ptr [eax*4 + 0x429df8]
    cpu.ip = app->getMemory<x86::reg32>(4365816 + cpu.eax * 4); goto dynamic_jump;
  case 0x00429d57:
    // 00429d57  c605ff3d490072         -mov byte ptr [0x493dff], 0x72
    app->getMemory<x86::reg8>(x86::reg32(4799999) /* 0x493dff */) = 114 /*0x72*/;
    // 00429d5e  eb22                   -jmp 0x429d82
    goto L_0x00429d82;
  case 0x00429d60:
    // 00429d60  c605ff3d49006d         -mov byte ptr [0x493dff], 0x6d
    app->getMemory<x86::reg8>(x86::reg32(4799999) /* 0x493dff */) = 109 /*0x6d*/;
    // 00429d67  eb19                   -jmp 0x429d82
    goto L_0x00429d82;
  case 0x00429d69:
    // 00429d69  c605ff3d490077         -mov byte ptr [0x493dff], 0x77
    app->getMemory<x86::reg8>(x86::reg32(4799999) /* 0x493dff */) = 119 /*0x77*/;
    // 00429d70  eb10                   -jmp 0x429d82
    goto L_0x00429d82;
  case 0x00429d72:
    // 00429d72  c605ff3d490073         -mov byte ptr [0x493dff], 0x73
    app->getMemory<x86::reg8>(x86::reg32(4799999) /* 0x493dff */) = 115 /*0x73*/;
    // 00429d79  eb07                   -jmp 0x429d82
    goto L_0x00429d82;
  case 0x00429d7b:
    // 00429d7b  c605ff3d490061         -mov byte ptr [0x493dff], 0x61
    app->getMemory<x86::reg8>(x86::reg32(4799999) /* 0x493dff */) = 97 /*0x61*/;
L_0x00429d82:
    // 00429d82  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00429d84  7534                   -jne 0x429dba
    if (!cpu.flags.zf)
    {
        goto L_0x00429dba;
    }
    // 00429d86  a1dc125200             -mov eax, dword ptr [0x5212dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5378780) /* 0x5212dc */);
    // 00429d8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429d8d  750d                   -jne 0x429d9c
    if (!cpu.flags.zf)
    {
        goto L_0x00429d9c;
    }
    // 00429d8f  6870444900             -push 0x494470
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801648 /*0x494470*/;
    cpu.esp -= 4;
    // 00429d94  e877aeffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 00429d99  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00429d9c:
    // 00429d9c  8b0ddc125200           -mov ecx, dword ptr [0x5212dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5378780) /* 0x5212dc */);
    // 00429da2  e8e9fcffff             -call 0x429a90
    cpu.esp -= 4;
    sub_429a90(app, cpu);
    // 00429da7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429da9  7e11                   -jle 0x429dbc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00429dbc;
    }
    // 00429dab  83f803                 +cmp eax, 3
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
    // 00429dae  7f0c                   -jg 0x429dbc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00429dbc;
    }
    // 00429db0  c605fd3d490077         -mov byte ptr [0x493dfd], 0x77
    app->getMemory<x86::reg8>(x86::reg32(4799997) /* 0x493dfd */) = 119 /*0x77*/;
    // 00429db7  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00429db8  eb09                   -jmp 0x429dc3
    goto L_0x00429dc3;
L_0x00429dba:
    // 00429dba  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00429dbc:
    // 00429dbc  c605fd3d49006c         -mov byte ptr [0x493dfd], 0x6c
    app->getMemory<x86::reg8>(x86::reg32(4799997) /* 0x493dfd */) = 108 /*0x6c*/;
L_0x00429dc3:
    // 00429dc3  f7d8                   +neg eax
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
    // 00429dc5  1ac0                   -sbb al, al
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.al) + cpu.flags.cf);
    // 00429dc7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429dc8  24fd                   -and al, 0xfd
    cpu.al &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 00429dca  68fc3d4900             -push 0x493dfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4799996 /*0x493dfc*/;
    cpu.esp -= 4;
    // 00429dcf  046d                   -add al, 0x6d
    (cpu.al) += x86::reg8(x86::sreg8(109 /*0x6d*/));
    // 00429dd1  6858444900             -push 0x494458
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801624 /*0x494458*/;
    cpu.esp -= 4;
    // 00429dd6  a2fe3d4900             -mov byte ptr [0x493dfe], al
    app->getMemory<x86::reg8>(x86::reg32(4799998) /* 0x493dfe */) = cpu.al;
    // 00429ddb  c605fc3d490061         -mov byte ptr [0x493dfc], 0x61
    app->getMemory<x86::reg8>(x86::reg32(4799996) /* 0x493dfc */) = 97 /*0x61*/;
    // 00429de2  e8d0cf0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429de7  83c40c                 +add esp, 0xc
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
    // 00429dea  b9fc3d4900             -mov ecx, 0x493dfc
    cpu.ecx = 4799996 /*0x493dfc*/;
    // 00429def  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429df0  e9db770000             -jmp 0x4315d0
    return sub_4315d0(app, cpu);
L_0x00429df5:
    // 00429df5  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_429e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429e10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429e11  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00429e15  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429e16  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429e17  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00429e19  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00429e1b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429e1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429e1d  68b0444900             -push 0x4944b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801712 /*0x4944b0*/;
    cpu.esp -= 4;
    // 00429e22  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00429e28  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00429e2f  e883cf0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429e34  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00429e37  81ff80020000           +cmp edi, 0x280
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(640 /*0x280*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429e3d  7d0e                   -jge 0x429e4d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00429e4d;
    }
    // 00429e3f  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 00429e44  2bc7                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00429e46  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00429e47  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00429e49  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00429e4b  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00429e4d:
    // 00429e4d  81fbe0010000           +cmp ebx, 0x1e0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(480 /*0x1e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00429e53  7d0f                   -jge 0x429e64
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00429e64;
    }
    // 00429e55  b8e0010000             -mov eax, 0x1e0
    cpu.eax = 480 /*0x1e0*/;
    // 00429e5a  2bc3                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00429e5c  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00429e5d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00429e5f  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00429e61  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00429e64:
    // 00429e64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429e65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429e66  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429e67  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_429e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429e70  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00429e73  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00429e75  8d542400               -lea edx, [esp]
    cpu.edx = x86::reg32(cpu.esp);
    // 00429e79  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00429e7d  89442400               -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00429e81  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00429e85  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00429e86  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00429e8a  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00429e8e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00429e92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00429e93  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00429e97  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 00429e9c  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00429ea0  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00429ea2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00429ea3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429ea4  ff515c                 -call dword ptr [ecx + 0x5c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00429ea7  f7d8                   +neg eax
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
    // 00429ea9  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00429eab  f7d8                   +neg eax
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
    // 00429ead  741f                   -je 0x429ece
    if (cpu.flags.zf)
    {
        goto L_0x00429ece;
    }
    // 00429eaf  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00429eb1  e88a0a0000             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 00429eb6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429eb7  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 00429ebc  e8f6ce0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429ec1  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 00429ec6  e89cda0400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 00429ecb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00429ece:
    // 00429ece  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00429ed2  8b4c2400               -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00429ed6  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00429ed8  2bd1                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00429eda  c1ea0a                 -shr edx, 0xa
    cpu.edx >>= 10 /*0xa*/ % 32;
    // 00429edd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00429ede  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00429ee0  c1ea0a                 -shr edx, 0xa
    cpu.edx >>= 10 /*0xa*/ % 32;
    // 00429ee3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00429ee4  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00429ee6  c1ea0a                 -shr edx, 0xa
    cpu.edx >>= 10 /*0xa*/ % 32;
    // 00429ee9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00429eea  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429eeb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429eec  68c8444900             -push 0x4944c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801736 /*0x4944c8*/;
    cpu.esp -= 4;
    // 00429ef1  e8c1ce0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429ef6  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00429efa  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00429efd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_429f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00429f00  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00429f03  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00429f04  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429f05  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00429f06  68dcca4800             -push 0x48cadc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770524 /*0x48cadc*/;
    cpu.esp -= 4;
    // 00429f0b  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00429f0d  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00429f0f  e8a3ce0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429f14  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00429f18  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00429f1b  891ddc1a5200           -mov dword ptr [0x521adc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5380828) /* 0x521adc */) = cpu.ebx;
    // 00429f21  68007f0000             -push 0x7f00
    app->getMemory<x86::reg32>(cpu.esp-4) = 32512 /*0x7f00*/;
    cpu.esp -= 4;
    // 00429f26  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00429f28  ff15e8714800           -call dword ptr [0x4871e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747752) /* 0x4871e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00429f2e  a3481a5200             -mov dword ptr [0x521a48], eax
    app->getMemory<x86::reg32>(x86::reg32(5380680) /* 0x521a48 */) = cpu.eax;
    // 00429f33  e8b88e0300             -call 0x462df0
    cpu.esp -= 4;
    sub_462df0(app, cpu);
    // 00429f38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429f39  ff15b0724800           -call dword ptr [0x4872b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747952) /* 0x4872b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00429f3f  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00429f41  6800e00f00             -push 0xfe000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1040384 /*0xfe000*/;
    cpu.esp -= 4;
    // 00429f46  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00429f47  ff15b8724800           -call dword ptr [0x4872b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747960) /* 0x4872b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00429f4d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429f4f  a360d44a00             -mov dword ptr [0x4ad460], eax
    app->getMemory<x86::reg32>(x86::reg32(4904032) /* 0x4ad460 */) = cpu.eax;
    // 00429f54  7518                   -jne 0x429f6e
    if (!cpu.flags.zf)
    {
        goto L_0x00429f6e;
    }
    // 00429f56  680c454900             -push 0x49450c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801804 /*0x49450c*/;
    cpu.esp -= 4;
    // 00429f5b  e857ce0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429f60  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00429f63  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00429f65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429f66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429f67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429f68  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00429f6b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00429f6e:
    // 00429f6e  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00429f71  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00429f74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00429f75  b984d44a00             -mov ecx, 0x4ad484
    cpu.ecx = 4904068 /*0x4ad484*/;
    // 00429f7a  e891feffff             -call 0x429e10
    cpu.esp -= 4;
    sub_429e10(app, cpu);
    // 00429f7f  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00429f81  e86a030000             -call 0x42a2f0
    cpu.esp -= 4;
    sub_42a2f0(app, cpu);
    // 00429f86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429f88  7510                   -jne 0x429f9a
    if (!cpu.flags.zf)
    {
        goto L_0x00429f9a;
    }
    // 00429f8a  e831070000             -call 0x42a6c0
    cpu.esp -= 4;
    sub_42a6c0(app, cpu);
    // 00429f8f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00429f91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429f92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429f93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00429f94  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00429f97  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00429f9a:
    // 00429f9a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00429f9b  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00429f9d  e83e150000             -call 0x42b4e0
    cpu.esp -= 4;
    sub_42b4e0(app, cpu);
    // 00429fa2  e8f9020000             -call 0x42a2a0
    cpu.esp -= 4;
    sub_42a2a0(app, cpu);
    // 00429fa7  e884b70300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 00429fac  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00429fae  688cca4800             -push 0x48ca8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770444 /*0x48ca8c*/;
    cpu.esp -= 4;
    // 00429fb3  e8ffcd0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 00429fb8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00429fbb  e8308b0300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 00429fc0  b139                   -mov cl, 0x39
    cpu.cl = 57 /*0x39*/;
    // 00429fc2  e8198c0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00429fc7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429fc9  0f85a4000000           -jne 0x42a073
    if (!cpu.flags.zf)
    {
        goto L_0x0042a073;
    }
    // 00429fcf  8b35e4714800           -mov esi, dword ptr [0x4871e4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4747748) /* 0x4871e4 */);
    // 00429fd5  8b3de0714800           -mov edi, dword ptr [0x4871e0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4747744) /* 0x4871e0 */);
    // 00429fdb  8b2ddc714800           -mov ebp, dword ptr [0x4871dc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4747740) /* 0x4871dc */);
L_0x00429fe1:
    // 00429fe1  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00429fe3  e8f88b0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00429fe8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429fea  0f8583000000           -jne 0x42a073
    if (!cpu.flags.zf)
    {
        goto L_0x0042a073;
    }
    // 00429ff0  b11c                   -mov cl, 0x1c
    cpu.cl = 28 /*0x1c*/;
    // 00429ff2  e8e98b0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 00429ff7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00429ff9  7578                   -jne 0x42a073
    if (!cpu.flags.zf)
    {
        goto L_0x0042a073;
    }
    // 00429ffb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00429ffd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429ffe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00429fff  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042a003  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a004  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042a005  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a007  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a009  7417                   -je 0x42a022
    if (cpu.flags.zf)
    {
        goto L_0x0042a022;
    }
    // 0042a00b  837c241412             +cmp dword ptr [esp + 0x14], 0x12
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
    // 0042a010  7461                   -je 0x42a073
    if (cpu.flags.zf)
    {
        goto L_0x0042a073;
    }
    // 0042a012  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042a016  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a017  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a019  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042a01d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042a01e  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a020  eb3d                   -jmp 0x42a05f
    goto L_0x0042a05f;
L_0x0042a022:
    // 0042a022  ff15d8714800           -call dword ptr [0x4871d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747736) /* 0x4871d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a028  3bd8                   +cmp ebx, eax
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
    // 0042a02a  7533                   -jne 0x42a05f
    if (!cpu.flags.zf)
    {
        goto L_0x0042a05f;
    }
    // 0042a02c  8b1560d44a00           -mov edx, dword ptr [0x4ad460]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904032) /* 0x4ad460 */);
    // 0042a032  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042a033  ff15b4724800           -call dword ptr [0x4872b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747956) /* 0x4872b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a039  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a03b  7522                   -jne 0x42a05f
    if (!cpu.flags.zf)
    {
        goto L_0x0042a05f;
    }
    // 0042a03d  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042a03f  e88c000000             -call 0x42a0d0
    cpu.esp -= 4;
    sub_42a0d0(app, cpu);
    // 0042a044  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a046  7512                   -jne 0x42a05a
    if (!cpu.flags.zf)
    {
        goto L_0x0042a05a;
    }
    // 0042a048  a160d44a00             -mov eax, dword ptr [0x4ad460]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904032) /* 0x4ad460 */);
    // 0042a04d  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0042a050  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042a053  e8e8140000             -call 0x42b540
    cpu.esp -= 4;
    sub_42b540(app, cpu);
    // 0042a058  eb05                   -jmp 0x42a05f
    goto L_0x0042a05f;
L_0x0042a05a:
    // 0042a05a  83f802                 +cmp eax, 2
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
    // 0042a05d  7514                   -jne 0x42a073
    if (!cpu.flags.zf)
    {
        goto L_0x0042a073;
    }
L_0x0042a05f:
    // 0042a05f  e88c8a0300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 0042a064  b139                   -mov cl, 0x39
    cpu.cl = 57 /*0x39*/;
    // 0042a066  e8758b0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0042a06b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a06d  0f846effffff           -je 0x429fe1
    if (cpu.flags.zf)
    {
        goto L_0x00429fe1;
    }
L_0x0042a073:
    // 0042a073  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042a074:
    // 0042a074  b139                   -mov cl, 0x39
    cpu.cl = 57 /*0x39*/;
    // 0042a076  e8658b0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0042a07b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a07d  7516                   -jne 0x42a095
    if (!cpu.flags.zf)
    {
        goto L_0x0042a095;
    }
    // 0042a07f  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 0042a081  e85a8b0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0042a086  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a088  750b                   -jne 0x42a095
    if (!cpu.flags.zf)
    {
        goto L_0x0042a095;
    }
    // 0042a08a  b11c                   -mov cl, 0x1c
    cpu.cl = 28 /*0x1c*/;
    // 0042a08c  e84f8b0300             -call 0x462be0
    cpu.esp -= 4;
    sub_462be0(app, cpu);
    // 0042a091  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a093  7407                   -je 0x42a09c
    if (cpu.flags.zf)
    {
        goto L_0x0042a09c;
    }
L_0x0042a095:
    // 0042a095  e8568a0300             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    // 0042a09a  ebd8                   -jmp 0x42a074
    goto L_0x0042a074;
L_0x0042a09c:
    // 0042a09c  6848ca4800             -push 0x48ca48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770376 /*0x48ca48*/;
    cpu.esp -= 4;
    // 0042a0a1  e811cd0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a0a6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042a0a9  e862140000             -call 0x42b510
    cpu.esp -= 4;
    sub_42b510(app, cpu);
    // 0042a0ae  680cca4800             -push 0x48ca0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770316 /*0x48ca0c*/;
    cpu.esp -= 4;
    // 0042a0b3  e8ffcc0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a0b8  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042a0bc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042a0bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a0c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a0c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a0c2  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042a0c5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_42a0d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a0d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a0d1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042a0d3  ff15d8714800           -call dword ptr [0x4871d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747736) /* 0x4871d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a0d9  3bc6                   +cmp eax, esi
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
    // 0042a0db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a0dc  0f85c3000000           -jne 0x42a1a5
    if (!cpu.flags.zf)
    {
        goto L_0x0042a1a5;
    }
    // 0042a0e2  a160d44a00             -mov eax, dword ptr [0x4ad460]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904032) /* 0x4ad460 */);
    // 0042a0e7  8b4868                 -mov ecx, dword ptr [eax + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 0042a0ea  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042a0ec  7405                   -je 0x42a0f3
    if (cpu.flags.zf)
    {
        goto L_0x0042a0f3;
    }
    // 0042a0ee  e8bd000000             -call 0x42a1b0
    cpu.esp -= 4;
    sub_42a1b0(app, cpu);
L_0x0042a0f3:
    // 0042a0f3  a174d44a00             -mov eax, dword ptr [0x4ad474]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904052) /* 0x4ad474 */);
    // 0042a0f8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a0fa  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042a0fc  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0042a101  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a103  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a105  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a106  ff5164                 -call dword ptr [ecx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a109  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a10b  742d                   -je 0x42a13a
    if (cpu.flags.zf)
    {
        goto L_0x0042a13a;
    }
L_0x0042a10d:
    // 0042a10d  a174d44a00             -mov eax, dword ptr [0x4ad474]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904052) /* 0x4ad474 */);
    // 0042a112  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a113  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a115  ff526c                 -call dword ptr [edx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a118  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a11a  0f8585000000           -jne 0x42a1a5
    if (!cpu.flags.zf)
    {
        goto L_0x0042a1a5;
    }
    // 0042a120  a174d44a00             -mov eax, dword ptr [0x4ad474]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904052) /* 0x4ad474 */);
    // 0042a125  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a127  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042a129  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0042a12e  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a130  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a132  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a133  ff5164                 -call dword ptr [ecx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a136  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a138  75d3                   -jne 0x42a10d
    if (!cpu.flags.zf)
    {
        goto L_0x0042a10d;
    }
L_0x0042a13a:
    // 0042a13a  8b15a0444900           -mov edx, dword ptr [0x4944a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4801696) /* 0x4944a0 */);
    // 0042a140  a1841a5200             -mov eax, dword ptr [0x521a84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380740) /* 0x521a84 */);
    // 0042a145  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042a146  8b15701a5200           -mov edx, dword ptr [0x521a70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5380720) /* 0x521a70 */);
    // 0042a14c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a14d  a160d44a00             -mov eax, dword ptr [0x4ad460]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904032) /* 0x4ad460 */);
    // 0042a152  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0042a155  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042a156  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042a157  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a159  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a15b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a15c  ff15c4724800           -call dword ptr [0x4872c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747972) /* 0x4872c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a162  a160d44a00             -mov eax, dword ptr [0x4ad460]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904032) /* 0x4ad460 */);
    // 0042a167  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a168  ff15c0724800           -call dword ptr [0x4872c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747968) /* 0x4872c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a16e  a174d44a00             -mov eax, dword ptr [0x4ad474]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904052) /* 0x4ad474 */);
    // 0042a173  c6058cd44a0001         -mov byte ptr [0x4ad48c], 1
    app->getMemory<x86::reg8>(x86::reg32(4904076) /* 0x4ad48c */) = 1 /*0x1*/;
    // 0042a17a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a17c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a17d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a17f  ff9180000000           -call dword ptr [ecx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a185  a160d44a00             -mov eax, dword ptr [0x4ad460]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904032) /* 0x4ad460 */);
    // 0042a18a  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0042a18d  8b8874030000           -mov ecx, dword ptr [eax + 0x374]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(884) /* 0x374 */);
    // 0042a193  4a                     -dec edx
    (cpu.edx)--;
    // 0042a194  3bca                   +cmp ecx, edx
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
    // 0042a196  7506                   -jne 0x42a19e
    if (!cpu.flags.zf)
    {
        goto L_0x0042a19e;
    }
    // 0042a198  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042a19d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a19e:
    // 0042a19e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a19f  ff15bc724800           -call dword ptr [0x4872bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747964) /* 0x4872bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042a1a5:
    // 0042a1a5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042a1a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42a1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a1b0  a160d44a00             -mov eax, dword ptr [0x4ad460]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904032) /* 0x4ad460 */);
    // 0042a1b5  b928000000             -mov ecx, 0x28
    cpu.ecx = 40 /*0x28*/;
    // 0042a1ba  058a000000             -add eax, 0x8a
    (cpu.eax) += x86::reg32(x86::sreg32(138 /*0x8a*/));
L_0x0042a1bf:
    // 0042a1bf  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042a1c1  40                     -inc eax
    (cpu.eax)++;
    // 0042a1c2  8891000e5200           -mov byte ptr [ecx + 0x520e00], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5377536) /* 0x520e00 */) = cpu.dl;
    // 0042a1c8  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042a1cb  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042a1cd  40                     -inc eax
    (cpu.eax)++;
    // 0042a1ce  8891fd0d5200           -mov byte ptr [ecx + 0x520dfd], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5377533) /* 0x520dfd */) = cpu.dl;
    // 0042a1d4  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042a1d6  40                     -inc eax
    (cpu.eax)++;
    // 0042a1d7  8891fe0d5200           -mov byte ptr [ecx + 0x520dfe], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5377534) /* 0x520dfe */) = cpu.dl;
    // 0042a1dd  81f9d8030000           +cmp ecx, 0x3d8
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(984 /*0x3d8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a1e3  72da                   -jb 0x42a1bf
    if (cpu.flags.cf)
    {
        goto L_0x0042a1bf;
    }
    // 0042a1e5  a180d44a00             -mov eax, dword ptr [0x4ad480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904064) /* 0x4ad480 */);
    // 0042a1ea  68000e5200             -push 0x520e00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5377536 /*0x520e00*/;
    cpu.esp -= 4;
    // 0042a1ef  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0042a1f4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a1f6  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a1f8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a1fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a1fb  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a1fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42a200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a200  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0042a206  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a207  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042a209  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042a20b  7517                   -jne 0x42a224
    if (!cpu.flags.zf)
    {
        goto L_0x0042a224;
    }
    // 0042a20d  6820454900             -push 0x494520
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801824 /*0x494520*/;
    cpu.esp -= 4;
    // 0042a212  e8a0cb0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a217  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042a21a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042a21c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a21d  81c484000000           -add esp, 0x84
    (cpu.esp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0042a223  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a224:
    // 0042a224  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042a226  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042a22a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042a22b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a22c  c744240c20000000       -mov dword ptr [esp + 0xc], 0x20
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 32 /*0x20*/;
    // 0042a234  ff5054                 -call dword ptr [eax + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a237  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a239  7526                   -jne 0x42a261
    if (!cpu.flags.zf)
    {
        goto L_0x0042a261;
    }
    // 0042a23b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042a23d  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 0042a241  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042a245  c744242464000000       -mov dword ptr [esp + 0x24], 0x64
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 100 /*0x64*/;
    // 0042a24d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a24e  6800040001             -push 0x1000400
    app->getMemory<x86::reg32>(cpu.esp-4) = 16778240 /*0x1000400*/;
    cpu.esp -= 4;
    // 0042a253  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a255  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a257  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a259  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a25a  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a25d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a25f  7429                   -je 0x42a28a
    if (cpu.flags.zf)
    {
        goto L_0x0042a28a;
    }
L_0x0042a261:
    // 0042a261  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042a263  e8d8060000             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042a268  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a269  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042a26e  e844cb0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a273  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042a278  e8ead60400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042a27d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042a280  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042a282  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a283  81c484000000           -add esp, 0x84
    (cpu.esp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0042a289  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a28a:
    // 0042a28a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042a28f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a290  81c484000000           -add esp, 0x84
    (cpu.esp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0042a296  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42a2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a2a0  6864454900             -push 0x494564
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801892 /*0x494564*/;
    cpu.esp -= 4;
    // 0042a2a5  e80dcb0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a2aa  8b0d74d44a00           -mov ecx, dword ptr [0x4ad474]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904052) /* 0x4ad474 */);
    // 0042a2b0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042a2b3  e848ffffff             -call 0x42a200
    cpu.esp -= 4;
    sub_42a200(app, cpu);
    // 0042a2b8  6850454900             -push 0x494550
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801872 /*0x494550*/;
    cpu.esp -= 4;
    // 0042a2bd  e8f5ca0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a2c2  8b0d70d44a00           -mov ecx, dword ptr [0x4ad470]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904048) /* 0x4ad470 */);
    // 0042a2c8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042a2cb  e830ffffff             -call 0x42a200
    cpu.esp -= 4;
    sub_42a200(app, cpu);
    // 0042a2d0  683c454900             -push 0x49453c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801852 /*0x49453c*/;
    cpu.esp -= 4;
    // 0042a2d5  e8ddca0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a2da  8b0d78d44a00           -mov ecx, dword ptr [0x4ad478]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904056) /* 0x4ad478 */);
    // 0042a2e0  83c404                 +add esp, 4
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
    // 0042a2e3  e918ffffff             -jmp 0x42a200
    return sub_42a200(app, cpu);
}

/* align: skip  */
void Application::sub_42a2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a2f0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a2f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042a2f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a2f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a2f6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a2f8  6864d44a00             -push 0x4ad464
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904036 /*0x4ad464*/;
    cpu.esp -= 4;
    // 0042a2fd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a2ff  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0042a301  e8306f0400             -call 0x471236
    cpu.esp -= 4;
    sub_471236(app, cpu);
    // 0042a306  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a308  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042a30a  743f                   -je 0x42a34b
    if (cpu.flags.zf)
    {
        goto L_0x0042a34b;
    }
    // 0042a30c  68b0cc4800             -push 0x48ccb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770992 /*0x48ccb0*/;
    cpu.esp -= 4;
L_0x0042a311:
    // 0042a311  e8a1ca0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a316  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042a319  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042a31b  e820060000             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042a320  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a321  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042a326  e88cca0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a32b  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042a330  e832d60400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042a335  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042a33a  e828d60400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042a33f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042a342  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042a344  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a345  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a346  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a347  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a34a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a34b:
    // 0042a34b  a164d44a00             -mov eax, dword ptr [0x4ad464]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904036) /* 0x4ad464 */);
    // 0042a350  6868d44a00             -push 0x4ad468
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904040 /*0x4ad468*/;
    cpu.esp -= 4;
    // 0042a355  68787c4800             -push 0x487c78
    app->getMemory<x86::reg32>(cpu.esp-4) = 4750456 /*0x487c78*/;
    cpu.esp -= 4;
    // 0042a35a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a35b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a35d  ff11                   -call dword ptr [ecx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a35f  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a361  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042a363  7407                   -je 0x42a36c
    if (cpu.flags.zf)
    {
        goto L_0x0042a36c;
    }
    // 0042a365  686ccc4800             -push 0x48cc6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770924 /*0x48cc6c*/;
    cpu.esp -= 4;
    // 0042a36a  eba5                   -jmp 0x42a311
    goto L_0x0042a311;
L_0x0042a36c:
    // 0042a36c  e8bfb30300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042a371  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042a376  dd5c240c               -fstp qword ptr [esp + 0xc]
    app->getMemory<double>(cpu.esp + x86::reg32(12) /* 0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042a37a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a37c  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 0042a37e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042a37f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a380  ff5250                 -call dword ptr [edx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a383  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a385  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042a387  742c                   -je 0x42a3b5
    if (cpu.flags.zf)
    {
        goto L_0x0042a3b5;
    }
L_0x0042a389:
    // 0042a389  e8a2b30300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042a38e  dc64240c               -fsub qword ptr [esp + 0xc]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 0042a392  dc1d78754800           -fcomp qword ptr [0x487578]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748664) /* 0x487578 */)));
    cpu.fpu.pop();
    // 0042a398  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042a39a  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042a39f  743f                   -je 0x42a3e0
    if (cpu.flags.zf)
    {
        goto L_0x0042a3e0;
    }
    // 0042a3a1  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042a3a6  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 0042a3a8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042a3a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a3aa  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a3ac  ff5150                 -call dword ptr [ecx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a3af  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a3b1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042a3b3  75d4                   -jne 0x42a389
    if (!cpu.flags.zf)
    {
        goto L_0x0042a389;
    }
L_0x0042a3b5:
    // 0042a3b5  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042a3ba  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a3bc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a3be  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0042a3c0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a3c2  68e0010000             -push 0x1e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 480 /*0x1e0*/;
    cpu.esp -= 4;
    // 0042a3c7  6880020000             -push 0x280
    app->getMemory<x86::reg32>(cpu.esp-4) = 640 /*0x280*/;
    cpu.esp -= 4;
    // 0042a3cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a3cd  ff5254                 -call dword ptr [edx + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a3d0  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a3d2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042a3d4  7414                   -je 0x42a3ea
    if (cpu.flags.zf)
    {
        goto L_0x0042a3ea;
    }
    // 0042a3d6  6854cc4800             -push 0x48cc54
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770900 /*0x48cc54*/;
    cpu.esp -= 4;
    // 0042a3db  e931ffffff             -jmp 0x42a311
    goto L_0x0042a311;
L_0x0042a3e0:
    // 0042a3e0  681ccc4800             -push 0x48cc1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770844 /*0x48cc1c*/;
    cpu.esp -= 4;
    // 0042a3e5  e927ffffff             -jmp 0x42a311
    goto L_0x0042a311;
L_0x0042a3ea:
    // 0042a3ea  b91f000000             -mov ecx, 0x1f
    cpu.ecx = 31 /*0x1f*/;
    // 0042a3ef  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042a3f1  bf601a5200             -mov edi, 0x521a60
    cpu.edi = 5380704 /*0x521a60*/;
    // 0042a3f6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a3f8  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042a3fa  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042a3ff  bf40400000             -mov edi, 0x4040
    cpu.edi = 16448 /*0x4040*/;
    // 0042a404  c705601a52007c000000   -mov dword ptr [0x521a60], 0x7c
    app->getMemory<x86::reg32>(x86::reg32(5380704) /* 0x521a60 */) = 124 /*0x7c*/;
    // 0042a40e  c705641a520007000000   -mov dword ptr [0x521a64], 7
    app->getMemory<x86::reg32>(x86::reg32(5380708) /* 0x521a64 */) = 7 /*0x7*/;
    // 0042a418  c705681a5200e0010000   -mov dword ptr [0x521a68], 0x1e0
    app->getMemory<x86::reg32>(x86::reg32(5380712) /* 0x521a68 */) = 480 /*0x1e0*/;
    // 0042a422  c7056c1a520080020000   -mov dword ptr [0x521a6c], 0x280
    app->getMemory<x86::reg32>(x86::reg32(5380716) /* 0x521a6c */) = 640 /*0x280*/;
    // 0042a42c  893dc81a5200           -mov dword ptr [0x521ac8], edi
    app->getMemory<x86::reg32>(x86::reg32(5380808) /* 0x521ac8 */) = cpu.edi;
    // 0042a432  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a434  6870d44a00             -push 0x4ad470
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904048 /*0x4ad470*/;
    cpu.esp -= 4;
    // 0042a439  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0042a43e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a43f  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a442  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a444  7450                   -je 0x42a496
    if (cpu.flags.zf)
    {
        goto L_0x0042a496;
    }
    // 0042a446  68eccb4800             -push 0x48cbec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770796 /*0x48cbec*/;
    cpu.esp -= 4;
    // 0042a44b  e867c90400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a450  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042a455  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042a458  c705c81a520040080000   -mov dword ptr [0x521ac8], 0x840
    app->getMemory<x86::reg32>(x86::reg32(5380808) /* 0x521ac8 */) = 2112 /*0x840*/;
    // 0042a462  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a464  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a466  6870d44a00             -push 0x4ad470
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904048 /*0x4ad470*/;
    cpu.esp -= 4;
    // 0042a46b  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0042a470  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a471  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a474  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a476  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042a478  741c                   -je 0x42a496
    if (cpu.flags.zf)
    {
        goto L_0x0042a496;
    }
    // 0042a47a  68cccb4800             -push 0x48cbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770764 /*0x48cbcc*/;
    cpu.esp -= 4;
    // 0042a47f  e833c90400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a484  68b0cb4800             -push 0x48cbb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770736 /*0x48cbb0*/;
    cpu.esp -= 4;
    // 0042a489  e829c90400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a48e  83c408                 +add esp, 8
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
    // 0042a491  e917010000             -jmp 0x42a5ad
    goto L_0x0042a5ad;
L_0x0042a496:
    // 0042a496  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042a49b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a49d  893dc81a5200           -mov dword ptr [0x521ac8], edi
    app->getMemory<x86::reg32>(x86::reg32(5380808) /* 0x521ac8 */) = cpu.edi;
    // 0042a4a3  6874d44a00             -push 0x4ad474
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904052 /*0x4ad474*/;
    cpu.esp -= 4;
    // 0042a4a8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a4aa  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0042a4af  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a4b0  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a4b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a4b5  7450                   -je 0x42a507
    if (cpu.flags.zf)
    {
        goto L_0x0042a507;
    }
    // 0042a4b7  6880cb4800             -push 0x48cb80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770688 /*0x48cb80*/;
    cpu.esp -= 4;
    // 0042a4bc  e8f6c80400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a4c1  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042a4c6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042a4c9  c705c81a520040080000   -mov dword ptr [0x521ac8], 0x840
    app->getMemory<x86::reg32>(x86::reg32(5380808) /* 0x521ac8 */) = 2112 /*0x840*/;
    // 0042a4d3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a4d5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a4d7  6874d44a00             -push 0x4ad474
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904052 /*0x4ad474*/;
    cpu.esp -= 4;
    // 0042a4dc  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0042a4e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a4e2  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a4e5  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a4e7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042a4e9  741c                   -je 0x42a507
    if (cpu.flags.zf)
    {
        goto L_0x0042a507;
    }
    // 0042a4eb  6860cb4800             -push 0x48cb60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770656 /*0x48cb60*/;
    cpu.esp -= 4;
    // 0042a4f0  e8c2c80400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a4f5  6844cb4800             -push 0x48cb44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770628 /*0x48cb44*/;
    cpu.esp -= 4;
    // 0042a4fa  e8b8c80400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a4ff  83c408                 +add esp, 8
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
    // 0042a502  e9a6000000             -jmp 0x42a5ad
    goto L_0x0042a5ad;
L_0x0042a507:
    // 0042a507  b91f000000             -mov ecx, 0x1f
    cpu.ecx = 31 /*0x1f*/;
    // 0042a50c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042a50e  bf601a5200             -mov edi, 0x521a60
    cpu.edi = 5380704 /*0x521a60*/;
    // 0042a513  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a515  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042a517  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042a51c  c705601a52007c000000   -mov dword ptr [0x521a60], 0x7c
    app->getMemory<x86::reg32>(x86::reg32(5380704) /* 0x521a60 */) = 124 /*0x7c*/;
    // 0042a526  c705641a520001000000   -mov dword ptr [0x521a64], 1
    app->getMemory<x86::reg32>(x86::reg32(5380708) /* 0x521a64 */) = 1 /*0x1*/;
    // 0042a530  c705c81a520000020000   -mov dword ptr [0x521ac8], 0x200
    app->getMemory<x86::reg32>(x86::reg32(5380808) /* 0x521ac8 */) = 512 /*0x200*/;
    // 0042a53a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a53c  6878d44a00             -push 0x4ad478
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904056 /*0x4ad478*/;
    cpu.esp -= 4;
    // 0042a541  68601a5200             -push 0x521a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5380704 /*0x521a60*/;
    cpu.esp -= 4;
    // 0042a546  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a547  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a54a  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a54c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042a54e  7407                   -je 0x42a557
    if (cpu.flags.zf)
    {
        goto L_0x0042a557;
    }
    // 0042a550  6824cb4800             -push 0x48cb24
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770596 /*0x48cb24*/;
    cpu.esp -= 4;
    // 0042a555  eb4e                   -jmp 0x42a5a5
    goto L_0x0042a5a5;
L_0x0042a557:
    // 0042a557  8b1578d44a00           -mov edx, dword ptr [0x4ad478]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904056) /* 0x4ad478 */);
    // 0042a55d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042a55e  ff15d0724800           -call dword ptr [0x4872d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747984) /* 0x4872d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a564  8b0d78d44a00           -mov ecx, dword ptr [0x4ad478]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904056) /* 0x4ad478 */);
    // 0042a56a  a3a0444900             -mov dword ptr [0x4944a0], eax
    app->getMemory<x86::reg32>(x86::reg32(4801696) /* 0x4944a0 */) = cpu.eax;
    // 0042a56f  a1481a5200             -mov eax, dword ptr [0x521a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5380680) /* 0x521a48 */);
    // 0042a574  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a575  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042a576  ff15cc724800           -call dword ptr [0x4872cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747980) /* 0x4872cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a57c  a34c1a5200             -mov dword ptr [0x521a4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5380684) /* 0x521a4c */) = cpu.eax;
    // 0042a581  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042a586  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a588  6880d44a00             -push 0x4ad480
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904064 /*0x4ad480*/;
    cpu.esp -= 4;
    // 0042a58d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a58f  68000e5200             -push 0x520e00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5377536 /*0x520e00*/;
    cpu.esp -= 4;
    // 0042a594  6a44                   -push 0x44
    app->getMemory<x86::reg32>(cpu.esp-4) = 68 /*0x44*/;
    cpu.esp -= 4;
    // 0042a596  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a597  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a59a  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a59c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042a59e  7435                   -je 0x42a5d5
    if (cpu.flags.zf)
    {
        goto L_0x0042a5d5;
    }
    // 0042a5a0  6894454900             -push 0x494594
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801940 /*0x494594*/;
    cpu.esp -= 4;
L_0x0042a5a5:
    // 0042a5a5  e80dc80400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a5aa  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042a5ad:
    // 0042a5ad  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042a5af  e88c030000             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042a5b4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a5b5  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042a5ba  e8f8c70400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a5bf  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042a5c4  e89ed30400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042a5c9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042a5cc  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042a5ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a5cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a5d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a5d1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a5d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a5d5:
    // 0042a5d5  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0042a5d7  e874000000             -call 0x42a650
    cpu.esp -= 4;
    sub_42a650(app, cpu);
    // 0042a5dc  a178d44a00             -mov eax, dword ptr [0x4ad478]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904056) /* 0x4ad478 */);
    // 0042a5e1  8b1580d44a00           -mov edx, dword ptr [0x4ad480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904064) /* 0x4ad480 */);
    // 0042a5e7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042a5e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a5e9  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a5eb  ff517c                 -call dword ptr [ecx + 0x7c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a5ee  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a5f0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042a5f2  742c                   -je 0x42a620
    if (cpu.flags.zf)
    {
        goto L_0x0042a620;
    }
    // 0042a5f4  6874454900             -push 0x494574
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801908 /*0x494574*/;
    cpu.esp -= 4;
    // 0042a5f9  e8b9c70400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a5fe  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042a601  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042a603  e838030000             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042a608  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a609  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042a60e  e8a4c70400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a613  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042a618  e84ad30400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042a61d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0042a620:
    // 0042a620  8b0d6cd44a00           -mov ecx, dword ptr [0x4ad46c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904044) /* 0x4ad46c */);
    // 0042a626  ba18cb4800             -mov edx, 0x48cb18
    cpu.edx = 4770584 /*0x48cb18*/;
    // 0042a62b  e860190000             -call 0x42bf90
    cpu.esp -= 4;
    sub_42bf90(app, cpu);
    // 0042a630  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042a632  a36cd44a00             -mov dword ptr [0x4ad46c], eax
    app->getMemory<x86::reg32>(x86::reg32(4904044) /* 0x4ad46c */) = cpu.eax;
    // 0042a637  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042a639  0f95c1                 -setne cl
    cpu.cl = !cpu.flags.zf;
    // 0042a63c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a63d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a63e  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042a640  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a641  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a644  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42a650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a650  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a651  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042a653  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a654  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a655  ff1500724800           -call dword ptr [0x487200]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747776) /* 0x487200 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a65b  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042a65d  68000e5200             -push 0x520e00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5377536 /*0x520e00*/;
    cpu.esp -= 4;
    // 0042a662  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0042a667  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042a669  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a66a  ff151c704800           -call dword ptr [0x48701c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747292) /* 0x48701c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a670  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042a672:
    // 0042a672  c60485030e520000       -mov byte ptr [eax*4 + 0x520e03], 0
    app->getMemory<x86::reg8>(x86::reg32(5377539) /* 0x520e03 */ + cpu.eax * 4) = 0 /*0x0*/;
    // 0042a67a  40                     -inc eax
    (cpu.eax)++;
    // 0042a67b  83f80a                 +cmp eax, 0xa
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
    // 0042a67e  7cf2                   -jl 0x42a672
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042a672;
    }
    // 0042a680  3df6000000             +cmp eax, 0xf6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(246 /*0xf6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a685  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0042a68a  7d0f                   -jge 0x42a69b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042a69b;
    }
L_0x0042a68c:
    // 0042a68c  880c85030e5200         -mov byte ptr [eax*4 + 0x520e03], cl
    app->getMemory<x86::reg8>(x86::reg32(5377539) /* 0x520e03 */ + cpu.eax * 4) = cpu.cl;
    // 0042a693  40                     -inc eax
    (cpu.eax)++;
    // 0042a694  3df6000000             +cmp eax, 0xf6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(246 /*0xf6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a699  7cf1                   -jl 0x42a68c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042a68c;
    }
L_0x0042a69b:
    // 0042a69b  3d00010000             +cmp eax, 0x100
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a6a0  7d13                   -jge 0x42a6b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042a6b5;
    }
    // 0042a6a2  8d0485030e5200         -lea eax, [eax*4 + 0x520e03]
    cpu.eax = x86::reg32(x86::reg32(5377539) /* 0x520e03 */ + cpu.eax * 4);
L_0x0042a6a9:
    // 0042a6a9  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 0042a6ac  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042a6ae  3d03125200             +cmp eax, 0x521203
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5378563 /*0x521203*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a6b3  7cf4                   -jl 0x42a6a9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042a6a9;
    }
L_0x0042a6b5:
    // 0042a6b5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a6b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a6b7  ff15fc714800           -call dword ptr [0x4871fc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747772) /* 0x4871fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a6bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a6be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a6bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42a6c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042a6c0  a180d44a00             -mov eax, dword ptr [0x4ad480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904064) /* 0x4ad480 */);
    // 0042a6c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a6c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042a6c7  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042a6c9  3bc7                   +cmp eax, edi
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
    // 0042a6cb  7441                   -je 0x42a70e
    if (cpu.flags.zf)
    {
        goto L_0x0042a70e;
    }
    // 0042a6cd  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a6cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a6d0  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a6d3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a6d5  3bf7                   +cmp esi, edi
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
    // 0042a6d7  742f                   -je 0x42a708
    if (cpu.flags.zf)
    {
        goto L_0x0042a708;
    }
    // 0042a6d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a6da  688c464900             -push 0x49468c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4802188 /*0x49468c*/;
    cpu.esp -= 4;
    // 0042a6df  e8d3c60400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a6e4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a6e7  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042a6e9  e852020000             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042a6ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a6ef  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042a6f4  e8bec60400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a6f9  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042a6fe  e864d20400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042a703  83c40c                 +add esp, 0xc
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
    // 0042a706  eb06                   -jmp 0x42a70e
    goto L_0x0042a70e;
L_0x0042a708:
    // 0042a708  893d80d44a00           -mov dword ptr [0x4ad480], edi
    app->getMemory<x86::reg32>(x86::reg32(4904064) /* 0x4ad480 */) = cpu.edi;
L_0x0042a70e:
    // 0042a70e  a16cd44a00             -mov eax, dword ptr [0x4ad46c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904044) /* 0x4ad46c */);
    // 0042a713  3bc7                   +cmp eax, edi
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
    // 0042a715  7441                   -je 0x42a758
    if (cpu.flags.zf)
    {
        goto L_0x0042a758;
    }
    // 0042a717  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a719  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a71a  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a71d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a71f  3bf7                   +cmp esi, edi
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
    // 0042a721  742f                   -je 0x42a752
    if (cpu.flags.zf)
    {
        goto L_0x0042a752;
    }
    // 0042a723  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a724  6870464900             -push 0x494670
    app->getMemory<x86::reg32>(cpu.esp-4) = 4802160 /*0x494670*/;
    cpu.esp -= 4;
    // 0042a729  e889c60400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a72e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a731  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042a733  e808020000             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042a738  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a739  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042a73e  e874c60400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a743  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042a748  e81ad20400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042a74d  83c40c                 +add esp, 0xc
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
    // 0042a750  eb06                   -jmp 0x42a758
    goto L_0x0042a758;
L_0x0042a752:
    // 0042a752  893d6cd44a00           -mov dword ptr [0x4ad46c], edi
    app->getMemory<x86::reg32>(x86::reg32(4904044) /* 0x4ad46c */) = cpu.edi;
L_0x0042a758:
    // 0042a758  a174d44a00             -mov eax, dword ptr [0x4ad474]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904052) /* 0x4ad474 */);
    // 0042a75d  3bc7                   +cmp eax, edi
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
    // 0042a75f  7441                   -je 0x42a7a2
    if (cpu.flags.zf)
    {
        goto L_0x0042a7a2;
    }
    // 0042a761  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a763  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a764  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a767  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a769  3bf7                   +cmp esi, edi
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
    // 0042a76b  742f                   -je 0x42a79c
    if (cpu.flags.zf)
    {
        goto L_0x0042a79c;
    }
    // 0042a76d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a76e  684c464900             -push 0x49464c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4802124 /*0x49464c*/;
    cpu.esp -= 4;
    // 0042a773  e83fc60400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a778  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a77b  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042a77d  e8be010000             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042a782  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a783  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042a788  e82ac60400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a78d  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042a792  e8d0d10400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042a797  83c40c                 +add esp, 0xc
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
    // 0042a79a  eb06                   -jmp 0x42a7a2
    goto L_0x0042a7a2;
L_0x0042a79c:
    // 0042a79c  893d74d44a00           -mov dword ptr [0x4ad474], edi
    app->getMemory<x86::reg32>(x86::reg32(4904052) /* 0x4ad474 */) = cpu.edi;
L_0x0042a7a2:
    // 0042a7a2  a170d44a00             -mov eax, dword ptr [0x4ad470]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904048) /* 0x4ad470 */);
    // 0042a7a7  3bc7                   +cmp eax, edi
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
    // 0042a7a9  7441                   -je 0x42a7ec
    if (cpu.flags.zf)
    {
        goto L_0x0042a7ec;
    }
    // 0042a7ab  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a7ad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a7ae  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a7b1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a7b3  3bf7                   +cmp esi, edi
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
    // 0042a7b5  742f                   -je 0x42a7e6
    if (cpu.flags.zf)
    {
        goto L_0x0042a7e6;
    }
    // 0042a7b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a7b8  6828464900             -push 0x494628
    app->getMemory<x86::reg32>(cpu.esp-4) = 4802088 /*0x494628*/;
    cpu.esp -= 4;
    // 0042a7bd  e8f5c50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a7c2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a7c5  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042a7c7  e874010000             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042a7cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a7cd  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042a7d2  e8e0c50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a7d7  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042a7dc  e886d10400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042a7e1  83c40c                 +add esp, 0xc
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
    // 0042a7e4  eb06                   -jmp 0x42a7ec
    goto L_0x0042a7ec;
L_0x0042a7e6:
    // 0042a7e6  893d70d44a00           -mov dword ptr [0x4ad470], edi
    app->getMemory<x86::reg32>(x86::reg32(4904048) /* 0x4ad470 */) = cpu.edi;
L_0x0042a7ec:
    // 0042a7ec  a178d44a00             -mov eax, dword ptr [0x4ad478]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904056) /* 0x4ad478 */);
    // 0042a7f1  3bc7                   +cmp eax, edi
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
    // 0042a7f3  7441                   -je 0x42a836
    if (cpu.flags.zf)
    {
        goto L_0x0042a836;
    }
    // 0042a7f5  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a7f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a7f8  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a7fb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a7fd  3bf7                   +cmp esi, edi
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
    // 0042a7ff  742f                   -je 0x42a830
    if (cpu.flags.zf)
    {
        goto L_0x0042a830;
    }
    // 0042a801  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a802  6800464900             -push 0x494600
    app->getMemory<x86::reg32>(cpu.esp-4) = 4802048 /*0x494600*/;
    cpu.esp -= 4;
    // 0042a807  e8abc50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a80c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a80f  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042a811  e82a010000             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042a816  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a817  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042a81c  e896c50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a821  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042a826  e83cd10400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042a82b  83c40c                 +add esp, 0xc
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
    // 0042a82e  eb06                   -jmp 0x42a836
    goto L_0x0042a836;
L_0x0042a830:
    // 0042a830  893d78d44a00           -mov dword ptr [0x4ad478], edi
    app->getMemory<x86::reg32>(x86::reg32(4904056) /* 0x4ad478 */) = cpu.edi;
L_0x0042a836:
    // 0042a836  a17cd44a00             -mov eax, dword ptr [0x4ad47c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904060) /* 0x4ad47c */);
    // 0042a83b  3bc7                   +cmp eax, edi
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
    // 0042a83d  7441                   -je 0x42a880
    if (cpu.flags.zf)
    {
        goto L_0x0042a880;
    }
    // 0042a83f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a841  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a842  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a845  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a847  3bf7                   +cmp esi, edi
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
    // 0042a849  742f                   -je 0x42a87a
    if (cpu.flags.zf)
    {
        goto L_0x0042a87a;
    }
    // 0042a84b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a84c  68e8454900             -push 0x4945e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4802024 /*0x4945e8*/;
    cpu.esp -= 4;
    // 0042a851  e861c50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a856  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a859  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042a85b  e8e0000000             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042a860  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a861  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042a866  e84cc50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a86b  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042a870  e8f2d00400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042a875  83c40c                 +add esp, 0xc
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
    // 0042a878  eb06                   -jmp 0x42a880
    goto L_0x0042a880;
L_0x0042a87a:
    // 0042a87a  893d7cd44a00           -mov dword ptr [0x4ad47c], edi
    app->getMemory<x86::reg32>(x86::reg32(4904060) /* 0x4ad47c */) = cpu.edi;
L_0x0042a880:
    // 0042a880  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042a885  3bc7                   +cmp eax, edi
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
    // 0042a887  7462                   -je 0x42a8eb
    if (cpu.flags.zf)
    {
        goto L_0x0042a8eb;
    }
    // 0042a889  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a88b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a88c  ff514c                 -call dword ptr [ecx + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a88f  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042a894  8b0ddc1a5200           -mov ecx, dword ptr [0x521adc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5380828) /* 0x521adc */);
    // 0042a89a  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0042a89c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042a89d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a89f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a8a0  ff5250                 -call dword ptr [edx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a8a3  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042a8a8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a8a9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a8ab  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a8ae  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a8b0  3bf7                   +cmp esi, edi
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
    // 0042a8b2  7431                   -je 0x42a8e5
    if (cpu.flags.zf)
    {
        goto L_0x0042a8e5;
    }
    // 0042a8b4  7e35                   -jle 0x42a8eb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042a8eb;
    }
    // 0042a8b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a8b7  68c8454900             -push 0x4945c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801992 /*0x4945c8*/;
    cpu.esp -= 4;
    // 0042a8bc  e8f6c40400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a8c1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a8c4  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042a8c6  e875000000             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042a8cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a8cc  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042a8d1  e8e1c40400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a8d6  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042a8db  e887d00400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042a8e0  83c40c                 +add esp, 0xc
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
    // 0042a8e3  eb06                   -jmp 0x42a8eb
    goto L_0x0042a8eb;
L_0x0042a8e5:
    // 0042a8e5  893d68d44a00           -mov dword ptr [0x4ad468], edi
    app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */) = cpu.edi;
L_0x0042a8eb:
    // 0042a8eb  a164d44a00             -mov eax, dword ptr [0x4ad464]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904036) /* 0x4ad464 */);
    // 0042a8f0  3bc7                   +cmp eax, edi
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
    // 0042a8f2  7442                   -je 0x42a936
    if (cpu.flags.zf)
    {
        goto L_0x0042a936;
    }
    // 0042a8f4  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042a8f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a8f7  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042a8fa  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042a8fc  3bf7                   +cmp esi, edi
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
    // 0042a8fe  7430                   -je 0x42a930
    if (cpu.flags.zf)
    {
        goto L_0x0042a930;
    }
    // 0042a900  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042a901  68a8454900             -push 0x4945a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4801960 /*0x4945a8*/;
    cpu.esp -= 4;
    // 0042a906  e8acc40400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a90b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042a90e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042a910  e82b000000             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042a915  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042a916  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042a91b  e897c40400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042a920  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042a925  e83dd00400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042a92a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042a92d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a92e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a92f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a930:
    // 0042a930  893d64d44a00           -mov dword ptr [0x4ad464], edi
    app->getMemory<x86::reg32>(x86::reg32(4904036) /* 0x4ad464 */) = cpu.edi;
L_0x0042a936:
    // 0042a936  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a937  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042a938  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42a940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0042a940  81f9c2017688           +cmp ecx, 0x887601c2
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435074 /*0x887601c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a946  0f8f1a020000           -jg 0x42ab66
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042ab66;
    }
    // 0042a94c  0f840e020000           -je 0x42ab60
    if (cpu.flags.zf)
    {
        goto L_0x0042ab60;
    }
    // 0042a952  81f9e1007688           +cmp ecx, 0x887600e1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289434849 /*0x887600e1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a958  0f8f40010000           -jg 0x42aa9e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042aa9e;
    }
    // 0042a95e  0f8434010000           -je 0x42aa98
    if (cpu.flags.zf)
    {
        goto L_0x0042aa98;
    }
    // 0042a964  81f96e007688           +cmp ecx, 0x8876006e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289434734 /*0x8876006e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a96a  0f8fbc000000           -jg 0x42aa2c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042aa2c;
    }
    // 0042a970  0f84b0000000           -je 0x42aa26
    if (cpu.flags.zf)
    {
        goto L_0x0042aa26;
    }
    // 0042a976  81f90a007688           +cmp ecx, 0x8876000a
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289434634 /*0x8876000a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a97c  7f66                   -jg 0x42a9e4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042a9e4;
    }
    // 0042a97e  745e                   -je 0x42a9de
    if (cpu.flags.zf)
    {
        goto L_0x0042a9de;
    }
    // 0042a980  81f90e000780           +cmp ecx, 0x8007000e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942414 /*0x8007000e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a986  7f36                   -jg 0x42a9be
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042a9be;
    }
    // 0042a988  742e                   -je 0x42a9b8
    if (cpu.flags.zf)
    {
        goto L_0x0042a9b8;
    }
    // 0042a98a  81f901400080           +cmp ecx, 0x80004001
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147500033 /*0x80004001*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a990  7420                   -je 0x42a9b2
    if (cpu.flags.zf)
    {
        goto L_0x0042a9b2;
    }
    // 0042a992  81f905400080           +cmp ecx, 0x80004005
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147500037 /*0x80004005*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a998  7412                   -je 0x42a9ac
    if (cpu.flags.zf)
    {
        goto L_0x0042a9ac;
    }
    // 0042a99a  81f9f0010480           +cmp ecx, 0x800401f0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147746288 /*0x800401f0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a9a0  0f8590030000           -jne 0x42ad36
    if (!cpu.flags.zf)
    {
        goto L_0x0042ad36;
    }
    // 0042a9a6  b8306b4900             -mov eax, 0x496b30
    cpu.eax = 4811568 /*0x496b30*/;
    // 0042a9ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a9ac:
    // 0042a9ac  b8086b4900             -mov eax, 0x496b08
    cpu.eax = 4811528 /*0x496b08*/;
    // 0042a9b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a9b2:
    // 0042a9b2  b8e46a4900             -mov eax, 0x496ae4
    cpu.eax = 4811492 /*0x496ae4*/;
    // 0042a9b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a9b8:
    // 0042a9b8  b8a06a4900             -mov eax, 0x496aa0
    cpu.eax = 4811424 /*0x496aa0*/;
    // 0042a9bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a9be:
    // 0042a9be  81f957000780           +cmp ecx, 0x80070057
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942487 /*0x80070057*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a9c4  7412                   -je 0x42a9d8
    if (cpu.flags.zf)
    {
        goto L_0x0042a9d8;
    }
    // 0042a9c6  81f905007688           +cmp ecx, 0x88760005
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289434629 /*0x88760005*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a9cc  0f8564030000           -jne 0x42ad36
    if (!cpu.flags.zf)
    {
        goto L_0x0042ad36;
    }
    // 0042a9d2  b8746a4900             -mov eax, 0x496a74
    cpu.eax = 4811380 /*0x496a74*/;
    // 0042a9d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a9d8:
    // 0042a9d8  b8306a4900             -mov eax, 0x496a30
    cpu.eax = 4811312 /*0x496a30*/;
    // 0042a9dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a9de:
    // 0042a9de  b8f4694900             -mov eax, 0x4969f4
    cpu.eax = 4811252 /*0x4969f4*/;
    // 0042a9e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042a9e4:
    // 0042a9e4  8d81ecff8977           -lea eax, [ecx + 0x7789ffec]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2005532652) /* 0x7789ffec */);
    // 0042a9ea  83f850                 +cmp eax, 0x50
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042a9ed  0f8743030000           -ja 0x42ad36
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042ad36;
    }
    // 0042a9f3  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0042a9f5  8a886cad4200           -mov cl, byte ptr [eax + 0x42ad6c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4369772) /* 0x42ad6c */);
    // 0042a9fb  ff248d50ad4200         -jmp dword ptr [ecx*4 + 0x42ad50]
    cpu.ip = app->getMemory<x86::reg32>(4369744 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0042aa02:
    // 0042aa02  b8b4694900             -mov eax, 0x4969b4
    cpu.eax = 4811188 /*0x4969b4*/;
    // 0042aa07  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa08:
    // 0042aa08  b890694900             -mov eax, 0x496990
    cpu.eax = 4811152 /*0x496990*/;
    // 0042aa0d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa0e:
    // 0042aa0e  b848694900             -mov eax, 0x496948
    cpu.eax = 4811080 /*0x496948*/;
    // 0042aa13  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa14:
    // 0042aa14  b8f0684900             -mov eax, 0x4968f0
    cpu.eax = 4810992 /*0x4968f0*/;
    // 0042aa19  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa1a:
    // 0042aa1a  b898684900             -mov eax, 0x496898
    cpu.eax = 4810904 /*0x496898*/;
    // 0042aa1f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa20:
    // 0042aa20  b840684900             -mov eax, 0x496840
    cpu.eax = 4810816 /*0x496840*/;
    // 0042aa25  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042aa26:
    // 0042aa26  b804684900             -mov eax, 0x496804
    cpu.eax = 4810756 /*0x496804*/;
    // 0042aa2b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042aa2c:
    // 0042aa2c  8d8188ff8977           -lea eax, [ecx + 0x7789ff88]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2005532552) /* 0x7789ff88 */);
    // 0042aa32  83f866                 +cmp eax, 0x66
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(102 /*0x66*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042aa35  0f87fb020000           -ja 0x42ad36
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042ad36;
    }
    // 0042aa3b  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0042aa3d  8a90f8ad4200           -mov dl, byte ptr [eax + 0x42adf8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4369912) /* 0x42adf8 */);
    // 0042aa43  ff2495c0ad4200         -jmp dword ptr [edx*4 + 0x42adc0]
    cpu.ip = app->getMemory<x86::reg32>(4369856 + cpu.edx * 4); goto dynamic_jump;
  case 0x0042aa4a:
    // 0042aa4a  b8d0674900             -mov eax, 0x4967d0
    cpu.eax = 4810704 /*0x4967d0*/;
    // 0042aa4f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa50:
    // 0042aa50  b888674900             -mov eax, 0x496788
    cpu.eax = 4810632 /*0x496788*/;
    // 0042aa55  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa56:
    // 0042aa56  b85c674900             -mov eax, 0x49675c
    cpu.eax = 4810588 /*0x49675c*/;
    // 0042aa5b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa5c:
    // 0042aa5c  b834674900             -mov eax, 0x496734
    cpu.eax = 4810548 /*0x496734*/;
    // 0042aa61  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa62:
    // 0042aa62  b8e0664900             -mov eax, 0x4966e0
    cpu.eax = 4810464 /*0x4966e0*/;
    // 0042aa67  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa68:
    // 0042aa68  b8b4664900             -mov eax, 0x4966b4
    cpu.eax = 4810420 /*0x4966b4*/;
    // 0042aa6d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa6e:
    // 0042aa6e  b848664900             -mov eax, 0x496648
    cpu.eax = 4810312 /*0x496648*/;
    // 0042aa73  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa74:
    // 0042aa74  b82c664900             -mov eax, 0x49662c
    cpu.eax = 4810284 /*0x49662c*/;
    // 0042aa79  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa7a:
    // 0042aa7a  b8c8654900             -mov eax, 0x4965c8
    cpu.eax = 4810184 /*0x4965c8*/;
    // 0042aa7f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa80:
    // 0042aa80  b894654900             -mov eax, 0x496594
    cpu.eax = 4810132 /*0x496594*/;
    // 0042aa85  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa86:
    // 0042aa86  b828654900             -mov eax, 0x496528
    cpu.eax = 4810024 /*0x496528*/;
    // 0042aa8b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa8c:
    // 0042aa8c  b8c8644900             -mov eax, 0x4964c8
    cpu.eax = 4809928 /*0x4964c8*/;
    // 0042aa91  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aa92:
    // 0042aa92  b880644900             -mov eax, 0x496480
    cpu.eax = 4809856 /*0x496480*/;
    // 0042aa97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042aa98:
    // 0042aa98  b808644900             -mov eax, 0x496408
    cpu.eax = 4809736 /*0x496408*/;
    // 0042aa9d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042aa9e:
    // 0042aa9e  8d811aff8977           -lea eax, [ecx + 0x7789ff1a]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2005532442) /* 0x7789ff1a */);
    // 0042aaa4  3dd2000000             +cmp eax, 0xd2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(210 /*0xd2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042aaa9  0f8787020000           -ja 0x42ad36
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042ad36;
    }
    // 0042aaaf  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0042aab1  8a88d0ae4200           -mov cl, byte ptr [eax + 0x42aed0]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4370128) /* 0x42aed0 */);
    // 0042aab7  ff248d60ae4200         -jmp dword ptr [ecx*4 + 0x42ae60]
    cpu.ip = app->getMemory<x86::reg32>(4370016 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0042aabe:
    // 0042aabe  b898634900             -mov eax, 0x496398
    cpu.eax = 4809624 /*0x496398*/;
    // 0042aac3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aac4:
    // 0042aac4  b860634900             -mov eax, 0x496360
    cpu.eax = 4809568 /*0x496360*/;
    // 0042aac9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aaca:
    // 0042aaca  b830634900             -mov eax, 0x496330
    cpu.eax = 4809520 /*0x496330*/;
    // 0042aacf  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aad0:
    // 0042aad0  b81c634900             -mov eax, 0x49631c
    cpu.eax = 4809500 /*0x49631c*/;
    // 0042aad5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aad6:
    // 0042aad6  b8c0624900             -mov eax, 0x4962c0
    cpu.eax = 4809408 /*0x4962c0*/;
    // 0042aadb  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aadc:
    // 0042aadc  b860624900             -mov eax, 0x496260
    cpu.eax = 4809312 /*0x496260*/;
    // 0042aae1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aae2:
    // 0042aae2  b8f0614900             -mov eax, 0x4961f0
    cpu.eax = 4809200 /*0x4961f0*/;
    // 0042aae7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aae8:
    // 0042aae8  b890614900             -mov eax, 0x496190
    cpu.eax = 4809104 /*0x496190*/;
    // 0042aaed  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aaee:
    // 0042aaee  b830614900             -mov eax, 0x496130
    cpu.eax = 4809008 /*0x496130*/;
    // 0042aaf3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aaf4:
    // 0042aaf4  b8b0604900             -mov eax, 0x4960b0
    cpu.eax = 4808880 /*0x4960b0*/;
    // 0042aaf9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aafa:
    // 0042aafa  b820604900             -mov eax, 0x496020
    cpu.eax = 4808736 /*0x496020*/;
    // 0042aaff  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab00:
    // 0042ab00  b8a05f4900             -mov eax, 0x495fa0
    cpu.eax = 4808608 /*0x495fa0*/;
    // 0042ab05  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab06:
    // 0042ab06  b8385f4900             -mov eax, 0x495f38
    cpu.eax = 4808504 /*0x495f38*/;
    // 0042ab0b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab0c:
    // 0042ab0c  b8105f4900             -mov eax, 0x495f10
    cpu.eax = 4808464 /*0x495f10*/;
    // 0042ab11  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab12:
    // 0042ab12  b8985e4900             -mov eax, 0x495e98
    cpu.eax = 4808344 /*0x495e98*/;
    // 0042ab17  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab18:
    // 0042ab18  b8f05d4900             -mov eax, 0x495df0
    cpu.eax = 4808176 /*0x495df0*/;
    // 0042ab1d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab1e:
    // 0042ab1e  b8705d4900             -mov eax, 0x495d70
    cpu.eax = 4808048 /*0x495d70*/;
    // 0042ab23  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab24:
    // 0042ab24  b8205d4900             -mov eax, 0x495d20
    cpu.eax = 4807968 /*0x495d20*/;
    // 0042ab29  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab2a:
    // 0042ab2a  b8d05c4900             -mov eax, 0x495cd0
    cpu.eax = 4807888 /*0x495cd0*/;
    // 0042ab2f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab30:
    // 0042ab30  b8485c4900             -mov eax, 0x495c48
    cpu.eax = 4807752 /*0x495c48*/;
    // 0042ab35  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab36:
    // 0042ab36  b8145c4900             -mov eax, 0x495c14
    cpu.eax = 4807700 /*0x495c14*/;
    // 0042ab3b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab3c:
    // 0042ab3c  b8c85b4900             -mov eax, 0x495bc8
    cpu.eax = 4807624 /*0x495bc8*/;
    // 0042ab41  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab42:
    // 0042ab42  b8705b4900             -mov eax, 0x495b70
    cpu.eax = 4807536 /*0x495b70*/;
    // 0042ab47  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab48:
    // 0042ab48  b8105b4900             -mov eax, 0x495b10
    cpu.eax = 4807440 /*0x495b10*/;
    // 0042ab4d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab4e:
    // 0042ab4e  b8a05a4900             -mov eax, 0x495aa0
    cpu.eax = 4807328 /*0x495aa0*/;
    // 0042ab53  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab54:
    // 0042ab54  b8485a4900             -mov eax, 0x495a48
    cpu.eax = 4807240 /*0x495a48*/;
    // 0042ab59  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab5a:
    // 0042ab5a  b8005a4900             -mov eax, 0x495a00
    cpu.eax = 4807168 /*0x495a00*/;
    // 0042ab5f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ab60:
    // 0042ab60  b850594900             -mov eax, 0x495950
    cpu.eax = 4806992 /*0x495950*/;
    // 0042ab65  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ab66:
    // 0042ab66  81f942027688           +cmp ecx, 0x88760242
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435202 /*0x88760242*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ab6c  0f8fcc000000           -jg 0x42ac3e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042ac3e;
    }
    // 0042ab72  0f84c0000000           -je 0x42ac38
    if (cpu.flags.zf)
    {
        goto L_0x0042ac38;
    }
    // 0042ab78  8d8134fe8977           -lea eax, [ecx + 0x7789fe34]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2005532212) /* 0x7789fe34 */);
    // 0042ab7e  83f875                 +cmp eax, 0x75
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(117 /*0x75*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ab81  0f87af010000           -ja 0x42ad36
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042ad36;
    }
    // 0042ab87  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0042ab89  8a9014b04200           -mov dl, byte ptr [eax + 0x42b014]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4370452) /* 0x42b014 */);
    // 0042ab8f  ff2495a4af4200         -jmp dword ptr [edx*4 + 0x42afa4]
    cpu.ip = app->getMemory<x86::reg32>(4370340 + cpu.edx * 4); goto dynamic_jump;
  case 0x0042ab96:
    // 0042ab96  b8c8584900             -mov eax, 0x4958c8
    cpu.eax = 4806856 /*0x4958c8*/;
    // 0042ab9b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ab9c:
    // 0042ab9c  b850584900             -mov eax, 0x495850
    cpu.eax = 4806736 /*0x495850*/;
    // 0042aba1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aba2:
    // 0042aba2  b8f0574900             -mov eax, 0x4957f0
    cpu.eax = 4806640 /*0x4957f0*/;
    // 0042aba7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aba8:
    // 0042aba8  b860574900             -mov eax, 0x495760
    cpu.eax = 4806496 /*0x495760*/;
    // 0042abad  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abae:
    // 0042abae  b8e0564900             -mov eax, 0x4956e0
    cpu.eax = 4806368 /*0x4956e0*/;
    // 0042abb3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abb4:
    // 0042abb4  b860564900             -mov eax, 0x495660
    cpu.eax = 4806240 /*0x495660*/;
    // 0042abb9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abba:
    // 0042abba  b82c564900             -mov eax, 0x49562c
    cpu.eax = 4806188 /*0x49562c*/;
    // 0042abbf  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abc0:
    // 0042abc0  b808564900             -mov eax, 0x495608
    cpu.eax = 4806152 /*0x495608*/;
    // 0042abc5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abc6:
    // 0042abc6  b8c8554900             -mov eax, 0x4955c8
    cpu.eax = 4806088 /*0x4955c8*/;
    // 0042abcb  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abcc:
    // 0042abcc  b888554900             -mov eax, 0x495588
    cpu.eax = 4806024 /*0x495588*/;
    // 0042abd1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abd2:
    // 0042abd2  b820554900             -mov eax, 0x495520
    cpu.eax = 4805920 /*0x495520*/;
    // 0042abd7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abd8:
    // 0042abd8  b8f4544900             -mov eax, 0x4954f4
    cpu.eax = 4805876 /*0x4954f4*/;
    // 0042abdd  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abde:
    // 0042abde  b870544900             -mov eax, 0x495470
    cpu.eax = 4805744 /*0x495470*/;
    // 0042abe3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abe4:
    // 0042abe4  b83c544900             -mov eax, 0x49543c
    cpu.eax = 4805692 /*0x49543c*/;
    // 0042abe9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abea:
    // 0042abea  b8fc534900             -mov eax, 0x4953fc
    cpu.eax = 4805628 /*0x4953fc*/;
    // 0042abef  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abf0:
    // 0042abf0  b8a8534900             -mov eax, 0x4953a8
    cpu.eax = 4805544 /*0x4953a8*/;
    // 0042abf5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abf6:
    // 0042abf6  b870534900             -mov eax, 0x495370
    cpu.eax = 4805488 /*0x495370*/;
    // 0042abfb  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042abfc:
    // 0042abfc  b820534900             -mov eax, 0x495320
    cpu.eax = 4805408 /*0x495320*/;
    // 0042ac01  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac02:
    // 0042ac02  b8f8524900             -mov eax, 0x4952f8
    cpu.eax = 4805368 /*0x4952f8*/;
    // 0042ac07  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac08:
    // 0042ac08  b8c4524900             -mov eax, 0x4952c4
    cpu.eax = 4805316 /*0x4952c4*/;
    // 0042ac0d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac0e:
    // 0042ac0e  b858524900             -mov eax, 0x495258
    cpu.eax = 4805208 /*0x495258*/;
    // 0042ac13  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac14:
    // 0042ac14  b820524900             -mov eax, 0x495220
    cpu.eax = 4805152 /*0x495220*/;
    // 0042ac19  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac1a:
    // 0042ac1a  b8e4514900             -mov eax, 0x4951e4
    cpu.eax = 4805092 /*0x4951e4*/;
    // 0042ac1f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac20:
    // 0042ac20  b898514900             -mov eax, 0x495198
    cpu.eax = 4805016 /*0x495198*/;
    // 0042ac25  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac26:
    // 0042ac26  b870514900             -mov eax, 0x495170
    cpu.eax = 4804976 /*0x495170*/;
    // 0042ac2b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac2c:
    // 0042ac2c  b808514900             -mov eax, 0x495108
    cpu.eax = 4804872 /*0x495108*/;
    // 0042ac31  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac32:
    // 0042ac32  b8b8504900             -mov eax, 0x4950b8
    cpu.eax = 4804792 /*0x4950b8*/;
    // 0042ac37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ac38:
    // 0042ac38  b800504900             -mov eax, 0x495000
    cpu.eax = 4804608 /*0x495000*/;
    // 0042ac3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ac3e:
    // 0042ac3e  81f976027688           +cmp ecx, 0x88760276
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435254 /*0x88760276*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ac44  0f8f96000000           -jg 0x42ace0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042ace0;
    }
    // 0042ac4a  0f848a000000           -je 0x42acda
    if (cpu.flags.zf)
    {
        goto L_0x0042acda;
    }
    // 0042ac50  8d81bdfd8977           -lea eax, [ecx + 0x7789fdbd]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2005532093) /* 0x7789fdbd */);
    // 0042ac56  83f829                 +cmp eax, 0x29
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ac59  0f87d7000000           -ja 0x42ad36
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042ad36;
    }
    // 0042ac5f  33c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0042ac61  8a88d8b04200           -mov cl, byte ptr [eax + 0x42b0d8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4370648) /* 0x42b0d8 */);
    // 0042ac67  ff248d8cb04200         -jmp dword ptr [ecx*4 + 0x42b08c]
    cpu.ip = app->getMemory<x86::reg32>(4370572 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0042ac6e:
    // 0042ac6e  b8004f4900             -mov eax, 0x494f00
    cpu.eax = 4804352 /*0x494f00*/;
    // 0042ac73  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac74:
    // 0042ac74  b8a04e4900             -mov eax, 0x494ea0
    cpu.eax = 4804256 /*0x494ea0*/;
    // 0042ac79  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac7a:
    // 0042ac7a  b8284e4900             -mov eax, 0x494e28
    cpu.eax = 4804136 /*0x494e28*/;
    // 0042ac7f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac80:
    // 0042ac80  b8d04d4900             -mov eax, 0x494dd0
    cpu.eax = 4804048 /*0x494dd0*/;
    // 0042ac85  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac86:
    // 0042ac86  b8804d4900             -mov eax, 0x494d80
    cpu.eax = 4803968 /*0x494d80*/;
    // 0042ac8b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac8c:
    // 0042ac8c  b8384d4900             -mov eax, 0x494d38
    cpu.eax = 4803896 /*0x494d38*/;
    // 0042ac91  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac92:
    // 0042ac92  b8d84c4900             -mov eax, 0x494cd8
    cpu.eax = 4803800 /*0x494cd8*/;
    // 0042ac97  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac98:
    // 0042ac98  b8a84c4900             -mov eax, 0x494ca8
    cpu.eax = 4803752 /*0x494ca8*/;
    // 0042ac9d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ac9e:
    // 0042ac9e  b8484c4900             -mov eax, 0x494c48
    cpu.eax = 4803656 /*0x494c48*/;
    // 0042aca3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042aca4:
    // 0042aca4  b8d04b4900             -mov eax, 0x494bd0
    cpu.eax = 4803536 /*0x494bd0*/;
    // 0042aca9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042acaa:
    // 0042acaa  b8984b4900             -mov eax, 0x494b98
    cpu.eax = 4803480 /*0x494b98*/;
    // 0042acaf  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042acb0:
    // 0042acb0  b85c4b4900             -mov eax, 0x494b5c
    cpu.eax = 4803420 /*0x494b5c*/;
    // 0042acb5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042acb6:
    // 0042acb6  b8184b4900             -mov eax, 0x494b18
    cpu.eax = 4803352 /*0x494b18*/;
    // 0042acbb  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042acbc:
    // 0042acbc  b8c04a4900             -mov eax, 0x494ac0
    cpu.eax = 4803264 /*0x494ac0*/;
    // 0042acc1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042acc2:
    // 0042acc2  b87c4a4900             -mov eax, 0x494a7c
    cpu.eax = 4803196 /*0x494a7c*/;
    // 0042acc7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042acc8:
    // 0042acc8  b8444a4900             -mov eax, 0x494a44
    cpu.eax = 4803140 /*0x494a44*/;
    // 0042accd  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042acce:
    // 0042acce  b8104a4900             -mov eax, 0x494a10
    cpu.eax = 4803088 /*0x494a10*/;
    // 0042acd3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042acd4:
    // 0042acd4  b8c0494900             -mov eax, 0x4949c0
    cpu.eax = 4803008 /*0x4949c0*/;
    // 0042acd9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042acda:
    // 0042acda  b848494900             -mov eax, 0x494948
    cpu.eax = 4802888 /*0x494948*/;
    // 0042acdf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ace0:
    // 0042ace0  81f9b3027688           +cmp ecx, 0x887602b3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435315 /*0x887602b3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ace6  7f3a                   -jg 0x42ad22
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042ad22;
    }
    // 0042ace8  7432                   -je 0x42ad1c
    if (cpu.flags.zf)
    {
        goto L_0x0042ad1c;
    }
    // 0042acea  8d8180fd8977           -lea eax, [ecx + 0x7789fd80]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2005532032) /* 0x7789fd80 */);
    // 0042acf0  83f832                 +cmp eax, 0x32
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042acf3  7741                   -ja 0x42ad36
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042ad36;
    }
    // 0042acf5  33d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0042acf7  8a9018b14200           -mov dl, byte ptr [eax + 0x42b118]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4370712) /* 0x42b118 */);
    // 0042acfd  ff249504b14200         -jmp dword ptr [edx*4 + 0x42b104]
    cpu.ip = app->getMemory<x86::reg32>(4370692 + cpu.edx * 4); goto dynamic_jump;
  case 0x0042ad04:
    // 0042ad04  b8c8484900             -mov eax, 0x4948c8
    cpu.eax = 4802760 /*0x4948c8*/;
    // 0042ad09  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ad0a:
    // 0042ad0a  b840484900             -mov eax, 0x494840
    cpu.eax = 4802624 /*0x494840*/;
    // 0042ad0f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ad10:
    // 0042ad10  b8f8474900             -mov eax, 0x4947f8
    cpu.eax = 4802552 /*0x4947f8*/;
    // 0042ad15  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0042ad16:
    // 0042ad16  b8a8474900             -mov eax, 0x4947a8
    cpu.eax = 4802472 /*0x4947a8*/;
    // 0042ad1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ad1c:
    // 0042ad1c  b870474900             -mov eax, 0x494770
    cpu.eax = 4802416 /*0x494770*/;
    // 0042ad21  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ad22:
    // 0042ad22  81f9b7027688           +cmp ecx, 0x887602b7
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435319 /*0x887602b7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ad28  741e                   -je 0x42ad48
    if (cpu.flags.zf)
    {
        goto L_0x0042ad48;
    }
    // 0042ad2a  81f9bb027688           +cmp ecx, 0x887602bb
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435323 /*0x887602bb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ad30  7410                   -je 0x42ad42
    if (cpu.flags.zf)
    {
        goto L_0x0042ad42;
    }
    // 0042ad32  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042ad34  7406                   -je 0x42ad3c
    if (cpu.flags.zf)
    {
        goto L_0x0042ad3c;
    }
  [[fallthrough]];
  case 0x0042ad36:
L_0x0042ad36:
    // 0042ad36  b854474900             -mov eax, 0x494754
    cpu.eax = 4802388 /*0x494754*/;
    // 0042ad3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ad3c:
    // 0042ad3c  b82c474900             -mov eax, 0x49472c
    cpu.eax = 4802348 /*0x49472c*/;
    // 0042ad41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ad42:
    // 0042ad42  b8c8464900             -mov eax, 0x4946c8
    cpu.eax = 4802248 /*0x4946c8*/;
    // 0042ad47  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042ad48:
    // 0042ad48  b8a8464900             -mov eax, 0x4946a8
    cpu.eax = 4802216 /*0x4946a8*/;
    // 0042ad4d  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_42b150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b150  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0042b156  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042b158  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0042b15b  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 0042b15e  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042b161  03c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042b163  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0042b165  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0042b168  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042b16b  8d0489                 -lea eax, [ecx + ecx*4]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 4);
    // 0042b16e  03c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042b170  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0042b173  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0042b176  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042b179  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42b180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b180  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042b184  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b185  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b186  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042b18a  8d3492                 -lea esi, [edx + edx*4]
    cpu.esi = x86::reg32(cpu.edx + cpu.edx * 4);
    // 0042b18d  03fa                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0042b18f  8d0cc8                 -lea ecx, [eax + ecx*8]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ecx * 8);
    // 0042b192  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042b196  8d1477                 -lea edx, [edi + esi*2]
    cpu.edx = x86::reg32(cpu.edi + cpu.esi * 2);
    // 0042b199  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b19a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0042b19c  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042b19f  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0042b1a2  83c20a                 -add edx, 0xa
    (cpu.edx) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0042b1a5  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042b1a8  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0042b1ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b1ac  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_42b1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b1b0  80fa2c                 +cmp dl, 0x2c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b1b3  7516                   -jne 0x42b1cb
    if (!cpu.flags.zf)
    {
        goto L_0x0042b1cb;
    }
    // 0042b1b5  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0042b1b8  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0042b1bd  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042b1bf  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042b1c2  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042b1c5  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042b1c7  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0042b1ca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042b1cb:
    // 0042b1cb  80fa2e                 +cmp dl, 0x2e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b1ce  750f                   -jne 0x42b1df
    if (!cpu.flags.zf)
    {
        goto L_0x0042b1df;
    }
    // 0042b1d0  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0042b1d3  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042b1d6  42                     -inc edx
    (cpu.edx)++;
    // 0042b1d7  40                     -inc eax
    (cpu.eax)++;
    // 0042b1d8  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042b1db  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042b1de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042b1df:
    // 0042b1df  80fa67                 +cmp dl, 0x67
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(103 /*0x67*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b1e2  7414                   -je 0x42b1f8
    if (cpu.flags.zf)
    {
        goto L_0x0042b1f8;
    }
    // 0042b1e4  80fa6a                 +cmp dl, 0x6a
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(106 /*0x6a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b1e7  740f                   -je 0x42b1f8
    if (cpu.flags.zf)
    {
        goto L_0x0042b1f8;
    }
    // 0042b1e9  80fa70                 +cmp dl, 0x70
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(112 /*0x70*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b1ec  740a                   -je 0x42b1f8
    if (cpu.flags.zf)
    {
        goto L_0x0042b1f8;
    }
    // 0042b1ee  80fa71                 +cmp dl, 0x71
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(113 /*0x71*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b1f1  7405                   -je 0x42b1f8
    if (cpu.flags.zf)
    {
        goto L_0x0042b1f8;
    }
    // 0042b1f3  80fa79                 +cmp dl, 0x79
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(121 /*0x79*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b1f6  7515                   -jne 0x42b20d
    if (!cpu.flags.zf)
    {
        goto L_0x0042b20d;
    }
L_0x0042b1f8:
    // 0042b1f8  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0042b1fb  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0042b200  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042b202  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042b205  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042b208  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042b20a  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0042b20d:
    // 0042b20d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42b210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b210  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0042b213  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b214  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042b215  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b216  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b217  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042b219  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0042b21d  0f840e010000           -je 0x42b331
    if (cpu.flags.zf)
    {
        goto L_0x0042b331;
    }
    // 0042b223  a1a4444900             -mov eax, dword ptr [0x4944a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4801700) /* 0x4944a4 */);
    // 0042b228  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042b22a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042b22e  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0042b230  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042b232  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0042b236  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042b238  0f84f3000000           -je 0x42b331
    if (cpu.flags.zf)
    {
        goto L_0x0042b331;
    }
    // 0042b23e  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x0042b240:
    // 0042b240  803f0d                 +cmp byte ptr [edi], 0xd
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b243  0f84dc000000           -je 0x42b325
    if (cpu.flags.zf)
    {
        goto L_0x0042b325;
    }
    // 0042b249  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042b24b  e8f02bfeff             -call 0x40de40
    cpu.esp -= 4;
    sub_40de40(app, cpu);
    // 0042b250  3b442410               +cmp eax, dword ptr [esp + 0x10]
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
    // 0042b254  7f05                   -jg 0x42b25b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042b25b;
    }
    // 0042b256  803f0a                 +cmp byte ptr [edi], 0xa
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
    // 0042b259  7511                   -jne 0x42b26c
    if (!cpu.flags.zf)
    {
        goto L_0x0042b26c;
    }
L_0x0042b25b:
    // 0042b25b  8b0da4444900           -mov ecx, dword ptr [0x4944a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4801700) /* 0x4944a4 */);
    // 0042b261  46                     -inc esi
    (cpu.esi)++;
    // 0042b262  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0042b266  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0042b26a  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0042b26c:
    // 0042b26c  83fe04                 +cmp esi, 4
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b26f  0f8dbc000000           -jge 0x42b331
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042b331;
    }
    // 0042b275  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042b277  80fb0a                 +cmp bl, 0xa
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b27a  0f84a5000000           -je 0x42b325
    if (cpu.flags.zf)
    {
        goto L_0x0042b325;
    }
    // 0042b280  80fb22                 +cmp bl, 0x22
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b283  0f849c000000           -je 0x42b325
    if (cpu.flags.zf)
    {
        goto L_0x0042b325;
    }
    // 0042b289  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0042b28d  8acb                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0042b28f  e8bcfeffff             -call 0x42b150
    cpu.esp -= 4;
    sub_42b150(app, cpu);
    // 0042b294  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0042b298  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0042b29c  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042b2a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042b2a1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b2a2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b2a3  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042b2a5  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0042b2a7  e8d4feffff             -call 0x42b180
    cpu.esp -= 4;
    sub_42b180(app, cpu);
    // 0042b2ac  837c244801             +cmp dword ptr [esp + 0x48], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b2b1  750b                   -jne 0x42b2be
    if (!cpu.flags.zf)
    {
        goto L_0x0042b2be;
    }
    // 0042b2b3  8ad3                   -mov dl, bl
    cpu.dl = cpu.bl;
    // 0042b2b5  8d4c241c               -lea ecx, [esp + 0x1c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042b2b9  e8f2feffff             -call 0x42b1b0
    cpu.esp -= 4;
    sub_42b1b0(app, cpu);
L_0x0042b2be:
    // 0042b2be  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042b2c2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042b2c4  8d4c2430               -lea ecx, [esp + 0x30]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0042b2c8  6800800001             -push 0x1008000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16809984 /*0x1008000*/;
    cpu.esp -= 4;
    // 0042b2cd  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042b2cf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b2d0  8b0d6cd44a00           -mov ecx, dword ptr [0x4ad46c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904044) /* 0x4ad46c */);
    // 0042b2d6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b2d7  8d4c242c               -lea ecx, [esp + 0x2c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0042b2db  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b2dc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b2dd  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b2e0  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042b2e2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042b2e4  7431                   -je 0x42b317
    if (cpu.flags.zf)
    {
        goto L_0x0042b317;
    }
    // 0042b2e6  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042b2e8  8a17                   -mov dl, byte ptr [edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi);
    // 0042b2ea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042b2eb  68b86b4900             -push 0x496bb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4811704 /*0x496bb8*/;
    cpu.esp -= 4;
    // 0042b2f0  e8c2ba0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b2f5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042b2f8  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042b2fa  e841f6ffff             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042b2ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b300  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042b305  e8adba0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b30a  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042b30f  e853c60400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042b314  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0042b317:
    // 0042b317  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042b31b  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042b31f  45                     -inc ebp
    (cpu.ebp)++;
    // 0042b320  48                     -dec eax
    (cpu.eax)--;
    // 0042b321  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0042b325:
    // 0042b325  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0042b328  47                     -inc edi
    (cpu.edi)++;
    // 0042b329  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042b32b  0f850fffffff           -jne 0x42b240
    if (!cpu.flags.zf)
    {
        goto L_0x0042b240;
    }
L_0x0042b331:
    // 0042b331  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b332  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b333  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b334  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b335  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0042b338  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_42b340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b341  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b342  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b343  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 0042b345  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042b347  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042b349  e82cbf0400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0042b34e  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042b350  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042b352  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042b354  8d5701                 -lea edx, [edi + 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0042b357  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042b358  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0042b35a  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0042b35d  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042b360  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042b363  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042b366  e80fbf0400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0042b36b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b36c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b36d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b36e  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0042b370  e84bca0400             -call 0x477dc0
    cpu.esp -= 4;
    _strncpy(app, cpu);
    // 0042b375  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042b377  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0042b37a  c6040700               -mov byte ptr [edi + eax], 0
    app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1) = 0 /*0x0*/;
    // 0042b37e  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042b380  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b381  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b382  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b383  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42b390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b391  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042b395  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b396  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042b39a  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042b39c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b39d  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0042b39f  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042b3a1  2bd6                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0042b3a3  8d0c30                 -lea ecx, [eax + esi]
    cpu.ecx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0042b3a6  e895ffffff             -call 0x42b340
    cpu.esp -= 4;
    sub_42b340(app, cpu);
    // 0042b3ab  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042b3af  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0042b3b2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042b3b4  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0042b3b7  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0042b3ba  7403                   -je 0x42b3bf
    if (cpu.flags.zf)
    {
        goto L_0x0042b3bf;
    }
    // 0042b3bc  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0042b3bf:
    // 0042b3bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b3c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b3c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b3c2  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_42b3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b3d0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042b3d2  7c09                   -jl 0x42b3dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042b3dd;
    }
L_0x0042b3d4:
    // 0042b3d4  803c113e               +cmp byte ptr [ecx + edx], 0x3e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.edx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(62 /*0x3e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b3d8  7406                   -je 0x42b3e0
    if (cpu.flags.zf)
    {
        goto L_0x0042b3e0;
    }
    // 0042b3da  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042b3db  79f7                   -jns 0x42b3d4
    if (!cpu.flags.sf)
    {
        goto L_0x0042b3d4;
    }
L_0x0042b3dd:
    // 0042b3dd  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042b3df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042b3e0:
    // 0042b3e0  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0042b3e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42b3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b3f0  803c113c               +cmp byte ptr [ecx + edx], 0x3c
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.edx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(60 /*0x3c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b3f4  7501                   -jne 0x42b3f7
    if (!cpu.flags.zf)
    {
        goto L_0x0042b3f7;
    }
    // 0042b3f6  42                     -inc edx
    (cpu.edx)++;
L_0x0042b3f7:
    // 0042b3f7  8a0411                 -mov al, byte ptr [ecx + edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + cpu.edx * 1);
    // 0042b3fa  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0042b3fc  3c30                   +cmp al, 0x30
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b3fe  7c0e                   -jl 0x42b40e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042b40e;
    }
    // 0042b400  3c39                   +cmp al, 0x39
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b402  7f0a                   -jg 0x42b40e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042b40e;
    }
    // 0042b404  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b405  e89adf0400             -call 0x4793a4
    cpu.esp -= 4;
    sub_4793a4(app, cpu);
    // 0042b40a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042b40d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042b40e:
    // 0042b40e  d90534734800           -fld dword ptr [0x487334]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    // 0042b414  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42b420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b420  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b421  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042b422  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b423  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042b425  33ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042b427  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042b429  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042b42b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b42c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042b42e  7470                   -je 0x42b4a0
    if (cpu.flags.zf)
    {
        goto L_0x0042b4a0;
    }
    // 0042b430  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0042b432  83c9ff                 +or ecx, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0042b435  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0042b437  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0042b439  49                     -dec ecx
    (cpu.ecx)--;
    // 0042b43a  81f910270000           +cmp ecx, 0x2710
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10000 /*0x2710*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b440  7214                   -jb 0x42b456
    if (cpu.flags.cf)
    {
        goto L_0x0042b456;
    }
    // 0042b442  68cc6b4900             -push 0x496bcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4811724 /*0x496bcc*/;
    cpu.esp -= 4;
    // 0042b447  e86bb90400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b44c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042b44f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042b451  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b452  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b453  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b454  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b455  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042b456:
    // 0042b456  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042b458  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042b45a  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042b45c  7440                   -je 0x42b49e
    if (cpu.flags.zf)
    {
        goto L_0x0042b49e;
    }
L_0x0042b45e:
    // 0042b45e  803c373c               +cmp byte ptr [edi + esi], 0x3c
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + cpu.esi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(60 /*0x3c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042b462  7408                   -je 0x42b46c
    if (cpu.flags.zf)
    {
        goto L_0x0042b46c;
    }
    // 0042b464  8a443701               -mov al, byte ptr [edi + esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */ + cpu.esi * 1);
    // 0042b468  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042b46a  7529                   -jne 0x42b495
    if (!cpu.flags.zf)
    {
        goto L_0x0042b495;
    }
L_0x0042b46c:
    // 0042b46c  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042b46e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042b470  e87bffffff             -call 0x42b3f0
    cpu.esp -= 4;
    sub_42b3f0(app, cpu);
    // 0042b475  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042b477  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b478  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042b47a  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042b47d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b47e  e84dffffff             -call 0x42b3d0
    cpu.esp -= 4;
    sub_42b3d0(app, cpu);
    // 0042b483  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042b485  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042b487  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b488  e803ffffff             -call 0x42b390
    cpu.esp -= 4;
    sub_42b390(app, cpu);
    // 0042b48d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042b48f  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042b491  7502                   -jne 0x42b495
    if (!cpu.flags.zf)
    {
        goto L_0x0042b495;
    }
    // 0042b493  8beb                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0042b495:
    // 0042b495  8a443701               -mov al, byte ptr [edi + esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */ + cpu.esi * 1);
    // 0042b499  47                     -inc edi
    (cpu.edi)++;
    // 0042b49a  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042b49c  75c0                   -jne 0x42b45e
    if (!cpu.flags.zf)
    {
        goto L_0x0042b45e;
    }
L_0x0042b49e:
    // 0042b49e  8bc5                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0042b4a0:
    // 0042b4a0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b4a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b4a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b4a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b4a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42b4b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b4b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b4b1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042b4b3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042b4b5  741c                   -je 0x42b4d3
    if (cpu.flags.zf)
    {
        goto L_0x0042b4d3;
    }
    // 0042b4b7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0042b4b8:
    // 0042b4b8  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0042b4ba  8b7610                 -mov esi, dword ptr [esi + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0042b4bd  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0042b4bf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b4c0  e8efbe0400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0042b4c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b4c6  e8e9be0400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0042b4cb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042b4ce  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042b4d0  75e6                   -jne 0x42b4b8
    if (!cpu.flags.zf)
    {
        goto L_0x0042b4b8;
    }
    // 0042b4d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042b4d3:
    // 0042b4d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b4d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42b4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b4e0  e83bffffff             -call 0x42b420
    cpu.esp -= 4;
    sub_42b420(app, cpu);
    // 0042b4e5  a398d44a00             -mov dword ptr [0x4ad498], eax
    app->getMemory<x86::reg32>(x86::reg32(4904088) /* 0x4ad498 */) = cpu.eax;
    // 0042b4ea  a39cd44a00             -mov dword ptr [0x4ad49c], eax
    app->getMemory<x86::reg32>(x86::reg32(4904092) /* 0x4ad49c */) = cpu.eax;
    // 0042b4ef  c70590d44a0000000000   -mov dword ptr [0x4ad490], 0
    app->getMemory<x86::reg32>(x86::reg32(4904080) /* 0x4ad490 */) = 0 /*0x0*/;
    // 0042b4f9  c70594d44a0000000000   -mov dword ptr [0x4ad494], 0
    app->getMemory<x86::reg32>(x86::reg32(4904084) /* 0x4ad494 */) = 0 /*0x0*/;
    // 0042b503  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42b510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b510  a160d44a00             -mov eax, dword ptr [0x4ad460]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904032) /* 0x4ad460 */);
    // 0042b515  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b517  7407                   -je 0x42b520
    if (cpu.flags.zf)
    {
        goto L_0x0042b520;
    }
    // 0042b519  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b51a  ff15c8724800           -call dword ptr [0x4872c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4747976) /* 0x4872c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042b520:
    // 0042b520  e89bf1ffff             -call 0x42a6c0
    cpu.esp -= 4;
    sub_42a6c0(app, cpu);
    // 0042b525  8b0d98d44a00           -mov ecx, dword ptr [0x4ad498]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904088) /* 0x4ad498 */);
    // 0042b52b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042b52d  7405                   -je 0x42b534
    if (cpu.flags.zf)
    {
        goto L_0x0042b534;
    }
    // 0042b52f  e97cffffff             -jmp 0x42b4b0
    return sub_42b4b0(app, cpu);
L_0x0042b534:
    // 0042b534  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42b540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b540  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0042b543  b8e0010000             -mov eax, 0x1e0
    cpu.eax = 480 /*0x1e0*/;
    // 0042b548  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b549  be80020000             -mov esi, 0x280
    cpu.esi = 640 /*0x280*/;
    // 0042b54e  3bce                   +cmp ecx, esi
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
    // 0042b550  7d02                   -jge 0x42b554
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042b554;
    }
    // 0042b552  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x0042b554:
    // 0042b554  81fae0010000           +cmp edx, 0x1e0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(480 /*0x1e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b55a  7d02                   -jge 0x42b55e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042b55e;
    }
    // 0042b55c  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0042b55e:
    // 0042b55e  8b1588d44a00           -mov edx, dword ptr [0x4ad488]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904072) /* 0x4ad488 */);
    // 0042b564  8b0d84d44a00           -mov ecx, dword ptr [0x4ad484]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904068) /* 0x4ad484 */);
    // 0042b56a  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0042b56e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b56f  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042b571  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042b573  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0042b577  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b578  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042b57c  6800000001             -push 0x1000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16777216 /*0x1000000*/;
    cpu.esp -= 4;
    // 0042b581  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042b582  8b1574d44a00           -mov edx, dword ptr [0x4ad474]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904052) /* 0x4ad474 */);
    // 0042b588  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0042b58c  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0042b590  a170d44a00             -mov eax, dword ptr [0x4ad470]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904048) /* 0x4ad470 */);
    // 0042b595  03ce                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0042b597  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042b598  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042b59c  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0042b5a0  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0042b5a4  897c241c               -mov dword ptr [esp + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 0042b5a8  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0042b5ac  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042b5ae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042b5af  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b5b0  ff5114                 -call dword ptr [ecx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b5b3  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042b5b5  3bf7                   +cmp esi, edi
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
    // 0042b5b7  7454                   -je 0x42b60d
    if (cpu.flags.zf)
    {
        goto L_0x0042b60d;
    }
    // 0042b5b9  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042b5bd  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042b5c1  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042b5c5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b5c6  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042b5ca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b5cb  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0042b5cf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042b5d0  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0042b5d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b5d5  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0042b5d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b5da  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0042b5de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042b5df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b5e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b5e1  68206c4900             -push 0x496c20
    app->getMemory<x86::reg32>(cpu.esp-4) = 4811808 /*0x496c20*/;
    cpu.esp -= 4;
    // 0042b5e6  e8ccb70400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b5eb  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0042b5ee  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042b5f0  e84bf3ffff             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042b5f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b5f6  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042b5fb  e8b7b70400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b600  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042b605  e85dc30400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042b60a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0042b60d:
    // 0042b60d  e87e000000             -call 0x42b690
    cpu.esp -= 4;
    sub_42b690(app, cpu);
    // 0042b612  a178d44a00             -mov eax, dword ptr [0x4ad478]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904056) /* 0x4ad478 */);
    // 0042b617  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042b61b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b61c  6800000001             -push 0x1000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16777216 /*0x1000000*/;
    cpu.esp -= 4;
    // 0042b621  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b622  8b0d70d44a00           -mov ecx, dword ptr [0x4ad470]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904048) /* 0x4ad470 */);
    // 0042b628  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b629  8d4c2438               -lea ecx, [esp + 0x38]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0042b62d  897c2438               -mov dword ptr [esp + 0x38], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edi;
    // 0042b631  897c243c               -mov dword ptr [esp + 0x3c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edi;
    // 0042b635  c744244080020000       -mov dword ptr [esp + 0x40], 0x280
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 640 /*0x280*/;
    // 0042b63d  c7442444e0010000       -mov dword ptr [esp + 0x44], 0x1e0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = 480 /*0x1e0*/;
    // 0042b645  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042b647  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b648  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b649  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042b64c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042b64e  3bf7                   +cmp esi, edi
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
    // 0042b650  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b651  742c                   -je 0x42b67f
    if (cpu.flags.zf)
    {
        goto L_0x0042b67f;
    }
    // 0042b653  68f46b4900             -push 0x496bf4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4811764 /*0x496bf4*/;
    cpu.esp -= 4;
    // 0042b658  e85ab70400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b65d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042b660  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042b662  e8d9f2ffff             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042b667  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b668  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042b66d  e845b70400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b672  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042b677  e8ebc20400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042b67c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0042b67f:
    // 0042b67f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b680  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0042b683  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42b690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b690  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b691  8b359cd44a00           -mov esi, dword ptr [0x4ad49c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4904092) /* 0x4ad49c */);
    // 0042b697  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042b699  7472                   -je 0x42b70d
    if (cpu.flags.zf)
    {
        goto L_0x0042b70d;
    }
    // 0042b69b  dd0590d44a00           -fld qword ptr [0x4ad490]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4904080) /* 0x4ad490 */)));
    // 0042b6a1  dc1d70744800           -fcomp qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    cpu.fpu.pop();
    // 0042b6a7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042b6a9  f6c441                 +test ah, 0x41
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 65 /*0x41*/));
    // 0042b6ac  7a0e                   -jp 0x42b6bc
    if (cpu.flags.pf)
    {
        goto L_0x0042b6bc;
    }
    // 0042b6ae  e87da00300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042b6b3  d8460c                 -fadd dword ptr [esi + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */));
    // 0042b6b6  dd1d90d44a00           -fstp qword ptr [0x4ad490]
    app->getMemory<double>(x86::reg32(4904080) /* 0x4ad490 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0042b6bc:
    // 0042b6bc  a1ac444900             -mov eax, dword ptr [0x4944ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4801708) /* 0x4944ac */);
    // 0042b6c1  8b0da8444900           -mov ecx, dword ptr [0x4944a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4801704) /* 0x4944a8 */);
    // 0042b6c7  8b1570d44a00           -mov edx, dword ptr [0x4ad470]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904048) /* 0x4ad470 */);
    // 0042b6cd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042b6cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b6d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b6d1  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042b6d3  e838fbffff             -call 0x42b210
    cpu.esp -= 4;
    sub_42b210(app, cpu);
    // 0042b6d8  e853a00300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042b6dd  dc1d90d44a00           -fcomp qword ptr [0x4ad490]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4904080) /* 0x4ad490 */)));
    cpu.fpu.pop();
    // 0042b6e3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042b6e5  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 0042b6ea  7521                   -jne 0x42b70d
    if (!cpu.flags.zf)
    {
        goto L_0x0042b70d;
    }
    // 0042b6ec  c70590d44a0000000000   -mov dword ptr [0x4ad490], 0
    app->getMemory<x86::reg32>(x86::reg32(4904080) /* 0x4ad490 */) = 0 /*0x0*/;
    // 0042b6f6  c70594d44a0000000000   -mov dword ptr [0x4ad494], 0
    app->getMemory<x86::reg32>(x86::reg32(4904084) /* 0x4ad494 */) = 0 /*0x0*/;
    // 0042b700  8b7610                 -mov esi, dword ptr [esi + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0042b703  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042b705  7406                   -je 0x42b70d
    if (cpu.flags.zf)
    {
        goto L_0x0042b70d;
    }
    // 0042b707  89359cd44a00           -mov dword ptr [0x4ad49c], esi
    app->getMemory<x86::reg32>(x86::reg32(4904092) /* 0x4ad49c */) = cpu.esi;
L_0x0042b70d:
    // 0042b70d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b70e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42b710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042b710  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042b713  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b714  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042b715  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042b716  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0042b718  6808c74800             -push 0x48c708
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769544 /*0x48c708*/;
    cpu.esp -= 4;
    // 0042b71d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042b71e  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042b720  e839c50400             -call 0x477c5e
    cpu.esp -= 4;
    sub_477c5e(app, cpu);
    // 0042b725  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042b727  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042b72a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042b72c  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0042b730  7514                   -jne 0x42b746
    if (!cpu.flags.zf)
    {
        goto L_0x0042b746;
    }
    // 0042b732  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042b733  e8c3dc0400             -call 0x4793fb
    cpu.esp -= 4;
    sub_4793fb(app, cpu);
    // 0042b738  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042b73b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042b73d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b73e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b73f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b740  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042b743  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0042b746:
    // 0042b746  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b747  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042b749  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042b74d  6a12                   -push 0x12
    app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 0042b74f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b750  e833bf0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0042b755  8a442426               -mov al, byte ptr [esp + 0x26]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(38) /* 0x26 */);
    // 0042b759  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042b75c  3c0a                   +cmp al, 0xa
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
    // 0042b75e  741c                   -je 0x42b77c
    if (cpu.flags.zf)
    {
        goto L_0x0042b77c;
    }
    // 0042b760  3c02                   +cmp al, 2
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
    // 0042b762  7418                   -je 0x42b77c
    if (cpu.flags.zf)
    {
        goto L_0x0042b77c;
    }
    // 0042b764  68246d4900             -push 0x496d24
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812068 /*0x496d24*/;
    cpu.esp -= 4;
    // 0042b769  e849b60400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b76e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042b771  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042b773  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b774  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b775  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042b776  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042b779  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0042b77c:
    // 0042b77c  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042b780  8b542422               -mov edx, dword ptr [esp + 0x22]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(34) /* 0x22 */);
    // 0042b784  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042b788  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0042b78e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b78f  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b795  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b796  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b79b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042b79c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b79d  68006d4900             -push 0x496d00
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812032 /*0x496d00*/;
    cpu.esp -= 4;
    // 0042b7a2  e810b60400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b7a7  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0042b7ab  8b7c2438               -mov edi, dword ptr [esp + 0x38]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0042b7af  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042b7b1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042b7b4  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b7ba  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0042b7bc  8b4c2426               -mov ecx, dword ptr [esp + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(38) /* 0x26 */);
    // 0042b7c0  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0042b7c4  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0042b7c6  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b7cc  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0042b7ce  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0042b7d2  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042b7d4  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0042b7da  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0042b7dc  8a542418               -mov dl, byte ptr [esp + 0x18]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042b7e0  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042b7e2  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0042b7e4  7623                   -jbe 0x42b809
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042b809;
    }
L_0x0042b7e6:
    // 0042b7e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042b7e7  e866cf0400             -call 0x478752
    cpu.esp -= 4;
    sub_478752(app, cpu);
    // 0042b7ec  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042b7f0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042b7f3  46                     -inc esi
    (cpu.esi)++;
    // 0042b7f4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0042b7f9  3bf0                   +cmp esi, eax
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
    // 0042b7fb  7ce9                   -jl 0x42b7e6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042b7e6;
    }
    // 0042b7fd  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042b801  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042b805  8b4c2426               -mov ecx, dword ptr [esp + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(38) /* 0x26 */);
L_0x0042b809:
    // 0042b809  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0042b80f  be686c4900             -mov esi, 0x496c68
    cpu.esi = 4811880 /*0x496c68*/;
    // 0042b814  c1ef03                 -shr edi, 3
    cpu.edi >>= 3 /*0x3*/ % 32;
L_0x0042b817:
    // 0042b817  813effff0000           +cmp dword ptr [esi], 0xffff
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65535 /*0xffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b81d  7527                   -jne 0x42b846
    if (!cpu.flags.zf)
    {
        goto L_0x0042b846;
    }
    // 0042b81f  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b825  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b826  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042b827  68e86c4900             -push 0x496ce8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812008 /*0x496ce8*/;
    cpu.esp -= 4;
    // 0042b82c  e886b50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b831  68bc6c4900             -push 0x496cbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4811964 /*0x496cbc*/;
    cpu.esp -= 4;
    // 0042b836  e87cb50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b83b  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0042b83f  8b4c2436               -mov ecx, dword ptr [esp + 0x36]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(54) /* 0x36 */);
    // 0042b843  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0042b846:
    // 0042b846  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042b848  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0042b84a  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b850  3bd3                   +cmp edx, ebx
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
    // 0042b852  7405                   -je 0x42b859
    if (cpu.flags.zf)
    {
        goto L_0x0042b859;
    }
    // 0042b854  83c604                 +add esi, 4
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
    // 0042b857  ebbe                   -jmp 0x42b817
    goto L_0x0042b817;
L_0x0042b859:
    // 0042b859  be686c4900             -mov esi, 0x496c68
    cpu.esi = 4811880 /*0x496c68*/;
L_0x0042b85e:
    // 0042b85e  813effff0000           +cmp dword ptr [esi], 0xffff
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65535 /*0xffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042b864  752d                   -jne 0x42b893
    if (!cpu.flags.zf)
    {
        goto L_0x0042b893;
    }
    // 0042b866  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b86b  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b871  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b872  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b873  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042b874  68a46c4900             -push 0x496ca4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4811940 /*0x496ca4*/;
    cpu.esp -= 4;
    // 0042b879  e839b50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b87e  68bc6c4900             -push 0x496cbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4811964 /*0x496cbc*/;
    cpu.esp -= 4;
    // 0042b883  e82fb50400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b888  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0042b88c  8b4c243a               -mov ecx, dword ptr [esp + 0x3a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(58) /* 0x3a */);
    // 0042b890  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0042b893:
    // 0042b893  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042b895  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042b897  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b89d  3bd3                   +cmp edx, ebx
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
    // 0042b89f  7405                   -je 0x42b8a6
    if (cpu.flags.zf)
    {
        goto L_0x0042b8a6;
    }
    // 0042b8a1  83c604                 +add esi, 4
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
    // 0042b8a4  ebb8                   -jmp 0x42b85e
    goto L_0x0042b85e;
L_0x0042b8a6:
    // 0042b8a6  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b8ab  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b8b1  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0042b8b4  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0042b8b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b8b8  e8bdb90400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0042b8bd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042b8c0  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0042b8c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b8c6  750d                   -jne 0x42b8d5
    if (!cpu.flags.zf)
    {
        goto L_0x0042b8d5;
    }
    // 0042b8c8  68c8c34800             -push 0x48c3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4768712 /*0x48c3c8*/;
    cpu.esp -= 4;
    // 0042b8cd  e8e5b40400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042b8d2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042b8d5:
    // 0042b8d5  8b6c2426               -mov ebp, dword ptr [esp + 0x26]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(38) /* 0x26 */);
    // 0042b8d9  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042b8dd  81e5ffff0000           -and ebp, 0xffff
    cpu.ebp &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b8e3  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b8e9  4d                     -dec ebp
    (cpu.ebp)--;
    // 0042b8ea  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0042b8ee  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0042b8f1  0faff7                 -imul esi, edi
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0042b8f4  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042b8f6  03f1                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042b8f8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042b8fa  0f8c25010000           -jl 0x42ba25
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042ba25;
    }
L_0x0042b900:
    // 0042b900  8a44241a               -mov al, byte ptr [esp + 0x1a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(26) /* 0x1a */);
    // 0042b904  3c0a                   +cmp al, 0xa
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
    // 0042b906  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042b90a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b90b  0f85cd000000           -jne 0x42b9de
    if (!cpu.flags.zf)
    {
        goto L_0x0042b9de;
    }
    // 0042b911  e83cce0400             -call 0x478752
    cpu.esp -= 4;
    sub_478752(app, cpu);
    // 0042b916  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0042b918  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042b91b  83e17f                 -and ecx, 0x7f
    cpu.ecx &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0042b91e  41                     -inc ecx
    (cpu.ecx)++;
    // 0042b91f  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0042b921  894c2434               -mov dword ptr [esp + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ecx;
    // 0042b925  795a                   -jns 0x42b981
    if (!cpu.flags.sf)
    {
        goto L_0x0042b981;
    }
    // 0042b927  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042b92b  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042b92f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042b930  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b931  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042b933  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b934  e84fbd0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0042b939  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0042b93d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042b940  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042b942  0f8ed5000000           -jle 0x42ba1d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ba1d;
    }
    // 0042b948  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0042b94a:
    // 0042b94a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042b94c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042b94e  7e0c                   -jle 0x42b95c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042b95c;
    }
L_0x0042b950:
    // 0042b950  8a540410               -mov dl, byte ptr [esp + eax + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */ + cpu.eax * 1);
    // 0042b954  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 0042b956  46                     -inc esi
    (cpu.esi)++;
    // 0042b957  40                     -inc eax
    (cpu.eax)++;
    // 0042b958  3bc7                   +cmp eax, edi
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
    // 0042b95a  7cf4                   -jl 0x42b950
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042b950;
    }
L_0x0042b95c:
    // 0042b95c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042b960  43                     -inc ebx
    (cpu.ebx)++;
    // 0042b961  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b966  3bd8                   +cmp ebx, eax
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
    // 0042b968  750f                   -jne 0x42b979
    if (!cpu.flags.zf)
    {
        goto L_0x0042b979;
    }
    // 0042b96a  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042b96c  4d                     -dec ebp
    (cpu.ebp)--;
    // 0042b96d  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0042b970  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0042b973  03442430               +add eax, dword ptr [esp + 0x30]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042b977  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0042b979:
    // 0042b979  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042b97a  75ce                   -jne 0x42b94a
    if (!cpu.flags.zf)
    {
        goto L_0x0042b94a;
    }
    // 0042b97c  e99c000000             -jmp 0x42ba1d
    goto L_0x0042ba1d;
L_0x0042b981:
    // 0042b981  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042b983  0f8e94000000           -jle 0x42ba1d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ba1d;
    }
    // 0042b989  894c2434               -mov dword ptr [esp + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ecx;
L_0x0042b98d:
    // 0042b98d  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042b991  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042b995  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042b996  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b997  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042b999  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b99a  e8e9bc0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0042b99f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042b9a2  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042b9a4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042b9a6  7e0c                   -jle 0x42b9b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042b9b4;
    }
L_0x0042b9a8:
    // 0042b9a8  8a540410               -mov dl, byte ptr [esp + eax + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */ + cpu.eax * 1);
    // 0042b9ac  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 0042b9ae  46                     -inc esi
    (cpu.esi)++;
    // 0042b9af  40                     -inc eax
    (cpu.eax)++;
    // 0042b9b0  3bc7                   +cmp eax, edi
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
    // 0042b9b2  7cf4                   -jl 0x42b9a8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042b9a8;
    }
L_0x0042b9b4:
    // 0042b9b4  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042b9b8  43                     -inc ebx
    (cpu.ebx)++;
    // 0042b9b9  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042b9be  3bd8                   +cmp ebx, eax
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
    // 0042b9c0  750f                   -jne 0x42b9d1
    if (!cpu.flags.zf)
    {
        goto L_0x0042b9d1;
    }
    // 0042b9c2  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042b9c4  4d                     -dec ebp
    (cpu.ebp)--;
    // 0042b9c5  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0042b9c8  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0042b9cb  03442430               +add eax, dword ptr [esp + 0x30]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042b9cf  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0042b9d1:
    // 0042b9d1  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0042b9d5  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042b9d6  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0042b9da  75b1                   -jne 0x42b98d
    if (!cpu.flags.zf)
    {
        goto L_0x0042b98d;
    }
    // 0042b9dc  eb3f                   -jmp 0x42ba1d
    goto L_0x0042ba1d;
L_0x0042b9de:
    // 0042b9de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042b9df  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042b9e3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042b9e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042b9e6  e89dbc0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0042b9eb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042b9ee  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042b9f0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042b9f2  7e0c                   -jle 0x42ba00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ba00;
    }
L_0x0042b9f4:
    // 0042b9f4  8a540410               -mov dl, byte ptr [esp + eax + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */ + cpu.eax * 1);
    // 0042b9f8  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 0042b9fa  46                     -inc esi
    (cpu.esi)++;
    // 0042b9fb  40                     -inc eax
    (cpu.eax)++;
    // 0042b9fc  3bc7                   +cmp eax, edi
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
    // 0042b9fe  7cf4                   -jl 0x42b9f4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042b9f4;
    }
L_0x0042ba00:
    // 0042ba00  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042ba04  43                     -inc ebx
    (cpu.ebx)++;
    // 0042ba05  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042ba0a  3bd8                   +cmp ebx, eax
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
    // 0042ba0c  750f                   -jne 0x42ba1d
    if (!cpu.flags.zf)
    {
        goto L_0x0042ba1d;
    }
    // 0042ba0e  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042ba10  4d                     -dec ebp
    (cpu.ebp)--;
    // 0042ba11  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0042ba14  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0042ba17  03442430               -add eax, dword ptr [esp + 0x30]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0042ba1b  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0042ba1d:
    // 0042ba1d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042ba1f  0f8ddbfeffff           -jge 0x42b900
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042b900;
    }
L_0x0042ba25:
    // 0042ba25  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042ba29  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ba2a  e8a8bb0400             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0042ba2f  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0042ba33  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ba36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba39  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba3a  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042ba3d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_42ba40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042ba40  81ec64010000           -sub esp, 0x164
    (cpu.esp) -= x86::reg32(x86::sreg32(356 /*0x164*/));
    // 0042ba46  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042ba47  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042ba48  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ba49  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ba4a  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042ba4c  6808c74800             -push 0x48c708
    app->getMemory<x86::reg32>(cpu.esp-4) = 4769544 /*0x48c708*/;
    cpu.esp -= 4;
    // 0042ba51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ba52  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0042ba56  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0042ba5c  e8fdc10400             -call 0x477c5e
    cpu.esp -= 4;
    sub_477c5e(app, cpu);
    // 0042ba61  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042ba63  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042ba66  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042ba68  7518                   -jne 0x42ba82
    if (!cpu.flags.zf)
    {
        goto L_0x0042ba82;
    }
    // 0042ba6a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ba6b  e88bd90400             -call 0x4793fb
    cpu.esp -= 4;
    sub_4793fb(app, cpu);
    // 0042ba70  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ba73  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042ba75  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba78  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ba79  81c464010000           -add esp, 0x164
    (cpu.esp) += x86::reg32(x86::sreg32(356 /*0x164*/));
    // 0042ba7f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0042ba82:
    // 0042ba82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ba83  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042ba85  8d442470               -lea eax, [esp + 0x70]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0042ba89  6a12                   -push 0x12
    app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 0042ba8b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042ba8c  e8f7bb0400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0042ba91  8a44247a               -mov al, byte ptr [esp + 0x7a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(122) /* 0x7a */);
    // 0042ba95  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042ba98  3c0a                   +cmp al, 0xa
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
    // 0042ba9a  7420                   -je 0x42babc
    if (cpu.flags.zf)
    {
        goto L_0x0042babc;
    }
    // 0042ba9c  3c02                   +cmp al, 2
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
    // 0042ba9e  741c                   -je 0x42babc
    if (cpu.flags.zf)
    {
        goto L_0x0042babc;
    }
    // 0042baa0  68246d4900             -push 0x496d24
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812068 /*0x496d24*/;
    cpu.esp -= 4;
    // 0042baa5  e80db30400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042baaa  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042baad  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042baaf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bab0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bab1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bab2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bab3  81c464010000           -add esp, 0x164
    (cpu.esp) += x86::reg32(x86::sreg32(356 /*0x164*/));
    // 0042bab9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0042babc:
    // 0042babc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042babd  e815bb0400             -call 0x4775d7
    cpu.esp -= 4;
    sub_4775d7(app, cpu);
    // 0042bac2  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0042bac6  8b6c247a               -mov ebp, dword ptr [esp + 0x7a]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(122) /* 0x7a */);
    // 0042baca  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0042bace  8b5c247c               -mov ebx, dword ptr [esp + 0x7c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0042bad2  668b54247c             -mov dx, word ptr [esp + 0x7c]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0042bad7  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042bad9  81e5ffff0000           -and ebp, 0xffff
    cpu.ebp &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042badf  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042bae4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042bae7  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0042baea  894c2438               -mov dword ptr [esp + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 0042baee  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042baf2  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0042baf8  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0042bafc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bafd  6689542444             -mov word ptr [esp + 0x44], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.dx;
    // 0042bb02  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 0042bb05  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042bb06  8d542434               -lea edx, [esp + 0x34]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0042bb0a  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042bb0c  89742444               -mov dword ptr [esp + 0x44], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.esi;
    // 0042bb10  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0042bb14  e8f7fbffff             -call 0x42b710
    cpu.esp -= 4;
    sub_42b710(app, cpu);
    // 0042bb19  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042bb1f  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0042bb23  89742434               -mov dword ptr [esp + 0x34], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.esi;
    // 0042bb27  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042bb29:
    // 0042bb29  8b88686c4900           -mov ecx, dword ptr [eax + 0x496c68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4811880) /* 0x496c68 */);
    // 0042bb2f  3bce                   +cmp ecx, esi
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
    // 0042bb31  7416                   -je 0x42bb49
    if (cpu.flags.zf)
    {
        goto L_0x0042bb49;
    }
    // 0042bb33  8b54243e               -mov edx, dword ptr [esp + 0x3e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(62) /* 0x3e */);
    // 0042bb37  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042bb3d  3bca                   +cmp ecx, edx
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
    // 0042bb3f  7408                   -je 0x42bb49
    if (cpu.flags.zf)
    {
        goto L_0x0042bb49;
    }
    // 0042bb41  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042bb44  83f83c                 +cmp eax, 0x3c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042bb47  72e0                   -jb 0x42bb29
    if (cpu.flags.cf)
    {
        goto L_0x0042bb29;
    }
L_0x0042bb49:
    // 0042bb49  b91f000000             -mov ecx, 0x1f
    cpu.ecx = 31 /*0x1f*/;
    // 0042bb4e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bb50  8dbc24f8000000         -lea edi, [esp + 0xf8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(248) /* 0xf8 */);
    // 0042bb57  8d9424f8000000         -lea edx, [esp + 0xf8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(248) /* 0xf8 */);
    // 0042bb5e  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042bb60  a178d44a00             -mov eax, dword ptr [0x4ad478]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904056) /* 0x4ad478 */);
    // 0042bb65  c78424f80000007c000000 -mov dword ptr [esp + 0xf8], 0x7c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */) = 124 /*0x7c*/;
    // 0042bb70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042bb71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bb72  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042bb74  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042bb77  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042bb79  f7df                   +neg edi
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.edi;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0042bb7b  1bff                   -sbb edi, edi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edi) + cpu.flags.cf);
    // 0042bb7d  f7df                   +neg edi
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.edi;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0042bb7f  743b                   -je 0x42bbbc
    if (cpu.flags.zf)
    {
        goto L_0x0042bbbc;
    }
    // 0042bb81  68fc6d4900             -push 0x496dfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812284 /*0x496dfc*/;
    cpu.esp -= 4;
    // 0042bb86  e82cb20400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042bb8b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042bb8e  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042bb90  e8abedffff             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042bb95  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bb96  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042bb9b  e817b20400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042bba0  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042bba5  e8bdbd0400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042bbaa  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042bbad  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bbaf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bbb0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bbb1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bbb2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bbb3  81c464010000           -add esp, 0x164
    (cpu.esp) += x86::reg32(x86::sreg32(356 /*0x164*/));
    // 0042bbb9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0042bbbc:
    // 0042bbbc  b91f000000             -mov ecx, 0x1f
    cpu.ecx = 31 /*0x1f*/;
    // 0042bbc1  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bbc3  8d7c247c               -lea edi, [esp + 0x7c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0042bbc7  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042bbc9  8b44243e               -mov eax, dword ptr [esp + 0x3e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(62) /* 0x3e */);
    // 0042bbcd  8b0d0cbb4900           -mov ecx, dword ptr [0x49bb0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4832012) /* 0x49bb0c */);
    // 0042bbd3  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0042bbd8  3bf1                   +cmp esi, ecx
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
    // 0042bbda  89842484000000         -mov dword ptr [esp + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 0042bbe1  8b842414010000         -mov eax, dword ptr [esp + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0042bbe8  c744247c7c000000       -mov dword ptr [esp + 0x7c], 0x7c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = 124 /*0x7c*/;
    // 0042bbf0  c784248000000007100000 -mov dword ptr [esp + 0x80], 0x1007
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = 4103 /*0x1007*/;
    // 0042bbfb  89b42488000000         -mov dword ptr [esp + 0x88], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.esi;
    // 0042bc02  89842498000000         -mov dword ptr [esp + 0x98], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.eax;
    // 0042bc09  7e23                   -jle 0x42bc2e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042bc2e;
    }
    // 0042bc0b  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042bc0d  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0042bc0f  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0042bc10  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042bc12  898c2488000000         -mov dword ptr [esp + 0x88], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.ecx;
    // 0042bc19  898c2484000000         -mov dword ptr [esp + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 0042bc20  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0042bc24  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0042bc27  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0042bc2b  0fafe9                 -imul ebp, ecx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.ecx)));
L_0x0042bc2e:
    // 0042bc2e  8a442440               -mov al, byte ptr [esp + 0x40]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0042bc32  8dbc24c4000000         -lea edi, [esp + 0xc4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0042bc39  8db42440010000         -lea esi, [esp + 0x140]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 0042bc40  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0042bc45  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042bc47  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042bc49  750a                   -jne 0x42bc55
    if (!cpu.flags.zf)
    {
        goto L_0x0042bc55;
    }
    // 0042bc4b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042bc4f  c70101000000           -mov dword ptr [ecx], 1
    app->getMemory<x86::reg32>(cpu.ecx) = 1 /*0x1*/;
L_0x0042bc55:
    // 0042bc55  8b942450010000         -mov edx, dword ptr [esp + 0x150]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(336) /* 0x150 */);
    // 0042bc5c  8d4c245c               -lea ecx, [esp + 0x5c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0042bc60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042bc61  8d54244c               -lea edx, [esp + 0x4c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0042bc65  e8f6020000             -call 0x42bf60
    cpu.esp -= 4;
    sub_42bf60(app, cpu);
    // 0042bc6a  8d542444               -lea edx, [esp + 0x44]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0042bc6e  8d4c2450               -lea ecx, [esp + 0x50]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0042bc72  8b8424d8000000         -mov eax, dword ptr [esp + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(216) /* 0xd8 */);
    // 0042bc79  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bc7a  e8e1020000             -call 0x42bf60
    cpu.esp -= 4;
    sub_42bf60(app, cpu);
    // 0042bc7f  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0042bc83  8b8c24dc000000         -mov ecx, dword ptr [esp + 0xdc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 0042bc8a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042bc8b  8d4c2450               -lea ecx, [esp + 0x50]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0042bc8f  e8cc020000             -call 0x42bf60
    cpu.esp -= 4;
    sub_42bf60(app, cpu);
    // 0042bc94  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042bc98  8b9424e0000000         -mov edx, dword ptr [esp + 0xe0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0042bc9f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042bca0  8d54245c               -lea edx, [esp + 0x5c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0042bca4  e8b7020000             -call 0x42bf60
    cpu.esp -= 4;
    sub_42bf60(app, cpu);
    // 0042bca9  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042bcad  c78424e400000040400000 -mov dword ptr [esp + 0xe4], 0x4040
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */) = 16448 /*0x4040*/;
    // 0042bcb8  8b8424d0000000         -mov eax, dword ptr [esp + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 0042bcbf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042bcc1  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0042bcc4  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0042bcc8  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042bccd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042bcce  8d942484000000         -lea edx, [esp + 0x84]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0042bcd5  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042bcd7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042bcd8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bcd9  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042bcdc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042bcde  745c                   -je 0x42bd3c
    if (cpu.flags.zf)
    {
        goto L_0x0042bd3c;
    }
    // 0042bce0  68c46d4900             -push 0x496dc4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812228 /*0x496dc4*/;
    cpu.esp -= 4;
    // 0042bce5  e8cdb00400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042bcea  a168d44a00             -mov eax, dword ptr [0x4ad468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904040) /* 0x4ad468 */);
    // 0042bcef  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042bcf2  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042bcf6  c78424e400000040080000 -mov dword ptr [esp + 0xe4], 0x840
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */) = 2112 /*0x840*/;
    // 0042bd01  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042bd03  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042bd05  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042bd06  8d942484000000         -lea edx, [esp + 0x84]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0042bd0d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042bd0e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bd0f  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042bd12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042bd14  7426                   -je 0x42bd3c
    if (cpu.flags.zf)
    {
        goto L_0x0042bd3c;
    }
    // 0042bd16  689c6d4900             -push 0x496d9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812188 /*0x496d9c*/;
    cpu.esp -= 4;
    // 0042bd1b  e897b00400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042bd20  68846d4900             -push 0x496d84
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812164 /*0x496d84*/;
    cpu.esp -= 4;
    // 0042bd25  e88db00400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042bd2a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042bd2d  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bd2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bd30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bd31  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bd32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bd33  81c464010000           -add esp, 0x164
    (cpu.esp) += x86::reg32(x86::sreg32(356 /*0x164*/));
    // 0042bd39  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0042bd3c:
    // 0042bd3c  e82fe1ffff             -call 0x429e70
    cpu.esp -= 4;
    sub_429e70(app, cpu);
L_0x0042bd41:
    // 0042bd41  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042bd45  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042bd47  8d942480000000         -lea edx, [esp + 0x80]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0042bd4e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042bd50  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042bd52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042bd53  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042bd55  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bd56  ff5164                 -call dword ptr [ecx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042bd59  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042bd5e  74e1                   -je 0x42bd41
    if (cpu.flags.zf)
    {
        goto L_0x0042bd41;
    }
    // 0042bd60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042bd62  7429                   -je 0x42bd8d
    if (cpu.flags.zf)
    {
        goto L_0x0042bd8d;
    }
    // 0042bd64  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042bd66  e8d5ebffff             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042bd6b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bd6c  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042bd71  e841b00400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042bd76  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042bd7b  e8e7bb0400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042bd80  68706d4900             -push 0x496d70
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812144 /*0x496d70*/;
    cpu.esp -= 4;
    // 0042bd85  e82db00400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042bd8a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0042bd8d:
    // 0042bd8d  8b8424a0000000         -mov eax, dword ptr [esp + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0042bd94  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042bd98  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042bd9a  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0042bd9e  c744241800000000       -mov dword ptr [esp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0042bda6  0f8e4b010000           -jle 0x42bef7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042bef7;
    }
    // 0042bdac  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
L_0x0042bdb0:
    // 0042bdb0  8b4c2458               -mov ecx, dword ptr [esp + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0042bdb4  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042bdb8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042bdba  894c2460               -mov dword ptr [esp + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 0042bdbe  8a4302                 -mov al, byte ptr [ebx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0042bdc1  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 0042bdc5  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042bdc7  b881808080             -mov eax, 0x80808081
    cpu.eax = 2155905153 /*0x80808081*/;
    // 0042bdcc  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 0042bdcf  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0042bdd1  c1ea07                 -shr edx, 7
    cpu.edx >>= 7 /*0x7*/ % 32;
    // 0042bdd4  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042bdd6  8b7c2448               -mov edi, dword ptr [esp + 0x48]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0042bdda  0faf74245c             -imul esi, dword ptr [esp + 0x5c]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */))));
    // 0042bddf  8b8424d4000000         -mov eax, dword ptr [esp + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(212) /* 0xd4 */);
    // 0042bde6  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 0042bdeb  2bcf                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0042bded  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042bdef  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0042bdf2  8bac24d8000000         -mov ebp, dword ptr [esp + 0xd8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(216) /* 0xd8 */);
    // 0042bdf9  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 0042bdfb  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0042bdfe  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 0042be03  23f0                   -and esi, eax
    cpu.esi &= x86::reg32(x86::sreg32(cpu.eax));
    // 0042be05  b881808080             -mov eax, 0x80808081
    cpu.eax = 2155905153 /*0x80808081*/;
    // 0042be0a  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 0042be0c  c1ea07                 -shr edx, 7
    cpu.edx >>= 7 /*0x7*/ % 32;
    // 0042be0f  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042be11  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0042be15  0faf7c2450             -imul edi, dword ptr [esp + 0x50]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */))));
    // 0042be1a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042be1c  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042be1e  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0042be20  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 0042be22  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042be24  b881808080             -mov eax, 0x80808081
    cpu.eax = 2155905153 /*0x80808081*/;
    // 0042be29  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 0042be2c  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0042be2e  c1ea07                 -shr edx, 7
    cpu.edx >>= 7 /*0x7*/ % 32;
    // 0042be31  23fd                   -and edi, ebp
    cpu.edi &= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042be33  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0042be35  0faf6c244c             -imul ebp, dword ptr [esp + 0x4c]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */))));
    // 0042be3a  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0042be3e  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 0042be43  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0042be45  8a442440               -mov al, byte ptr [esp + 0x40]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0042be49  d3ed                   -shr ebp, cl
    cpu.ebp >>= cpu.cl % 32;
    // 0042be4b  8b8c24dc000000         -mov ecx, dword ptr [esp + 0xdc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(220) /* 0xdc */);
    // 0042be52  23e9                   -and ebp, ecx
    cpu.ebp &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042be54  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042be56  7540                   -jne 0x42be98
    if (!cpu.flags.zf)
    {
        goto L_0x0042be98;
    }
    // 0042be58  837c242801             +cmp dword ptr [esp + 0x28], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042be5d  750a                   -jne 0x42be69
    if (!cpu.flags.zf)
    {
        goto L_0x0042be69;
    }
    // 0042be5f  807b0340               +cmp byte ptr [ebx + 3], 0x40
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(64 /*0x40*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042be63  7604                   -jbe 0x42be69
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042be69;
    }
    // 0042be65  c64303ff               -mov byte ptr [ebx + 3], 0xff
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = 255 /*0xff*/;
L_0x0042be69:
    // 0042be69  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042be6b  b881808080             -mov eax, 0x80808081
    cpu.eax = 2155905153 /*0x80808081*/;
    // 0042be70  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0042be73  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 0042be78  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0042be7b  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 0042be7d  c1ea07                 -shr edx, 7
    cpu.edx >>= 7 /*0x7*/ % 32;
    // 0042be80  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042be82  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0042be86  0faf442454             -imul eax, dword ptr [esp + 0x54]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */))));
    // 0042be8b  2bca                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042be8d  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0042be8f  238424e0000000         +and eax, dword ptr [esp + 0xe0]
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */)))));
    // 0042be96  eb02                   -jmp 0x42be9a
    goto L_0x0042be9a;
L_0x0042be98:
    // 0042be98  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042be9a:
    // 0042be9a  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042be9e  0bc5                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042bea0  0bc7                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 0042bea2  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0042bea6  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0042beaa  0bc6                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 0042beac  668901                 -mov word ptr [ecx], ax
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.ax;
    // 0042beaf  a10cbb4900             -mov eax, dword ptr [0x49bb0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4832012) /* 0x49bb0c */);
    // 0042beb4  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0042beb6  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0042beba  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0042bebe  03d9                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042bec0  3bd0                   +cmp edx, eax
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
    // 0042bec2  7e1b                   -jle 0x42bedf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042bedf;
    }
    // 0042bec4  39442418               +cmp dword ptr [esp + 0x18], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042bec8  7515                   -jne 0x42bedf
    if (!cpu.flags.zf)
    {
        goto L_0x0042bedf;
    }
    // 0042beca  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042bece  c744241800000000       -mov dword ptr [esp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0042bed6  4a                     -dec edx
    (cpu.edx)--;
    // 0042bed7  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0042beda  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0042bedd  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0042bedf:
    // 0042bedf  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042bee3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042bee7  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042bee8  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042bee9  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0042beed  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042bef1  0f85b9feffff           -jne 0x42bdb0
    if (!cpu.flags.zf)
    {
        goto L_0x0042bdb0;
    }
L_0x0042bef7:
    // 0042bef7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042befb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042befd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042befe  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042bf00  ff9180000000           -call dword ptr [ecx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042bf06  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042bf08  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042bf0a  742c                   -je 0x42bf38
    if (cpu.flags.zf)
    {
        goto L_0x0042bf38;
    }
    // 0042bf0c  685c6d4900             -push 0x496d5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812124 /*0x496d5c*/;
    cpu.esp -= 4;
    // 0042bf11  e8a1ae0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042bf16  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042bf19  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042bf1b  e820eaffff             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042bf20  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bf21  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042bf26  e88cae0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042bf2b  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042bf30  e832ba0400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042bf35  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0042bf38:
    // 0042bf38  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042bf3c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042bf3d  e872b40400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0042bf42  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042bf46  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042bf49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bf4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bf4b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bf4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bf4d  81c464010000           -add esp, 0x164
    (cpu.esp) += x86::reg32(x86::sreg32(356 /*0x164*/));
    // 0042bf53  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42bf60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bf60  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042bf64  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bf65  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0042bf67  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0042bf6d  7510                   -jne 0x42bf7f
    if (!cpu.flags.zf)
    {
        goto L_0x0042bf7f;
    }
L_0x0042bf6f:
    // 0042bf6f  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0042bf71  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0042bf73  46                     -inc esi
    (cpu.esi)++;
    // 0042bf74  83fe1f                 +cmp esi, 0x1f
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042bf77  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0042bf79  7404                   -je 0x42bf7f
    if (cpu.flags.zf)
    {
        goto L_0x0042bf7f;
    }
    // 0042bf7b  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0042bf7d  74f0                   -je 0x42bf6f
    if (cpu.flags.zf)
    {
        goto L_0x0042bf6f;
    }
L_0x0042bf7f:
    // 0042bf7f  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0042bf81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042bf82  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42bf90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042bf90  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0042bf96  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bf97  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042bf98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042bf99  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042bf9d  683c6e4900             -push 0x496e3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812348 /*0x496e3c*/;
    cpu.esp -= 4;
    // 0042bfa2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bfa3  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0042bfa7  e84cae0400             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0042bfac  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042bfb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042bfb1  68306e4900             -push 0x496e30
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812336 /*0x496e30*/;
    cpu.esp -= 4;
    // 0042bfb6  e8fcad0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042bfbb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0042bfbe  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042bfc2  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042bfc6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042bfc8  e873faffff             -call 0x42ba40
    cpu.esp -= 4;
    sub_42ba40(app, cpu);
    // 0042bfcd  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042bfcf  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042bfd1  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042bfd3  e8b8860100             -call 0x444690
    cpu.esp -= 4;
    sub_444690(app, cpu);
    // 0042bfd8  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042bfda  f7de                   +neg esi
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
    // 0042bfdc  1bf6                   -sbb esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 0042bfde  f7de                   +neg esi
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
    // 0042bfe0  742d                   -je 0x42c00f
    if (cpu.flags.zf)
    {
        goto L_0x0042c00f;
    }
    // 0042bfe2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042bfe3  68206e4900             -push 0x496e20
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812320 /*0x496e20*/;
    cpu.esp -= 4;
    // 0042bfe8  e8caad0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042bfed  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042bff0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042bff2  e849e9ffff             -call 0x42a940
    cpu.esp -= 4;
    sub_42a940(app, cpu);
    // 0042bff7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042bff8  68a0cc4800             -push 0x48cca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4770976 /*0x48cca0*/;
    cpu.esp -= 4;
    // 0042bffd  e8b5ad0400             -call 0x476db7
    cpu.esp -= 4;
    sub_476db7(app, cpu);
    // 0042c002  68283d4a00             -push 0x4a3d28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4865320 /*0x4a3d28*/;
    cpu.esp -= 4;
    // 0042c007  e85bb90400             -call 0x477967
    cpu.esp -= 4;
    sub_477967(app, cpu);
    // 0042c00c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0042c00f:
    // 0042c00f  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042c011  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c012  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c013  81c484000000           -add esp, 0x84
    (cpu.esp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0042c019  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42c020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c020  81ec28010000           -sub esp, 0x128
    (cpu.esp) -= x86::reg32(x86::sreg32(296 /*0x128*/));
    // 0042c026  d9842430010000         -fld dword ptr [esp + 0x130]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(304) /* 0x130 */)));
    // 0042c02d  d80db8744800           -fmul dword ptr [0x4874b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 0042c033  d9842430010000         -fld dword ptr [esp + 0x130]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(304) /* 0x130 */)));
    // 0042c03a  d80d34734800           -fmul dword ptr [0x487334]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */));
    // 0042c040  d9842430010000         -fld dword ptr [esp + 0x130]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(304) /* 0x130 */)));
    // 0042c047  d80dd0754800           -fmul dword ptr [0x4875d0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748752) /* 0x4875d0 */));
    // 0042c04d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042c04e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c04f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c050  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042c052  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042c054  885c2470               -mov byte ptr [esp + 0x70], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.bl;
    // 0042c058  895c246c               -mov dword ptr [esp + 0x6c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebx;
    // 0042c05c  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0042c060  895c2448               -mov dword ptr [esp + 0x48], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.ebx;
    // 0042c064  895c243c               -mov dword ptr [esp + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 0042c068  c744244c0000803f       -mov dword ptr [esp + 0x4c], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = 1065353216 /*0x3f800000*/;
    // 0042c070  c74424400000803f       -mov dword ptr [esp + 0x40], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 1065353216 /*0x3f800000*/;
    // 0042c078  c74424500000803f       -mov dword ptr [esp + 0x50], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = 1065353216 /*0x3f800000*/;
    // 0042c080  c74424440000803f       -mov dword ptr [esp + 0x44], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = 1065353216 /*0x3f800000*/;
    // 0042c088  895c2454               -mov dword ptr [esp + 0x54], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.ebx;
    // 0042c08c  c74424640000803f       -mov dword ptr [esp + 0x64], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = 1065353216 /*0x3f800000*/;
    // 0042c094  c74424600000803f       -mov dword ptr [esp + 0x60], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = 1065353216 /*0x3f800000*/;
    // 0042c09c  c744245c0000803f       -mov dword ptr [esp + 0x5c], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 1065353216 /*0x3f800000*/;
    // 0042c0a4  c74424580000803f       -mov dword ptr [esp + 0x58], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = 1065353216 /*0x3f800000*/;
    // 0042c0ac  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0042c0b1  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042c0b3:
    // 0042c0b3  d9842438010000         -fld dword ptr [esp + 0x138]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(312) /* 0x138 */)));
    // 0042c0ba  d888506e4900           -fmul dword ptr [eax + 0x496e50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4812368) /* 0x496e50 */));
    // 0042c0c0  8d71ff                 -lea esi, [ecx - 1]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0042c0c3  81e60f000080           +and esi, 0x8000000f
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(2147483663 /*0x8000000f*/))));
    // 0042c0c9  d9fe                   +fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0042c0cb  dc0d48754800           +fmul qword ptr [0x487548]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748616) /* 0x487548 */));
    // 0042c0d1  d88c243c010000         +fmul dword ptr [esp + 0x13c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(316) /* 0x13c */));
    // 0042c0d8  d86204                 +fsub dword ptr [edx + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 0042c0db  d8c3                   +fadd st(3)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(3));
    // 0042c0dd  d95c0474               +fstp dword ptr [esp + eax + 0x74]
    app->getMemory<float>(cpu.esp + x86::reg32(116) /* 0x74 */ + cpu.eax * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c0e1  7905                   -jns 0x42c0e8
    if (!cpu.flags.sf)
    {
        goto L_0x0042c0e8;
    }
    // 0042c0e3  4e                     -dec esi
    (cpu.esi)--;
    // 0042c0e4  83cef0                 -or esi, 0xfffffff0
    cpu.esi |= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 0042c0e7  46                     -inc esi
    (cpu.esi)++;
L_0x0042c0e8:
    // 0042c0e8  d9842438010000         -fld dword ptr [esp + 0x138]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(312) /* 0x138 */)));
    // 0042c0ef  d80cb5506e4900         -fmul dword ptr [esi*4 + 0x496e50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4812368) /* 0x496e50 */ + cpu.esi * 4));
    // 0042c0f6  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042c0f8  81e60f000080           +and esi, 0x8000000f
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(2147483663 /*0x8000000f*/))));
    // 0042c0fe  d9fe                   +fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0042c100  dc0578754800           +fadd qword ptr [0x487578]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748664) /* 0x487578 */));
    // 0042c106  dc0dd8784800           +fmul qword ptr [0x4878d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749528) /* 0x4878d8 */));
    // 0042c10c  d88c243c010000         +fmul dword ptr [esp + 0x13c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(316) /* 0x13c */));
    // 0042c113  d86208                 +fsub dword ptr [edx + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0042c116  d8c2                   +fadd st(2)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(2));
    // 0042c118  d99c04f4000000         +fstp dword ptr [esp + eax + 0xf4]
    app->getMemory<float>(cpu.esp + x86::reg32(244) /* 0xf4 */ + cpu.eax * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c11f  7905                   -jns 0x42c126
    if (!cpu.flags.sf)
    {
        goto L_0x0042c126;
    }
    // 0042c121  4e                     -dec esi
    (cpu.esi)--;
    // 0042c122  83cef0                 -or esi, 0xfffffff0
    cpu.esi |= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 0042c125  46                     -inc esi
    (cpu.esi)++;
L_0x0042c126:
    // 0042c126  d9842438010000         -fld dword ptr [esp + 0x138]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(312) /* 0x138 */)));
    // 0042c12d  d80cb5506e4900         -fmul dword ptr [esi*4 + 0x496e50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4812368) /* 0x496e50 */ + cpu.esi * 4));
    // 0042c134  41                     -inc ecx
    (cpu.ecx)++;
    // 0042c135  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042c138  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0042c13a  8d71fe                 -lea esi, [ecx - 2]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 0042c13d  83fe10                 +cmp esi, 0x10
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
    // 0042c140  dc0d48754800           +fmul qword ptr [0x487548]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748616) /* 0x487548 */));
    // 0042c146  d88c243c010000         +fmul dword ptr [esp + 0x13c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(316) /* 0x13c */));
    // 0042c14d  d8620c                 +fsub dword ptr [edx + 0xc]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 0042c150  d8c1                   +fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0042c152  d99c04b0000000         +fstp dword ptr [esp + eax + 0xb0]
    app->getMemory<float>(cpu.esp + x86::reg32(176) /* 0xb0 */ + cpu.eax * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c159  0f8c54ffffff           -jl 0x42c0b3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042c0b3;
    }
    // 0042c15f  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c162  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042c164  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c166  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0042c169  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c16b  3bcb                   +cmp ecx, ebx
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
    // 0042c16d  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c16f  0f8e11030000           -jle 0x42c486
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042c486;
    }
L_0x0042c175:
    // 0042c175  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0042c178  8b1cb0                 -mov ebx, dword ptr [eax + esi*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0042c17b  d9431c                 -fld dword ptr [ebx + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(28) /* 0x1c */)));
    // 0042c17e  d81dd0784800           -fcomp dword ptr [0x4878d0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749520) /* 0x4878d0 */)));
    cpu.fpu.pop();
    // 0042c184  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c186  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c18b  0f85c7010000           -jne 0x42c358
    if (!cpu.flags.zf)
    {
        goto L_0x0042c358;
    }
    // 0042c191  d94320                 -fld dword ptr [ebx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
    // 0042c194  d81dd0784800           -fcomp dword ptr [0x4878d0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749520) /* 0x4878d0 */)));
    cpu.fpu.pop();
    // 0042c19a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c19c  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c1a1  0f85b1010000           -jne 0x42c358
    if (!cpu.flags.zf)
    {
        goto L_0x0042c358;
    }
    // 0042c1a7  8b0d50f85100           -mov ecx, dword ptr [0x51f850]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */);
    // 0042c1ad  81c1c8000000           -add ecx, 0xc8
    (cpu.ecx) += x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 0042c1b3  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0042c1b7  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0042c1bb  d85b1c                 -fcomp dword ptr [ebx + 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(28) /* 0x1c */)));
    cpu.fpu.pop();
    // 0042c1be  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c1c0  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c1c5  0f858d010000           -jne 0x42c358
    if (!cpu.flags.zf)
    {
        goto L_0x0042c358;
    }
    // 0042c1cb  8b1554f85100           -mov edx, dword ptr [0x51f854]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */);
    // 0042c1d1  81c2c8000000           -add edx, 0xc8
    (cpu.edx) += x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 0042c1d7  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0042c1db  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0042c1df  d85b20                 -fcomp dword ptr [ebx + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0042c1e2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c1e4  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c1e9  0f8569010000           -jne 0x42c358
    if (!cpu.flags.zf)
    {
        goto L_0x0042c358;
    }
    // 0042c1ef  d94318                 -fld dword ptr [ebx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 0042c1f2  d81d18744800           -fcomp dword ptr [0x487418]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748312) /* 0x487418 */)));
    cpu.fpu.pop();
    // 0042c1f8  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c1fa  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c1ff  0f8553010000           -jne 0x42c358
    if (!cpu.flags.zf)
    {
        goto L_0x0042c358;
    }
    // 0042c205  d94318                 -fld dword ptr [ebx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 0042c208  d81d5c764800           -fcomp dword ptr [0x48765c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748892) /* 0x48765c */)));
    cpu.fpu.pop();
    // 0042c20e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c210  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042c213  0f8a3f010000           -jp 0x42c358
    if (cpu.flags.pf)
    {
        goto L_0x0042c358;
    }
    // 0042c219  d9431c                 -fld dword ptr [ebx + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(28) /* 0x1c */)));
    // 0042c21c  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0042c222  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c224  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 0042c229  0f85d4000000           -jne 0x42c303
    if (!cpu.flags.zf)
    {
        goto L_0x0042c303;
    }
    // 0042c22f  d94320                 -fld dword ptr [ebx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
    // 0042c232  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0042c238  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c23a  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c23f  0f85be000000           -jne 0x42c303
    if (!cpu.flags.zf)
    {
        goto L_0x0042c303;
    }
    // 0042c245  db0550f85100           -fild dword ptr [0x51f850]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */))));
    // 0042c24b  d85b1c                 -fcomp dword ptr [ebx + 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(28) /* 0x1c */)));
    cpu.fpu.pop();
    // 0042c24e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c250  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c255  0f85a8000000           -jne 0x42c303
    if (!cpu.flags.zf)
    {
        goto L_0x0042c303;
    }
    // 0042c25b  db0554f85100           -fild dword ptr [0x51f854]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */))));
    // 0042c261  d85b20                 -fcomp dword ptr [ebx + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0042c264  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c266  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c26b  0f8592000000           -jne 0x42c303
    if (!cpu.flags.zf)
    {
        goto L_0x0042c303;
    }
    // 0042c271  d90508754800           -fld dword ptr [0x487508]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748552) /* 0x487508 */)));
    // 0042c277  d87318                 -fdiv dword ptr [ebx + 0x18]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */));
    // 0042c27a  d9431c                 -fld dword ptr [ebx + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(28) /* 0x1c */)));
    // 0042c27d  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 0042c27f  e80cab0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c284  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0042c288  d94320                 -fld dword ptr [ebx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
    // 0042c28b  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 0042c28d  e8feaa0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c292  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0042c296  d9431c                 -fld dword ptr [ebx + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(28) /* 0x1c */)));
    // 0042c299  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 0042c29b  e8f0aa0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c2a0  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042c2a2  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0042c2a6  d84320                 -fadd dword ptr [ebx + 0x20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */));
    // 0042c2a9  e8e2aa0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c2ae  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042c2b0  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0042c2b4  d8431c                 -fadd dword ptr [ebx + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(28) /* 0x1c */));
    // 0042c2b7  e8d4aa0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c2bc  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042c2be  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0042c2c2  d84320                 -fadd dword ptr [ebx + 0x20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */));
    // 0042c2c5  e8c6aa0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c2ca  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042c2cc  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0042c2d0  d8431c                 -fadd dword ptr [ebx + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(28) /* 0x1c */));
    // 0042c2d3  e8b8aa0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c2d8  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0042c2dc  d94320                 -fld dword ptr [ebx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
    // 0042c2df  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 0042c2e1  e8aaaa0400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c2e6  8b0da4d44a00           -mov ecx, dword ptr [0x4ad4a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904100) /* 0x4ad4a4 */);
    // 0042c2ec  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0042c2f0  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0042c2f3  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042c2f7  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c2f9  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 0042c2fd  ff1560845100           -call dword ptr [0x518460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342304) /* 0x518460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042c303:
    // 0042c303  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c306  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042c308  250f000080             +and eax, 0x8000000f
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2147483663 /*0x8000000f*/))));
    // 0042c30d  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042c310  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0042c313  7905                   -jns 0x42c31a
    if (!cpu.flags.sf)
    {
        goto L_0x0042c31a;
    }
    // 0042c315  48                     -dec eax
    (cpu.eax)--;
    // 0042c316  83c8f0                 -or eax, 0xfffffff0
    cpu.eax |= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 0042c319  40                     -inc eax
    (cpu.eax)++;
L_0x0042c31a:
    // 0042c31a  c1e002                 +shl eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.eax);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0042c31d  d9440474               +fld dword ptr [esp + eax + 0x74]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(116) /* 0x74 */ + cpu.eax * 1)));
    // 0042c321  d84104                 +fadd dword ptr [ecx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */));
    // 0042c324  d95904                 +fstp dword ptr [ecx + 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c327  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c32a  d98404f4000000         +fld dword ptr [esp + eax + 0xf4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(244) /* 0xf4 */ + cpu.eax * 1)));
    // 0042c331  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042c334  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0042c337  d84108                 +fadd dword ptr [ecx + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */));
    // 0042c33a  d95908                 +fstp dword ptr [ecx + 8]
    app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c33d  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c340  d98404b4000000         +fld dword ptr [esp + eax + 0xb4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(180) /* 0xb4 */ + cpu.eax * 1)));
    // 0042c347  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042c34a  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0042c34d  d8410c                 +fadd dword ptr [ecx + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */));
    // 0042c350  d9590c                 +fstp dword ptr [ecx + 0xc]
    app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c353  e921010000             -jmp 0x42c479
    goto L_0x0042c479;
L_0x0042c358:
    // 0042c358  e843130200             -call 0x44d6a0
    cpu.esp -= 4;
    sub_44d6a0(app, cpu);
    // 0042c35d  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042c360  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042c363  b803000180             -mov eax, 0x80010003
    cpu.eax = 2147549187 /*0x80010003*/;
    // 0042c368  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0042c36b  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0042c36d  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042c36f  c1fa0e                 -sar edx, 0xe
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (14 /*0xe*/ % 32));
    // 0042c372  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042c374  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 0042c377  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042c379  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0042c37d  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0042c381  d80594744800           -fadd dword ptr [0x487494]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 0042c387  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c38b  e810130200             -call 0x44d6a0
    cpu.esp -= 4;
    sub_44d6a0(app, cpu);
    // 0042c390  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042c393  b803000180             -mov eax, 0x80010003
    cpu.eax = 2147549187 /*0x80010003*/;
    // 0042c398  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0042c39b  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0042c39d  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042c39f  c1fa0e                 -sar edx, 0xe
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (14 /*0xe*/ % 32));
    // 0042c3a2  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042c3a4  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 0042c3a7  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042c3a9  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0042c3ad  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0042c3b1  d825d0754800           -fsub dword ptr [0x4875d0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748752) /* 0x4875d0 */));
    // 0042c3b7  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0042c3bb  d80dcc784800           -fmul dword ptr [0x4878cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749516) /* 0x4878cc */));
    // 0042c3c1  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c3c5  e8d6120200             -call 0x44d6a0
    cpu.esp -= 4;
    sub_44d6a0(app, cpu);
    // 0042c3ca  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042c3cd  b803000180             -mov eax, 0x80010003
    cpu.eax = 2147549187 /*0x80010003*/;
    // 0042c3d2  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0042c3d5  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0042c3d7  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042c3d9  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042c3df  c1fa0e                 -sar edx, 0xe
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (14 /*0xe*/ % 32));
    // 0042c3e2  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042c3e4  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 0042c3e7  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042c3e9  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042c3eb  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0042c3ef  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c3f2  db442414               -fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0042c3f6  d825d0754800           -fsub dword ptr [0x4875d0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748752) /* 0x4875d0 */));
    // 0042c3fc  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0042c400  d80dcc784800           -fmul dword ptr [0x4878cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749516) /* 0x4878cc */));
    // 0042c406  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042c408  d84874                 -fmul dword ptr [eax + 0x74]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(116) /* 0x74 */));
    // 0042c40b  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0042c40f  d8484c                 -fmul dword ptr [eax + 0x4c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(76) /* 0x4c */));
    // 0042c412  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042c414  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0042c418  d84824                 -fmul dword ptr [eax + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */));
    // 0042c41b  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0042c41e  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0042c421  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042c423  d95904                 -fstp dword ptr [ecx + 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c426  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042c42c  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042c42e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042c430  d84878                 -fmul dword ptr [eax + 0x78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(120) /* 0x78 */));
    // 0042c433  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0042c437  d84850                 -fmul dword ptr [eax + 0x50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(80) /* 0x50 */));
    // 0042c43a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042c43c  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0042c440  d84828                 -fmul dword ptr [eax + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */));
    // 0042c443  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c446  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0042c449  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0042c44c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042c44e  d95a08                 -fstp dword ptr [edx + 8]
    app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c451  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042c456  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c459  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0042c45b  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042c45e  d8487c                 -fmul dword ptr [eax + 0x7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(124) /* 0x7c */));
    // 0042c461  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0042c465  d84854                 -fmul dword ptr [eax + 0x54]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */));
    // 0042c468  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042c46a  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0042c46e  d8482c                 -fmul dword ptr [eax + 0x2c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */));
    // 0042c471  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0042c474  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042c476  d9580c                 -fstp dword ptr [eax + 0xc]
    app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0042c479:
    // 0042c479  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c47c  46                     -inc esi
    (cpu.esi)++;
    // 0042c47d  3b7008                 +cmp esi, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c480  0f8ceffcffff           -jl 0x42c175
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042c175;
    }
L_0x0042c486:
    // 0042c486  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c487  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c488  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c489  81c428010000           -add esp, 0x128
    (cpu.esp) += x86::reg32(x86::sreg32(296 /*0x128*/));
    // 0042c48f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_42c4a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c4a0  d90554095200           -fld dword ptr [0x520954]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5376340) /* 0x520954 */)));
    // 0042c4a6  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0042c4ac  81ec28010000           -sub esp, 0x128
    (cpu.esp) -= x86::reg32(x86::sreg32(296 /*0x128*/));
    // 0042c4b2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042c4b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042c4b4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c4b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c4b7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c4b8  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0042c4bb  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042c4bd  7a07                   -jp 0x42c4c6
    if (cpu.flags.pf)
    {
        goto L_0x0042c4c6;
    }
    // 0042c4bf  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0042c4c4  eb02                   -jmp 0x42c4c8
    goto L_0x0042c4c8;
L_0x0042c4c6:
    // 0042c4c6  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0042c4c8:
    // 0042c4c8  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042c4ca  c644247400             -mov byte ptr [esp + 0x74], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(116) /* 0x74 */) = 0 /*0x0*/;
    // 0042c4cf  89742470               -mov dword ptr [esp + 0x70], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.esi;
    // 0042c4d3  8974243c               -mov dword ptr [esp + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 0042c4d7  8974244c               -mov dword ptr [esp + 0x4c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.esi;
    // 0042c4db  89742440               -mov dword ptr [esp + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 0042c4df  c74424500000803f       -mov dword ptr [esp + 0x50], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = 1065353216 /*0x3f800000*/;
    // 0042c4e7  c74424440000803f       -mov dword ptr [esp + 0x44], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = 1065353216 /*0x3f800000*/;
    // 0042c4ef  c74424540000803f       -mov dword ptr [esp + 0x54], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = 1065353216 /*0x3f800000*/;
    // 0042c4f7  c74424480000803f       -mov dword ptr [esp + 0x48], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = 1065353216 /*0x3f800000*/;
    // 0042c4ff  89742458               -mov dword ptr [esp + 0x58], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.esi;
    // 0042c503  c74424680000803f       -mov dword ptr [esp + 0x68], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = 1065353216 /*0x3f800000*/;
    // 0042c50b  c74424640000803f       -mov dword ptr [esp + 0x64], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = 1065353216 /*0x3f800000*/;
    // 0042c513  c74424600000803f       -mov dword ptr [esp + 0x60], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = 1065353216 /*0x3f800000*/;
    // 0042c51b  c744245c0000803f       -mov dword ptr [esp + 0x5c], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 1065353216 /*0x3f800000*/;
    // 0042c523  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0042c528  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042c52a:
    // 0042c52a  d984243c010000         -fld dword ptr [esp + 0x13c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(316) /* 0x13c */)));
    // 0042c531  d888506e4900           -fmul dword ptr [eax + 0x496e50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4812368) /* 0x496e50 */));
    // 0042c537  8d69ff                 -lea ebp, [ecx - 1]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0042c53a  81e50f000080           +and ebp, 0x8000000f
    cpu.clear_co();
    cpu.set_szp((cpu.ebp &= x86::reg32(x86::sreg32(2147483663 /*0x8000000f*/))));
    // 0042c540  d9fe                   +fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0042c542  dc0d48754800           +fmul qword ptr [0x487548]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748616) /* 0x487548 */));
    // 0042c548  d88c2440010000         +fmul dword ptr [esp + 0x140]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(320) /* 0x140 */));
    // 0042c54f  d86204                 +fsub dword ptr [edx + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 0042c552  d95c0478               +fstp dword ptr [esp + eax + 0x78]
    app->getMemory<float>(cpu.esp + x86::reg32(120) /* 0x78 */ + cpu.eax * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c556  7905                   -jns 0x42c55d
    if (!cpu.flags.sf)
    {
        goto L_0x0042c55d;
    }
    // 0042c558  4d                     -dec ebp
    (cpu.ebp)--;
    // 0042c559  83cdf0                 -or ebp, 0xfffffff0
    cpu.ebp |= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 0042c55c  45                     -inc ebp
    (cpu.ebp)++;
L_0x0042c55d:
    // 0042c55d  d984243c010000         -fld dword ptr [esp + 0x13c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(316) /* 0x13c */)));
    // 0042c564  d80cad506e4900         -fmul dword ptr [ebp*4 + 0x496e50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4812368) /* 0x496e50 */ + cpu.ebp * 4));
    // 0042c56b  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0042c56d  81e50f000080           +and ebp, 0x8000000f
    cpu.clear_co();
    cpu.set_szp((cpu.ebp &= x86::reg32(x86::sreg32(2147483663 /*0x8000000f*/))));
    // 0042c573  d9fe                   +fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0042c575  dc0578754800           +fadd qword ptr [0x487578]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748664) /* 0x487578 */));
    // 0042c57b  dc0de0784800           +fmul qword ptr [0x4878e0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749536) /* 0x4878e0 */));
    // 0042c581  d88c2440010000         +fmul dword ptr [esp + 0x140]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(320) /* 0x140 */));
    // 0042c588  d86208                 +fsub dword ptr [edx + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0042c58b  d99c04f8000000         +fstp dword ptr [esp + eax + 0xf8]
    app->getMemory<float>(cpu.esp + x86::reg32(248) /* 0xf8 */ + cpu.eax * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c592  7905                   -jns 0x42c599
    if (!cpu.flags.sf)
    {
        goto L_0x0042c599;
    }
    // 0042c594  4d                     -dec ebp
    (cpu.ebp)--;
    // 0042c595  83cdf0                 -or ebp, 0xfffffff0
    cpu.ebp |= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 0042c598  45                     -inc ebp
    (cpu.ebp)++;
L_0x0042c599:
    // 0042c599  d984243c010000         -fld dword ptr [esp + 0x13c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(316) /* 0x13c */)));
    // 0042c5a0  d80cad506e4900         -fmul dword ptr [ebp*4 + 0x496e50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4812368) /* 0x496e50 */ + cpu.ebp * 4));
    // 0042c5a7  41                     -inc ecx
    (cpu.ecx)++;
    // 0042c5a8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042c5ab  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0042c5ad  8d69fe                 -lea ebp, [ecx - 2]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 0042c5b0  83fd10                 +cmp ebp, 0x10
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c5b3  dc0d48754800           +fmul qword ptr [0x487548]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4748616) /* 0x487548 */));
    // 0042c5b9  d88c2440010000         +fmul dword ptr [esp + 0x140]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(320) /* 0x140 */));
    // 0042c5c0  d8620c                 +fsub dword ptr [edx + 0xc]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 0042c5c3  d99c04b4000000         +fstp dword ptr [esp + eax + 0xb4]
    app->getMemory<float>(cpu.esp + x86::reg32(180) /* 0xb4 */ + cpu.eax * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c5ca  0f8c5affffff           -jl 0x42c52a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042c52a;
    }
    // 0042c5d0  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c5d3  397008                 +cmp dword ptr [eax + 8], esi
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
    // 0042c5d6  0f8e25030000           -jle 0x42c901
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042c901;
    }
L_0x0042c5dc:
    // 0042c5dc  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0042c5df  8b2cb0                 -mov ebp, dword ptr [eax + esi*4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0042c5e2  d9451c                 -fld dword ptr [ebp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 0042c5e5  d81dd0784800           -fcomp dword ptr [0x4878d0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749520) /* 0x4878d0 */)));
    cpu.fpu.pop();
    // 0042c5eb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c5ed  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c5f2  0f85db010000           -jne 0x42c7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0042c7d3;
    }
    // 0042c5f8  d94520                 -fld dword ptr [ebp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    // 0042c5fb  d81dd0784800           -fcomp dword ptr [0x4878d0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749520) /* 0x4878d0 */)));
    cpu.fpu.pop();
    // 0042c601  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c603  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c608  0f85c5010000           -jne 0x42c7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0042c7d3;
    }
    // 0042c60e  8b0d50f85100           -mov ecx, dword ptr [0x51f850]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */);
    // 0042c614  81c1c8000000           -add ecx, 0xc8
    (cpu.ecx) += x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 0042c61a  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0042c61e  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0042c622  d85d1c                 -fcomp dword ptr [ebp + 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    cpu.fpu.pop();
    // 0042c625  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c627  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c62c  0f85a1010000           -jne 0x42c7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0042c7d3;
    }
    // 0042c632  8b1554f85100           -mov edx, dword ptr [0x51f854]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */);
    // 0042c638  81c2c8000000           -add edx, 0xc8
    (cpu.edx) += x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 0042c63e  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042c642  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0042c646  d85d20                 -fcomp dword ptr [ebp + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0042c649  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c64b  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c650  0f857d010000           -jne 0x42c7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0042c7d3;
    }
    // 0042c656  d94518                 -fld dword ptr [ebp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 0042c659  d81d18744800           -fcomp dword ptr [0x487418]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748312) /* 0x487418 */)));
    cpu.fpu.pop();
    // 0042c65f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c661  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c666  0f8567010000           -jne 0x42c7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0042c7d3;
    }
    // 0042c66c  d94518                 -fld dword ptr [ebp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 0042c66f  d81d5c764800           -fcomp dword ptr [0x48765c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748892) /* 0x48765c */)));
    cpu.fpu.pop();
    // 0042c675  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c677  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042c67a  0f8a53010000           -jp 0x42c7d3
    if (cpu.flags.pf)
    {
        goto L_0x0042c7d3;
    }
    // 0042c680  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042c682  751c                   -jne 0x42c6a0
    if (!cpu.flags.zf)
    {
        goto L_0x0042c6a0;
    }
    // 0042c684  d90554095200           -fld dword ptr [0x520954]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5376340) /* 0x520954 */)));
    // 0042c68a  d84d08                 -fmul dword ptr [ebp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 0042c68d  d81de40d5200           -fcomp dword ptr [0x520de4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(5377508) /* 0x520de4 */)));
    cpu.fpu.pop();
    // 0042c693  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c695  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c69a  0f8533010000           -jne 0x42c7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0042c7d3;
    }
L_0x0042c6a0:
    // 0042c6a0  d9451c                 -fld dword ptr [ebp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 0042c6a3  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0042c6a9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c6ab  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 0042c6b0  0f85c8000000           -jne 0x42c77e
    if (!cpu.flags.zf)
    {
        goto L_0x0042c77e;
    }
    // 0042c6b6  d94520                 -fld dword ptr [ebp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    // 0042c6b9  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0042c6bf  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c6c1  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c6c6  0f85b2000000           -jne 0x42c77e
    if (!cpu.flags.zf)
    {
        goto L_0x0042c77e;
    }
    // 0042c6cc  db0550f85100           -fild dword ptr [0x51f850]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */))));
    // 0042c6d2  d85d1c                 -fcomp dword ptr [ebp + 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    cpu.fpu.pop();
    // 0042c6d5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c6d7  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c6dc  0f859c000000           -jne 0x42c77e
    if (!cpu.flags.zf)
    {
        goto L_0x0042c77e;
    }
    // 0042c6e2  db0554f85100           -fild dword ptr [0x51f854]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */))));
    // 0042c6e8  d85d20                 -fcomp dword ptr [ebp + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0042c6eb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c6ed  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042c6f2  0f8586000000           -jne 0x42c77e
    if (!cpu.flags.zf)
    {
        goto L_0x0042c77e;
    }
    // 0042c6f8  d90504754800           -fld dword ptr [0x487504]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748548) /* 0x487504 */)));
    // 0042c6fe  d87518                 -fdiv dword ptr [ebp + 0x18]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */));
    // 0042c701  d9451c                 -fld dword ptr [ebp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 0042c704  e887a60400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c709  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0042c70d  d94520                 -fld dword ptr [ebp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    // 0042c710  e87ba60400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c715  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0042c719  d9451c                 -fld dword ptr [ebp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 0042c71c  e86fa60400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c721  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042c723  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0042c727  d84520                 -fadd dword ptr [ebp + 0x20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */));
    // 0042c72a  e861a60400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c72f  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042c731  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0042c735  d8451c                 -fadd dword ptr [ebp + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */));
    // 0042c738  e853a60400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c73d  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042c73f  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0042c743  d84520                 -fadd dword ptr [ebp + 0x20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */));
    // 0042c746  e845a60400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c74b  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0042c74f  d8451c                 -fadd dword ptr [ebp + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */));
    // 0042c752  e839a60400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c757  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0042c75b  d94520                 -fld dword ptr [ebp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    // 0042c75e  e82da60400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042c763  8b0da4d44a00           -mov ecx, dword ptr [0x4ad4a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904100) /* 0x4ad4a4 */);
    // 0042c769  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0042c76d  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0042c770  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042c774  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0042c778  ff1560845100           -call dword ptr [0x518460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342304) /* 0x518460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042c77e:
    // 0042c77e  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c781  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042c783  250f000080             +and eax, 0x8000000f
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2147483663 /*0x8000000f*/))));
    // 0042c788  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042c78b  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0042c78e  7905                   -jns 0x42c795
    if (!cpu.flags.sf)
    {
        goto L_0x0042c795;
    }
    // 0042c790  48                     -dec eax
    (cpu.eax)--;
    // 0042c791  83c8f0                 -or eax, 0xfffffff0
    cpu.eax |= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 0042c794  40                     -inc eax
    (cpu.eax)++;
L_0x0042c795:
    // 0042c795  c1e002                 +shl eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.eax);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0042c798  d9440478               +fld dword ptr [esp + eax + 0x78]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(120) /* 0x78 */ + cpu.eax * 1)));
    // 0042c79c  d84104                 +fadd dword ptr [ecx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */));
    // 0042c79f  d95904                 +fstp dword ptr [ecx + 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c7a2  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c7a5  d98404f8000000         +fld dword ptr [esp + eax + 0xf8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(248) /* 0xf8 */ + cpu.eax * 1)));
    // 0042c7ac  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042c7af  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0042c7b2  d84108                 +fadd dword ptr [ecx + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */));
    // 0042c7b5  d95908                 +fstp dword ptr [ecx + 8]
    app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c7b8  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c7bb  d98404b8000000         +fld dword ptr [esp + eax + 0xb8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(184) /* 0xb8 */ + cpu.eax * 1)));
    // 0042c7c2  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042c7c5  8b0cb2                 -mov ecx, dword ptr [edx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0042c7c8  d8410c                 +fadd dword ptr [ecx + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */));
    // 0042c7cb  d9590c                 +fstp dword ptr [ecx + 0xc]
    app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c7ce  e921010000             -jmp 0x42c8f4
    goto L_0x0042c8f4;
L_0x0042c7d3:
    // 0042c7d3  e8c80e0200             -call 0x44d6a0
    cpu.esp -= 4;
    sub_44d6a0(app, cpu);
    // 0042c7d8  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042c7db  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042c7de  b803000180             -mov eax, 0x80010003
    cpu.eax = 2147549187 /*0x80010003*/;
    // 0042c7e3  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0042c7e6  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0042c7e8  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042c7ea  c1fa0e                 -sar edx, 0xe
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (14 /*0xe*/ % 32));
    // 0042c7ed  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042c7ef  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 0042c7f2  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042c7f4  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042c7f8  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0042c7fc  d80594744800           -fadd dword ptr [0x487494]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 0042c802  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c806  e8950e0200             -call 0x44d6a0
    cpu.esp -= 4;
    sub_44d6a0(app, cpu);
    // 0042c80b  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042c80e  b803000180             -mov eax, 0x80010003
    cpu.eax = 2147549187 /*0x80010003*/;
    // 0042c813  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0042c816  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0042c818  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042c81a  c1fa0e                 -sar edx, 0xe
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (14 /*0xe*/ % 32));
    // 0042c81d  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042c81f  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 0042c822  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042c824  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042c828  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0042c82c  d825d0754800           -fsub dword ptr [0x4875d0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748752) /* 0x4875d0 */));
    // 0042c832  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0042c836  d80dcc784800           -fmul dword ptr [0x4878cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749516) /* 0x4878cc */));
    // 0042c83c  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c840  e85b0e0200             -call 0x44d6a0
    cpu.esp -= 4;
    sub_44d6a0(app, cpu);
    // 0042c845  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042c848  b803000180             -mov eax, 0x80010003
    cpu.eax = 2147549187 /*0x80010003*/;
    // 0042c84d  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0042c850  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0042c852  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042c854  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042c85a  c1fa0e                 -sar edx, 0xe
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (14 /*0xe*/ % 32));
    // 0042c85d  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042c85f  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 0042c862  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042c864  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042c866  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0042c86a  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c86d  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0042c871  d825d0754800           -fsub dword ptr [0x4875d0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748752) /* 0x4875d0 */));
    // 0042c877  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0042c87b  d80dcc784800           -fmul dword ptr [0x4878cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749516) /* 0x4878cc */));
    // 0042c881  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042c883  d84874                 -fmul dword ptr [eax + 0x74]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(116) /* 0x74 */));
    // 0042c886  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0042c88a  d8484c                 -fmul dword ptr [eax + 0x4c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(76) /* 0x4c */));
    // 0042c88d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042c88f  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0042c893  d84824                 -fmul dword ptr [eax + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */));
    // 0042c896  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0042c899  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0042c89c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042c89e  d95904                 -fstp dword ptr [ecx + 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c8a1  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042c8a7  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042c8a9  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042c8ab  d84878                 -fmul dword ptr [eax + 0x78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(120) /* 0x78 */));
    // 0042c8ae  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0042c8b2  d84850                 -fmul dword ptr [eax + 0x50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(80) /* 0x50 */));
    // 0042c8b5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042c8b7  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0042c8bb  d84828                 -fmul dword ptr [eax + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */));
    // 0042c8be  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c8c1  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0042c8c4  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0042c8c7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042c8c9  d95a08                 -fstp dword ptr [edx + 8]
    app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c8cc  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042c8d1  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c8d4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0042c8d6  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042c8d9  d8487c                 -fmul dword ptr [eax + 0x7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(124) /* 0x7c */));
    // 0042c8dc  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0042c8e0  d84854                 -fmul dword ptr [eax + 0x54]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */));
    // 0042c8e3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042c8e5  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0042c8e9  d8482c                 -fmul dword ptr [eax + 0x2c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */));
    // 0042c8ec  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0042c8ef  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042c8f1  d9580c                 -fstp dword ptr [eax + 0xc]
    app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0042c8f4:
    // 0042c8f4  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042c8f7  46                     -inc esi
    (cpu.esi)++;
    // 0042c8f8  3b7008                 +cmp esi, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042c8fb  0f8cdbfcffff           -jl 0x42c5dc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042c5dc;
    }
L_0x0042c901:
    // 0042c901  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c902  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c903  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c904  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042c905  81c428010000           -add esp, 0x128
    (cpu.esp) += x86::reg32(x86::sreg32(296 /*0x128*/));
    // 0042c90b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_42c910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042c910  81ec30010000           -sub esp, 0x130
    (cpu.esp) -= x86::reg32(x86::sreg32(304 /*0x130*/));
    // 0042c916  d90554095200           -fld dword ptr [0x520954]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5376340) /* 0x520954 */)));
    // 0042c91c  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0042c922  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042c923  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042c924  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042c925  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042c927  c744241c01000000       -mov dword ptr [esp + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 0042c92f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042c931  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0042c934  7b08                   -jnp 0x42c93e
    if (!cpu.flags.pf)
    {
        goto L_0x0042c93e;
    }
    // 0042c936  c744241c00000000       -mov dword ptr [esp + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x0042c93e:
    // 0042c93e  d9842444010000         -fld dword ptr [esp + 0x144]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(324) /* 0x144 */)));
    // 0042c945  d80db8744800           -fmul dword ptr [0x4874b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748472) /* 0x4874b8 */));
    // 0042c94b  d9842444010000         -fld dword ptr [esp + 0x144]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(324) /* 0x144 */)));
    // 0042c952  d80d34734800           -fmul dword ptr [0x487334]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */));
    // 0042c958  d9842444010000         -fld dword ptr [esp + 0x144]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(324) /* 0x144 */)));
    // 0042c95f  d80dd0754800           -fmul dword ptr [0x4875d0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4748752) /* 0x4875d0 */));
    // 0042c965  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042c967  c644247800             -mov byte ptr [esp + 0x78], 0
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 0042c96c  895c2474               -mov dword ptr [esp + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.ebx;
    // 0042c970  895c2440               -mov dword ptr [esp + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 0042c974  895c2450               -mov dword ptr [esp + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 0042c978  895c2444               -mov dword ptr [esp + 0x44], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ebx;
    // 0042c97c  c74424540000803f       -mov dword ptr [esp + 0x54], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = 1065353216 /*0x3f800000*/;
    // 0042c984  c74424480000803f       -mov dword ptr [esp + 0x48], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = 1065353216 /*0x3f800000*/;
    // 0042c98c  c74424580000803f       -mov dword ptr [esp + 0x58], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = 1065353216 /*0x3f800000*/;
    // 0042c994  c744244c0000803f       -mov dword ptr [esp + 0x4c], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = 1065353216 /*0x3f800000*/;
    // 0042c99c  c744245c0000803f       -mov dword ptr [esp + 0x5c], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 1065353216 /*0x3f800000*/;
    // 0042c9a4  c74424680000803f       -mov dword ptr [esp + 0x68], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = 1065353216 /*0x3f800000*/;
    // 0042c9ac  c74424640000803f       -mov dword ptr [esp + 0x64], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = 1065353216 /*0x3f800000*/;
    // 0042c9b4  c74424600000803f       -mov dword ptr [esp + 0x60], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = 1065353216 /*0x3f800000*/;
    // 0042c9bc  c744246c0000803f       -mov dword ptr [esp + 0x6c], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = 1065353216 /*0x3f800000*/;
    // 0042c9c4  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0042c9c9  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042c9cb:
    // 0042c9cb  d9842440010000         -fld dword ptr [esp + 0x140]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(320) /* 0x140 */)));
    // 0042c9d2  d888506e4900           -fmul dword ptr [eax + 0x496e50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4812368) /* 0x496e50 */));
    // 0042c9d8  8d71ff                 -lea esi, [ecx - 1]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0042c9db  81e60f000080           +and esi, 0x8000000f
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(2147483663 /*0x8000000f*/))));
    // 0042c9e1  d9fe                   +fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0042c9e3  dc0df8784800           +fmul qword ptr [0x4878f8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749560) /* 0x4878f8 */));
    // 0042c9e9  d88c2444010000         +fmul dword ptr [esp + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(324) /* 0x144 */));
    // 0042c9f0  d86204                 +fsub dword ptr [edx + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 0042c9f3  d8c3                   +fadd st(3)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(3));
    // 0042c9f5  d95c047c               +fstp dword ptr [esp + eax + 0x7c]
    app->getMemory<float>(cpu.esp + x86::reg32(124) /* 0x7c */ + cpu.eax * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042c9f9  7905                   -jns 0x42ca00
    if (!cpu.flags.sf)
    {
        goto L_0x0042ca00;
    }
    // 0042c9fb  4e                     -dec esi
    (cpu.esi)--;
    // 0042c9fc  83cef0                 -or esi, 0xfffffff0
    cpu.esi |= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 0042c9ff  46                     -inc esi
    (cpu.esi)++;
L_0x0042ca00:
    // 0042ca00  d9842440010000         -fld dword ptr [esp + 0x140]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(320) /* 0x140 */)));
    // 0042ca07  d80cb5506e4900         -fmul dword ptr [esi*4 + 0x496e50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4812368) /* 0x496e50 */ + cpu.esi * 4));
    // 0042ca0e  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042ca10  81e60f000080           +and esi, 0x8000000f
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(2147483663 /*0x8000000f*/))));
    // 0042ca16  d9fe                   +fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0042ca18  dc0578754800           +fadd qword ptr [0x487578]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4748664) /* 0x487578 */));
    // 0042ca1e  dc0df0784800           +fmul qword ptr [0x4878f0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749552) /* 0x4878f0 */));
    // 0042ca24  d88c2444010000         +fmul dword ptr [esp + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(324) /* 0x144 */));
    // 0042ca2b  d86208                 +fsub dword ptr [edx + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0042ca2e  d8c2                   +fadd st(2)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(2));
    // 0042ca30  d99c04fc000000         +fstp dword ptr [esp + eax + 0xfc]
    app->getMemory<float>(cpu.esp + x86::reg32(252) /* 0xfc */ + cpu.eax * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042ca37  7905                   -jns 0x42ca3e
    if (!cpu.flags.sf)
    {
        goto L_0x0042ca3e;
    }
    // 0042ca39  4e                     -dec esi
    (cpu.esi)--;
    // 0042ca3a  83cef0                 -or esi, 0xfffffff0
    cpu.esi |= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 0042ca3d  46                     -inc esi
    (cpu.esi)++;
L_0x0042ca3e:
    // 0042ca3e  d9842440010000         -fld dword ptr [esp + 0x140]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(320) /* 0x140 */)));
    // 0042ca45  d80cb5506e4900         -fmul dword ptr [esi*4 + 0x496e50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4812368) /* 0x496e50 */ + cpu.esi * 4));
    // 0042ca4c  41                     -inc ecx
    (cpu.ecx)++;
    // 0042ca4d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042ca50  d9fe                   -fsin 
    cpu.fpu.st(0) = cpu.fpu.sin(cpu.fpu.st(0));
    // 0042ca52  8d71fe                 -lea esi, [ecx - 2]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 0042ca55  83fe10                 +cmp esi, 0x10
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
    // 0042ca58  dc0df8784800           +fmul qword ptr [0x4878f8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4749560) /* 0x4878f8 */));
    // 0042ca5e  d88c2444010000         +fmul dword ptr [esp + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(324) /* 0x144 */));
    // 0042ca65  d8620c                 +fsub dword ptr [edx + 0xc]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */));
    // 0042ca68  d8c1                   +fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0042ca6a  d99c04b8000000         +fstp dword ptr [esp + eax + 0xb8]
    app->getMemory<float>(cpu.esp + x86::reg32(184) /* 0xb8 */ + cpu.eax * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042ca71  0f8c54ffffff           -jl 0x42c9cb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042c9cb;
    }
    // 0042ca77  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042ca7a  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042ca7c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042ca7e  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0042ca81  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042ca83  3bcb                   +cmp ecx, ebx
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
    // 0042ca85  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042ca87  0f8ed1030000           -jle 0x42ce5e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ce5e;
    }
    // 0042ca8d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0042ca8e:
    // 0042ca8e  8b0db0d44a00           -mov ecx, dword ptr [0x4ad4b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */);
    // 0042ca94  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0042ca97  d9040b                 -fld dword ptr [ebx + ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + cpu.ecx * 1)));
    // 0042ca9a  8b2cb0                 -mov ebp, dword ptr [eax + esi*4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0042ca9d  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042caa1  d9440b04               -fld dword ptr [ebx + ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1)));
    // 0042caa5  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042caa9  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0042caad  d81de8784800           -fcomp dword ptr [0x4878e8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749544) /* 0x4878e8 */)));
    cpu.fpu.pop();
    // 0042cab3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cab5  f6c444                 +test ah, 0x44
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 68 /*0x44*/));
    // 0042cab8  7a13                   -jp 0x42cacd
    if (cpu.flags.pf)
    {
        goto L_0x0042cacd;
    }
    // 0042caba  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0042cabd  89140b                 -mov dword ptr [ebx + ecx], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.ecx * 1) = cpu.edx;
    // 0042cac0  8b0db0d44a00           -mov ecx, dword ptr [0x4ad4b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */);
    // 0042cac6  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0042cac9  89440b04               -mov dword ptr [ebx + ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1) = cpu.eax;
L_0x0042cacd:
    // 0042cacd  d9451c                 -fld dword ptr [ebp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 0042cad0  d81dd0784800           -fcomp dword ptr [0x4878d0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749520) /* 0x4878d0 */)));
    cpu.fpu.pop();
    // 0042cad6  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cad8  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042cadd  0f853c020000           -jne 0x42cd1f
    if (!cpu.flags.zf)
    {
        goto L_0x0042cd1f;
    }
    // 0042cae3  d94520                 -fld dword ptr [ebp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    // 0042cae6  d81dd0784800           -fcomp dword ptr [0x4878d0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749520) /* 0x4878d0 */)));
    cpu.fpu.pop();
    // 0042caec  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042caee  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042caf3  0f8526020000           -jne 0x42cd1f
    if (!cpu.flags.zf)
    {
        goto L_0x0042cd1f;
    }
    // 0042caf9  8b1550f85100           -mov edx, dword ptr [0x51f850]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */);
    // 0042caff  81c2c8000000           -add edx, 0xc8
    (cpu.edx) += x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 0042cb05  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042cb09  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0042cb0d  d85d1c                 -fcomp dword ptr [ebp + 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    cpu.fpu.pop();
    // 0042cb10  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cb12  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042cb17  0f8502020000           -jne 0x42cd1f
    if (!cpu.flags.zf)
    {
        goto L_0x0042cd1f;
    }
    // 0042cb1d  a154f85100             -mov eax, dword ptr [0x51f854]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */);
    // 0042cb22  05c8000000             -add eax, 0xc8
    (cpu.eax) += x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 0042cb27  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042cb2b  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0042cb2f  d85d20                 -fcomp dword ptr [ebp + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0042cb32  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cb34  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042cb39  0f85e0010000           -jne 0x42cd1f
    if (!cpu.flags.zf)
    {
        goto L_0x0042cd1f;
    }
    // 0042cb3f  d94518                 -fld dword ptr [ebp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 0042cb42  d81d18744800           -fcomp dword ptr [0x487418]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748312) /* 0x487418 */)));
    cpu.fpu.pop();
    // 0042cb48  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cb4a  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042cb4f  0f85ca010000           -jne 0x42cd1f
    if (!cpu.flags.zf)
    {
        goto L_0x0042cd1f;
    }
    // 0042cb55  d94518                 -fld dword ptr [ebp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 0042cb58  d81d5c764800           -fcomp dword ptr [0x48765c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748892) /* 0x48765c */)));
    cpu.fpu.pop();
    // 0042cb5e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cb60  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042cb63  0f8ab6010000           -jp 0x42cd1f
    if (cpu.flags.pf)
    {
        goto L_0x0042cd1f;
    }
    // 0042cb69  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042cb6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042cb6f  751c                   -jne 0x42cb8d
    if (!cpu.flags.zf)
    {
        goto L_0x0042cb8d;
    }
    // 0042cb71  d90554095200           -fld dword ptr [0x520954]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5376340) /* 0x520954 */)));
    // 0042cb77  d84d08                 -fmul dword ptr [ebp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 0042cb7a  d81de40d5200           -fcomp dword ptr [0x520de4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(5377508) /* 0x520de4 */)));
    cpu.fpu.pop();
    // 0042cb80  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cb82  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042cb87  0f8592010000           -jne 0x42cd1f
    if (!cpu.flags.zf)
    {
        goto L_0x0042cd1f;
    }
L_0x0042cb8d:
    // 0042cb8d  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0042cb91  d81dd0784800           -fcomp dword ptr [0x4878d0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749520) /* 0x4878d0 */)));
    cpu.fpu.pop();
    // 0042cb97  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cb99  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042cb9e  0f8523010000           -jne 0x42ccc7
    if (!cpu.flags.zf)
    {
        goto L_0x0042ccc7;
    }
    // 0042cba4  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0042cba8  d81dd0784800           -fcomp dword ptr [0x4878d0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4749520) /* 0x4878d0 */)));
    cpu.fpu.pop();
    // 0042cbae  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cbb0  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042cbb5  0f850c010000           -jne 0x42ccc7
    if (!cpu.flags.zf)
    {
        goto L_0x0042ccc7;
    }
    // 0042cbbb  db0550f85100           -fild dword ptr [0x51f850]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371984) /* 0x51f850 */))));
    // 0042cbc1  d95c241c               -fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042cbc5  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0042cbc9  d85c241c               -fcomp dword ptr [esp + 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    cpu.fpu.pop();
    // 0042cbcd  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cbcf  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042cbd2  0f8aef000000           -jp 0x42ccc7
    if (cpu.flags.pf)
    {
        goto L_0x0042ccc7;
    }
    // 0042cbd8  db0554f85100           -fild dword ptr [0x51f854]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5371988) /* 0x51f854 */))));
    // 0042cbde  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042cbe2  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0042cbe6  d85c2410               -fcomp dword ptr [esp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    cpu.fpu.pop();
    // 0042cbea  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cbec  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042cbef  0f8ad2000000           -jp 0x42ccc7
    if (cpu.flags.pf)
    {
        goto L_0x0042ccc7;
    }
    // 0042cbf5  d9451c                 -fld dword ptr [ebp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 0042cbf8  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0042cbfe  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cc00  2500010000             +and eax, 0x100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(256 /*0x100*/))));
    // 0042cc05  0f85bc000000           -jne 0x42ccc7
    if (!cpu.flags.zf)
    {
        goto L_0x0042ccc7;
    }
    // 0042cc0b  d94520                 -fld dword ptr [ebp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    // 0042cc0e  d81d34734800           -fcomp dword ptr [0x487334]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(4748084) /* 0x487334 */)));
    cpu.fpu.pop();
    // 0042cc14  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cc16  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042cc1b  0f85a6000000           -jne 0x42ccc7
    if (!cpu.flags.zf)
    {
        goto L_0x0042ccc7;
    }
    // 0042cc21  d9451c                 -fld dword ptr [ebp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 0042cc24  d85c241c               -fcomp dword ptr [esp + 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    cpu.fpu.pop();
    // 0042cc28  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cc2a  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042cc2d  0f8a94000000           -jp 0x42ccc7
    if (cpu.flags.pf)
    {
        goto L_0x0042ccc7;
    }
    // 0042cc33  d94520                 -fld dword ptr [ebp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    // 0042cc36  d85c2410               -fcomp dword ptr [esp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    cpu.fpu.pop();
    // 0042cc3a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042cc3c  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042cc3f  0f8a82000000           -jp 0x42ccc7
    if (cpu.flags.pf)
    {
        goto L_0x0042ccc7;
    }
    // 0042cc45  d90508754800           -fld dword ptr [0x487508]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4748552) /* 0x487508 */)));
    // 0042cc4b  d87518                 -fdiv dword ptr [ebp + 0x18]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */));
    // 0042cc4e  d80594744800           -fadd dword ptr [0x487494]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 0042cc54  d9451c                 -fld dword ptr [ebp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 0042cc57  e834a10400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042cc5c  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0042cc60  d94520                 -fld dword ptr [ebp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    // 0042cc63  e828a10400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042cc68  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0042cc6c  d9451c                 -fld dword ptr [ebp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 0042cc6f  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 0042cc71  e81aa10400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042cc76  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0042cc7a  d94520                 -fld dword ptr [ebp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(32) /* 0x20 */)));
    // 0042cc7d  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 0042cc7f  e80ca10400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042cc84  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042cc86  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0042cc8a  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0042cc8e  e8fda00400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042cc93  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0042cc97  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0042cc9b  e8f0a00400             -call 0x476d90
    cpu.esp -= 4;
    __ftol(app, cpu);
    // 0042cca0  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0042cca4  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0042cca8  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0042ccac  8b0da4d44a00           -mov ecx, dword ptr [0x4ad4a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904100) /* 0x4ad4a4 */);
    // 0042ccb2  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0042ccb6  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0042ccb9  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 0042ccbd  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042ccc1  ff1560845100           -call dword ptr [0x518460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342304) /* 0x518460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0042ccc7:
    // 0042ccc7  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042ccca  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0042cccd  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042cccf  250f000080             +and eax, 0x8000000f
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2147483663 /*0x8000000f*/))));
    // 0042ccd4  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0042ccd7  7905                   -jns 0x42ccde
    if (!cpu.flags.sf)
    {
        goto L_0x0042ccde;
    }
    // 0042ccd9  48                     -dec eax
    (cpu.eax)--;
    // 0042ccda  83c8f0                 -or eax, 0xfffffff0
    cpu.eax |= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 0042ccdd  40                     -inc eax
    (cpu.eax)++;
L_0x0042ccde:
    // 0042ccde  c1e002                 +shl eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.eax);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0042cce1  d9840480000000         +fld dword ptr [esp + eax + 0x80]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(128) /* 0x80 */ + cpu.eax * 1)));
    // 0042cce8  d84104                 +fadd dword ptr [ecx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */));
    // 0042cceb  d95904                 +fstp dword ptr [ecx + 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042ccee  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042ccf1  d9840400010000         +fld dword ptr [esp + eax + 0x100]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(256) /* 0x100 */ + cpu.eax * 1)));
    // 0042ccf8  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0042ccfb  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0042ccfe  d84108                 +fadd dword ptr [ecx + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */));
    // 0042cd01  d95908                 +fstp dword ptr [ecx + 8]
    app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042cd04  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042cd07  d98404c0000000         +fld dword ptr [esp + eax + 0xc0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(192) /* 0xc0 */ + cpu.eax * 1)));
    // 0042cd0e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0042cd11  8b0cb1                 -mov ecx, dword ptr [ecx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0042cd14  d8410c                 +fadd dword ptr [ecx + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */));
    // 0042cd17  d9590c                 +fstp dword ptr [ecx + 0xc]
    app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042cd1a  e92e010000             -jmp 0x42ce4d
    goto L_0x0042ce4d;
L_0x0042cd1f:
    // 0042cd1f  e87c090200             -call 0x44d6a0
    cpu.esp -= 4;
    sub_44d6a0(app, cpu);
    // 0042cd24  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042cd27  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042cd2a  b803000180             -mov eax, 0x80010003
    cpu.eax = 2147549187 /*0x80010003*/;
    // 0042cd2f  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0042cd32  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0042cd34  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042cd36  c1fa0e                 -sar edx, 0xe
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (14 /*0xe*/ % 32));
    // 0042cd39  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042cd3b  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 0042cd3e  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042cd40  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042cd44  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0042cd48  d80594744800           -fadd dword ptr [0x487494]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(4748436) /* 0x487494 */));
    // 0042cd4e  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042cd52  e849090200             -call 0x44d6a0
    cpu.esp -= 4;
    sub_44d6a0(app, cpu);
    // 0042cd57  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042cd5a  b803000180             -mov eax, 0x80010003
    cpu.eax = 2147549187 /*0x80010003*/;
    // 0042cd5f  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0042cd62  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0042cd64  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042cd66  c1fa0e                 -sar edx, 0xe
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (14 /*0xe*/ % 32));
    // 0042cd69  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042cd6b  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 0042cd6e  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042cd70  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042cd74  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0042cd78  d825d0754800           -fsub dword ptr [0x4875d0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748752) /* 0x4875d0 */));
    // 0042cd7e  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0042cd82  d80dcc784800           -fmul dword ptr [0x4878cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749516) /* 0x4878cc */));
    // 0042cd88  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042cd8c  e80f090200             -call 0x44d6a0
    cpu.esp -= 4;
    sub_44d6a0(app, cpu);
    // 0042cd91  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 0042cd94  b803000180             -mov eax, 0x80010003
    cpu.eax = 2147549187 /*0x80010003*/;
    // 0042cd99  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0042cd9c  f7e9                   -imul ecx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0042cd9e  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042cda0  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042cda6  c1fa0e                 -sar edx, 0xe
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (14 /*0xe*/ % 32));
    // 0042cda9  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042cdab  c1e81f                 -shr eax, 0x1f
    cpu.eax >>= 31 /*0x1f*/ % 32;
    // 0042cdae  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042cdb0  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042cdb2  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042cdb6  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042cdb9  db442410               -fild dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */))));
    // 0042cdbd  d825d0754800           -fsub dword ptr [0x4875d0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(x86::reg32(4748752) /* 0x4875d0 */));
    // 0042cdc3  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0042cdc7  d80dcc784800           -fmul dword ptr [0x4878cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4749516) /* 0x4878cc */));
    // 0042cdcd  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042cdcf  d84874                 -fmul dword ptr [eax + 0x74]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(116) /* 0x74 */));
    // 0042cdd2  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0042cdd6  d8484c                 -fmul dword ptr [eax + 0x4c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(76) /* 0x4c */));
    // 0042cdd9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042cddb  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0042cddf  d84824                 -fmul dword ptr [eax + 0x24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */));
    // 0042cde2  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0042cde5  8b0cb0                 -mov ecx, dword ptr [eax + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 0042cde8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042cdea  d95904                 -fstp dword ptr [ecx + 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042cded  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042cdf3  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042cdf5  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042cdf7  d84878                 -fmul dword ptr [eax + 0x78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(120) /* 0x78 */));
    // 0042cdfa  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0042cdfe  d84850                 -fmul dword ptr [eax + 0x50]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(80) /* 0x50 */));
    // 0042ce01  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042ce03  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0042ce07  d84828                 -fmul dword ptr [eax + 0x28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */));
    // 0042ce0a  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042ce0d  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0042ce10  8b14b1                 -mov edx, dword ptr [ecx + esi*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4);
    // 0042ce13  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042ce15  d95a08                 -fstp dword ptr [edx + 8]
    app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042ce18  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042ce1d  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042ce20  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0042ce22  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042ce25  d8487c                 -fmul dword ptr [eax + 0x7c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(124) /* 0x7c */));
    // 0042ce28  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0042ce2c  d84854                 -fmul dword ptr [eax + 0x54]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */));
    // 0042ce2f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042ce31  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0042ce35  d8482c                 -fmul dword ptr [eax + 0x2c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */));
    // 0042ce38  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 0042ce3b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042ce3d  d9580c                 -fstp dword ptr [eax + 0xc]
    app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042ce40  8b0db0d44a00           -mov ecx, dword ptr [0x4ad4b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */);
    // 0042ce46  c7040b0080bb45         -mov dword ptr [ebx + ecx], 0x45bb8000
    app->getMemory<x86::reg32>(cpu.ebx + cpu.ecx * 1) = 1169915904 /*0x45bb8000*/;
L_0x0042ce4d:
    // 0042ce4d  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0042ce50  46                     -inc esi
    (cpu.esi)++;
    // 0042ce51  83c30c                 -add ebx, 0xc
    (cpu.ebx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042ce54  3b7008                 +cmp esi, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042ce57  0f8c31fcffff           -jl 0x42ca8e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042ca8e;
    }
    // 0042ce5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042ce5e:
    // 0042ce5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ce5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ce60  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ce61  81c430010000           -add esp, 0x130
    (cpu.esp) += x86::reg32(x86::sreg32(304 /*0x130*/));
    // 0042ce67  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_42ce70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0042ce70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042ce71  a1486e4900             -mov eax, dword ptr [0x496e48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4812360) /* 0x496e48 */);
    // 0042ce76  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042ce77  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042ce78  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042ce7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042ce7c  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042ce7e  7e18                   -jle 0x42ce98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042ce98;
    }
    // 0042ce80  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042ce86  8b0c81                 -mov ecx, dword ptr [ecx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0042ce89  e8b21b0300             -call 0x45ea40
    cpu.esp -= 4;
    sub_45ea40(app, cpu);
    // 0042ce8e  c705486e4900ffffffff   -mov dword ptr [0x496e48], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(4812360) /* 0x496e48 */) = 4294967295 /*0xffffffff*/;
L_0x0042ce98:
    // 0042ce98  83ff03                 +cmp edi, 3
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
    // 0042ce9b  7723                   -ja 0x42cec0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042cec0;
    }
    // 0042ce9d  ff24bd08cf4200         -jmp dword ptr [edi*4 + 0x42cf08]
    cpu.ip = app->getMemory<x86::reg32>(4378376 + cpu.edi * 4); goto dynamic_jump;
  case 0x0042cea4:
    // 0042cea4  b84cbb4a00             -mov eax, 0x4abb4c
    cpu.eax = 4897612 /*0x4abb4c*/;
    // 0042cea9  eb19                   -jmp 0x42cec4
    goto L_0x0042cec4;
  case 0x0042ceab:
    // 0042ceab  b8ac6e4900             -mov eax, 0x496eac
    cpu.eax = 4812460 /*0x496eac*/;
    // 0042ceb0  eb12                   -jmp 0x42cec4
    goto L_0x0042cec4;
  case 0x0042ceb2:
    // 0042ceb2  b89c6e4900             -mov eax, 0x496e9c
    cpu.eax = 4812444 /*0x496e9c*/;
    // 0042ceb7  eb0b                   -jmp 0x42cec4
    goto L_0x0042cec4;
  case 0x0042ceb9:
    // 0042ceb9  b8906e4900             -mov eax, 0x496e90
    cpu.eax = 4812432 /*0x496e90*/;
    // 0042cebe  eb04                   -jmp 0x42cec4
    goto L_0x0042cec4;
L_0x0042cec0:
    // 0042cec0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0042cec4:
    // 0042cec4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042cec6  893da0d44a00           -mov dword ptr [0x4ad4a0], edi
    app->getMemory<x86::reg32>(x86::reg32(4904096) /* 0x4ad4a0 */) = cpu.edi;
    // 0042cecc  ba60095200             -mov edx, 0x520960
    cpu.edx = 5376352 /*0x520960*/;
    // 0042ced1  7410                   -je 0x42cee3
    if (cpu.flags.zf)
    {
        goto L_0x0042cee3;
    }
    // 0042ced3  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042ced5  2bd6                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0042ced7:
    // 0042ced7  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042ced9  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0042cedc  40                     -inc eax
    (cpu.eax)++;
    // 0042cedd  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0042cedf  75f6                   -jne 0x42ced7
    if (!cpu.flags.zf)
    {
        goto L_0x0042ced7;
    }
    // 0042cee1  eb0c                   -jmp 0x42ceef
    goto L_0x0042ceef;
L_0x0042cee3:
    // 0042cee3  2bd0                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042cee5:
    // 0042cee5  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042cee7  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0042ceea  40                     -inc eax
    (cpu.eax)++;
    // 0042ceeb  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0042ceed  75f6                   -jne 0x42cee5
    if (!cpu.flags.zf)
    {
        goto L_0x0042cee5;
    }
L_0x0042ceef:
    // 0042ceef  a1a4d44a00             -mov eax, dword ptr [0x4ad4a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904100) /* 0x4ad4a4 */);
    // 0042cef4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cef5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042cef7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cef8  740a                   -je 0x42cf04
    if (cpu.flags.zf)
    {
        goto L_0x0042cf04;
    }
    // 0042cefa  c705a4d44a0000000000   -mov dword ptr [0x4ad4a4], 0
    app->getMemory<x86::reg32>(x86::reg32(4904100) /* 0x4ad4a4 */) = 0 /*0x0*/;
L_0x0042cf04:
    // 0042cf04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042cf05  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_42cf20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042cf20  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042cf22  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042cf24  e807000000             -call 0x42cf30
    cpu.esp -= 4;
    sub_42cf30(app, cpu);
    // 0042cf29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42cf30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042cf30  83e900                 +sub ecx, 0
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
    // 0042cf33  7433                   -je 0x42cf68
    if (cpu.flags.zf)
    {
        goto L_0x0042cf68;
    }
    // 0042cf35  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042cf36  7419                   -je 0x42cf51
    if (cpu.flags.zf)
    {
        goto L_0x0042cf51;
    }
    // 0042cf38  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042cf3c  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042cf3d  a3e00d5200             -mov dword ptr [0x520de0], eax
    app->getMemory<x86::reg32>(x86::reg32(5377504) /* 0x520de0 */) = cpu.eax;
    // 0042cf42  7538                   -jne 0x42cf7c
    if (!cpu.flags.zf)
    {
        goto L_0x0042cf7c;
    }
    // 0042cf44  c705540952000000803f   -mov dword ptr [0x520954], 0x3f800000
    app->getMemory<x86::reg32>(x86::reg32(5376340) /* 0x520954 */) = 1065353216 /*0x3f800000*/;
    // 0042cf4e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0042cf51:
    // 0042cf51  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042cf55  c70554095200000080bf   -mov dword ptr [0x520954], 0xbf800000
    app->getMemory<x86::reg32>(x86::reg32(5376340) /* 0x520954 */) = 3212836864 /*0xbf800000*/;
    // 0042cf5f  890de00d5200           -mov dword ptr [0x520de0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5377504) /* 0x520de0 */) = cpu.ecx;
    // 0042cf65  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0042cf68:
    // 0042cf68  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042cf6c  c7055409520000000000   -mov dword ptr [0x520954], 0
    app->getMemory<x86::reg32>(x86::reg32(5376340) /* 0x520954 */) = 0 /*0x0*/;
    // 0042cf76  8915e00d5200           -mov dword ptr [0x520de0], edx
    app->getMemory<x86::reg32>(x86::reg32(5377504) /* 0x520de0 */) = cpu.edx;
L_0x0042cf7c:
    // 0042cf7c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42cf80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042cf80  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042cf82  b9bc6e4900             -mov ecx, 0x496ebc
    cpu.ecx = 4812476 /*0x496ebc*/;
    // 0042cf87  e884140300             -call 0x45e410
    cpu.esp -= 4;
    sub_45e410(app, cpu);
    // 0042cf8c  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042cf92  a3486e4900             -mov dword ptr [0x496e48], eax
    app->getMemory<x86::reg32>(x86::reg32(4812360) /* 0x496e48 */) = cpu.eax;
    // 0042cf97  8b0481                 -mov eax, dword ptr [ecx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0042cf9a  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0042cfa0  83e2df                 -and edx, 0xffffffdf
    cpu.edx &= x86::reg32(x86::sreg32(4294967263 /*0xffffffdf*/));
    // 0042cfa3  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0042cfa9  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042cfaf  a1486e4900             -mov eax, dword ptr [0x496e48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4812360) /* 0x496e48 */);
    // 0042cfb4  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0042cfb7  e864d50100             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0042cfbc  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042cfc2  8b15486e4900           -mov edx, dword ptr [0x496e48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4812360) /* 0x496e48 */);
    // 0042cfc8  8b0491                 -mov eax, dword ptr [ecx + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0042cfcb  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0042cfd1  83e1bf                 -and ecx, 0xffffffbf
    cpu.ecx &= x86::reg32(x86::sreg32(4294967231 /*0xffffffbf*/));
    // 0042cfd4  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0042cfda  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042cfdf  8b0d486e4900           -mov ecx, dword ptr [0x496e48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4812360) /* 0x496e48 */);
    // 0042cfe5  8b0c88                 -mov ecx, dword ptr [eax + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0042cfe8  e833d50100             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0042cfed  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042cff3  a1486e4900             -mov eax, dword ptr [0x496e48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4812360) /* 0x496e48 */);
    // 0042cff8  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0042cffb  8b90a8020000           -mov edx, dword ptr [eax + 0x2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0042d001  83e2fb                 -and edx, 0xfffffffb
    cpu.edx &= x86::reg32(x86::sreg32(4294967291 /*0xfffffffb*/));
    // 0042d004  8990a8020000           -mov dword ptr [eax + 0x2a8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.edx;
    // 0042d00a  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042d010  8b15486e4900           -mov edx, dword ptr [0x496e48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4812360) /* 0x496e48 */);
    // 0042d016  8b0c91                 -mov ecx, dword ptr [ecx + edx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0042d019  e802d50100             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0042d01e  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042d023  8b0d486e4900           -mov ecx, dword ptr [0x496e48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4812360) /* 0x496e48 */);
    // 0042d029  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 0042d02c  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0042d032  83e1f7                 -and ecx, 0xfffffff7
    cpu.ecx &= x86::reg32(x86::sreg32(4294967287 /*0xfffffff7*/));
    // 0042d035  8988a8020000           -mov dword ptr [eax + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0042d03b  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042d041  a1486e4900             -mov eax, dword ptr [0x496e48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4812360) /* 0x496e48 */);
    // 0042d046  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0042d049  e8d2d40100             -call 0x44a520
    cpu.esp -= 4;
    sub_44a520(app, cpu);
    // 0042d04e  8b0d486e4900           -mov ecx, dword ptr [0x496e48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4812360) /* 0x496e48 */);
    // 0042d054  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042d05a  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0042d05d  8b8818030000           -mov ecx, dword ptr [eax + 0x318]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(792) /* 0x318 */);
    // 0042d063  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042d065  7405                   -je 0x42d06c
    if (cpu.flags.zf)
    {
        goto L_0x0042d06c;
    }
    // 0042d067  e824b10300             -call 0x468190
    cpu.esp -= 4;
    sub_468190(app, cpu);
L_0x0042d06c:
    // 0042d06c  c705b0d44a0000000000   -mov dword ptr [0x4ad4b0], 0
    app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */) = 0 /*0x0*/;
    // 0042d076  c705acd44a0000000000   -mov dword ptr [0x4ad4ac], 0
    app->getMemory<x86::reg32>(x86::reg32(4904108) /* 0x4ad4ac */) = 0 /*0x0*/;
    // 0042d080  b8f8095200             -mov eax, 0x5209f8
    cpu.eax = 5376504 /*0x5209f8*/;
L_0x0042d085:
    // 0042d085  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0042d08b  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0042d08e  3df80d5200             +cmp eax, 0x520df8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5377528 /*0x520df8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d093  7cf0                   -jl 0x42d085
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042d085;
    }
    // 0042d095  e986feffff             -jmp 0x42cf20
    return sub_42cf20(app, cpu);
}

/* align: skip  */
void Application::sub_42d0a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d0a0  a1a0d44a00             -mov eax, dword ptr [0x4ad4a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904096) /* 0x4ad4a0 */);
    // 0042d0a5  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0042d0a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d0a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d0aa  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042d0ac  3bc7                   +cmp eax, edi
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
    // 0042d0ae  0f8496030000           -je 0x42d44a
    if (cpu.flags.zf)
    {
        goto L_0x0042d44a;
    }
    // 0042d0b4  393d486e4900           +cmp dword ptr [0x496e48], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4812360) /* 0x496e48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d0ba  7f0a                   -jg 0x42d0c6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0042d0c6;
    }
    // 0042d0bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d0bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d0be  83c430                 +add esp, 0x30
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
    // 0042d0c1  e9bafeffff             -jmp 0x42cf80
    return sub_42cf80(app, cpu);
L_0x0042d0c6:
    // 0042d0c6  e865860300             -call 0x465730
    cpu.esp -= 4;
    sub_465730(app, cpu);
    // 0042d0cb  d905b4d44a00           -fld dword ptr [0x4ad4b4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(4904116) /* 0x4ad4b4 */)));
    // 0042d0d1  a1486e4900             -mov eax, dword ptr [0x496e48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4812360) /* 0x496e48 */);
    // 0042d0d6  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042d0dc  d8e9                   -fsubr st(1)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(1)) - cpu.fpu.st(0);
    // 0042d0de  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042d0e2  d91db4d44a00           -fstp dword ptr [0x4ad4b4]
    app->getMemory<float>(x86::reg32(4904116) /* 0x4ad4b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042d0e8  8b3481                 -mov esi, dword ptr [ecx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 0042d0eb  a1a4d44a00             -mov eax, dword ptr [0x4ad4a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904100) /* 0x4ad4a4 */);
    // 0042d0f0  3bc7                   +cmp eax, edi
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
    // 0042d0f2  751a                   -jne 0x42d10e
    if (!cpu.flags.zf)
    {
        goto L_0x0042d10e;
    }
    // 0042d0f4  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042d0f6  b960095200             -mov ecx, 0x520960
    cpu.ecx = 5376352 /*0x520960*/;
    // 0042d0fb  ff1568845100           -call dword ptr [0x518468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5342312) /* 0x518468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0042d101  3bc7                   +cmp eax, edi
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
    // 0042d103  a3a4d44a00             -mov dword ptr [0x4ad4a4], eax
    app->getMemory<x86::reg32>(x86::reg32(4904100) /* 0x4ad4a4 */) = cpu.eax;
    // 0042d108  0f843c030000           -je 0x42d44a
    if (cpu.flags.zf)
    {
        goto L_0x0042d44a;
    }
L_0x0042d10e:
    // 0042d10e  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042d114  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042d116  d980d0000000           -fld dword ptr [eax + 0xd0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(208) /* 0xd0 */)));
    // 0042d11c  d8a6d0000000           -fsub dword ptr [esi + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(208) /* 0xd0 */));
    // 0042d122  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042d126  d980d4000000           -fld dword ptr [eax + 0xd4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(212) /* 0xd4 */)));
    // 0042d12c  d8a6d4000000           -fsub dword ptr [esi + 0xd4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(212) /* 0xd4 */));
    // 0042d132  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042d136  d980d8000000           -fld dword ptr [eax + 0xd8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(216) /* 0xd8 */)));
    // 0042d13c  8b80d0000000           -mov eax, dword ptr [eax + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(208) /* 0xd0 */);
    // 0042d142  8986d0000000           -mov dword ptr [esi + 0xd0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(208) /* 0xd0 */) = cpu.eax;
    // 0042d148  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042d14e  d8a6d8000000           -fsub dword ptr [esi + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(216) /* 0xd8 */));
    // 0042d154  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042d156  8b82d4000000           -mov eax, dword ptr [edx + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(212) /* 0xd4 */);
    // 0042d15c  8986d4000000           -mov dword ptr [esi + 0xd4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(212) /* 0xd4 */) = cpu.eax;
    // 0042d162  8b0d30845100           -mov ecx, dword ptr [0x518430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042d168  d95c241c               -fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042d16c  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042d16e  8b82d8000000           -mov eax, dword ptr [edx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(216) /* 0xd8 */);
    // 0042d174  8986d8000000           -mov dword ptr [esi + 0xd8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(216) /* 0xd8 */) = cpu.eax;
    // 0042d17a  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d17d  3bc7                   +cmp eax, edi
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
    // 0042d17f  0f84c5020000           -je 0x42d44a
    if (cpu.flags.zf)
    {
        goto L_0x0042d44a;
    }
    // 0042d185  897818                 -mov dword ptr [eax + 0x18], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0042d188  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d189  d905e00d5200           -fld dword ptr [0x520de0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5377504) /* 0x520de0 */)));
    // 0042d18f  d8a6d4000000           -fsub dword ptr [esi + 0xd4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(212) /* 0xd4 */));
    // 0042d195  d80d54095200           -fmul dword ptr [0x520954]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5376340) /* 0x520954 */));
    // 0042d19b  d91de40d5200           -fstp dword ptr [0x520de4]
    app->getMemory<float>(x86::reg32(5377508) /* 0x520de4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042d1a1  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d1a4  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0042d1a7  8b0dacd44a00           -mov ecx, dword ptr [0x4ad4ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904108) /* 0x4ad4ac */);
    // 0042d1ad  3bc8                   +cmp ecx, eax
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
    // 0042d1af  8b0db0d44a00           -mov ecx, dword ptr [0x4ad4b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */);
    // 0042d1b5  0f85c8010000           -jne 0x42d383
    if (!cpu.flags.zf)
    {
        goto L_0x0042d383;
    }
    // 0042d1bb  3bcf                   +cmp ecx, edi
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
    // 0042d1bd  0f84c0010000           -je 0x42d383
    if (cpu.flags.zf)
    {
        goto L_0x0042d383;
    }
    // 0042d1c3  8b0da8d44a00           -mov ecx, dword ptr [0x4ad4a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904104) /* 0x4ad4a8 */);
    // 0042d1c9  3bc8                   +cmp ecx, eax
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
    // 0042d1cb  7d04                   -jge 0x42d1d1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042d1d1;
    }
    // 0042d1cd  3bcf                   +cmp ecx, edi
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
    // 0042d1cf  7d08                   -jge 0x42d1d9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042d1d9;
    }
L_0x0042d1d1:
    // 0042d1d1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042d1d3  890da8d44a00           -mov dword ptr [0x4ad4a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(4904104) /* 0x4ad4a8 */) = cpu.ecx;
L_0x0042d1d9:
    // 0042d1d9  b8f8095200             -mov eax, 0x5209f8
    cpu.eax = 5376504 /*0x5209f8*/;
    // 0042d1de  c744241020000000       -mov dword ptr [esp + 0x10], 0x20
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 32 /*0x20*/;
    // 0042d1e6  ba0000f041             -mov edx, 0x41f00000
    cpu.edx = 1106247680 /*0x41f00000*/;
    // 0042d1eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0042d1ec:
    // 0042d1ec  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042d1ee  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042d1f1  3beb                   +cmp ebp, ebx
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
    // 0042d1f3  7603                   -jbe 0x42d1f8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042d1f8;
    }
    // 0042d1f5  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x0042d1f8:
    // 0042d1f8  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042d1fb  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042d1fd  3bef                   +cmp ebp, edi
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
    // 0042d1ff  0f860c010000           -jbe 0x42d311
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042d311;
    }
L_0x0042d205:
    // 0042d205  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 0042d207  d940f4                 -fld dword ptr [eax - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-12) /* -0xc */)));
    // 0042d20a  4d                     -dec ebp
    (cpu.ebp)--;
    // 0042d20b  8928                   -mov dword ptr [eax], ebp
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 0042d20d  8b6e04                 -mov ebp, dword ptr [esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d210  d8a6d0000000           -fsub dword ptr [esi + 0xd0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(208) /* 0xd0 */));
    // 0042d216  8b6d0c                 -mov ebp, dword ptr [ebp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042d219  8b4c8d00               -mov ecx, dword ptr [ebp + ecx*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4);
    // 0042d21d  d95904                 -fstp dword ptr [ecx + 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042d220  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d223  8b2da8d44a00           -mov ebp, dword ptr [0x4ad4a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4904104) /* 0x4ad4a8 */);
    // 0042d229  d940f8                 -fld dword ptr [eax - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-8) /* -0x8 */)));
    // 0042d22c  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042d22f  d8a6d4000000           -fsub dword ptr [esi + 0xd4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(212) /* 0xd4 */));
    // 0042d235  8b0ca9                 -mov ecx, dword ptr [ecx + ebp*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.ebp * 4);
    // 0042d238  d95908                 -fstp dword ptr [ecx + 8]
    app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042d23b  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d23e  8b2da8d44a00           -mov ebp, dword ptr [0x4ad4a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4904104) /* 0x4ad4a8 */);
    // 0042d244  d940fc                 -fld dword ptr [eax - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */)));
    // 0042d247  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042d24a  d8a6d8000000           -fsub dword ptr [esi + 0xd8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(216) /* 0xd8 */));
    // 0042d250  8b0ca9                 -mov ecx, dword ptr [ecx + ebp*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.ebp * 4);
    // 0042d253  d9590c                 -fstp dword ptr [ecx + 0xc]
    app->getMemory<float>(cpu.ecx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042d256  d940e8                 -fld dword ptr [eax - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-24) /* -0x18 */)));
    // 0042d259  d840f4                 -fadd dword ptr [eax - 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-12) /* -0xc */));
    // 0042d25c  8b2da8d44a00           -mov ebp, dword ptr [0x4ad4a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4904104) /* 0x4ad4a8 */);
    // 0042d262  d958f4                 -fstp dword ptr [eax - 0xc]
    app->getMemory<float>(cpu.eax + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042d265  d940ec                 -fld dword ptr [eax - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-20) /* -0x14 */)));
    // 0042d268  d840f8                 -fadd dword ptr [eax - 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-8) /* -0x8 */));
    // 0042d26b  d958f8                 -fstp dword ptr [eax - 8]
    app->getMemory<float>(cpu.eax + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042d26e  d940fc                 -fld dword ptr [eax - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */)));
    // 0042d271  d840f0                 -fadd dword ptr [eax - 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-16) /* -0x10 */));
    // 0042d274  d958fc                 -fstp dword ptr [eax - 4]
    app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042d277  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d27a  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042d27d  8b0ca9                 -mov ecx, dword ptr [ecx + ebp*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.ebp * 4);
    // 0042d280  c7411c000020c1         -mov dword ptr [ecx + 0x1c], 0xc1200000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 3240099840 /*0xc1200000*/;
    // 0042d287  8b0da8d44a00           -mov ecx, dword ptr [0x4ad4a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904104) /* 0x4ad4a8 */);
    // 0042d28d  8b2db0d44a00           -mov ebp, dword ptr [0x4ad4b0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */);
    // 0042d293  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0042d296  c7448d00000020c1       -mov dword ptr [ebp + ecx*4], 0xc1200000
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 3240099840 /*0xc1200000*/;
    // 0042d29e  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d2a1  8b2da8d44a00           -mov ebp, dword ptr [0x4ad4a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4904104) /* 0x4ad4a8 */);
    // 0042d2a7  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042d2aa  8b0ca9                 -mov ecx, dword ptr [ecx + ebp*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.ebp * 4);
    // 0042d2ad  897920                 -mov dword ptr [ecx + 0x20], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 0042d2b0  8b0da8d44a00           -mov ecx, dword ptr [0x4ad4a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904104) /* 0x4ad4a8 */);
    // 0042d2b6  8b2db0d44a00           -mov ebp, dword ptr [0x4ad4b0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */);
    // 0042d2bc  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0042d2bf  897c8d04               -mov dword ptr [ebp + ecx*4 + 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4) = cpu.edi;
    // 0042d2c3  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d2c6  8b2da8d44a00           -mov ebp, dword ptr [0x4ad4a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4904104) /* 0x4ad4a8 */);
    // 0042d2cc  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042d2cf  8b0ca9                 -mov ecx, dword ptr [ecx + ebp*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.ebp * 4);
    // 0042d2d2  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0042d2d5  8b0da8d44a00           -mov ecx, dword ptr [0x4ad4a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904104) /* 0x4ad4a8 */);
    // 0042d2db  8b2db0d44a00           -mov ebp, dword ptr [0x4ad4b0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */);
    // 0042d2e1  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0042d2e4  89548d08               -mov dword ptr [ebp + ecx*4 + 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4) = cpu.edx;
    // 0042d2e8  8b0da8d44a00           -mov ecx, dword ptr [0x4ad4a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904104) /* 0x4ad4a8 */);
    // 0042d2ee  41                     -inc ecx
    (cpu.ecx)++;
    // 0042d2ef  890da8d44a00           -mov dword ptr [0x4ad4a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(4904104) /* 0x4ad4a8 */) = cpu.ecx;
    // 0042d2f5  8b6e04                 -mov ebp, dword ptr [esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d2f8  3b4d08                 +cmp ecx, dword ptr [ebp + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d2fb  7c08                   -jl 0x42d305
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042d305;
    }
    // 0042d2fd  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042d2ff  890da8d44a00           -mov dword ptr [0x4ad4a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(4904104) /* 0x4ad4a8 */) = cpu.ecx;
L_0x0042d305:
    // 0042d305  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042d308  43                     -inc ebx
    (cpu.ebx)++;
    // 0042d309  3bdd                   +cmp ebx, ebp
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
    // 0042d30b  0f82f4feffff           -jb 0x42d205
    if (cpu.flags.cf)
    {
        goto L_0x0042d205;
    }
L_0x0042d311:
    // 0042d311  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042d315  83c020                 +add eax, 0x20
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
    // 0042d318  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042d319  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0042d31d  0f85c9feffff           -jne 0x42d1ec
    if (!cpu.flags.zf)
    {
        goto L_0x0042d1ec;
    }
    // 0042d323  a1a0d44a00             -mov eax, dword ptr [0x4ad4a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904096) /* 0x4ad4a0 */);
    // 0042d328  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d329  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042d32a  743e                   -je 0x42d36a
    if (cpu.flags.zf)
    {
        goto L_0x0042d36a;
    }
    // 0042d32c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042d32d  7422                   -je 0x42d351
    if (cpu.flags.zf)
    {
        goto L_0x0042d351;
    }
    // 0042d32f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0042d330  0f85ab000000           -jne 0x42d3e1
    if (!cpu.flags.zf)
    {
        goto L_0x0042d3e1;
    }
    // 0042d336  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042d33a  a1b4d44a00             -mov eax, dword ptr [0x4ad4b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904116) /* 0x4ad4b4 */);
    // 0042d33f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042d340  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d341  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042d345  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042d347  e854f1ffff             -call 0x42c4a0
    cpu.esp -= 4;
    sub_42c4a0(app, cpu);
    // 0042d34c  e990000000             -jmp 0x42d3e1
    goto L_0x0042d3e1;
L_0x0042d351:
    // 0042d351  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042d355  8b15b4d44a00           -mov edx, dword ptr [0x4ad4b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904116) /* 0x4ad4b4 */);
    // 0042d35b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042d35c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042d35d  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042d361  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042d363  e8a8f5ffff             -call 0x42c910
    cpu.esp -= 4;
    sub_42c910(app, cpu);
    // 0042d368  eb77                   -jmp 0x42d3e1
    goto L_0x0042d3e1;
L_0x0042d36a:
    // 0042d36a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042d36e  8b0db4d44a00           -mov ecx, dword ptr [0x4ad4b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904116) /* 0x4ad4b4 */);
    // 0042d374  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d375  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042d376  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042d37a  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042d37c  e89fecffff             -call 0x42c020
    cpu.esp -= 4;
    sub_42c020(app, cpu);
    // 0042d381  eb5e                   -jmp 0x42d3e1
    goto L_0x0042d3e1;
L_0x0042d383:
    // 0042d383  8d1440                 -lea edx, [eax + eax*2]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 2);
    // 0042d386  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0042d389  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042d38a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042d38b  e8bb9b0400             -call 0x476f4b
    cpu.esp -= 4;
    sub_476f4b(app, cpu);
    // 0042d390  8b0dacd44a00           -mov ecx, dword ptr [0x4ad4ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904108) /* 0x4ad4ac */);
    // 0042d396  a3b0d44a00             -mov dword ptr [0x4ad4b0], eax
    app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */) = cpu.eax;
    // 0042d39b  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d39e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042d3a1  3b4808                 +cmp ecx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d3a4  732f                   -jae 0x42d3d5
    if (!cpu.flags.cf)
    {
        goto L_0x0042d3d5;
    }
    // 0042d3a6  8d0449                 -lea eax, [ecx + ecx*2]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0042d3a9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
L_0x0042d3ac:
    // 0042d3ac  8b15b0d44a00           -mov edx, dword ptr [0x4ad4b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */);
    // 0042d3b2  41                     -inc ecx
    (cpu.ecx)++;
    // 0042d3b3  893c10                 -mov dword ptr [eax + edx], edi
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 1) = cpu.edi;
    // 0042d3b6  8b15b0d44a00           -mov edx, dword ptr [0x4ad4b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */);
    // 0042d3bc  897c1004               -mov dword ptr [eax + edx + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edx * 1) = cpu.edi;
    // 0042d3c0  8b15b0d44a00           -mov edx, dword ptr [0x4ad4b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */);
    // 0042d3c6  897c1008               -mov dword ptr [eax + edx + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.edx * 1) = cpu.edi;
    // 0042d3ca  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d3cd  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042d3d0  3b4a08                 +cmp ecx, dword ptr [edx + 8]
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
    // 0042d3d3  72d7                   -jb 0x42d3ac
    if (cpu.flags.cf)
    {
        goto L_0x0042d3ac;
    }
L_0x0042d3d5:
    // 0042d3d5  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d3d8  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0042d3db  890dacd44a00           -mov dword ptr [0x4ad4ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(4904108) /* 0x4ad4ac */) = cpu.ecx;
L_0x0042d3e1:
    // 0042d3e1  8b0dacd44a00           -mov ecx, dword ptr [0x4ad4ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904108) /* 0x4ad4ac */);
    // 0042d3e7  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d3e9  3bcf                   +cmp ecx, edi
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
    // 0042d3eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d3ec  765c                   -jbe 0x42d44a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042d44a;
    }
    // 0042d3ee  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0042d3f0:
    // 0042d3f0  8b15b0d44a00           -mov edx, dword ptr [0x4ad4b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */);
    // 0042d3f6  813c110080bb45         +cmp dword ptr [ecx + edx], 0x45bb8000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1169915904 /*0x45bb8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d3fd  740f                   -je 0x42d40e
    if (cpu.flags.zf)
    {
        goto L_0x0042d40e;
    }
    // 0042d3ff  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d402  8b7f0c                 -mov edi, dword ptr [edi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0042d405  8b3c87                 -mov edi, dword ptr [edi + eax*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 0042d408  8b7f1c                 -mov edi, dword ptr [edi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0042d40b  893c11                 -mov dword ptr [ecx + edx], edi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.edi;
L_0x0042d40e:
    // 0042d40e  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d411  8b3db0d44a00           -mov edi, dword ptr [0x4ad4b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */);
    // 0042d417  40                     -inc eax
    (cpu.eax)++;
    // 0042d418  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042d41b  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0042d41e  8b5482fc               -mov edx, dword ptr [edx + eax*4 - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 4);
    // 0042d422  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0042d425  895439f8               -mov dword ptr [ecx + edi - 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.edi * 1) = cpu.edx;
    // 0042d429  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d42c  8b3db0d44a00           -mov edi, dword ptr [0x4ad4b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4904112) /* 0x4ad4b0 */);
    // 0042d432  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0042d435  8b5482fc               -mov edx, dword ptr [edx + eax*4 - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 4);
    // 0042d439  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0042d43c  895439fc               -mov dword ptr [ecx + edi - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1) = cpu.edx;
    // 0042d440  8b15acd44a00           -mov edx, dword ptr [0x4ad4ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904108) /* 0x4ad4ac */);
    // 0042d446  3bc2                   +cmp eax, edx
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
    // 0042d448  72a6                   -jb 0x42d3f0
    if (cpu.flags.cf)
    {
        goto L_0x0042d3f0;
    }
L_0x0042d44a:
    // 0042d44a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d44b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d44c  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0042d44f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d450  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042d453  a010155200             -mov al, byte ptr [0x521510]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5379344) /* 0x521510 */);
    // 0042d458  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042d459  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042d45b  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0042d45d  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042d461  720e                   -jb 0x42d471
    if (cpu.flags.cf)
    {
        goto L_0x0042d471;
    }
    // 0042d463  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 0042d46a  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d46c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d46d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042d470  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042d471:
    // 0042d471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d472  6890010000             -push 0x190
    app->getMemory<x86::reg32>(cpu.esp-4) = 400 /*0x190*/;
    cpu.esp -= 4;
    // 0042d477  c745000a000000         -mov dword ptr [ebp], 0xa
    app->getMemory<x86::reg32>(cpu.ebp) = 10 /*0xa*/;
    // 0042d47e  e8f79d0400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0042d483  8b4d00                 -mov ecx, dword ptr [ebp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0042d486  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042d488  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042d48b  3bcf                   +cmp ecx, edi
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
    // 0042d48d  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0042d491  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0042d495  7e4b                   -jle 0x42d4e2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042d4e2;
    }
    // 0042d497  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d498  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d499  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042d49b  8d7004                 -lea esi, [eax + 4]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0042d49e:
    // 0042d49e  8d4761                 -lea eax, [edi + 0x61]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(97) /* 0x61 */);
    // 0042d4a1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d4a2  68c46f4900             -push 0x496fc4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812740 /*0x496fc4*/;
    cpu.esp -= 4;
    // 0042d4a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d4a8  e84b990400             -call 0x476df8
    cpu.esp -= 4;
    sub_476df8(app, cpu);
    // 0042d4ad  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042d4b0  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042d4b2  e8d9540000             -call 0x432990
    cpu.esp -= 4;
    sub_432990(app, cpu);
    // 0042d4b7  83f8ff                 +cmp eax, -1
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
    // 0042d4ba  7415                   -je 0x42d4d1
    if (cpu.flags.zf)
    {
        goto L_0x0042d4d1;
    }
    // 0042d4bc  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042d4c0  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0042d4c2  41                     -inc ecx
    (cpu.ecx)++;
    // 0042d4c3  c7432405000000         -mov dword ptr [ebx + 0x24], 5
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 5 /*0x5*/;
    // 0042d4ca  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0042d4ce  83c328                 -add ebx, 0x28
    (cpu.ebx) += x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x0042d4d1:
    // 0042d4d1  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0042d4d4  47                     -inc edi
    (cpu.edi)++;
    // 0042d4d5  83c628                 -add esi, 0x28
    (cpu.esi) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0042d4d8  3bf8                   +cmp edi, eax
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
    // 0042d4da  7cc2                   -jl 0x42d49e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042d49e;
    }
    // 0042d4dc  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042d4e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d4e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042d4e2:
    // 0042d4e2  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042d4e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d4e7  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0042d4ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d4eb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042d4ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d4f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d4f1  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042d4f3  8b4e58                 -mov ecx, dword ptr [esi + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 0042d4f6  8d565c                 -lea edx, [esi + 0x5c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 0042d4f9  e852ffffff             -call 0x42d450
    cpu.esp -= 4;
    sub_42d450(app, cpu);
    // 0042d4fe  894658                 -mov dword ptr [esi + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 0042d501  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d502  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d510  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d511  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042d513  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d514  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d516  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042d518  68ccd44a00             -push 0x4ad4cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904140 /*0x4ad4cc*/;
    cpu.esp -= 4;
    // 0042d51d  e87da20400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0042d522  a1ccd44a00             -mov eax, dword ptr [0x4ad4cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */);
    // 0042d527  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042d52a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d52c  7412                   -je 0x42d540
    if (cpu.flags.zf)
    {
        goto L_0x0042d540;
    }
    // 0042d52e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d52f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d530  a1c8d44a00             -mov eax, dword ptr [0x4ad4c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904136) /* 0x4ad4c8 */);
    // 0042d535  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042d537  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d538  e862a20400             -call 0x47779f
    cpu.esp -= 4;
    sub_47779f(app, cpu);
    // 0042d53d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0042d540:
    // 0042d540  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d541  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d550  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d551  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042d553  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d554  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042d556  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042d558  68ccd44a00             -push 0x4ad4cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4904140 /*0x4ad4cc*/;
    cpu.esp -= 4;
    // 0042d55d  e826a10400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0042d562  a1ccd44a00             -mov eax, dword ptr [0x4ad4cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */);
    // 0042d567  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042d56a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d56c  7436                   -je 0x42d5a4
    if (cpu.flags.zf)
    {
        goto L_0x0042d5a4;
    }
    // 0042d56e  a1c8d44a00             -mov eax, dword ptr [0x4ad4c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904136) /* 0x4ad4c8 */);
    // 0042d573  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d575  751a                   -jne 0x42d591
    if (!cpu.flags.zf)
    {
        goto L_0x0042d591;
    }
    // 0042d577  a12c845100             -mov eax, dword ptr [0x51842c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */);
    // 0042d57c  8d0c8500080000         -lea ecx, [eax*4 + 0x800]
    cpu.ecx = x86::reg32(x86::reg32(2048) /* 0x800 */ + cpu.eax * 4);
    // 0042d583  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042d584  e8f19c0400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0042d589  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042d58c  a3c8d44a00             -mov dword ptr [0x4ad4c8], eax
    app->getMemory<x86::reg32>(x86::reg32(4904136) /* 0x4ad4c8 */) = cpu.eax;
L_0x0042d591:
    // 0042d591  8b15ccd44a00           -mov edx, dword ptr [0x4ad4cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */);
    // 0042d597  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d598  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042d599  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042d59b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042d59c  e8e7a00400             -call 0x477688
    cpu.esp -= 4;
    sub_477688(app, cpu);
    // 0042d5a1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0042d5a4:
    // 0042d5a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d5a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d5b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d5b0  c705c86e4900ffffffff   -mov dword ptr [0x496ec8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(4812488) /* 0x496ec8 */) = 4294967295 /*0xffffffff*/;
    // 0042d5ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d5c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d5c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042d5c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042d5c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d5c3  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042d5c7  e824380000             -call 0x430df0
    cpu.esp -= 4;
    sub_430df0(app, cpu);
    // 0042d5cc  a1c8d44a00             -mov eax, dword ptr [0x4ad4c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904136) /* 0x4ad4c8 */);
    // 0042d5d1  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042d5d3  3bc7                   +cmp eax, edi
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
    // 0042d5d5  7524                   -jne 0x42d5fb
    if (!cpu.flags.zf)
    {
        goto L_0x0042d5fb;
    }
    // 0042d5d7  a12c845100             -mov eax, dword ptr [0x51842c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342252) /* 0x51842c */);
    // 0042d5dc  0500020000             -add eax, 0x200
    (cpu.eax) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0042d5e1  a3bcd44a00             -mov dword ptr [0x4ad4bc], eax
    app->getMemory<x86::reg32>(x86::reg32(4904124) /* 0x4ad4bc */) = cpu.eax;
    // 0042d5e6  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0042d5ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042d5ee  e8879c0400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0042d5f3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042d5f6  a3c8d44a00             -mov dword ptr [0x4ad4c8], eax
    app->getMemory<x86::reg32>(x86::reg32(4904136) /* 0x4ad4c8 */) = cpu.eax;
L_0x0042d5fb:
    // 0042d5fb  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042d600  8b6828                 -mov ebp, dword ptr [eax + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0042d603  3bef                   +cmp ebp, edi
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
    // 0042d605  7506                   -jne 0x42d60d
    if (!cpu.flags.zf)
    {
        goto L_0x0042d60d;
    }
    // 0042d607  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d608  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d60a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d60b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d60c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042d60d:
    // 0042d60d  f6405401               +test byte ptr [eax + 0x54], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(84) /* 0x54 */) & 1 /*0x1*/));
    // 0042d611  7413                   -je 0x42d626
    if (cpu.flags.zf)
    {
        goto L_0x0042d626;
    }
    // 0042d613  c705c86e4900ffffffff   -mov dword ptr [0x496ec8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(4812488) /* 0x496ec8 */) = 4294967295 /*0xffffffff*/;
    // 0042d61d  8b4854                 -mov ecx, dword ptr [eax + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 0042d620  83e1fe                 -and ecx, 0xfffffffe
    cpu.ecx &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/));
    // 0042d623  894854                 -mov dword ptr [eax + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.ecx;
L_0x0042d626:
    // 0042d626  8b15c86e4900           -mov edx, dword ptr [0x496ec8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4812488) /* 0x496ec8 */);
    // 0042d62c  8b8580000000           -mov eax, dword ptr [ebp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(128) /* 0x80 */);
    // 0042d632  3bd0                   +cmp edx, eax
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
    // 0042d634  0f840c010000           -je 0x42d746
    if (cpu.flags.zf)
    {
        goto L_0x0042d746;
    }
    // 0042d63a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d63b  893dccd44a00           -mov dword ptr [0x4ad4cc], edi
    app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */) = cpu.edi;
    // 0042d641  e81a860200             -call 0x455c60
    cpu.esp -= 4;
    sub_455c60(app, cpu);
    // 0042d646  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042d648  3bf7                   +cmp esi, edi
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
    // 0042d64a  744c                   -je 0x42d698
    if (cpu.flags.zf)
    {
        goto L_0x0042d698;
    }
L_0x0042d64c:
    // 0042d64c  807e4819               +cmp byte ptr [esi + 0x48], 0x19
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(72) /* 0x48 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(25 /*0x19*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042d650  743c                   -je 0x42d68e
    if (cpu.flags.zf)
    {
        goto L_0x0042d68e;
    }
    // 0042d652  3b6e28                 +cmp ebp, dword ptr [esi + 0x28]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d655  7537                   -jne 0x42d68e
    if (!cpu.flags.zf)
    {
        goto L_0x0042d68e;
    }
    // 0042d657  8b0dc8d44a00           -mov ecx, dword ptr [0x4ad4c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904136) /* 0x4ad4c8 */);
    // 0042d65d  8b15ccd44a00           -mov edx, dword ptr [0x4ad4cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */);
    // 0042d663  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0042d669  890491                 -mov dword ptr [ecx + edx*4], eax
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4) = cpu.eax;
    // 0042d66c  a1ccd44a00             -mov eax, dword ptr [0x4ad4cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */);
    // 0042d671  8b0dbcd44a00           -mov ecx, dword ptr [0x4ad4bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904124) /* 0x4ad4bc */);
    // 0042d677  40                     -inc eax
    (cpu.eax)++;
    // 0042d678  3bc1                   +cmp eax, ecx
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
    // 0042d67a  a3ccd44a00             -mov dword ptr [0x4ad4cc], eax
    app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */) = cpu.eax;
    // 0042d67f  7c0d                   -jl 0x42d68e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042d68e;
    }
    // 0042d681  68d06f4900             -push 0x496fd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812752 /*0x496fd0*/;
    cpu.esp -= 4;
    // 0042d686  e88575ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042d68b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042d68e:
    // 0042d68e  8bb630030000           -mov esi, dword ptr [esi + 0x330]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(816) /* 0x330 */);
    // 0042d694  3bf7                   +cmp esi, edi
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
    // 0042d696  75b4                   -jne 0x42d64c
    if (!cpu.flags.zf)
    {
        goto L_0x0042d64c;
    }
L_0x0042d698:
    // 0042d698  8bb590000000           -mov esi, dword ptr [ebp + 0x90]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 0042d69e  3bf7                   +cmp esi, edi
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
    // 0042d6a0  743c                   -je 0x42d6de
    if (cpu.flags.zf)
    {
        goto L_0x0042d6de;
    }
L_0x0042d6a2:
    // 0042d6a2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0042d6a4  8b15c8d44a00           -mov edx, dword ptr [0x4ad4c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904136) /* 0x4ad4c8 */);
    // 0042d6aa  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0042d6ad  a1ccd44a00             -mov eax, dword ptr [0x4ad4cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */);
    // 0042d6b2  890c82                 -mov dword ptr [edx + eax*4], ecx
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = cpu.ecx;
    // 0042d6b5  a1ccd44a00             -mov eax, dword ptr [0x4ad4cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */);
    // 0042d6ba  8b0dbcd44a00           -mov ecx, dword ptr [0x4ad4bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904124) /* 0x4ad4bc */);
    // 0042d6c0  40                     -inc eax
    (cpu.eax)++;
    // 0042d6c1  3bc1                   +cmp eax, ecx
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
    // 0042d6c3  a3ccd44a00             -mov dword ptr [0x4ad4cc], eax
    app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */) = cpu.eax;
    // 0042d6c8  7c0d                   -jl 0x42d6d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042d6d7;
    }
    // 0042d6ca  68d06f4900             -push 0x496fd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812752 /*0x496fd0*/;
    cpu.esp -= 4;
    // 0042d6cf  e83c75ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042d6d4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042d6d7:
    // 0042d6d7  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d6da  3bf7                   +cmp esi, edi
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
    // 0042d6dc  75c4                   -jne 0x42d6a2
    if (!cpu.flags.zf)
    {
        goto L_0x0042d6a2;
    }
L_0x0042d6de:
    // 0042d6de  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042d6e3  8b485c                 -mov ecx, dword ptr [eax + 0x5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 0042d6e6  3bcf                   +cmp ecx, edi
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
    // 0042d6e8  744f                   -je 0x42d739
    if (cpu.flags.zf)
    {
        goto L_0x0042d739;
    }
    // 0042d6ea  397858                 +cmp dword ptr [eax + 0x58], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d6ed  744a                   -je 0x42d739
    if (cpu.flags.zf)
    {
        goto L_0x0042d739;
    }
    // 0042d6ef  3bcf                   +cmp ecx, edi
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
    // 0042d6f1  7e46                   -jle 0x42d739
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042d739;
    }
    // 0042d6f3  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0042d6f5:
    // 0042d6f5  8b4858                 -mov ecx, dword ptr [eax + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 0042d6f8  a1c8d44a00             -mov eax, dword ptr [0x4ad4c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904136) /* 0x4ad4c8 */);
    // 0042d6fd  8b140e                 -mov edx, dword ptr [esi + ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 0042d700  8b0dccd44a00           -mov ecx, dword ptr [0x4ad4cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */);
    // 0042d706  891488                 -mov dword ptr [eax + ecx*4], edx
    app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4) = cpu.edx;
    // 0042d709  a1ccd44a00             -mov eax, dword ptr [0x4ad4cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */);
    // 0042d70e  8b0dbcd44a00           -mov ecx, dword ptr [0x4ad4bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4904124) /* 0x4ad4bc */);
    // 0042d714  40                     -inc eax
    (cpu.eax)++;
    // 0042d715  3bc1                   +cmp eax, ecx
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
    // 0042d717  a3ccd44a00             -mov dword ptr [0x4ad4cc], eax
    app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */) = cpu.eax;
    // 0042d71c  7c0d                   -jl 0x42d72b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042d72b;
    }
    // 0042d71e  68d06f4900             -push 0x496fd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812752 /*0x496fd0*/;
    cpu.esp -= 4;
    // 0042d723  e8e874ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042d728  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042d72b:
    // 0042d72b  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042d730  47                     -inc edi
    (cpu.edi)++;
    // 0042d731  83c628                 -add esi, 0x28
    (cpu.esi) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0042d734  3b785c                 +cmp edi, dword ptr [eax + 0x5c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042d737  7cbc                   -jl 0x42d6f5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042d6f5;
    }
L_0x0042d739:
    // 0042d739  8b9580000000           -mov edx, dword ptr [ebp + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(128) /* 0x80 */);
    // 0042d73f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d740  8915c86e4900           -mov dword ptr [0x496ec8], edx
    app->getMemory<x86::reg32>(x86::reg32(4812488) /* 0x496ec8 */) = cpu.edx;
L_0x0042d746:
    // 0042d746  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042d74a  a1ccd44a00             -mov eax, dword ptr [0x4ad4cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904140) /* 0x4ad4cc */);
    // 0042d74f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d750  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d751  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0042d753  a1c8d44a00             -mov eax, dword ptr [0x4ad4c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904136) /* 0x4ad4c8 */);
    // 0042d758  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d759  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d760  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d762  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042d764  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d765  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0042d76a  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042d76c  e81f000000             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 0042d771  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042d773  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042d775  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042d777  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0042d779  e852000000             -call 0x42d7d0
    cpu.esp -= 4;
    sub_42d7d0(app, cpu);
    // 0042d77e  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042d780  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d781  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d782  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d783  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d790  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d791  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d792  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042d794  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d795  e8e09a0400             -call 0x47727a
    cpu.esp -= 4;
    _malloc(app, cpu);
    // 0042d79a  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042d79c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042d79f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042d7a1  750d                   -jne 0x42d7b0
    if (!cpu.flags.zf)
    {
        goto L_0x0042d7b0;
    }
    // 0042d7a3  6808704900             -push 0x497008
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812808 /*0x497008*/;
    cpu.esp -= 4;
    // 0042d7a8  e86374ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042d7ad  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042d7b0:
    // 0042d7b0  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042d7b2  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042d7b4  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0042d7b6  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0042d7b8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042d7bb  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0042d7bd  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0042d7bf  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0042d7c2  f3aa                   -rep stosb byte ptr es:[edi], al
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
    // 0042d7c4  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042d7c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d7c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d7c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d7d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d7d0  8b8194000000           -mov eax, dword ptr [ecx + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */);
    // 0042d7d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d7d8  7514                   -jne 0x42d7ee
    if (!cpu.flags.zf)
    {
        goto L_0x0042d7ee;
    }
    // 0042d7da  40                     -inc eax
    (cpu.eax)++;
    // 0042d7db  899198000000           -mov dword ptr [ecx + 0x98], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */) = cpu.edx;
    // 0042d7e1  89919c000000           -mov dword ptr [ecx + 0x9c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */) = cpu.edx;
    // 0042d7e7  898194000000           -mov dword ptr [ecx + 0x94], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */) = cpu.eax;
    // 0042d7ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042d7ee:
    // 0042d7ee  8b819c000000           -mov eax, dword ptr [ecx + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 0042d7f4  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042d7f7  8b8194000000           -mov eax, dword ptr [ecx + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */);
    // 0042d7fd  40                     -inc eax
    (cpu.eax)++;
    // 0042d7fe  89919c000000           -mov dword ptr [ecx + 0x9c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */) = cpu.edx;
    // 0042d804  898194000000           -mov dword ptr [ecx + 0x94], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */) = cpu.eax;
    // 0042d80a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d810  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d811  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d812  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042d814  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d815  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0042d81a  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042d81c  e86fffffff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 0042d821  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042d823  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042d825  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042d827  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0042d829  e812000000             -call 0x42d840
    cpu.esp -= 4;
    sub_42d840(app, cpu);
    // 0042d82e  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042d830  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d831  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d832  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d833  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d840  8b8188000000           -mov eax, dword ptr [ecx + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(136) /* 0x88 */);
    // 0042d846  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d848  7514                   -jne 0x42d85e
    if (!cpu.flags.zf)
    {
        goto L_0x0042d85e;
    }
    // 0042d84a  40                     -inc eax
    (cpu.eax)++;
    // 0042d84b  89918c000000           -mov dword ptr [ecx + 0x8c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */) = cpu.edx;
    // 0042d851  899190000000           -mov dword ptr [ecx + 0x90], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.edx;
    // 0042d857  898188000000           -mov dword ptr [ecx + 0x88], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0042d85d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042d85e:
    // 0042d85e  8b8190000000           -mov eax, dword ptr [ecx + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */);
    // 0042d864  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042d867  8b8188000000           -mov eax, dword ptr [ecx + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(136) /* 0x88 */);
    // 0042d86d  40                     -inc eax
    (cpu.eax)++;
    // 0042d86e  899190000000           -mov dword ptr [ecx + 0x90], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.edx;
    // 0042d874  898188000000           -mov dword ptr [ecx + 0x88], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0042d87a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d880  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d881  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d882  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0042d884  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0042d889  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042d88b  e800ffffff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 0042d890  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0042d893  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0042d895  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d896  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d897  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d8a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d8a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d8a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d8a2  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0042d8a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d8a7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042d8a9  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042d8ab  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042d8ad  750d                   -jne 0x42d8bc
    if (!cpu.flags.zf)
    {
        goto L_0x0042d8bc;
    }
    // 0042d8af  68101f4900             -push 0x491f10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4792080 /*0x491f10*/;
    cpu.esp -= 4;
    // 0042d8b4  e85773ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042d8b9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042d8bc:
    // 0042d8bc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042d8be  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d8bf  7513                   -jne 0x42d8d4
    if (!cpu.flags.zf)
    {
        goto L_0x0042d8d4;
    }
    // 0042d8c1  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d8c4  e8eb9a0400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0042d8c9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042d8cc  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042d8ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8d1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0042d8d4:
    // 0042d8d4  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042d8d7  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0042d8da  e8d59a0400             -call 0x4773b4
    cpu.esp -= 4;
    sub_4773b4(app, cpu);
    // 0042d8df  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042d8e2  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042d8e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d8e7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42d8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d8f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d8f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d8f2  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042d8f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d8f5  b9c0000000             -mov ecx, 0xc0
    cpu.ecx = 192 /*0xc0*/;
    // 0042d8fa  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042d8fc  e88ffeffff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 0042d901  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042d905  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042d907  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042d90b  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042d90d  898688000000           -mov dword ptr [esi + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0042d913  898e84000000           -mov dword ptr [esi + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 0042d919  c786b000000000000000   -mov dword ptr [esi + 0xb0], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */) = 0 /*0x0*/;
    // 0042d923  c786ac00000001000000   -mov dword ptr [esi + 0xac], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */) = 1 /*0x1*/;
    // 0042d92d  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042d92f  2bd7                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x0042d931:
    // 0042d931  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042d933  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0042d936  40                     -inc eax
    (cpu.eax)++;
    // 0042d937  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0042d939  75f6                   -jne 0x42d931
    if (!cpu.flags.zf)
    {
        goto L_0x0042d931;
    }
    // 0042d93b  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042d93d  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042d93f  e80c000000             -call 0x42d950
    cpu.esp -= 4;
    sub_42d950(app, cpu);
    // 0042d944  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042d946  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d947  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d948  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d949  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_42d950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d950  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0042d953  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042d955  750b                   -jne 0x42d962
    if (!cpu.flags.zf)
    {
        goto L_0x0042d962;
    }
    // 0042d957  40                     -inc eax
    (cpu.eax)++;
    // 0042d958  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0042d95b  895124                 -mov dword ptr [ecx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0042d95e  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0042d961  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042d962:
    // 0042d962  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 0042d965  8990bc000000           -mov dword ptr [eax + 0xbc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.edx;
    // 0042d96b  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0042d96e  40                     -inc eax
    (cpu.eax)++;
    // 0042d96f  895124                 -mov dword ptr [ecx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0042d972  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0042d975  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42d980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042d980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042d981  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042d982  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042d983  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042d985  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042d986  b99c000000             -mov ecx, 0x9c
    cpu.ecx = 156 /*0x9c*/;
    // 0042d98b  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042d98d  e8fefdffff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 0042d992  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042d994  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042d998  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042d99a  8d8e80000000           -lea ecx, [esi + 0x80]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0042d9a0  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 0042d9a2  8929                   -mov dword ptr [ecx], ebp
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebp;
    // 0042d9a4  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0042d9a7  896904                 -mov dword ptr [ecx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0042d9aa  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0042d9ad  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0042d9b0  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042d9b4  83f902                 +cmp ecx, 2
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
    // 0042d9b7  7c1b                   -jl 0x42d9d4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042d9d4;
    }
    // 0042d9b9  83c00c                 +add eax, 0xc
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042d9bc  8d8e8c000000           -lea ecx, [esi + 0x8c]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0042d9c2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042d9c4  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0042d9c6  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042d9c9  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042d9cc  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0042d9cf  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042d9d2  eb0d                   -jmp 0x42d9e1
    goto L_0x0042d9e1;
L_0x0042d9d4:
    // 0042d9d4  6820704900             -push 0x497020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4812832 /*0x497020*/;
    cpu.esp -= 4;
    // 0042d9d9  e83272ffff             -call 0x424c10
    cpu.esp -= 4;
    sub_424c10(app, cpu);
    // 0042d9de  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0042d9e1:
    // 0042d9e1  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042d9e3  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042d9e5  2bd7                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x0042d9e7:
    // 0042d9e7  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042d9e9  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0042d9ec  40                     -inc eax
    (cpu.eax)++;
    // 0042d9ed  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0042d9ef  75f6                   -jne 0x42d9e7
    if (!cpu.flags.zf)
    {
        goto L_0x0042d9e7;
    }
    // 0042d9f1  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042d9f3  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042d9f5  e816000000             -call 0x42da10
    cpu.esp -= 4;
    sub_42da10(app, cpu);
    // 0042d9fa  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042d9fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d9fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d9fe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042d9ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da00  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_42da10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042da10  8b412c                 -mov eax, dword ptr [ecx + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 0042da13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042da15  750b                   -jne 0x42da22
    if (!cpu.flags.zf)
    {
        goto L_0x0042da22;
    }
    // 0042da17  40                     -inc eax
    (cpu.eax)++;
    // 0042da18  895130                 -mov dword ptr [ecx + 0x30], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0042da1b  895134                 -mov dword ptr [ecx + 0x34], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0042da1e  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0042da21  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042da22:
    // 0042da22  8b4134                 -mov eax, dword ptr [ecx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0042da25  899098000000           -mov dword ptr [eax + 0x98], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.edx;
    // 0042da2b  8b412c                 -mov eax, dword ptr [ecx + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 0042da2e  40                     -inc eax
    (cpu.eax)++;
    // 0042da2f  895134                 -mov dword ptr [ecx + 0x34], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0042da32  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0042da35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42da40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042da40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042da41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042da42  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042da44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042da45  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0042da4a  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042da4c  e83ffdffff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 0042da51  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042da53  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042da55  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042da57  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0042da59  e812000000             -call 0x42da70
    cpu.esp -= 4;
    sub_42da70(app, cpu);
    // 0042da5e  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042da60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da62  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042da63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42da70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042da70  8b81a0000000           -mov eax, dword ptr [ecx + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 0042da76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042da78  7514                   -jne 0x42da8e
    if (!cpu.flags.zf)
    {
        goto L_0x0042da8e;
    }
    // 0042da7a  40                     -inc eax
    (cpu.eax)++;
    // 0042da7b  8991a4000000           -mov dword ptr [ecx + 0xa4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */) = cpu.edx;
    // 0042da81  8991a8000000           -mov dword ptr [ecx + 0xa8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.edx;
    // 0042da87  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0042da8d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042da8e:
    // 0042da8e  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0042da94  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042da97  8b81a0000000           -mov eax, dword ptr [ecx + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 0042da9d  40                     -inc eax
    (cpu.eax)++;
    // 0042da9e  8991a8000000           -mov dword ptr [ecx + 0xa8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.edx;
    // 0042daa4  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0042daaa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42dab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042dab0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dab1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dab2  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042dab4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042dab5  b9a4000000             -mov ecx, 0xa4
    cpu.ecx = 164 /*0xa4*/;
    // 0042daba  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042dabc  e8cffcffff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 0042dac1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042dac5  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042dac7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042dacb  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042dacd  898684000000           -mov dword ptr [esi + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 0042dad3  898e80000000           -mov dword ptr [esi + 0x80], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */) = cpu.ecx;
    // 0042dad9  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042dadb  2bd7                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x0042dadd:
    // 0042dadd  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042dadf  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0042dae2  40                     -inc eax
    (cpu.eax)++;
    // 0042dae3  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0042dae5  75f6                   -jne 0x42dadd
    if (!cpu.flags.zf)
    {
        goto L_0x0042dadd;
    }
    // 0042dae7  8bd6                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0042dae9  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0042daeb  e810000000             -call 0x42db00
    cpu.esp -= 4;
    sub_42db00(app, cpu);
    // 0042daf0  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042daf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042daf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042daf4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042daf5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_42db00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042db00  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042db02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042db04  750a                   -jne 0x42db10
    if (!cpu.flags.zf)
    {
        goto L_0x0042db10;
    }
    // 0042db06  40                     -inc eax
    (cpu.eax)++;
    // 0042db07  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042db0a  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0042db0d  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0042db0f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042db10:
    // 0042db10  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0042db13  899098000000           -mov dword ptr [eax + 0x98], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.edx;
    // 0042db19  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042db1b  40                     -inc eax
    (cpu.eax)++;
    // 0042db1c  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0042db1f  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0042db21  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42db30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042db30  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0042db33  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 0042db35  d94108                 -fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 0042db38  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0042db3a  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0042db3e  dd5c2420               -fstp qword ptr [esp + 0x20]
    app->getMemory<double>(cpu.esp + x86::reg32(32) /* 0x20 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042db42  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0042db44  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 0042db47  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0042db4b  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0042db4d  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 0042db50  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042db54  d8e2                   -fsub st(2)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(2));
    // 0042db56  dd5c2400               -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042db5a  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0042db5c  d8e3                   -fsub st(3)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(3));
    // 0042db5e  dd5c2410               -fstp qword ptr [esp + 0x10]
    app->getMemory<double>(cpu.esp + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042db62  dd442418               -fld qword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0042db66  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 0042db68  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042db6c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042db6e  d8e2                   -fsub st(2)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(2));
    // 0042db70  dd5c2418               -fstp qword ptr [esp + 0x18]
    app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042db74  d86a08                 -fsubr dword ptr [edx + 8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)) - cpu.fpu.st(0);
    // 0042db77  dd442420               -fld qword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0042db7b  d8e2                   -fsub st(2)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(2));
    // 0042db7d  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 0042db7f  dc4c2400               -fmul qword ptr [esp]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(cpu.esp));
    // 0042db83  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 0042db85  dc4c2408               -fmul qword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0042db89  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042db8b  dd442410               -fld qword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0042db8f  dc4c2400               -fmul qword ptr [esp]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(cpu.esp));
    // 0042db93  dd442418               -fld qword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0042db97  dc4c2408               -fmul qword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0042db9b  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042db9d  d8f1                   -fdiv st(1)
    cpu.fpu.st(0) /= x86::Float(cpu.fpu.st(1));
    // 0042db9f  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042dba3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0042dba5  dc4c2410               -fmul qword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0042dba9  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0042dbab  dc4c2418               -fmul qword ptr [esp + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(24) /* 0x18 */));
    // 0042dbaf  deea                   -fsubp st(2)
    cpu.fpu.st(2) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0042dbb1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0042dbb3  d8f1                   -fdiv st(1)
    cpu.fpu.st(0) /= x86::Float(cpu.fpu.st(1));
    // 0042dbb5  ddda                   -fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042dbb7  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0042dbb9  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0042dbbd  dc1d68734800           -fcomp qword ptr [0x487368]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */)));
    cpu.fpu.pop();
    // 0042dbc3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042dbc5  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042dbc8  7a3a                   -jp 0x42dc04
    if (cpu.flags.pf)
    {
        goto L_0x0042dc04;
    }
    // 0042dbca  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0042dbce  dc1d70744800           -fcomp qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    cpu.fpu.pop();
    // 0042dbd4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042dbd6  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042dbdb  7527                   -jne 0x42dc04
    if (!cpu.flags.zf)
    {
        goto L_0x0042dc04;
    }
    // 0042dbdd  dc1568734800           -fcom qword ptr [0x487368]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748136) /* 0x487368 */)));
    // 0042dbe3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042dbe5  f6c405                 +test ah, 5
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 5 /*0x5*/));
    // 0042dbe8  7a1a                   -jp 0x42dc04
    if (cpu.flags.pf)
    {
        goto L_0x0042dc04;
    }
    // 0042dbea  dc1d70744800           -fcomp qword ptr [0x487470]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(4748400) /* 0x487470 */)));
    cpu.fpu.pop();
    // 0042dbf0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0042dbf2  2500410000             +and eax, 0x4100
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(16640 /*0x4100*/))));
    // 0042dbf7  750d                   -jne 0x42dc06
    if (!cpu.flags.zf)
    {
        goto L_0x0042dc06;
    }
    // 0042dbf9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042dbfe  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0042dc01  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0042dc04:
    // 0042dc04  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0042dc06:
    // 0042dc06  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042dc08  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0042dc0b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_42dc10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042dc10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dc11  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042dc13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dc14  c7431400000000         -mov dword ptr [ebx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0042dc1b  8b354cea4a00           -mov esi, dword ptr [0x4aea4c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4909644) /* 0x4aea4c */);
    // 0042dc21  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042dc23  7464                   -je 0x42dc89
    if (cpu.flags.zf)
    {
        goto L_0x0042dc89;
    }
    // 0042dc25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0042dc26:
    // 0042dc26  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 0042dc2b  e860fbffff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    // 0042dc30  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042dc32  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0042dc35  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042dc37  894724                 -mov dword ptr [edi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0042dc3a  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0042dc3d  8b1530845100           -mov edx, dword ptr [0x518430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042dc43  8b048a                 -mov eax, dword ptr [edx + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 0042dc46  8b88a8020000           -mov ecx, dword ptr [eax + 0x2a8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(680) /* 0x2a8 */);
    // 0042dc4c  894f20                 -mov dword ptr [edi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0042dc4f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0042dc52  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042dc57  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0042dc59  8b1490                 -mov edx, dword ptr [eax + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0042dc5c  e89f230000             -call 0x430000
    cpu.esp -= 4;
    sub_430000(app, cpu);
    // 0042dc61  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042dc63  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042dc65  2bd6                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0042dc67:
    // 0042dc67  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0042dc69  880c02                 -mov byte ptr [edx + eax], cl
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = cpu.cl;
    // 0042dc6c  40                     -inc eax
    (cpu.eax)++;
    // 0042dc6d  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0042dc6f  75f6                   -jne 0x42dc67
    if (!cpu.flags.zf)
    {
        goto L_0x0042dc67;
    }
    // 0042dc71  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0042dc74  897b18                 -mov dword ptr [ebx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0042dc77  894760                 -mov dword ptr [edi + 0x60], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0042dc7a  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0042dc7d  41                     -inc ecx
    (cpu.ecx)++;
    // 0042dc7e  894b14                 -mov dword ptr [ebx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0042dc81  8b7618                 -mov esi, dword ptr [esi + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0042dc84  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042dc86  759e                   -jne 0x42dc26
    if (!cpu.flags.zf)
    {
        goto L_0x0042dc26;
    }
    // 0042dc88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042dc89:
    // 0042dc89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dc8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dc8b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42dc90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042dc90  a1c4d44a00             -mov eax, dword ptr [0x4ad4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042dc95  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042dc96  8b7820                 -mov edi, dword ptr [eax + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0042dc99  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042dc9b  7441                   -je 0x42dcde
    if (cpu.flags.zf)
    {
        goto L_0x0042dcde;
    }
    // 0042dc9d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dc9e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x0042dc9f:
    // 0042dc9f  398f80000000           +cmp dword ptr [edi + 0x80], ecx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(128) /* 0x80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042dca5  752b                   -jne 0x42dcd2
    if (!cpu.flags.zf)
    {
        goto L_0x0042dcd2;
    }
    // 0042dca7  8b8790000000           -mov eax, dword ptr [edi + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */);
    // 0042dcad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042dcaf  7421                   -je 0x42dcd2
    if (cpu.flags.zf)
    {
        goto L_0x0042dcd2;
    }
L_0x0042dcb1:
    // 0042dcb1  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042dcb3  8b1d30845100           -mov ebx, dword ptr [0x518430]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042dcb9  8b7224                 -mov esi, dword ptr [edx + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 0042dcbc  8b34b3                 -mov esi, dword ptr [ebx + esi*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + cpu.esi * 4);
    // 0042dcbf  8bb6a8020000           -mov esi, dword ptr [esi + 0x2a8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(680) /* 0x2a8 */);
    // 0042dcc5  89722c                 -mov dword ptr [edx + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = cpu.esi;
    // 0042dcc8  897220                 -mov dword ptr [edx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0042dccb  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042dcce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042dcd0  75df                   -jne 0x42dcb1
    if (!cpu.flags.zf)
    {
        goto L_0x0042dcb1;
    }
L_0x0042dcd2:
    // 0042dcd2  8bbfbc000000           -mov edi, dword ptr [edi + 0xbc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(188) /* 0xbc */);
    // 0042dcd8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0042dcda  75c3                   -jne 0x42dc9f
    if (!cpu.flags.zf)
    {
        goto L_0x0042dc9f;
    }
    // 0042dcdc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dcdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042dcde:
    // 0042dcde  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dcdf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_42dce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042dce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dce1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042dce2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dce3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042dce4  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042dce6  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042dcea  8be9                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0042dcec  8b8790000000           -mov eax, dword ptr [edi + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */);
    // 0042dcf2  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042dcf4  395924                 +cmp dword ptr [ecx + 0x24], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042dcf7  7442                   -je 0x42dd3b
    if (cpu.flags.zf)
    {
        goto L_0x0042dd3b;
    }
    // 0042dcf9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dcfa  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0042dcfc  e86f000000             -call 0x42dd70
    cpu.esp -= 4;
    sub_42dd70(app, cpu);
    // 0042dd01  83f801                 +cmp eax, 1
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
    // 0042dd04  7507                   -jne 0x42dd0d
    if (!cpu.flags.zf)
    {
        goto L_0x0042dd0d;
    }
    // 0042dd06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd09  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd0a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0042dd0d:
    // 0042dd0d  8b15c4d44a00           -mov edx, dword ptr [0x4ad4c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4904132) /* 0x4ad4c4 */);
    // 0042dd13  8b7220                 -mov esi, dword ptr [edx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0042dd16  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042dd18  7421                   -je 0x42dd3b
    if (cpu.flags.zf)
    {
        goto L_0x0042dd3b;
    }
L_0x0042dd1a:
    // 0042dd1a  3bf5                   +cmp esi, ebp
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
    // 0042dd1c  7413                   -je 0x42dd31
    if (cpu.flags.zf)
    {
        goto L_0x0042dd31;
    }
    // 0042dd1e  3bf7                   +cmp esi, edi
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
    // 0042dd20  740f                   -je 0x42dd31
    if (cpu.flags.zf)
    {
        goto L_0x0042dd31;
    }
    // 0042dd22  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dd23  8bd7                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042dd25  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042dd27  e844000000             -call 0x42dd70
    cpu.esp -= 4;
    sub_42dd70(app, cpu);
    // 0042dd2c  83f801                 +cmp eax, 1
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
    // 0042dd2f  7413                   -je 0x42dd44
    if (cpu.flags.zf)
    {
        goto L_0x0042dd44;
    }
L_0x0042dd31:
    // 0042dd31  8bb6bc000000           -mov esi, dword ptr [esi + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 0042dd37  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042dd39  75df                   -jne 0x42dd1a
    if (!cpu.flags.zf)
    {
        goto L_0x0042dd1a;
    }
L_0x0042dd3b:
    // 0042dd3b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd3c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd3e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042dd40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd41  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0042dd44:
    // 0042dd44  a130845100             -mov eax, dword ptr [0x518430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5342256) /* 0x518430 */);
    // 0042dd49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd4b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd4c  8b1c98                 -mov ebx, dword ptr [eax + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 0042dd4f  8b83a8020000           -mov eax, dword ptr [ebx + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(680) /* 0x2a8 */);
    // 0042dd55  25ffffffbf             -and eax, 0xbfffffff
    cpu.eax &= x86::reg32(x86::sreg32(3221225471 /*0xbfffffff*/));
    // 0042dd5a  8983a8020000           -mov dword ptr [ebx + 0x2a8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(680) /* 0x2a8 */) = cpu.eax;
    // 0042dd60  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042dd65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd66  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_42dd70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042dd70  8b8190000000           -mov eax, dword ptr [ecx + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */);
    // 0042dd76  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042dd77  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042dd78  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042dd7a  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042dd7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042dd7e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042dd7f  7414                   -je 0x42dd95
    if (cpu.flags.zf)
    {
        goto L_0x0042dd95;
    }
    // 0042dd81  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0042dd85:
    // 0042dd85  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042dd87  397b24                 +cmp dword ptr [ebx + 0x24], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042dd8a  7411                   -je 0x42dd9d
    if (cpu.flags.zf)
    {
        goto L_0x0042dd9d;
    }
    // 0042dd8c  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042dd8e  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042dd91  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042dd93  75f0                   -jne 0x42dd85
    if (!cpu.flags.zf)
    {
        goto L_0x0042dd85;
    }
L_0x0042dd95:
    // 0042dd95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd97  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042dd99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042dd9a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0042dd9d:
    // 0042dd9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042dd9e  e83d000000             -call 0x42dde0
    cpu.esp -= 4;
    sub_42dde0(app, cpu);
    // 0042dda3  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042dda5  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0042dda7  e814000000             -call 0x42ddc0
    cpu.esp -= 4;
    sub_42ddc0(app, cpu);
    // 0042ddac  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042ddb1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ddb2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ddb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042ddb4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

}
