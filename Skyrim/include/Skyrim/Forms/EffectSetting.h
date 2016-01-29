#pragma once

#include "TESForm.h"
#include "../BSCore/BSTArray.h"
#include "../BSCore/BSTList.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/BGSMenuDisplayObject.h"
#include "../FormComponents/BGSKeywordForm.h"

class TESObjectLIGH;
class TESEffectShader;
class BGSProjectile;
class BGSExplosion;
class BGSArtObject;
class BGSImpactDataSet;
class BGSDualCastData;
class TESImageSpaceModifier;
class TESSound;

/*==============================================================================
class EffectSetting +0000 (_vtbl=010776AC)
0000: class EffectSetting
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class BGSMenuDisplayObject
001C: |   |   class BaseFormComponent
0024: |   class BGSKeywordForm
0024: |   |   class BaseFormComponent
==============================================================================*/
// F4
class EffectSetting : public TESForm,
	public TESFullName,				// 14
	public BGSMenuDisplayObject,	// 1C
	public BGSKeywordForm			// 24
{
public:
	enum { kTypeID = (UInt32)FormType::EffectSetting };

	// @override
	virtual void			Unk_05(void) override;					// 00404600
	virtual bool			LoadForm(TESFile *arg) override;		// 004047E0
	virtual void			InitItem(void) override;				// 00404BB0
	virtual void			CopyFrom(TESForm * srcForm) override;	// 004043B0
	virtual const char *	GetTypeString(void) const override;		// 00403EF0 - Value Modifier, Script, Dispel, Cure Disese...

	// @members

	// 98
	struct Properties
	{
		enum {
			kEffectType_Hostile = 0x00000001,
			kEffectType_Recover = 0x00000002,
			kEffectType_Detrimental = 0x00000004,
			kEffectType_NoHitEvent = 0x00000010,
			kEffectType_DispelKeywords = 0x00000100,
			kEffectType_NoDuration = 0x00000200,
			kEffectType_NoMagnitude = 0x00000400,
			kEffectType_NoArea = 0x00000800,
			kEffectType_FXPersist = 0x00001000,
			kEffectType_GloryVisuals = 0x00004000,
			kEffectType_HideInUI = 0x00008000,
			kEffectType_NoRecast = 0x00020000,
			kEffectType_Magnitude = 0x00200000,
			kEffectType_Duration = 0x00400000,
			kEffectType_Painless = 0x04000000,
			kEffectType_NoHitEffect = 0x08000000,
			kEffectType_NoDeathDispel = 0x10000000
		};

		enum {
			kArchetype_ValueMod = 0,
			kArchetype_Script,
			kArchetype_Dispel,
			kArchetype_CureDisease,
			kArchetype_Absorb,
			kArchetype_DualValueMod,
			kArchetype_Calm,
			kArchetype_Demoralize,
			kArchetype_Frenzy,
			kArchetype_Disarm,
			kArchetype_CommandSummoned,
			kArchetype_Invisibility,
			kArchetype_Light,
			kArchetype_Lock = 15,
			kArchetype_Open,
			kArchetype_BoundWeapon,
			kArchetype_SummonCreature,
			kArchetype_DetectLife,
			kArchetype_Telekinesis,
			kArchetype_Paralysis,
			kArchetype_Reanimate,
			kArchetype_SoulTrap,
			kArchetype_TurnUndead,
			kArchetype_Guide,
			kArchetype_WerewolfFeed,
			kArchetype_CureParalysis,
			kArchetype_CureAddiction,
			kArchetype_CurePoison,
			kArchetype_Concussion,
			kArchetype_ValueAndParts,
			kArchetype_AccumulateMagnitude,
			kArchetype_Stagger,
			kArchetype_PeakValueMod,
			kArchetype_Cloak,
			kArchetype_Werewolf,
			kArchetype_SlowTime,
			kArchetype_Rally,
			kArchetype_EnhanceWeapon,
			kArchetype_SpawnHazard,
			kArchetype_Etherealize,
			kArchetype_Banish,
			kArchetype_Disguise = 44,
			kArchetype_GrabActor,
			kArchetype_VampireLord
		};

		enum {
			kCastingType_ConstantEffect = 0,
			kCastingType_FireAndForget,
			kCastingType_Concentration
		};

		enum {
			kDeliveryType_Self = 0,
			kDeliveryType_Contact,
			kDeliveryType_Aimed,
			kDeliveryType_TargetActor,
			kDeliveryType_TargetLocation
		};

		enum {
			kVolume_Loud = 0,
			kVolume_Normal,
			kVolume_Silent,
			kVolume_VeryLoud
		};

		UInt32					flags;				// 00 - init'd to 0
		float					baseCost;			// 04 - init'd to 0
		TESForm*				primaryObject;		// 08 - init'd to 0
		UInt32					school;				// 0C - init'd to FFFFFFFF
		UInt32					resistance;			// 10 - init'd to FFFFFFFF
		UInt16					unk14;				// 14 - init'd to 0 
		UInt8					pad16[2];			// 16
		TESObjectLIGH*			light;				// 18 - init'd to 0
		float					taperWeight;		// 1C - init'd to 0
		TESEffectShader*		hitShader;			// 20 - init'd to 0
		TESEffectShader*		enchantShader;		// 24 - init'd to 0
		UInt32					level;				// 28 - init'd to 0
		UInt32					area;				// 2C - init'd to 0
		float					castingTime;		// 30 - init'd to 0
		float					taperCurve;			// 34 - init'd to 0
		float					taperDuration;		// 38 - init'd to 0
		float					secondAVWeight;		// 3C - init'd to 0 float - Always 0
		UInt32					archetype;			// 40 - init'd to 0
		UInt32					primaryValue;		// 44 - init'd to FFFFFFFF
		BGSProjectile*			projectile;			// 48 - init'd to 0
		BGSExplosion*			explosion;			// 4C - init'd to 0
		UInt32					castType;			// 50 - init'd to 3 cast type?
		UInt32					deliveryType;		// 54 - init'd to 5 cast type?
		UInt32					secondaryValue;		// 58 - init'd to FFFFFFFF
		BGSArtObject*			castingArt;			// 5C - init'd to 0
		BGSArtObject*			hitEffectArt;		// 60 - init'd to 0
		BGSImpactDataSet*		impactDataSet;		// 64 - init'd to 0
		float					skillUsageMult;		// 68 - init'd to 0
		BGSDualCastData*		dualCastData;		// 6C - init'd to 0
		float					dualCastingScale;	// 70 - init'd to 1
		BGSArtObject*			enchantArt;			// 74 - init'd to 0
		UInt32					unk78;				// 78 - init'd to 0
		UInt32					unk7C;				// 7C - init'd to 0
		SpellItem*				equipAbility;		// 80 - init'd to 0
		TESImageSpaceModifier*	imageSpaceMod;		// 84 - init'd to 0
		BGSPerk*				perk;				// 88 - init'd to 0
		UInt32					soundVolume;		// 8C - init'd to 1
		float					aiScore;			// 90 - init'd to 0
		float					delayTime;			// 94 - init'd to 0
	};

	struct SoundInfo
	{
		UInt32		value;
		TESSound*	sound;
	};

	// @members
	//void							** _vtbl;		// 00 - 010776AC
	UInt32							unk30;			// 30
	UInt32							unk34;			// 34
	Properties						properties;		// 38
	BSSimpleList<EffectSetting*>	counterEffects;	// D0
	BSTArray<SoundInfo>				sounds;			// D8
	BSFixedString					description;	// E4
	UInt32							unkE8;			// E8
	UInt32							unkEC;			// EC
	void							* unkF0;		// F0 - linked list

	UInt32 school() { return properties.school; }
	UInt32 level() { return properties.level; }
};
STATIC_ASSERT(sizeof(EffectSetting) == 0xF4);
