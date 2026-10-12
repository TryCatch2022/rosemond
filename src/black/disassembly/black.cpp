#include "black.h"
#include <x86.h>
#include <winapi/wrapper.h>
#include <winapi/kernel32.h>
#include <winapi/user32.h>
#include <winapi/gdi32.h>

namespace black
{

Application::Application()
{
    registerMethod(0x00401000, {"<Application>sub_401000", &Application::sub_401000});
    registerMethod(0x00401050, {"<Application>sub_401050", &Application::sub_401050});
    registerMethod(0x004010a0, {"<Application>sub_4010a0", &Application::sub_4010a0});
    registerMethod(0x004010c0, {"<Application>sub_4010c0", &Application::sub_4010c0});
    registerMethod(0x00401130, {"<Application>sub_401130", &Application::sub_401130});
    registerMethod(0x004011a0, {"<Application>sub_4011a0", &Application::sub_4011a0});
    registerMethod(0x0040128b, {"<Application>sub_40128b", &Application::sub_40128b});
    registerMethod(0x00401296, {"<Application>sub_401296", &Application::sub_401296});
    registerMethod(0x004012bb, {"<Application>sub_4012bb", &Application::sub_4012bb});
    registerMethod(0x004012df, {"<Application>sub_4012df", &Application::sub_4012df});
    registerMethod(0x0040130c, {"<Application>sub_40130c", &Application::sub_40130c});
    registerMethod(0x0040131d, {"<Application>sub_40131d", &Application::sub_40131d});
    registerMethod(0x0040132e, {"<Application>sub_40132e", &Application::sub_40132e});
    registerMethod(0x004013c7, {"<Application>sub_4013c7", &Application::sub_4013c7});
    registerMethod(0x004013e1, {"<Application>sub_4013e1", &Application::sub_4013e1});
    registerMethod(0x00401522, {"<Application>sub_401522", &Application::sub_401522});
    registerMethod(0x00401565, {"<Application>sub_401565", &Application::sub_401565});
    registerMethod(0x004015bd, {"<Application>sub_4015bd", &Application::sub_4015bd});
    registerMethod(0x00401676, {"<Application>sub_401676", &Application::sub_401676});
    registerMethod(0x0040170f, {"<Application>sub_40170f", &Application::sub_40170f});
    registerMethod(0x004018c3, {"<Application>sub_4018c3", &Application::sub_4018c3});
    registerMethod(0x004019f5, {"<Application>sub_4019f5", &Application::sub_4019f5});
    registerMethod(0x00401ba0, {"<Application>sub_401ba0", &Application::sub_401ba0});
    registerMethod(0x00401bdc, {"<Application>sub_401bdc", &Application::sub_401bdc});
    registerMethod(0x00401bfc, {"<Application>sub_401bfc", &Application::sub_401bfc});
    registerMethod(0x00401c1e, {"<Application>sub_401c1e", &Application::sub_401c1e});
    registerMethod(0x00401cb2, {"<Application>sub_401cb2", &Application::sub_401cb2});
    registerMethod(0x00401cd4, {"<Application>sub_401cd4", &Application::sub_401cd4});
    registerMethod(0x00401d91, {"<Application>sub_401d91", &Application::sub_401d91});
    registerMethod(0x00401dac, {"<Application>sub_401dac", &Application::sub_401dac});
    registerMethod(0x00401de5, {"<Application>sub_401de5", &Application::sub_401de5});
    registerMethod(0x00401f38, {"<Application>sub_401f38", &Application::sub_401f38});
    registerMethod(0x00401f49, {"<Application>sub_401f49", &Application::sub_401f49});
    registerMethod(0x00401f7a, {"<Application>sub_401f7a", &Application::sub_401f7a});
    registerMethod(0x00402113, {"<Application>sub_402113", &Application::sub_402113});
    registerMethod(0x0040215d, {"<Application>sub_40215d", &Application::sub_40215d});
    registerMethod(0x00402190, {"<Application>sub_402190", &Application::sub_402190});
    registerMethod(0x004021b9, {"<Application>sub_4021b9", &Application::sub_4021b9});
    registerMethod(0x0040233e, {"<Application>sub_40233e", &Application::sub_40233e});
    registerMethod(0x0040235a, {"<Application>sub_40235a", &Application::sub_40235a});
    registerMethod(0x00402390, {"<Application>sub_402390", &Application::sub_402390});
    registerMethod(0x004023a0, {"<Application>sub_4023a0", &Application::sub_4023a0});
    registerMethod(0x00402401, {"<Application>sub_402401", &Application::sub_402401});
    registerMethod(0x00402480, {"<Application>sub_402480", &Application::sub_402480});
    registerMethod(0x00402492, {"<Application>sub_402492", &Application::sub_402492});
    registerMethod(0x004024be, {"<Application>sub_4024be", &Application::sub_4024be});
    registerMethod(0x00402500, {"<Application>sub_402500", &Application::sub_402500});
    registerMethod(0x00402580, {"<Application>sub_402580", &Application::sub_402580});
    registerMethod(0x004028b5, {"<Application>sub_4028b5", &Application::sub_4028b5});
    registerMethod(0x004028f3, {"<Application>sub_4028f3", &Application::sub_4028f3});
    registerMethod(0x0040291e, {"<Application>sub_40291e", &Application::sub_40291e});
    registerMethod(0x00402c49, {"<Application>sub_402c49", &Application::sub_402c49});
    registerMethod(0x00402f52, {"<Application>sub_402f52", &Application::sub_402f52});
    registerMethod(0x00403003, {"<Application>sub_403003", &Application::sub_403003});
    registerMethod(0x004030fe, {"<Application>sub_4030fe", &Application::sub_4030fe});
    registerMethod(0x00403190, {"<Application>sub_403190", &Application::sub_403190});
    registerMethod(0x0040328e, {"<Application>sub_40328e", &Application::sub_40328e});
    registerMethod(0x0040339e, {"<Application>sub_40339e", &Application::sub_40339e});
    registerMethod(0x004033a2, {"<Application>sub_4033a2", &Application::sub_4033a2});
    registerMethod(0x0040341e, {"<Application>sub_40341e", &Application::sub_40341e});
    registerMethod(0x0040341c, {"<Application>sub_40341c", &Application::sub_40341c});
    registerMethod(0x004033b1, {"<Application>sub_4033b1", &Application::sub_4033b1});
    registerMethod(0x00403452, {"<Application>sub_403452", &Application::sub_403452});
    registerMethod(0x00403456, {"<Application>sub_403456", &Application::sub_403456});
    registerMethod(0x004034ab, {"<Application>sub_4034ab", &Application::sub_4034ab});
    registerMethod(0x00403464, {"<Application>sub_403464", &Application::sub_403464});
    registerMethod(0x004034b2, {"<Application>sub_4034b2", &Application::sub_4034b2});
    registerMethod(0x004034dd, {"<Application>sub_4034dd", &Application::sub_4034dd});
    registerMethod(0x004035d6, {"<Application>sub_4035d6", &Application::sub_4035d6});
    registerMethod(0x004035da, {"<Application>sub_4035da", &Application::sub_4035da});
    registerMethod(0x00403614, {"<Application>sub_403614", &Application::sub_403614});
    registerMethod(0x00403612, {"<Application>sub_403612", &Application::sub_403612});
    registerMethod(0x004035e1, {"<Application>sub_4035e1", &Application::sub_4035e1});
    registerMethod(0x00403626, {"<Application>sub_403626", &Application::sub_403626});
    registerMethod(0x00403650, {"<Application>sub_403650", &Application::sub_403650});
    registerMethod(0x00403990, {"<Application>sub_403990", &Application::sub_403990});
    registerMethod(0x004039c0, {"<Application>sub_4039c0", &Application::sub_4039c0});
    registerMethod(0x00403a18, {"<Application>sub_403a18", &Application::sub_403a18});
    registerMethod(0x00400aad, {"<kernel32>GetCurrentProcess", &win32::Wrapper<decltype(&win32::kernel32::GetCurrentProcess), &win32::kernel32::GetCurrentProcess>::stdcall});
    registerMethod(0x00400aae, {"<kernel32>SetPriorityClass", &win32::Wrapper<decltype(&win32::kernel32::SetPriorityClass), &win32::kernel32::SetPriorityClass>::stdcall});
    registerMethod(0x00400aaf, {"<kernel32>FreeEnvironmentStringsW", &win32::Wrapper<decltype(&win32::kernel32::FreeEnvironmentStringsW), &win32::kernel32::FreeEnvironmentStringsW>::stdcall});
    registerMethod(0x00400ab0, {"<kernel32>GetEnvironmentStringsW", &win32::Wrapper<decltype(&win32::kernel32::GetEnvironmentStringsW), &win32::kernel32::GetEnvironmentStringsW>::stdcall});
    registerMethod(0x00400ab1, {"<kernel32>SetHandleCount", &win32::Wrapper<decltype(&win32::kernel32::SetHandleCount), &win32::kernel32::SetHandleCount>::stdcall});
    registerMethod(0x00400ab2, {"<kernel32>GetStringTypeA", &win32::Wrapper<decltype(&win32::kernel32::GetStringTypeA), &win32::kernel32::GetStringTypeA>::stdcall});
    registerMethod(0x00400ab3, {"<kernel32>LCMapStringW", &win32::Wrapper<decltype(&win32::kernel32::LCMapStringW), &win32::kernel32::LCMapStringW>::stdcall});
    registerMethod(0x00400ab4, {"<kernel32>GetStringTypeW", &win32::Wrapper<decltype(&win32::kernel32::GetStringTypeW), &win32::kernel32::GetStringTypeW>::stdcall});
    registerMethod(0x00400ab5, {"<kernel32>MultiByteToWideChar", &win32::Wrapper<decltype(&win32::kernel32::MultiByteToWideChar), &win32::kernel32::MultiByteToWideChar>::stdcall});
    registerMethod(0x00400ab6, {"<kernel32>LoadLibraryA", &win32::Wrapper<decltype(&win32::kernel32::LoadLibraryA), &win32::kernel32::LoadLibraryA>::stdcall});
    registerMethod(0x00400ab7, {"<kernel32>LCMapStringA", &win32::Wrapper<decltype(&win32::kernel32::LCMapStringA), &win32::kernel32::LCMapStringA>::stdcall});
    registerMethod(0x00400ab8, {"<kernel32>HeapReAlloc", &win32::Wrapper<decltype(&win32::kernel32::HeapReAlloc), &win32::kernel32::HeapReAlloc>::stdcall});
    registerMethod(0x00400ab9, {"<kernel32>GetProcAddress", &win32::Wrapper<decltype(&win32::kernel32::GetProcAddress), &win32::kernel32::GetProcAddress>::stdcall});
    registerMethod(0x00400aba, {"<kernel32>GetModuleHandleA", &win32::Wrapper<decltype(&win32::kernel32::GetModuleHandleA), &win32::kernel32::GetModuleHandleA>::stdcall});
    registerMethod(0x00400abb, {"<kernel32>GetStartupInfoA", &win32::Wrapper<decltype(&win32::kernel32::GetStartupInfoA), &win32::kernel32::GetStartupInfoA>::stdcall});
    registerMethod(0x00400abc, {"<kernel32>GetCommandLineA", &win32::Wrapper<decltype(&win32::kernel32::GetCommandLineA), &win32::kernel32::GetCommandLineA>::stdcall});
    registerMethod(0x00400abd, {"<kernel32>GetVersion", &win32::Wrapper<decltype(&win32::kernel32::GetVersion), &win32::kernel32::GetVersion>::stdcall});
    registerMethod(0x00400abe, {"<kernel32>ExitProcess", &win32::Wrapper<decltype(&win32::kernel32::ExitProcess), &win32::kernel32::ExitProcess>::stdcall});
    registerMethod(0x00400abf, {"<kernel32>TerminateProcess", &win32::Wrapper<decltype(&win32::kernel32::TerminateProcess), &win32::kernel32::TerminateProcess>::stdcall});
    registerMethod(0x00400ac0, {"<kernel32>UnhandledExceptionFilter", &win32::Wrapper<decltype(&win32::kernel32::UnhandledExceptionFilter), &win32::kernel32::UnhandledExceptionFilter>::stdcall});
    registerMethod(0x00400ac1, {"<kernel32>GetModuleFileNameA", &win32::Wrapper<decltype(&win32::kernel32::GetModuleFileNameA), &win32::kernel32::GetModuleFileNameA>::stdcall});
    registerMethod(0x00400ac2, {"<kernel32>FreeEnvironmentStringsA", &win32::Wrapper<decltype(&win32::kernel32::FreeEnvironmentStringsA), &win32::kernel32::FreeEnvironmentStringsA>::stdcall});
    registerMethod(0x00400ac3, {"<kernel32>Sleep", &win32::Wrapper<decltype(&win32::kernel32::Sleep), &win32::kernel32::Sleep>::stdcall});
    registerMethod(0x00400ac4, {"<kernel32>WideCharToMultiByte", &win32::Wrapper<decltype(&win32::kernel32::WideCharToMultiByte), &win32::kernel32::WideCharToMultiByte>::stdcall});
    registerMethod(0x00400ac5, {"<kernel32>GetEnvironmentStrings", &win32::Wrapper<decltype(&win32::kernel32::GetEnvironmentStrings), &win32::kernel32::GetEnvironmentStrings>::stdcall});
    registerMethod(0x00400ac6, {"<kernel32>HeapFree", &win32::Wrapper<decltype(&win32::kernel32::HeapFree), &win32::kernel32::HeapFree>::stdcall});
    registerMethod(0x00400ac7, {"<kernel32>RtlUnwind", &win32::Wrapper<decltype(&win32::kernel32::RtlUnwind), &win32::kernel32::RtlUnwind>::stdcall});
    registerMethod(0x00400ac8, {"<kernel32>GetStdHandle", &win32::Wrapper<decltype(&win32::kernel32::GetStdHandle), &win32::kernel32::GetStdHandle>::stdcall});
    registerMethod(0x00400ac9, {"<kernel32>GetFileType", &win32::Wrapper<decltype(&win32::kernel32::GetFileType), &win32::kernel32::GetFileType>::stdcall});
    registerMethod(0x00400aca, {"<kernel32>HeapDestroy", &win32::Wrapper<decltype(&win32::kernel32::HeapDestroy), &win32::kernel32::HeapDestroy>::stdcall});
    registerMethod(0x00400acb, {"<kernel32>HeapCreate", &win32::Wrapper<decltype(&win32::kernel32::HeapCreate), &win32::kernel32::HeapCreate>::stdcall});
    registerMethod(0x00400acc, {"<kernel32>VirtualFree", &win32::Wrapper<decltype(&win32::kernel32::VirtualFree), &win32::kernel32::VirtualFree>::stdcall});
    registerMethod(0x00400acd, {"<kernel32>HeapAlloc", &win32::Wrapper<decltype(&win32::kernel32::HeapAlloc), &win32::kernel32::HeapAlloc>::stdcall});
    registerMethod(0x00400ace, {"<kernel32>WriteFile", &win32::Wrapper<decltype(&win32::kernel32::WriteFile), &win32::kernel32::WriteFile>::stdcall});
    registerMethod(0x00400acf, {"<kernel32>GetCPInfo", &win32::Wrapper<decltype(&win32::kernel32::GetCPInfo), &win32::kernel32::GetCPInfo>::stdcall});
    registerMethod(0x00400ad0, {"<kernel32>GetACP", &win32::Wrapper<decltype(&win32::kernel32::GetACP), &win32::kernel32::GetACP>::stdcall});
    registerMethod(0x00400ad1, {"<kernel32>GetOEMCP", &win32::Wrapper<decltype(&win32::kernel32::GetOEMCP), &win32::kernel32::GetOEMCP>::stdcall});
    registerMethod(0x00400ad2, {"<kernel32>VirtualAlloc", &win32::Wrapper<decltype(&win32::kernel32::VirtualAlloc), &win32::kernel32::VirtualAlloc>::stdcall});
    registerMethod(0x00400ad3, {"<user32>TranslateMessage", &win32::Wrapper<decltype(&win32::user32::TranslateMessage), &win32::user32::TranslateMessage>::stdcall});
    registerMethod(0x00400ad4, {"<user32>PeekMessageA", &win32::Wrapper<decltype(&win32::user32::PeekMessageA), &win32::user32::PeekMessageA>::stdcall});
    registerMethod(0x00400ad5, {"<user32>CreateWindowExA", &win32::Wrapper<decltype(&win32::user32::CreateWindowExA), &win32::user32::CreateWindowExA>::stdcall});
    registerMethod(0x00400ad6, {"<user32>GetSystemMetrics", &win32::Wrapper<decltype(&win32::user32::GetSystemMetrics), &win32::user32::GetSystemMetrics>::stdcall});
    registerMethod(0x00400ad7, {"<user32>LoadIconA", &win32::Wrapper<decltype(&win32::user32::LoadIconA), &win32::user32::LoadIconA>::stdcall});
    registerMethod(0x00400ad8, {"<user32>ShowWindow", &win32::Wrapper<decltype(&win32::user32::ShowWindow), &win32::user32::ShowWindow>::stdcall});
    registerMethod(0x00400ad9, {"<user32>UpdateWindow", &win32::Wrapper<decltype(&win32::user32::UpdateWindow), &win32::user32::UpdateWindow>::stdcall});
    registerMethod(0x00400ada, {"<user32>DispatchMessageA", &win32::Wrapper<decltype(&win32::user32::DispatchMessageA), &win32::user32::DispatchMessageA>::stdcall});
    registerMethod(0x00400adb, {"<user32>RegisterClassA", &win32::Wrapper<decltype(&win32::user32::RegisterClassA), &win32::user32::RegisterClassA>::stdcall});
    registerMethod(0x00400adc, {"<user32>DefWindowProcA", &win32::Wrapper<decltype(&win32::user32::DefWindowProcA), &win32::user32::DefWindowProcA>::stdcall});
    registerMethod(0x00400add, {"<gdi32>GetStockObject", &win32::Wrapper<decltype(&win32::gdi32::GetStockObject), &win32::gdi32::GetStockObject>::stdcall});
}

// The stub executable's entry point calls this; the segments it
// carries are mapped before anything here runs.
extern "C" __declspec(dllexport) int blackMain()
{
    Application application;
    application.execute();
    return 0;
}

void Application::execute()
{
    x86::CPU cpu{};
    runThread(cpu, 0x4011a0);
}

}
