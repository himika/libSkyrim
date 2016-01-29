#include "Skyrim/Events/BGSStoryEvent.h"
#include <new>


BSTEventSource<TESHarvestEvent::ItemHarvested>* TESHarvestEvent::GetEventSource()
{
	typedef BSTEventSource<TESHarvestEvent::ItemHarvested> EventSource;
	EventSource *instance = (EventSource*)0x012E5A74;
	UInt8 &bInit = *(UInt8*)(instance + 1);
	if (bInit & 1) {
		bInit |= 1;
		new(instance)EventSource;
	}
	return instance;
}


#define DECLARE_EVENT_SOURCE(addr, name)						\
	BSTEventSource<name::Event>* name::GetEventSource() {		\
		typedef BSTEventSource<name::Event> SrcT;				\
		SrcT *instance = (SrcT*)addr;							\
		UInt8 &bInit = *(UInt8*)(addr + sizeof(SrcT));			\
		if (bInit & 1) {										\
			bInit |= 1;											\
			new(instance) SrcT;									\
		}														\
		return instance;										\
	}

DECLARE_EVENT_SOURCE(0x012E5FB0, Inventory)
DECLARE_EVENT_SOURCE(0x012E736C, BookRead)
DECLARE_EVENT_SOURCE(0x012E7610, LocationCleared)
DECLARE_EVENT_SOURCE(0x01B10FE0, ObjectiveState)
DECLARE_EVENT_SOURCE(0x01B113A0, QuestStaus)
DECLARE_EVENT_SOURCE(0x01B2E728, DaysPassed)
DECLARE_EVENT_SOURCE(0x01B38B14, ActorItemEquipped)
DECLARE_EVENT_SOURCE(0x01B38B48, ActorKill)
DECLARE_EVENT_SOURCE(0x01B38B7C, Disarmed)
DECLARE_EVENT_SOURCE(0x01B38BE4, AssaultCrime)
DECLARE_EVENT_SOURCE(0x01B38C18, MurderCrime)
DECLARE_EVENT_SOURCE(0x01B38C4C, GrandTheftHorse)
DECLARE_EVENT_SOURCE(0x01B38F2C, DragonSoulGained)
DECLARE_EVENT_SOURCE(0x01B38FD0, CriticalHit)
DECLARE_EVENT_SOURCE(0x01B38F9C, ContractedDisease)
DECLARE_EVENT_SOURCE(0x01B39028, SoulsTrapped)
DECLARE_EVENT_SOURCE(0x01B3905C, SpellsLearned)
DECLARE_EVENT_SOURCE(0x01B397D0, SkillIncrease)
DECLARE_EVENT_SOURCE(0x01B39804, LevelIncrease)
DECLARE_EVENT_SOURCE(0x01B39AF0, Pickpocket)
DECLARE_EVENT_SOURCE(0x01B39B24, ItemStolen)
DECLARE_EVENT_SOURCE(0x01B39B58, LocationDiscovery)
DECLARE_EVENT_SOURCE(0x01B39B8C, FinesPaid)
DECLARE_EVENT_SOURCE(0x01B39BC0, Jailing)
DECLARE_EVENT_SOURCE(0x01B39BF4, JailEscape)
DECLARE_EVENT_SOURCE(0x01B39C28, Bounty)
DECLARE_EVENT_SOURCE(0x01B39C5C, WeaponAttack)
DECLARE_EVENT_SOURCE(0x01B39C90, ShoutAttack)
DECLARE_EVENT_SOURCE(0x01B39CC4, PoisonedWeapon)
DECLARE_EVENT_SOURCE(0x01B39CF8, DaysJailed)
DECLARE_EVENT_SOURCE(0x01B39D2C, WordLearned)
DECLARE_EVENT_SOURCE(0x01B39D60, WordUnlocked)
DECLARE_EVENT_SOURCE(0x01B39D94, ShoutMastered)
DECLARE_EVENT_SOURCE(0x01B3B04C, SpellAttack)
DECLARE_EVENT_SOURCE(0x01B3B2A8, Trespass)
DECLARE_EVENT_SOURCE(0x01B3E480, TimesBartered)
DECLARE_EVENT_SOURCE(0x01B3E788, ChestsLooted)
DECLARE_EVENT_SOURCE(0x01B3E7BC, ItemsPickpocketed)
DECLARE_EVENT_SOURCE(0x01B3E7F4, ItemCrafted)
DECLARE_EVENT_SOURCE(0x01B3FAC8, SoulGemsUsed)
DECLARE_EVENT_SOURCE(0x01B3FBBC, LocksPicked)
DECLARE_EVENT_SOURCE(0x01B3FDE4, HourPassed)
DECLARE_EVENT_SOURCE(0x01B40130, TimesTrained)

#undef DECLARE_EVENT_SOURCE
