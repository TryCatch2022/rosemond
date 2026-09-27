#ifndef WINAPI_WRAPPER_H_
#define WINAPI_WRAPPER_H_

#include <lib/winapp.h>

#include <cstddef>
#include <type_traits>
#include <utility>

// Bridge from a recompiled x86 stdcall call to a native Win32 call.
//
// The generated registration code names, for every DLL import the executable
// has, `Wrapper<decltype(&win32::<dll>::<fn>), &win32::<dll>::<fn>>::stdcall`.
// That is a `MethodPtr`: it takes the application and the emulated CPU, so it
// has to read the arguments the recompiled code pushed onto the emulated stack,
// convert each one to the native type the real function expects, call it, and
// put the result back where the recompiled code looks for it.
//
// The `win32::<dll>` namespaces pull in the real declarations (`using ::X;`, or
// a `__declspec(dllimport)` block for the DLLs that are not part of Windows),
// so the native signature is what drives all of this -- there is nothing to
// implement per function.
//
// There is one address space: WinApplication loads the executable's segments at
// the addresses they were linked for, so a pointer the recompiled code holds is
// already a pointer the real API can use. Nothing is translated in either
// direction -- which is also why a handle the API returns can be handed straight
// back to it later.

namespace win32
{

static_assert(sizeof(void *) == 4,
              "The recompiled code holds pointers in 32-bit registers and "
              "memory, and they are real pointers rather than offsets into an "
              "emulated space, so this must be built for 32-bit Windows "
              "(i686-w64-mingw32). On a 64-bit target the pointers would not "
              "fit and the struct layouts the game passes to the API would not "
              "match either.");

// Bytes one argument of type T occupies on the emulated stack.  Arguments are
// pushed in whole dwords, so anything narrower than a dword still costs a slot.
template <typename T>
constexpr x86::reg32 slotSize()
{
    return x86::reg32((sizeof(T) + 3) & ~x86::reg32(3));
}

// --------------------------------------------------------------------------
// Reading one native argument out of the emulated stack.
// --------------------------------------------------------------------------

template <typename T>
struct Argument
{
    static_assert(!std::is_reference_v<T>,
                  "reference parameters cannot cross the bridge");
    static_assert(std::is_pointer_v<T> || std::is_integral_v<T> ||
                      std::is_enum_v<T> || std::is_floating_point_v<T>,
                  "only integers, enums, pointers and floating point values "
                  "can cross the bridge; an aggregate passed by value would "
                  "need its own conversion");

    static T get(WinApplication *app, x86::reg32 address)
    {
        if constexpr (std::is_pointer_v<T>)
        {
            // Segments live at their linked addresses, so the dword on the
            // stack is already a usable pointer -- whether it points at the
            // executable's own data or is a handle the API returned earlier.
            // Zero stays a null pointer on its own.
            return reinterpret_cast<T>(x86::reg32(app->getMemory<x86::reg32>(address)));
        }
        else if constexpr (std::is_floating_point_v<T>)
        {
            return T(app->getMemory<T>(address));
        }
        else if constexpr (sizeof(T) > 4)
        {
            return static_cast<T>(x86::reg64(app->getMemory<x86::reg64>(address)));
        }
        else
        {
            // Narrower-than-dword parameters occupy a full slot; taking the low
            // bytes is what the callee would have done.
            return static_cast<T>(x86::reg32(app->getMemory<x86::reg32>(address)));
        }
    }
};

// --------------------------------------------------------------------------
// Putting the native return value where the recompiled code expects it.
// --------------------------------------------------------------------------

template <typename R>
struct Result
{
    static void store(x86::CPU &cpu, R value)
    {
        if constexpr (std::is_pointer_v<R>)
        {
            // Straight into eax: a 32-bit pointer fits whole, and the
            // recompiled code can dereference it or hand it back to the API
            // as-is.
            cpu.eax = reinterpret_cast<x86::reg32>(value);
        }
        else if constexpr (std::is_floating_point_v<R>)
        {
            cpu.fpu.push(x86::Float(value));
        }
        else if constexpr (sizeof(R) > 4)
        {
            cpu.edx_eax = static_cast<x86::reg64>(value);
        }
        else
        {
            cpu.eax = static_cast<x86::reg32>(value);
        }
    }
};

// --------------------------------------------------------------------------
// The call itself.
// --------------------------------------------------------------------------

template <typename Fn, Fn fn, bool calleePops, typename R, typename... T>
struct Bridge
{
private:
    static constexpr std::size_t count = sizeof...(T);

    // The trailing zero keeps the array non-empty for a nullary function.
    static constexpr x86::reg32 sizes[count + 1] = {slotSize<T>()..., 0};

    static constexpr x86::reg32 offsetOf(std::size_t index)
    {
        x86::reg32 offset = 0;
        for (std::size_t i = 0; i < index; ++i)
        {
            offset += sizes[i];
        }
        return offset;
    }

    template <std::size_t... I>
    static void call(WinApplication *app, x86::CPU &cpu, std::index_sequence<I...>)
    {
        // cg_call reserves the return-address slot with `esp -= 4` without
        // writing to it, so the arguments start one dword above esp.
        const x86::reg32 arguments = cpu.esp + 4;
        if constexpr (std::is_void_v<R>)
        {
            fn(Argument<T>::get(app, arguments + offsetOf(I))...);
        }
        else
        {
            Result<R>::store(cpu, fn(Argument<T>::get(app, arguments + offsetOf(I))...));
        }
        // A stdcall callee pops its own arguments; every callee pops the
        // reserved return-address slot, matching cg_ret.
        cpu.esp += 4 + (calleePops ? offsetOf(count) : 0);
    }

public:
    static void stdcall(WinApplication *app, x86::CPU &cpu)
    {
        call(app, cpu, std::make_index_sequence<count>{});
    }
};

// --------------------------------------------------------------------------
// Wrapper: pick the bridge apart from the function's own type.
// --------------------------------------------------------------------------

template <typename T, T t>
struct Wrapper;

template <typename R, typename... T, R (*F)(T...)>
struct Wrapper<R (*)(T...), F>
    : public Bridge<R (*)(T...), F, true, R, T...>
{
};

#if defined(__i386__) || defined(_M_IX86)
// On 32-bit x86 the calling convention is part of the type, so a stdcall
// function pointer is a distinct specialization from the default cdecl one (on
// a 64-bit target they collapse into one, which is why this is guarded).  Both pop
// their arguments here: the recompiled code was compiled against stdcall
// imports either way, and a genuinely cdecl import would be a caller-pops
// mismatch worth failing on rather than guessing at.
template <typename R, typename... T, R(__stdcall *F)(T...)>
struct Wrapper<R(__stdcall *)(T...), F>
    : public Bridge<R(__stdcall *)(T...), F, true, R, T...>
{
};
#endif

}

#endif
