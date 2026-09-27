#pragma once

#if !defined _MSC_VER
#if !defined(__stdcall)
#if defined __has_attribute && __has_attribute(stdcall)
#define __stdcall __attribute__((stdcall))
#else
#define __stdcall
#endif
#endif /* !defined __stdcall */
#endif /* !defined COMPILER_MSVC */

#define SMACKEXPORT __declspec(dllimport)

// Declarations for the nine smackw32.dll entry points this executable imports.
// The argument counts were read off the call sites in the recompiled code (the
// number of pushes in the basic block leading to each `call dword ptr [IAT]`)
// and agree with RAD's published Smacker API, which is what fixes the stdcall
// stack adjustment the bridge performs.

extern "C"
{

#define SMACKTRACKS      0x000f0000
#define SMACKAUTOEXTRA   0x80000000
#define SMACKNEEDVOLUME  0x00400000
#define SMACKBUFFER565   0x80000000

    // The game only holds the handle; it is never allocated here.  If it turns
    // out to read fields out of it, mirror the leading members the way
    // binkw32.h does for BINK so the layout matches.
    typedef struct SMACK SMACK, *HSMACK;

    SMACKEXPORT SMACK *__stdcall SmackOpen(const char *name, unsigned int flags, int extrabuf);
    SMACKEXPORT void __stdcall SmackClose(SMACK *smk);
    SMACKEXPORT unsigned int __stdcall SmackDoFrame(SMACK *smk);
    SMACKEXPORT void __stdcall SmackNextFrame(SMACK *smk);
    SMACKEXPORT unsigned int __stdcall SmackWait(SMACK *smk);
    SMACKEXPORT unsigned int __stdcall SmackToBuffer(
        SMACK *smk, unsigned int left, unsigned int top, unsigned int pitch,
        unsigned int destheight, void *dest, unsigned int flags);
    SMACKEXPORT unsigned int __stdcall SmackSoundUseDirectSound(void *dsound);
    SMACKEXPORT unsigned int __stdcall SmackDDSurfaceType(void *lpDDS);
    SMACKEXPORT int __stdcall SmackIsSoftwareCursor(void *lpDDSP, void *cur);

} // extern "C"

namespace win32::smackw32
{
    using ::SmackClose;
    using ::SmackDDSurfaceType;
    using ::SmackDoFrame;
    using ::SmackIsSoftwareCursor;
    using ::SmackNextFrame;
    using ::SmackOpen;
    using ::SmackSoundUseDirectSound;
    using ::SmackToBuffer;
    using ::SmackWait;
}
