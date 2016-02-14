#pragma once

#include "TESForm.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESReactionForm.h"
#include "../FormComponents/Condition.h"

class TESObjectREFR;
class BGSListForm;
class BGSOutfit;


/*==============================================================================
class TESFaction +0000 (_vtbl=010A4F04)
0000: class TESFaction
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class TESReactionForm
001C: |   |   class BaseFormComponent
==============================================================================*/
// 98
class TESFaction : public TESForm,
	public TESFullName,			// 14
	public TESReactionForm		// 1C
{
public:
	enum { kTypeID = (UInt32)FormType::Faction };

	enum FactionFlags
	{
		kFlag_HiddenFromPC				= 1 << 0,		//     1
		kFlag_SpecialCombat				= 1 << 1,		//     2
		kFlag_TrackCrime				= 1 << 6,		//    40
		kFlag_IgnoreMurder				= 1 << 7,		//    80
		kFlag_IgnoreAssault				= 1 << 8,		//   100
		kFlag_IgnorePickpocket			= 1 << 9,		//   200
		kFlag_IgnoreStealing			= 1 << 10,		//   400
		kFlag_DoReportCrimes			= 1 << 11,		//   800
		kFlag_CrimeGoldDefaults			= 1 << 12,		//  1000
		kFlag_IgnoreTrespass			= 1 << 13,		//  2000
		kFlag_Vender					= 1 << 14,		//  4000
		kFlag_CanBeOwner				= 1 << 15,		//  8000
		kFlag_IgnoreWerewolf			= 1 << 16		// 10000
	};

	// 2C
	struct CrimeValues								// CRVA
	{
		TESObjectREFR	* exteriorJailMarker;		// 00 (34) JAIL
		TESObjectREFR	* followerWaitMarker;		// 04 (38) WAIT
		TESObjectREFR	* stolenGoodsContainer;		// 08 (3C) STOL
		TESObjectREFR	* playerInventoryContainer;	// 0C (40) PLCN
		BGSListForm		* sharedCrimeFactionList;	// 10 (44) CRGR
		BGSOutfit		* jailOutfit;				// 14 (48) JOUT
		bool			arrest;						// 18 (4C)
		bool			attackOnSight;				// 19 (4D)
		UInt16			murder;						// 1A (4E)
		UInt16			assault;					// 1C (50)
		UInt16			trespass;					// 1E (52)
		UInt16			pickpocket;					// 20 (54)
		UInt16			pad22;						// 22 (56)
		float			stealMult;					// 24 (58)
		UInt16			escape;						// 28 (5C)
		UInt16			werewolf;					// 2A (5E)
	};

	// 20
	struct VendorValues							// VENV
	{
		UInt16			startHour;				// 00
		UInt16			endHour;				// 02
		UInt32			radius;					// 04
		bool			onlyBuysStolenItems;	// 08
		bool			notSellBuy;				// 09
		UInt16			pad0B;					// 0A
		void			* packageLocation;		// 0C
		Condition		* condition;			// 10
		BGSListForm		* buySellList;			// 14
		TESObjectREFR	* merchantContainer;	// 18
		UInt32			unk1C;					// 1C
	};

	// 8
	struct Data80
	{
		UInt32	unk0;	// 0
		UInt32	unk4;	// 4
	};

	// @members
	UInt32			unk2C;			// 2C
	UInt32			factionFlags;	// 30 - DATA
	CrimeValues		crimeValues;	// 34 - CRVA
	VendorValues	vendorValues;	// 60 - VENV
	Data80			unk80;			// 80
	UInt32			unk88;			// 88
	UInt32			unk8C;			// 8C
	float			unk90;			// 90
	UInt32			unk94;			// 94
};
STATIC_ASSERT(sizeof(TESFaction) == 0x98);
STATIC_ASSERT(offsetof(TESFaction, vendorValues) == 0x60);
