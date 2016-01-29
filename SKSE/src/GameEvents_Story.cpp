#include "SKSE/GameEvents.h"

template <>
BSTEventSource<Inventory::Event>* SKSEEvent2<Inventory::Event>::GetEventSource()
{
	return Inventory::GetEventSource();
}

template <>
BSTEventSource<ActorItemEquipped::Event>* SKSEEvent2<ActorItemEquipped::Event>::GetEventSource()
{
	return ActorItemEquipped::GetEventSource();
}

template <>
BSTEventSource<ActorKill::Event>* SKSEEvent2<ActorKill::Event>::GetEventSource()
{
	return ActorKill::GetEventSource();
}

template <>
BSTEventSource<CriticalHit::Event>* SKSEEvent2<CriticalHit::Event>::GetEventSource()
{
	return CriticalHit::GetEventSource();
}

template <>
BSTEventSource<SkillIncrease::Event>* SKSEEvent2<SkillIncrease::Event>::GetEventSource()
{
	return SkillIncrease::GetEventSource();
}

template <>
BSTEventSource<Bounty::Event>* SKSEEvent2<Bounty::Event>::GetEventSource()
{
	return Bounty::GetEventSource();
}

template <>
BSTEventSource<QuestStaus::Event>* SKSEEvent2<QuestStaus::Event>::GetEventSource()
{
	return QuestStaus::GetEventSource();
}

template <>
BSTEventSource<ObjectiveState::Event>* SKSEEvent2<ObjectiveState::Event>::GetEventSource()
{
	return ObjectiveState::GetEventSource();
}

template <>
BSTEventSource<LocationDiscovery::Event>* SKSEEvent2<LocationDiscovery::Event>::GetEventSource()
{
	return LocationDiscovery::GetEventSource();
}

template <>
BSTEventSource<BookRead::Event>* SKSEEvent2<BookRead::Event>::GetEventSource()
{
	return BookRead::GetEventSource();
}

template <>
BSTEventSource<TESHarvestEvent::ItemHarvested>* SKSEEvent2<TESHarvestEvent::ItemHarvested>::GetEventSource()
{
	return TESHarvestEvent::GetEventSource();
}

template <>
BSTEventSource<DaysPassed::Event>* SKSEEvent2<DaysPassed::Event>::GetEventSource()
{
	return DaysPassed::GetEventSource();
}

template <>
BSTEventSource<AssaultCrime::Event>* SKSEEvent2<AssaultCrime::Event>::GetEventSource()
{
	return AssaultCrime::GetEventSource();
}

template <>
BSTEventSource<MurderCrime::Event>* SKSEEvent2<MurderCrime::Event>::GetEventSource()
{
	return MurderCrime::GetEventSource();
}

template <>
BSTEventSource<LocationCleared::Event>* SKSEEvent2<LocationCleared::Event>::GetEventSource()
{
	return LocationCleared::GetEventSource();
}

template <>
BSTEventSource<SoulsTrapped::Event>* SKSEEvent2<SoulsTrapped::Event>::GetEventSource()
{
	return SoulsTrapped::GetEventSource();
}

template <>
BSTEventSource<LocksPicked::Event>* SKSEEvent2<LocksPicked::Event>::GetEventSource()
{
	return LocksPicked::GetEventSource();
}

template <>
BSTEventSource<SoulGemsUsed::Event>* SKSEEvent2<SoulGemsUsed::Event>::GetEventSource()
{
	return SoulGemsUsed::GetEventSource();
}

template <>
BSTEventSource<ChestsLooted::Event>* SKSEEvent2<ChestsLooted::Event>::GetEventSource()
{
	return ChestsLooted::GetEventSource();
}

template <>
BSTEventSource<LevelIncrease::Event>* SKSEEvent2<LevelIncrease::Event>::GetEventSource()
{
	return LevelIncrease::GetEventSource();
}

template <>
BSTEventSource<HourPassed::Event>* SKSEEvent2<HourPassed::Event>::GetEventSource()
{
	return HourPassed::GetEventSource();
}

template <>
BSTEventSource<TimesTrained::Event>* SKSEEvent2<TimesTrained::Event>::GetEventSource()
{
	return TimesTrained::GetEventSource();
}

template <>
BSTEventSource<TimesBartered::Event>* SKSEEvent2<TimesBartered::Event>::GetEventSource()
{
	return TimesBartered::GetEventSource();
}

template <>
BSTEventSource<ContractedDisease::Event>* SKSEEvent2<ContractedDisease::Event>::GetEventSource()
{
	return ContractedDisease::GetEventSource();
}

template <>
BSTEventSource<PoisonedWeapon::Event>* SKSEEvent2<PoisonedWeapon::Event>::GetEventSource()
{
	return PoisonedWeapon::GetEventSource();
}

template <>
BSTEventSource<Disarmed::Event>* SKSEEvent2<Disarmed::Event>::GetEventSource()
{
	return Disarmed::GetEventSource();
}

template <>
BSTEventSource<WordLearned::Event>* SKSEEvent2<WordLearned::Event>::GetEventSource()
{
	return WordLearned::GetEventSource();
}

template <>
BSTEventSource<WordUnlocked::Event>* SKSEEvent2<WordUnlocked::Event>::GetEventSource()
{
	return WordUnlocked::GetEventSource();
}

template <>
BSTEventSource<SpellsLearned::Event>* SKSEEvent2<SpellsLearned::Event>::GetEventSource()
{
	return SpellsLearned::GetEventSource();
}

template <>
BSTEventSource<DragonSoulGained::Event>* SKSEEvent2<DragonSoulGained::Event>::GetEventSource()
{
	return DragonSoulGained::GetEventSource();
}

template <>
BSTEventSource<WeaponAttack::Event>* SKSEEvent2<WeaponAttack::Event>::GetEventSource()
{
	return WeaponAttack::GetEventSource();
}

template <>
BSTEventSource<SpellAttack::Event>* SKSEEvent2<SpellAttack::Event>::GetEventSource()
{
	return SpellAttack::GetEventSource();
}

template <>
BSTEventSource<ShoutAttack::Event>* SKSEEvent2<ShoutAttack::Event>::GetEventSource()
{
	return ShoutAttack::GetEventSource();
}

template <>
BSTEventSource<ShoutMastered::Event>* SKSEEvent2<ShoutMastered::Event>::GetEventSource()
{
	return ShoutMastered::GetEventSource();
}

template <>
BSTEventSource<ItemCrafted::Event>* SKSEEvent2<ItemCrafted::Event>::GetEventSource()
{
	return ItemCrafted::GetEventSource();
}

template <>
BSTEventSource<Pickpocket::Event>* SKSEEvent2<Pickpocket::Event>::GetEventSource()
{
	return Pickpocket::GetEventSource();
}

template <>
BSTEventSource<Trespass::Event>* SKSEEvent2<Trespass::Event>::GetEventSource()
{
	return Trespass::GetEventSource();
}

template <>
BSTEventSource<FinesPaid::Event>* SKSEEvent2<FinesPaid::Event>::GetEventSource()
{
	return FinesPaid::GetEventSource();
}

template <>
BSTEventSource<DaysJailed::Event>* SKSEEvent2<DaysJailed::Event>::GetEventSource()
{
	return DaysJailed::GetEventSource();
}

template <>
BSTEventSource<ItemsPickpocketed::Event>* SKSEEvent2<ItemsPickpocketed::Event>::GetEventSource()
{
	return ItemsPickpocketed::GetEventSource();
}

template <>
BSTEventSource<ItemStolen::Event>* SKSEEvent2<ItemStolen::Event>::GetEventSource()
{
	return ItemStolen::GetEventSource();
}

template <>
BSTEventSource<Jailing::Event>* SKSEEvent2<Jailing::Event>::GetEventSource()
{
	return Jailing::GetEventSource();
}

template <>
BSTEventSource<JailEscape::Event>* SKSEEvent2<JailEscape::Event>::GetEventSource()
{
	return JailEscape::GetEventSource();
}

template <>
BSTEventSource<GrandTheftHorse::Event>* SKSEEvent2<GrandTheftHorse::Event>::GetEventSource()
{
	return GrandTheftHorse::GetEventSource();
}
