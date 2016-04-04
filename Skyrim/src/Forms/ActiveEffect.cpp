#include "Skyrim/Forms/ActiveEffect.h"
#include "Skyrim/Forms/Actor.h"

Actor * ActiveEffect::GetCasterActor() const
{
	TESObjectREFRPtr refPtr;
	TESObjectREFR::LookupByHandle(casterRefhandle, refPtr);
	if (!refPtr)
		return nullptr;

	Actor * actor = static_cast<Actor *>((TESObjectREFR *)refPtr);
	return actor;
}


Actor * ActiveEffect::GetTargetActor() const
{
	Actor * actor = nullptr;
	if (magicTarget && magicTarget->IsActorMagicTarget())
		actor = static_cast<Actor *>(magicTarget);
	return actor;
}
