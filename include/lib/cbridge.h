#ifndef LIB_CBRIDGE_H_
#define LIB_CBRIDGE_H_

#include <lib/winapp.h>

#include <cstring>
#include <type_traits>

// What the generated stubs between translated routines and decompiled C++
// functions stand on (see disasm/cstubs.py).
//
// A translated routine takes the application and the CPU it runs on as
// arguments; a C++ function takes ordinary arguments and has no CPU to hand.
// So the CPU a thread is running translated code on is also kept here, where a
// C++ function calling back into translated code can find it. Translated code
// can nest a second CPU on the same thread -- a callback the API makes while
// the first is waiting in a native call gets a CPU of its own -- so entering
// one is scoped: CpuScope restores the outer CPU on the way out.

namespace win32
{

    x86::CPU &currentCpu();

    class CpuScope
    {
    public:
        explicit CpuScope(x86::CPU &cpu);
        ~CpuScope();
        CpuScope(const CpuScope &) = delete;
        CpuScope &operator=(const CpuScope &) = delete;

    private:
        x86::CPU *m_previous;
    };

    // A register holds whatever the argument's bytes were, low bytes first.
    // Pointers, integers, enums, bools and the occasional float in a register
    // all cross the same way, so this is a bit copy rather than a conversion.
    template <typename T, typename R>
    inline T fromReg(R value)
    {
        static_assert(std::is_trivially_copyable_v<T> && sizeof(T) <= sizeof(R),
                      "a register argument must fit in the register(s) it is passed in");
        T result;
        std::memcpy(&result, &value, sizeof(T));
        return result;
    }

    template <typename T>
    inline x86::reg32 toReg(T value)
    {
        static_assert(std::is_trivially_copyable_v<T> && sizeof(T) <= 4,
                      "only values up to a dword travel in one register");
        x86::reg32 result = 0;
        std::memcpy(&result, &value, sizeof(T));
        return result;
    }

    template <typename T>
    inline x86::reg64 toReg64(T value)
    {
        static_assert(std::is_trivially_copyable_v<T> && sizeof(T) <= 8,
                      "only values up to a qword travel in a register pair");
        x86::reg64 result = 0;
        std::memcpy(&result, &value, sizeof(T));
        return result;
    }

    namespace detail
    {
        template <typename T>
        constexpr x86::reg32 slot()
        {
            return x86::reg32((sizeof(T) + 3) & ~3u);
        }

        inline void push(WinApplication *, x86::reg32)
        {
        }

        template <typename A, typename... Rest>
        inline void push(WinApplication *app, x86::reg32 address, A argument, Rest... rest)
        {
            static_assert(std::is_trivially_copyable_v<A>,
                          "guestCall arguments are copied onto the emulated stack");
            if constexpr (sizeof(A) < 4)
            {
                app->getMemory<x86::reg32>(address) = toReg(argument);
            }
            else
            {
                app->getMemory<A>(address) = argument;
            }
            push(app, address + slot<A>(), rest...);
        }
    }

    // Call a routine of the game by address from C++: the arguments go on the
    // emulated stack right to left, ecx carries `thisPointer` when the routine
    // is a __thiscall method, and the result comes back from eax (or edx:eax for
    // a 64-bit result, or st0 for a floating point one). Meant for what the
    // decompiler writes as `(**(code **)(*p + 8))(p, x)`: an indirect call whose
    // target is a translated routine, not native code. Whatever the callee pops,
    // esp is put back afterwards, so caller-pops and callee-pops both work.
    template <typename R = x86::reg32, typename... A>
    inline R guestCallThis(x86::reg32 address, x86::reg32 thisPointer, A... arguments)
    {
        x86::CPU &cpu = currentCpu();
        WinApplication *app = WinApplication::current();
        const x86::reg32 esp = cpu.esp;
        const x86::reg32 frame = (x86::reg32(0) + ... + detail::slot<A>());
        cpu.esp = esp - frame - 4;
        detail::push(app, cpu.esp + 4, arguments...);
        cpu.ecx = thisPointer;
        app->dynamic_call(address, cpu);
        cpu.esp = esp;
        if constexpr (std::is_void_v<R>)
        {
            return;
        }
        else if constexpr (std::is_floating_point_v<R>)
        {
            return R(double(cpu.fpu.pop()));
        }
        else if constexpr (sizeof(R) > 4)
        {
            return fromReg<R>(cpu.edx_eax);
        }
        else
        {
            return fromReg<R>(cpu.eax);
        }
    }

    template <typename R = x86::reg32, typename... A>
    inline R guestCall(x86::reg32 address, A... arguments)
    {
        return guestCallThis<R>(address, currentCpu().ecx, arguments...);
    }

}

#endif /* !LIB_CBRIDGE_H_ */
