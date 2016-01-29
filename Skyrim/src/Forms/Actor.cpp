#include "Skyrim.h"
#include "Skyrim/RTTI.h"
#include "Skyrim/Forms/Actor.h"
#include "Skyrim/Forms/TESNPC.h"
#include "Skyrim/Forms/BGSColorForm.h"
#include "Skyrim/Forms/PlayerCharacter.h"
#include "Skyrim/ExtraData/ExtraInteraction.h"

#include "Skyrim/Forms/Character/Components/ActorProcessManager.h"
#include "Skyrim/Forms/Character/Components/DetectionState.h"
#include "Skyrim/Forms/Character/Components/ActorKnowledge.h"


typedef UInt32(*_UpdateModelSkin)(NiNode*, NiColorA**);
const static _UpdateModelSkin UpdateModelSkin = (_UpdateModelSkin)0x005A9810; // Applies tint to ShaderType 5 nodes

typedef UInt32(*_UpdateModelHair)(NiNode*, NiColorA**);
const static _UpdateModelHair UpdateModelHair = (_UpdateModelHair)0x005A9890; // Applies tint to ShaderType 6 nodes

typedef bool(*_HasLOS)(Actor* viewer, TESObjectREFR* target, bool& result);
const static _HasLOS HasLos = (_HasLOS)0x008C0FA0;



TESForm * Actor::GetEquippedObject(bool abLeftHand)
{
	if (!processManager)
		return nullptr;

	if (abLeftHand)
		return processManager->equippedObject[ActorProcessManager::kEquippedHand_Left];
	else
		return processManager->equippedObject[ActorProcessManager::kEquippedHand_Right];

	return nullptr;
}

void Actor::UpdateHairColor()
{
	TESNPC* npc = DYNAMIC_CAST<TESNPC*>(baseForm);
	if (npc && npc->headData) {
		BGSColorForm * hairColor = npc->headData->hairColor; // Non-player actors won't have this
		if (hairColor) {
			NiColorA val;
			val.r = hairColor->color.red / 128.0;
			val.g = hairColor->color.green / 128.0;
			val.b = hairColor->color.blue / 128.0;
			NiColorA * color = &val;

			NiNode * model = GetNiRootNode(0);
			if (model) {
				UpdateModelHair(model, &color);
			}
		}
	}
}

void Actor::UpdateSkinColor()
{
	TESNPC* npc = DYNAMIC_CAST<TESNPC*>(baseForm);
	if (npc) {
		NiColorA val;
		val.r = npc->color.red / 255.0;
		val.g = npc->color.green / 255.0;
		val.b = npc->color.blue / 255.0;
		NiColorA * color = &val;

		NiNode * thirdPerson = GetNiRootNode(0);
		NiNode * firstPerson = GetNiRootNode(1);
		if (thirdPerson) {
			UpdateModelSkin(thirdPerson, &color); // Update for 3rd Person
		}
		if (firstPerson) {
			UpdateModelSkin(firstPerson, &color); // Update for 1st Person
		}
	}
}

TESRace * Actor::GetRace() const
{
	TESRace *race = nullptr;

	TESNPC *actorBase = GetActorBase();
	if (actorBase)
		race = actorBase->GetRace();

	return race;
}

bool Actor::HasLOS(TESObjectREFR* target)
{
	bool result = false;
	return HasLos(this, target, result) ? result : false;
}

bool Actor::HasSpell(TESForm * spell) const
{
	if (spell == nullptr)
		return false;

	if (spell->Is(FormType::Spell))
	{
		return this->HasSpell((SpellItem*)spell);
	}
	else if (spell->Is(FormType::Shout))
	{
		return this->HasShout((TESShout*)spell);
	}

	return false;
}

bool Actor::IsBeingRidden() const
{
	return flags2.hasInteraction && extraData.HasType<ExtraInteraction>();
}

bool Actor::IsOnMount() const
{
	return flags2.hasInteraction && extraData.HasType<ExtraInteraction>();
}

bool Actor::IsPlayersLastRiddenHorse()
{
	RefHandle handle;
	g_thePlayer->GetLastRiddenHorse(handle);
	return handle == CreateRefHandle();
}

bool Actor::IsSneaking() const
{
	if (!ActorState::IsSneaking())
		return false;

	if (ActorState::IsSwimming())
		return false;

	if (IsOnMount())
		return false;

	return true;
}
