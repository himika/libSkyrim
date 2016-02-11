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

		enum {
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

		UInt32					flags;				// 00 - init'd to 0
		float					baseCost;			// 04 - init'd to 0
		TESForm*				primaryObject;		// 08 - init'd to 0 - Assoc. Item
		UInt32					school;				// 0C - init'd to FFFFFFFF - Magic Skill
		UInt32					resistance;			// 10 - init'd to FFFFFFFF - Resist Value
		UInt16					unk14;				// 14 - init'd to 0 
		UInt8					pad16[2];			// 16
		TESObjectLIGH*			light;				// 18 - init'd to 0 - Casting Light
		float					taperWeight;		// 1C - init'd to 0
		TESEffectShader*		hitShader;			// 20 - init'd to 0
		TESEffectShader*		enchantShader;		// 24 - init'd to 0
		UInt32					level;				// 28 - init'd to 0 - Minimum Skill level
		UInt32					area;				// 2C - init'd to 0 - Spellmaking, Area
		float					castingTime;		// 30 - init'd to 0 - Spellmaking, CastingTime
		float					taperCurve;			// 34 - init'd to 0
		float					taperDuration;		// 38 - init'd to 0
		float					secondAVWeight;		// 3C - init'd to 0 float - Always 0
		UInt32					archetype;			// 40 - init'd to 0
		UInt32					primaryValue;		// 44 - init'd to FFFFFFFF - Actor Value
		BGSProjectile*			projectile;			// 48 - init'd to 0
		BGSExplosion*			explosion;			// 4C - init'd to 0
		UInt32					castType;			// 50 - init'd to 3 cast type?
		UInt32					deliveryType;		// 54 - init'd to 5 cast type?
		UInt32					secondaryValue;		// 58 - init'd to FFFFFFFF - Second Actor Value
		BGSArtObject*			castingArt;			// 5C - init'd to 0
		BGSArtObject*			hitEffectArt;		// 60 - init'd to 0
		BGSImpactDataSet*		impactDataSet;		// 64 - init'd to 0
		float					skillUsageMult;		// 68 - init'd to 0
		BGSDualCastData*		dualCastData;		// 6C - init'd to 0
		float					dualCastingScale;	// 70 - init'd to 1
		BGSArtObject*			enchantArt;			// 74 - init'd to 0
		UInt32					unk78;				// 78 - init'd to 0 - unknown
		UInt32					unk7C;				// 7C - init'd to 0 - unknown
		SpellItem*				equipAbility;		// 80 - init'd to 0
		TESImageSpaceModifier*	imageSpaceMod;		// 84 - init'd to 0
		BGSPerk*				perk;				// 88 - init'd to 0 - Perk to Apply
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
