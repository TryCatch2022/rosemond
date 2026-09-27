#include <lib/winapp.h>
#include <windows.h>
#include <array>
#include <mutex>
#include <utility>

// A window procedure the program registers is an address in the original binary.
// user32 cannot call it: the bytes are mapped, but they are the original machine
// code, not the translation, and the calls they make go through an import table
// this build rewrote. So the address handed to RegisterClassA is swapped for a
// real window procedure that enters the translated routine instead.
//
// user32 passes a window procedure no context of its own, so the guest address
// has to be recoverable from the procedure that was called. Rather than generate
// code at run time, there is a fixed pool of real procedures, each knowing its
// own slot, and registering a class takes the next one. Nothing here needs
// writable code, so it works the same under either toolchain.

namespace win32
{

    namespace
    {
        const unsigned MAX_WINDOW_PROCS = 16;

        std::mutex g_lock;
        x86::reg32 g_guest[MAX_WINDOW_PROCS];
        unsigned g_used = 0;

        LRESULT enterGuest(unsigned slot, HWND hwnd, UINT message,
                           WPARAM wparam, LPARAM lparam)
        {
            WinApplication *application = WinApplication::current();
            NFS2_ASSERT(application);

            // The four arguments a window procedure is called with, in the order
            // a stdcall callee reads them.
            const x86::reg32 arguments[4] = {
                x86::reg32(reinterpret_cast<uintptr_t>(hwnd)),
                x86::reg32(message),
                x86::reg32(wparam),
                x86::reg32(lparam)};

            return LRESULT(application->callGuest(g_guest[slot], arguments, 4));
        }

        template <unsigned Slot>
        LRESULT CALLBACK thunk(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
        {
            return enterGuest(Slot, hwnd, message, wparam, lparam);
        }

        template <unsigned... Slots>
        std::array<WNDPROC, sizeof...(Slots)> makeThunks(std::index_sequence<Slots...>)
        {
            return {{&thunk<Slots>...}};
        }

        const std::array<WNDPROC, MAX_WINDOW_PROCS> &thunks()
        {
            static const std::array<WNDPROC, MAX_WINDOW_PROCS> instance =
                makeThunks(std::make_index_sequence<MAX_WINDOW_PROCS>{});
            return instance;
        }
    }

    WNDPROC wrapWindowProc(x86::reg32 guestProc)
    {
        if (!guestProc)
        {
            return nullptr;
        }

        std::lock_guard<std::mutex> guard(g_lock);
        // A class registered twice with the same procedure reuses its thunk, so
        // repeated registration cannot exhaust the pool.
        for (unsigned i = 0; i < g_used; ++i)
        {
            if (g_guest[i] == guestProc)
            {
                return thunks()[i];
            }
        }
        NFS2_ASSERT(g_used < MAX_WINDOW_PROCS);
        g_guest[g_used] = guestProc;
        return thunks()[g_used++];
    }

}

namespace win32::user32
{

    // Not the real RegisterClassA: the class is registered with a window
    // procedure that can actually be called, and the program's own address is
    // remembered behind it.
    ATOM __stdcall RegisterClassA(const WNDCLASSA *lpWndClass)
    {
        NFS2_ASSERT(lpWndClass);
        WNDCLASSA wndClass = *lpWndClass;
        wndClass.lpfnWndProc = win32::wrapWindowProc(
            x86::reg32(reinterpret_cast<uintptr_t>(lpWndClass->lpfnWndProc)));
        return ::RegisterClassA(&wndClass);
    }

}
