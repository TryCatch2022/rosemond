// Lerp at 0x0041f9f0, decompiled by Ghidra.
//
// This file belongs to the project now: edit it freely. Until you do, every
// export rewrites it, so it follows what changes in Ghidra; once edited, an
// export only renames in it what was renamed in Ghidra. Its signature still
// belongs to Ghidra (functions.h, and the stub translated code calls it
// through), so change that in Ghidra.

#include <decomp.h>

namespace game
{

void Lerp(InterpolatingFloat *this_, float lerpT)
{
	int array[] = { 0, 1, 2 };
	this_->current = (this_->end - this_->start) * lerpT + this_->start;
	return;
}

}
