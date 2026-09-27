#include <x86.h>
#include <lib/winapp.h>
#include <windows.h>
#include <cstdio>

// Implemented in trampoline.S / trampoline_masm.asm.
extern "C"
{
    struct NativeCallFrame
    {
        x86::reg32 target;
        x86::reg32 esp;        // in: where to stand; out: where the callee left it
        x86::reg32 eax;
        x86::reg32 ecx;
        x86::reg32 edx;
    };

    void rosemondNativeCall(NativeCallFrame *frame);
}

namespace win32
{

    namespace
    {
        // How much of the thread's stack the translated code gets. The original
        // ran on a megabyte; Thread::start asks for enough on top of that for the
        // native frames the translated calls build up.
        const x86::reg32 GUEST_STACK = 1024 * 1024;

        // A callback gets less, because callbacks nest -- a window procedure that
        // sends a message is back in here a level deeper -- and each level takes
        // this much of the thread's stack.
        const x86::reg32 CALLBACK_STACK = 256 * 1024;

        // The span this image occupies, read from its own headers. Every address
        // in it belongs to a translated routine and was registered, so one that
        // is not is a corrupted call target rather than a call into real code.
        struct Image
        {
            Image()
            {
                const x86::reg8 *base =
                    reinterpret_cast<const x86::reg8 *>(GetModuleHandleW(nullptr));
                const IMAGE_DOS_HEADER *dos =
                    reinterpret_cast<const IMAGE_DOS_HEADER *>(base);
                const IMAGE_NT_HEADERS32 *nt =
                    reinterpret_cast<const IMAGE_NT_HEADERS32 *>(base + dos->e_lfanew);
                start = x86::reg32(reinterpret_cast<uintptr_t>(base));
                end = start + nt->OptionalHeader.SizeOfImage;
            }

            x86::reg32 start;
            x86::reg32 end;
        };

        const Image &image()
        {
            static const Image instance;
            return instance;
        }

        // Filled while the DLL is loaded, before any thread runs, and only read
        // after that.
        std::unordered_map<x86::reg32, x86::reg32> &nativeCallbacks()
        {
            static std::unordered_map<x86::reg32, x86::reg32> instance;
            return instance;
        }

        // How many dwords above the return-address slot nativeCall looks through
        // for a callback. The widest call handing one over takes five.
        const unsigned CALLBACK_ARGUMENTS = 8;
    }

    void WinApplication::registerNativeCallback(x86::reg32 guest, void *native)
    {
        nativeCallbacks()[guest] = x86::reg32(reinterpret_cast<uintptr_t>(native));
    }

    // The bridge to the real API passes a native function only the arguments it
    // declares, so a shim that needs the application -- CreateThread, for one --
    // has no way of being handed it. There is one of these per process.
    static WinApplication *s_current = nullptr;

    WinApplication *WinApplication::current()
    {
        return s_current;
    }

    WinApplication::WinApplication()
    {
        NFS2_ASSERT(!s_current);
        s_current = this;
    }

    WinApplication::~WinApplication()
    {
        s_current = nullptr;
    }

    void WinApplication::registerMethod(x86::reg32 pointer, Method method)
    {
        NFS2_ASSERT(m_methods.find(pointer - 0x400000) == m_methods.end());
        m_methods[pointer - 0x400000] = method;
    }

    void WinApplication::nativeCall(x86::reg32 address, x86::CPU &cpu)
    {
        if (address >= image().start && address < image().end)
        {
            // Inside the image, so it should have been a translated routine that
            // registerMethod knows about. Reaching here means the call target was
            // never registered -- most often a routine reached only through a
            // computed address, which the analysis did not see.
            printf("unregistered call target inside the image: 0x%08x\n", address);
            fflush(stdout);
            NFS2_ASSERT(false);
        }

        // The signature does not have to be known. The arguments are already laid
        // out on the stack in the ordinary x86 way, above the slot the generated
        // call reserved for a return address, so standing on that stack and
        // issuing a real call is enough. However much the callee pops on the way
        // out is what its calling convention pops, which is exactly the
        // adjustment the generated code expects to find.
        // A callback among the arguments is an address in the original binary,
        // which real code cannot call, so it goes over as its native entry
        // instead. The slots are put back afterwards: past the arguments the
        // window reaches into the caller's own frame, which must not change.
        struct Swap
        {
            x86::reg32 *slot;
            x86::reg32 value;
        } swaps[CALLBACK_ARGUMENTS];
        unsigned swapped = 0;
        const std::unordered_map<x86::reg32, x86::reg32> &callbacks = nativeCallbacks();
        if (!callbacks.empty())
        {
            x86::reg32 *arguments = reinterpret_cast<x86::reg32 *>(cpu.esp + 4);
            for (unsigned i = 0; i < CALLBACK_ARGUMENTS; ++i)
            {
                std::unordered_map<x86::reg32, x86::reg32>::const_iterator it =
                    callbacks.find(arguments[i]);
                if (it != callbacks.end())
                {
                    swaps[swapped++] = {&arguments[i], arguments[i]};
                    arguments[i] = it->second;
                }
            }
        }

        NativeCallFrame frame;
        frame.target = address;
        frame.esp = cpu.esp + 4;
        frame.eax = cpu.eax;
        frame.ecx = cpu.ecx;
        frame.edx = cpu.edx;

        rosemondNativeCall(&frame);

        for (unsigned i = 0; i < swapped; ++i)
        {
            *swaps[i].slot = swaps[i].value;
        }

        cpu.eax = frame.eax;
        cpu.edx = frame.edx;
        cpu.esp = frame.esp;
        // A value returned on the x87 stack cannot be spotted from here; a native
        // function returning float or double would need its signature.
    }

    x86::reg32 WinApplication::callGuest(x86::reg32 address,
                                        const x86::reg32 *arguments,
                                        unsigned count)
    {
        // A stack and an FS block of its own, for the same reasons runThread
        // gives the thread one, and taken from the same place -- this frame. A
        // callback can arrive while translated code is already running and can
        // nest, so it cannot borrow the stack that code is standing on.
        alignas(16) x86::reg8 stack[CALLBACK_STACK];
        alignas(16) x86::reg32 storage[16] = {0xffffffff};

        x86::CPU cpu{};
        cpu.init(x86::reg32(reinterpret_cast<uintptr_t>(storage)), address);

        // The frame a translated routine expects: arguments above the
        // return-address slot that cg_call reserves and cg_ret pops.
        x86::reg32 esp = x86::reg32(reinterpret_cast<uintptr_t>(stack + sizeof stack))
                         - 4 * (count + 1);
        for (unsigned i = 0; i < count; ++i)
        {
            getMemory<x86::reg32>(esp + 4 + 4 * i) = arguments[i];
        }
        getMemory<x86::reg32>(esp) = cpu.ip;
        cpu.esp = esp;

        dynamic_call(address, cpu);
        return cpu.eax;
    }

    int WinApplication::runThread(x86::CPU &cpu, x86::reg32 entryPoint,
                                  x86::reg32 parameter)
    {
        // The translated code's stack is this thread's stack. Reserving it as a
        // frame here means the native calls the translated code makes get their
        // frames below it, so the two never meet, and the trampoline can hand a
        // real callee a stack pointer into it.
        alignas(16) x86::reg8 stack[GUEST_STACK];

        // Four bytes the translated code reads as the head of the
        // structured-exception chain its prologues push onto; the only thing this
        // binary uses the FS base for.
        alignas(16) x86::reg32 storage[16] = {0xffffffff};

        cpu.init(x86::reg32(reinterpret_cast<uintptr_t>(storage)), entryPoint);

        // Lay out the frame the entry point expects: its argument above the
        // return-address slot that cg_call reserves and cg_ret pops.
        cpu.esp = x86::reg32(reinterpret_cast<uintptr_t>(stack + sizeof stack)) - 8;
        getMemory<x86::reg32>(cpu.esp + 4) = parameter;
        getMemory<x86::reg32>(cpu.esp) = cpu.ip;

        dynamic_call(entryPoint, cpu);
        return int(cpu.eax);
    }

}
