#include <ddraw.h>

namespace win32::ddraw
{
    using ::DirectDrawCreate;
    // Not the real DirectDrawEnumerateA: the callback the program passes is an
    // address in the original binary, so lib/callbacks.cpp substitutes a real one.
    HRESULT __stdcall DirectDrawEnumerateA(LPDDENUMCALLBACKA lpCallback, LPVOID lpContext);
}