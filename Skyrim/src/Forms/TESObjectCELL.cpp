#include "Skyrim/Forms/TESObjectCELL.h"

TESForm * TESObjectCELL::GetOwner() const
{
	return GetOwner_Impl();
}


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
