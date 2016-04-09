#pragma once

// c:_skyrim\code\tesv\magic\EffectSetting.h

#include "../FormComponents/TESForm.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/BGSMenuDisplayObject.h"
#include "../FormComponents/BGSKeywordForm.h"
#include "../FormComponents/Condition.h"
#include "../BSCore/BSTArray.h"
#include "../BSCore/BSTList.h"

class TESObjectLIGH;
class TESEffectShader;
class BGSProjectile;
class BGSExplosion;
class BGSArtObject;
class BGSImpactDataSet;
class BGSDualCastData;
class TESImageSpaceModifier;
class BGSSoundDescriptorForm;


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
// F4 - magic effect
class EffectSetting : public TESForm,
	public TESFullName,				// 14
	public BGSMenuDisplayObject,	// 1C
	public BGSKeywordForm			// 24
{
public:
	enum { kTypeID = (UInt32)FormType::EffectSetting };


	// 98
	struct Properties
	{
		enum Flag
		{
			kEffectType_Hostile			= (1 << 0),		// 00000001
			kEffectType_Recover			= (1 << 1),		// 00000002
			kEffectType_Detrimental		= (1 << 2),		// 00000004
			kEffectType_Unk08			= (1 << 3),		// 00000008
			kEffectType_NoHitEvent		= (1 << 4),		// 00000010
			kEffectType_Unk20			= (1 << 5),		// 00000020
			kEffectType_Unk40			= (1 << 6),		// 00000040
			kEffectType_Unk80			= (1 << 7),		// 00000080
			kEffectType_DispelKeywords	= (1 << 8),		// 00000100
			kEffectType_NoDuration		= (1 << 9),		// 00000200
			kEffectType_NoMagnitude		= (1 << 10),	// 00000400
			kEffectType_NoArea			= (1 << 11),	// 00000800
			kEffectType_FXPersist		= (1 << 12),	// 00001000
			kEffectType_Unk2000			= (1 << 13),	// 00002000
			kEffectType_GloryVisuals	= (1 << 14),	// 00004000
			kEffectType_HideInUI		= (1 << 15),	// 00008000
			kEffectType_Unk10000		= (1 << 16),	// 00010000
			kEffectType_NoRecast		= (1 << 17),	// 00020000
			kEffectType_Unk40000		= (1 << 18),	// 00040000
			kEffectType_Unk80000		= (1 << 19),	// 00080000
			kEffectType_Unk100000		= (1 << 20),	// 00100000
			kEffectType_Magnitude		= (1 << 21),	// 00200000
			kEffectType_Duration		= (1 << 22),	// 00400000
			kEffectType_Unk800000		= (1 << 23),	// 00800000
			kEffectType_Unk1000000		= (1 << 24),	// 01000000
			kEffectType_Unk2000000		= (1 << 25),	// 02000000
			kEffectType_Painless		= (1 << 26),	// 04000000
			kEffectType_NoHitEffect		= (1 << 27),	// 08000000
			kEffectType_NoDeathDispel	= (1 << 28)		// 10000000
		};

		enum Archetype
		{
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

		enum CastingType
		{
			kCastingType_ConstantEffect = 0,
			kCastingType_FireAndForget,
			kCastingType_Concentration
		};

		enum DeliveryType
		{
			kDeliveryType_Self = 0,
			kDeliveryType_Contact,
			kDeliveryType_Aimed,
			kDeliveryType_TargetActor,
			kDeliveryType_TargetLocation
		};

		enum
		{
			kVolume_Loud = 0,
			kVolume_Normal,
			kVolume_Silent,
			kVolume_VeryLoud
		};

		enum
		{
			kActorValue_Aggression = 0,
			kActorValue_Confidence,
			kActorValue_Energy,
			kActorValue_Morality,
			kActorValue_Mood,
			kActorValue_Assistance,
			kActorValue_Onehanded,
			kActorValue_Twohanded,
			kActorValue_Marksman,
			kActorValue_Block,
			kActorValue_Smithing,
			kActorValue_HeavyArmor,
			kActorValue_LightArmor,
			kActorValue_Pickpocket,
			kActorValue_Lockpicking,
			kActorValue_Sneak,
			kActorValue_Alchemy,
			kActorValue_Speechcraft,
			kActorValue_Alteration,
			kActorValue_Conjuration,
			kActorValue_Destruction,
			kActorValue_Illusion,
			kActorValue_Restoration,
			kActorValue_Enchanting,
			kActorValue_Health,
			kActorValue_Magicka,
			kActorValue_Stamina,
			kActorValue_Healrate,
			kActorValue_MagickaRate,
			kActorValue_StaminaRate,
			kActorValue_SpeedMult,
			kActorValue_InventoryWeight,
			kActorValue_CarryWeight,
			kActorValue_CritChance,
			kActorValue_MeleeDamage,
			kActorValue_UnarmedDamage,
			kActorValue_Mass,
			kActorValue_VoicePoints,
			kActorValue_VoiceRate,
			kActorValue_DamageResist,
			kActorValue_PoisonResist,
			kActorValue_FireResist,
			kActorValue_ElectricResist,
			kActorValue_FrostResist,
			kActorValue_MagicResist,
			kActorValue_DiseaseResist,
			kActorValue_PerceptionCondition,
			kActorValue_EnduranceCondition,
			kActorValue_LeftAttackCondition,
			kActorValue_RightAttackCondition,
			kActorValue_LeftMobilityCondition,
			kActorValue_RightMobilityCondition,
			kActorValue_BrainCondition,
			kActorValue_Paralysis,
			kActorValue_Invisibility,
			kActorValue_NightEye,
			kActorValue_DetectLifeRange,
			kActorValue_WaterBreathing,
			kActorValue_WaterWalking,
			kActorValue_IgnoreCrippledLimbs,
			kActorValue_Fame,
			kActorValue_Infamy,
			kActorValue_JumpingBonus,
			kActorValue_WardPower,
			kActorValue_RightItemCharge,
			kActorValue_ArmorPerks,
			kActorValue_ShieldPerks,
			kActorValue_WardDeflection,
			kActorValue_Variable01,
			kActorValue_Variable02,
			kActorValue_Variable03,
			kActorValue_Variable04,
			kActorValue_Variable05,
			kActorValue_Variable06,
			kActorValue_Variable07,
			kActorValue_Variable08,
			kActorValue_Variable09,
			kActorValue_Variable10,
			kActorValue_BowSpeedBonus,
			kActorValue_FavorActive,
			kActorValue_FavorSperDay,
			kActorValue_FavorSperDaytimer,
			kActorValue_LeftItemCharge,
			kActorValue_AbsorbChance,
			kActorValue_Blindness,
			kActorValue_WeaponSpeedMult,
			kActorValue_ShoutRecoveryMult,
			kActorValue_BowStaggerBonus,
			kActorValue_Telekinesis,
			kActorValue_FavorPointsBonus,
			kActorValue_LastBribedIntimidated,
			kActorValue_LastFlattered,
			kActorValue_MovementNoiseMult,
			kActorValue_BypassVendorStolenCheck,
			kActorValue_BypassVendorKeywordCheck,
			kActorValue_WaitingForPlayer,
			kActorValue_OnehandedMod,
			kActorValue_TwohandedMod,
			kActorValue_MarksmanMod,
			kActorValue_BlockMod,
			kActorValue_SmithingMod,
			kActorValue_HeavyArmorMod,
			kActorValue_LightArmorMod,
			kActorValue_PickpocketMod,
			kActorValue_LockpickingMod,
			kActorValue_SneakMod,
			kActorValue_AlchemyMod,
			kActorValue_SpeechcraftMod,
			kActorValue_AlterationMod,
			kActorValue_ConjurationMod,
			kActorValue_DestructionMod,
			kActorValue_IllusionMod,
			kActorValue_RestorationMod,
			kActorValue_EnchantingMod,
			kActorValue_OnehandedSkillAdvance,
			kActorValue_TwohandedSkillAdvance,
			kActorValue_MarksmanSkillAdvance,
			kActorValue_BlockSkillAdvance,
			kActorValue_SmithingSkillAdvance,
			kActorValue_HeavyArmorSkillAdvance,
			kActorValue_LightArmorSkillAdvance,
			kActorValue_PickpocketSkillAdvance,
			kActorValue_LockpickingSkillAdvance,
			kActorValue_SneakSkillAdvance,
			kActorValue_AlchemySkillAdvance,
			kActorValue_SpeechcraftSkillAdvance,
			kActorValue_AlterationSkillAdvance,
			kActorValue_ConjurationSkillAdvance,
			kActorValue_DestructionSkillAdvance,
			kActorValue_IllusionSkillAdvance,
			kActorValue_RestorationSkillAdvance,
			kActorValue_EnchantingSkillAdvance,
			kActorValue_LeftWeaponSpeedMult,
			kActorValue_DragonSouls,
			kActorValue_CombatHealthRegenMult,
			kActorValue_OnehandedPowerMod,
			kActorValue_TwohandedPowerMod,
			kActorValue_MarksmanPowerMod,
			kActorValue_BlockPowerMod,
			kActorValue_SmithingPowerMod,
			kActorValue_HeavyarmorPowerMod,
			kActorValue_LightarmorPowerMod,
			kActorValue_PickpocketPowerMod,
			kActorValue_LockpickingPowerMod,
			kActorValue_SneakPowerMod,
			kActorValue_AlchemyPowerMod,
			kActorValue_SpeechcraftPowerMod,
			kActorValue_AlterationPowerMod,
			kActorValue_ConjurationPowerMod,
			kActorValue_DestructionPowerMod,
			kActorValue_IllusionPowerMod,
			kActorValue_RestorationPowerMod,
			kActorValue_EnchantingPowerMod,
			kActorValue_Dragonrend,
			kActorValue_AttackDamageMult,
			kActorValue_HealRateMult,
			kActorValue_MagickaRateMult,
			kActorValue_StaminaRateMult,
			kActorValue_WerewolfPerks,
			kActorValue_VampirePerks,
			kActorValue_GrabActorOffset,
			kActorValue_Grabbed,
			kActorValue_Deprecated05,
			kActorValue_ReflectDamage
		};

		// @members
		UInt32					flags;				// 00 (38) - init'd to 0
		float					baseCost;			// 04 (3C) - init'd to 0
		TESForm					* primaryObject;	// 08 (40) - init'd to 0 - Assoc. Item
		UInt32					school;				// 0C (44) - init'd to FFFFFFFF - Magic Skill
		UInt32					resistance;			// 10 (48) - init'd to FFFFFFFF - Resist Value
		UInt16					unk14;				// 14 (4C) - init'd to 0 
		UInt8					pad16[2];			// 16 (4E)
		TESObjectLIGH			* light;			// 18 (50) - init'd to 0 - Casting Light
		float					taperWeight;		// 1C (54) - init'd to 0
		TESEffectShader			* hitShader;		// 20 (58) - init'd to 0
		TESEffectShader			* enchantShader;	// 24 (5C) - init'd to 0
		UInt32					level;				// 28 (60) - init'd to 0 - Minimum Skill level
		UInt32					area;				// 2C (64) - init'd to 0 - Spellmaking, Area
		float					castingTime;		// 30 (68) - init'd to 0 - Spellmaking, CastingTime
		float					taperCurve;			// 34 (6C) - init'd to 0
		float					taperDuration;		// 38 (70) - init'd to 0
		float					secondAVWeight;		// 3C (74) - init'd to 0 float - Always 0
		UInt32					archetype;			// 40 (78) - init'd to 0
		UInt32					primaryValue;		// 44 (7C) - init'd to FFFFFFFF - Actor Value
		BGSProjectile			* projectile;		// 48 (80) - init'd to 0
		BGSExplosion			* explosion;		// 4C (84) - init'd to 0
		UInt32					castType;			// 50 (88) - init'd to 3 cast type?
		UInt32					deliveryType;		// 54 (8C) - init'd to 5 cast type?
		UInt32					secondaryValue;		// 58 (90) - init'd to FFFFFFFF - Second Actor Value
		BGSArtObject			* castingArt;		// 5C (94) - init'd to 0
		BGSArtObject			* hitEffectArt;		// 60 - init'd to 0
		BGSImpactDataSet		* impactDataSet;	// 64 - init'd to 0
		float					skillUsageMult;		// 68 - init'd to 0
		BGSDualCastData			* dualCastData;		// 6C - init'd to 0
		float					dualCastingScale;	// 70 - init'd to 1
		BGSArtObject			* enchantArt;		// 74 - init'd to 0
		UInt32					unk78;				// 78 - init'd to 0 - unknown
		UInt32					unk7C;				// 7C - init'd to 0 - unknown
		SpellItem				* equipAbility;		// 80 - init'd to 0
		TESImageSpaceModifier	* imageSpaceMod;	// 84 - init'd to 0
		BGSPerk					* perk;				// 88 - init'd to 0 - Perk to Apply
		UInt32					soundVolume;		// 8C - init'd to 1
		float					aiScore;			// 90 - init'd to 0
		float					delayTime;			// 94 - init'd to 0
	};

	struct SoundInfo
	{
		UInt32					value;		// 00
		BGSSoundDescriptorForm	* sound;	// 04
	};


	virtual ~EffectSetting();		// 00405020

   // @override class TESForm : (vtbl=010776AC)
	virtual void			Unk_05(void) override;								// 05 00404600
	virtual bool			LoadForm(TESFile *mod) override;					// 06 004047E0
	virtual void			InitItem(void) override;							// 13 00404BB0
	virtual void			CopyFrom(TESForm * srcForm) override;				// 2F 004043B0
	virtual const char *	GetTypeString(void) const override;					// 39 00403EF0

	// @override class BGSKeywordForm : (vtbl=0107779C)
	virtual bool			HasKeyword(BGSKeyword *keyword) const override;		// 04 00404290


	UInt32 school() { return properties.school; }
	UInt32 level() { return properties.level; }


	// @members
	//void							** _vtbl;		// 00 - 010776AC
	UInt32							unk30;			// 30
	UInt32							unk34;			// 34
	Properties						properties;		// 38
	BSSimpleList<EffectSetting *>	counterEffects;	// D0
	BSTArray<SoundInfo>				sounds;			// D8
	BSFixedString					description;	// E4
	UInt32							unkE8;			// E8
	UInt32							unkEC;			// EC
	Condition						conditions;		// F0

private:
	DEFINE_MEMBER_FN(ctor, EffectSetting *, 0x00404630);
	DEFINE_MEMBER_FN(dtor, void, 0x00404720);
};
STATIC_ASSERT(sizeof(EffectSetting) == 0xF4);
