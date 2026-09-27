#ifndef LIB_THREAD_H_
#define LIB_THREAD_H_

#include <x86.h>

namespace win32
{

    class WinApplication;

    // Threads the recompiled code asks for cannot be handed straight to
    // CreateThread: the start address it passes is an address in the original
    // binary, not a function this process can call. The thread has to be
    // started here so it gets a CPU of its own, its own stack, and its own FS
    // block before it enters the translated code.
    //
    // The handle that comes back is a real OS handle, so everything else the
    // game does with it -- WaitForSingleObject, CloseHandle, SuspendThread --
    // goes to the real API unchanged.
    class Thread
    {
    public:
        static void *start(WinApplication *application, x86::reg32 entryPoint,
                           x86::reg32 parameter, x86::reg32 creationFlags,
                           x86::reg32 *threadId);

        static void sleep(x86::reg32 milliseconds);
        static x86::reg32 currentThreadId();
    };

}

#endif /* !LIB_THREAD_H_ */
