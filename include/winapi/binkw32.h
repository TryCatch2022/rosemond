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

#define BINKEXPORT __declspec(dllimport)

extern "C"
{

#define BINKSURFACE24 1
#define BINKSURFACE32 3
#define BINKSURFACE555 9
#define BINKSURFACE565 10
#define BINKPRELOADALL 0x00002000
#define BINKCOPYNOSCALING 0x70000000

    typedef struct BINK
    {
        unsigned int Width;
        unsigned int Height;
        unsigned int Frames;
        unsigned int FrameNum;
        unsigned int LastFrameNum;
        unsigned int FrameRate;
        unsigned int FrameRateDiv;
        /* Original struct has more members, but we only need these to match the ABI*/
    } BINK, *HBINK;

    typedef void *(__stdcall *SndOpenCallback)(unsigned long param);
    typedef unsigned int u32;

    BINKEXPORT HBINK __stdcall BinkOpen(const char *name, unsigned int flags);
    BINKEXPORT void __stdcall BinkSetSoundTrack(unsigned int total_tracks, unsigned int *tracks);
    BINKEXPORT int __stdcall BinkSetSoundSystem(SndOpenCallback open, unsigned long param);
    BINKEXPORT void *__stdcall BinkOpenDirectSound(unsigned long param);
    BINKEXPORT void __stdcall BinkClose(HBINK handle);
    BINKEXPORT int __stdcall BinkWait(HBINK handle);
    BINKEXPORT int __stdcall BinkDoFrame(HBINK handle);
    BINKEXPORT int __stdcall BinkCopyToBuffer(
        HBINK handle, void *dest, int destpitch, unsigned int destheight, unsigned int destx, unsigned int desty, unsigned int flags);
    BINKEXPORT void __stdcall BinkSetVolume(HBINK handle, unsigned int trackid, int volume);
    BINKEXPORT void __stdcall BinkNextFrame(HBINK handle);
    BINKEXPORT void __stdcall BinkGoto(HBINK handle, unsigned int frame, int flags);
    BINKEXPORT int __stdcall BinkDDSurfaceType(void *lpDDS);
    BINKEXPORT int __stdcall BinkIsSoftwareCursor(void *lpDDSP, void * /*HCURSOR*/ cur);
    BINKEXPORT char *__stdcall BinkGetError(void);

#define BinkSoundUseDirectSound(x) BinkSetSoundSystem(BinkOpenDirectSound, (unsigned long)x)

} // extern "C"

namespace win32::binkw32
{
    using ::BinkClose;
    using ::BinkCopyToBuffer;
    using ::BinkDDSurfaceType;
    using ::BinkDoFrame;
    using ::BinkGetError;
    using ::BinkIsSoftwareCursor;
    using ::BinkNextFrame;
    using ::BinkOpen;
    using ::BinkOpenDirectSound;
    // Not the real BinkSetSoundSystem: the sound-system opener the program
    // passes is an address of its own. See lib/callbacks.cpp.
    int __stdcall BinkSetSoundSystem(SndOpenCallback open, unsigned long param);
    using ::BinkWait;
}