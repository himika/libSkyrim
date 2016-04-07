#include "Skyrim.h"
#include "Skyrim/TESForms/Character/BGSRefAlias.h"
#include "Skyrim/TESForms/Character/TESQuest.h"
#include "Skyrim/TESForms/World/TESObjectREFR.h"

void BGSRefAlias::Clear(void)
{
	if ((flags & kFlag_Optional) != 0)
		owner->ClearReferenceAlias(this);
}


TESObjectREFR* BGSRefAlias::GetReference(void)
{
	RefHandle handle = 0;
	TESObjectREFR* ref = nullptr;

	if (owner == nullptr)
		return nullptr;

	owner->CreateRefHandleByAliasID(handle, aliasId);
	if (handle != g_invalidRefHandle)
	{
		if (!LookupREFRByHandle(handle, ref))
		{
			ref = nullptr;
		}
	}

	return ref;
}

Actor* BGSRefAlias::GetActorReference(void)
{
	TESObjectREFR* actor = this->GetReference();

	if (actor == nullptr || actor->formType != FormType::Character)
		actor = nullptr;

	return (Actor*)actor;
}

UInt32 BGSRefAlias::ForceRefTo(TESObjectREFR * reference)
{
	return (owner) ? owner->ForceRefTo(aliasId, reference) : 0;
}
