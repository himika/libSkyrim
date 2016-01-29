#pragma once

#include "TESForm.h"
#include "TESBoundObject.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESModelTextureSwap.h"
#include "../FormComponents/TESEnchantableForm.h"
#include "../FormComponents/TESValueForm.h"
#include "../FormComponents/TESWeightForm.h"
#include "../FormComponents/BGSDestructibleObjectForm.h"
#include "../FormComponents/TESAttackDamageForm.h"
#include "../FormComponents/BGSEquipType.h"
#include "../FormComponents/BGSPreloadable.h"
#include "../FormComponents/BGSMessageIcon.h"
#include "../FormComponents/BGSPickupPutdownSounds.h"
#include "../FormComponents/BGSBlockBashData.h"
#include "../FormComponents/BGSKeywordForm.h"
#include "../FormComponents/TESDescription.h"

/*==============================================================================
class TESObjectWEAP +0000 (_vtbl=01085C44)
0000: class TESObjectWEAP
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESFullName
0020: |   |   class BaseFormComponent
0028: |   class TESModelTextureSwap
0028: |   |   class TESModel
0028: |   |   |   class BaseFormComponent
0044: |   class TESIcon
0044: |   |   class TESTexture
0044: |   |   |   class BaseFormComponent
004C: |   class TESEnchantableForm
004C: |   |   class BaseFormComponent
0058: |   class TESValueForm
0058: |   |   class BaseFormComponent
0060: |   class TESWeightForm
0060: |   |   class BaseFormComponent
0068: |   class TESAttackDamageForm
0068: |   |   class BaseFormComponent
0070: |   class BGSDestructibleObjectForm
0070: |   |   class BaseFormComponent
0078: |   class BGSEquipType
0078: |   |   class BaseFormComponent
0080: |   class BGSPreloadable
0080: |   |   class BaseFormComponent
0084: |   class BGSMessageIcon
0084: |   |   class BaseFormComponent
0090: |   class BGSPickupPutdownSounds
0090: |   |   class BaseFormComponent
009C: |   class BGSBlockBashData
009C: |   |   class BaseFormComponent
00A8: |   class BGSKeywordForm
00A8: |   |   class BaseFormComponent
00B4: |   class TESDescription
00B4: |   |   class BaseFormComponent
==============================================================================*/
// 134
class TESObjectWEAP : public TESBoundObject,
	public TESFullName,					// 20
	public TESModelTextureSwap,			// 28
	public TESIcon,						// 44
	public TESEnchantableForm,			// 4C
	public TESValueForm,				// 58
	public TESWeightForm,				// 60
	public TESAttackDamageForm,			// 68
	public BGSDestructibleObjectForm,	// 70
	public BGSEquipType,				// 78
	public BGSPreloadable,				// 80
	public BGSMessageIcon,				// 84
	public BGSPickupPutdownSounds,		// 90
	public BGSBlockBashData,			// 9C
	public BGSKeywordForm,				// A8
	public TESDescription				// B4
{
public:
	enum { kTypeID = (UInt32)FormType::Weapon };
	// @members

	// 34
	struct GameData
	{
		enum	// type
		{
			kType_HandToHandMelee = 0,
			kType_OneHandSword,
			kType_OneHandDagger,
			kType_OneHandAxe,
			kType_OneHandMace,
			kType_TwoHandSword,
			kType_TwoHandAxe,
			kType_Bow,
			kType_Staff,
			kType_CrossBow,
			kType_H2H,
			kType_1HS,
			kType_1HD,
			kType_1HA,
			kType_1HM,
			kType_2HS,
			kType_2HA,
			kType_Bow2,
			kType_Staff2,
			kType_CBow
		};

		enum Flags1 {
			kFlags_PlayerOnly = 0x01,
			kFlags_NPCUseAmmo = 0x02,
			kFlags_NoJamAfterReload = 0x04,
			kFlags_MinorCrime = 0x10,
			kFlags_NotUsedInNormalCombat = 0x40,
			kFlags_Unknown1 = 0x100,
			kFlags_LongBursts = 0x800,
			kFlags_NonHostile = 0x1000,
			kFlags_BoundWeapon = 0x2000,
		};

		enum Flags2 {
			kFlags_Hidebackpack = 0x01,
			kFlags_Automatic = 0x02,
			kFlags_CantDrop = 0x08,
			kFlags_EmbeddedWeapon = 0x20,
			kFlags_Unknown2 = 0x40,
			kFlags_NotPlayable = 0x80,
		};

		UInt32	unk00;	// 00
		float	speed;	// 04
		float	reach;	// 08
		float	minRange;	// 0C
		float	maxRange;	// 10
		float	animationMult;	// 14
		float	unk18;	// 18
		float	stagger;// 1C
		UInt32	unk20;	// 20
		UInt32	skill;	// 24
		UInt32	resist;	// 28
		UInt16	flags1;	// 2C
		UInt8	vatsChance;	// 2E
		UInt8	unk2F;	// 2F
		UInt8	unk30;	// 30
		UInt8	type;	// 31
		UInt8	flags2;	// 32
		UInt8	unk33;	// 33
	};

	// 0C
	struct CritData
	{
		float	critMult;			// 00
		SpellItem	* critEffect;	// 04
		UInt16	critDamage;			// 08
		UInt8	effectOnDeath;		// 0A
		UInt8	pad0B;				// 0B
	};

	// @override
	//virtual ????   Unk_004(????) override;                           // 004A9430
	//virtual ????   Unk_005(????) override;                           // 004A8780
	//virtual ????   LoadForm(????) override;                          // 004A9580
	//virtual ????   SaveBuffer(????) override;                        // 004A80C0
	//virtual ????   LoadBuffer(????) override;                        // 004A80E0
	//virtual ????   InitItem(????) override;                          // 004AA3C0
	//virtual ????   Unk_014(????) override;                           // 004A8D70
	//virtual ????   IsPlayable(????) override;                        // 004A8E90
	//virtual ????   ActivateReference(????) override;                 // 004A8110
	//virtual ????   GetTypeString(????) override;                     // 004A8D90

	// @members
	GameData				gameData;			// 0C0
	CritData				critData;			// 0F4
	TESForm					* scopeEffect;		// 100
	BGSSoundDescriptorForm	* attackSound;		// 104
	BGSSoundDescriptorForm	* attackSound2D;	// 108
	BGSSoundDescriptorForm	* attackLoopSound;	// 10C
	BGSSoundDescriptorForm	* attackFailSound;	// 110
	BGSSoundDescriptorForm	* idleSound;		// 114
	BGSSoundDescriptorForm	* equipSound;		// 118
	BGSSoundDescriptorForm	* unequipSound;		// 11C
	BGSImpactDataSet		* impactDataSet;	// 120
	TESObjectSTAT			* model;			// 124
	TESObjectWEAP			* templateForm;		// 128 - Non-weapon templates don't make sense here and would probably crash anyway so assume it
	BSFixedString			embeddedNode;		// 12C
	UInt32					pad130;				// 130

	float speed() { return gameData.speed; }
	float reach() { return gameData.reach; }
	float stagger() { return gameData.stagger; }
	float minRange() { return gameData.minRange; }
	float maxRange() { return gameData.maxRange; }
	UInt8 type() { return gameData.type; }
	UInt16 critDamage() { return critData.critDamage; }
};
STATIC_ASSERT(sizeof(TESObjectWEAP) == 0x134);
