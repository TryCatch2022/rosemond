#include "black.h"
namespace black
{

/* align: skip  */
void Application::asm_sub_401000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401000  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00401003  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401004  8b1dc0404000           -mov ebx, dword ptr [0x4040c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4210880) /* 0x4040c0 */);
    // 0040100a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040100b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040100c  8b35a8404000           -mov esi, dword ptr [0x4040a8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4210856) /* 0x4040a8 */);
    // 00401012  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401013  8b3da4404000           -mov edi, dword ptr [0x4040a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4210852) /* 0x4040a4 */);
    // 00401019  bd14000000             -mov ebp, 0x14
    cpu.ebp = 20 /*0x14*/;
L_0x0040101e:
    // 0040101e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401020  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401022  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401024  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00401028  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040102a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040102b  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040102d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040102f  7411                   -je 0x401042
    if (cpu.flags.zf)
    {
        goto L_0x00401042;
    }
    // 00401031  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00401035  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401036  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401038  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040103c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040103d  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040103f  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00401040  75dc                   -jne 0x40101e
    if (!cpu.flags.zf)
    {
        goto L_0x0040101e;
    }
L_0x00401042:
    // 00401042  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401043  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401044  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401045  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401046  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00401049  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401050  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401051  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00401055  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401056  e865000000             -call 0x4010c0
    cpu.esp -= 4;
    sub_4010c0(app, cpu);
    // 0040105b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040105e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401060  7435                   -je 0x401097
    if (cpu.flags.zf)
    {
        goto L_0x00401097;
    }
    // 00401062  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00401066  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401067  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401068  e8c3000000             -call 0x401130
    cpu.esp -= 4;
    sub_401130(app, cpu);
    // 0040106d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00401070  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401072  7423                   -je 0x401097
    if (cpu.flags.zf)
    {
        goto L_0x00401097;
    }
    // 00401074  ff1508404000           -call dword ptr [0x404008]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210696) /* 0x404008 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040107a  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 0040107c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040107d  ff150c404000           -call dword ptr [0x40400c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210700) /* 0x40400c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401083  8b3560404000           -mov esi, dword ptr [0x404060]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4210784) /* 0x404060 */);
L_0x00401089:
    // 00401089  68e8030000             -push 0x3e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1000 /*0x3e8*/;
    cpu.esp -= 4;
    // 0040108e  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401090  e86bffffff             -call 0x401000
    cpu.esp -= 4;
    sub_401000(app, cpu);
    // 00401095  ebf2                   -jmp 0x401089
    goto L_0x00401089;
L_0x00401097:
    // 00401097  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401099  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040109a  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_4010a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004010a0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004010a4  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004010a8  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004010ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004010ad  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004010b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004010b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004010b3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004010b4  ff15c8404000           -call dword ptr [0x4040c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210888) /* 0x4040c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004010ba  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::asm_sub_4010c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004010c0  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004010c3  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004010c7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004010c8  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004010ca  68007f0000             -push 0x7f00
    app->getMemory<x86::reg32>(cpu.esp-4) = 32512 /*0x7f00*/;
    cpu.esp -= 4;
    // 004010cf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004010d0  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004010d4  c7442410a0104000       -mov dword ptr [esp + 0x10], 0x4010a0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 4198560 /*0x4010a0*/;
    // 004010dc  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 004010e0  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004010e4  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004010e8  ff15b4404000           -call dword ptr [0x4040b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210868) /* 0x4040b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004010ee  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004010f0  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004010f4  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004010f8  ff1500404000           -call dword ptr [0x404000]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210688) /* 0x404000 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004010fe  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00401102  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00401106  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401107  89742428               -mov dword ptr [esp + 0x28], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 0040110b  c744242c34504000       -mov dword ptr [esp + 0x2c], 0x405034
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4214836 /*0x405034*/;
    // 00401113  ff15c4404000           -call dword ptr [0x4040c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210884) /* 0x4040c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401119  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040111e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040111f  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00401122  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401130  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00401134  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401135  8b35b0404000           -mov esi, dword ptr [0x4040b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4210864) /* 0x4040b0 */);
    // 0040113b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040113d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040113e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401140  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401142  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401144  a34c564000             -mov dword ptr [0x40564c], eax
    app->getMemory<x86::reg32>(x86::reg32(4216396) /* 0x40564c */) = cpu.eax;
    // 00401149  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040114b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040114c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040114e  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401150  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401151  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401153  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401155  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 0040115a  68a0544000             -push 0x4054a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4215968 /*0x4054a0*/;
    cpu.esp -= 4;
    // 0040115f  6834504000             -push 0x405034
    app->getMemory<x86::reg32>(cpu.esp-4) = 4214836 /*0x405034*/;
    cpu.esp -= 4;
    // 00401164  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401166  ff15ac404000           -call dword ptr [0x4040ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210860) /* 0x4040ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040116c  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040116e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00401170  7502                   -jne 0x401174
    if (!cpu.flags.zf)
    {
        goto L_0x00401174;
    }
    // 00401172  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401173  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401174:
    // 00401174  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00401178  893550564000           -mov dword ptr [0x405650], esi
    app->getMemory<x86::reg32>(x86::reg32(4216400) /* 0x405650 */) = cpu.esi;
    // 0040117e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040117f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401180  ff15b8404000           -call dword ptr [0x4040b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210872) /* 0x4040b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401186  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401187  ff15bc404000           -call dword ptr [0x4040bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210876) /* 0x4040bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040118d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00401192  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401193  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4011a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004011a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004011a1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004011a3  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004011a5  68d0404000             -push 0x4040d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4210896 /*0x4040d0*/;
    cpu.esp -= 4;
    // 004011aa  68d41c4000             -push 0x401cd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4201684 /*0x401cd4*/;
    cpu.esp -= 4;
    // 004011af  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 004011b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004011b6  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 004011bd  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 004011c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004011c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004011c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004011c3  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 004011c6  ff1548404000           -call dword ptr [0x404048]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210760) /* 0x404048 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004011cc  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004011ce  8ad4                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004011d0  8915c8544000           -mov dword ptr [0x4054c8], edx
    app->getMemory<x86::reg32>(x86::reg32(4216008) /* 0x4054c8 */) = cpu.edx;
    // 004011d6  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004011d8  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004011de  890dc4544000           -mov dword ptr [0x4054c4], ecx
    app->getMemory<x86::reg32>(x86::reg32(4216004) /* 0x4054c4 */) = cpu.ecx;
    // 004011e4  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004011e7  03ca                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004011e9  890dc0544000           -mov dword ptr [0x4054c0], ecx
    app->getMemory<x86::reg32>(x86::reg32(4216000) /* 0x4054c0 */) = cpu.ecx;
    // 004011ef  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004011f2  a3bc544000             -mov dword ptr [0x4054bc], eax
    app->getMemory<x86::reg32>(x86::reg32(4215996) /* 0x4054bc */) = cpu.eax;
    // 004011f7  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004011f9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004011fa  e8a1090000             -call 0x401ba0
    cpu.esp -= 4;
    sub_401ba0(app, cpu);
    // 004011ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401200  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401202  7508                   -jne 0x40120c
    if (!cpu.flags.zf)
    {
        goto L_0x0040120c;
    }
    // 00401204  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 00401206  e8b0000000             -call 0x4012bb
    cpu.esp -= 4;
    sub_4012bb(app, cpu);
    // 0040120b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040120c:
    // 0040120c  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0040120f  e8e1070000             -call 0x4019f5
    cpu.esp -= 4;
    sub_4019f5(app, cpu);
    // 00401214  ff1544404000           -call dword ptr [0x404044]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210756) /* 0x404044 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040121a  a3b8594000             -mov dword ptr [0x4059b8], eax
    app->getMemory<x86::reg32>(x86::reg32(4217272) /* 0x4059b8 */) = cpu.eax;
    // 0040121f  e89f060000             -call 0x4018c3
    cpu.esp -= 4;
    sub_4018c3(app, cpu);
    // 00401224  a3a4544000             -mov dword ptr [0x4054a4], eax
    app->getMemory<x86::reg32>(x86::reg32(4215972) /* 0x4054a4 */) = cpu.eax;
    // 00401229  e848040000             -call 0x401676
    cpu.esp -= 4;
    sub_401676(app, cpu);
    // 0040122e  e88a030000             -call 0x4015bd
    cpu.esp -= 4;
    sub_4015bd(app, cpu);
    // 00401233  e8a7000000             -call 0x4012df
    cpu.esp -= 4;
    sub_4012df(app, cpu);
    // 00401238  8975d0                 -mov dword ptr [ebp - 0x30], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.esi;
    // 0040123b  8d45a4                 -lea eax, [ebp - 0x5c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 0040123e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040123f  ff1540404000           -call dword ptr [0x404040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210752) /* 0x404040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401245  e81b030000             -call 0x401565
    cpu.esp -= 4;
    sub_401565(app, cpu);
    // 0040124a  89459c                 -mov dword ptr [ebp - 0x64], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-100) /* -0x64 */) = cpu.eax;
    // 0040124d  f645d001               +test byte ptr [ebp - 0x30], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-48) /* -0x30 */) & 1 /*0x1*/));
    // 00401251  7406                   -je 0x401259
    if (cpu.flags.zf)
    {
        goto L_0x00401259;
    }
    // 00401253  0fb745d4               -movzx eax, word ptr [ebp - 0x2c]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */));
    // 00401257  eb03                   -jmp 0x40125c
    goto L_0x0040125c;
L_0x00401259:
    // 00401259  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0040125b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040125c:
    // 0040125c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040125d  ff759c                 -push dword ptr [ebp - 0x64]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    cpu.esp -= 4;
    // 00401260  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401261  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401262  ff153c404000           -call dword ptr [0x40403c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210748) /* 0x40403c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401268  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401269  e8e2fdffff             -call 0x401050
    cpu.esp -= 4;
    sub_401050(app, cpu);
    // 0040126e  8945a0                 -mov dword ptr [ebp - 0x60], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-96) /* -0x60 */) = cpu.eax;
    // 00401271  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401272  e895000000             -call 0x40130c
    cpu.esp -= 4;
    sub_40130c(app, cpu);
    // 00401277  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0040127a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0040127c  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040127e  894d98                 -mov dword ptr [ebp - 0x68], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-104) /* -0x68 */) = cpu.ecx;
    // 00401281  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401282  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401283  e859010000             -call 0x4013e1
    cpu.esp -= 4;
    sub_4013e1(app, cpu);
    // 00401288  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401289  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040128a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40128b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040128b  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0040128e  ff7598                 -push dword ptr [ebp - 0x68]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-104) /* -0x68 */);
    cpu.esp -= 4;
    // 00401291  e887000000             -call 0x40131d
    cpu.esp -= 4;
    sub_40131d(app, cpu);
    return sub_401296(app, cpu);
}

/* align: skip  */
void Application::asm_sub_401296(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401296  833dac54400001         +cmp dword ptr [0x4054ac], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4215980) /* 0x4054ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040129d  7505                   -jne 0x4012a4
    if (!cpu.flags.zf)
    {
        goto L_0x004012a4;
    }
    // 0040129f  e8080b0000             -call 0x401dac
    cpu.esp -= 4;
    sub_401dac(app, cpu);
L_0x004012a4:
    // 004012a4  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004012a8  e8380b0000             -call 0x401de5
    cpu.esp -= 4;
    sub_401de5(app, cpu);
    // 004012ad  68ff000000             -push 0xff
    app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 004012b2  ff1544504000           -call dword ptr [0x405044]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4214852) /* 0x405044 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    NFS2_ASSERT(false);  // falls off the end of the routine
}

/* align: skip  */
void Application::asm_sub_4012bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004012bb  833dac54400001         +cmp dword ptr [0x4054ac], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4215980) /* 0x4054ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004012c2  7505                   -jne 0x4012c9
    if (!cpu.flags.zf)
    {
        goto L_0x004012c9;
    }
    // 004012c4  e8e30a0000             -call 0x401dac
    cpu.esp -= 4;
    sub_401dac(app, cpu);
L_0x004012c9:
    // 004012c9  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004012cd  e8130b0000             -call 0x401de5
    cpu.esp -= 4;
    sub_401de5(app, cpu);
    // 004012d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004012d3  68ff000000             -push 0xff
    app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 004012d8  ff154c404000           -call dword ptr [0x40404c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210764) /* 0x40404c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    NFS2_ASSERT(false);  // falls off the end of the routine
}

/* align: skip  */
void Application::asm_sub_4012df(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004012df  a1b4594000             -mov eax, dword ptr [0x4059b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4217268) /* 0x4059b4 */);
    // 004012e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004012e6  7402                   -je 0x4012ea
    if (cpu.flags.zf)
    {
        goto L_0x004012ea;
    }
    // 004012e8  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004012ea:
    // 004012ea  6810504000             -push 0x405010
    app->getMemory<x86::reg32>(cpu.esp-4) = 4214800 /*0x405010*/;
    cpu.esp -= 4;
    // 004012ef  6808504000             -push 0x405008
    app->getMemory<x86::reg32>(cpu.esp-4) = 4214792 /*0x405008*/;
    cpu.esp -= 4;
    // 004012f4  e8ce000000             -call 0x4013c7
    cpu.esp -= 4;
    sub_4013c7(app, cpu);
    // 004012f9  6804504000             -push 0x405004
    app->getMemory<x86::reg32>(cpu.esp-4) = 4214788 /*0x405004*/;
    cpu.esp -= 4;
    // 004012fe  6800504000             -push 0x405000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4214784 /*0x405000*/;
    cpu.esp -= 4;
    // 00401303  e8bf000000             -call 0x4013c7
    cpu.esp -= 4;
    sub_4013c7(app, cpu);
    // 00401308  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040130b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40130c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040130c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040130e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401310  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00401314  e815000000             -call 0x40132e
    cpu.esp -= 4;
    sub_40132e(app, cpu);
    // 00401319  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040131c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40131d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040131d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040131f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401321  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00401325  e804000000             -call 0x40132e
    cpu.esp -= 4;
    sub_40132e(app, cpu);
    // 0040132a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040132d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40132e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040132e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040132f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401331  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401332  393df8544000           +cmp dword ptr [0x4054f8], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4216056) /* 0x4054f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401338  7511                   -jne 0x40134b
    if (!cpu.flags.zf)
    {
        goto L_0x0040134b;
    }
    // 0040133a  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0040133e  ff1508404000           -call dword ptr [0x404008]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210696) /* 0x404008 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401344  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401345  ff1550404000           -call dword ptr [0x404050]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210768) /* 0x404050 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0040134b:
    // 0040134b  837c240c00             +cmp dword ptr [esp + 0xc], 0
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
    // 00401350  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401351  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00401355  893df4544000           -mov dword ptr [0x4054f4], edi
    app->getMemory<x86::reg32>(x86::reg32(4216052) /* 0x4054f4 */) = cpu.edi;
    // 0040135b  881df0544000           -mov byte ptr [0x4054f0], bl
    app->getMemory<x86::reg8>(x86::reg32(4216048) /* 0x4054f0 */) = cpu.bl;
    // 00401361  753c                   -jne 0x40139f
    if (!cpu.flags.zf)
    {
        goto L_0x0040139f;
    }
    // 00401363  a1b0594000             -mov eax, dword ptr [0x4059b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4217264) /* 0x4059b0 */);
    // 00401368  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040136a  7422                   -je 0x40138e
    if (cpu.flags.zf)
    {
        goto L_0x0040138e;
    }
    // 0040136c  8b0dac594000           -mov ecx, dword ptr [0x4059ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4217260) /* 0x4059ac */);
    // 00401372  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401373  8d71fc                 -lea esi, [ecx - 4]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00401376  3bf0                   +cmp esi, eax
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
    // 00401378  7213                   -jb 0x40138d
    if (cpu.flags.cf)
    {
        goto L_0x0040138d;
    }
L_0x0040137a:
    // 0040137a  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0040137c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040137e  7402                   -je 0x401382
    if (cpu.flags.zf)
    {
        goto L_0x00401382;
    }
    // 00401380  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00401382:
    // 00401382  83ee04                 -sub esi, 4
    (cpu.esi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401385  3b35b0594000           +cmp esi, dword ptr [0x4059b0]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4217264) /* 0x4059b0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040138b  73ed                   -jae 0x40137a
    if (!cpu.flags.cf)
    {
        goto L_0x0040137a;
    }
L_0x0040138d:
    // 0040138d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040138e:
    // 0040138e  6818504000             -push 0x405018
    app->getMemory<x86::reg32>(cpu.esp-4) = 4214808 /*0x405018*/;
    cpu.esp -= 4;
    // 00401393  6814504000             -push 0x405014
    app->getMemory<x86::reg32>(cpu.esp-4) = 4214804 /*0x405014*/;
    cpu.esp -= 4;
    // 00401398  e82a000000             -call 0x4013c7
    cpu.esp -= 4;
    sub_4013c7(app, cpu);
    // 0040139d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040139e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040139f:
    // 0040139f  6820504000             -push 0x405020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4214816 /*0x405020*/;
    cpu.esp -= 4;
    // 004013a4  681c504000             -push 0x40501c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4214812 /*0x40501c*/;
    cpu.esp -= 4;
    // 004013a9  e819000000             -call 0x4013c7
    cpu.esp -= 4;
    sub_4013c7(app, cpu);
    // 004013ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004013af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004013b0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004013b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004013b3  7510                   -jne 0x4013c5
    if (!cpu.flags.zf)
    {
        goto L_0x004013c5;
    }
    // 004013b5  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004013b9  893df8544000           -mov dword ptr [0x4054f8], edi
    app->getMemory<x86::reg32>(x86::reg32(4216056) /* 0x4054f8 */) = cpu.edi;
    // 004013bf  ff154c404000           -call dword ptr [0x40404c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210764) /* 0x40404c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004013c5:
    // 004013c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004013c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4013c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004013c7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004013c8  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x004013cc:
    // 004013cc  3b74240c               +cmp esi, dword ptr [esp + 0xc]
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
    // 004013d0  730d                   -jae 0x4013df
    if (!cpu.flags.cf)
    {
        goto L_0x004013df;
    }
    // 004013d2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004013d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004013d6  7402                   -je 0x4013da
    if (cpu.flags.zf)
    {
        goto L_0x004013da;
    }
    // 004013d8  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004013da:
    // 004013da  83c604                 +add esi, 4
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
    // 004013dd  ebed                   -jmp 0x4013cc
    goto L_0x004013cc;
L_0x004013df:
    // 004013df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004013e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4013e1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004013e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004013e2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004013e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004013e5  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004013e8  e835010000             -call 0x401522
    cpu.esp -= 4;
    sub_401522(app, cpu);
    // 004013ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004013ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004013f0  0f8420010000           -je 0x401516
    if (cpu.flags.zf)
    {
        goto L_0x00401516;
    }
    // 004013f6  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004013f9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004013fb  0f8415010000           -je 0x401516
    if (cpu.flags.zf)
    {
        goto L_0x00401516;
    }
    // 00401401  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401404  750c                   -jne 0x401412
    if (!cpu.flags.zf)
    {
        goto L_0x00401412;
    }
    // 00401406  83600800               +and dword ptr [eax + 8], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/))));
    // 0040140a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040140c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040140d  e90d010000             -jmp 0x40151f
    goto L_0x0040151f;
L_0x00401412:
    // 00401412  83fb01                 +cmp ebx, 1
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
    // 00401415  0f84f6000000           -je 0x401511
    if (cpu.flags.zf)
    {
        goto L_0x00401511;
    }
    // 0040141b  8b0dfc544000           -mov ecx, dword ptr [0x4054fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4216060) /* 0x4054fc */);
    // 00401421  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00401424  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00401427  890dfc544000           -mov dword ptr [0x4054fc], ecx
    app->getMemory<x86::reg32>(x86::reg32(4216060) /* 0x4054fc */) = cpu.ecx;
    // 0040142d  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00401430  83f908                 +cmp ecx, 8
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
    // 00401433  0f85c8000000           -jne 0x401501
    if (!cpu.flags.zf)
    {
        goto L_0x00401501;
    }
    // 00401439  8b0dc8504000           -mov ecx, dword ptr [0x4050c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4214984) /* 0x4050c8 */);
    // 0040143f  8b15cc504000           -mov edx, dword ptr [0x4050cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4214988) /* 0x4050cc */);
    // 00401445  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00401447  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401448  3bca                   +cmp ecx, edx
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
    // 0040144a  7d15                   -jge 0x401461
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00401461;
    }
    // 0040144c  8d3449                 -lea esi, [ecx + ecx*2]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0040144f  2bd1                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00401451  8d34b558504000         -lea esi, [esi*4 + 0x405058]
    cpu.esi = x86::reg32(x86::reg32(4214872) /* 0x405058 */ + cpu.esi * 4);
L_0x00401458:
    // 00401458  832600                 -and dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0040145b  83c60c                 +add esi, 0xc
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
    // 0040145e  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040145f  75f7                   -jne 0x401458
    if (!cpu.flags.zf)
    {
        goto L_0x00401458;
    }
L_0x00401461:
    // 00401461  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00401463  8b35d4504000           -mov esi, dword ptr [0x4050d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4214996) /* 0x4050d4 */);
    // 00401469  3d8e0000c0             +cmp eax, 0xc000008e
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
    // 0040146e  750c                   -jne 0x40147c
    if (!cpu.flags.zf)
    {
        goto L_0x0040147c;
    }
    // 00401470  c705d450400083000000   -mov dword ptr [0x4050d4], 0x83
    app->getMemory<x86::reg32>(x86::reg32(4214996) /* 0x4050d4 */) = 131 /*0x83*/;
    // 0040147a  eb70                   -jmp 0x4014ec
    goto L_0x004014ec;
L_0x0040147c:
    // 0040147c  3d900000c0             +cmp eax, 0xc0000090
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
    // 00401481  750c                   -jne 0x40148f
    if (!cpu.flags.zf)
    {
        goto L_0x0040148f;
    }
    // 00401483  c705d450400081000000   -mov dword ptr [0x4050d4], 0x81
    app->getMemory<x86::reg32>(x86::reg32(4214996) /* 0x4050d4 */) = 129 /*0x81*/;
    // 0040148d  eb5d                   -jmp 0x4014ec
    goto L_0x004014ec;
L_0x0040148f:
    // 0040148f  3d910000c0             +cmp eax, 0xc0000091
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
    // 00401494  750c                   -jne 0x4014a2
    if (!cpu.flags.zf)
    {
        goto L_0x004014a2;
    }
    // 00401496  c705d450400084000000   -mov dword ptr [0x4050d4], 0x84
    app->getMemory<x86::reg32>(x86::reg32(4214996) /* 0x4050d4 */) = 132 /*0x84*/;
    // 004014a0  eb4a                   -jmp 0x4014ec
    goto L_0x004014ec;
L_0x004014a2:
    // 004014a2  3d930000c0             +cmp eax, 0xc0000093
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
    // 004014a7  750c                   -jne 0x4014b5
    if (!cpu.flags.zf)
    {
        goto L_0x004014b5;
    }
    // 004014a9  c705d450400085000000   -mov dword ptr [0x4050d4], 0x85
    app->getMemory<x86::reg32>(x86::reg32(4214996) /* 0x4050d4 */) = 133 /*0x85*/;
    // 004014b3  eb37                   -jmp 0x4014ec
    goto L_0x004014ec;
L_0x004014b5:
    // 004014b5  3d8d0000c0             +cmp eax, 0xc000008d
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
    // 004014ba  750c                   -jne 0x4014c8
    if (!cpu.flags.zf)
    {
        goto L_0x004014c8;
    }
    // 004014bc  c705d450400082000000   -mov dword ptr [0x4050d4], 0x82
    app->getMemory<x86::reg32>(x86::reg32(4214996) /* 0x4050d4 */) = 130 /*0x82*/;
    // 004014c6  eb24                   -jmp 0x4014ec
    goto L_0x004014ec;
L_0x004014c8:
    // 004014c8  3d8f0000c0             +cmp eax, 0xc000008f
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
    // 004014cd  750c                   -jne 0x4014db
    if (!cpu.flags.zf)
    {
        goto L_0x004014db;
    }
    // 004014cf  c705d450400086000000   -mov dword ptr [0x4050d4], 0x86
    app->getMemory<x86::reg32>(x86::reg32(4214996) /* 0x4050d4 */) = 134 /*0x86*/;
    // 004014d9  eb11                   -jmp 0x4014ec
    goto L_0x004014ec;
L_0x004014db:
    // 004014db  3d920000c0             +cmp eax, 0xc0000092
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
    // 004014e0  750a                   -jne 0x4014ec
    if (!cpu.flags.zf)
    {
        goto L_0x004014ec;
    }
    // 004014e2  c705d45040008a000000   -mov dword ptr [0x4050d4], 0x8a
    app->getMemory<x86::reg32>(x86::reg32(4214996) /* 0x4050d4 */) = 138 /*0x8a*/;
L_0x004014ec:
    // 004014ec  ff35d4504000           -push dword ptr [0x4050d4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4214996) /* 0x4050d4 */);
    cpu.esp -= 4;
    // 004014f2  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004014f4  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004014f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004014f7  8935d4504000           -mov dword ptr [0x4050d4], esi
    app->getMemory<x86::reg32>(x86::reg32(4214996) /* 0x4050d4 */) = cpu.esi;
    // 004014fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004014fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004014ff  eb08                   -jmp 0x401509
    goto L_0x00401509;
L_0x00401501:
    // 00401501  83600800               -and dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00401505  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401506  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401508  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00401509:
    // 00401509  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0040150c  a3fc544000             -mov dword ptr [0x4054fc], eax
    app->getMemory<x86::reg32>(x86::reg32(4216060) /* 0x4054fc */) = cpu.eax;
L_0x00401511:
    // 00401511  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00401514  eb09                   -jmp 0x40151f
    goto L_0x0040151f;
L_0x00401516:
    // 00401516  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00401519  ff1554404000           -call dword ptr [0x404054]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210772) /* 0x404054 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0040151f:
    // 0040151f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401520  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401521  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401522(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401522  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00401526  8b0dd0504000           -mov ecx, dword ptr [0x4050d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4214992) /* 0x4050d0 */);
    // 0040152c  391550504000           +cmp dword ptr [0x405050], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4214864) /* 0x405050 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401532  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401533  b850504000             -mov eax, 0x405050
    cpu.eax = 4214864 /*0x405050*/;
    // 00401538  7415                   -je 0x40154f
    if (cpu.flags.zf)
    {
        goto L_0x0040154f;
    }
    // 0040153a  8d3449                 -lea esi, [ecx + ecx*2]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 0040153d  8d34b550504000         -lea esi, [esi*4 + 0x405050]
    cpu.esi = x86::reg32(x86::reg32(4214864) /* 0x405050 */ + cpu.esi * 4);
L_0x00401544:
    // 00401544  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00401547  3bc6                   +cmp eax, esi
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
    // 00401549  7304                   -jae 0x40154f
    if (!cpu.flags.cf)
    {
        goto L_0x0040154f;
    }
    // 0040154b  3910                   +cmp dword ptr [eax], edx
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
    // 0040154d  75f5                   -jne 0x401544
    if (!cpu.flags.zf)
    {
        goto L_0x00401544;
    }
L_0x0040154f:
    // 0040154f  8d0c49                 -lea ecx, [ecx + ecx*2]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.ecx * 2);
    // 00401552  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401553  8d0c8d50504000         -lea ecx, [ecx*4 + 0x405050]
    cpu.ecx = x86::reg32(x86::reg32(4214864) /* 0x405050 */ + cpu.ecx * 4);
    // 0040155a  3bc1                   +cmp eax, ecx
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
    // 0040155c  7304                   -jae 0x401562
    if (!cpu.flags.cf)
    {
        goto L_0x00401562;
    }
    // 0040155e  3910                   +cmp dword ptr [eax], edx
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
    // 00401560  7402                   -je 0x401564
    if (cpu.flags.zf)
    {
        goto L_0x00401564;
    }
L_0x00401562:
    // 00401562  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00401564:
    // 00401564  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401565(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401565  833da859400000         +cmp dword ptr [0x4059a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4217256) /* 0x4059a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040156c  7505                   -jne 0x401573
    if (!cpu.flags.zf)
    {
        goto L_0x00401573;
    }
    // 0040156e  e8cb0d0000             -call 0x40233e
    cpu.esp -= 4;
    sub_40233e(app, cpu);
L_0x00401573:
    // 00401573  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401574  8b35b8594000           -mov esi, dword ptr [0x4059b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4217272) /* 0x4059b8 */);
    // 0040157a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0040157c  3c22                   +cmp al, 0x22
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040157e  7525                   -jne 0x4015a5
    if (!cpu.flags.zf)
    {
        goto L_0x004015a5;
    }
L_0x00401580:
    // 00401580  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00401583  46                     -inc esi
    (cpu.esi)++;
    // 00401584  3c22                   +cmp al, 0x22
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00401586  7415                   -je 0x40159d
    if (cpu.flags.zf)
    {
        goto L_0x0040159d;
    }
    // 00401588  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0040158a  7411                   -je 0x40159d
    if (cpu.flags.zf)
    {
        goto L_0x0040159d;
    }
    // 0040158c  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 0040158f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401590  e8a3090000             -call 0x401f38
    cpu.esp -= 4;
    sub_401f38(app, cpu);
    // 00401595  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401597  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401598  74e6                   -je 0x401580
    if (cpu.flags.zf)
    {
        goto L_0x00401580;
    }
    // 0040159a  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040159b  ebe3                   -jmp 0x401580
    goto L_0x00401580;
L_0x0040159d:
    // 0040159d  803e22                 +cmp byte ptr [esi], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004015a0  750d                   -jne 0x4015af
    if (!cpu.flags.zf)
    {
        goto L_0x004015af;
    }
L_0x004015a2:
    // 004015a2  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004015a3  eb0a                   -jmp 0x4015af
    goto L_0x004015af;
L_0x004015a5:
    // 004015a5  3c20                   +cmp al, 0x20
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
    // 004015a7  7606                   -jbe 0x4015af
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004015af;
    }
L_0x004015a9:
    // 004015a9  46                     -inc esi
    (cpu.esi)++;
    // 004015aa  803e20                 +cmp byte ptr [esi], 0x20
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004015ad  77fa                   -ja 0x4015a9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004015a9;
    }
L_0x004015af:
    // 004015af  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004015b1  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004015b3  7404                   -je 0x4015b9
    if (cpu.flags.zf)
    {
        goto L_0x004015b9;
    }
    // 004015b5  3c20                   +cmp al, 0x20
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
    // 004015b7  76e9                   -jbe 0x4015a2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004015a2;
    }
L_0x004015b9:
    // 004015b9  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004015bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004015bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4015bd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004015bd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004015be  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004015c0  391da8594000           +cmp dword ptr [0x4059a8], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4217256) /* 0x4059a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004015c6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004015c7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004015c8  7505                   -jne 0x4015cf
    if (!cpu.flags.zf)
    {
        goto L_0x004015cf;
    }
    // 004015ca  e86f0d0000             -call 0x40233e
    cpu.esp -= 4;
    sub_40233e(app, cpu);
L_0x004015cf:
    // 004015cf  8b35a4544000           -mov esi, dword ptr [0x4054a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4215972) /* 0x4054a4 */);
    // 004015d5  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004015d7:
    // 004015d7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004015d9  3ac3                   +cmp al, bl
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
    // 004015db  7412                   -je 0x4015ef
    if (cpu.flags.zf)
    {
        goto L_0x004015ef;
    }
    // 004015dd  3c3d                   +cmp al, 0x3d
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
    // 004015df  7401                   -je 0x4015e2
    if (cpu.flags.zf)
    {
        goto L_0x004015e2;
    }
    // 004015e1  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004015e2:
    // 004015e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004015e3  e8180f0000             -call 0x402500
    cpu.esp -= 4;
    sub_402500(app, cpu);
    // 004015e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004015e9  8d740601               -lea esi, [esi + eax + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 004015ed  ebe8                   -jmp 0x4015d7
    goto L_0x004015d7;
L_0x004015ef:
    // 004015ef  8d04bd04000000         -lea eax, [edi*4 + 4]
    cpu.eax = x86::reg32(x86::reg32(4) /* 0x4 */ + cpu.edi * 4);
    // 004015f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004015f7  e8840e0000             -call 0x402480
    cpu.esp -= 4;
    sub_402480(app, cpu);
    // 004015fc  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004015fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004015ff  3bf3                   +cmp esi, ebx
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
    // 00401601  8935d8544000           -mov dword ptr [0x4054d8], esi
    app->getMemory<x86::reg32>(x86::reg32(4216024) /* 0x4054d8 */) = cpu.esi;
    // 00401607  7508                   -jne 0x401611
    if (!cpu.flags.zf)
    {
        goto L_0x00401611;
    }
    // 00401609  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0040160b  e886fcffff             -call 0x401296
    cpu.esp -= 4;
    sub_401296(app, cpu);
    // 00401610  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00401611:
    // 00401611  8b3da4544000           -mov edi, dword ptr [0x4054a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4215972) /* 0x4054a4 */);
    // 00401617  381f                   +cmp byte ptr [edi], bl
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
    // 00401619  7439                   -je 0x401654
    if (cpu.flags.zf)
    {
        goto L_0x00401654;
    }
    // 0040161b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0040161c:
    // 0040161c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040161d  e8de0e0000             -call 0x402500
    cpu.esp -= 4;
    sub_402500(app, cpu);
    // 00401622  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00401624  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401625  45                     -inc ebp
    (cpu.ebp)++;
    // 00401626  803f3d                 +cmp byte ptr [edi], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00401629  7422                   -je 0x40164d
    if (cpu.flags.zf)
    {
        goto L_0x0040164d;
    }
    // 0040162b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040162c  e84f0e0000             -call 0x402480
    cpu.esp -= 4;
    sub_402480(app, cpu);
    // 00401631  3bc3                   +cmp eax, ebx
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
    // 00401633  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401634  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00401636  7508                   -jne 0x401640
    if (!cpu.flags.zf)
    {
        goto L_0x00401640;
    }
    // 00401638  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0040163a  e857fcffff             -call 0x401296
    cpu.esp -= 4;
    sub_401296(app, cpu);
    // 0040163f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00401640:
    // 00401640  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401641  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 00401643  e8480d0000             -call 0x402390
    cpu.esp -= 4;
    sub_402390(app, cpu);
    // 00401648  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401649  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040164c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040164d:
    // 0040164d  03fd                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0040164f  381f                   +cmp byte ptr [edi], bl
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
    // 00401651  75c9                   -jne 0x40161c
    if (!cpu.flags.zf)
    {
        goto L_0x0040161c;
    }
    // 00401653  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00401654:
    // 00401654  ff35a4544000           -push dword ptr [0x4054a4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4215972) /* 0x4054a4 */);
    cpu.esp -= 4;
    // 0040165a  e8fb0c0000             -call 0x40235a
    cpu.esp -= 4;
    sub_40235a(app, cpu);
    // 0040165f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401660  891da4544000           -mov dword ptr [0x4054a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(4215972) /* 0x4054a4 */) = cpu.ebx;
    // 00401666  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00401668  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401669  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040166a  c705a459400001000000   -mov dword ptr [0x4059a4], 1
    app->getMemory<x86::reg32>(x86::reg32(4217252) /* 0x4059a4 */) = 1 /*0x1*/;
    // 00401674  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401675  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401676(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401676  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401677  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401679  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040167a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040167b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040167c  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040167e  391da8594000           +cmp dword ptr [0x4059a8], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4217256) /* 0x4059a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401684  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401685  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401686  7505                   -jne 0x40168d
    if (!cpu.flags.zf)
    {
        goto L_0x0040168d;
    }
    // 00401688  e8b10c0000             -call 0x40233e
    cpu.esp -= 4;
    sub_40233e(app, cpu);
L_0x0040168d:
    // 0040168d  be00554000             -mov esi, 0x405500
    cpu.esi = 4216064 /*0x405500*/;
    // 00401692  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00401697  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401698  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401699  ff1558404000           -call dword ptr [0x404058]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210776) /* 0x404058 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040169f  a1b8594000             -mov eax, dword ptr [0x4059b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4217272) /* 0x4059b8 */);
    // 004016a4  8935e8544000           -mov dword ptr [0x4054e8], esi
    app->getMemory<x86::reg32>(x86::reg32(4216040) /* 0x4054e8 */) = cpu.esi;
    // 004016aa  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004016ac  3818                   +cmp byte ptr [eax], bl
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
    // 004016ae  7402                   -je 0x4016b2
    if (cpu.flags.zf)
    {
        goto L_0x004016b2;
    }
    // 004016b0  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004016b2:
    // 004016b2  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004016b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004016b6  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004016b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004016ba  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004016bb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004016bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004016bd  e84d000000             -call 0x40170f
    cpu.esp -= 4;
    sub_40170f(app, cpu);
    // 004016c2  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004016c5  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004016c8  8d0488                 -lea eax, [eax + ecx*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.ecx * 4);
    // 004016cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004016cc  e8af0d0000             -call 0x402480
    cpu.esp -= 4;
    sub_402480(app, cpu);
    // 004016d1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004016d3  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004016d6  3bf3                   +cmp esi, ebx
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
    // 004016d8  7508                   -jne 0x4016e2
    if (!cpu.flags.zf)
    {
        goto L_0x004016e2;
    }
    // 004016da  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004016dc  e8b5fbffff             -call 0x401296
    cpu.esp -= 4;
    sub_401296(app, cpu);
    // 004016e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004016e2:
    // 004016e2  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004016e5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004016e6  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004016e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004016ea  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004016ed  8d0486                 -lea eax, [esi + eax*4]
    cpu.eax = x86::reg32(cpu.esi + cpu.eax * 4);
    // 004016f0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004016f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004016f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004016f3  e817000000             -call 0x40170f
    cpu.esp -= 4;
    sub_40170f(app, cpu);
    // 004016f8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004016fb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004016fe  48                     -dec eax
    (cpu.eax)--;
    // 004016ff  8935d0544000           -mov dword ptr [0x4054d0], esi
    app->getMemory<x86::reg32>(x86::reg32(4216016) /* 0x4054d0 */) = cpu.esi;
    // 00401705  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401706  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401707  a3cc544000             -mov dword ptr [0x4054cc], eax
    app->getMemory<x86::reg32>(x86::reg32(4216012) /* 0x4054cc */) = cpu.eax;
    // 0040170c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040170d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040170e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40170f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040170f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401710  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401712  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00401715  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00401718  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401719  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040171a  832100                 -and dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0040171d  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00401720  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401721  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00401724  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 0040172a  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0040172d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0040172f  7408                   -je 0x401739
    if (cpu.flags.zf)
    {
        goto L_0x00401739;
    }
    // 00401731  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 00401733  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401736  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x00401739:
    // 00401739  803822                 +cmp byte ptr [eax], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040173c  7544                   -jne 0x401782
    if (!cpu.flags.zf)
    {
        goto L_0x00401782;
    }
L_0x0040173e:
    // 0040173e  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00401741  40                     -inc eax
    (cpu.eax)++;
    // 00401742  80fa22                 +cmp dl, 0x22
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00401745  7429                   -je 0x401770
    if (cpu.flags.zf)
    {
        goto L_0x00401770;
    }
    // 00401747  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00401749  7425                   -je 0x401770
    if (cpu.flags.zf)
    {
        goto L_0x00401770;
    }
    // 0040174b  0fb6d2                 -movzx edx, dl
    cpu.edx = x86::reg32(cpu.dl);
    // 0040174e  f6828157400004         +test byte ptr [edx + 0x405781], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4216705) /* 0x405781 */) & 4 /*0x4*/));
    // 00401755  740c                   -je 0x401763
    if (cpu.flags.zf)
    {
        goto L_0x00401763;
    }
    // 00401757  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 00401759  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040175b  7406                   -je 0x401763
    if (cpu.flags.zf)
    {
        goto L_0x00401763;
    }
    // 0040175d  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0040175f  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 00401761  46                     -inc esi
    (cpu.esi)++;
    // 00401762  40                     -inc eax
    (cpu.eax)++;
L_0x00401763:
    // 00401763  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 00401765  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00401767  74d5                   -je 0x40173e
    if (cpu.flags.zf)
    {
        goto L_0x0040173e;
    }
    // 00401769  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0040176b  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 0040176d  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040176e  ebce                   -jmp 0x40173e
    goto L_0x0040173e;
L_0x00401770:
    // 00401770  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 00401772  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00401774  7404                   -je 0x40177a
    if (cpu.flags.zf)
    {
        goto L_0x0040177a;
    }
    // 00401776  802600                 -and byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00401779  46                     -inc esi
    (cpu.esi)++;
L_0x0040177a:
    // 0040177a  803822                 +cmp byte ptr [eax], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040177d  7546                   -jne 0x4017c5
    if (!cpu.flags.zf)
    {
        goto L_0x004017c5;
    }
    // 0040177f  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00401780  eb43                   -jmp 0x4017c5
    goto L_0x004017c5;
L_0x00401782:
    // 00401782  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 00401784  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00401786  7405                   -je 0x40178d
    if (cpu.flags.zf)
    {
        goto L_0x0040178d;
    }
    // 00401788  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0040178a  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 0040178c  46                     -inc esi
    (cpu.esi)++;
L_0x0040178d:
    // 0040178d  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0040178f  40                     -inc eax
    (cpu.eax)++;
    // 00401790  0fb6da                 -movzx ebx, dl
    cpu.ebx = x86::reg32(cpu.dl);
    // 00401793  f6838157400004         +test byte ptr [ebx + 0x405781], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4216705) /* 0x405781 */) & 4 /*0x4*/));
    // 0040179a  740c                   -je 0x4017a8
    if (cpu.flags.zf)
    {
        goto L_0x004017a8;
    }
    // 0040179c  ff01                   -inc dword ptr [ecx]
    (app->getMemory<x86::reg32>(cpu.ecx))++;
    // 0040179e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004017a0  7405                   -je 0x4017a7
    if (cpu.flags.zf)
    {
        goto L_0x004017a7;
    }
    // 004017a2  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004017a4  881e                   -mov byte ptr [esi], bl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.bl;
    // 004017a6  46                     -inc esi
    (cpu.esi)++;
L_0x004017a7:
    // 004017a7  40                     -inc eax
    (cpu.eax)++;
L_0x004017a8:
    // 004017a8  80fa20                 +cmp dl, 0x20
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
    // 004017ab  7409                   -je 0x4017b6
    if (cpu.flags.zf)
    {
        goto L_0x004017b6;
    }
    // 004017ad  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004017af  7409                   -je 0x4017ba
    if (cpu.flags.zf)
    {
        goto L_0x004017ba;
    }
    // 004017b1  80fa09                 +cmp dl, 9
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
    // 004017b4  75cc                   -jne 0x401782
    if (!cpu.flags.zf)
    {
        goto L_0x00401782;
    }
L_0x004017b6:
    // 004017b6  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004017b8  7503                   -jne 0x4017bd
    if (!cpu.flags.zf)
    {
        goto L_0x004017bd;
    }
L_0x004017ba:
    // 004017ba  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004017bb  eb08                   -jmp 0x4017c5
    goto L_0x004017c5;
L_0x004017bd:
    // 004017bd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004017bf  7404                   -je 0x4017c5
    if (cpu.flags.zf)
    {
        goto L_0x004017c5;
    }
    // 004017c1  8066ff00               -and byte ptr [esi - 1], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x004017c5:
    // 004017c5  83651800               -and dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x004017c9:
    // 004017c9  803800                 +cmp byte ptr [eax], 0
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
    // 004017cc  0f84e0000000           -je 0x4018b2
    if (cpu.flags.zf)
    {
        goto L_0x004018b2;
    }
L_0x004017d2:
    // 004017d2  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004017d4  80fa20                 +cmp dl, 0x20
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
    // 004017d7  7405                   -je 0x4017de
    if (cpu.flags.zf)
    {
        goto L_0x004017de;
    }
    // 004017d9  80fa09                 +cmp dl, 9
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
    // 004017dc  7503                   -jne 0x4017e1
    if (!cpu.flags.zf)
    {
        goto L_0x004017e1;
    }
L_0x004017de:
    // 004017de  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004017df  ebf1                   -jmp 0x4017d2
    goto L_0x004017d2;
L_0x004017e1:
    // 004017e1  803800                 +cmp byte ptr [eax], 0
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
    // 004017e4  0f84c8000000           -je 0x4018b2
    if (cpu.flags.zf)
    {
        goto L_0x004018b2;
    }
    // 004017ea  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004017ec  7408                   -je 0x4017f6
    if (cpu.flags.zf)
    {
        goto L_0x004017f6;
    }
    // 004017ee  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 004017f0  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004017f3  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x004017f6:
    // 004017f6  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004017f9  ff02                   -inc dword ptr [edx]
    (app->getMemory<x86::reg32>(cpu.edx))++;
L_0x004017fb:
    // 004017fb  c7450801000000         -mov dword ptr [ebp + 8], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 00401802  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00401804:
    // 00401804  80385c                 +cmp byte ptr [eax], 0x5c
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
    // 00401807  7504                   -jne 0x40180d
    if (!cpu.flags.zf)
    {
        goto L_0x0040180d;
    }
    // 00401809  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040180a  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040180b  ebf7                   -jmp 0x401804
    goto L_0x00401804;
L_0x0040180d:
    // 0040180d  803822                 +cmp byte ptr [eax], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00401810  752c                   -jne 0x40183e
    if (!cpu.flags.zf)
    {
        goto L_0x0040183e;
    }
    // 00401812  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00401815  7525                   -jne 0x40183c
    if (!cpu.flags.zf)
    {
        goto L_0x0040183c;
    }
    // 00401817  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00401819  397d18                 +cmp dword ptr [ebp + 0x18], edi
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
    // 0040181c  740d                   -je 0x40182b
    if (cpu.flags.zf)
    {
        goto L_0x0040182b;
    }
    // 0040181e  80780122               +cmp byte ptr [eax + 1], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00401822  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00401825  7504                   -jne 0x40182b
    if (!cpu.flags.zf)
    {
        goto L_0x0040182b;
    }
    // 00401827  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00401829  eb03                   -jmp 0x40182e
    goto L_0x0040182e;
L_0x0040182b:
    // 0040182b  897d08                 -mov dword ptr [ebp + 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edi;
L_0x0040182e:
    // 0040182e  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00401831  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00401833  395518                 +cmp dword ptr [ebp + 0x18], edx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401836  0f94c2                 -sete dl
    cpu.dl = cpu.flags.zf;
    // 00401839  895518                 -mov dword ptr [ebp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x0040183c:
    // 0040183c  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
L_0x0040183e:
    // 0040183e  8bd3                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00401840  4b                     -dec ebx
    (cpu.ebx)--;
    // 00401841  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00401843  740e                   -je 0x401853
    if (cpu.flags.zf)
    {
        goto L_0x00401853;
    }
    // 00401845  43                     -inc ebx
    (cpu.ebx)++;
L_0x00401846:
    // 00401846  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00401848  7404                   -je 0x40184e
    if (cpu.flags.zf)
    {
        goto L_0x0040184e;
    }
    // 0040184a  c6065c                 -mov byte ptr [esi], 0x5c
    app->getMemory<x86::reg8>(cpu.esi) = 92 /*0x5c*/;
    // 0040184d  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0040184e:
    // 0040184e  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00401850  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00401851  75f3                   -jne 0x401846
    if (!cpu.flags.zf)
    {
        goto L_0x00401846;
    }
L_0x00401853:
    // 00401853  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00401855  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00401857  744a                   -je 0x4018a3
    if (cpu.flags.zf)
    {
        goto L_0x004018a3;
    }
    // 00401859  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040185d  750a                   -jne 0x401869
    if (!cpu.flags.zf)
    {
        goto L_0x00401869;
    }
    // 0040185f  80fa20                 +cmp dl, 0x20
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
    // 00401862  743f                   -je 0x4018a3
    if (cpu.flags.zf)
    {
        goto L_0x004018a3;
    }
    // 00401864  80fa09                 +cmp dl, 9
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
    // 00401867  743a                   -je 0x4018a3
    if (cpu.flags.zf)
    {
        goto L_0x004018a3;
    }
L_0x00401869:
    // 00401869  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 0040186d  742e                   -je 0x40189d
    if (cpu.flags.zf)
    {
        goto L_0x0040189d;
    }
    // 0040186f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00401871  7419                   -je 0x40188c
    if (cpu.flags.zf)
    {
        goto L_0x0040188c;
    }
    // 00401873  0fb6da                 -movzx ebx, dl
    cpu.ebx = x86::reg32(cpu.dl);
    // 00401876  f6838157400004         +test byte ptr [ebx + 0x405781], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4216705) /* 0x405781 */) & 4 /*0x4*/));
    // 0040187d  7406                   -je 0x401885
    if (cpu.flags.zf)
    {
        goto L_0x00401885;
    }
    // 0040187f  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 00401881  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00401882  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00401883  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x00401885:
    // 00401885  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00401887  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 00401889  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040188a  eb0f                   -jmp 0x40189b
    goto L_0x0040189b;
L_0x0040188c:
    // 0040188c  0fb6d2                 -movzx edx, dl
    cpu.edx = x86::reg32(cpu.dl);
    // 0040188f  f6828157400004         +test byte ptr [edx + 0x405781], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4216705) /* 0x405781 */) & 4 /*0x4*/));
    // 00401896  7403                   -je 0x40189b
    if (cpu.flags.zf)
    {
        goto L_0x0040189b;
    }
    // 00401898  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00401899  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0040189b:
    // 0040189b  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0040189d:
    // 0040189d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040189e  e958ffffff             -jmp 0x4017fb
    goto L_0x004017fb;
L_0x004018a3:
    // 004018a3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004018a5  7404                   -je 0x4018ab
    if (cpu.flags.zf)
    {
        goto L_0x004018ab;
    }
    // 004018a7  802600                 +and byte ptr [esi], 0
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi) &= x86::reg8(x86::sreg8(0 /*0x0*/))));
    // 004018aa  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004018ab:
    // 004018ab  ff01                   +inc dword ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004018ad  e917ffffff             -jmp 0x4017c9
    goto L_0x004017c9;
L_0x004018b2:
    // 004018b2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004018b4  7403                   -je 0x4018b9
    if (cpu.flags.zf)
    {
        goto L_0x004018b9;
    }
    // 004018b6  832700                 -and dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x004018b9:
    // 004018b9  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004018bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004018bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004018be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004018bf  ff00                   -inc dword ptr [eax]
    (app->getMemory<x86::reg32>(cpu.eax))++;
    // 004018c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004018c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4018c3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004018c3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004018c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004018c5  a104564000             -mov eax, dword ptr [0x405604]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216324) /* 0x405604 */);
    // 004018ca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004018cb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004018cc  8b2d14404000           -mov ebp, dword ptr [0x404014]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4210708) /* 0x404014 */);
    // 004018d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004018d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004018d4  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004018d6  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004018d8  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004018da  3bc3                   +cmp eax, ebx
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
    // 004018dc  7533                   -jne 0x401911
    if (!cpu.flags.zf)
    {
        goto L_0x00401911;
    }
    // 004018de  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004018e0  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004018e2  3bf3                   +cmp esi, ebx
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
    // 004018e4  740c                   -je 0x4018f2
    if (cpu.flags.zf)
    {
        goto L_0x004018f2;
    }
    // 004018e6  c7050456400001000000   -mov dword ptr [0x405604], 1
    app->getMemory<x86::reg32>(x86::reg32(4216324) /* 0x405604 */) = 1 /*0x1*/;
    // 004018f0  eb28                   -jmp 0x40191a
    goto L_0x0040191a;
L_0x004018f2:
    // 004018f2  ff1568404000           -call dword ptr [0x404068]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210792) /* 0x404068 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004018f8  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004018fa  3bfb                   +cmp edi, ebx
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
    // 004018fc  0f84ea000000           -je 0x4019ec
    if (cpu.flags.zf)
    {
        goto L_0x004019ec;
    }
    // 00401902  c7050456400002000000   -mov dword ptr [0x405604], 2
    app->getMemory<x86::reg32>(x86::reg32(4216324) /* 0x405604 */) = 2 /*0x2*/;
    // 0040190c  e98f000000             -jmp 0x4019a0
    goto L_0x004019a0;
L_0x00401911:
    // 00401911  83f801                 +cmp eax, 1
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
    // 00401914  0f8581000000           -jne 0x40199b
    if (!cpu.flags.zf)
    {
        goto L_0x0040199b;
    }
L_0x0040191a:
    // 0040191a  3bf3                   +cmp esi, ebx
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
    // 0040191c  750c                   -jne 0x40192a
    if (!cpu.flags.zf)
    {
        goto L_0x0040192a;
    }
    // 0040191e  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401920  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00401922  3bf3                   +cmp esi, ebx
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
    // 00401924  0f84c2000000           -je 0x4019ec
    if (cpu.flags.zf)
    {
        goto L_0x004019ec;
    }
L_0x0040192a:
    // 0040192a  66391e                 +cmp word ptr [esi], bx
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040192d  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040192f  740e                   -je 0x40193f
    if (cpu.flags.zf)
    {
        goto L_0x0040193f;
    }
L_0x00401931:
    // 00401931  40                     -inc eax
    (cpu.eax)++;
    // 00401932  40                     -inc eax
    (cpu.eax)++;
    // 00401933  663918                 +cmp word ptr [eax], bx
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00401936  75f9                   -jne 0x401931
    if (!cpu.flags.zf)
    {
        goto L_0x00401931;
    }
    // 00401938  40                     -inc eax
    (cpu.eax)++;
    // 00401939  40                     -inc eax
    (cpu.eax)++;
    // 0040193a  663918                 +cmp word ptr [eax], bx
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040193d  75f2                   -jne 0x401931
    if (!cpu.flags.zf)
    {
        goto L_0x00401931;
    }
L_0x0040193f:
    // 0040193f  2bc6                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00401941  8b3d64404000           -mov edi, dword ptr [0x404064]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4210788) /* 0x404064 */);
    // 00401947  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00401949  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040194a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040194b  40                     -inc eax
    (cpu.eax)++;
    // 0040194c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040194d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040194e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040194f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401950  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401951  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401952  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00401956  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401958  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0040195a  3beb                   +cmp ebp, ebx
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
    // 0040195c  7432                   -je 0x401990
    if (cpu.flags.zf)
    {
        goto L_0x00401990;
    }
    // 0040195e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040195f  e81c0b0000             -call 0x402480
    cpu.esp -= 4;
    sub_402480(app, cpu);
    // 00401964  3bc3                   +cmp eax, ebx
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
    // 00401966  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401967  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0040196b  7423                   -je 0x401990
    if (cpu.flags.zf)
    {
        goto L_0x00401990;
    }
    // 0040196d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040196e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040196f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401970  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401971  ff742424               -push dword ptr [esp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00401975  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401976  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401977  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401978  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040197a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040197c  750e                   -jne 0x40198c
    if (!cpu.flags.zf)
    {
        goto L_0x0040198c;
    }
    // 0040197e  ff742410               -push dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00401982  e8d3090000             -call 0x40235a
    cpu.esp -= 4;
    sub_40235a(app, cpu);
    // 00401987  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401988  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
L_0x0040198c:
    // 0040198c  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x00401990:
    // 00401990  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401991  ff1510404000           -call dword ptr [0x404010]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210704) /* 0x404010 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401997  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00401999  eb53                   -jmp 0x4019ee
    goto L_0x004019ee;
L_0x0040199b:
    // 0040199b  83f802                 +cmp eax, 2
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
    // 0040199e  754c                   -jne 0x4019ec
    if (!cpu.flags.zf)
    {
        goto L_0x004019ec;
    }
L_0x004019a0:
    // 004019a0  3bfb                   +cmp edi, ebx
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
    // 004019a2  750c                   -jne 0x4019b0
    if (!cpu.flags.zf)
    {
        goto L_0x004019b0;
    }
    // 004019a4  ff1568404000           -call dword ptr [0x404068]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210792) /* 0x404068 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004019aa  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004019ac  3bfb                   +cmp edi, ebx
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
    // 004019ae  743c                   -je 0x4019ec
    if (cpu.flags.zf)
    {
        goto L_0x004019ec;
    }
L_0x004019b0:
    // 004019b0  381f                   +cmp byte ptr [edi], bl
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
    // 004019b2  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004019b4  740a                   -je 0x4019c0
    if (cpu.flags.zf)
    {
        goto L_0x004019c0;
    }
L_0x004019b6:
    // 004019b6  40                     -inc eax
    (cpu.eax)++;
    // 004019b7  3818                   +cmp byte ptr [eax], bl
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
    // 004019b9  75fb                   -jne 0x4019b6
    if (!cpu.flags.zf)
    {
        goto L_0x004019b6;
    }
    // 004019bb  40                     -inc eax
    (cpu.eax)++;
    // 004019bc  3818                   +cmp byte ptr [eax], bl
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
    // 004019be  75f6                   -jne 0x4019b6
    if (!cpu.flags.zf)
    {
        goto L_0x004019b6;
    }
L_0x004019c0:
    // 004019c0  2bc7                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004019c2  40                     -inc eax
    (cpu.eax)++;
    // 004019c3  8be8                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004019c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004019c6  e8b50a0000             -call 0x402480
    cpu.esp -= 4;
    sub_402480(app, cpu);
    // 004019cb  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004019cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004019ce  3bf3                   +cmp esi, ebx
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
    // 004019d0  7504                   -jne 0x4019d6
    if (!cpu.flags.zf)
    {
        goto L_0x004019d6;
    }
    // 004019d2  33f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004019d4  eb0b                   -jmp 0x4019e1
    goto L_0x004019e1;
L_0x004019d6:
    // 004019d6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004019d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004019d8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004019d9  e8a20b0000             -call 0x402580
    cpu.esp -= 4;
    sub_402580(app, cpu);
    // 004019de  83c40c                 +add esp, 0xc
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
L_0x004019e1:
    // 004019e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004019e2  ff155c404000           -call dword ptr [0x40405c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210780) /* 0x40405c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004019e8  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004019ea  eb02                   -jmp 0x4019ee
    goto L_0x004019ee;
L_0x004019ec:
    // 004019ec  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004019ee:
    // 004019ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004019ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004019f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004019f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004019f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004019f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004019f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4019f5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004019f5  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004019f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004019f9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004019fa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004019fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004019fc  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00401a01  e87a0a0000             -call 0x402480
    cpu.esp -= 4;
    sub_402480(app, cpu);
    // 00401a06  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00401a08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a09  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00401a0b  7508                   -jne 0x401a15
    if (!cpu.flags.zf)
    {
        goto L_0x00401a15;
    }
    // 00401a0d  6a1b                   -push 0x1b
    app->getMemory<x86::reg32>(cpu.esp-4) = 27 /*0x1b*/;
    cpu.esp -= 4;
    // 00401a0f  e882f8ffff             -call 0x401296
    cpu.esp -= 4;
    sub_401296(app, cpu);
    // 00401a14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00401a15:
    // 00401a15  8935a0584000           -mov dword ptr [0x4058a0], esi
    app->getMemory<x86::reg32>(x86::reg32(4216992) /* 0x4058a0 */) = cpu.esi;
    // 00401a1b  c705a059400020000000   -mov dword ptr [0x4059a0], 0x20
    app->getMemory<x86::reg32>(x86::reg32(4217248) /* 0x4059a0 */) = 32 /*0x20*/;
    // 00401a25  8d8600010000           -lea eax, [esi + 0x100]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(256) /* 0x100 */);
L_0x00401a2b:
    // 00401a2b  3bf0                   +cmp esi, eax
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
    // 00401a2d  731a                   -jae 0x401a49
    if (!cpu.flags.cf)
    {
        goto L_0x00401a49;
    }
    // 00401a2f  80660400               -and byte ptr [esi + 4], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00401a33  830eff                 -or dword ptr [esi], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00401a36  c646050a               -mov byte ptr [esi + 5], 0xa
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = 10 /*0xa*/;
    // 00401a3a  a1a0584000             -mov eax, dword ptr [0x4058a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216992) /* 0x4058a0 */);
    // 00401a3f  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00401a42  0500010000             +add eax, 0x100
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
    // 00401a47  ebe2                   -jmp 0x401a2b
    goto L_0x00401a2b;
L_0x00401a49:
    // 00401a49  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00401a4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401a4e  ff1540404000           -call dword ptr [0x404040]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210752) /* 0x404040 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401a54  66837c244200           +cmp word ptr [esp + 0x42], 0
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
    // 00401a5a  0f84c5000000           -je 0x401b25
    if (cpu.flags.zf)
    {
        goto L_0x00401b25;
    }
    // 00401a60  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00401a64  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401a66  0f84b9000000           -je 0x401b25
    if (cpu.flags.zf)
    {
        goto L_0x00401b25;
    }
    // 00401a6c  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00401a6e  8d6804                 -lea ebp, [eax + 4]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00401a71  b800080000             -mov eax, 0x800
    cpu.eax = 2048 /*0x800*/;
    // 00401a76  3bf0                   +cmp esi, eax
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
    // 00401a78  8d1c2e                 -lea ebx, [esi + ebp]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 00401a7b  7c02                   -jl 0x401a7f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401a7f;
    }
    // 00401a7d  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00401a7f:
    // 00401a7f  3935a0594000           +cmp dword ptr [0x4059a0], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4217248) /* 0x4059a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401a85  7d52                   -jge 0x401ad9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00401ad9;
    }
    // 00401a87  bfa4584000             -mov edi, 0x4058a4
    cpu.edi = 4216996 /*0x4058a4*/;
L_0x00401a8c:
    // 00401a8c  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00401a91  e8ea090000             -call 0x402480
    cpu.esp -= 4;
    sub_402480(app, cpu);
    // 00401a96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401a98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a99  7438                   -je 0x401ad3
    if (cpu.flags.zf)
    {
        goto L_0x00401ad3;
    }
    // 00401a9b  8305a059400020         -add dword ptr [0x4059a0], 0x20
    (app->getMemory<x86::reg32>(x86::reg32(4217248) /* 0x4059a0 */)) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00401aa2  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00401aa4  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
L_0x00401aaa:
    // 00401aaa  3bc1                   +cmp eax, ecx
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
    // 00401aac  7318                   -jae 0x401ac6
    if (!cpu.flags.cf)
    {
        goto L_0x00401ac6;
    }
    // 00401aae  80600400               -and byte ptr [eax + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00401ab2  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00401ab5  c640050a               -mov byte ptr [eax + 5], 0xa
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = 10 /*0xa*/;
    // 00401ab9  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00401abb  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00401abe  81c100010000           +add ecx, 0x100
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
    // 00401ac4  ebe4                   -jmp 0x401aaa
    goto L_0x00401aaa;
L_0x00401ac6:
    // 00401ac6  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401ac9  3935a0594000           +cmp dword ptr [0x4059a0], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4217248) /* 0x4059a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401acf  7cbb                   -jl 0x401a8c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401a8c;
    }
    // 00401ad1  eb06                   -jmp 0x401ad9
    goto L_0x00401ad9;
L_0x00401ad3:
    // 00401ad3  8b35a0594000           -mov esi, dword ptr [0x4059a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4217248) /* 0x4059a0 */);
L_0x00401ad9:
    // 00401ad9  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00401adb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00401add  7e46                   -jle 0x401b25
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401b25;
    }
L_0x00401adf:
    // 00401adf  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00401ae1  83f8ff                 +cmp eax, -1
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
    // 00401ae4  7436                   -je 0x401b1c
    if (cpu.flags.zf)
    {
        goto L_0x00401b1c;
    }
    // 00401ae6  8a4d00                 -mov cl, byte ptr [ebp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00401ae9  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00401aec  742e                   -je 0x401b1c
    if (cpu.flags.zf)
    {
        goto L_0x00401b1c;
    }
    // 00401aee  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00401af1  750b                   -jne 0x401afe
    if (!cpu.flags.zf)
    {
        goto L_0x00401afe;
    }
    // 00401af3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401af4  ff1578404000           -call dword ptr [0x404078]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210808) /* 0x404078 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401afa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401afc  741e                   -je 0x401b1c
    if (cpu.flags.zf)
    {
        goto L_0x00401b1c;
    }
L_0x00401afe:
    // 00401afe  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00401b00  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00401b02  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00401b05  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00401b08  8b0485a0584000         -mov eax, dword ptr [eax*4 + 0x4058a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216992) /* 0x4058a0 */ + cpu.eax * 4);
    // 00401b0f  8d04c8                 -lea eax, [eax + ecx*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.ecx * 8);
    // 00401b12  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00401b14  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00401b16  8a4d00                 -mov cl, byte ptr [ebp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00401b19  884804                 -mov byte ptr [eax + 4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.cl;
L_0x00401b1c:
    // 00401b1c  47                     -inc edi
    (cpu.edi)++;
    // 00401b1d  45                     -inc ebp
    (cpu.ebp)++;
    // 00401b1e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401b21  3bfe                   +cmp edi, esi
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
    // 00401b23  7cba                   -jl 0x401adf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401adf;
    }
L_0x00401b25:
    // 00401b25  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00401b27:
    // 00401b27  a1a0584000             -mov eax, dword ptr [0x4058a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216992) /* 0x4058a0 */);
    // 00401b2c  833cd8ff               +cmp dword ptr [eax + ebx*8], -1
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
    // 00401b30  8d34d8                 -lea esi, [eax + ebx*8]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 8);
    // 00401b33  754d                   -jne 0x401b82
    if (!cpu.flags.zf)
    {
        goto L_0x00401b82;
    }
    // 00401b35  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00401b37  c6460481               -mov byte ptr [esi + 4], 0x81
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 129 /*0x81*/;
    // 00401b3b  7505                   -jne 0x401b42
    if (!cpu.flags.zf)
    {
        goto L_0x00401b42;
    }
    // 00401b3d  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 00401b3f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401b40  eb0a                   -jmp 0x401b4c
    goto L_0x00401b4c;
L_0x00401b42:
    // 00401b42  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00401b44  48                     -dec eax
    (cpu.eax)--;
    // 00401b45  f7d8                   +neg eax
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
    // 00401b47  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00401b49  83c0f5                 -add eax, -0xb
    (cpu.eax) += x86::reg32(x86::sreg32(-11 /*-0xb*/));
L_0x00401b4c:
    // 00401b4c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401b4d  ff1574404000           -call dword ptr [0x404074]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210804) /* 0x404074 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401b53  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00401b55  83ffff                 +cmp edi, -1
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
    // 00401b58  7417                   -je 0x401b71
    if (cpu.flags.zf)
    {
        goto L_0x00401b71;
    }
    // 00401b5a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401b5b  ff1578404000           -call dword ptr [0x404078]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210808) /* 0x404078 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401b61  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401b63  740c                   -je 0x401b71
    if (cpu.flags.zf)
    {
        goto L_0x00401b71;
    }
    // 00401b65  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00401b6a  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00401b6c  83f802                 +cmp eax, 2
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
    // 00401b6f  7506                   -jne 0x401b77
    if (!cpu.flags.zf)
    {
        goto L_0x00401b77;
    }
L_0x00401b71:
    // 00401b71  804e0440               +or byte ptr [esi + 4], 0x40
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 00401b75  eb0f                   -jmp 0x401b86
    goto L_0x00401b86;
L_0x00401b77:
    // 00401b77  83f803                 +cmp eax, 3
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
    // 00401b7a  750a                   -jne 0x401b86
    if (!cpu.flags.zf)
    {
        goto L_0x00401b86;
    }
    // 00401b7c  804e0408               +or byte ptr [esi + 4], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00401b80  eb04                   -jmp 0x401b86
    goto L_0x00401b86;
L_0x00401b82:
    // 00401b82  804e0480               -or byte ptr [esi + 4], 0x80
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x00401b86:
    // 00401b86  43                     -inc ebx
    (cpu.ebx)++;
    // 00401b87  83fb03                 +cmp ebx, 3
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
    // 00401b8a  7c9b                   -jl 0x401b27
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401b27;
    }
    // 00401b8c  ff35a0594000           -push dword ptr [0x4059a0]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4217248) /* 0x4059a0 */);
    cpu.esp -= 4;
    // 00401b92  ff1518404000           -call dword ptr [0x404018]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210712) /* 0x404018 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401b98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401b99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401b9a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401b9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401b9c  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00401b9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401ba0  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401ba2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401ba4  39442408               +cmp dword ptr [esp + 8], eax
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
    // 00401ba8  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 00401bad  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00401bb0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401bb1  ff1580404000           -call dword ptr [0x404080]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210816) /* 0x404080 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401bb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401bb9  a388584000             -mov dword ptr [0x405888], eax
    app->getMemory<x86::reg32>(x86::reg32(4216968) /* 0x405888 */) = cpu.eax;
    // 00401bbe  7415                   -je 0x401bd5
    if (cpu.flags.zf)
    {
        goto L_0x00401bd5;
    }
    // 00401bc0  e8f00c0000             -call 0x4028b5
    cpu.esp -= 4;
    sub_4028b5(app, cpu);
    // 00401bc5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401bc7  750f                   -jne 0x401bd8
    if (!cpu.flags.zf)
    {
        goto L_0x00401bd8;
    }
    // 00401bc9  ff3588584000           -push dword ptr [0x405888]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216968) /* 0x405888 */);
    cpu.esp -= 4;
    // 00401bcf  ff157c404000           -call dword ptr [0x40407c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210812) /* 0x40407c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00401bd5:
    // 00401bd5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401bd7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401bd8:
    // 00401bd8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401bda  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401bdb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401bdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401bdc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401bdd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401bdf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401be0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401be1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401be2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401be3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401be5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401be7  68f41b4000             -push 0x401bf4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4201460 /*0x401bf4*/;
    cpu.esp -= 4;
    // 00401bec  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00401bef  e8241e0000             -call 0x403a18
    cpu.esp -= 4;
    sub_403a18(app, cpu);
    // 00401bf4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401bf5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401bf6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401bf7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401bf8  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00401bfa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401bfb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401bfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401bfc  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00401c00  f7410406000000         +test dword ptr [ecx + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 00401c07  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00401c0c  740f                   -je 0x401c1d
    if (cpu.flags.zf)
    {
        goto L_0x00401c1d;
    }
    // 00401c0e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00401c12  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00401c16  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00401c18  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x00401c1d:
    // 00401c1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401c1e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401c1e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401c1f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401c20  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401c21  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00401c25  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401c26  6afe                   -push -2
    app->getMemory<x86::reg32>(cpu.esp-4) = -2 /*-0x2*/;
    cpu.esp -= 4;
    // 00401c28  68fc1b4000             -push 0x401bfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4201468 /*0x401bfc*/;
    cpu.esp -= 4;
    // 00401c2d  64ff3500000000         -push dword ptr fs:[0]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.efs);
    cpu.esp -= 4;
    // 00401c34  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
L_0x00401c3b:
    // 00401c3b  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00401c3f  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00401c42  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00401c45  83feff                 +cmp esi, -1
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
    // 00401c48  742e                   -je 0x401c78
    if (cpu.flags.zf)
    {
        goto L_0x00401c78;
    }
    // 00401c4a  3b742424               +cmp esi, dword ptr [esp + 0x24]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401c4e  7428                   -je 0x401c78
    if (cpu.flags.zf)
    {
        goto L_0x00401c78;
    }
    // 00401c50  8d3476                 -lea esi, [esi + esi*2]
    cpu.esi = x86::reg32(cpu.esi + cpu.esi * 2);
    // 00401c53  8b0cb3                 -mov ecx, dword ptr [ebx + esi*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + cpu.esi * 4);
    // 00401c56  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00401c5a  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00401c5d  837cb30400             +cmp dword ptr [ebx + esi*4 + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.esi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401c62  7512                   -jne 0x401c76
    if (!cpu.flags.zf)
    {
        goto L_0x00401c76;
    }
    // 00401c64  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 00401c69  8b44b308               -mov eax, dword ptr [ebx + esi*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.esi * 4);
    // 00401c6d  e840000000             -call 0x401cb2
    cpu.esp -= 4;
    sub_401cb2(app, cpu);
    // 00401c72  ff54b308               -call dword ptr [ebx + esi*4 + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.esi * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00401c76:
    // 00401c76  ebc3                   -jmp 0x401c3b
    goto L_0x00401c3b;
L_0x00401c78:
    // 00401c78  648f0500000000         -pop dword ptr fs:[0]
    app->getMemory<x86::reg32>(cpu.efs) = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401c7f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00401c82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401c83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401c84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401c85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401cb2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401cb2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401cb3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401cb4  bbe4504000             -mov ebx, 0x4050e4
    cpu.ebx = 4215012 /*0x4050e4*/;
    // 00401cb9  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00401cbc  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00401cbf  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00401cc2  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00401cc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401cc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401cc7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_401cd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401cd4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401cd5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401cd7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00401cda  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401cdb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401cdc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401cdd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401cde  fc                     -cld 
    cpu.flags.df = 0;
    // 00401cdf  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00401ce2  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00401ce5  f7400406000000         +test dword ptr [eax + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 00401cec  0f8582000000           -jne 0x401d74
    if (!cpu.flags.zf)
    {
        goto L_0x00401d74;
    }
    // 00401cf2  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00401cf5  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00401cf8  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00401cfb  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00401cfe  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00401d01  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00401d04  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
L_0x00401d07:
    // 00401d07  83feff                 +cmp esi, -1
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
    // 00401d0a  7461                   -je 0x401d6d
    if (cpu.flags.zf)
    {
        goto L_0x00401d6d;
    }
    // 00401d0c  8d0c76                 -lea ecx, [esi + esi*2]
    cpu.ecx = x86::reg32(cpu.esi + cpu.esi * 2);
    // 00401d0f  837c8f0400             +cmp dword ptr [edi + ecx*4 + 4], 0
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
    // 00401d14  7445                   -je 0x401d5b
    if (cpu.flags.zf)
    {
        goto L_0x00401d5b;
    }
    // 00401d16  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401d17  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401d18  8d6b10                 -lea ebp, [ebx + 0x10]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00401d1b  ff548f04               -call dword ptr [edi + ecx*4 + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401d1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401d20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401d21  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00401d24  0bc0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00401d26  7433                   -je 0x401d5b
    if (cpu.flags.zf)
    {
        goto L_0x00401d5b;
    }
    // 00401d28  783c                   -js 0x401d66
    if (cpu.flags.sf)
    {
        goto L_0x00401d66;
    }
    // 00401d2a  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00401d2d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401d2e  e8a9feffff             -call 0x401bdc
    cpu.esp -= 4;
    sub_401bdc(app, cpu);
    // 00401d33  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401d36  8d6b10                 -lea ebp, [ebx + 0x10]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00401d39  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401d3a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401d3b  e8defeffff             -call 0x401c1e
    cpu.esp -= 4;
    sub_401c1e(app, cpu);
    // 00401d40  83c408                 +add esp, 8
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
    // 00401d43  8d0c76                 -lea ecx, [esi + esi*2]
    cpu.ecx = x86::reg32(cpu.esi + cpu.esi * 2);
    // 00401d46  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401d48  8b448f08               -mov eax, dword ptr [edi + ecx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    // 00401d4c  e861ffffff             -call 0x401cb2
    cpu.esp -= 4;
    sub_401cb2(app, cpu);
    // 00401d51  8b048f                 -mov eax, dword ptr [edi + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 00401d54  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00401d57  ff548f08               -call dword ptr [edi + ecx*4 + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00401d5b:
    // 00401d5b  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00401d5e  8d0c76                 -lea ecx, [esi + esi*2]
    cpu.ecx = x86::reg32(cpu.esi + cpu.esi * 2);
    // 00401d61  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 00401d64  eba1                   -jmp 0x401d07
    goto L_0x00401d07;
L_0x00401d66:
    // 00401d66  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 00401d6b  eb1c                   -jmp 0x401d89
    goto L_0x00401d89;
L_0x00401d6d:
    // 00401d6d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00401d72  eb15                   -jmp 0x401d89
    goto L_0x00401d89;
L_0x00401d74:
    // 00401d74  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401d75  8d6b10                 -lea ebp, [ebx + 0x10]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00401d78  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00401d7a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401d7b  e89efeffff             -call 0x401c1e
    cpu.esp -= 4;
    sub_401c1e(app, cpu);
    // 00401d80  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00401d83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401d84  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00401d89:
    // 00401d89  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401d8a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401d8b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401d8c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401d8d  8be5                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00401d8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401d90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401d91(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401d91  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401d92  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00401d96  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 00401d98  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00401d9b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401d9c  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00401d9f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401da0  e879feffff             -call 0x401c1e
    cpu.esp -= 4;
    sub_401c1e(app, cpu);
    // 00401da5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00401da8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401da9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::asm_sub_401dac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401dac  a1ac544000             -mov eax, dword ptr [0x4054ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4215980) /* 0x4054ac */);
    // 00401db1  83f801                 +cmp eax, 1
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
    // 00401db4  740d                   -je 0x401dc3
    if (cpu.flags.zf)
    {
        goto L_0x00401dc3;
    }
    // 00401db6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401db8  752a                   -jne 0x401de4
    if (!cpu.flags.zf)
    {
        goto L_0x00401de4;
    }
    // 00401dba  833d4850400001         +cmp dword ptr [0x405048], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4214856) /* 0x405048 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401dc1  7521                   -jne 0x401de4
    if (!cpu.flags.zf)
    {
        goto L_0x00401de4;
    }
L_0x00401dc3:
    // 00401dc3  68fc000000             -push 0xfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 252 /*0xfc*/;
    cpu.esp -= 4;
    // 00401dc8  e818000000             -call 0x401de5
    cpu.esp -= 4;
    sub_401de5(app, cpu);
    // 00401dcd  a108564000             -mov eax, dword ptr [0x405608]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216328) /* 0x405608 */);
    // 00401dd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401dd3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401dd5  7402                   -je 0x401dd9
    if (cpu.flags.zf)
    {
        goto L_0x00401dd9;
    }
    // 00401dd7  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00401dd9:
    // 00401dd9  68ff000000             -push 0xff
    app->getMemory<x86::reg32>(cpu.esp-4) = 255 /*0xff*/;
    cpu.esp -= 4;
    // 00401dde  e802000000             -call 0x401de5
    cpu.esp -= 4;
    sub_401de5(app, cpu);
    // 00401de3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00401de4:
    // 00401de4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401de5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401de5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401de6  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401de8  81eca4010000           -sub esp, 0x1a4
    (cpu.esp) -= x86::reg32(x86::sreg32(420 /*0x1a4*/));
    // 00401dee  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00401df1  33c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00401df3  b8f8504000             -mov eax, 0x4050f8
    cpu.eax = 4215032 /*0x4050f8*/;
L_0x00401df8:
    // 00401df8  3b10                   +cmp edx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401dfa  740b                   -je 0x401e07
    if (cpu.flags.zf)
    {
        goto L_0x00401e07;
    }
    // 00401dfc  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00401dff  41                     -inc ecx
    (cpu.ecx)++;
    // 00401e00  3d88514000             +cmp eax, 0x405188
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4215176 /*0x405188*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401e05  7cf1                   -jl 0x401df8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401df8;
    }
L_0x00401e07:
    // 00401e07  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401e08  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00401e0a  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 00401e0d  3b96f8504000           +cmp edx, dword ptr [esi + 0x4050f8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4215032) /* 0x4050f8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401e13  0f851c010000           -jne 0x401f35
    if (!cpu.flags.zf)
    {
        goto L_0x00401f35;
    }
    // 00401e19  a1ac544000             -mov eax, dword ptr [0x4054ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4215980) /* 0x4054ac */);
    // 00401e1e  83f801                 +cmp eax, 1
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
    // 00401e21  0f84e8000000           -je 0x401f0f
    if (cpu.flags.zf)
    {
        goto L_0x00401f0f;
    }
    // 00401e27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401e29  750d                   -jne 0x401e38
    if (!cpu.flags.zf)
    {
        goto L_0x00401e38;
    }
    // 00401e2b  833d4850400001         +cmp dword ptr [0x405048], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4214856) /* 0x405048 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401e32  0f84d7000000           -je 0x401f0f
    if (cpu.flags.zf)
    {
        goto L_0x00401f0f;
    }
L_0x00401e38:
    // 00401e38  81fafc000000           +cmp edx, 0xfc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401e3e  0f84f1000000           -je 0x401f35
    if (cpu.flags.zf)
    {
        goto L_0x00401f35;
    }
    // 00401e44  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 00401e4a  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00401e4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401e50  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401e52  ff1558404000           -call dword ptr [0x404058]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210776) /* 0x404058 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401e58  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401e5a  7513                   -jne 0x401e6f
    if (!cpu.flags.zf)
    {
        goto L_0x00401e6f;
    }
    // 00401e5c  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 00401e62  68b4434000             -push 0x4043b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211636 /*0x4043b4*/;
    cpu.esp -= 4;
    // 00401e67  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401e68  e823050000             -call 0x402390
    cpu.esp -= 4;
    sub_402390(app, cpu);
    // 00401e6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401e6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00401e6f:
    // 00401e6f  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 00401e75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401e76  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401e77  8dbd5cfeffff           -lea edi, [ebp - 0x1a4]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 00401e7d  e87e060000             -call 0x402500
    cpu.esp -= 4;
    sub_402500(app, cpu);
    // 00401e82  40                     -inc eax
    (cpu.eax)++;
    // 00401e83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401e84  83f83c                 +cmp eax, 0x3c
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
    // 00401e87  7629                   -jbe 0x401eb2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00401eb2;
    }
    // 00401e89  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 00401e8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401e90  e86b060000             -call 0x402500
    cpu.esp -= 4;
    sub_402500(app, cpu);
    // 00401e95  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00401e97  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 00401e9d  83e83b                 -sub eax, 0x3b
    (cpu.eax) -= x86::reg32(x86::sreg32(59 /*0x3b*/));
    // 00401ea0  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00401ea2  03f8                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00401ea4  68b0434000             -push 0x4043b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211632 /*0x4043b0*/;
    cpu.esp -= 4;
    // 00401ea9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401eaa  e8e1120000             -call 0x403190
    cpu.esp -= 4;
    sub_403190(app, cpu);
    // 00401eaf  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00401eb2:
    // 00401eb2  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 00401eb8  6894434000             -push 0x404394
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211604 /*0x404394*/;
    cpu.esp -= 4;
    // 00401ebd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401ebe  e8cd040000             -call 0x402390
    cpu.esp -= 4;
    sub_402390(app, cpu);
    // 00401ec3  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 00401ec9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401eca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401ecb  e8d0040000             -call 0x4023a0
    cpu.esp -= 4;
    sub_4023a0(app, cpu);
    // 00401ed0  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 00401ed6  6890434000             -push 0x404390
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211600 /*0x404390*/;
    cpu.esp -= 4;
    // 00401edb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401edc  e8bf040000             -call 0x4023a0
    cpu.esp -= 4;
    sub_4023a0(app, cpu);
    // 00401ee1  ffb6fc504000           -push dword ptr [esi + 0x4050fc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4215036) /* 0x4050fc */);
    cpu.esp -= 4;
    // 00401ee7  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 00401eed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401eee  e8ad040000             -call 0x4023a0
    cpu.esp -= 4;
    sub_4023a0(app, cpu);
    // 00401ef3  6810200100             -push 0x12010
    app->getMemory<x86::reg32>(cpu.esp-4) = 73744 /*0x12010*/;
    cpu.esp -= 4;
    // 00401ef8  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 00401efe  6868434000             -push 0x404368
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211560 /*0x404368*/;
    cpu.esp -= 4;
    // 00401f03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401f04  e8f5110000             -call 0x4030fe
    cpu.esp -= 4;
    sub_4030fe(app, cpu);
    // 00401f09  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00401f0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401f0d  eb26                   -jmp 0x401f35
    goto L_0x00401f35;
L_0x00401f0f:
    // 00401f0f  8d4508                 -lea eax, [ebp + 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00401f12  8db6fc504000           -lea esi, [esi + 0x4050fc]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4215036) /* 0x4050fc */);
    // 00401f18  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401f1a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401f1b  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 00401f1d  e8de050000             -call 0x402500
    cpu.esp -= 4;
    sub_402500(app, cpu);
    // 00401f22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401f23  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401f24  ff36                   -push dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    // 00401f26  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 00401f28  ff1574404000           -call dword ptr [0x404074]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210804) /* 0x404074 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401f2e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401f2f  ff158c404000           -call dword ptr [0x40408c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210828) /* 0x40408c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00401f35:
    // 00401f35  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401f36  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401f37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401f38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401f38  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00401f3a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401f3c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00401f40  e804000000             -call 0x401f49
    cpu.esp -= 4;
    sub_401f49(app, cpu);
    // 00401f45  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00401f48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401f49(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401f49  0fb6442404             -movzx eax, byte ptr [esp + 4]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 00401f4e  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00401f52  848881574000           -test byte ptr [eax + 0x405781], cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4216705) /* 0x405781 */) & cpu.cl));
    // 00401f58  751c                   -jne 0x401f76
    if (!cpu.flags.zf)
    {
        goto L_0x00401f76;
    }
    // 00401f5a  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401f5f  740e                   -je 0x401f6f
    if (cpu.flags.zf)
    {
        goto L_0x00401f6f;
    }
    // 00401f61  0fb704459a524000       -movzx eax, word ptr [eax*2 + 0x40529a]
    cpu.eax = x86::reg32(app->getMemory<x86::reg16>(x86::reg32(4215450) /* 0x40529a */ + cpu.eax * 2));
    // 00401f69  23442408               +and eax, dword ptr [esp + 8]
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)))));
    // 00401f6d  eb02                   -jmp 0x401f71
    goto L_0x00401f71;
L_0x00401f6f:
    // 00401f6f  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00401f71:
    // 00401f71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401f73  7501                   -jne 0x401f76
    if (!cpu.flags.zf)
    {
        goto L_0x00401f76;
    }
    // 00401f75  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401f76:
    // 00401f76  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00401f78  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401f79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_401f7a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401f7a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401f7b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401f7d  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00401f80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401f81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401f82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401f83  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00401f86  e888010000             -call 0x402113
    cpu.esp -= 4;
    sub_402113(app, cpu);
    // 00401f8b  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00401f8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401f8e  3b356c564000           +cmp esi, dword ptr [0x40566c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4216428) /* 0x40566c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401f94  897508                 -mov dword ptr [ebp + 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00401f97  0f846a010000           -je 0x402107
    if (cpu.flags.zf)
    {
        goto L_0x00402107;
    }
    // 00401f9d  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00401f9f  3bf3                   +cmp esi, ebx
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
    // 00401fa1  0f8456010000           -je 0x4020fd
    if (cpu.flags.zf)
    {
        goto L_0x004020fd;
    }
    // 00401fa7  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00401fa9  b890514000             -mov eax, 0x405190
    cpu.eax = 4215184 /*0x405190*/;
L_0x00401fae:
    // 00401fae  3930                   +cmp dword ptr [eax], esi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401fb0  7472                   -je 0x402024
    if (cpu.flags.zf)
    {
        goto L_0x00402024;
    }
    // 00401fb2  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00401fb5  42                     -inc edx
    (cpu.edx)++;
    // 00401fb6  3d80524000             +cmp eax, 0x405280
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4215424 /*0x405280*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401fbb  7cf1                   -jl 0x401fae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401fae;
    }
    // 00401fbd  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00401fc0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401fc1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401fc2  ff1590404000           -call dword ptr [0x404090]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210832) /* 0x404090 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00401fc8  83f801                 +cmp eax, 1
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
    // 00401fcb  0f8524010000           -jne 0x4020f5
    if (!cpu.flags.zf)
    {
        goto L_0x004020f5;
    }
    // 00401fd1  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00401fd3  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401fd5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401fd6  bf80574000             -mov edi, 0x405780
    cpu.edi = 4216704 /*0x405780*/;
    // 00401fdb  837de801               +cmp dword ptr [ebp - 0x18], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401fdf  89356c564000           -mov dword ptr [0x40566c], esi
    app->getMemory<x86::reg32>(x86::reg32(4216428) /* 0x40566c */) = cpu.esi;
    // 00401fe5  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00401fe7  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 00401fe8  891d84584000           -mov dword ptr [0x405884], ebx
    app->getMemory<x86::reg32>(x86::reg32(4216964) /* 0x405884 */) = cpu.ebx;
    // 00401fee  0f86ef000000           -jbe 0x4020e3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004020e3;
    }
    // 00401ff4  807dee00               +cmp byte ptr [ebp - 0x12], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-18) /* -0x12 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00401ff8  0f84bb000000           -je 0x4020b9
    if (cpu.flags.zf)
    {
        goto L_0x004020b9;
    }
    // 00401ffe  8d4def                 -lea ecx, [ebp - 0x11]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-17) /* -0x11 */);
L_0x00402001:
    // 00402001  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00402003  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00402005  0f84ae000000           -je 0x4020b9
    if (cpu.flags.zf)
    {
        goto L_0x004020b9;
    }
    // 0040200b  0fb641ff               -movzx eax, byte ptr [ecx - 1]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */));
    // 0040200f  0fb6d2                 -movzx edx, dl
    cpu.edx = x86::reg32(cpu.dl);
L_0x00402012:
    // 00402012  3bc2                   +cmp eax, edx
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
    // 00402014  0f8793000000           -ja 0x4020ad
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004020ad;
    }
    // 0040201a  80888157400004         +or byte ptr [eax + 0x405781], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4216705) /* 0x405781 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00402021  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00402022  ebee                   -jmp 0x402012
    goto L_0x00402012;
L_0x00402024:
    // 00402024  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00402026  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00402028  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402029  bf80574000             -mov edi, 0x405780
    cpu.edi = 4216704 /*0x405780*/;
    // 0040202e  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00402030  8d3452                 -lea esi, [edx + edx*2]
    cpu.esi = x86::reg32(cpu.edx + cpu.edx * 2);
    // 00402033  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00402036  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00402039  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 0040203a  8d9ea0514000           -lea ebx, [esi + 0x4051a0]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(4215200) /* 0x4051a0 */);
L_0x00402040:
    // 00402040  803b00                 +cmp byte ptr [ebx], 0
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
    // 00402043  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00402045  742c                   -je 0x402073
    if (cpu.flags.zf)
    {
        goto L_0x00402073;
    }
L_0x00402047:
    // 00402047  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0040204a  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0040204c  7425                   -je 0x402073
    if (cpu.flags.zf)
    {
        goto L_0x00402073;
    }
    // 0040204e  0fb601                 -movzx eax, byte ptr [ecx]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx));
    // 00402051  0fb6fa                 -movzx edi, dl
    cpu.edi = x86::reg32(cpu.dl);
    // 00402054  3bc7                   +cmp eax, edi
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
    // 00402056  7714                   -ja 0x40206c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040206c;
    }
    // 00402058  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040205b  8a9288514000           -mov dl, byte ptr [edx + 0x405188]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4215176) /* 0x405188 */);
L_0x00402061:
    // 00402061  089081574000           -or byte ptr [eax + 0x405781], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4216705) /* 0x405781 */) |= x86::reg8(x86::sreg8(cpu.dl));
    // 00402067  40                     -inc eax
    (cpu.eax)++;
    // 00402068  3bc7                   +cmp eax, edi
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
    // 0040206a  76f5                   -jbe 0x402061
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00402061;
    }
L_0x0040206c:
    // 0040206c  41                     -inc ecx
    (cpu.ecx)++;
    // 0040206d  41                     -inc ecx
    (cpu.ecx)++;
    // 0040206e  803900                 +cmp byte ptr [ecx], 0
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
    // 00402071  75d4                   -jne 0x402047
    if (!cpu.flags.zf)
    {
        goto L_0x00402047;
    }
L_0x00402073:
    // 00402073  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 00402076  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00402079  837dfc04               +cmp dword ptr [ebp - 4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040207d  72c1                   -jb 0x402040
    if (cpu.flags.cf)
    {
        goto L_0x00402040;
    }
    // 0040207f  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402082  c7057c56400001000000   -mov dword ptr [0x40567c], 1
    app->getMemory<x86::reg32>(x86::reg32(4216444) /* 0x40567c */) = 1 /*0x1*/;
    // 0040208c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040208d  a36c564000             -mov dword ptr [0x40566c], eax
    app->getMemory<x86::reg32>(x86::reg32(4216428) /* 0x40566c */) = cpu.eax;
    // 00402092  e8c6000000             -call 0x40215d
    cpu.esp -= 4;
    sub_40215d(app, cpu);
    // 00402097  8db694514000           -lea esi, [esi + 0x405194]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4215188) /* 0x405194 */);
    // 0040209d  bf70564000             -mov edi, 0x405670
    cpu.edi = 4216432 /*0x405670*/;
    // 004020a2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004020a3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004020a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004020a5  a384584000             -mov dword ptr [0x405884], eax
    app->getMemory<x86::reg32>(x86::reg32(4216964) /* 0x405884 */) = cpu.eax;
    // 004020aa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004020ab  eb55                   -jmp 0x402102
    goto L_0x00402102;
L_0x004020ad:
    // 004020ad  41                     -inc ecx
    (cpu.ecx)++;
    // 004020ae  41                     -inc ecx
    (cpu.ecx)++;
    // 004020af  8079ff00               +cmp byte ptr [ecx - 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004020b3  0f8548ffffff           -jne 0x402001
    if (!cpu.flags.zf)
    {
        goto L_0x00402001;
    }
L_0x004020b9:
    // 004020b9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004020bb  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004020bc:
    // 004020bc  80888157400008         -or byte ptr [eax + 0x405781], 8
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4216705) /* 0x405781 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004020c3  40                     -inc eax
    (cpu.eax)++;
    // 004020c4  3dff000000             +cmp eax, 0xff
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
    // 004020c9  72f1                   -jb 0x4020bc
    if (cpu.flags.cf)
    {
        goto L_0x004020bc;
    }
    // 004020cb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004020cc  e88c000000             -call 0x40215d
    cpu.esp -= 4;
    sub_40215d(app, cpu);
    // 004020d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004020d2  a384584000             -mov dword ptr [0x405884], eax
    app->getMemory<x86::reg32>(x86::reg32(4216964) /* 0x405884 */) = cpu.eax;
    // 004020d7  c7057c56400001000000   -mov dword ptr [0x40567c], 1
    app->getMemory<x86::reg32>(x86::reg32(4216444) /* 0x40567c */) = 1 /*0x1*/;
    // 004020e1  eb06                   -jmp 0x4020e9
    goto L_0x004020e9;
L_0x004020e3:
    // 004020e3  891d7c564000           -mov dword ptr [0x40567c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4216444) /* 0x40567c */) = cpu.ebx;
L_0x004020e9:
    // 004020e9  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004020eb  bf70564000             -mov edi, 0x405670
    cpu.edi = 4216432 /*0x405670*/;
    // 004020f0  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 004020f1  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 004020f2  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 004020f3  eb0d                   -jmp 0x402102
    goto L_0x00402102;
L_0x004020f5:
    // 004020f5  391d0c564000           +cmp dword ptr [0x40560c], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4216332) /* 0x40560c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004020fb  740e                   -je 0x40210b
    if (cpu.flags.zf)
    {
        goto L_0x0040210b;
    }
L_0x004020fd:
    // 004020fd  e88e000000             -call 0x402190
    cpu.esp -= 4;
    sub_402190(app, cpu);
L_0x00402102:
    // 00402102  e8b2000000             -call 0x4021b9
    cpu.esp -= 4;
    sub_4021b9(app, cpu);
L_0x00402107:
    // 00402107  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00402109  eb03                   -jmp 0x40210e
    goto L_0x0040210e;
L_0x0040210b:
    // 0040210b  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
L_0x0040210e:
    // 0040210e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040210f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402110  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402111  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402112  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402113(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402113  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00402117  83250c56400000         -and dword ptr [0x40560c], 0
    app->getMemory<x86::reg32>(x86::reg32(4216332) /* 0x40560c */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 0040211e  83f8fe                 +cmp eax, -2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402121  7510                   -jne 0x402133
    if (!cpu.flags.zf)
    {
        goto L_0x00402133;
    }
    // 00402123  c7050c56400001000000   -mov dword ptr [0x40560c], 1
    app->getMemory<x86::reg32>(x86::reg32(4216332) /* 0x40560c */) = 1 /*0x1*/;
    // 0040212d  ff2598404000           -jmp dword ptr [0x404098]
    return app->dynamic_call(app->getMemory<x86::reg32>(4210840), cpu);
L_0x00402133:
    // 00402133  83f8fd                 +cmp eax, -3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402136  7510                   -jne 0x402148
    if (!cpu.flags.zf)
    {
        goto L_0x00402148;
    }
    // 00402138  c7050c56400001000000   -mov dword ptr [0x40560c], 1
    app->getMemory<x86::reg32>(x86::reg32(4216332) /* 0x40560c */) = 1 /*0x1*/;
    // 00402142  ff2594404000           -jmp dword ptr [0x404094]
    return app->dynamic_call(app->getMemory<x86::reg32>(4210836), cpu);
L_0x00402148:
    // 00402148  83f8fc                 +cmp eax, -4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040214b  750f                   -jne 0x40215c
    if (!cpu.flags.zf)
    {
        goto L_0x0040215c;
    }
    // 0040214d  a134564000             -mov eax, dword ptr [0x405634]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216372) /* 0x405634 */);
    // 00402152  c7050c56400001000000   -mov dword ptr [0x40560c], 1
    app->getMemory<x86::reg32>(x86::reg32(4216332) /* 0x40560c */) = 1 /*0x1*/;
L_0x0040215c:
    // 0040215c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40215d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040215d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00402161  2da4030000             +sub eax, 0x3a4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00402166  7422                   -je 0x40218a
    if (cpu.flags.zf)
    {
        goto L_0x0040218a;
    }
    // 00402168  83e804                 +sub eax, 4
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
    // 0040216b  7417                   -je 0x402184
    if (cpu.flags.zf)
    {
        goto L_0x00402184;
    }
    // 0040216d  83e80d                 +sub eax, 0xd
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00402170  740c                   -je 0x40217e
    if (cpu.flags.zf)
    {
        goto L_0x0040217e;
    }
    // 00402172  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00402173  7403                   -je 0x402178
    if (cpu.flags.zf)
    {
        goto L_0x00402178;
    }
    // 00402175  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00402177  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402178:
    // 00402178  b804040000             -mov eax, 0x404
    cpu.eax = 1028 /*0x404*/;
    // 0040217d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040217e:
    // 0040217e  b812040000             -mov eax, 0x412
    cpu.eax = 1042 /*0x412*/;
    // 00402183  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402184:
    // 00402184  b804080000             -mov eax, 0x804
    cpu.eax = 2052 /*0x804*/;
    // 00402189  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040218a:
    // 0040218a  b811040000             -mov eax, 0x411
    cpu.eax = 1041 /*0x411*/;
    // 0040218f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402190  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402191  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00402193  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402194  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00402196  bf80574000             -mov edi, 0x405780
    cpu.edi = 4216704 /*0x405780*/;
    // 0040219b  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 0040219d  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 0040219e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004021a0  bf70564000             -mov edi, 0x405670
    cpu.edi = 4216432 /*0x405670*/;
    // 004021a5  a36c564000             -mov dword ptr [0x40566c], eax
    app->getMemory<x86::reg32>(x86::reg32(4216428) /* 0x40566c */) = cpu.eax;
    // 004021aa  a37c564000             -mov dword ptr [0x40567c], eax
    app->getMemory<x86::reg32>(x86::reg32(4216444) /* 0x40567c */) = cpu.eax;
    // 004021af  a384584000             -mov dword ptr [0x405884], eax
    app->getMemory<x86::reg32>(x86::reg32(4216964) /* 0x405884 */) = cpu.eax;
    // 004021b4  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 004021b5  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 004021b6  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 004021b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004021b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4021b9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004021b9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004021ba  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004021bc  81ec14050000           -sub esp, 0x514
    (cpu.esp) -= x86::reg32(x86::sreg32(1300 /*0x514*/));
    // 004021c2  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004021c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004021c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004021c7  ff356c564000           -push dword ptr [0x40566c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216428) /* 0x40566c */);
    cpu.esp -= 4;
    // 004021cd  ff1590404000           -call dword ptr [0x404090]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210832) /* 0x404090 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004021d3  83f801                 +cmp eax, 1
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
    // 004021d6  0f8516010000           -jne 0x4022f2
    if (!cpu.flags.zf)
    {
        goto L_0x004022f2;
    }
    // 004021dc  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004021de  be00010000             -mov esi, 0x100
    cpu.esi = 256 /*0x100*/;
L_0x004021e3:
    // 004021e3  888405ecfeffff         -mov byte ptr [ebp + eax - 0x114], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-276) /* -0x114 */ + cpu.eax * 1) = cpu.al;
    // 004021ea  40                     -inc eax
    (cpu.eax)++;
    // 004021eb  3bc6                   +cmp eax, esi
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
    // 004021ed  72f4                   -jb 0x4021e3
    if (cpu.flags.cf)
    {
        goto L_0x004021e3;
    }
    // 004021ef  8a45f2                 -mov al, byte ptr [ebp - 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 004021f2  c685ecfeffff20         -mov byte ptr [ebp - 0x114], 0x20
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-276) /* -0x114 */) = 32 /*0x20*/;
    // 004021f9  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004021fb  7437                   -je 0x402234
    if (cpu.flags.zf)
    {
        goto L_0x00402234;
    }
    // 004021fd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004021fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004021ff  8d55f3                 -lea edx, [ebp - 0xd]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-13) /* -0xd */);
L_0x00402202:
    // 00402202  0fb60a                 -movzx ecx, byte ptr [edx]
    cpu.ecx = x86::reg32(app->getMemory<x86::reg8>(cpu.edx));
    // 00402205  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 00402208  3bc1                   +cmp eax, ecx
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
    // 0040220a  771d                   -ja 0x402229
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00402229;
    }
    // 0040220c  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0040220e  8dbc05ecfeffff         -lea edi, [ebp + eax - 0x114]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */ + cpu.eax * 1);
    // 00402215  41                     -inc ecx
    (cpu.ecx)++;
    // 00402216  b820202020             -mov eax, 0x20202020
    cpu.eax = 538976288 /*0x20202020*/;
    // 0040221b  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0040221d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00402220  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00402222  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00402224  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00402227  f3aa                   -rep stosb byte ptr es:[edi], al
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
L_0x00402229:
    // 00402229  42                     -inc edx
    (cpu.edx)++;
    // 0040222a  42                     -inc edx
    (cpu.edx)++;
    // 0040222b  8a42ff                 -mov al, byte ptr [edx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0040222e  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00402230  75d0                   -jne 0x402202
    if (!cpu.flags.zf)
    {
        goto L_0x00402202;
    }
    // 00402232  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402233  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00402234:
    // 00402234  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00402236  8d85ecfaffff           -lea eax, [ebp - 0x514]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
    // 0040223c  ff3584584000           -push dword ptr [0x405884]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216964) /* 0x405884 */);
    cpu.esp -= 4;
    // 00402242  ff356c564000           -push dword ptr [0x40566c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216428) /* 0x40566c */);
    cpu.esp -= 4;
    // 00402248  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402249  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 0040224f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402250  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402251  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00402253  e885120000             -call 0x4034dd
    cpu.esp -= 4;
    sub_4034dd(app, cpu);
    // 00402258  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040225a  8d85ecfdffff           -lea eax, [ebp - 0x214]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-532) /* -0x214 */);
    // 00402260  ff356c564000           -push dword ptr [0x40566c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216428) /* 0x40566c */);
    cpu.esp -= 4;
    // 00402266  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402267  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402268  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 0040226e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040226f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402270  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402271  ff3584584000           -push dword ptr [0x405884]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216964) /* 0x405884 */);
    cpu.esp -= 4;
    // 00402277  e812100000             -call 0x40328e
    cpu.esp -= 4;
    sub_40328e(app, cpu);
    // 0040227c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040227e  8d85ecfcffff           -lea eax, [ebp - 0x314]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-788) /* -0x314 */);
    // 00402284  ff356c564000           -push dword ptr [0x40566c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216428) /* 0x40566c */);
    cpu.esp -= 4;
    // 0040228a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040228b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040228c  8d85ecfeffff           -lea eax, [ebp - 0x114]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00402292  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402293  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402294  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 00402299  ff3584584000           -push dword ptr [0x405884]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216964) /* 0x405884 */);
    cpu.esp -= 4;
    // 0040229f  e8ea0f0000             -call 0x40328e
    cpu.esp -= 4;
    sub_40328e(app, cpu);
    // 004022a4  83c45c                 -add esp, 0x5c
    (cpu.esp) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 004022a7  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004022a9  8d8decfaffff           -lea ecx, [ebp - 0x514]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
L_0x004022af:
    // 004022af  668b11                 -mov dx, word ptr [ecx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx);
    // 004022b2  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004022b5  7416                   -je 0x4022cd
    if (cpu.flags.zf)
    {
        goto L_0x004022cd;
    }
    // 004022b7  80888157400010         +or byte ptr [eax + 0x405781], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4216705) /* 0x405781 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004022be  8a9405ecfdffff         -mov dl, byte ptr [ebp + eax - 0x214]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-532) /* -0x214 */ + cpu.eax * 1);
L_0x004022c5:
    // 004022c5  889080564000           -mov byte ptr [eax + 0x405680], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4216448) /* 0x405680 */) = cpu.dl;
    // 004022cb  eb1c                   -jmp 0x4022e9
    goto L_0x004022e9;
L_0x004022cd:
    // 004022cd  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004022d0  7410                   -je 0x4022e2
    if (cpu.flags.zf)
    {
        goto L_0x004022e2;
    }
    // 004022d2  80888157400020         +or byte ptr [eax + 0x405781], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4216705) /* 0x405781 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004022d9  8a9405ecfcffff         -mov dl, byte ptr [ebp + eax - 0x314]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-788) /* -0x314 */ + cpu.eax * 1);
    // 004022e0  ebe3                   -jmp 0x4022c5
    goto L_0x004022c5;
L_0x004022e2:
    // 004022e2  80a08056400000         -and byte ptr [eax + 0x405680], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4216448) /* 0x405680 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x004022e9:
    // 004022e9  40                     -inc eax
    (cpu.eax)++;
    // 004022ea  41                     -inc ecx
    (cpu.ecx)++;
    // 004022eb  41                     -inc ecx
    (cpu.ecx)++;
    // 004022ec  3bc6                   +cmp eax, esi
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
    // 004022ee  72bf                   -jb 0x4022af
    if (cpu.flags.cf)
    {
        goto L_0x004022af;
    }
    // 004022f0  eb49                   -jmp 0x40233b
    goto L_0x0040233b;
L_0x004022f2:
    // 004022f2  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004022f4  be00010000             -mov esi, 0x100
    cpu.esi = 256 /*0x100*/;
L_0x004022f9:
    // 004022f9  83f841                 +cmp eax, 0x41
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65 /*0x41*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004022fc  7219                   -jb 0x402317
    if (cpu.flags.cf)
    {
        goto L_0x00402317;
    }
    // 004022fe  83f85a                 +cmp eax, 0x5a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(90 /*0x5a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402301  7714                   -ja 0x402317
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00402317;
    }
    // 00402303  80888157400010         -or byte ptr [eax + 0x405781], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4216705) /* 0x405781 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0040230a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0040230c  80c120                 +add cl, 0x20
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0040230f:
    // 0040230f  888880564000           -mov byte ptr [eax + 0x405680], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4216448) /* 0x405680 */) = cpu.cl;
    // 00402315  eb1f                   -jmp 0x402336
    goto L_0x00402336;
L_0x00402317:
    // 00402317  83f861                 +cmp eax, 0x61
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
    // 0040231a  7213                   -jb 0x40232f
    if (cpu.flags.cf)
    {
        goto L_0x0040232f;
    }
    // 0040231c  83f87a                 +cmp eax, 0x7a
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
    // 0040231f  770e                   -ja 0x40232f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040232f;
    }
    // 00402321  80888157400020         -or byte ptr [eax + 0x405781], 0x20
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4216705) /* 0x405781 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00402328  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0040232a  80e920                 +sub cl, 0x20
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040232d  ebe0                   -jmp 0x40230f
    goto L_0x0040230f;
L_0x0040232f:
    // 0040232f  80a08056400000         -and byte ptr [eax + 0x405680], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4216448) /* 0x405680 */) &= x86::reg8(x86::sreg8(0 /*0x0*/));
L_0x00402336:
    // 00402336  40                     -inc eax
    (cpu.eax)++;
    // 00402337  3bc6                   +cmp eax, esi
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
    // 00402339  72be                   -jb 0x4022f9
    if (cpu.flags.cf)
    {
        goto L_0x004022f9;
    }
L_0x0040233b:
    // 0040233b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040233c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040233d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40233e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040233e  833da859400000         +cmp dword ptr [0x4059a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4217256) /* 0x4059a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402345  7512                   -jne 0x402359
    if (!cpu.flags.zf)
    {
        goto L_0x00402359;
    }
    // 00402347  6afd                   -push -3
    app->getMemory<x86::reg32>(cpu.esp-4) = -3 /*-0x3*/;
    cpu.esp -= 4;
    // 00402349  e82cfcffff             -call 0x401f7a
    cpu.esp -= 4;
    sub_401f7a(app, cpu);
    // 0040234e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040234f  c705a859400001000000   -mov dword ptr [0x4059a8], 1
    app->getMemory<x86::reg32>(x86::reg32(4217256) /* 0x4059a8 */) = 1 /*0x1*/;
L_0x00402359:
    // 00402359  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40235a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040235a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040235b  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0040235f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00402361  7424                   -je 0x402387
    if (cpu.flags.zf)
    {
        goto L_0x00402387;
    }
    // 00402363  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402364  e88a050000             -call 0x4028f3
    cpu.esp -= 4;
    sub_4028f3(app, cpu);
    // 00402369  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040236a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040236c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040236d  740a                   -je 0x402379
    if (cpu.flags.zf)
    {
        goto L_0x00402379;
    }
    // 0040236f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402370  e8a9050000             -call 0x40291e
    cpu.esp -= 4;
    sub_40291e(app, cpu);
    // 00402375  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402376  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402377  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402378  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402379:
    // 00402379  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040237b  ff3588584000           -push dword ptr [0x405888]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216968) /* 0x405888 */);
    cpu.esp -= 4;
    // 00402381  ff156c404000           -call dword ptr [0x40406c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210796) /* 0x40406c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00402387:
    // 00402387  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402388  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402390  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402391  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00402395  eb6a                   -jmp 0x402401
    return sub_402401(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4023a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004023a0  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004023a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004023a5  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 004023ab  740f                   -je 0x4023bc
    if (cpu.flags.zf)
    {
        goto L_0x004023bc;
    }
L_0x004023ad:
    // 004023ad  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004023af  41                     -inc ecx
    (cpu.ecx)++;
    // 004023b0  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004023b2  743b                   -je 0x4023ef
    if (cpu.flags.zf)
    {
        goto L_0x004023ef;
    }
    // 004023b4  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 004023ba  75f1                   -jne 0x4023ad
    if (!cpu.flags.zf)
    {
        goto L_0x004023ad;
    }
L_0x004023bc:
    // 004023bc  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004023be  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 004023c3  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004023c5  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004023c8  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004023ca  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004023cd  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 004023d2  74e8                   -je 0x4023bc
    if (cpu.flags.zf)
    {
        goto L_0x004023bc;
    }
    // 004023d4  8b41fc                 -mov eax, dword ptr [ecx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004023d7  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004023d9  7423                   -je 0x4023fe
    if (cpu.flags.zf)
    {
        goto L_0x004023fe;
    }
    // 004023db  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004023dd  741a                   -je 0x4023f9
    if (cpu.flags.zf)
    {
        goto L_0x004023f9;
    }
    // 004023df  a90000ff00             +test eax, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16711680 /*0xff0000*/));
    // 004023e4  740e                   -je 0x4023f4
    if (cpu.flags.zf)
    {
        goto L_0x004023f4;
    }
    // 004023e6  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 004023eb  7402                   -je 0x4023ef
    if (cpu.flags.zf)
    {
        goto L_0x004023ef;
    }
    // 004023ed  ebcd                   -jmp 0x4023bc
    goto L_0x004023bc;
L_0x004023ef:
    // 004023ef  8d79ff                 -lea edi, [ecx - 1]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004023f2  eb0d                   -jmp 0x402401
    goto L_0x00402401;
L_0x004023f4:
    // 004023f4  8d79fe                 -lea edi, [ecx - 2]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 004023f7  eb08                   -jmp 0x402401
    goto L_0x00402401;
L_0x004023f9:
    // 004023f9  8d79fd                 -lea edi, [ecx - 3]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-3) /* -0x3 */);
    // 004023fc  eb03                   -jmp 0x402401
    goto L_0x00402401;
L_0x004023fe:
    // 004023fe  8d79fc                 -lea edi, [ecx - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
L_0x00402401:
    // 00402401  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00402405  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0040240b  7419                   -je 0x402426
    if (cpu.flags.zf)
    {
        goto L_0x00402426;
    }
L_0x0040240d:
    // 0040240d  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0040240f  41                     -inc ecx
    (cpu.ecx)++;
    // 00402410  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00402412  7464                   -je 0x402478
    if (cpu.flags.zf)
    {
        goto L_0x00402478;
    }
    // 00402414  8817                   -mov byte ptr [edi], dl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.dl;
    // 00402416  47                     -inc edi
    (cpu.edi)++;
    // 00402417  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0040241d  75ee                   -jne 0x40240d
    if (!cpu.flags.zf)
    {
        goto L_0x0040240d;
    }
    // 0040241f  eb05                   -jmp 0x402426
    goto L_0x00402426;
L_0x00402421:
    // 00402421  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 00402423  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00402426:
    // 00402426  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 0040242b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040242d  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040242f  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402432  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00402434  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00402436  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00402439  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 0040243e  74e1                   -je 0x402421
    if (cpu.flags.zf)
    {
        goto L_0x00402421;
    }
    // 00402440  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00402442  7434                   -je 0x402478
    if (cpu.flags.zf)
    {
        goto L_0x00402478;
    }
    // 00402444  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00402446  7427                   -je 0x40246f
    if (cpu.flags.zf)
    {
        goto L_0x0040246f;
    }
    // 00402448  f7c20000ff00           +test edx, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 16711680 /*0xff0000*/));
    // 0040244e  7412                   -je 0x402462
    if (cpu.flags.zf)
    {
        goto L_0x00402462;
    }
    // 00402450  f7c2000000ff           +test edx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4278190080 /*0xff000000*/));
    // 00402456  7402                   -je 0x40245a
    if (cpu.flags.zf)
    {
        goto L_0x0040245a;
    }
    // 00402458  ebc7                   -jmp 0x402421
    goto L_0x00402421;
L_0x0040245a:
    // 0040245a  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0040245c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00402460  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402461  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402462:
    // 00402462  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
    // 00402465  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00402469  c6470200               -mov byte ptr [edi + 2], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0040246d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040246e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040246f:
    // 0040246f  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
    // 00402472  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00402476  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402477  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402478:
    // 00402478  8817                   -mov byte ptr [edi], dl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.dl;
    // 0040247a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0040247e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040247f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402401(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00402401;
    // 004023a0  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004023a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004023a5  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 004023ab  740f                   -je 0x4023bc
    if (cpu.flags.zf)
    {
        goto L_0x004023bc;
    }
L_0x004023ad:
    // 004023ad  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004023af  41                     -inc ecx
    (cpu.ecx)++;
    // 004023b0  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004023b2  743b                   -je 0x4023ef
    if (cpu.flags.zf)
    {
        goto L_0x004023ef;
    }
    // 004023b4  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 004023ba  75f1                   -jne 0x4023ad
    if (!cpu.flags.zf)
    {
        goto L_0x004023ad;
    }
L_0x004023bc:
    // 004023bc  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004023be  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 004023c3  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004023c5  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004023c8  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004023ca  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004023cd  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 004023d2  74e8                   -je 0x4023bc
    if (cpu.flags.zf)
    {
        goto L_0x004023bc;
    }
    // 004023d4  8b41fc                 -mov eax, dword ptr [ecx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004023d7  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004023d9  7423                   -je 0x4023fe
    if (cpu.flags.zf)
    {
        goto L_0x004023fe;
    }
    // 004023db  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004023dd  741a                   -je 0x4023f9
    if (cpu.flags.zf)
    {
        goto L_0x004023f9;
    }
    // 004023df  a90000ff00             +test eax, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16711680 /*0xff0000*/));
    // 004023e4  740e                   -je 0x4023f4
    if (cpu.flags.zf)
    {
        goto L_0x004023f4;
    }
    // 004023e6  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 004023eb  7402                   -je 0x4023ef
    if (cpu.flags.zf)
    {
        goto L_0x004023ef;
    }
    // 004023ed  ebcd                   -jmp 0x4023bc
    goto L_0x004023bc;
L_0x004023ef:
    // 004023ef  8d79ff                 -lea edi, [ecx - 1]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004023f2  eb0d                   -jmp 0x402401
    goto L_0x00402401;
L_0x004023f4:
    // 004023f4  8d79fe                 -lea edi, [ecx - 2]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 004023f7  eb08                   -jmp 0x402401
    goto L_0x00402401;
L_0x004023f9:
    // 004023f9  8d79fd                 -lea edi, [ecx - 3]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-3) /* -0x3 */);
    // 004023fc  eb03                   -jmp 0x402401
    goto L_0x00402401;
L_0x004023fe:
    // 004023fe  8d79fc                 -lea edi, [ecx - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
L_0x00402401:
L_entry_0x00402401:
    // 00402401  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00402405  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0040240b  7419                   -je 0x402426
    if (cpu.flags.zf)
    {
        goto L_0x00402426;
    }
L_0x0040240d:
    // 0040240d  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0040240f  41                     -inc ecx
    (cpu.ecx)++;
    // 00402410  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00402412  7464                   -je 0x402478
    if (cpu.flags.zf)
    {
        goto L_0x00402478;
    }
    // 00402414  8817                   -mov byte ptr [edi], dl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.dl;
    // 00402416  47                     -inc edi
    (cpu.edi)++;
    // 00402417  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0040241d  75ee                   -jne 0x40240d
    if (!cpu.flags.zf)
    {
        goto L_0x0040240d;
    }
    // 0040241f  eb05                   -jmp 0x402426
    goto L_0x00402426;
L_0x00402421:
    // 00402421  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 00402423  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00402426:
    // 00402426  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 0040242b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0040242d  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040242f  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402432  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00402434  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00402436  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00402439  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 0040243e  74e1                   -je 0x402421
    if (cpu.flags.zf)
    {
        goto L_0x00402421;
    }
    // 00402440  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00402442  7434                   -je 0x402478
    if (cpu.flags.zf)
    {
        goto L_0x00402478;
    }
    // 00402444  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00402446  7427                   -je 0x40246f
    if (cpu.flags.zf)
    {
        goto L_0x0040246f;
    }
    // 00402448  f7c20000ff00           +test edx, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 16711680 /*0xff0000*/));
    // 0040244e  7412                   -je 0x402462
    if (cpu.flags.zf)
    {
        goto L_0x00402462;
    }
    // 00402450  f7c2000000ff           +test edx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4278190080 /*0xff000000*/));
    // 00402456  7402                   -je 0x40245a
    if (cpu.flags.zf)
    {
        goto L_0x0040245a;
    }
    // 00402458  ebc7                   -jmp 0x402421
    goto L_0x00402421;
L_0x0040245a:
    // 0040245a  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0040245c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00402460  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402461  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402462:
    // 00402462  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
    // 00402465  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00402469  c6470200               -mov byte ptr [edi + 2], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0040246d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040246e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040246f:
    // 0040246f  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
    // 00402472  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00402476  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402477  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402478:
    // 00402478  8817                   -mov byte ptr [edi], dl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.dl;
    // 0040247a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0040247e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040247f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402480  ff3544564000           -push dword ptr [0x405644]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216388) /* 0x405644 */);
    cpu.esp -= 4;
    // 00402486  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0040248a  e803000000             -call 0x402492
    cpu.esp -= 4;
    sub_402492(app, cpu);
    // 0040248f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402490  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402491  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402492(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402492  837c2404e0             +cmp dword ptr [esp + 4], -0x20
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-32 /*-0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402497  7722                   -ja 0x4024bb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004024bb;
    }
L_0x00402499:
    // 00402499  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0040249d  e81c000000             -call 0x4024be
    cpu.esp -= 4;
    sub_4024be(app, cpu);
    // 004024a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004024a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004024a5  7516                   -jne 0x4024bd
    if (!cpu.flags.zf)
    {
        goto L_0x004024bd;
    }
    // 004024a7  39442408               +cmp dword ptr [esp + 8], eax
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
    // 004024ab  7410                   -je 0x4024bd
    if (cpu.flags.zf)
    {
        goto L_0x004024bd;
    }
    // 004024ad  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004024b1  e870110000             -call 0x403626
    cpu.esp -= 4;
    sub_403626(app, cpu);
    // 004024b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004024b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004024b9  75de                   -jne 0x402499
    if (!cpu.flags.zf)
    {
        goto L_0x00402499;
    }
L_0x004024bb:
    // 004024bb  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004024bd:
    // 004024bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4024be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004024be  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004024bf  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004024c3  3b3580524000           +cmp esi, dword ptr [0x405280]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4215424) /* 0x405280 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004024c9  770b                   -ja 0x4024d6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004024d6;
    }
    // 004024cb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004024cc  e878070000             -call 0x402c49
    cpu.esp -= 4;
    sub_402c49(app, cpu);
    // 004024d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004024d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004024d4  751c                   -jne 0x4024f2
    if (!cpu.flags.zf)
    {
        goto L_0x004024f2;
    }
L_0x004024d6:
    // 004024d6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004024d8  7503                   -jne 0x4024dd
    if (!cpu.flags.zf)
    {
        goto L_0x004024dd;
    }
    // 004024da  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004024dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004024dd:
    // 004024dd  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004024e0  83e6f0                 -and esi, 0xfffffff0
    cpu.esi &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 004024e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004024e4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004024e6  ff3588584000           -push dword ptr [0x405888]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216968) /* 0x405888 */);
    cpu.esp -= 4;
    // 004024ec  ff1588404000           -call dword ptr [0x404088]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210824) /* 0x404088 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x004024f2:
    // 004024f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004024f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402500  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00402504  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 0040250a  7414                   -je 0x402520
    if (cpu.flags.zf)
    {
        goto L_0x00402520;
    }
L_0x0040250c:
    // 0040250c  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0040250e  41                     -inc ecx
    (cpu.ecx)++;
    // 0040250f  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00402511  7440                   -je 0x402553
    if (cpu.flags.zf)
    {
        goto L_0x00402553;
    }
    // 00402513  f7c103000000           +test ecx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 3 /*0x3*/));
    // 00402519  75f1                   -jne 0x40250c
    if (!cpu.flags.zf)
    {
        goto L_0x0040250c;
    }
    // 0040251b  0500000000             -add eax, 0
    (cpu.eax) += x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x00402520:
    // 00402520  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00402522  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 00402527  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00402529  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040252c  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040252e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00402531  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 00402536  74e8                   -je 0x402520
    if (cpu.flags.zf)
    {
        goto L_0x00402520;
    }
    // 00402538  8b41fc                 -mov eax, dword ptr [ecx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 0040253b  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0040253d  7432                   -je 0x402571
    if (cpu.flags.zf)
    {
        goto L_0x00402571;
    }
    // 0040253f  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00402541  7424                   -je 0x402567
    if (cpu.flags.zf)
    {
        goto L_0x00402567;
    }
    // 00402543  a90000ff00             +test eax, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 16711680 /*0xff0000*/));
    // 00402548  7413                   -je 0x40255d
    if (cpu.flags.zf)
    {
        goto L_0x0040255d;
    }
    // 0040254a  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 0040254f  7402                   -je 0x402553
    if (cpu.flags.zf)
    {
        goto L_0x00402553;
    }
    // 00402551  ebcd                   -jmp 0x402520
    goto L_0x00402520;
L_0x00402553:
    // 00402553  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00402556  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0040255a  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040255c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040255d:
    // 0040255d  8d41fe                 -lea eax, [ecx - 2]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 00402560  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00402564  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00402566  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402567:
    // 00402567  8d41fd                 -lea eax, [ecx - 3]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-3) /* -0x3 */);
    // 0040256a  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0040256e  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00402570  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402571:
    // 00402571  8d41fc                 -lea eax, [ecx - 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00402574  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00402578  2bc1                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040257a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00402580  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402581  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402583  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402584  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402585  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00402588  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0040258b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0040258e  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402590  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00402592  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00402594  3bfe                   +cmp edi, esi
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
    // 00402596  7608                   -jbe 0x4025a0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004025a0;
    }
    // 00402598  3bf8                   +cmp edi, eax
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
    // 0040259a  0f8278010000           -jb 0x402718
    if (cpu.flags.cf)
    {
        goto L_0x00402718;
    }
L_0x004025a0:
    // 004025a0  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004025a6  7514                   -jne 0x4025bc
    if (!cpu.flags.zf)
    {
        goto L_0x004025bc;
    }
    // 004025a8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004025ab  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004025ae  83f908                 +cmp ecx, 8
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
    // 004025b1  7229                   -jb 0x4025dc
    if (cpu.flags.cf)
    {
        goto L_0x004025dc;
    }
    // 004025b3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004025b5  ff2495c8264000         -jmp dword ptr [edx*4 + 0x4026c8]
    cpu.ip = app->getMemory<x86::reg32>(4204232 + cpu.edx * 4); goto dynamic_jump;
L_0x004025bc:
    // 004025bc  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004025be  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004025c3  83e904                 +sub ecx, 4
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
    // 004025c6  720c                   -jb 0x4025d4
    if (cpu.flags.cf)
    {
        goto L_0x004025d4;
    }
    // 004025c8  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004025cb  03c8                   +add ecx, eax
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
    // 004025cd  ff2485e0254000         -jmp dword ptr [eax*4 + 0x4025e0]
    cpu.ip = app->getMemory<x86::reg32>(4204000 + cpu.eax * 4); goto dynamic_jump;
L_0x004025d4:
    // 004025d4  ff248dd8264000         -jmp dword ptr [ecx*4 + 0x4026d8]
    cpu.ip = app->getMemory<x86::reg32>(4204248 + cpu.ecx * 4); goto dynamic_jump;
L_0x004025dc:
    // 004025dc  ff248d5c264000         -jmp dword ptr [ecx*4 + 0x40265c]
    cpu.ip = app->getMemory<x86::reg32>(4204124 + cpu.ecx * 4); goto dynamic_jump;
  case 0x004025f0:
    // 004025f0  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004025f2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004025f4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004025f6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004025f9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004025fc  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004025ff  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00402602  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00402605  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00402608  83c703                 -add edi, 3
    (cpu.edi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040260b  83f908                 +cmp ecx, 8
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
    // 0040260e  72cc                   -jb 0x4025dc
    if (cpu.flags.cf)
    {
        goto L_0x004025dc;
    }
    // 00402610  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00402612  ff2495c8264000         -jmp dword ptr [edx*4 + 0x4026c8]
    cpu.ip = app->getMemory<x86::reg32>(4204232 + cpu.edx * 4); goto dynamic_jump;
  case 0x0040261c:
    // 0040261c  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040261e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00402620  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00402622  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00402625  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00402628  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0040262b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040262e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00402631  83f908                 +cmp ecx, 8
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
    // 00402634  72a6                   -jb 0x4025dc
    if (cpu.flags.cf)
    {
        goto L_0x004025dc;
    }
    // 00402636  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00402638  ff2495c8264000         -jmp dword ptr [edx*4 + 0x4026c8]
    cpu.ip = app->getMemory<x86::reg32>(4204232 + cpu.edx * 4); goto dynamic_jump;
  case 0x00402640:
    // 00402640  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00402642  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00402644  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00402646  46                     -inc esi
    (cpu.esi)++;
    // 00402647  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0040264a  47                     -inc edi
    (cpu.edi)++;
    // 0040264b  83f908                 +cmp ecx, 8
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
    // 0040264e  728c                   -jb 0x4025dc
    if (cpu.flags.cf)
    {
        goto L_0x004025dc;
    }
    // 00402650  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00402652  ff2495c8264000         -jmp dword ptr [edx*4 + 0x4026c8]
    cpu.ip = app->getMemory<x86::reg32>(4204232 + cpu.edx * 4); goto dynamic_jump;
  case 0x0040267c:
    // 0040267c  8b448ee4               -mov eax, dword ptr [esi + ecx*4 - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-28) /* -0x1c */ + cpu.ecx * 4);
    // 00402680  89448fe4               -mov dword ptr [edi + ecx*4 - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-28) /* -0x1c */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00402684:
    // 00402684  8b448ee8               -mov eax, dword ptr [esi + ecx*4 - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 4);
    // 00402688  89448fe8               -mov dword ptr [edi + ecx*4 - 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0040268c:
    // 0040268c  8b448eec               -mov eax, dword ptr [esi + ecx*4 - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-20) /* -0x14 */ + cpu.ecx * 4);
    // 00402690  89448fec               -mov dword ptr [edi + ecx*4 - 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-20) /* -0x14 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00402694:
    // 00402694  8b448ef0               -mov eax, dword ptr [esi + ecx*4 - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 4);
    // 00402698  89448ff0               -mov dword ptr [edi + ecx*4 - 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0040269c:
    // 0040269c  8b448ef4               -mov eax, dword ptr [esi + ecx*4 - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-12) /* -0xc */ + cpu.ecx * 4);
    // 004026a0  89448ff4               -mov dword ptr [edi + ecx*4 - 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-12) /* -0xc */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x004026a4:
    // 004026a4  8b448ef8               -mov eax, dword ptr [esi + ecx*4 - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 4);
    // 004026a8  89448ff8               -mov dword ptr [edi + ecx*4 - 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x004026ac:
    // 004026ac  8b448efc               -mov eax, dword ptr [esi + ecx*4 - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 004026b0  89448ffc               -mov dword ptr [edi + ecx*4 - 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.eax;
    // 004026b4  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004026bb  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004026bd  03f8                   +add edi, eax
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
  case 0x004026bf:
    // 004026bf  ff2495c8264000         -jmp dword ptr [edx*4 + 0x4026c8]
    cpu.ip = app->getMemory<x86::reg32>(4204232 + cpu.edx * 4); goto dynamic_jump;
  case 0x004026d8:
    // 004026d8  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004026db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026dd  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026de  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004026e0:
    // 004026e0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004026e2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004026e4  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004026e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026e9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026ea  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004026ec:
    // 004026ec  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004026ee  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004026f0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004026f3  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004026f6  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004026f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026fb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026fc  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00402700:
    // 00402700  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00402702  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00402704  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00402707  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0040270a  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0040270d  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00402710  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402713  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402714  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402715  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402716  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402718:
    // 00402718  8d7431fc               -lea esi, [ecx + esi - 4]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1);
    // 0040271c  8d7c39fc               -lea edi, [ecx + edi - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 00402720  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 00402726  7524                   -jne 0x40274c
    if (!cpu.flags.zf)
    {
        goto L_0x0040274c;
    }
    // 00402728  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0040272b  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040272e  83f908                 +cmp ecx, 8
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
    // 00402731  720d                   -jb 0x402740
    if (cpu.flags.cf)
    {
        goto L_0x00402740;
    }
    // 00402733  fd                     -std 
    cpu.flags.df = 1;
    // 00402734  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00402736  fc                     -cld 
    cpu.flags.df = 0;
    // 00402737  ff249560284000         -jmp dword ptr [edx*4 + 0x402860]
    cpu.ip = app->getMemory<x86::reg32>(4204640 + cpu.edx * 4); goto dynamic_jump;
L_0x00402740:
    // 00402740  f7d9                   +neg ecx
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
    // 00402742  ff248d10284000         -jmp dword ptr [ecx*4 + 0x402810]
    cpu.ip = app->getMemory<x86::reg32>(4204560 + cpu.ecx * 4); goto dynamic_jump;
L_0x0040274c:
    // 0040274c  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0040274e  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00402753  83f904                 +cmp ecx, 4
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
    // 00402756  720c                   -jb 0x402764
    if (cpu.flags.cf)
    {
        goto L_0x00402764;
    }
    // 00402758  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040275b  2bc8                   +sub ecx, eax
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
    // 0040275d  ff248568274000         -jmp dword ptr [eax*4 + 0x402768]
    cpu.ip = app->getMemory<x86::reg32>(4204392 + cpu.eax * 4); goto dynamic_jump;
L_0x00402764:
    // 00402764  ff248d60284000         -jmp dword ptr [ecx*4 + 0x402860]
    cpu.ip = app->getMemory<x86::reg32>(4204640 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00402778:
    // 00402778  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0040277b  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040277d  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00402780  4e                     -dec esi
    (cpu.esi)--;
    // 00402781  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00402784  4f                     -dec edi
    (cpu.edi)--;
    // 00402785  83f908                 +cmp ecx, 8
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
    // 00402788  72b6                   -jb 0x402740
    if (cpu.flags.cf)
    {
        goto L_0x00402740;
    }
    // 0040278a  fd                     -std 
    cpu.flags.df = 1;
    // 0040278b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040278d  fc                     -cld 
    cpu.flags.df = 0;
    // 0040278e  ff249560284000         -jmp dword ptr [edx*4 + 0x402860]
    cpu.ip = app->getMemory<x86::reg32>(4204640 + cpu.edx * 4); goto dynamic_jump;
  case 0x00402798:
    // 00402798  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0040279b  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040279d  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004027a0  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004027a3  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004027a6  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004027a9  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004027ac  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004027af  83f908                 +cmp ecx, 8
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
    // 004027b2  728c                   -jb 0x402740
    if (cpu.flags.cf)
    {
        goto L_0x00402740;
    }
    // 004027b4  fd                     -std 
    cpu.flags.df = 1;
    // 004027b5  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004027b7  fc                     -cld 
    cpu.flags.df = 0;
    // 004027b8  ff249560284000         -jmp dword ptr [edx*4 + 0x402860]
    cpu.ip = app->getMemory<x86::reg32>(4204640 + cpu.edx * 4); goto dynamic_jump;
  case 0x004027c0:
    // 004027c0  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004027c3  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004027c5  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004027c8  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004027cb  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004027ce  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004027d1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004027d4  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004027d7  83ee03                 -sub esi, 3
    (cpu.esi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004027da  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004027dd  83f908                 +cmp ecx, 8
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
    // 004027e0  0f825affffff           -jb 0x402740
    if (cpu.flags.cf)
    {
        goto L_0x00402740;
    }
    // 004027e6  fd                     -std 
    cpu.flags.df = 1;
    // 004027e7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004027e9  fc                     -cld 
    cpu.flags.df = 0;
    // 004027ea  ff249560284000         -jmp dword ptr [edx*4 + 0x402860]
    cpu.ip = app->getMemory<x86::reg32>(4204640 + cpu.edx * 4); goto dynamic_jump;
  case 0x00402814:
    // 00402814  8b448e1c               -mov eax, dword ptr [esi + ecx*4 + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */ + cpu.ecx * 4);
    // 00402818  89448f1c               -mov dword ptr [edi + ecx*4 + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0040281c:
    // 0040281c  8b448e18               -mov eax, dword ptr [esi + ecx*4 + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */ + cpu.ecx * 4);
    // 00402820  89448f18               -mov dword ptr [edi + ecx*4 + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00402824:
    // 00402824  8b448e14               -mov eax, dword ptr [esi + ecx*4 + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */ + cpu.ecx * 4);
    // 00402828  89448f14               -mov dword ptr [edi + ecx*4 + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0040282c:
    // 0040282c  8b448e10               -mov eax, dword ptr [esi + ecx*4 + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */ + cpu.ecx * 4);
    // 00402830  89448f10               -mov dword ptr [edi + ecx*4 + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00402834:
    // 00402834  8b448e0c               -mov eax, dword ptr [esi + ecx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ecx * 4);
    // 00402838  89448f0c               -mov dword ptr [edi + ecx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0040283c:
    // 0040283c  8b448e08               -mov eax, dword ptr [esi + ecx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    // 00402840  89448f08               -mov dword ptr [edi + ecx*4 + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00402844:
    // 00402844  8b448e04               -mov eax, dword ptr [esi + ecx*4 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    // 00402848  89448f04               -mov dword ptr [edi + ecx*4 + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4) = cpu.eax;
    // 0040284c  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00402853  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00402855  03f8                   +add edi, eax
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
  case 0x00402857:
    // 00402857  ff249560284000         -jmp dword ptr [edx*4 + 0x402860]
    cpu.ip = app->getMemory<x86::reg32>(4204640 + cpu.edx * 4); goto dynamic_jump;
  case 0x00402870:
    // 00402870  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402873  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402874  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402875  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402876  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00402878:
    // 00402878  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0040287b  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0040287e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402881  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402882  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402883  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402884  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00402888:
    // 00402888  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0040288b  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0040288e  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00402891  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00402894  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402897  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402898  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402899  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040289a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040289c:
    // 0040289c  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0040289f  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004028a2  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004028a5  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004028a8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004028ab  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004028ae  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004028b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028b3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028b4  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_4028b5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004028b5  6840010000             -push 0x140
    app->getMemory<x86::reg32>(cpu.esp-4) = 320 /*0x140*/;
    cpu.esp -= 4;
    // 004028ba  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004028bc  ff3588584000           -push dword ptr [0x405888]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216968) /* 0x405888 */);
    cpu.esp -= 4;
    // 004028c2  ff1588404000           -call dword ptr [0x404088]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210824) /* 0x404088 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004028c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004028ca  a368564000             -mov dword ptr [0x405668], eax
    app->getMemory<x86::reg32>(x86::reg32(4216424) /* 0x405668 */) = cpu.eax;
    // 004028cf  7501                   -jne 0x4028d2
    if (!cpu.flags.zf)
    {
        goto L_0x004028d2;
    }
    // 004028d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004028d2:
    // 004028d2  83256056400000         -and dword ptr [0x405660], 0
    app->getMemory<x86::reg32>(x86::reg32(4216416) /* 0x405660 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004028d9  83256456400000         -and dword ptr [0x405664], 0
    app->getMemory<x86::reg32>(x86::reg32(4216420) /* 0x405664 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004028e0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004028e2  a35c564000             -mov dword ptr [0x40565c], eax
    app->getMemory<x86::reg32>(x86::reg32(4216412) /* 0x40565c */) = cpu.eax;
    // 004028e7  c7055456400010000000   -mov dword ptr [0x405654], 0x10
    app->getMemory<x86::reg32>(x86::reg32(4216404) /* 0x405654 */) = 16 /*0x10*/;
    // 004028f1  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4028f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004028f3  a164564000             -mov eax, dword ptr [0x405664]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216420) /* 0x405664 */);
    // 004028f8  8d0c80                 -lea ecx, [eax + eax*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 4);
    // 004028fb  a168564000             -mov eax, dword ptr [0x405668]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216424) /* 0x405668 */);
    // 00402900  8d0c88                 -lea ecx, [eax + ecx*4]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ecx * 4);
L_0x00402903:
    // 00402903  3bc1                   +cmp eax, ecx
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
    // 00402905  7314                   -jae 0x40291b
    if (!cpu.flags.cf)
    {
        goto L_0x0040291b;
    }
    // 00402907  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0040290b  2b500c                 -sub edx, dword ptr [eax + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 0040290e  81fa00001000           +cmp edx, 0x100000
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
    // 00402914  7207                   -jb 0x40291d
    if (cpu.flags.cf)
    {
        goto L_0x0040291d;
    }
    // 00402916  83c014                 +add eax, 0x14
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
    // 00402919  ebe8                   -jmp 0x402903
    goto L_0x00402903;
L_0x0040291b:
    // 0040291b  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040291d:
    // 0040291d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40291e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040291e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040291f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402921  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00402924  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00402927  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0040292a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040292b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040292c  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0040292f  8bf2                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00402931  2b710c                 -sub esi, dword ptr [ecx + 0xc]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 00402934  8b5afc                 -mov ebx, dword ptr [edx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00402937  83c2fc                 -add edx, -4
    (cpu.edx) += x86::reg32(x86::sreg32(-4 /*-0x4*/));
    // 0040293a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040293b  c1ee0f                 -shr esi, 0xf
    cpu.esi >>= 15 /*0xf*/ % 32;
    // 0040293e  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00402940  8b7afc                 -mov edi, dword ptr [edx - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00402943  69c904020000           -imul ecx, ecx, 0x204
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(516 /*0x204*/)));
    // 00402949  4b                     -dec ebx
    (cpu.ebx)--;
    // 0040294a  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0040294d  8d8c0144010000         -lea ecx, [ecx + eax + 0x144]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(324) /* 0x144 */ + cpu.eax * 1);
    // 00402954  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00402957  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 0040295a  8b0c13                 -mov ecx, dword ptr [ebx + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + cpu.edx * 1);
    // 0040295d  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00402960  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00402963  757f                   -jne 0x4029e4
    if (!cpu.flags.zf)
    {
        goto L_0x004029e4;
    }
    // 00402965  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00402968  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0040296a  49                     -dec ecx
    (cpu.ecx)--;
    // 0040296b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040296c  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0040296f  3bcf                   +cmp ecx, edi
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
    // 00402971  7603                   -jbe 0x402976
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00402976;
    }
    // 00402973  897d0c                 -mov dword ptr [ebp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x00402976:
    // 00402976  8b4c1304               -mov ecx, dword ptr [ebx + edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.edx * 1);
    // 0040297a  3b4c1308               +cmp ecx, dword ptr [ebx + edx + 8]
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
    // 0040297e  7548                   -jne 0x4029c8
    if (!cpu.flags.zf)
    {
        goto L_0x004029c8;
    }
    // 00402980  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00402983  83f920                 +cmp ecx, 0x20
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
    // 00402986  731c                   -jae 0x4029a4
    if (!cpu.flags.cf)
    {
        goto L_0x004029a4;
    }
    // 00402988  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 0040298d  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 0040298f  8d4c0104               -lea ecx, [ecx + eax + 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00402993  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 00402995  217cb044               +and dword ptr [eax + esi*4 + 0x44], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.esi * 4) &= x86::reg32(x86::sreg32(cpu.edi))));
    // 00402999  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 0040299b  752b                   -jne 0x4029c8
    if (!cpu.flags.zf)
    {
        goto L_0x004029c8;
    }
    // 0040299d  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004029a0  2139                   +and dword ptr [ecx], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(cpu.edi))));
    // 004029a2  eb24                   -jmp 0x4029c8
    goto L_0x004029c8;
L_0x004029a4:
    // 004029a4  83c1e0                 -add ecx, -0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(-32 /*-0x20*/));
    // 004029a7  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 004029ac  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 004029ae  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004029b1  8d4c0104               -lea ecx, [ecx + eax + 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 004029b5  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 004029b7  21bcb0c4000000         +and dword ptr [eax + esi*4 + 0xc4], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.esi * 4) &= x86::reg32(x86::sreg32(cpu.edi))));
    // 004029be  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 004029c0  7506                   -jne 0x4029c8
    if (!cpu.flags.zf)
    {
        goto L_0x004029c8;
    }
    // 004029c2  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004029c5  217904                 -and dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(cpu.edi));
L_0x004029c8:
    // 004029c8  8b4c1308               -mov ecx, dword ptr [ebx + edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.edx * 1);
    // 004029cc  8b7c1304               -mov edi, dword ptr [ebx + edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.edx * 1);
    // 004029d0  897904                 -mov dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004029d3  8b4c1304               -mov ecx, dword ptr [ebx + edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.edx * 1);
    // 004029d7  8b7c1308               -mov edi, dword ptr [ebx + edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.edx * 1);
    // 004029db  035df8                 -add ebx, dword ptr [ebp - 8]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004029de  897908                 -mov dword ptr [ecx + 8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004029e1  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x004029e4:
    // 004029e4  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004029e6  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 004029e9  4f                     -dec edi
    (cpu.edi)--;
    // 004029ea  83ff3f                 +cmp edi, 0x3f
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
    // 004029ed  7603                   -jbe 0x4029f2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004029f2;
    }
    // 004029ef  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 004029f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004029f2:
    // 004029f2  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004029f5  83e101                 +and ecx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004029f8  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 004029fb  0f85a0000000           -jne 0x402aa1
    if (!cpu.flags.zf)
    {
        goto L_0x00402aa1;
    }
    // 00402a01  2b55fc                 -sub edx, dword ptr [ebp - 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00402a04  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00402a07  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00402a0a  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 00402a0c  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00402a0f  49                     -dec ecx
    (cpu.ecx)--;
    // 00402a10  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402a11  3bca                   +cmp ecx, edx
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
    // 00402a13  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00402a16  7605                   -jbe 0x402a1d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00402a1d;
    }
    // 00402a18  89550c                 -mov dword ptr [ebp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00402a1b  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x00402a1d:
    // 00402a1d  035dfc                 -add ebx, dword ptr [ebp - 4]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00402a20  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00402a22  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00402a25  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00402a28  4f                     -dec edi
    (cpu.edi)--;
    // 00402a29  3bfa                   +cmp edi, edx
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
    // 00402a2b  7602                   -jbe 0x402a2f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00402a2f;
    }
    // 00402a2d  8bfa                   -mov edi, edx
    cpu.edi = cpu.edx;
L_0x00402a2f:
    // 00402a2f  3bcf                   +cmp ecx, edi
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
    // 00402a31  746b                   -je 0x402a9e
    if (cpu.flags.zf)
    {
        goto L_0x00402a9e;
    }
    // 00402a33  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00402a36  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00402a39  3b5108                 +cmp edx, dword ptr [ecx + 8]
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
    // 00402a3c  7548                   -jne 0x402a86
    if (!cpu.flags.zf)
    {
        goto L_0x00402a86;
    }
    // 00402a3e  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00402a41  83f920                 +cmp ecx, 0x20
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
    // 00402a44  731c                   -jae 0x402a62
    if (!cpu.flags.cf)
    {
        goto L_0x00402a62;
    }
    // 00402a46  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 00402a4b  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 00402a4d  8d4c0104               -lea ecx, [ecx + eax + 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00402a51  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00402a53  2154b044               +and dword ptr [eax + esi*4 + 0x44], edx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.esi * 4) &= x86::reg32(x86::sreg32(cpu.edx))));
    // 00402a57  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 00402a59  752b                   -jne 0x402a86
    if (!cpu.flags.zf)
    {
        goto L_0x00402a86;
    }
    // 00402a5b  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402a5e  2111                   +and dword ptr [ecx], edx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(cpu.edx))));
    // 00402a60  eb24                   -jmp 0x402a86
    goto L_0x00402a86;
L_0x00402a62:
    // 00402a62  83c1e0                 -add ecx, -0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(-32 /*-0x20*/));
    // 00402a65  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 00402a6a  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 00402a6c  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00402a6f  8d4c0104               -lea ecx, [ecx + eax + 4]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00402a73  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00402a75  2194b0c4000000         +and dword ptr [eax + esi*4 + 0xc4], edx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.esi * 4) &= x86::reg32(x86::sreg32(cpu.edx))));
    // 00402a7c  fe09                   +dec byte ptr [ecx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ecx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 00402a7e  7506                   -jne 0x402a86
    if (!cpu.flags.zf)
    {
        goto L_0x00402a86;
    }
    // 00402a80  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402a83  215104                 -and dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(cpu.edx));
L_0x00402a86:
    // 00402a86  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00402a89  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00402a8c  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00402a8f  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00402a92  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00402a95  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00402a98  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00402a9b  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
L_0x00402a9e:
    // 00402a9e  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x00402aa1:
    // 00402aa1  837dec00               +cmp dword ptr [ebp - 0x14], 0
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
    // 00402aa5  7509                   -jne 0x402ab0
    if (!cpu.flags.zf)
    {
        goto L_0x00402ab0;
    }
    // 00402aa7  397d0c                 +cmp dword ptr [ebp + 0xc], edi
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
    // 00402aaa  0f8489000000           -je 0x402b39
    if (cpu.flags.zf)
    {
        goto L_0x00402b39;
    }
L_0x00402ab0:
    // 00402ab0  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00402ab3  8d0cf9                 -lea ecx, [ecx + edi*8]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.edi * 8);
    // 00402ab6  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00402ab9  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00402abc  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00402abf  8d0cf9                 -lea ecx, [ecx + edi*8]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.edi * 8);
    // 00402ac2  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00402ac5  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00402ac8  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00402acb  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00402ace  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00402ad1  3b4a08                 +cmp ecx, dword ptr [edx + 8]
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
    // 00402ad4  7563                   -jne 0x402b39
    if (!cpu.flags.zf)
    {
        goto L_0x00402b39;
    }
    // 00402ad6  8a4c0704               -mov cl, byte ptr [edi + eax + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00402ada  83ff20                 +cmp edi, 0x20
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
    // 00402add  884d0f                 -mov byte ptr [ebp + 0xf], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(15) /* 0xf */) = cpu.cl;
    // 00402ae0  fec1                   +inc cl
    {
        x86::reg8& tmp = cpu.cl;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 00402ae2  884c0704               -mov byte ptr [edi + eax + 4], cl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.cl;
    // 00402ae6  7325                   -jae 0x402b0d
    if (!cpu.flags.cf)
    {
        goto L_0x00402b0d;
    }
    // 00402ae8  807d0f00               +cmp byte ptr [ebp + 0xf], 0
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
    // 00402aec  750e                   -jne 0x402afc
    if (!cpu.flags.zf)
    {
        goto L_0x00402afc;
    }
    // 00402aee  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00402af3  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00402af5  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 00402af7  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402afa  0919                   -or dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00402afc:
    // 00402afc  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00402b01  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00402b03  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 00402b05  8d44b044               -lea eax, [eax + esi*4 + 0x44]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.esi * 4);
    // 00402b09  0918                   +or dword ptr [eax], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00402b0b  eb29                   -jmp 0x402b36
    goto L_0x00402b36;
L_0x00402b0d:
    // 00402b0d  807d0f00               +cmp byte ptr [ebp + 0xf], 0
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
    // 00402b11  7510                   -jne 0x402b23
    if (!cpu.flags.zf)
    {
        goto L_0x00402b23;
    }
    // 00402b13  8d4fe0                 -lea ecx, [edi - 0x20]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-32) /* -0x20 */);
    // 00402b16  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00402b1b  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 00402b1d  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402b20  095904                 -or dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00402b23:
    // 00402b23  8d4fe0                 -lea ecx, [edi - 0x20]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-32) /* -0x20 */);
    // 00402b26  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 00402b2b  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 00402b2d  8d84b0c4000000         -lea eax, [eax + esi*4 + 0xc4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.esi * 4);
    // 00402b34  0938                   +or dword ptr [eax], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edi))));
L_0x00402b36:
    // 00402b36  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
L_0x00402b39:
    // 00402b39  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00402b3c  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00402b3e  895c13fc               -mov dword ptr [ebx + edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */ + cpu.edx * 1) = cpu.ebx;
    // 00402b42  ff08                   +dec dword ptr [eax]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.eax);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00402b44  0f85fa000000           -jne 0x402c44
    if (!cpu.flags.zf)
    {
        goto L_0x00402c44;
    }
    // 00402b4a  a160564000             -mov eax, dword ptr [0x405660]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216416) /* 0x405660 */);
    // 00402b4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402b51  0f84df000000           -je 0x402c36
    if (cpu.flags.zf)
    {
        goto L_0x00402c36;
    }
    // 00402b57  8b0d58564000           -mov ecx, dword ptr [0x405658]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4216408) /* 0x405658 */);
    // 00402b5d  8b3d84404000           -mov edi, dword ptr [0x404084]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4210820) /* 0x404084 */);
    // 00402b63  c1e10f                 -shl ecx, 0xf
    cpu.ecx <<= 15 /*0xf*/ % 32;
    // 00402b66  03480c                 -add ecx, dword ptr [eax + 0xc]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 00402b69  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 00402b6e  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 00402b73  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402b74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402b75  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00402b77  8b0d58564000           -mov ecx, dword ptr [0x405658]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4216408) /* 0x405658 */);
    // 00402b7d  a160564000             -mov eax, dword ptr [0x405660]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216416) /* 0x405660 */);
    // 00402b82  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 00402b87  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 00402b89  095008                 -or dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) |= x86::reg32(x86::sreg32(cpu.edx));
    // 00402b8c  a160564000             -mov eax, dword ptr [0x405660]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216416) /* 0x405660 */);
    // 00402b91  8b0d58564000           -mov ecx, dword ptr [0x405658]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4216408) /* 0x405658 */);
    // 00402b97  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00402b9a  83a488c400000000       -and dword ptr [eax + ecx*4 + 0xc4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.ecx * 4) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00402ba2  a160564000             -mov eax, dword ptr [0x405660]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216416) /* 0x405660 */);
    // 00402ba7  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00402baa  fe4843                 -dec byte ptr [eax + 0x43]
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(67) /* 0x43 */))--;
    // 00402bad  a160564000             -mov eax, dword ptr [0x405660]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216416) /* 0x405660 */);
    // 00402bb2  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00402bb5  80794300               +cmp byte ptr [ecx + 0x43], 0
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
    // 00402bb9  7509                   -jne 0x402bc4
    if (!cpu.flags.zf)
    {
        goto L_0x00402bc4;
    }
    // 00402bbb  836004fe               -and dword ptr [eax + 4], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(4294967294 /*0xfffffffe*/));
    // 00402bbf  a160564000             -mov eax, dword ptr [0x405660]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216416) /* 0x405660 */);
L_0x00402bc4:
    // 00402bc4  837808ff               +cmp dword ptr [eax + 8], -1
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
    // 00402bc8  756c                   -jne 0x402c36
    if (!cpu.flags.zf)
    {
        goto L_0x00402c36;
    }
    // 00402bca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402bcb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00402bcd  ff700c                 -push dword ptr [eax + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00402bd0  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00402bd2  a160564000             -mov eax, dword ptr [0x405660]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216416) /* 0x405660 */);
    // 00402bd7  ff7010                 -push dword ptr [eax + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00402bda  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00402bdc  ff3588584000           -push dword ptr [0x405888]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216968) /* 0x405888 */);
    cpu.esp -= 4;
    // 00402be2  ff156c404000           -call dword ptr [0x40406c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210796) /* 0x40406c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00402be8  a164564000             -mov eax, dword ptr [0x405664]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216420) /* 0x405664 */);
    // 00402bed  8b1568564000           -mov edx, dword ptr [0x405668]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4216424) /* 0x405668 */);
    // 00402bf3  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00402bf6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00402bf9  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00402bfb  a160564000             -mov eax, dword ptr [0x405660]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216416) /* 0x405660 */);
    // 00402c00  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00402c02  8d4c11ec               -lea ecx, [ecx + edx - 0x14]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(-20) /* -0x14 */ + cpu.edx * 1);
    // 00402c06  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402c07  8d4814                 -lea ecx, [eax + 0x14]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00402c0a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402c0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402c0c  e83f0a0000             -call 0x403650
    cpu.esp -= 4;
    sub_403650(app, cpu);
    // 00402c11  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402c14  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00402c17  ff0d64564000           -dec dword ptr [0x405664]
    (app->getMemory<x86::reg32>(x86::reg32(4216420) /* 0x405664 */))--;
    // 00402c1d  3b0560564000           +cmp eax, dword ptr [0x405660]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4216416) /* 0x405660 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402c23  7603                   -jbe 0x402c28
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00402c28;
    }
    // 00402c25  83e814                 +sub eax, 0x14
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
L_0x00402c28:
    // 00402c28  8b0d68564000           -mov ecx, dword ptr [0x405668]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4216424) /* 0x405668 */);
    // 00402c2e  890d5c564000           -mov dword ptr [0x40565c], ecx
    app->getMemory<x86::reg32>(x86::reg32(4216412) /* 0x40565c */) = cpu.ecx;
    // 00402c34  eb03                   -jmp 0x402c39
    goto L_0x00402c39;
L_0x00402c36:
    // 00402c36  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x00402c39:
    // 00402c39  a360564000             -mov dword ptr [0x405660], eax
    app->getMemory<x86::reg32>(x86::reg32(4216416) /* 0x405660 */) = cpu.eax;
    // 00402c3e  893558564000           -mov dword ptr [0x405658], esi
    app->getMemory<x86::reg32>(x86::reg32(4216408) /* 0x405658 */) = cpu.esi;
L_0x00402c44:
    // 00402c44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c47  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402c49(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402c49  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402c4a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402c4c  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00402c4f  a164564000             -mov eax, dword ptr [0x405664]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216420) /* 0x405664 */);
    // 00402c54  8b1568564000           -mov edx, dword ptr [0x405668]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4216424) /* 0x405668 */);
    // 00402c5a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402c5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402c5c  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00402c5f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402c60  8d3c82                 -lea edi, [edx + eax*4]
    cpu.edi = x86::reg32(cpu.edx + cpu.eax * 4);
    // 00402c63  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402c66  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00402c69  8d4817                 -lea ecx, [eax + 0x17]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 00402c6c  83e1f0                 -and ecx, 0xfffffff0
    cpu.ecx &= x86::reg32(x86::sreg32(4294967280 /*0xfffffff0*/));
    // 00402c6f  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 00402c72  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00402c75  49                     -dec ecx
    (cpu.ecx)--;
    // 00402c76  83f920                 +cmp ecx, 0x20
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
    // 00402c79  7d0e                   -jge 0x402c89
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402c89;
    }
    // 00402c7b  83ceff                 -or esi, 0xffffffff
    cpu.esi |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402c7e  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 00402c80  834df8ff               +or dword ptr [ebp - 8], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00402c84  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00402c87  eb10                   -jmp 0x402c99
    goto L_0x00402c99;
L_0x00402c89:
    // 00402c89  83c1e0                 -add ecx, -0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(-32 /*-0x20*/));
    // 00402c8c  83c8ff                 -or eax, 0xffffffff
    cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402c8f  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00402c91  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00402c93  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00402c96  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x00402c99:
    // 00402c99  a15c564000             -mov eax, dword ptr [0x40565c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216412) /* 0x40565c */);
    // 00402c9e  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00402ca0  3bdf                   +cmp ebx, edi
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
    // 00402ca2  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00402ca5  7319                   -jae 0x402cc0
    if (!cpu.flags.cf)
    {
        goto L_0x00402cc0;
    }
L_0x00402ca7:
    // 00402ca7  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00402caa  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00402cac  234df8                 -and ecx, dword ptr [ebp - 8]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00402caf  23fe                   -and edi, esi
    cpu.edi &= x86::reg32(x86::sreg32(cpu.esi));
    // 00402cb1  0bcf                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00402cb3  750b                   -jne 0x402cc0
    if (!cpu.flags.zf)
    {
        goto L_0x00402cc0;
    }
    // 00402cb5  83c314                 -add ebx, 0x14
    (cpu.ebx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00402cb8  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
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
    // 00402cbb  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00402cbe  72e7                   -jb 0x402ca7
    if (cpu.flags.cf)
    {
        goto L_0x00402ca7;
    }
L_0x00402cc0:
    // 00402cc0  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
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
    // 00402cc3  7579                   -jne 0x402d3e
    if (!cpu.flags.zf)
    {
        goto L_0x00402d3e;
    }
    // 00402cc5  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00402cc7:
    // 00402cc7  3bd8                   +cmp ebx, eax
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
    // 00402cc9  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00402ccc  7315                   -jae 0x402ce3
    if (!cpu.flags.cf)
    {
        goto L_0x00402ce3;
    }
    // 00402cce  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00402cd1  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00402cd3  234df8                 -and ecx, dword ptr [ebp - 8]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00402cd6  23fe                   -and edi, esi
    cpu.edi &= x86::reg32(x86::sreg32(cpu.esi));
    // 00402cd8  0bcf                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00402cda  7505                   -jne 0x402ce1
    if (!cpu.flags.zf)
    {
        goto L_0x00402ce1;
    }
    // 00402cdc  83c314                 +add ebx, 0x14
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
    // 00402cdf  ebe6                   -jmp 0x402cc7
    goto L_0x00402cc7;
L_0x00402ce1:
    // 00402ce1  3bd8                   +cmp ebx, eax
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
L_0x00402ce3:
    // 00402ce3  7559                   -jne 0x402d3e
    if (!cpu.flags.zf)
    {
        goto L_0x00402d3e;
    }
L_0x00402ce5:
    // 00402ce5  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
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
    // 00402ce8  7311                   -jae 0x402cfb
    if (!cpu.flags.cf)
    {
        goto L_0x00402cfb;
    }
    // 00402cea  837b0800               +cmp dword ptr [ebx + 8], 0
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
    // 00402cee  7508                   -jne 0x402cf8
    if (!cpu.flags.zf)
    {
        goto L_0x00402cf8;
    }
    // 00402cf0  83c314                 +add ebx, 0x14
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
    // 00402cf3  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00402cf6  ebed                   -jmp 0x402ce5
    goto L_0x00402ce5;
L_0x00402cf8:
    // 00402cf8  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
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
L_0x00402cfb:
    // 00402cfb  7526                   -jne 0x402d23
    if (!cpu.flags.zf)
    {
        goto L_0x00402d23;
    }
    // 00402cfd  8bda                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00402cff:
    // 00402cff  3bd8                   +cmp ebx, eax
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
    // 00402d01  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00402d04  730d                   -jae 0x402d13
    if (!cpu.flags.cf)
    {
        goto L_0x00402d13;
    }
    // 00402d06  837b0800               +cmp dword ptr [ebx + 8], 0
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
    // 00402d0a  7505                   -jne 0x402d11
    if (!cpu.flags.zf)
    {
        goto L_0x00402d11;
    }
    // 00402d0c  83c314                 +add ebx, 0x14
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
    // 00402d0f  ebee                   -jmp 0x402cff
    goto L_0x00402cff;
L_0x00402d11:
    // 00402d11  3bd8                   +cmp ebx, eax
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
L_0x00402d13:
    // 00402d13  750e                   -jne 0x402d23
    if (!cpu.flags.zf)
    {
        goto L_0x00402d23;
    }
    // 00402d15  e838020000             -call 0x402f52
    cpu.esp -= 4;
    sub_402f52(app, cpu);
    // 00402d1a  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00402d1c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00402d1e  895d08                 -mov dword ptr [ebp + 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00402d21  7414                   -je 0x402d37
    if (cpu.flags.zf)
    {
        goto L_0x00402d37;
    }
L_0x00402d23:
    // 00402d23  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402d24  e8da020000             -call 0x403003
    cpu.esp -= 4;
    sub_403003(app, cpu);
    // 00402d29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402d2a  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00402d2d  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00402d2f  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00402d32  8338ff                 +cmp dword ptr [eax], -1
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
    // 00402d35  7507                   -jne 0x402d3e
    if (!cpu.flags.zf)
    {
        goto L_0x00402d3e;
    }
L_0x00402d37:
    // 00402d37  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00402d39  e90f020000             -jmp 0x402f4d
    goto L_0x00402f4d;
L_0x00402d3e:
    // 00402d3e  891d5c564000           -mov dword ptr [0x40565c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4216412) /* 0x40565c */) = cpu.ebx;
    // 00402d44  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00402d47  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00402d49  83faff                 +cmp edx, -1
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
    // 00402d4c  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00402d4f  7414                   -je 0x402d65
    if (cpu.flags.zf)
    {
        goto L_0x00402d65;
    }
    // 00402d51  8b8c90c4000000         -mov ecx, dword ptr [eax + edx*4 + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4);
    // 00402d58  8b7c9044               -mov edi, dword ptr [eax + edx*4 + 0x44]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4);
    // 00402d5c  234df8                 -and ecx, dword ptr [ebp - 8]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00402d5f  23fe                   -and edi, esi
    cpu.edi &= x86::reg32(x86::sreg32(cpu.esi));
    // 00402d61  0bcf                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00402d63  7537                   -jne 0x402d9c
    if (!cpu.flags.zf)
    {
        goto L_0x00402d9c;
    }
L_0x00402d65:
    // 00402d65  8b90c4000000           -mov edx, dword ptr [eax + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 00402d6b  8b7044                 -mov esi, dword ptr [eax + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00402d6e  2355f8                 -and edx, dword ptr [ebp - 8]
    cpu.edx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00402d71  2375f4                 -and esi, dword ptr [ebp - 0xc]
    cpu.esi &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00402d74  8365fc00               -and dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 00402d78  8d4844                 -lea ecx, [eax + 0x44]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 00402d7b  0bd6                   +or edx, esi
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.esi))));
    // 00402d7d  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00402d80  7517                   -jne 0x402d99
    if (!cpu.flags.zf)
    {
        goto L_0x00402d99;
    }
L_0x00402d82:
    // 00402d82  8b9184000000           -mov edx, dword ptr [ecx + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 00402d88  ff45fc                 -inc dword ptr [ebp - 4]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))++;
    // 00402d8b  2355f8                 -and edx, dword ptr [ebp - 8]
    cpu.edx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00402d8e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00402d91  8bfe                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00402d93  2339                   -and edi, dword ptr [ecx]
    cpu.edi &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 00402d95  0bd7                   +or edx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00402d97  74e9                   -je 0x402d82
    if (cpu.flags.zf)
    {
        goto L_0x00402d82;
    }
L_0x00402d99:
    // 00402d99  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x00402d9c:
    // 00402d9c  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00402d9e  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00402da0  69c904020000           -imul ecx, ecx, 0x204
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(516 /*0x204*/)));
    // 00402da6  8d8c0144010000         -lea ecx, [ecx + eax + 0x144]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(324) /* 0x144 */ + cpu.eax * 1);
    // 00402dad  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00402db0  8b4c9044               -mov ecx, dword ptr [eax + edx*4 + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.edx * 4);
    // 00402db4  23ce                   +and ecx, esi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(cpu.esi))));
    // 00402db6  750d                   -jne 0x402dc5
    if (!cpu.flags.zf)
    {
        goto L_0x00402dc5;
    }
    // 00402db8  8b8c90c4000000         -mov ecx, dword ptr [eax + edx*4 + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.edx * 4);
    // 00402dbf  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00402dc1  234df8                 -and ecx, dword ptr [ebp - 8]
    cpu.ecx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00402dc4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00402dc5:
    // 00402dc5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00402dc7  7c05                   -jl 0x402dce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00402dce;
    }
    // 00402dc9  d1e1                   +shl ecx, 1
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
    // 00402dcb  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00402dcc  ebf7                   -jmp 0x402dc5
    goto L_0x00402dc5;
L_0x00402dce:
    // 00402dce  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00402dd1  8b54f904               -mov edx, dword ptr [ecx + edi*8 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.edi * 8);
    // 00402dd5  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00402dd7  2b4df0                 -sub ecx, dword ptr [ebp - 0x10]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 00402dda  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00402ddc  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00402ddf  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 00402de2  4e                     -dec esi
    (cpu.esi)--;
    // 00402de3  83fe3f                 +cmp esi, 0x3f
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
    // 00402de6  7e03                   -jle 0x402deb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402deb;
    }
    // 00402de8  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 00402dea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00402deb:
    // 00402deb  3bf7                   +cmp esi, edi
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
    // 00402ded  0f840d010000           -je 0x402f00
    if (cpu.flags.zf)
    {
        goto L_0x00402f00;
    }
    // 00402df3  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00402df6  3b4a08                 +cmp ecx, dword ptr [edx + 8]
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
    // 00402df9  7561                   -jne 0x402e5c
    if (!cpu.flags.zf)
    {
        goto L_0x00402e5c;
    }
    // 00402dfb  83ff20                 +cmp edi, 0x20
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
    // 00402dfe  7d2b                   -jge 0x402e2b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402e2b;
    }
    // 00402e00  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00402e05  8bcf                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00402e07  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 00402e09  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00402e0c  8d7c3804               -lea edi, [eax + edi + 4]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edi * 1);
    // 00402e10  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 00402e12  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00402e15  235c8844               +and ebx, dword ptr [eax + ecx*4 + 0x44]
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.ecx * 4)))));
    // 00402e19  895c8844               -mov dword ptr [eax + ecx*4 + 0x44], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.ecx * 4) = cpu.ebx;
    // 00402e1d  fe0f                   +dec byte ptr [edi]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.edi);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 00402e1f  7538                   -jne 0x402e59
    if (!cpu.flags.zf)
    {
        goto L_0x00402e59;
    }
    // 00402e21  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402e24  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00402e27  210b                   +and dword ptr [ebx], ecx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebx) &= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00402e29  eb31                   -jmp 0x402e5c
    goto L_0x00402e5c;
L_0x00402e2b:
    // 00402e2b  8d4fe0                 -lea ecx, [edi - 0x20]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-32) /* -0x20 */);
    // 00402e2e  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00402e33  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 00402e35  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00402e38  8d7c3804               -lea edi, [eax + edi + 4]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edi * 1);
    // 00402e3c  8d8c88c4000000         -lea ecx, [eax + ecx*4 + 0xc4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.ecx * 4);
    // 00402e43  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 00402e45  2119                   +and dword ptr [ecx], ebx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ecx) &= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00402e47  fe0f                   +dec byte ptr [edi]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.edi);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 00402e49  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00402e4c  750b                   -jne 0x402e59
    if (!cpu.flags.zf)
    {
        goto L_0x00402e59;
    }
    // 00402e4e  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00402e51  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00402e54  214b04                 +and dword ptr [ebx + 4], ecx
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) &= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00402e57  eb03                   -jmp 0x402e5c
    goto L_0x00402e5c;
L_0x00402e59:
    // 00402e59  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
L_0x00402e5c:
    // 00402e5c  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00402e5f  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00402e62  837df800               +cmp dword ptr [ebp - 8], 0
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
    // 00402e66  897904                 -mov dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00402e69  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00402e6c  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00402e6f  897908                 -mov dword ptr [ecx + 8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00402e72  0f8494000000           -je 0x402f0c
    if (cpu.flags.zf)
    {
        goto L_0x00402f0c;
    }
    // 00402e78  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00402e7b  8b7cf104               -mov edi, dword ptr [ecx + esi*8 + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 8);
    // 00402e7f  8d0cf1                 -lea ecx, [ecx + esi*8]
    cpu.ecx = x86::reg32(cpu.ecx + cpu.esi * 8);
    // 00402e82  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00402e85  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00402e88  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00402e8b  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00402e8e  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00402e91  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00402e94  3b4a08                 +cmp ecx, dword ptr [edx + 8]
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
    // 00402e97  7564                   -jne 0x402efd
    if (!cpu.flags.zf)
    {
        goto L_0x00402efd;
    }
    // 00402e99  8a4c0604               -mov cl, byte ptr [esi + eax + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00402e9d  83fe20                 +cmp esi, 0x20
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
    // 00402ea0  884d0b                 -mov byte ptr [ebp + 0xb], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(11) /* 0xb */) = cpu.cl;
    // 00402ea3  7d29                   -jge 0x402ece
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402ece;
    }
    // 00402ea5  fec1                   -inc cl
    (cpu.cl)++;
    // 00402ea7  807d0b00               +cmp byte ptr [ebp + 0xb], 0
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
    // 00402eab  884c0604               -mov byte ptr [esi + eax + 4], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.cl;
    // 00402eaf  750b                   -jne 0x402ebc
    if (!cpu.flags.zf)
    {
        goto L_0x00402ebc;
    }
    // 00402eb1  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 00402eb6  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00402eb8  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 00402eba  093b                   -or dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) |= x86::reg32(x86::sreg32(cpu.edi));
L_0x00402ebc:
    // 00402ebc  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 00402ec1  8bce                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00402ec3  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 00402ec5  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00402ec8  097c8844               +or dword ptr [eax + ecx*4 + 0x44], edi
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */ + cpu.ecx * 4) |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00402ecc  eb2f                   -jmp 0x402efd
    goto L_0x00402efd;
L_0x00402ece:
    // 00402ece  fec1                   -inc cl
    (cpu.cl)++;
    // 00402ed0  807d0b00               +cmp byte ptr [ebp + 0xb], 0
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
    // 00402ed4  884c0604               -mov byte ptr [esi + eax + 4], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.cl;
    // 00402ed8  750d                   -jne 0x402ee7
    if (!cpu.flags.zf)
    {
        goto L_0x00402ee7;
    }
    // 00402eda  8d4ee0                 -lea ecx, [esi - 0x20]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 00402edd  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
    // 00402ee2  d3ef                   -shr edi, cl
    cpu.edi >>= cpu.cl % 32;
    // 00402ee4  097b04                 -or dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.edi));
L_0x00402ee7:
    // 00402ee7  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00402eea  8dbc88c4000000         -lea edi, [eax + ecx*4 + 0xc4]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(196) /* 0xc4 */ + cpu.ecx * 4);
    // 00402ef1  8d4ee0                 -lea ecx, [esi - 0x20]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 00402ef4  be00000080             -mov esi, 0x80000000
    cpu.esi = 2147483648 /*0x80000000*/;
    // 00402ef9  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 00402efb  0937                   -or dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) |= x86::reg32(x86::sreg32(cpu.esi));
L_0x00402efd:
    // 00402efd  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x00402f00:
    // 00402f00  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00402f02  740b                   -je 0x402f0f
    if (cpu.flags.zf)
    {
        goto L_0x00402f0f;
    }
    // 00402f04  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00402f06  894c11fc               -mov dword ptr [ecx + edx - 4], ecx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edx * 1) = cpu.ecx;
    // 00402f0a  eb03                   -jmp 0x402f0f
    goto L_0x00402f0f;
L_0x00402f0c:
    // 00402f0c  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x00402f0f:
    // 00402f0f  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00402f12  03d1                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00402f14  8d4e01                 -lea ecx, [esi + 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00402f17  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00402f19  894c32fc               -mov dword ptr [edx + esi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1) = cpu.ecx;
    // 00402f1d  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00402f20  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00402f22  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00402f24  8d7901                 -lea edi, [ecx + 1]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00402f27  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00402f29  751a                   -jne 0x402f45
    if (!cpu.flags.zf)
    {
        goto L_0x00402f45;
    }
    // 00402f2b  3b1d60564000           +cmp ebx, dword ptr [0x405660]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4216416) /* 0x405660 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402f31  7512                   -jne 0x402f45
    if (!cpu.flags.zf)
    {
        goto L_0x00402f45;
    }
    // 00402f33  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00402f36  3b0d58564000           +cmp ecx, dword ptr [0x405658]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4216408) /* 0x405658 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402f3c  7507                   -jne 0x402f45
    if (!cpu.flags.zf)
    {
        goto L_0x00402f45;
    }
    // 00402f3e  83256056400000         -and dword ptr [0x405660], 0
    app->getMemory<x86::reg32>(x86::reg32(4216416) /* 0x405660 */) &= x86::reg32(x86::sreg32(0 /*0x0*/));
L_0x00402f45:
    // 00402f45  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00402f48  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00402f4a  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
L_0x00402f4d:
    // 00402f4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402f4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402f4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402f50  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402f51  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_402f52(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402f52  a164564000             -mov eax, dword ptr [0x405664]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216420) /* 0x405664 */);
    // 00402f57  8b0d54564000           -mov ecx, dword ptr [0x405654]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4216404) /* 0x405654 */);
    // 00402f5d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402f5e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402f5f  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00402f61  3bc1                   +cmp eax, ecx
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
    // 00402f63  7530                   -jne 0x402f95
    if (!cpu.flags.zf)
    {
        goto L_0x00402f95;
    }
    // 00402f65  8d448950               -lea eax, [ecx + ecx*4 + 0x50]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(80) /* 0x50 */ + cpu.ecx * 4);
    // 00402f69  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00402f6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00402f6d  ff3568564000           -push dword ptr [0x405668]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216424) /* 0x405668 */);
    cpu.esp -= 4;
    // 00402f73  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402f74  ff3588584000           -push dword ptr [0x405888]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216968) /* 0x405888 */);
    cpu.esp -= 4;
    // 00402f7a  ff1534404000           -call dword ptr [0x404034]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210740) /* 0x404034 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00402f80  3bc7                   +cmp eax, edi
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
    // 00402f82  7461                   -je 0x402fe5
    if (cpu.flags.zf)
    {
        goto L_0x00402fe5;
    }
    // 00402f84  83055456400010         -add dword ptr [0x405654], 0x10
    (app->getMemory<x86::reg32>(x86::reg32(4216404) /* 0x405654 */)) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00402f8b  a368564000             -mov dword ptr [0x405668], eax
    app->getMemory<x86::reg32>(x86::reg32(4216424) /* 0x405668 */) = cpu.eax;
    // 00402f90  a164564000             -mov eax, dword ptr [0x405664]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216420) /* 0x405664 */);
L_0x00402f95:
    // 00402f95  8b0d68564000           -mov ecx, dword ptr [0x405668]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4216424) /* 0x405668 */);
    // 00402f9b  68c4410000             -push 0x41c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 16836 /*0x41c4*/;
    cpu.esp -= 4;
    // 00402fa0  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00402fa2  8d0480                 -lea eax, [eax + eax*4]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 4);
    // 00402fa5  ff3588584000           -push dword ptr [0x405888]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216968) /* 0x405888 */);
    cpu.esp -= 4;
    // 00402fab  8d3481                 -lea esi, [ecx + eax*4]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 4);
    // 00402fae  ff1588404000           -call dword ptr [0x404088]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210824) /* 0x404088 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00402fb4  3bc7                   +cmp eax, edi
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
    // 00402fb6  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00402fb9  742a                   -je 0x402fe5
    if (cpu.flags.zf)
    {
        goto L_0x00402fe5;
    }
    // 00402fbb  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00402fbd  6800200000             -push 0x2000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8192 /*0x2000*/;
    cpu.esp -= 4;
    // 00402fc2  6800001000             -push 0x100000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1048576 /*0x100000*/;
    cpu.esp -= 4;
    // 00402fc7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402fc8  ff159c404000           -call dword ptr [0x40409c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210844) /* 0x40409c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00402fce  3bc7                   +cmp eax, edi
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
    // 00402fd0  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00402fd3  7514                   -jne 0x402fe9
    if (!cpu.flags.zf)
    {
        goto L_0x00402fe9;
    }
    // 00402fd5  ff7610                 -push dword ptr [esi + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00402fd8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402fd9  ff3588584000           -push dword ptr [0x405888]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(4216968) /* 0x405888 */);
    cpu.esp -= 4;
    // 00402fdf  ff156c404000           -call dword ptr [0x40406c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210796) /* 0x40406c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x00402fe5:
    // 00402fe5  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00402fe7  eb17                   -jmp 0x403000
    goto L_0x00403000;
L_0x00402fe9:
    // 00402fe9  834e08ff               -or dword ptr [esi + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402fed  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00402fef  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00402ff2  ff0564564000           -inc dword ptr [0x405664]
    (app->getMemory<x86::reg32>(x86::reg32(4216420) /* 0x405664 */))++;
    // 00402ff8  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00402ffb  8308ff                 -or dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00402ffe  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00403000:
    // 00403000  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403001  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403002  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403003(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403003  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403004  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403006  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403007  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0040300a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040300b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040300c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040300d  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00403010  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00403013  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00403015:
    // 00403015  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403017  7c05                   -jl 0x40301e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040301e;
    }
    // 00403019  d1e0                   +shl eax, 1
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
    // 0040301b  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040301c  ebf7                   -jmp 0x403015
    goto L_0x00403015;
L_0x0040301e:
    // 0040301e  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00403020  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 00403022  69c004020000           -imul eax, eax, 0x204
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(516 /*0x204*/)));
    // 00403028  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403029  8d843044010000         -lea eax, [eax + esi + 0x144]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(324) /* 0x144 */ + cpu.esi * 1);
    // 00403030  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x00403033:
    // 00403033  894008                 -mov dword ptr [eax + 8], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00403036  894004                 -mov dword ptr [eax + 4], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00403039  83c008                 +add eax, 8
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
    // 0040303c  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040303d  75f4                   -jne 0x403033
    if (!cpu.flags.zf)
    {
        goto L_0x00403033;
    }
    // 0040303f  8bfb                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00403041  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00403043  c1e70f                 -shl edi, 0xf
    cpu.edi <<= 15 /*0xf*/ % 32;
    // 00403046  03790c                 -add edi, dword ptr [ecx + 0xc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 00403049  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 0040304e  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 00403053  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403054  ff159c404000           -call dword ptr [0x40409c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210844) /* 0x40409c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040305a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040305c  7508                   -jne 0x403066
    if (!cpu.flags.zf)
    {
        goto L_0x00403066;
    }
    // 0040305e  83c8ff                 +or eax, 0xffffffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00403061  e993000000             -jmp 0x4030f9
    goto L_0x004030f9;
L_0x00403066:
    // 00403066  8d9700700000           -lea edx, [edi + 0x7000]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(28672) /* 0x7000 */);
    // 0040306c  3bfa                   +cmp edi, edx
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
    // 0040306e  773c                   -ja 0x4030ac
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004030ac;
    }
    // 00403070  8d4710                 -lea eax, [edi + 0x10]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
L_0x00403073:
    // 00403073  8348f8ff               -or dword ptr [eax - 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00403077  8388ec0f0000ff         -or dword ptr [eax + 0xfec], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4076) /* 0xfec */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040307e  8d88fc0f0000           -lea ecx, [eax + 0xffc]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4092) /* 0xffc */);
    // 00403084  c740fcf00f0000         -mov dword ptr [eax - 4], 0xff0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = 4080 /*0xff0*/;
    // 0040308b  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0040308d  8d88fcefffff           -lea ecx, [eax - 0x1004]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4100) /* -0x1004 */);
    // 00403093  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00403096  c780e80f0000f00f0000   -mov dword ptr [eax + 0xfe8], 0xff0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4072) /* 0xfe8 */) = 4080 /*0xff0*/;
    // 004030a0  0500100000             -add eax, 0x1000
    (cpu.eax) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 004030a5  8d48f0                 -lea ecx, [eax - 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
    // 004030a8  3bca                   +cmp ecx, edx
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
    // 004030aa  76c7                   -jbe 0x403073
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00403073;
    }
L_0x004030ac:
    // 004030ac  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004030af  8d4f0c                 -lea ecx, [edi + 0xc]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004030b2  05f8010000             -add eax, 0x1f8
    (cpu.eax) += x86::reg32(x86::sreg32(504 /*0x1f8*/));
    // 004030b7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004030b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004030ba  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004030bd  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004030c0  8d4a0c                 -lea ecx, [edx + 0xc]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004030c3  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004030c6  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004030c9  83649e4400             -and dword ptr [esi + ebx*4 + 0x44], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */ + cpu.ebx * 4) &= x86::reg32(x86::sreg32(0 /*0x0*/));
    // 004030ce  89bc9ec4000000         -mov dword ptr [esi + ebx*4 + 0xc4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(196) /* 0xc4 */ + cpu.ebx * 4) = cpu.edi;
    // 004030d5  8a4643                 -mov al, byte ptr [esi + 0x43]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(67) /* 0x43 */);
    // 004030d8  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004030da  fec1                   -inc cl
    (cpu.cl)++;
    // 004030dc  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004030de  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004030e1  884e43                 -mov byte ptr [esi + 0x43], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(67) /* 0x43 */) = cpu.cl;
    // 004030e4  7503                   -jne 0x4030e9
    if (!cpu.flags.zf)
    {
        goto L_0x004030e9;
    }
    // 004030e6  097804                 -or dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.edi));
L_0x004030e9:
    // 004030e9  ba00000080             -mov edx, 0x80000000
    cpu.edx = 2147483648 /*0x80000000*/;
    // 004030ee  8bcb                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004030f0  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 004030f2  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 004030f4  215008                 -and dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) &= x86::reg32(x86::sreg32(cpu.edx));
    // 004030f7  8bc3                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004030f9:
    // 004030f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004030fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004030fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004030fc  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004030fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4030fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004030fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004030ff  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00403101  391d10564000           +cmp dword ptr [0x405610], ebx
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4216336) /* 0x405610 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403107  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403108  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403109  7542                   -jne 0x40314d
    if (!cpu.flags.zf)
    {
        goto L_0x0040314d;
    }
    // 0040310b  68fc434000             -push 0x4043fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211708 /*0x4043fc*/;
    cpu.esp -= 4;
    // 00403110  ff152c404000           -call dword ptr [0x40402c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210732) /* 0x40402c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403116  8bf8                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00403118  3bfb                   +cmp edi, ebx
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
    // 0040311a  7467                   -je 0x403183
    if (cpu.flags.zf)
    {
        goto L_0x00403183;
    }
    // 0040311c  8b3538404000           -mov esi, dword ptr [0x404038]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4210744) /* 0x404038 */);
    // 00403122  68f0434000             -push 0x4043f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211696 /*0x4043f0*/;
    cpu.esp -= 4;
    // 00403127  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403128  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040312a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040312c  a310564000             -mov dword ptr [0x405610], eax
    app->getMemory<x86::reg32>(x86::reg32(4216336) /* 0x405610 */) = cpu.eax;
    // 00403131  7450                   -je 0x403183
    if (cpu.flags.zf)
    {
        goto L_0x00403183;
    }
    // 00403133  68e0434000             -push 0x4043e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211680 /*0x4043e0*/;
    cpu.esp -= 4;
    // 00403138  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403139  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040313b  68cc434000             -push 0x4043cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211660 /*0x4043cc*/;
    cpu.esp -= 4;
    // 00403140  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403141  a314564000             -mov dword ptr [0x405614], eax
    app->getMemory<x86::reg32>(x86::reg32(4216340) /* 0x405614 */) = cpu.eax;
    // 00403146  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403148  a318564000             -mov dword ptr [0x405618], eax
    app->getMemory<x86::reg32>(x86::reg32(4216344) /* 0x405618 */) = cpu.eax;
L_0x0040314d:
    // 0040314d  a114564000             -mov eax, dword ptr [0x405614]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216340) /* 0x405614 */);
    // 00403152  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403154  7416                   -je 0x40316c
    if (cpu.flags.zf)
    {
        goto L_0x0040316c;
    }
    // 00403156  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403158  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040315a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0040315c  740e                   -je 0x40316c
    if (cpu.flags.zf)
    {
        goto L_0x0040316c;
    }
    // 0040315e  a118564000             -mov eax, dword ptr [0x405618]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216344) /* 0x405618 */);
    // 00403163  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403165  7405                   -je 0x40316c
    if (cpu.flags.zf)
    {
        goto L_0x0040316c;
    }
    // 00403167  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403168  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040316a  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0040316c:
    // 0040316c  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00403170  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00403174  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00403178  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403179  ff1510564000           -call dword ptr [0x405610]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4216336) /* 0x405610 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
L_0x0040317f:
    // 0040317f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403180  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403181  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403182  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403183:
    // 00403183  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00403185  ebf8                   -jmp 0x40317f
    goto L_0x0040317f;
}

/* align: skip  */
void Application::asm_sub_403190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403190  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00403194  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403195  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00403197  747a                   -je 0x403213
    if (cpu.flags.zf)
    {
        goto L_0x00403213;
    }
    // 00403199  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040319a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040319b  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0040319d  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004031a1  f7c603000000           +test esi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 3 /*0x3*/));
    // 004031a7  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004031ab  7507                   -jne 0x4031b4
    if (!cpu.flags.zf)
    {
        goto L_0x004031b4;
    }
    // 004031ad  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.ecx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004031b0  756f                   -jne 0x403221
    if (!cpu.flags.zf)
    {
        goto L_0x00403221;
    }
    // 004031b2  eb21                   -jmp 0x4031d5
    goto L_0x004031d5;
L_0x004031b4:
    // 004031b4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004031b6  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004031b7  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004031b9  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004031ba  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004031bb  7425                   -je 0x4031e2
    if (cpu.flags.zf)
    {
        goto L_0x004031e2;
    }
    // 004031bd  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004031bf  7429                   -je 0x4031ea
    if (cpu.flags.zf)
    {
        goto L_0x004031ea;
    }
    // 004031c1  f7c603000000           +test esi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 3 /*0x3*/));
    // 004031c7  75eb                   -jne 0x4031b4
    if (!cpu.flags.zf)
    {
        goto L_0x004031b4;
    }
    // 004031c9  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004031cb  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.ecx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004031ce  7551                   -jne 0x403221
    if (!cpu.flags.zf)
    {
        goto L_0x00403221;
    }
L_0x004031d0:
    // 004031d0  83e303                 +and ebx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004031d3  740d                   -je 0x4031e2
    if (cpu.flags.zf)
    {
        goto L_0x004031e2;
    }
L_0x004031d5:
    // 004031d5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004031d7  46                     -inc esi
    (cpu.esi)++;
    // 004031d8  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004031da  47                     -inc edi
    (cpu.edi)++;
    // 004031db  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004031dd  742f                   -je 0x40320e
    if (cpu.flags.zf)
    {
        goto L_0x0040320e;
    }
    // 004031df  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004031e0  75f3                   -jne 0x4031d5
    if (!cpu.flags.zf)
    {
        goto L_0x004031d5;
    }
L_0x004031e2:
    // 004031e2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004031e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004031e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004031e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004031e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004031ea:
    // 004031ea  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004031f0  7412                   -je 0x403204
    if (cpu.flags.zf)
    {
        goto L_0x00403204;
    }
L_0x004031f2:
    // 004031f2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004031f4  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004031f5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004031f6  0f848a000000           -je 0x403286
    if (cpu.flags.zf)
    {
        goto L_0x00403286;
    }
    // 004031fc  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 00403202  75ee                   -jne 0x4031f2
    if (!cpu.flags.zf)
    {
        goto L_0x004031f2;
    }
L_0x00403204:
    // 00403204  8bd9                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00403206  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.ecx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00403209  756c                   -jne 0x403277
    if (!cpu.flags.zf)
    {
        goto L_0x00403277;
    }
L_0x0040320b:
    // 0040320b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0040320d  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0040320e:
    // 0040320e  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040320f  75fa                   -jne 0x40320b
    if (!cpu.flags.zf)
    {
        goto L_0x0040320b;
    }
    // 00403211  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403212  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00403213:
    // 00403213  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00403217  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403218  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403219:
    // 00403219  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0040321b  83c704                 +add edi, 4
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
    // 0040321e  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040321f  74af                   -je 0x4031d0
    if (cpu.flags.zf)
    {
        goto L_0x004031d0;
    }
L_0x00403221:
    // 00403221  bafffefe7e             -mov edx, 0x7efefeff
    cpu.edx = 2130640639 /*0x7efefeff*/;
    // 00403226  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00403228  03d0                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040322a  83f0ff                 -xor eax, 0xffffffff
    cpu.eax ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0040322d  33c2                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040322f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00403231  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00403234  a900010181             +test eax, 0x81010100
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2164326656 /*0x81010100*/));
    // 00403239  74de                   -je 0x403219
    if (cpu.flags.zf)
    {
        goto L_0x00403219;
    }
    // 0040323b  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0040323d  742c                   -je 0x40326b
    if (cpu.flags.zf)
    {
        goto L_0x0040326b;
    }
    // 0040323f  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00403241  741e                   -je 0x403261
    if (cpu.flags.zf)
    {
        goto L_0x00403261;
    }
    // 00403243  f7c20000ff00           +test edx, 0xff0000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 16711680 /*0xff0000*/));
    // 00403249  740c                   -je 0x403257
    if (cpu.flags.zf)
    {
        goto L_0x00403257;
    }
    // 0040324b  f7c2000000ff           +test edx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4278190080 /*0xff000000*/));
    // 00403251  75c6                   -jne 0x403219
    if (!cpu.flags.zf)
    {
        goto L_0x00403219;
    }
    // 00403253  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 00403255  eb18                   -jmp 0x40326f
    goto L_0x0040326f;
L_0x00403257:
    // 00403257  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0040325d  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0040325f  eb0e                   -jmp 0x40326f
    goto L_0x0040326f;
L_0x00403261:
    // 00403261  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00403267  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 00403269  eb04                   -jmp 0x40326f
    goto L_0x0040326f;
L_0x0040326b:
    // 0040326b  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040326d  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
L_0x0040326f:
    // 0040326f  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00403272  33c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00403274  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00403275  740a                   -je 0x403281
    if (cpu.flags.zf)
    {
        goto L_0x00403281;
    }
L_0x00403277:
    // 00403277  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00403279:
    // 00403279  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0040327b  83c704                 +add edi, 4
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
    // 0040327e  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040327f  75f8                   -jne 0x403279
    if (!cpu.flags.zf)
    {
        goto L_0x00403279;
    }
L_0x00403281:
    // 00403281  83e303                 +and ebx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00403284  7585                   -jne 0x40320b
    if (!cpu.flags.zf)
    {
        goto L_0x0040320b;
    }
L_0x00403286:
    // 00403286  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0040328a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040328b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040328c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040328d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_40328e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040328e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040328f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403291  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00403293  6810444000             -push 0x404410
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211728 /*0x404410*/;
    cpu.esp -= 4;
    // 00403298  68d41c4000             -push 0x401cd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4201684 /*0x401cd4*/;
    cpu.esp -= 4;
    // 0040329d  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 004032a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004032a4  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 004032ab  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004032ae  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004032af  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004032b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004032b1  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 004032b4  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004032b6  393d3c564000           +cmp dword ptr [0x40563c], edi
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4216380) /* 0x40563c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004032bc  7546                   -jne 0x403304
    if (!cpu.flags.zf)
    {
        goto L_0x00403304;
    }
    // 004032be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004032bf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004032c0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004032c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004032c3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004032c4  680c444000             -push 0x40440c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211724 /*0x40440c*/;
    cpu.esp -= 4;
    // 004032c9  be00010000             -mov esi, 0x100
    cpu.esi = 256 /*0x100*/;
    // 004032ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004032cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004032d0  ff1520404000           -call dword ptr [0x404020]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210720) /* 0x404020 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004032d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004032d8  7408                   -je 0x4032e2
    if (cpu.flags.zf)
    {
        goto L_0x004032e2;
    }
    // 004032da  891d3c564000           -mov dword ptr [0x40563c], ebx
    app->getMemory<x86::reg32>(x86::reg32(4216380) /* 0x40563c */) = cpu.ebx;
    // 004032e0  eb22                   -jmp 0x403304
    goto L_0x00403304;
L_0x004032e2:
    // 004032e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004032e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004032e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004032e5  6808444000             -push 0x404408
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211720 /*0x404408*/;
    cpu.esp -= 4;
    // 004032ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004032eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004032ec  ff1530404000           -call dword ptr [0x404030]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210736) /* 0x404030 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004032f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004032f4  0f8422010000           -je 0x40341c
    if (cpu.flags.zf)
    {
        return sub_40341c(app, cpu);
    }
    // 004032fa  c7053c56400002000000   -mov dword ptr [0x40563c], 2
    app->getMemory<x86::reg32>(x86::reg32(4216380) /* 0x40563c */) = 2 /*0x2*/;
L_0x00403304:
    // 00403304  397d14                 +cmp dword ptr [ebp + 0x14], edi
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
    // 00403307  7e10                   -jle 0x403319
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00403319;
    }
    // 00403309  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0040330c  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0040330f  e89e010000             -call 0x4034b2
    cpu.esp -= 4;
    sub_4034b2(app, cpu);
    // 00403314  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403315  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403316  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x00403319:
    // 00403319  a13c564000             -mov eax, dword ptr [0x40563c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216380) /* 0x40563c */);
    // 0040331e  83f802                 +cmp eax, 2
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
    // 00403321  751d                   -jne 0x403340
    if (!cpu.flags.zf)
    {
        goto L_0x00403340;
    }
    // 00403323  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00403326  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00403329  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0040332c  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0040332f  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00403332  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00403335  ff1530404000           -call dword ptr [0x404030]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210736) /* 0x404030 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040333b  e9de000000             -jmp 0x40341e
    return sub_40341e(app, cpu);
L_0x00403340:
    // 00403340  83f801                 +cmp eax, 1
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
    // 00403343  0f85d3000000           -jne 0x40341c
    if (!cpu.flags.zf)
    {
        return sub_40341c(app, cpu);
    }
    // 00403349  397d20                 +cmp dword ptr [ebp + 0x20], edi
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
    // 0040334c  7508                   -jne 0x403356
    if (!cpu.flags.zf)
    {
        goto L_0x00403356;
    }
    // 0040334e  a134564000             -mov eax, dword ptr [0x405634]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216372) /* 0x405634 */);
    // 00403353  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x00403356:
    // 00403356  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403357  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403358  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0040335b  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0040335e  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00403361  f7d8                   +neg eax
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
    // 00403363  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00403365  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00403368  40                     -inc eax
    (cpu.eax)++;
    // 00403369  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040336a  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0040336d  ff1528404000           -call dword ptr [0x404028]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210728) /* 0x404028 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403373  8bd8                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00403375  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 00403378  3bdf                   +cmp ebx, edi
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
    // 0040337a  0f849c000000           -je 0x40341c
    if (cpu.flags.zf)
    {
        return sub_40341c(app, cpu);
    }
    // 00403380  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00403383  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 00403386  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00403389  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0040338b  e800060000             -call 0x403990
    cpu.esp -= 4;
    sub_403990(app, cpu);
    // 00403390  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00403393  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00403395  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00403398  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 0040339c  eb13                   -jmp 0x4033b1
    return sub_4033b1(app, cpu);
}

/* align: skip  */
void Application::asm_sub_40339e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040339e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004033a0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004033a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4033a2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004033a2  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004033a5  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004033a7  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 004033aa  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004033ae  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004033b1  397ddc                 +cmp dword ptr [ebp - 0x24], edi
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
    // 004033b4  7466                   -je 0x40341c
    if (cpu.flags.zf)
    {
        goto L_0x0040341c;
    }
    // 004033b6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004033b7  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 004033ba  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004033bd  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004033c0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004033c2  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004033c5  ff1528404000           -call dword ptr [0x404028]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210728) /* 0x404028 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004033cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004033cd  744d                   -je 0x40341c
    if (cpu.flags.zf)
    {
        goto L_0x0040341c;
    }
    // 004033cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004033d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004033d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004033d2  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 004033d5  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004033d8  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004033db  ff1520404000           -call dword ptr [0x404020]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210720) /* 0x404020 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004033e1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004033e3  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 004033e6  3bf7                   +cmp esi, edi
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
    // 004033e8  7432                   -je 0x40341c
    if (cpu.flags.zf)
    {
        goto L_0x0040341c;
    }
    // 004033ea  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004033ee  7440                   -je 0x403430
    if (cpu.flags.zf)
    {
        goto L_0x00403430;
    }
    // 004033f0  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 004033f3  0f84b2000000           -je 0x4034ab
    if (cpu.flags.zf)
    {
        return sub_4034ab(app, cpu);
    }
    // 004033f9  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
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
    // 004033fc  7f1e                   -jg 0x40341c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040341c;
    }
    // 004033fe  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00403401  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00403404  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403405  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 00403408  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0040340b  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0040340e  ff1520404000           -call dword ptr [0x404020]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210720) /* 0x404020 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403414  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403416  0f858f000000           -jne 0x4034ab
    if (!cpu.flags.zf)
    {
        return sub_4034ab(app, cpu);
    }
L_0x0040341c:
    // 0040341c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040341e  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 00403421  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00403424  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0040342b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403430:
    // 00403430  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00403437  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0040343a  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040343d  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0040343f  e84c050000             -call 0x403990
    cpu.esp -= 4;
    sub_403990(app, cpu);
    // 00403444  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00403447  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00403449  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0040344c  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00403450  eb12                   -jmp 0x403464
    return sub_403464(app, cpu);
}

/* align: skip  */
void Application::asm_sub_40341e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0040341e;
    // 004033a2  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004033a5  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004033a7  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 004033aa  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004033ae  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004033b1  397ddc                 +cmp dword ptr [ebp - 0x24], edi
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
    // 004033b4  7466                   -je 0x40341c
    if (cpu.flags.zf)
    {
        goto L_0x0040341c;
    }
    // 004033b6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004033b7  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 004033ba  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004033bd  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004033c0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004033c2  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004033c5  ff1528404000           -call dword ptr [0x404028]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210728) /* 0x404028 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004033cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004033cd  744d                   -je 0x40341c
    if (cpu.flags.zf)
    {
        goto L_0x0040341c;
    }
    // 004033cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004033d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004033d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004033d2  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 004033d5  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004033d8  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004033db  ff1520404000           -call dword ptr [0x404020]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210720) /* 0x404020 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004033e1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004033e3  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 004033e6  3bf7                   +cmp esi, edi
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
    // 004033e8  7432                   -je 0x40341c
    if (cpu.flags.zf)
    {
        goto L_0x0040341c;
    }
    // 004033ea  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004033ee  7440                   -je 0x403430
    if (cpu.flags.zf)
    {
        goto L_0x00403430;
    }
    // 004033f0  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 004033f3  0f84b2000000           -je 0x4034ab
    if (cpu.flags.zf)
    {
        return sub_4034ab(app, cpu);
    }
    // 004033f9  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
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
    // 004033fc  7f1e                   -jg 0x40341c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040341c;
    }
    // 004033fe  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00403401  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00403404  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403405  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 00403408  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0040340b  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0040340e  ff1520404000           -call dword ptr [0x404020]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210720) /* 0x404020 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403414  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403416  0f858f000000           -jne 0x4034ab
    if (!cpu.flags.zf)
    {
        return sub_4034ab(app, cpu);
    }
L_0x0040341c:
    // 0040341c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_entry_0x0040341e:
    // 0040341e  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 00403421  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00403424  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0040342b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403430:
    // 00403430  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00403437  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0040343a  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040343d  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0040343f  e84c050000             -call 0x403990
    cpu.esp -= 4;
    sub_403990(app, cpu);
    // 00403444  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00403447  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00403449  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0040344c  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00403450  eb12                   -jmp 0x403464
    return sub_403464(app, cpu);
}

/* align: skip  */
void Application::asm_sub_40341c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0040341c;
    // 004033a2  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004033a5  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004033a7  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 004033aa  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004033ae  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004033b1  397ddc                 +cmp dword ptr [ebp - 0x24], edi
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
    // 004033b4  7466                   -je 0x40341c
    if (cpu.flags.zf)
    {
        goto L_0x0040341c;
    }
    // 004033b6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004033b7  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 004033ba  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004033bd  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004033c0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004033c2  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004033c5  ff1528404000           -call dword ptr [0x404028]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210728) /* 0x404028 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004033cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004033cd  744d                   -je 0x40341c
    if (cpu.flags.zf)
    {
        goto L_0x0040341c;
    }
    // 004033cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004033d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004033d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004033d2  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 004033d5  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004033d8  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004033db  ff1520404000           -call dword ptr [0x404020]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210720) /* 0x404020 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004033e1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004033e3  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 004033e6  3bf7                   +cmp esi, edi
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
    // 004033e8  7432                   -je 0x40341c
    if (cpu.flags.zf)
    {
        goto L_0x0040341c;
    }
    // 004033ea  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004033ee  7440                   -je 0x403430
    if (cpu.flags.zf)
    {
        goto L_0x00403430;
    }
    // 004033f0  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 004033f3  0f84b2000000           -je 0x4034ab
    if (cpu.flags.zf)
    {
        return sub_4034ab(app, cpu);
    }
    // 004033f9  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
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
    // 004033fc  7f1e                   -jg 0x40341c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040341c;
    }
    // 004033fe  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00403401  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00403404  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403405  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 00403408  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0040340b  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0040340e  ff1520404000           -call dword ptr [0x404020]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210720) /* 0x404020 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403414  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403416  0f858f000000           -jne 0x4034ab
    if (!cpu.flags.zf)
    {
        return sub_4034ab(app, cpu);
    }
L_0x0040341c:
L_entry_0x0040341c:
    // 0040341c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040341e  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 00403421  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00403424  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0040342b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403430:
    // 00403430  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00403437  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0040343a  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040343d  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0040343f  e84c050000             -call 0x403990
    cpu.esp -= 4;
    sub_403990(app, cpu);
    // 00403444  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00403447  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00403449  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0040344c  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00403450  eb12                   -jmp 0x403464
    return sub_403464(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4033b1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004033b1;
    // 004033a2  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004033a5  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004033a7  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 004033aa  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004033ae  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
L_entry_0x004033b1:
    // 004033b1  397ddc                 +cmp dword ptr [ebp - 0x24], edi
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
    // 004033b4  7466                   -je 0x40341c
    if (cpu.flags.zf)
    {
        goto L_0x0040341c;
    }
    // 004033b6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004033b7  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 004033ba  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004033bd  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004033c0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004033c2  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004033c5  ff1528404000           -call dword ptr [0x404028]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210728) /* 0x404028 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004033cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004033cd  744d                   -je 0x40341c
    if (cpu.flags.zf)
    {
        goto L_0x0040341c;
    }
    // 004033cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004033d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004033d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004033d2  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 004033d5  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004033d8  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004033db  ff1520404000           -call dword ptr [0x404020]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210720) /* 0x404020 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004033e1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004033e3  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 004033e6  3bf7                   +cmp esi, edi
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
    // 004033e8  7432                   -je 0x40341c
    if (cpu.flags.zf)
    {
        goto L_0x0040341c;
    }
    // 004033ea  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004033ee  7440                   -je 0x403430
    if (cpu.flags.zf)
    {
        goto L_0x00403430;
    }
    // 004033f0  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 004033f3  0f84b2000000           -je 0x4034ab
    if (cpu.flags.zf)
    {
        return sub_4034ab(app, cpu);
    }
    // 004033f9  3b751c                 +cmp esi, dword ptr [ebp + 0x1c]
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
    // 004033fc  7f1e                   -jg 0x40341c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040341c;
    }
    // 004033fe  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00403401  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00403404  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403405  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 00403408  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0040340b  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0040340e  ff1520404000           -call dword ptr [0x404020]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210720) /* 0x404020 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403414  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403416  0f858f000000           -jne 0x4034ab
    if (!cpu.flags.zf)
    {
        return sub_4034ab(app, cpu);
    }
L_0x0040341c:
    // 0040341c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040341e  8d65c8                 -lea esp, [ebp - 0x38]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 00403421  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00403424  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 0040342b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403430:
    // 00403430  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00403437  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0040343a  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040343d  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0040343f  e84c050000             -call 0x403990
    cpu.esp -= 4;
    sub_403990(app, cpu);
    // 00403444  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00403447  8bdc                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00403449  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 0040344c  834dfcff               +or dword ptr [ebp - 4], 0xffffffff
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/))));
    // 00403450  eb12                   -jmp 0x403464
    return sub_403464(app, cpu);
}

/* align: skip  */
void Application::asm_sub_403452(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403452  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00403454  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403455  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403456(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403456  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00403459  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0040345b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040345d  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00403461  8b75d8                 -mov esi, dword ptr [ebp - 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00403464  3bdf                   +cmp ebx, edi
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
    // 00403466  74b4                   -je 0x40341c
    if (cpu.flags.zf)
    {
        return sub_40341c(app, cpu);
    }
    // 00403468  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403469  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040346a  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0040346d  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 00403470  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00403473  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00403476  ff1520404000           -call dword ptr [0x404020]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210720) /* 0x404020 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040347c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040347e  749c                   -je 0x40341c
    if (cpu.flags.zf)
    {
        return sub_40341c(app, cpu);
    }
    // 00403480  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 00403483  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403484  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403485  7504                   -jne 0x40348b
    if (!cpu.flags.zf)
    {
        goto L_0x0040348b;
    }
    // 00403487  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403488  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403489  eb06                   -jmp 0x403491
    goto L_0x00403491;
L_0x0040348b:
    // 0040348b  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0040348e  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
L_0x00403491:
    // 00403491  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403492  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403493  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 00403498  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0040349b  ff1564404000           -call dword ptr [0x404064]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210788) /* 0x404064 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004034a1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004034a3  3bf7                   +cmp esi, edi
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
    // 004034a5  0f8471ffffff           -je 0x40341c
    if (cpu.flags.zf)
    {
        return sub_40341c(app, cpu);
    }
    // 004034ab  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004034ad  e96cffffff             -jmp 0x40341e
    return sub_40341e(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4034ab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004034ab;
    // 00403456  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00403459  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0040345b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040345d  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00403461  8b75d8                 -mov esi, dword ptr [ebp - 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00403464  3bdf                   +cmp ebx, edi
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
    // 00403466  74b4                   -je 0x40341c
    if (cpu.flags.zf)
    {
        return sub_40341c(app, cpu);
    }
    // 00403468  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403469  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040346a  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0040346d  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 00403470  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00403473  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00403476  ff1520404000           -call dword ptr [0x404020]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210720) /* 0x404020 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040347c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040347e  749c                   -je 0x40341c
    if (cpu.flags.zf)
    {
        return sub_40341c(app, cpu);
    }
    // 00403480  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 00403483  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403484  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403485  7504                   -jne 0x40348b
    if (!cpu.flags.zf)
    {
        goto L_0x0040348b;
    }
    // 00403487  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403488  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403489  eb06                   -jmp 0x403491
    goto L_0x00403491;
L_0x0040348b:
    // 0040348b  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0040348e  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
L_0x00403491:
    // 00403491  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403492  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403493  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 00403498  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0040349b  ff1564404000           -call dword ptr [0x404064]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210788) /* 0x404064 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004034a1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004034a3  3bf7                   +cmp esi, edi
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
    // 004034a5  0f8471ffffff           -je 0x40341c
    if (cpu.flags.zf)
    {
        return sub_40341c(app, cpu);
    }
L_entry_0x004034ab:
    // 004034ab  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004034ad  e96cffffff             -jmp 0x40341e
    return sub_40341e(app, cpu);
}

/* align: skip  */
void Application::asm_sub_403464(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00403464;
    // 00403456  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00403459  33ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0040345b  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040345d  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00403461  8b75d8                 -mov esi, dword ptr [ebp - 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
L_entry_0x00403464:
    // 00403464  3bdf                   +cmp ebx, edi
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
    // 00403466  74b4                   -je 0x40341c
    if (cpu.flags.zf)
    {
        return sub_40341c(app, cpu);
    }
    // 00403468  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403469  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040346a  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0040346d  ff75dc                 -push dword ptr [ebp - 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    cpu.esp -= 4;
    // 00403470  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00403473  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00403476  ff1520404000           -call dword ptr [0x404020]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210720) /* 0x404020 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040347c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040347e  749c                   -je 0x40341c
    if (cpu.flags.zf)
    {
        return sub_40341c(app, cpu);
    }
    // 00403480  397d1c                 +cmp dword ptr [ebp + 0x1c], edi
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
    // 00403483  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403484  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403485  7504                   -jne 0x40348b
    if (!cpu.flags.zf)
    {
        goto L_0x0040348b;
    }
    // 00403487  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403488  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403489  eb06                   -jmp 0x403491
    goto L_0x00403491;
L_0x0040348b:
    // 0040348b  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0040348e  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
L_0x00403491:
    // 00403491  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403492  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403493  6820020000             -push 0x220
    app->getMemory<x86::reg32>(cpu.esp-4) = 544 /*0x220*/;
    cpu.esp -= 4;
    // 00403498  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0040349b  ff1564404000           -call dword ptr [0x404064]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210788) /* 0x404064 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004034a1  8bf0                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004034a3  3bf7                   +cmp esi, edi
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
    // 004034a5  0f8471ffffff           -je 0x40341c
    if (cpu.flags.zf)
    {
        return sub_40341c(app, cpu);
    }
    // 004034ab  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004034ad  e96cffffff             -jmp 0x40341e
    return sub_40341e(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4034b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004034b2  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004034b6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004034ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004034bc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004034bd  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004034c0  740d                   -je 0x4034cf
    if (cpu.flags.zf)
    {
        goto L_0x004034cf;
    }
L_0x004034c2:
    // 004034c2  803800                 +cmp byte ptr [eax], 0
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
    // 004034c5  7408                   -je 0x4034cf
    if (cpu.flags.zf)
    {
        goto L_0x004034cf;
    }
    // 004034c7  40                     -inc eax
    (cpu.eax)++;
    // 004034c8  8bf1                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004034ca  49                     -dec ecx
    (cpu.ecx)--;
    // 004034cb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004034cd  75f3                   -jne 0x4034c2
    if (!cpu.flags.zf)
    {
        goto L_0x004034c2;
    }
L_0x004034cf:
    // 004034cf  803800                 +cmp byte ptr [eax], 0
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
    // 004034d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004034d3  7505                   -jne 0x4034da
    if (!cpu.flags.zf)
    {
        goto L_0x004034da;
    }
    // 004034d5  2b442404               -sub eax, dword ptr [esp + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004034d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004034da:
    // 004034da  8bc2                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004034dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4034dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004034dd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004034de  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004034e0  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004034e2  6828444000             -push 0x404428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211752 /*0x404428*/;
    cpu.esp -= 4;
    // 004034e7  68d41c4000             -push 0x401cd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4201684 /*0x401cd4*/;
    cpu.esp -= 4;
    // 004034ec  64a100000000           -mov eax, dword ptr fs:[0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs);
    // 004034f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004034f3  64892500000000         -mov dword ptr fs:[0], esp
    app->getMemory<x86::reg32>(cpu.efs) = cpu.esp;
    // 004034fa  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004034fd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004034fe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004034ff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403500  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 00403503  a140564000             -mov eax, dword ptr [0x405640]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216384) /* 0x405640 */);
    // 00403508  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040350a  3bc3                   +cmp eax, ebx
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
    // 0040350c  753e                   -jne 0x40354c
    if (!cpu.flags.zf)
    {
        goto L_0x0040354c;
    }
    // 0040350e  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00403511  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403512  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00403514  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403515  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403516  680c444000             -push 0x40440c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211724 /*0x40440c*/;
    cpu.esp -= 4;
    // 0040351b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040351c  ff1524404000           -call dword ptr [0x404024]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210724) /* 0x404024 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403522  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403524  7404                   -je 0x40352a
    if (cpu.flags.zf)
    {
        goto L_0x0040352a;
    }
    // 00403526  8bc6                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00403528  eb1d                   -jmp 0x403547
    goto L_0x00403547;
L_0x0040352a:
    // 0040352a  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0040352d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040352e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040352f  6808444000             -push 0x404408
    app->getMemory<x86::reg32>(cpu.esp-4) = 4211720 /*0x404408*/;
    cpu.esp -= 4;
    // 00403534  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403535  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403536  ff151c404000           -call dword ptr [0x40401c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210716) /* 0x40401c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 0040353c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040353e  0f84ce000000           -je 0x403612
    if (cpu.flags.zf)
    {
        return sub_403612(app, cpu);
    }
    // 00403544  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00403546  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00403547:
    // 00403547  a340564000             -mov dword ptr [0x405640], eax
    app->getMemory<x86::reg32>(x86::reg32(4216384) /* 0x405640 */) = cpu.eax;
L_0x0040354c:
    // 0040354c  83f802                 +cmp eax, 2
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
    // 0040354f  7524                   -jne 0x403575
    if (!cpu.flags.zf)
    {
        goto L_0x00403575;
    }
    // 00403551  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00403554  3bc3                   +cmp eax, ebx
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
    // 00403556  7505                   -jne 0x40355d
    if (!cpu.flags.zf)
    {
        goto L_0x0040355d;
    }
    // 00403558  a124564000             -mov eax, dword ptr [0x405624]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216356) /* 0x405624 */);
L_0x0040355d:
    // 0040355d  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00403560  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00403563  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00403566  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00403569  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040356a  ff151c404000           -call dword ptr [0x40401c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210716) /* 0x40401c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403570  e99f000000             -jmp 0x403614
    return sub_403614(app, cpu);
L_0x00403575:
    // 00403575  83f801                 +cmp eax, 1
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
    // 00403578  0f8594000000           -jne 0x403612
    if (!cpu.flags.zf)
    {
        return sub_403612(app, cpu);
    }
    // 0040357e  395d18                 +cmp dword ptr [ebp + 0x18], ebx
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
    // 00403581  7508                   -jne 0x40358b
    if (!cpu.flags.zf)
    {
        goto L_0x0040358b;
    }
    // 00403583  a134564000             -mov eax, dword ptr [0x405634]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216372) /* 0x405634 */);
    // 00403588  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0040358b:
    // 0040358b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040358c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040358d  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00403590  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00403593  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00403596  f7d8                   +neg eax
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
    // 00403598  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0040359a  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040359d  40                     -inc eax
    (cpu.eax)++;
    // 0040359e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040359f  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004035a2  ff1528404000           -call dword ptr [0x404028]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210728) /* 0x404028 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004035a8  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004035ab  3bc3                   +cmp eax, ebx
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
    // 004035ad  7463                   -je 0x403612
    if (cpu.flags.zf)
    {
        return sub_403612(app, cpu);
    }
    // 004035af  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004035b2  8d3c00                 -lea edi, [eax + eax]
    cpu.edi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004035b5  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004035b7  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004035ba  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004035bc  e8cf030000             -call 0x403990
    cpu.esp -= 4;
    sub_403990(app, cpu);
    // 004035c1  8965e8                 -mov dword ptr [ebp - 0x18], esp
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.esp;
    // 004035c4  8bf4                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004035c6  8975dc                 -mov dword ptr [ebp - 0x24], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.esi;
    // 004035c9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004035ca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004035cb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004035cc  e8ef030000             -call 0x4039c0
    cpu.esp -= 4;
    sub_4039c0(app, cpu);
    // 004035d1  83c40c                 +add esp, 0xc
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
    // 004035d4  eb0b                   -jmp 0x4035e1
    return sub_4035e1(app, cpu);
}

/* align: skip  */
void Application::asm_sub_4035d6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004035d6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004035d8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4035da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004035da  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004035dd  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004035df  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004035e1  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004035e5  3bf3                   +cmp esi, ebx
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
    // 004035e7  7429                   -je 0x403612
    if (cpu.flags.zf)
    {
        goto L_0x00403612;
    }
    // 004035e9  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 004035ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004035ed  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004035f0  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004035f3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004035f5  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004035f8  ff1528404000           -call dword ptr [0x404028]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210728) /* 0x404028 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004035fe  3bc3                   +cmp eax, ebx
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
    // 00403600  7410                   -je 0x403612
    if (cpu.flags.zf)
    {
        goto L_0x00403612;
    }
    // 00403602  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00403605  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403606  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403607  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0040360a  ff1524404000           -call dword ptr [0x404024]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210724) /* 0x404024 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403610  eb02                   -jmp 0x403614
    goto L_0x00403614;
L_0x00403612:
    // 00403612  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00403614:
    // 00403614  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00403617  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0040361a  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00403621  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403622  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403623  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403624  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403625  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403614(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00403614;
    // 004035da  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004035dd  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004035df  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004035e1  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004035e5  3bf3                   +cmp esi, ebx
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
    // 004035e7  7429                   -je 0x403612
    if (cpu.flags.zf)
    {
        goto L_0x00403612;
    }
    // 004035e9  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 004035ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004035ed  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004035f0  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004035f3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004035f5  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004035f8  ff1528404000           -call dword ptr [0x404028]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210728) /* 0x404028 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004035fe  3bc3                   +cmp eax, ebx
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
    // 00403600  7410                   -je 0x403612
    if (cpu.flags.zf)
    {
        goto L_0x00403612;
    }
    // 00403602  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00403605  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403606  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403607  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0040360a  ff1524404000           -call dword ptr [0x404024]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210724) /* 0x404024 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403610  eb02                   -jmp 0x403614
    goto L_0x00403614;
L_0x00403612:
    // 00403612  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00403614:
L_entry_0x00403614:
    // 00403614  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00403617  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0040361a  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00403621  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403622  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403623  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403624  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403625  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403612(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00403612;
    // 004035da  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004035dd  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004035df  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004035e1  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004035e5  3bf3                   +cmp esi, ebx
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
    // 004035e7  7429                   -je 0x403612
    if (cpu.flags.zf)
    {
        goto L_0x00403612;
    }
    // 004035e9  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 004035ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004035ed  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004035f0  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004035f3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004035f5  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004035f8  ff1528404000           -call dword ptr [0x404028]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210728) /* 0x404028 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004035fe  3bc3                   +cmp eax, ebx
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
    // 00403600  7410                   -je 0x403612
    if (cpu.flags.zf)
    {
        goto L_0x00403612;
    }
    // 00403602  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00403605  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403606  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403607  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0040360a  ff1524404000           -call dword ptr [0x404024]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210724) /* 0x404024 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403610  eb02                   -jmp 0x403614
    goto L_0x00403614;
L_0x00403612:
L_entry_0x00403612:
    // 00403612  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00403614:
    // 00403614  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00403617  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0040361a  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00403621  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403622  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403623  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403624  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403625  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4035e1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004035e1;
    // 004035da  8b65e8                 -mov esp, dword ptr [ebp - 0x18]
    cpu.esp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004035dd  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004035df  33f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_entry_0x004035e1:
    // 004035e1  834dfcff               -or dword ptr [ebp - 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004035e5  3bf3                   +cmp esi, ebx
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
    // 004035e7  7429                   -je 0x403612
    if (cpu.flags.zf)
    {
        goto L_0x00403612;
    }
    // 004035e9  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 004035ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004035ed  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004035f0  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004035f3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004035f5  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004035f8  ff1528404000           -call dword ptr [0x404028]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210728) /* 0x404028 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 004035fe  3bc3                   +cmp eax, ebx
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
    // 00403600  7410                   -je 0x403612
    if (cpu.flags.zf)
    {
        goto L_0x00403612;
    }
    // 00403602  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00403605  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403606  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403607  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0040360a  ff1524404000           -call dword ptr [0x404024]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4210724) /* 0x404024 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403610  eb02                   -jmp 0x403614
    goto L_0x00403614;
L_0x00403612:
    // 00403612  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00403614:
    // 00403614  8d65cc                 -lea esp, [ebp - 0x34]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00403617  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0040361a  64890d00000000         -mov dword ptr fs:[0], ecx
    app->getMemory<x86::reg32>(cpu.efs) = cpu.ecx;
    // 00403621  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403622  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403623  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403624  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403625  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403626(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403626  a148564000             -mov eax, dword ptr [0x405648]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4216392) /* 0x405648 */);
    // 0040362b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040362d  740f                   -je 0x40363e
    if (cpu.flags.zf)
    {
        goto L_0x0040363e;
    }
    // 0040362f  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 00403633  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    // 00403635  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403637  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403638  7404                   -je 0x40363e
    if (cpu.flags.zf)
    {
        goto L_0x0040363e;
    }
    // 0040363a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040363c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040363d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040363e:
    // 0040363e  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403640  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00403650  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403651  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403653  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403654  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403655  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00403658  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0040365b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0040365e  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403660  8bd1                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00403662  03c6                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00403664  3bfe                   +cmp edi, esi
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
    // 00403666  7608                   -jbe 0x403670
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00403670;
    }
    // 00403668  3bf8                   +cmp edi, eax
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
    // 0040366a  0f8278010000           -jb 0x4037e8
    if (cpu.flags.cf)
    {
        goto L_0x004037e8;
    }
L_0x00403670:
    // 00403670  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 00403676  7514                   -jne 0x40368c
    if (!cpu.flags.zf)
    {
        goto L_0x0040368c;
    }
    // 00403678  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0040367b  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040367e  83f908                 +cmp ecx, 8
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
    // 00403681  7229                   -jb 0x4036ac
    if (cpu.flags.cf)
    {
        goto L_0x004036ac;
    }
    // 00403683  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00403685  ff249598374000         -jmp dword ptr [edx*4 + 0x403798]
    cpu.ip = app->getMemory<x86::reg32>(4208536 + cpu.edx * 4); goto dynamic_jump;
L_0x0040368c:
    // 0040368c  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0040368e  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00403693  83e904                 +sub ecx, 4
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
    // 00403696  720c                   -jb 0x4036a4
    if (cpu.flags.cf)
    {
        goto L_0x004036a4;
    }
    // 00403698  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040369b  03c8                   +add ecx, eax
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
    // 0040369d  ff2485b0364000         -jmp dword ptr [eax*4 + 0x4036b0]
    cpu.ip = app->getMemory<x86::reg32>(4208304 + cpu.eax * 4); goto dynamic_jump;
L_0x004036a4:
    // 004036a4  ff248da8374000         -jmp dword ptr [ecx*4 + 0x4037a8]
    cpu.ip = app->getMemory<x86::reg32>(4208552 + cpu.ecx * 4); goto dynamic_jump;
L_0x004036ac:
    // 004036ac  ff248d2c374000         -jmp dword ptr [ecx*4 + 0x40372c]
    cpu.ip = app->getMemory<x86::reg32>(4208428 + cpu.ecx * 4); goto dynamic_jump;
  case 0x004036c0:
    // 004036c0  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004036c2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004036c4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004036c6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004036c9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004036cc  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004036cf  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004036d2  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004036d5  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004036d8  83c703                 -add edi, 3
    (cpu.edi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004036db  83f908                 +cmp ecx, 8
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
    // 004036de  72cc                   -jb 0x4036ac
    if (cpu.flags.cf)
    {
        goto L_0x004036ac;
    }
    // 004036e0  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004036e2  ff249598374000         -jmp dword ptr [edx*4 + 0x403798]
    cpu.ip = app->getMemory<x86::reg32>(4208536 + cpu.edx * 4); goto dynamic_jump;
  case 0x004036ec:
    // 004036ec  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004036ee  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004036f0  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004036f2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004036f5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004036f8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004036fb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004036fe  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00403701  83f908                 +cmp ecx, 8
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
    // 00403704  72a6                   -jb 0x4036ac
    if (cpu.flags.cf)
    {
        goto L_0x004036ac;
    }
    // 00403706  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00403708  ff249598374000         -jmp dword ptr [edx*4 + 0x403798]
    cpu.ip = app->getMemory<x86::reg32>(4208536 + cpu.edx * 4); goto dynamic_jump;
  case 0x00403710:
    // 00403710  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00403712  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00403714  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00403716  46                     -inc esi
    (cpu.esi)++;
    // 00403717  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0040371a  47                     -inc edi
    (cpu.edi)++;
    // 0040371b  83f908                 +cmp ecx, 8
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
    // 0040371e  728c                   -jb 0x4036ac
    if (cpu.flags.cf)
    {
        goto L_0x004036ac;
    }
    // 00403720  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00403722  ff249598374000         -jmp dword ptr [edx*4 + 0x403798]
    cpu.ip = app->getMemory<x86::reg32>(4208536 + cpu.edx * 4); goto dynamic_jump;
  case 0x0040374c:
    // 0040374c  8b448ee4               -mov eax, dword ptr [esi + ecx*4 - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-28) /* -0x1c */ + cpu.ecx * 4);
    // 00403750  89448fe4               -mov dword ptr [edi + ecx*4 - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-28) /* -0x1c */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00403754:
    // 00403754  8b448ee8               -mov eax, dword ptr [esi + ecx*4 - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 4);
    // 00403758  89448fe8               -mov dword ptr [edi + ecx*4 - 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0040375c:
    // 0040375c  8b448eec               -mov eax, dword ptr [esi + ecx*4 - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-20) /* -0x14 */ + cpu.ecx * 4);
    // 00403760  89448fec               -mov dword ptr [edi + ecx*4 - 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-20) /* -0x14 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00403764:
    // 00403764  8b448ef0               -mov eax, dword ptr [esi + ecx*4 - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 4);
    // 00403768  89448ff0               -mov dword ptr [edi + ecx*4 - 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0040376c:
    // 0040376c  8b448ef4               -mov eax, dword ptr [esi + ecx*4 - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-12) /* -0xc */ + cpu.ecx * 4);
    // 00403770  89448ff4               -mov dword ptr [edi + ecx*4 - 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-12) /* -0xc */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00403774:
    // 00403774  8b448ef8               -mov eax, dword ptr [esi + ecx*4 - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 4);
    // 00403778  89448ff8               -mov dword ptr [edi + ecx*4 - 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0040377c:
    // 0040377c  8b448efc               -mov eax, dword ptr [esi + ecx*4 - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 00403780  89448ffc               -mov dword ptr [edi + ecx*4 - 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.eax;
    // 00403784  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0040378b  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040378d  03f8                   +add edi, eax
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
  case 0x0040378f:
    // 0040378f  ff249598374000         -jmp dword ptr [edx*4 + 0x403798]
    cpu.ip = app->getMemory<x86::reg32>(4208536 + cpu.edx * 4); goto dynamic_jump;
  case 0x004037a8:
    // 004037a8  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004037ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037ac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037ad  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037ae  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004037b0:
    // 004037b0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004037b2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004037b4  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004037b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037b9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037ba  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004037bc:
    // 004037bc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004037be  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004037c0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004037c3  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004037c6  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004037c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037cb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037cc  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004037d0:
    // 004037d0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004037d2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004037d4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004037d7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004037da  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004037dd  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004037e0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004037e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037e5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004037e8:
    // 004037e8  8d7431fc               -lea esi, [ecx + esi - 4]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.esi * 1);
    // 004037ec  8d7c39fc               -lea edi, [ecx + edi - 4]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 004037f0  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004037f6  7524                   -jne 0x40381c
    if (!cpu.flags.zf)
    {
        goto L_0x0040381c;
    }
    // 004037f8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004037fb  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004037fe  83f908                 +cmp ecx, 8
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
    // 00403801  720d                   -jb 0x403810
    if (cpu.flags.cf)
    {
        goto L_0x00403810;
    }
    // 00403803  fd                     -std 
    cpu.flags.df = 1;
    // 00403804  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00403806  fc                     -cld 
    cpu.flags.df = 0;
    // 00403807  ff249530394000         -jmp dword ptr [edx*4 + 0x403930]
    cpu.ip = app->getMemory<x86::reg32>(4208944 + cpu.edx * 4); goto dynamic_jump;
L_0x00403810:
    // 00403810  f7d9                   +neg ecx
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
    // 00403812  ff248de0384000         -jmp dword ptr [ecx*4 + 0x4038e0]
    cpu.ip = app->getMemory<x86::reg32>(4208864 + cpu.ecx * 4); goto dynamic_jump;
L_0x0040381c:
    // 0040381c  8bc7                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0040381e  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00403823  83f904                 +cmp ecx, 4
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
    // 00403826  720c                   -jb 0x403834
    if (cpu.flags.cf)
    {
        goto L_0x00403834;
    }
    // 00403828  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040382b  2bc8                   +sub ecx, eax
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
    // 0040382d  ff248538384000         -jmp dword ptr [eax*4 + 0x403838]
    cpu.ip = app->getMemory<x86::reg32>(4208696 + cpu.eax * 4); goto dynamic_jump;
L_0x00403834:
    // 00403834  ff248d30394000         -jmp dword ptr [ecx*4 + 0x403930]
    cpu.ip = app->getMemory<x86::reg32>(4208944 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00403848:
    // 00403848  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0040384b  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040384d  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00403850  4e                     -dec esi
    (cpu.esi)--;
    // 00403851  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00403854  4f                     -dec edi
    (cpu.edi)--;
    // 00403855  83f908                 +cmp ecx, 8
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
    // 00403858  72b6                   -jb 0x403810
    if (cpu.flags.cf)
    {
        goto L_0x00403810;
    }
    // 0040385a  fd                     -std 
    cpu.flags.df = 1;
    // 0040385b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040385d  fc                     -cld 
    cpu.flags.df = 0;
    // 0040385e  ff249530394000         -jmp dword ptr [edx*4 + 0x403930]
    cpu.ip = app->getMemory<x86::reg32>(4208944 + cpu.edx * 4); goto dynamic_jump;
  case 0x00403868:
    // 00403868  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0040386b  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040386d  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00403870  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00403873  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00403876  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00403879  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040387c  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040387f  83f908                 +cmp ecx, 8
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
    // 00403882  728c                   -jb 0x403810
    if (cpu.flags.cf)
    {
        goto L_0x00403810;
    }
    // 00403884  fd                     -std 
    cpu.flags.df = 1;
    // 00403885  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00403887  fc                     -cld 
    cpu.flags.df = 0;
    // 00403888  ff249530394000         -jmp dword ptr [edx*4 + 0x403930]
    cpu.ip = app->getMemory<x86::reg32>(4208944 + cpu.edx * 4); goto dynamic_jump;
  case 0x00403890:
    // 00403890  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00403893  23d1                   -and edx, ecx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00403895  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00403898  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0040389b  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0040389e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004038a1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004038a4  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004038a7  83ee03                 -sub esi, 3
    (cpu.esi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004038aa  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004038ad  83f908                 +cmp ecx, 8
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
    // 004038b0  0f825affffff           -jb 0x403810
    if (cpu.flags.cf)
    {
        goto L_0x00403810;
    }
    // 004038b6  fd                     -std 
    cpu.flags.df = 1;
    // 004038b7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004038b9  fc                     -cld 
    cpu.flags.df = 0;
    // 004038ba  ff249530394000         -jmp dword ptr [edx*4 + 0x403930]
    cpu.ip = app->getMemory<x86::reg32>(4208944 + cpu.edx * 4); goto dynamic_jump;
  case 0x004038e4:
    // 004038e4  8b448e1c               -mov eax, dword ptr [esi + ecx*4 + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */ + cpu.ecx * 4);
    // 004038e8  89448f1c               -mov dword ptr [edi + ecx*4 + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x004038ec:
    // 004038ec  8b448e18               -mov eax, dword ptr [esi + ecx*4 + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */ + cpu.ecx * 4);
    // 004038f0  89448f18               -mov dword ptr [edi + ecx*4 + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x004038f4:
    // 004038f4  8b448e14               -mov eax, dword ptr [esi + ecx*4 + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */ + cpu.ecx * 4);
    // 004038f8  89448f14               -mov dword ptr [edi + ecx*4 + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x004038fc:
    // 004038fc  8b448e10               -mov eax, dword ptr [esi + ecx*4 + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */ + cpu.ecx * 4);
    // 00403900  89448f10               -mov dword ptr [edi + ecx*4 + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00403904:
    // 00403904  8b448e0c               -mov eax, dword ptr [esi + ecx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ecx * 4);
    // 00403908  89448f0c               -mov dword ptr [edi + ecx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x0040390c:
    // 0040390c  8b448e08               -mov eax, dword ptr [esi + ecx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    // 00403910  89448f08               -mov dword ptr [edi + ecx*4 + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4) = cpu.eax;
  [[fallthrough]];
  case 0x00403914:
    // 00403914  8b448e04               -mov eax, dword ptr [esi + ecx*4 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    // 00403918  89448f04               -mov dword ptr [edi + ecx*4 + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4) = cpu.eax;
    // 0040391c  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00403923  03f0                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00403925  03f8                   +add edi, eax
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
  case 0x00403927:
    // 00403927  ff249530394000         -jmp dword ptr [edx*4 + 0x403930]
    cpu.ip = app->getMemory<x86::reg32>(4208944 + cpu.edx * 4); goto dynamic_jump;
  case 0x00403940:
    // 00403940  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00403943  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403944  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403945  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403946  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00403948:
    // 00403948  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0040394b  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0040394e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00403951  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403952  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403953  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403954  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00403958:
    // 00403958  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0040395b  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0040395e  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00403961  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00403964  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00403967  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403968  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403969  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040396a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040396c:
    // 0040396c  8a4603                 -mov al, byte ptr [esi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0040396f  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00403972  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00403975  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00403978  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0040397b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0040397e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00403981  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403982  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403983  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403984  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::asm_sub_403990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403990  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403991  3d00100000             +cmp eax, 0x1000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403996  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0040399a  7214                   -jb 0x4039b0
    if (cpu.flags.cf)
    {
        goto L_0x004039b0;
    }
L_0x0040399c:
    // 0040399c  81e900100000           -sub ecx, 0x1000
    (cpu.ecx) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 004039a2  2d00100000             -sub eax, 0x1000
    (cpu.eax) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 004039a7  8501                   -test dword ptr [ecx], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ecx) & cpu.eax));
    // 004039a9  3d00100000             +cmp eax, 0x1000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004039ae  73ec                   -jae 0x40399c
    if (!cpu.flags.cf)
    {
        goto L_0x0040399c;
    }
L_0x004039b0:
    // 004039b0  2bc8                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004039b2  8bc4                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004039b4  8501                   -test dword ptr [ecx], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ecx) & cpu.eax));
    // 004039b6  8be1                   -mov esp, ecx
    cpu.esp = cpu.ecx;
    // 004039b8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004039ba  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004039bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004039be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_4039c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004039c0  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004039c4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004039c8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004039ca  7447                   -je 0x403a13
    if (cpu.flags.zf)
    {
        goto L_0x00403a13;
    }
    // 004039cc  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004039ce  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004039d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004039d3  8bf9                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004039d5  83fa04                 +cmp edx, 4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004039d8  722d                   -jb 0x403a07
    if (cpu.flags.cf)
    {
        goto L_0x00403a07;
    }
    // 004039da  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004039dc  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004039df  7408                   -je 0x4039e9
    if (cpu.flags.zf)
    {
        goto L_0x004039e9;
    }
    // 004039e1  2bd1                   +sub edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004039e3:
    // 004039e3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004039e5  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004039e6  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004039e7  75fa                   -jne 0x4039e3
    if (!cpu.flags.zf)
    {
        goto L_0x004039e3;
    }
L_0x004039e9:
    // 004039e9  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004039eb  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004039ee  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004039f0  8bc8                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004039f2  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004039f5  03c1                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004039f7  8bca                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004039f9  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004039fc  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = static_cast<x86::reg32&>(cpu.ecx);
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004039ff  7406                   -je 0x403a07
    if (cpu.flags.zf)
    {
        goto L_0x00403a07;
    }
    // 00403a01  f3ab                   -rep stosd dword ptr es:[edi], eax
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
    // 00403a03  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00403a05  7406                   -je 0x403a0d
    if (cpu.flags.zf)
    {
        goto L_0x00403a0d;
    }
L_0x00403a07:
    // 00403a07  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00403a09  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00403a0a  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00403a0b  75fa                   -jne 0x403a07
    if (!cpu.flags.zf)
    {
        goto L_0x00403a07;
    }
L_0x00403a0d:
    // 00403a0d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00403a11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403a12  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403a13:
    // 00403a13  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00403a17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::asm_sub_403a18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403a18  ff2570404000           -jmp dword ptr [0x404070]
    return app->dynamic_call(app->getMemory<x86::reg32>(4210800), cpu);
}

}
