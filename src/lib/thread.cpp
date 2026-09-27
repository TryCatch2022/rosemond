#include <lib/thread.h>
#include <lib/winapp.h>
#include <windows.h>

namespace win32
{

    namespace
    {
        struct Start
        {
            WinApplication *application;
            x86::reg32 entryPoint;
            x86::reg32 parameter;
        };

        // runThread carves the translated code's stack out of the thread's own,
        // and the native frames its calls build up sit below that -- guest call
        // depth becomes native call depth. The original ran on a megabyte, so
        // reserve well past it. Reserved, not committed.
        const SIZE_T NATIVE_STACK = 16 * 1024 * 1024;

        DWORD WINAPI run(void *parameter)
        {
            Start start = *static_cast<Start *>(parameter);
            delete static_cast<Start *>(parameter);

            // A CPU per thread: the translated code keeps all its machine state
            // here, so two threads sharing one would trample each other.
            x86::CPU cpu{};
            return DWORD(start.application->runThread(cpu, start.entryPoint,
                                                      start.parameter));
        }
    }

    void *Thread::start(WinApplication *application, x86::reg32 entryPoint,
                        x86::reg32 parameter, x86::reg32 creationFlags,
                        x86::reg32 *threadId)
    {
        Start *start = new Start{application, entryPoint, parameter};
        DWORD id = 0;
        // CREATE_SUSPENDED is passed straight through, so a game that creates a
        // thread suspended and resumes it later behaves as it did.
        HANDLE handle = ::CreateThread(nullptr, NATIVE_STACK, &run, start,
                                       creationFlags, &id);
        if (!handle)
        {
            delete start;
            return nullptr;
        }
        if (threadId)
        {
            *threadId = x86::reg32(id);
        }
        return handle;
    }

    void Thread::sleep(x86::reg32 milliseconds)
    {
        Sleep(milliseconds);
    }

    x86::reg32 Thread::currentThreadId()
    {
        return x86::reg32(GetCurrentThreadId());
    }

}

namespace win32::kernel32
{

    // Replaces the real CreateThread for the recompiled code: lpStartAddress is
    // an address in the original binary, so the thread has to be started through
    // Thread::start, which gives it a CPU and a stack first. The handle returned
    // is the real one, so every other thread API still works untouched.
    HANDLE __stdcall CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,
                                  SIZE_T dwStackSize,
                                  LPTHREAD_START_ROUTINE lpStartAddress,
                                  LPVOID lpParameter,
                                  DWORD dwCreationFlags,
                                  LPDWORD lpThreadId)
    {
        NFS2_USE(lpThreadAttributes);
        NFS2_USE(dwStackSize);
        WinApplication *application = WinApplication::current();
        NFS2_ASSERT(application);

        x86::reg32 id = 0;
        void *handle = Thread::start(
            application,
            x86::reg32(reinterpret_cast<uintptr_t>(lpStartAddress)),
            x86::reg32(reinterpret_cast<uintptr_t>(lpParameter)),
            x86::reg32(dwCreationFlags),
            &id);
        if (lpThreadId)
        {
            *lpThreadId = DWORD(id);
        }
        return handle;
    }

}
