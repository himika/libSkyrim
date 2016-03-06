#include "Skyrim.h"
#include "Skyrim/Forms/BGSLocAlias.h"
#include "Skyrim/Forms/TESQuest.h"

void BGSLocAlias::Clear(void)
{
	if ((flags & kFlag_Optional) != 0)
		owner->ClearLocationAlias(this);
}
