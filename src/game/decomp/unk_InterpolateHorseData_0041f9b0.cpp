// unk_InterpolateHorseData at 0x0041f9b0, decompiled by Ghidra.
//
// This file belongs to the project now: edit it freely. Until you do, every
// export rewrites it, so it follows what changes in Ghidra; once edited, an
// export only renames in it what was renamed in Ghidra. Its signature still
// belongs to Ghidra (functions.h, and the stub translated code calls it
// through), so change that in Ghidra.

#include <decomp.h>

namespace game
{

void unk_InterpolateHorseData(Entity* entity)
{
	if (entity && entity->horseData) 
	{
		HorseUserData* horseData = entity->horseData;
		const float lerpT = horseData->interpolationFactor;

		Lerp(&horseData->interpolatingFloat1,lerpT);
		Lerp(&horseData->interpolatingFloat2,lerpT);
		Lerp(&horseData->interpolatingFloat3,lerpT);
	}
	return;
}

}
