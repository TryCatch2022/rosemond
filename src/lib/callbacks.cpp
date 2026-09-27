#include <lib/winapp.h>
#include <windows.h>
#include <ddraw.h>
#include <mmsystem.h>
#include <winapi/binkw32.h>

// Every remaining place the program hands a function pointer to the API.
//
// The address it gives is an address in the original binary, so the API cannot
// call it: what is mapped there is the original machine code, not the
// translation, and the calls it makes go through an import table this build
// rewrote. Each of these installs a real function of its own and enters the
// translated routine through callGuest instead.
//
// Where the API carries a context value through to the callback, that is used to
// find the routine again, so nothing needs to be remembered globally. The two
// that have nowhere to put it are process-wide by nature and keep one address.

namespace
{
    template <typename T>
    x86::reg32 address(T value)
    {
        return x86::reg32(reinterpret_cast<uintptr_t>(value));
    }

    x86::reg32 enterGuest(x86::reg32 guest, const x86::reg32 *arguments, unsigned count)
    {
        win32::WinApplication *application = win32::WinApplication::current();
        NFS2_ASSERT(application);
        return application->callGuest(guest, arguments, count);
    }

    // A routine to enter, plus whatever context value the program asked to have
    // handed back to it.
    struct Callback
    {
        x86::reg32 routine;
        x86::reg32 context;
    };

    // --- DirectDrawEnumerateA ---------------------------------------------
    BOOL WINAPI enumerateThunk(GUID *guid, LPSTR description, LPSTR name, LPVOID context)
    {
        const Callback *callback = static_cast<const Callback *>(context);
        const x86::reg32 arguments[4] = {address(guid), address(description),
                                         address(name), callback->context};
        return BOOL(enterGuest(callback->routine, arguments, 4));
    }

    // --- SetUnhandledExceptionFilter --------------------------------------
    // One per process, so one address to remember.
    x86::reg32 g_exceptionFilter = 0;

    LONG WINAPI exceptionFilterThunk(EXCEPTION_POINTERS *information)
    {
        const x86::reg32 arguments[1] = {address(information)};
        return LONG(enterGuest(g_exceptionFilter, arguments, 1));
    }

    // --- BinkSetSoundSystem ------------------------------------------------
    // Also one per process: Bink keeps a single sound-system opener.
    x86::reg32 g_binkSoundOpen = 0;

    void *__stdcall binkSoundThunk(unsigned long parameter)
    {
        const x86::reg32 arguments[1] = {x86::reg32(parameter)};
        return reinterpret_cast<void *>(enterGuest(g_binkSoundOpen, arguments, 1));
    }

    // --- mixerOpen ---------------------------------------------------------
    void CALLBACK mixerThunk(HMIXEROBJ mixer, UINT message, DWORD_PTR instance,
                             DWORD_PTR parameter1, DWORD_PTR parameter2)
    {
        const Callback *callback = reinterpret_cast<const Callback *>(instance);
        const x86::reg32 arguments[5] = {address(mixer), x86::reg32(message),
                                         callback->context, x86::reg32(parameter1),
                                         x86::reg32(parameter2)};
        enterGuest(callback->routine, arguments, 5);
    }
}

namespace win32::ddraw
{
    HRESULT __stdcall DirectDrawEnumerateA(LPDDENUMCALLBACKA lpCallback, LPVOID lpContext)
    {
        if (!lpCallback)
        {
            return ::DirectDrawEnumerateA(nullptr, lpContext);
        }
        // Enumeration finishes before this returns, so the callback can live here.
        Callback callback = {address(lpCallback), address(lpContext)};
        return ::DirectDrawEnumerateA(&enumerateThunk, &callback);
    }
}

namespace win32::kernel32
{
    LPTOP_LEVEL_EXCEPTION_FILTER __stdcall SetUnhandledExceptionFilter(
        LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter)
    {
        const x86::reg32 installed = address(lpTopLevelExceptionFilter);
        LPTOP_LEVEL_EXCEPTION_FILTER previous =
            ::SetUnhandledExceptionFilter(installed ? &exceptionFilterThunk : nullptr);
        const x86::reg32 previousGuest = g_exceptionFilter;
        g_exceptionFilter = installed;

        // Hand back what was there before in the same terms it was given: the
        // program's own address if it installed one, otherwise whatever real
        // filter was in place, which it can call through the trampoline.
        return previousGuest
                   ? reinterpret_cast<LPTOP_LEVEL_EXCEPTION_FILTER>(previousGuest)
                   : previous;
    }
}

namespace win32::binkw32
{
    int __stdcall BinkSetSoundSystem(SndOpenCallback open, unsigned long param)
    {
        g_binkSoundOpen = address(open);
        return ::BinkSetSoundSystem(g_binkSoundOpen ? &binkSoundThunk : nullptr, param);
    }
}

namespace win32::winmm
{
    MMRESULT __stdcall mixerOpen(LPHMIXER phmx, UINT uMxId, DWORD_PTR dwCallback,
                                 DWORD_PTR dwInstance, DWORD fdwOpen)
    {
        // dwCallback is only a function when asked for as one; a window handle or
        // a thread id goes straight through.
        if ((fdwOpen & CALLBACK_TYPEMASK) != CALLBACK_FUNCTION || !dwCallback)
        {
            return ::mixerOpen(phmx, uMxId, dwCallback, dwInstance, fdwOpen);
        }
        // Lives as long as the mixer does, and a mixer is closed at exit, so it
        // is not worth tracking for release.
        Callback *callback = new Callback{x86::reg32(dwCallback), x86::reg32(dwInstance)};
        return ::mixerOpen(phmx, uMxId, reinterpret_cast<DWORD_PTR>(&mixerThunk),
                           reinterpret_cast<DWORD_PTR>(callback), fdwOpen);
    }
}
