#pragma once

struct InterpolatingFloat 
{
    float start;
    float end;
    float current;

    void interpolate(float factor) {
        current = start + (end - start) * factor;
    }
};
static_assert(sizeof(InterpolatingFloat) == 0xc, "InterpolatingFloat has wrong size");

struct HorseUserData {
    char field0_0x0[0x47];
    int id;
    char field73_0x4c[8];
    int index; /* into DAT_004912c8 for new random offset? */
    char field82_0x58[4];
    struct InterpolatingFloat interpolatingFloat1;
    struct InterpolatingFloat interpolatingFloat2;
    struct InterpolatingFloat interpolatingFloat3;
    int task;
    int taskCount;
    char field91_0x88[0x9c];
    float gameTime; /* Created by Rename Structure Field action */
    float interpolationFactor; /* Created by Rename Structure Field action */
    char field246_0x12c[4];
    int flags; /* Created by Rename Structure Field action */
    char field251_0x134[9804];
};
static_assert(sizeof(HorseUserData) == 0x2780, "HorseUserData has wrong size");