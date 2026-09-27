#ifndef LIB_WINAPP_H_
#define LIB_WINAPP_H_

#include <x86.h>
#include <cpu.h>
#include <fpu.h>
#include <string>
#include <unordered_map>

namespace win32
{

    class WinApplication;

    typedef void (*MethodPtr)(WinApplication *application, x86::CPU &cpu);

    struct Method
    {
        std::string name;
        MethodPtr method;

        void operator()(WinApplication *application, x86::CPU &cpu) const
        {
            method(application, cpu);
        }
    };


    template <typename T>
    struct MemoryAccessor
    {
        friend class WinApplication;

    private:
        MemoryAccessor(x86::reg8 *address) : address(address) {}
        x86::reg8 *address;

    public:
        MemoryAccessor(const MemoryAccessor &other) = default;
        MemoryAccessor &operator=(const MemoryAccessor &other)
        {
            if (this != &other)
            {
                T value = other;
                memcpy(address, &value, sizeof(T));
            }
            return *this;
        }
        operator T() const
        {
            T result;
            memcpy(&result, address, sizeof(T));
            return result;
        }
        explicit operator T &()
        {
            return *reinterpret_cast<T *>(address);
        }
        MemoryAccessor &operator=(T value)
        {
            memcpy(address, &value, sizeof(T));
            return *this;
        }
        T operator-=(T value)
        {
            T result = *this;
            result -= value;
            memcpy(address, &result, sizeof(T));
            return result;
        }
        T operator+=(T value)
        {
            T result = *this;
            result += value;
            memcpy(address, &result, sizeof(T));
            return result;
        }
        T operator|=(T value)
        {
            T result = *this;
            result |= value;
            memcpy(address, &result, sizeof(T));
            return result;
        }
        T operator&=(T value)
        {
            T result = *this;
            result &= value;
            memcpy(address, &result, sizeof(T));
            return result;
        }
        T operator^=(T value)
        {
            T result = *this;
            result ^= value;
            memcpy(address, &result, sizeof(T));
            return result;
        }
        T operator>>=(T value)
        {
            T result = *this;
            result >>= value;
            memcpy(address, &result, sizeof(T));
            return result;
        }
        T operator<<=(T value)
        {
            T result = *this;
            result <<= value;
            memcpy(address, &result, sizeof(T));
            return result;
        }
        T operator++(int)
        {
            T result = *this;
            T newValue = result;
            newValue++;
            memcpy(address, &newValue, sizeof(T));
            return result;
        }
        T operator--(int)
        {
            T result = *this;
            T newValue = result;
            newValue--;
            memcpy(address, &newValue, sizeof(T));
            return result;
        }
        T operator++()
        {
            T result = *this;
            T newValue = result;
            newValue++;
            memcpy(address, &newValue, sizeof(T));
            return newValue;
        }
        T operator--()
        {
            T result = *this;
            T newValue = result;
            newValue--;
            memcpy(address, &newValue, sizeof(T));
            return newValue;
        }
        T *operator&() { return reinterpret_cast<T *>(address); }
    };

    template <>
    struct MemoryAccessor<x86::IEEEf80>
    {
        friend class WinApplication;

    private:
        MemoryAccessor(x86::reg8 *address) : address(address) {}
        x86::reg8 *address;

    public:
        MemoryAccessor(const MemoryAccessor &other) = default;
        MemoryAccessor &operator=(const MemoryAccessor &other) = delete;
        operator x86::Float() const
        {
            x86::IEEEf80Data result;
            memcpy(&result, address, sizeof(x86::IEEEf80Data));
            return double(x86::IEEEf80(result));
        }
        operator x86::IEEEf80() const
        {
            x86::IEEEf80Data result;
            memcpy(&result, address, sizeof(x86::IEEEf80Data));
            return x86::IEEEf80(result);
        }
        MemoryAccessor &operator=(x86::Float value)
        {
            x86::IEEEf80 f80value(value);
            memcpy(address, &f80value.data, sizeof(x86::IEEEf80Data));
            return *this;
        }
        MemoryAccessor &operator=(x86::IEEEf80 value)
        {
            memcpy(address, &value.data, sizeof(x86::IEEEf80Data));
            return *this;
        }
    };

    template <>
    struct MemoryAccessor<void>
    {
        friend class WinApplication;

    private:
        MemoryAccessor(x86::reg8 *address) : address(address) {}
        x86::reg8 *address;

    public:
        MemoryAccessor(const MemoryAccessor &other) = default;
        MemoryAccessor &operator=(const MemoryAccessor &other) = delete;
        void *operator&() { return reinterpret_cast<void *>(address); }
    };

    template <>
    struct MemoryAccessor<const void>
    {
        friend class WinApplication;

    private:
        MemoryAccessor(x86::reg8 *address) : address(address) {}
        x86::reg8 *address;

    public:
        MemoryAccessor(const MemoryAccessor &other) = default;
        MemoryAccessor &operator=(const MemoryAccessor &other) = delete;
        const void *operator&() { return reinterpret_cast<const void *>(address); }
    };

    class WinApplication
    {
    public:
        WinApplication();
        ~WinApplication();

        // The executable's segments are sections of this image, mapped by the
        // loader at the addresses the original binary was linked for, so an
        // address the recompiled code holds is already a real one.
        template <typename T>
        inline MemoryAccessor<T> getMemory(x86::reg32 address) { return MemoryAccessor<T>{reinterpret_cast<x86::reg8 *>(address)}; }

        void registerMethod(x86::reg32 pointer, Method method);

        // Enter a translated routine, or real machine code if the address is not
        // one. Out of line because entering real code switches stacks.
        inline void dynamic_call(x86::reg32 address, x86::CPU &cpu)
        {
            std::unordered_map<x86::reg32, Method>::const_iterator it =
                m_methods.find(address - 0x400000);
            if (it != m_methods.end())
            {
                it->second(this, cpu);
            }
            else
            {
                // Not a translated routine, so it is real machine code: a pointer
                // the program fetched with GetProcAddress, or a slot in a COM or
                // DirectX vtable. Its signature is unknown and need not be.
                nativeCall(address, cpu);
            }
        }

        void nativeCall(x86::reg32 address, x86::CPU &cpu);

        // The other direction: enter translated code from a native caller, with
        // count dword arguments laid out the way a stdcall callee expects. This
        // is what a callback the program handed to the API has to go through --
        // its window procedure, for one -- because the address it gave is an
        // address in the original binary, not a function this process can call.
        x86::reg32 callGuest(x86::reg32 address, const x86::reg32 *arguments,
                             unsigned count);

        // A routine the program hands to real code by passing its address
        // straight to a COM method, where no API wrapper sees it. nativeCall
        // swaps that address for native, a function that enters the routine
        // through callGuest, in the arguments of any call it makes.
        static void registerNativeCallback(x86::reg32 guest, void *native);

        // Run translated code from entryPoint on this thread, with its own stack
        // and its own FS block.
        int runThread(x86::CPU &cpu, x86::reg32 entryPoint, x86::reg32 parameter = 0);

        static WinApplication *current();

    protected:
        std::unordered_map<x86::reg32, Method> m_methods;
    };

}

#endif
