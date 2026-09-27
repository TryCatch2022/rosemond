#include <windows.h>

namespace win32::winmm
{
    using ::mciGetErrorStringA;
    using ::mciSendCommandA;
    using ::mixerClose;
    using ::mixerGetControlDetailsA;
    using ::mixerGetDevCapsA;
    using ::mixerGetLineControlsA;
    using ::mixerGetLineInfoA;
    // Not the real mixerOpen: when asked for a function callback, the address
    // the program gives is one of its own. See lib/callbacks.cpp.
    MMRESULT __stdcall mixerOpen(LPHMIXER phmx, UINT uMxId, DWORD_PTR dwCallback,
                                 DWORD_PTR dwInstance, DWORD fdwOpen);
    using ::mixerSetControlDetails;
    using ::mmioAdvance;
    using ::mmioAscend;
    using ::mmioClose;
    using ::mmioDescend;
    using ::mmioGetInfo;
    using ::mmioOpenA;
    using ::mmioRead;
    using ::mmioSeek;
    using ::mmioSetInfo;
}