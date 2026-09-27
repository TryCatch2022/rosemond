#include <windows.h>

namespace win32::user32
{
    using ::CreateWindowExA;
    using ::DefWindowProcA;
    using ::DestroyWindow;
    using ::DispatchMessageA;
    using ::GetDC;
    using ::GetFocus;
    using ::GetKeyboardState;
    using ::GetMessageA;
    using ::LoadCursorA;
    using ::LoadIconA;
    using ::LoadImageA;
    using ::MessageBoxA;
    using ::PeekMessageA;
    using ::PostQuitMessage;
    // Not the real RegisterClassA: the window procedure the program passes is an
    // address in the original binary, so lib/windowproc.cpp swaps it for a real
    // procedure that enters the translated routine.
    ATOM __stdcall RegisterClassA(const WNDCLASSA *lpWndClass);
    using ::ReleaseDC;
    using ::SetCursor;
    using ::SetCursorPos;
    using ::ShowWindow;
    using ::ToAscii;
    using ::TranslateMessage;
    using ::UpdateWindow;
}