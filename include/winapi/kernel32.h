#include <windows.h>

// Defining the forwarder needs the macro out of the way; nothing in the
// recompiled code uses the macro form.
#ifdef InterlockedIncrement
#undef InterlockedIncrement
#endif
#ifdef InterlockedDecrement
#undef InterlockedDecrement
#endif

#define InterlockedForward(name)                      \
    inline LONG __stdcall name(LONG volatile *addend) \
    {                                                 \
        return _##name(addend);                       \
    }

namespace win32::kernel32
{
    using ::_lclose;
    using ::_lopen;
    using ::_lread;
    using ::CloseHandle;
    using ::CompareStringA;
    using ::CompareStringW;
    using ::CreateEventA;
    using ::CreateFileA;
    using ::CreatePipe;
    using ::CreateProcessA;
    // Not the real CreateThread: the start address the recompiled code passes is
    // an address in the original binary, so the thread has to be started by
    // lib/thread.cpp, which gives it a CPU, a stack and an FS block first. The
    // handle it returns is a real one, so the rest of the thread API is untouched.
    HANDLE __stdcall CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,
                                  SIZE_T dwStackSize,
                                  LPTHREAD_START_ROUTINE lpStartAddress,
                                  LPVOID lpParameter,
                                  DWORD dwCreationFlags,
                                  LPDWORD lpThreadId);
    using ::DeleteCriticalSection;
    using ::DeleteFileA;
    using ::EnterCriticalSection;
    using ::ExitProcess;
    using ::FileTimeToLocalFileTime;
    using ::FileTimeToSystemTime;
    using ::FindClose;
    using ::FindFirstFileA;
    using ::FindNextFileA;
    using ::FlushFileBuffers;
    using ::FreeEnvironmentStringsA;
    using ::FreeEnvironmentStringsW;
    using ::GetACP;
    using ::GetCommandLineA;
    using ::GetCPInfo;
    using ::GetCurrentDirectoryA;
    using ::GetCurrentProcess;
    using ::GetCurrentThreadId;
    using ::GetDriveTypeA;
    using ::GetEnvironmentStrings;
    using ::GetEnvironmentStringsW;
    using ::GetEnvironmentVariableA;
    using ::GetExitCodeProcess;
    using ::GetFileAttributesA;
    using ::GetFileInformationByHandle;
    using ::GetFileType;
    using ::GetFullPathNameA;
    using ::GetLastError;
    using ::GetModuleFileNameA;
    using ::GetModuleHandleA;
    using ::GetOEMCP;
    using ::GetProcAddress;
    using ::GetStartupInfoA;
    using ::GetStdHandle;
    using ::GetStringTypeA;
    using ::GetStringTypeW;
    using ::GetTimeZoneInformation;
    using ::GetVersion;
    using ::GetVersionExA;
    using ::GlobalAlloc;
    using ::GlobalFree;
    using ::GlobalMemoryStatus;
    using ::HeapAlloc;
    using ::HeapCreate;
    using ::HeapDestroy;
    using ::HeapFree;
    using ::HeapReAlloc;
    using ::InitializeCriticalSection;
    // InterlockedIncrement/Decrement are macros for the overloaded
    // _Interlocked* intrinsics, so `&win32::kernel32::InterlockedIncrement`
    // cannot resolve. Forward to the intrinsic through one concrete signature
    // -- the one kernel32.dll actually exports.
    InterlockedForward(InterlockedDecrement)
        InterlockedForward(InterlockedIncrement) using ::IsBadCodePtr;
    using ::IsBadReadPtr;
    using ::IsBadWritePtr;
    using ::LCMapStringA;
    using ::LCMapStringW;
    using ::LeaveCriticalSection;
    using ::LoadLibraryA;
    using ::LocalAlloc;
    using ::LocalFree;
    using ::MultiByteToWideChar;
    using ::OutputDebugStringA;
    using ::PeekNamedPipe;
    using ::QueryPerformanceCounter;
    using ::QueryPerformanceFrequency;
    using ::RaiseException;
    using ::ReadFile;
    using ::RtlUnwind;
    using ::SetEndOfFile;
    using ::SetEnvironmentVariableA;
    using ::SetEnvironmentVariableW;
    using ::SetErrorMode;
    using ::SetEvent;
    using ::SetFilePointer;
    using ::SetHandleCount;
    using ::SetLastError;
    using ::SetStdHandle;
    // Not the real SetUnhandledExceptionFilter: see lib/callbacks.cpp.
    LPTOP_LEVEL_EXCEPTION_FILTER __stdcall SetUnhandledExceptionFilter(
        LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);
    using ::Sleep;
    using ::TerminateProcess;
    using ::TlsAlloc;
    using ::TlsGetValue;
    using ::TlsSetValue;
    using ::UnhandledExceptionFilter;
    using ::VirtualAlloc;
    using ::VirtualFree;
    using ::WaitForSingleObject;
    using ::WideCharToMultiByte;
    using ::WriteFile;
}

#undef InterlockedForward
