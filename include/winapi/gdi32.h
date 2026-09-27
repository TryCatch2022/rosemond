#include <windows.h>

namespace win32::gdi32
{
    using ::BitBlt;
    using ::CreateCompatibleDC;
    using ::DeleteDC;
    using ::DeleteObject;
    using ::GetObjectA;
    using ::GetStockObject;
    using ::GetSystemPaletteEntries;
    using ::SelectObject;
    using ::SetStretchBltMode;
    using ::StretchBlt;
}