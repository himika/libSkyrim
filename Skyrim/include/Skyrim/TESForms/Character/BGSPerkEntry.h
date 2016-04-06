#pragma once

#include "BGSEntryPointFunction.h"
#include "../../FormComponents/Condition.h"

class TESQuest;
class SpellItem;
class TESObjectREFR;
class BGSPerk;

/*==============================================================================
class BGSPerkEntry +0000 (_vtbl=010A3658)
0000: class BGSPerkEntry
==============================================================================*/
class BGSPerkEntry
{
public:
	virtual bool	CanProcess(UInt32 numArgs, void *args);				// 00 009EA550 { return false; }
	virtual UInt8	GetType(void) const;								// 01 0092D110 { return 0; }
	virtual BGSEntryPointFunctionData *	GetFunctionData(void) const;	// 02 005EADD0 { return nullptr; }
	virtual ~BGSPerkEntry();											// 03 0054FCB0
	virtual void	Unk_04(void) = 0;									// 04
	virtual void	Unk_05(void);										// 05 006C50E0 { return; }
	virtual void	Unk_06(UInt32 arg);									// 06 00588F30 { return; }
	virtual bool	Unk_07(UInt32 arg);									// 07 00C8CCA0 { return true; }
	virtual void	Unk_08(UInt32 arg);									// 08 00588F30 { return; }
	virtual void	Unk_09(void);										// 09 0054F4B0
	virtual void	Unk_0A(void) = 0;									// 0A
	virtual void	Unk_0B(UInt32 arg) = 0;								// 0B

	// @members
	//void	** _vtbl;	// 00
	UInt8	rank;		// 04
	UInt8	priority;	// 05
	UInt16	type;		// 06
};


/*==============================================================================
class BGSQuestPerkEntry +0000 (_vtbl=010A368C)
0000: class BGSQuestPerkEntry
0000: |   class BGSPerkEntry
==============================================================================*/
class BGSQuestPerkEntry : public BGSPerkEntry
{
public:
	// @override
	virtual void	Unk_04(void) override;				// 005EADD0 (void) { return 0; }
	virtual void	Unk_06(UInt32 arg) override;		// 0054F690
	virtual bool	Unk_07(UInt32 arg) override;		// 0054FCE0
	virtual void	Unk_0A(void) override;				// 0054F4C0
	virtual void	Unk_0B(UInt32 arg) override;		// 00588F30 (UInt32 arg) { return; }

	// @members
	TESQuest	* quest;		// 08
	UInt8		stage;			// 0C
	UInt8		pad[3];			// 0D
};

/*==============================================================================
class BGSAbilityPerkEntry +0000 (_vtbl=010A36C0)
0000: class BGSAbilityPerkEntry
0000: |   class BGSPerkEntry
==============================================================================*/
class BGSAbilityPerkEntry : public BGSPerkEntry
{
public:
	virtual void	Unk_04(void) override;				// 00CAC8A0
	virtual void	Unk_06(UInt32 arg) override;		// 0054F710
	virtual bool	Unk_07(UInt32 arg) override;		// 0054FDE0
	virtual void	Unk_0A(void) override;				// 0054F500
	virtual void	Unk_0B(UInt32 arg) override;		// 0054F530

	// @members
	SpellItem	* spellItem;	// 08
};

/*==============================================================================
class BGSEntryPointPerkEntry +0000 (_vtbl=010A36F4)
0000: class BGSEntryPointPerkEntry
0000: |   class BGSPerkEntry
==============================================================================*/
// 18
class BGSEntryPointPerkEntry : public BGSPerkEntry
{
public:
	enum EntryPointType
	{
		kEntryPoint_Calculate_Weapon_Damage,
		kEntryPoint_Calculate_My_Critical_Hit_Chance,
		kEntryPoint_Calculate_My_Critical_Hit_Damage,
		kEntryPoint_Calculate_Mine_Explode_Chance,
		kEntryPoint_Adjust_Limb_Damage,
		kEntryPoint_Adjust_Book_Skill_Points,
		kEntryPoint_Modify_Recovered_Health,
		kEntryPoint_Get_Should_Attack,
		kEntryPoint_Modify_Buy_Prices,
		kEntryPoint_Add_Leveled_List_On_Death,
		kEntryPoint_Get_Max_Carry_Weight,
		kEntryPoint_Modify_Addiction_Chance,
		kEntryPoint_Modify_Addiction_Duration,
		kEntryPoint_Modify_Positive_Chem_Duration,
		kEntryPoint_Activate,
		kEntryPoint_Ignore_Running_During_Detection,
		kEntryPoint_Ignore_Broken_Lock,
		kEntryPoint_Modify_Enemy_Critical_Hit_Chance,
		kEntryPoint_Modify_Sneak_Attack_Mult,
		kEntryPoint_Modify_Max_Placeable_Mines,
		kEntryPoint_Modify_Bow_Zoom,
		kEntryPoint_Modify_Recover_Arrow_Chance,
		kEntryPoint_Modify_Skill_Use,
		kEntryPoint_Modify_Telekinesis_Distance,
		kEntryPoint_Modify_Telekinesis_Damage_Mult,
		kEntryPoint_Modify_Telekinesis_Damage,
		kEntryPoint_Mod_Bashing_Damage,
		kEntryPoint_Mod_Power_Attack_Stamina,
		kEntryPoint_Mod_Power_Attack_Damage,
		kEntryPoint_Mod_Spell_Magnitude,
		kEntryPoint_Mod_Spell_Duration,
		kEntryPoint_Mod_Secondary_Value_Weight,
		kEntryPoint_Mod_Armor_Weight,
		kEntryPoint_Mod_Incoming_Stagger,
		kEntryPoint_Mod_Target_Stagger,
		kEntryPoint_Mod_Attack_Damage,
		kEntryPoint_Mod_Incoming_Damage,
		kEntryPoint_Mod_Target_Damage_Resistance,
		kEntryPoint_Mod_Spell_Cost,
		kEntryPoint_Mod_Percent_Blocked,
		kEntryPoint_Mod_Shield_Deflect_Arrow_Chance,
		kEntryPoint_Mod_Incoming_Spell_Magnitude,
		kEntryPoint_Mod_Incoming_Spell_Duration,
		kEntryPoint_Mod_Player_Intimidation,
		kEntryPoint_Mod_Player_Reputation,
		kEntryPoint_Mod_Favor_Points,
		kEntryPoint_Mod_Bribe_Amount,
		kEntryPoint_Mod_Detection_Light,
		kEntryPoint_Mod_Detection_Movement,
		kEntryPoint_Mod_Soul_Gem_Recharge,
		kEntryPoint_Set_Sweep_Attack,
		kEntryPoint_Apply_Combat_Hit_Spell,
		kEntryPoint_Apply_Bashing_Spell,
		kEntryPoint_Apply_Reanimate_Spell,
		kEntryPoint_Set_Boolean_Graph_Variable,
		kEntryPoint_Mod_Spell_Casting_Sound_Event,
		kEntryPoint_Modify_Pickpocket_Chance,
		kEntryPoint_Modify_Detection_Sneak_Skill,
		kEntryPoint_Modify_Falling_Damage,
		kEntryPoint_Modify_Lockpick_Sweet_Spot,
		kEntryPoint_Modify_Sell_Prices,
		kEntryPoint_Can_Pickpocket_Equipped_Item,
		kEntryPoint_Modify_Lockpick_level_allowed,
		kEntryPoint_Set_Lockpick_Starting_Arc,
		kEntryPoint_Set_Progression_Picking,
		kEntryPoint_Make_lockpicks_unbreakable_,
		kEntryPoint_Modify_Alchemy_Effectiveness,
		kEntryPoint_Apply_Weapon_Swing_Spell,
		kEntryPoint_Modify_Commanded_Actor_Limit,
		kEntryPoint_Apply_Sneaking_Spell,
		kEntryPoint_Modify_Player_Magic_Slowdown,
		kEntryPoint_Modify_Ward_Magicka_Absorption_Pct,
		kEntryPoint_Modify_Initial_Ingredient_Effects_Learned,
		kEntryPoint_Purify_Alchemy_Ingredients,
		kEntryPoint_Filter_Activation,
		kEntryPoint_Can_dual_cast_spell,
		kEntryPoint_Modify_Tempering_Health,
		kEntryPoint_Modify_Enchantment_Power,
		kEntryPoint_Modify_Soul_Pct_Captured_to_Weapon,
		kEntryPoint_Mod_Soul_Gem_Enchanting,
		kEntryPoint_Mod_applied_enchantments_allowed,
		kEntryPoint_Set_Activate_Label,
		kEntryPoint_Mod_Shout_OK,
		kEntryPoint_Mod_Poison_Dose_Count,
		kEntryPoint_Should_Apply_Placed_Item,
		kEntryPoint_Modify_Armor_Rating,
		kEntryPoint_Modify_lockpicking_crime_chance,
		kEntryPoint_Modify_ingredients_harvested,
		kEntryPoint_Modify_Spell_Range_Target_Loc,
		kEntryPoint_Modify_Potions_Created,
		kEntryPoint_Modify_lockpicking_key_reward_chance,
		kEntryPoint_Allow_Mount_Actor,

		kNumPerkEntryPoints
	};


	virtual bool	CanProcess(UInt32 numArgs, void *args) override;			// 00 0054FE70
	virtual UInt8	GetType(void) const override;								// 01 00941C90 { return this->unk09; }
	virtual BGSEntryPointFunctionData *	GetFunctionData(void) const override;	// 02 00E80F90 { return this->unk0C; }
	virtual ~BGSEntryPointPerkEntry();											// 03 00550280
	virtual void	Unk_04(void) override;										// 04 005C8DE0
	virtual void	Unk_05(void) override;										// 05 0054FFA0
	virtual void	Unk_06(UInt32 arg) override;								// 06 0054F560
	virtual bool	Unk_07(UInt32 arg) override;								// 07 0054F790
	virtual void	Unk_08(UInt32 arg) override;								// 08 0054F5A0
	virtual void	Unk_09(void) override;										// 09 0054F5C0
	virtual void	Unk_0A(void) override;										// 0A 0054F5E0
	virtual void	Unk_0B(UInt32 arg) override;								// 0B 0054F610

	static void Calculate(EntryPointType type, TESObjectREFR *source, ...);


	// @members
	UInt8						type;				// 08 - EntryPointType
	UInt8						unk09;				// 09
	UInt8						numArgs;			// 0A
	BGSEntryPointFunctionData	* functionData;		// 0C
	Condition					* conditions;		// 10
	BGSPerk						* perk;				// 14
};
