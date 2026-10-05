#ifndef GHIDRA_COMPAT_H_
#define GHIDRA_COMPAT_H_

// What Ghidra's decompiler output assumes exists: its builtin type names and
// the pseudo-operations it writes when the C type system cannot say what the
// machine code did (CONCAT31, SUB41, CARRY4, ...). Everything a decompiled
// function needs beyond the generated headers in src/game/ghidra is here.

#include <windows.h>
#include <mmsystem.h>

#include <cmath>
#include <cstdint>
#include <cstring>
#include <type_traits>

// Ghidra's builtin types, sized as Ghidra sizes them for 32-bit Windows.
typedef unsigned char undefined;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned long long undefined8;
struct undefined3 { unsigned char bytes[3]; };
struct undefined5 { unsigned char bytes[5]; };
struct undefined6 { unsigned char bytes[6]; };
struct undefined7 { unsigned char bytes[7]; };
typedef unsigned char byte;
typedef signed char sbyte;
typedef unsigned char uchar;
typedef signed char schar;
typedef unsigned short word;
typedef short sword;
typedef unsigned short ushort;
typedef unsigned int dword;
typedef int sdword;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long qword;
typedef long long sqword;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned int uint3;
typedef int int3;
typedef unsigned long long uint5;
typedef unsigned long long uint6;
typedef unsigned long long uint7;
typedef long long int5;
typedef long long int6;
typedef long long int7;
typedef wchar_t wchar16;
typedef char32_t wchar32;
// The decompiler's x87 temporaries. The emulated FPU computes in double too.
typedef double float10;
typedef double longdouble;
// A function whose signature Ghidra does not know. Calling one of these
// directly runs the original machine code natively, which is almost never what
// is wanted: an indirect call into the game belongs in win32::guestCall.
typedef void code(...);

namespace ghidra
{
    template <int N>
    using uintN = std::conditional_t<(N <= 1), uint8_t,
                  std::conditional_t<(N <= 2), uint16_t,
                  std::conditional_t<(N <= 4), uint32_t, uint64_t>>>;
    template <int N>
    using sintN = std::make_signed_t<uintN<N>>;

    template <typename T>
    inline uint64_t bits(T value)
    {
        uint64_t result = 0;
        std::memcpy(&result, &value, sizeof(T) < 8 ? sizeof(T) : 8);
        return result;
    }

    template <int N>
    inline uint64_t mask(uint64_t value)
    {
        return N >= 8 ? value : value & ((uint64_t(1) << (8 * N)) - 1);
    }

    template <int X, int Y, typename A, typename B>
    inline uintN<X + Y> concat(A high, B low)
    {
        return uintN<X + Y>((mask<X>(bits(high)) << (8 * Y)) | mask<Y>(bits(low)));
    }

    template <int X, int Y, typename V>
    inline uintN<Y> sub(V value, int offset)
    {
        return uintN<Y>(mask<Y>(bits(value) >> (8 * offset)));
    }

    template <int X, int Y, typename V>
    inline uintN<Y> zext(V value)
    {
        return uintN<Y>(mask<X>(bits(value)));
    }

    template <int X, int Y, typename V>
    inline sintN<Y> sext(V value)
    {
        return sintN<Y>(sintN<X>(uintN<X>(mask<X>(bits(value)))));
    }

    // The address of a routine of the game, as decompiled code stores it for
    // translated code to call later (a callback in a structure, say). It is the
    // address in the image -- what dynamic_call looks up -- and converts to
    // whatever pointer or integer the decompiler thought it was.
    struct CodeAddress
    {
        uint32_t value;

        template <typename T>
        operator T *() const
        {
            return reinterpret_cast<T *>(uintptr_t(value));
        }
        operator uint32_t() const
        {
            return value;
        }
    };

    constexpr CodeAddress code_address(uint32_t value)
    {
        return CodeAddress{value};
    }

    inline int popcount(uint64_t value)
    {
        int count = 0;
        for (; value; value &= value - 1)
        {
            ++count;
        }
        return count;
    }

    template <int N, typename A, typename B>
    inline bool carry(A a, B b)
    {
        return uintN<N>(uintN<N>(a) + uintN<N>(b)) < uintN<N>(a);
    }

    template <int N, typename A, typename B>
    inline bool scarry(A a, B b)
    {
        sintN<N> x = sintN<N>(a), y = sintN<N>(b);
        sintN<N> r = sintN<N>(uintN<N>(x) + uintN<N>(y));
        return (x >= 0) == (y >= 0) && (r >= 0) != (x >= 0);
    }

    template <int N, typename A, typename B>
    inline bool sborrow(A a, B b)
    {
        sintN<N> x = sintN<N>(a), y = sintN<N>(b);
        sintN<N> r = sintN<N>(uintN<N>(x) - uintN<N>(y));
        return (x >= 0) != (y >= 0) && (r >= 0) != (x >= 0);
    }
}

#define CONCAT11(a, b) ghidra::concat<1, 1>((a), (b))
#define CONCAT12(a, b) ghidra::concat<1, 2>((a), (b))
#define CONCAT13(a, b) ghidra::concat<1, 3>((a), (b))
#define CONCAT14(a, b) ghidra::concat<1, 4>((a), (b))
#define CONCAT15(a, b) ghidra::concat<1, 5>((a), (b))
#define CONCAT16(a, b) ghidra::concat<1, 6>((a), (b))
#define CONCAT17(a, b) ghidra::concat<1, 7>((a), (b))
#define CONCAT21(a, b) ghidra::concat<2, 1>((a), (b))
#define CONCAT22(a, b) ghidra::concat<2, 2>((a), (b))
#define CONCAT23(a, b) ghidra::concat<2, 3>((a), (b))
#define CONCAT24(a, b) ghidra::concat<2, 4>((a), (b))
#define CONCAT25(a, b) ghidra::concat<2, 5>((a), (b))
#define CONCAT26(a, b) ghidra::concat<2, 6>((a), (b))
#define CONCAT31(a, b) ghidra::concat<3, 1>((a), (b))
#define CONCAT32(a, b) ghidra::concat<3, 2>((a), (b))
#define CONCAT33(a, b) ghidra::concat<3, 3>((a), (b))
#define CONCAT34(a, b) ghidra::concat<3, 4>((a), (b))
#define CONCAT35(a, b) ghidra::concat<3, 5>((a), (b))
#define CONCAT41(a, b) ghidra::concat<4, 1>((a), (b))
#define CONCAT42(a, b) ghidra::concat<4, 2>((a), (b))
#define CONCAT43(a, b) ghidra::concat<4, 3>((a), (b))
#define CONCAT44(a, b) ghidra::concat<4, 4>((a), (b))
#define CONCAT51(a, b) ghidra::concat<5, 1>((a), (b))
#define CONCAT52(a, b) ghidra::concat<5, 2>((a), (b))
#define CONCAT53(a, b) ghidra::concat<5, 3>((a), (b))
#define CONCAT61(a, b) ghidra::concat<6, 1>((a), (b))
#define CONCAT62(a, b) ghidra::concat<6, 2>((a), (b))
#define CONCAT71(a, b) ghidra::concat<7, 1>((a), (b))
#define SUB21(v, offset) ghidra::sub<2, 1>((v), (offset))
#define SUB31(v, offset) ghidra::sub<3, 1>((v), (offset))
#define SUB32(v, offset) ghidra::sub<3, 2>((v), (offset))
#define SUB41(v, offset) ghidra::sub<4, 1>((v), (offset))
#define SUB42(v, offset) ghidra::sub<4, 2>((v), (offset))
#define SUB43(v, offset) ghidra::sub<4, 3>((v), (offset))
#define SUB51(v, offset) ghidra::sub<5, 1>((v), (offset))
#define SUB52(v, offset) ghidra::sub<5, 2>((v), (offset))
#define SUB53(v, offset) ghidra::sub<5, 3>((v), (offset))
#define SUB54(v, offset) ghidra::sub<5, 4>((v), (offset))
#define SUB61(v, offset) ghidra::sub<6, 1>((v), (offset))
#define SUB62(v, offset) ghidra::sub<6, 2>((v), (offset))
#define SUB63(v, offset) ghidra::sub<6, 3>((v), (offset))
#define SUB64(v, offset) ghidra::sub<6, 4>((v), (offset))
#define SUB65(v, offset) ghidra::sub<6, 5>((v), (offset))
#define SUB71(v, offset) ghidra::sub<7, 1>((v), (offset))
#define SUB72(v, offset) ghidra::sub<7, 2>((v), (offset))
#define SUB73(v, offset) ghidra::sub<7, 3>((v), (offset))
#define SUB74(v, offset) ghidra::sub<7, 4>((v), (offset))
#define SUB75(v, offset) ghidra::sub<7, 5>((v), (offset))
#define SUB76(v, offset) ghidra::sub<7, 6>((v), (offset))
#define SUB81(v, offset) ghidra::sub<8, 1>((v), (offset))
#define SUB82(v, offset) ghidra::sub<8, 2>((v), (offset))
#define SUB83(v, offset) ghidra::sub<8, 3>((v), (offset))
#define SUB84(v, offset) ghidra::sub<8, 4>((v), (offset))
#define SUB85(v, offset) ghidra::sub<8, 5>((v), (offset))
#define SUB86(v, offset) ghidra::sub<8, 6>((v), (offset))
#define SUB87(v, offset) ghidra::sub<8, 7>((v), (offset))
#define ZEXT12(v) ghidra::zext<1, 2>(v)
#define SEXT12(v) ghidra::sext<1, 2>(v)
#define ZEXT13(v) ghidra::zext<1, 3>(v)
#define SEXT13(v) ghidra::sext<1, 3>(v)
#define ZEXT14(v) ghidra::zext<1, 4>(v)
#define SEXT14(v) ghidra::sext<1, 4>(v)
#define ZEXT15(v) ghidra::zext<1, 5>(v)
#define SEXT15(v) ghidra::sext<1, 5>(v)
#define ZEXT16(v) ghidra::zext<1, 6>(v)
#define SEXT16(v) ghidra::sext<1, 6>(v)
#define ZEXT17(v) ghidra::zext<1, 7>(v)
#define SEXT17(v) ghidra::sext<1, 7>(v)
#define ZEXT18(v) ghidra::zext<1, 8>(v)
#define SEXT18(v) ghidra::sext<1, 8>(v)
#define ZEXT23(v) ghidra::zext<2, 3>(v)
#define SEXT23(v) ghidra::sext<2, 3>(v)
#define ZEXT24(v) ghidra::zext<2, 4>(v)
#define SEXT24(v) ghidra::sext<2, 4>(v)
#define ZEXT25(v) ghidra::zext<2, 5>(v)
#define SEXT25(v) ghidra::sext<2, 5>(v)
#define ZEXT26(v) ghidra::zext<2, 6>(v)
#define SEXT26(v) ghidra::sext<2, 6>(v)
#define ZEXT27(v) ghidra::zext<2, 7>(v)
#define SEXT27(v) ghidra::sext<2, 7>(v)
#define ZEXT28(v) ghidra::zext<2, 8>(v)
#define SEXT28(v) ghidra::sext<2, 8>(v)
#define ZEXT34(v) ghidra::zext<3, 4>(v)
#define SEXT34(v) ghidra::sext<3, 4>(v)
#define ZEXT35(v) ghidra::zext<3, 5>(v)
#define SEXT35(v) ghidra::sext<3, 5>(v)
#define ZEXT36(v) ghidra::zext<3, 6>(v)
#define SEXT36(v) ghidra::sext<3, 6>(v)
#define ZEXT37(v) ghidra::zext<3, 7>(v)
#define SEXT37(v) ghidra::sext<3, 7>(v)
#define ZEXT38(v) ghidra::zext<3, 8>(v)
#define SEXT38(v) ghidra::sext<3, 8>(v)
#define ZEXT45(v) ghidra::zext<4, 5>(v)
#define SEXT45(v) ghidra::sext<4, 5>(v)
#define ZEXT46(v) ghidra::zext<4, 6>(v)
#define SEXT46(v) ghidra::sext<4, 6>(v)
#define ZEXT47(v) ghidra::zext<4, 7>(v)
#define SEXT47(v) ghidra::sext<4, 7>(v)
#define ZEXT48(v) ghidra::zext<4, 8>(v)
#define SEXT48(v) ghidra::sext<4, 8>(v)
#define ZEXT56(v) ghidra::zext<5, 6>(v)
#define SEXT56(v) ghidra::sext<5, 6>(v)
#define ZEXT57(v) ghidra::zext<5, 7>(v)
#define SEXT57(v) ghidra::sext<5, 7>(v)
#define ZEXT58(v) ghidra::zext<5, 8>(v)
#define SEXT58(v) ghidra::sext<5, 8>(v)
#define ZEXT67(v) ghidra::zext<6, 7>(v)
#define SEXT67(v) ghidra::sext<6, 7>(v)
#define ZEXT68(v) ghidra::zext<6, 8>(v)
#define SEXT68(v) ghidra::sext<6, 8>(v)
#define ZEXT78(v) ghidra::zext<7, 8>(v)
#define SEXT78(v) ghidra::sext<7, 8>(v)
#define CARRY1(a, b) ghidra::carry<1>((a), (b))
#define SCARRY1(a, b) ghidra::scarry<1>((a), (b))
#define SBORROW1(a, b) ghidra::sborrow<1>((a), (b))
#define CARRY2(a, b) ghidra::carry<2>((a), (b))
#define SCARRY2(a, b) ghidra::scarry<2>((a), (b))
#define SBORROW2(a, b) ghidra::sborrow<2>((a), (b))
#define CARRY4(a, b) ghidra::carry<4>((a), (b))
#define SCARRY4(a, b) ghidra::scarry<4>((a), (b))
#define SBORROW4(a, b) ghidra::sborrow<4>((a), (b))
#define CARRY8(a, b) ghidra::carry<8>((a), (b))
#define SCARRY8(a, b) ghidra::scarry<8>((a), (b))
#define SBORROW8(a, b) ghidra::sborrow<8>((a), (b))

#define POPCOUNT(v) ghidra::popcount(ghidra::bits(v))
#define ROUND(v) ((int)std::nearbyint(v))
#define TRUNC(v) ((int)(v))
#define NAN_CHECK(v) ((v) != (v))

#endif /* !GHIDRA_COMPAT_H_ */
