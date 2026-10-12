#ifndef BLACK_H_
#define BLACK_H_
#include <x86.h>
#include <lib/winapp.h>
#include <map>

namespace black
{

// Called by the stub executable through its import table.
extern "C" __declspec(dllexport) int blackMain();

class Application : public win32::WinApplication
{
public:
    Application();
    void execute();
    // Public so the generated entry points and the stubs to and
    // from decompiled functions can reach them.
    static void sub_401000(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401000(WinApplication* app, x86::CPU& cpu);
    static void sub_401050(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401050(WinApplication* app, x86::CPU& cpu);
    static void sub_4010a0(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4010a0(WinApplication* app, x86::CPU& cpu);
    static void sub_4010c0(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4010c0(WinApplication* app, x86::CPU& cpu);
    static void sub_401130(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401130(WinApplication* app, x86::CPU& cpu);
    static void sub_4011a0(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4011a0(WinApplication* app, x86::CPU& cpu);
    static void sub_40128b(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_40128b(WinApplication* app, x86::CPU& cpu);
    static void sub_401296(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401296(WinApplication* app, x86::CPU& cpu);
    static void sub_4012bb(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4012bb(WinApplication* app, x86::CPU& cpu);
    static void sub_4012df(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4012df(WinApplication* app, x86::CPU& cpu);
    static void sub_40130c(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_40130c(WinApplication* app, x86::CPU& cpu);
    static void sub_40131d(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_40131d(WinApplication* app, x86::CPU& cpu);
    static void sub_40132e(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_40132e(WinApplication* app, x86::CPU& cpu);
    static void sub_4013c7(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4013c7(WinApplication* app, x86::CPU& cpu);
    static void sub_4013e1(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4013e1(WinApplication* app, x86::CPU& cpu);
    static void sub_401522(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401522(WinApplication* app, x86::CPU& cpu);
    static void sub_401565(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401565(WinApplication* app, x86::CPU& cpu);
    static void sub_4015bd(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4015bd(WinApplication* app, x86::CPU& cpu);
    static void sub_401676(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401676(WinApplication* app, x86::CPU& cpu);
    static void sub_40170f(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_40170f(WinApplication* app, x86::CPU& cpu);
    static void sub_4018c3(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4018c3(WinApplication* app, x86::CPU& cpu);
    static void sub_4019f5(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4019f5(WinApplication* app, x86::CPU& cpu);
    static void sub_401ba0(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401ba0(WinApplication* app, x86::CPU& cpu);
    static void sub_401bdc(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401bdc(WinApplication* app, x86::CPU& cpu);
    static void sub_401bfc(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401bfc(WinApplication* app, x86::CPU& cpu);
    static void sub_401c1e(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401c1e(WinApplication* app, x86::CPU& cpu);
    static void sub_401cb2(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401cb2(WinApplication* app, x86::CPU& cpu);
    static void sub_401cd4(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401cd4(WinApplication* app, x86::CPU& cpu);
    static void sub_401d91(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401d91(WinApplication* app, x86::CPU& cpu);
    static void sub_401dac(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401dac(WinApplication* app, x86::CPU& cpu);
    static void sub_401de5(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401de5(WinApplication* app, x86::CPU& cpu);
    static void sub_401f38(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401f38(WinApplication* app, x86::CPU& cpu);
    static void sub_401f49(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401f49(WinApplication* app, x86::CPU& cpu);
    static void sub_401f7a(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_401f7a(WinApplication* app, x86::CPU& cpu);
    static void sub_402113(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_402113(WinApplication* app, x86::CPU& cpu);
    static void sub_40215d(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_40215d(WinApplication* app, x86::CPU& cpu);
    static void sub_402190(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_402190(WinApplication* app, x86::CPU& cpu);
    static void sub_4021b9(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4021b9(WinApplication* app, x86::CPU& cpu);
    static void sub_40233e(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_40233e(WinApplication* app, x86::CPU& cpu);
    static void sub_40235a(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_40235a(WinApplication* app, x86::CPU& cpu);
    static void sub_402390(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_402390(WinApplication* app, x86::CPU& cpu);
    static void sub_4023a0(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4023a0(WinApplication* app, x86::CPU& cpu);
    static void sub_402401(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_402401(WinApplication* app, x86::CPU& cpu);
    static void sub_402480(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_402480(WinApplication* app, x86::CPU& cpu);
    static void sub_402492(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_402492(WinApplication* app, x86::CPU& cpu);
    static void sub_4024be(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4024be(WinApplication* app, x86::CPU& cpu);
    static void sub_402500(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_402500(WinApplication* app, x86::CPU& cpu);
    static void sub_402580(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_402580(WinApplication* app, x86::CPU& cpu);
    static void sub_4028b5(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4028b5(WinApplication* app, x86::CPU& cpu);
    static void sub_4028f3(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4028f3(WinApplication* app, x86::CPU& cpu);
    static void sub_40291e(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_40291e(WinApplication* app, x86::CPU& cpu);
    static void sub_402c49(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_402c49(WinApplication* app, x86::CPU& cpu);
    static void sub_402f52(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_402f52(WinApplication* app, x86::CPU& cpu);
    static void sub_403003(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_403003(WinApplication* app, x86::CPU& cpu);
    static void sub_4030fe(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4030fe(WinApplication* app, x86::CPU& cpu);
    static void sub_403190(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_403190(WinApplication* app, x86::CPU& cpu);
    static void sub_40328e(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_40328e(WinApplication* app, x86::CPU& cpu);
    static void sub_40339e(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_40339e(WinApplication* app, x86::CPU& cpu);
    static void sub_4033a2(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4033a2(WinApplication* app, x86::CPU& cpu);
    static void sub_40341e(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_40341e(WinApplication* app, x86::CPU& cpu);
    static void sub_40341c(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_40341c(WinApplication* app, x86::CPU& cpu);
    static void sub_4033b1(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4033b1(WinApplication* app, x86::CPU& cpu);
    static void sub_403452(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_403452(WinApplication* app, x86::CPU& cpu);
    static void sub_403456(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_403456(WinApplication* app, x86::CPU& cpu);
    static void sub_4034ab(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4034ab(WinApplication* app, x86::CPU& cpu);
    static void sub_403464(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_403464(WinApplication* app, x86::CPU& cpu);
    static void sub_4034b2(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4034b2(WinApplication* app, x86::CPU& cpu);
    static void sub_4034dd(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4034dd(WinApplication* app, x86::CPU& cpu);
    static void sub_4035d6(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4035d6(WinApplication* app, x86::CPU& cpu);
    static void sub_4035da(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4035da(WinApplication* app, x86::CPU& cpu);
    static void sub_403614(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_403614(WinApplication* app, x86::CPU& cpu);
    static void sub_403612(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_403612(WinApplication* app, x86::CPU& cpu);
    static void sub_4035e1(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4035e1(WinApplication* app, x86::CPU& cpu);
    static void sub_403626(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_403626(WinApplication* app, x86::CPU& cpu);
    static void sub_403650(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_403650(WinApplication* app, x86::CPU& cpu);
    static void sub_403990(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_403990(WinApplication* app, x86::CPU& cpu);
    static void sub_4039c0(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_4039c0(WinApplication* app, x86::CPU& cpu);
    static void sub_403a18(WinApplication* app, x86::CPU& cpu);
    static void asm_sub_403a18(WinApplication* app, x86::CPU& cpu);
};

}

#endif /* !BLACK_H_ */
