#include "Skyrim/Forms/TESObjectCELL.h"

TESNPC * TESObjectCELL::GetActorOwner() const
{
	TESForm *owner = GetOwner_Impl();
	return (owner->Is(FormType::Character)) ? (TESNPC*)owner : nullptr;
}

TESFaction * TESObjectCELL::GetFactionOwner() const
{
	TESForm *owner = GetOwner_Impl();
	return (owner->Is(FormType::Faction)) ? (TESFaction*)owner : nullptr;
}
