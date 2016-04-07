#include "Skyrim.h"
#include "Skyrim/TESForms/World/PlayerCharacter.h"

PlayerCharacter *& g_thePlayer = *(PlayerCharacter **)0x01B2E8E4;

typedef UInt32 (*_LookupActorValueByName)(const char * name);
static const _LookupActorValueByName LookupActorValueByName = (_LookupActorValueByName)0x005AD5F0;

SInt32 PlayerSkills::ResolveAdvanceableSkillId(SInt32 actorValue)
{
	if (actorValue - kAdvanceableSkillOffset >= 0 && actorValue < kNumAdvanceableSkills + kAdvanceableSkillOffset)
		return actorValue - kAdvanceableSkillOffset;

	return -1;
}

float PlayerSkills::GetSkillPoints(const BSFixedString &actorValue)
{
	if (data) {
		UInt32 avId = LookupActorValueByName(actorValue);
		SInt32 skillId = ResolveAdvanceableSkillId(avId);
		if (skillId != -1)
			return data->levelData[skillId].points;
	}

	return 0.0;
}

void PlayerSkills::SetSkillPoints(const BSFixedString & actorValue, float points)
{
	if (data) {
		UInt32 avId = LookupActorValueByName(actorValue);
		SInt32 skillId = ResolveAdvanceableSkillId(avId);
		if (skillId != -1)
			data->levelData[skillId].points = points;
	}
}

SInt32 PlayerSkills::GetSkillLegendaryLevel(const BSFixedString & actorValue)
{
	if (data) {
		UInt32 avId = LookupActorValueByName(actorValue);
		SInt32 skillId = ResolveAdvanceableSkillId(avId);
		if (skillId != -1)
			return data->legendaryLevel[skillId];
	}

	return -1;
}

void PlayerSkills::SetSkillLegendaryLevel(const BSFixedString & actorValue, UInt32 level)
{
	if (data) {
		UInt32 avId = LookupActorValueByName(actorValue);
		SInt32 skillId = ResolveAdvanceableSkillId(avId);
		if (skillId != -1)
			data->legendaryLevel[skillId] = level;
	}
}

TESObjectREFR * PlayerCharacter::GetGrabbedRef() const
{
	TESObjectREFRPtr refPtr = nullptr;
	RefHandle handle = playerGrabbedHandle;
	if (handle != g_invalidRefHandle)
	{
		TESObjectREFR::LookupByHandle(handle, refPtr);
	}
	return refPtr;
}

TintMask * PlayerCharacter::GetOverlayTintMask(TintMask * original)
{
	SInt32 curIndex = -1;
	if (!overlayTintMasks)
		return nullptr;

	TintMask * foundMask = nullptr;
	UInt32 i = 0;
	while (tintMasks.GetAt(i, foundMask))
	{
		if (foundMask == original) {
			curIndex = i;
			break;
		}
		++i;
	}

	if (overlayTintMasks->GetAt(curIndex, foundMask))
		return foundMask;

	return nullptr;
}
