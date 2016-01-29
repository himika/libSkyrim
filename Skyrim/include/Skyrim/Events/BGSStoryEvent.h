#pragma once

#include "../BSCore/BSTEvent.h"

class Actor;

struct Inventory
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct ActorItemEquipped
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct ActorKill
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct CriticalHit
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct SkillIncrease
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct Bounty
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct QuestStaus
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct ObjectiveState
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct LocationDiscovery
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct BookRead
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct TESHarvestEvent
{
	struct ItemHarvested
	{
	};
	static BSTEventSource<ItemHarvested>* GetEventSource();
};

struct DaysPassed
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct AssaultCrime
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct MurderCrime
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct LocationCleared
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct SoulsTrapped
{
	// 08
	struct Event
	{
		Actor* trapper;
		Actor* target;
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct LocksPicked
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct SoulGemsUsed
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct ChestsLooted
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};


struct LevelIncrease
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct HourPassed
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct TimesTrained
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct TimesBartered
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct ContractedDisease
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct PoisonedWeapon
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct Disarmed
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct WordLearned
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct WordUnlocked
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct SpellsLearned
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct DragonSoulGained
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct WeaponAttack
{
	struct Event
	{
		/*
		007426D1: 01B39C5C.SendEvent(01B40324)
		struct `anonymous namespace'::FavoriteWeaponHandler +0000
		+0000 02 struct `anonymous namespace'::FavoriteWeaponHandler | 012B610C
		+0000 01 struct `anonymous namespace'::FavoriteItemHandler<class TESObjectWEAP,struct WeaponAttack::Event> | 012B6008
		-->		+0000 00 class BSTEventSink<struct WeaponAttack::Event> | 012B5F9C
		*/
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct SpellAttack
{
	struct Event
	{
		/*
		007739A0: 01B3B04C.SendEvent(01B40334)
		struct `anonymous namespace'::FavoriteSpellHandler +0000
		+0000 02 struct `anonymous namespace'::FavoriteSpellHandler | 012B6140
		+0000 01 struct `anonymous namespace'::FavoriteItemHandler<class MagicItem,struct SpellAttack::Event> | 012B6060
		-->		+0000 00 class BSTEventSink<struct SpellAttack::Event> | 012B5FD0
		*/
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct ShoutAttack
{
	struct Event
	{
		/*
		007427A1: 01B39C90.SendEvent(01B40344)
		struct `anonymous namespace'::FavoriteShoutHandler +0000
		+0000 02 struct `anonymous namespace'::FavoriteShoutHandler | 012B6170
		+0000 01 struct `anonymous namespace'::FavoriteItemHandler<class TESShout,struct ShoutAttack::Event> | 012B60B8
		-->		+0000 00 class BSTEventSink<struct ShoutAttack::Event> | 01274BA4
		*/
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct ShoutMastered
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct ItemCrafted
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct Pickpocket
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct Trespass
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct FinesPaid
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct DaysJailed
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct ItemsPickpocketed
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct ItemStolen
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct Jailing
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct JailEscape
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};

struct GrandTheftHorse
{
	struct Event
	{
	};
	static BSTEventSource<Event>* GetEventSource();
};
