#ifndef MMX_H_
#define MMX_H_

#include <x86.h>
#include <emmintrin.h>

namespace x86
{

    struct regmmx
    {
        __m128i reg;
        operator x86::reg64() const
        {
            x86::reg64 result;
            _mm_storel_epi64(reinterpret_cast<__m128i *>(&result), reg);
            return result;
        }
        operator __m128i() const
        {
            return reg;
        }
    };

    static inline regmmx from_reg64(const x86::reg64 &value)
    {
        regmmx result;
        result.reg = _mm_loadl_epi64(reinterpret_cast<const __m128i *>(&value));
        return result;
    }

    struct MMX
    {
        regmmx mm0;
        regmmx mm1;
        regmmx mm2;
        regmmx mm3;
        regmmx mm4;
        regmmx mm5;
        regmmx mm6;
        regmmx mm7;
        void init()
        {
            memset(this, 0, sizeof(*this));
        }
    };

}

#endif /* !MMX_H_ */
