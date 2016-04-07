#include "Skyrim.h"
#include "Skyrim/TESForms/Character/BGSLocAlias.h"
#include "Skyrim/TESForms/Character/TESQuest.h"

void BGSLocAlias::Clear(void)
{
	if ((flags & kFlag_Optional) != 0)
		owner->ClearLocationAlias(this);
}
