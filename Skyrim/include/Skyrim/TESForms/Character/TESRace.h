#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/TESDescription.h"
#include "../../FormComponents/TESSpellList.h"
#include "../../FormComponents/BGSSkinForm.h"
#include "../../FormComponents/BGSBipedObjectForm.h"
#include "../../FormComponents/BGSKeywordForm.h"
#include "../../FormComponents/BGSAttackDataForm.h"
#include "../../FormComponents/BGSTextureModel.h"
#include "../../FormComponents/BGSBehaviorGraphModel.h"
#include "../../FormComponents/TESTexture.h"
#include "../../BSCore/BSTArray.h"
#include "../../BSCore/BSTHashMap.h"

NiSmartPointer(AttackAnimationArrayMap);

// 0C
struct SetEventData
{
	BSFixedString					eventName;		// 00
	BSTSmallArray<BSFixedString>	* clipNames;	// 04
	UInt32							unk08;			// 08 - M
};


/*==============================================================================
class AttackAnimationArrayMap +0000 (_vtbl=010A6234)
0000: class AttackAnimationArrayMap
0008: |   class BSTHashMap<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTDefaultScatterTable>
0008: |   |   class BSTHashMapBase<struct BSTHashMapTraits<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTDefaultScatterTable<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *> > >
0008: |   |   |   struct BSTHashMapTraits<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTDefaultScatterTable<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *> >
000C: |   |   |   struct BSTDefaultScatterTable<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *>
000C: |   |   |   |   class BSTScatterTable<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage,struct BSTScatterTableDefaultHashPolicy,struct BSTScatterTableHeapAllocator,8>
000C: |   |   |   |   |   class BSTScatterTableBase<struct BSTScatterTableTraits<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage,struct BSTScatterTableDefaultHashPolicy<unsigned int>,struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage> >,8> >
000C: |   |   |   |   |   |   class BSTScatterTableKernel<struct BSTScatterTableTraits<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage,struct BSTScatterTableDefaultHashPolicy<unsigned int>,struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage> >,8> >
000C: |   |   |   |   |   |   |   struct BSTScatterTableTraits<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage,struct BSTScatterTableDefaultHashPolicy<unsigned int>,struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage> >,8>
000D: |   |   |   |   |   |   |   struct BSTScatterTableDefaultHashPolicy<unsigned int>
0021: |   |   |   |   |   |   struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage> >
0000: |   class NiRefObject
==============================================================================*/
// 28
class AttackAnimationArrayMap : 
	public BSTHashMap<UInt32, BSTArray<SetEventData> const *>,	// 04
	public NiRefObject											// 00
{
public:
	// hash key (hiword = right hand | loward = left hand)
	enum class HashKey : unsigned short {
		kAttackAnimation_H2H,		// 00 fist
		kAttackAnimation_1HS,		// 01 1h sword
		kAttackAnimation_1HD,		// 02 1h dagger
		kAttackAnimation_1HA,		// 03 1h war axe
		kAttackAnimation_1HM,		// 04 1h mace
		kAttackAnimation_2HS,		// 05 2h sword
		kAttackAnimation_2HA,		// 06 2h battle axe & war hammer
		kAttackAnimation_Bow,		// 07 bow
		kAttackAnimation_Staff,		// 08 staff
		kAttackAnimation_Crossbow,	// 09 crossbow
		kAttackAnimation_Spwll,		// 0A spell
		kAttackAnimation_Shield		// 0B shield
	};

	// @members
	//void	** _vtbl		// 00 - 010A6234
};
STATIC_ASSERT(sizeof(AttackAnimationArrayMap) == 0x28);


/*==============================================================================
class TESRace +0000 (_vtbl=010A62B4)
0000: class TESRace
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class TESDescription
001C: |   |   class BaseFormComponent
0028: |   class TESSpellList
0028: |   |   class BaseFormComponent
0030: |   class BGSSkinForm
0030: |   |   class BaseFormComponent
0038: |   class BGSBipedObjectForm
0038: |   |   class BaseFormComponent
0044: |   class BGSKeywordForm
0044: |   |   class BaseFormComponent
0050: |   class BGSAttackDataForm
0050: |   |   class BaseFormComponent
==============================================================================*/
// 2BC
class TESRace : public TESForm,
	public TESFullName,			// 014
	public TESDescription,		// 01C
	public TESSpellList,		// 028
	public BGSSkinForm,			// 030
	public BGSBipedObjectForm,	// 038
	public BGSKeywordForm,		// 044
	public BGSAttackDataForm	// 050
{
public:
	enum { kTypeID = (UInt32)FormType::Race };

	enum {
		kRace_Playable = 0x00000001,
		kRace_FaceGenHead = 0x00000002,
		kRace_Child = 0x00000004,
		kRace_TiltFrontBack = 0x00000008,
		kRace_TiltLeftRight = 0x00000010,
		kRace_NoShadow = 0x00000020,
		kRace_Swims = 0x00000040,
		kRace_Flies = 0x00000080,
		kRace_Walks = 0x00000100,
		kRace_Immobile = 0x00000200,
		kRace_NotPushable = 0x00000400,
		kRace_NoCombatInWater = 0x00000800,
		kRace_NoRotatingToHeadTrack = 0x00001000,
		kRace_UseHeadTrackAnim = 0x00008000,
		kRace_SpellsAlignWithMagicNode = 0x00010000,
		kRace_UseWorldRaycasts = 0x00020000,
		kRace_AllowRagdollCollision = 0x00040000,
		kRace_CantOpenDoors = 0x00100000,
		kRace_AllowPCDialogue = 0x00200000,
		kRace_NoKnockdowns = 0x00400000,
		kRace_AllowPickpocket = 0x00800000,
		kRace_AlwaysUseProxyController = 0x01000000,
		kRace_OverlayHeadParts = 0x04000000,
		kRace_OverrideHeadParts = 0x08000000,
		kRace_AllowMultipleMembraneShaders = 0x20000000,
		kRace_CanDualWield = 0x40000000,
		kRace_AvoidsRoads = 0x80000000,
	};

	enum {
		kRace_NumSkillBonuses = 7
	};

	// 84
	struct Data
	{
		struct SkillBonus
		{
			UInt8 skill;
			UInt8 bonus;
		};
		SkillBonus skillBonus[kRace_NumSkillBonuses];
		UInt8	pad0E[2];			// 0E
		float	height[2];			// 10
		float	weight[2];			// 18
		UInt32	raceFlags;			// 20 - not init'd
		float	health;				// 24
		float	magicka;			// 28
		float	stamina;			// 2C
		float	carryweight;		// 30
		float	mass;				// 34
		float	accelRate;			// 38
		float	deaccelRate;		// 3C
		UInt32	unk40;				// 40 - init'd to 1 - Size
		SInt32	unk44;				// 44 - init'd to FFFFFFFF - Head Biped Object
		SInt32	unk48;				// 48 - init'd to FFFFFFFF - Hair Biped Object
		UInt32	unk4C;				// 4C - not init'd
		float	injuredHealthPct;	// 50 - init'd to FFFFFFFF
		float	healthRegen;		// 54
		float	manaRegen;			// 58
		float	staminaRegen;		// 5C
		float	unarmedDamage;		// 60
		float	handReach;			// 64
		SInt32	unk68;				// 68 - init'd to FFFFFFFF - Body Biped Object
		float	aimAngleTolerance;	// 6C
		float	flightRadius;		// 70 - init'd to 0
		float	angleAcceleration;	// 74
		float	angleTolerance;		// 78
		UInt32	unk7C;				// 7C
		UInt32	unk80;				// 80
		UInt32	unk84;				// 84
		float	mountOffsetX;		// 88 - mount offset X
		float	mountOffsetY;		// 8C - mount offset Y
		float	unk90;
		float	unk94;
		float	unk98;
		float	unk9C;
		float	unkA0;
		float	unkA4;
		float	unkAC;
	};

	struct CharGenData
	{
		struct TintOption
		{
			UInt32					unk00;			// 00
			TESTexture				texture;		// 04
			BGSColorForm			* defaultColor;	// 0C
			BSTArray<BGSColorForm*>	colors;			// 10
			BSTArray<float>			alpha;			// 14
			BSTArray<UInt32>		unk18;			// 18
		};
		UInt32	unk00[0x90 >> 2];						// 00 - Don't know what this is yet, mostly FFFFFFFF
		BSTArray<TintOption*>		* tintData;			// 90
		BSTArray<BGSTextureSet*>	* textureSet;		// 94
		BGSTextureSet				* defaultTexture;	// 98
		BSTArray<TESNPC*>			* presets;			// 9C
		BSTArray<BGSColorForm*>		* colors;			// A0
		BGSColorForm				* defaultColor;		// A4
		BSTArray<BGSHeadPart*>		* headParts;		// A8
	};


	static TESRace* LookupByEditorID(const BSFixedString &editorId);

	// @members
	TESModel					models[2];			// 058
	Data						data;				// 080
	BGSTextureModel				textureModel[2];	// 12C
	BGSBehaviorGraphModel		behaviorGraph[2];	// 154
	BSFixedString				behaviorPath[2];	// 17C
	BSFixedString				behaviorName[2];	// 184
	BGSVoiceType				* voiceTypes[2];	// 18C
	BGSBodyPartData				* bodyPartData;		// 194
	TESForm						* decapitateArmor[2];	// 198
	BSTArray<void*>				unk1A0[2];				// nif?
	void						* unk1B8[4];
	AttackAnimationArrayMap		* attackAnimationArrayMap[2];	// 1C8
	BSFixedString				editorId;						// 1CC
	BGSMaterialType				* impactMaterial;				// 1D0
	BGSImpactDataSet			* meleeImpact;					// 1D4
	BGSArtObject				* decapitateBloodArt;			// 1D8
	BGSSoundDescriptorForm		* openCorpseSound;				// 1DC
	BGSSoundDescriptorForm		* closeCorpseSound;				// 1E0
	BSFixedString				bipedObjectNames[0x20];			// 1E4
	BSTArray<BGSEquipSlot*>		slotRestrictions;				// 268
	UInt32						unk274;
	BGSEquipSlot				* unarmedEquipSlot;				// 278
	TESRace						* morphRace;					// 27C
	TESRace						* armorRace;					// 280
	BSTArray<void*>				unk284;
	BSTArray<void*>				unk290;
	UInt8						unk29C[0x18];
	CharGenData					* chargenData[2];
};
STATIC_ASSERT(offsetof(TESRace::CharGenData, tintData) == 0x90);
