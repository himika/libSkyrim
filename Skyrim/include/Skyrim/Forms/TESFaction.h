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

	// @members

	enum {
		kFlag_HiddenFromPC						= 1 << 0,
		kFlag_SpecialCombat						= 1 << 1,
		kFlag_CanBeOwner						= 1 << 15,
		kFlag_TrackCrime						= 1 << 6,
		kFlag_Ignore_Murder						= 1 << 7,
		kFlag_Ignore_Assault					= 1 << 8,
		kFlag_Ignore_Pickpocket					= 1 << 9,
		kFlag_Ignore_Stealing					= 1 << 10,
		kFlag_Ignore_Trespass					= 1 << 13,
		kFlag_Ignore_Werewolf					= 1 << 16,
		kFlag_DoNotReportCrimesAgainstMembers	= 1 << 11,
		kFlag_CrimeGoldUseDefaults				= 1 << 12,
		kFlag_Vender							= 1 << 14
	};

	// 2C
	struct CrimeValues
	{
		TESObjectREFR	* exteriorJailMarker;		// 00 himika
		TESObjectREFR	* followerWaitMarker;		// 04 himika
		TESObjectREFR	* stolenGoodsContainer;		// 08 himika
		TESObjectREFR	* playerInventoryContainer;	// 0C himika
		BGSListForm		* sharedCrimeFactionList;	// 10 himika
		BGSOutfit		* jailOutfit;				// 14 himika
		bool	arrest;				// 18
		bool	attackOnSight;		// 19
		UInt16	murder;				// 1A
		UInt16	assault;			// 1C
		UInt16	trespass;			// 1E fixed by himika
		UInt16	pickpocket;			// 20 fixed by himika
		UInt16	pad22;				// 22 fixed by himika
		float	stealMult;			// 24
		UInt16	escape;				// 28
		UInt16	werewolf;			// 2A
	};

	// 20
	struct VendorData
	{
		UInt16			startHour;				// 00
		UInt16			endHour;				// 02
		UInt32			radius;					// 04
		UInt8			onlyBuysStolenItems;	// 08
		UInt8			notSellBuy;				// 0A
		UInt16			pad0B;					// 0B
		void			* packageLocation;		// 0C
		Condition		* condition;			// 10 himika
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

	UInt32	unk2C;	// 2C

	enum
	{
		kFactionFlag_HiddenFromNPC		= (1 << 0),
		kFactionFlag_SpecialCombat		= (1 << 1),
		kFactionFlag_TrackCrime			= (1 << 4),
		kFactionFlag_IgnoreMurder		= (1 << 5),
		kFactionFlag_IgnoreAssult		= (1 << 6),
		kFactionFlag_IngoreStealing		= (1 << 7),
		kFactionFlag_IgnoreTrespass		= (1 << 8),
		kFactionFlag_NoReportCrime		= (1 << 9),
		kFactionFlag_CrimeGoldDefaults	= (1 << 10),
		kFactionFlag_IgnorePickpocket	= (1 << 11),
		kFactionFlag_Vendor				= (1 << 12),
		kFactionFlag_CanBeOwner			= (1 << 13),
		kFactionFlag_IgnoreWerewolf		= (1 << 14)
	};

	UInt32		factionFlags;	// 30
	CrimeValues	crimeValues;	// 34
	VendorData	vendorData;		// 60
	Data80		unk80;			// 80
	UInt32		unk88;			// 88
	UInt32		unk8C;			// 8C
	float		unk90;			// 90
	UInt32		unk94;			// 94
};
STATIC_ASSERT(sizeof(TESFaction) == 0x98);
STATIC_ASSERT(offsetof(TESFaction, vendorData) == 0x60);
