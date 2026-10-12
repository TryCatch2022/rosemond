#include "menu.h"
namespace menu
{

/* align: skip  */
void Application::asm_sub_42f210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f210  8b8d18ffffff           -mov ecx, dword ptr [ebp - 0xe8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-232) /* -0xe8 */);
    // 0042f216  e9f540fdff             -jmp 0x403310
    return sub_403310(app, cpu);
}

/* align: skip  */
void Application::asm_sub_42f21b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0042f21b  b888124300             -mov eax, 0x431288
    cpu.eax = 4395656 /*0x431288*/;
    // 0042f220  e96b65ffff             -jmp 0x425790
    return sub_425790(app, cpu);
}

}
