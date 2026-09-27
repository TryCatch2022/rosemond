#include <x86.h>
#include <lib/winapp.h>

// The routines the program hands to DirectX methods as enumeration callbacks.
//
// A COM method is reached through its vtable, so no API wrapper sees these
// addresses go by the way src/lib/callbacks.cpp sees the ones given to imported
// functions. nativeCall swaps each for its thunk here on the way out instead.
// All of them are stdcall; the argument counts are the ones their ret pops.

namespace
{
    x86::reg32 enterGuest(x86::reg32 guest, const x86::reg32 *arguments, unsigned count)
    {
        win32::WinApplication *application = win32::WinApplication::current();
        NFS2_ASSERT(application);
        return application->callGuest(guest, arguments, count);
    }

    template <x86::reg32 Guest>
    x86::reg32 __stdcall callback2(x86::reg32 a, x86::reg32 b)
    {
        const x86::reg32 arguments[2] = {a, b};
        return enterGuest(Guest, arguments, 2);
    }

    template <x86::reg32 Guest>
    x86::reg32 __stdcall callback6(x86::reg32 a, x86::reg32 b, x86::reg32 c,
                                   x86::reg32 d, x86::reg32 e, x86::reg32 f)
    {
        const x86::reg32 arguments[6] = {a, b, c, d, e, f};
        return enterGuest(Guest, arguments, 6);
    }

    template <typename T>
    void *native(T function)
    {
        return reinterpret_cast<void *>(function);
    }

    struct Registration
    {
        Registration()
        {
            using win32::WinApplication;
            // IDirectDraw::EnumDisplayModes, from 0x43e244
            WinApplication::registerNativeCallback(0x43cac0, native(&callback2<0x43cac0>));
            // IDirect3D::EnumDevices, from 0x43cd29
            WinApplication::registerNativeCallback(0x43caf0, native(&callback6<0x43caf0>));
            // IDirect3D3::EnumZBufferFormats, from 0x43d092
            WinApplication::registerNativeCallback(0x43d5f0, native(&callback2<0x43d5f0>));
            // IDirect3DDevice3::EnumTextureFormats, from 0x43d87e
            WinApplication::registerNativeCallback(0x43d730, native(&callback2<0x43d730>));
            // IDirect3DDevice2::EnumTextureFormats, from 0x43d919
            WinApplication::registerNativeCallback(0x43d660, native(&callback2<0x43d660>));
            // IDirectInput::EnumDevices, from 0x462798
            WinApplication::registerNativeCallback(0x462510, native(&callback2<0x462510>));
        }
    } registration;
}
