#pragma once

#include "TESForm.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESDescription.h"
#include "../FormComponents/TESIcon.h"
#include "../FormComponents/Condition.h"
#include "../FormComponents/BGSPerkRankArray.h"
#include "../BSCore/BSTArray.h"

class BGSPerk;
class Actor;
class SpellItem;

/*==============================================================================
class BGSEntryPointFunctionData +0000 (_vtbl=010A2BAC)
0000: class BGSEntryPointFunctionData
==============================================================================*/
class BGSEntryPointFunctionData
{
public:
	enum FunctionType
	{
		kFunctionType_Invalid = 0,
		kFunctionType_OneValue,
		kFunctionType_TwoValue,
		kFunctionType_LeveledList,
		kFunctionType_DataActivateChoice,
		kFunctionType_DataSpellItem,
		kFunctionType_DataBooleanGraphVariable,
		kFunctionType_DataText
	};
	
	virtual ~BGSEntryPointFunctionData();		// 0054B640

	virtual UInt32	GetType(void) const = 0;	// pure
	virtual void	Unk_002(void) = 0;			// pure
	virtual void	Unk_003(void);				// 00588F30 (UInt32 arg) { return; }
	virtual void	Unk_004(void);				// 004D43E0 (UInt32 arg1, UInt32 arg2) { return; }
	virtual void	Unk_005(void);				// 0054F4B0
	virtual void	Unk_006(void);				// 00588F30 (UInt32 arg) { return; }
	virtual void	Unk_007(void);				// 005EADD0 (void) { return 0; }
};

//class BGSEntryPointFunctionDataOneValue;				// type: 1
//class BGSEntryPointFunctionDataTwoValue;				// type: 2
//class BGSEntryPointFunctionDataLeveledList;			// type: 3

/*==============================================================================
class BGSEntryPointFunctionDataActivateChoice +0000 (_vtbl=010A2C60)
0000: class BGSEntryPointFunctionDataActivateChoice
0000: |   class BGSEntryPointFunctionData
==============================================================================*/
// 14
class BGSEntryPointFunctionDataActivateChoice : public BGSEntryPointFunctionData
{
public:
	enum Flags
	{
		kFlag_RunImmediately = 1,
		kFlag_ReplaceDefault = 2
	};

	virtual ~BGSEntryPointFunctionDataActivateChoice();				// 0054B6D0

	virtual UInt32	GetType() const override;						// 009048A0 { return 0x00000004; }
	//virtual ????   Unk_002(????) override;                        // 0054BF50
	//virtual ????   Unk_003(????) override;                        // 0054C1B0
	//virtual ????   Unk_005(????) override;                        // 0054B630
	//virtual ????   Unk_006(????) override;                        // 00474D90
	//virtual UInt32 Unk_007(void) override;                        // 005E8920 { return (UInt32)unk8; }

	// @members
	BSFixedString	unk04;			// 04
	BGSPerk			* perk;			// 08 - init'd arg1
	SpellItem		* applySpell;	// 0C - init'd 0
	UInt16			flags;			// 10 - init'd 0
	UInt16			unk12;			// 12 - init'd arg2 - flag ?

private:
	DEFINE_MEMBER_FN(ctor, BGSEntryPointFunctionDataActivateChoice *, 0x0054B690, BGSPerk *a_perk, UInt16 arg2);
};

//class BGSEntryPointFunctionDataSpellItem;				// type: 5
//class BGSEntryPointFunctionDataBooleanGraphVariable;	// type: 6
//class BGSEntryPointFunctionDataText;					// type: 7


/*==============================================================================
class BGSPerkEntry +0000 (_vtbl=010A3658)
0000: class BGSPerkEntry
==============================================================================*/
class BGSPerkEntry
{
public:
	virtual bool	CanProcess(UInt32 numArgs, void *args);	// 009EA550 { return false; }
	virtual UInt8	GetType(void) const;					// 0092D110 { return 0; }
	virtual BGSEntryPointFunctionData *	GetFunctionData(void) const;	// 005EADD0 { return nullptr; }
	virtual ~BGSPerkEntry();								// 0054FCB0
	virtual void	Unk_04(void) = 0;						// pure
	virtual void	Unk_05(void);							// 006C50E0 { return; }
	virtual void	Unk_06(UInt32 arg);						// 00588F30 { return; }
	virtual bool	Unk_07(UInt32 arg);						// 00C8CCA0 { return true; }
	virtual void	Unk_08(UInt32 arg);						// 00588F30 { return; }
	virtual void	Unk_09(void);							// 0054F4B0
	virtual void	Unk_0A(void) = 0;						// pure
	virtual void	Unk_0B(UInt32 arg) = 0;					// pure

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

	TESQuest	* quest;
	UInt8		stage;
	UInt8		pad[3];
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

	SpellItem	* spellItem;
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


	virtual bool	CanProcess(UInt32 numArgs, void *args) override;	// 0054FE70
	virtual UInt8	GetType(void) const override;						// 00941C90 { return this->unk09; }
	virtual BGSEntryPointFunctionData *	GetFunctionData(void) const override;	// 00E80F90 { return this->unk0C; }
	virtual ~BGSEntryPointPerkEntry();									// 00550280
	virtual void	Unk_04(void) override;								// 005C8DE0
	virtual void	Unk_05(void) override;								// 0054FFA0
	virtual void	Unk_06(UInt32 arg) override;						// 0054F560
	virtual bool	Unk_07(UInt32 arg) override;						// 0054F790
	virtual void	Unk_08(UInt32 arg) override;						// 0054F5A0
	virtual void	Unk_09(void) override;								// 0054F5C0
	virtual void	Unk_0A(void) override;								// 0054F5E0
	virtual void	Unk_0B(UInt32 arg) override;						// 0054F610

	static void Calculate(EntryPointType type, TESObjectREFR *source, ...);

	UInt8						type;				// 08 - EntryPointType
	UInt8						unk09;				// 09
	UInt8						numArgs;			// 0A
	BGSEntryPointFunctionData	* functionData;		// 0C
	Condition					* conditions;		// 10
	BGSPerk						* perk;				// 14
};


/*==============================================================================
class BGSPerk +0000 (_vtbl=010A37CC)
0000: class BGSPerk
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class TESDescription
001C: |   |   class BaseFormComponent
0028: |   class TESIcon
0028: |   |   class TESTexture
0028: |   |   |   class BaseFormComponent
==============================================================================*/
// 4C
class BGSPerk : public TESForm,
	public TESFullName,
	public TESDescription,
	public TESIcon
{
public:
	enum { kTypeID = (UInt32)FormType::Perk };

	/*==============================================================================
	class BGSPerk::FindPerkInRanksVisitor +0000 (_vtbl=010D1288)
	0000: class BGSPerk::FindPerkInRanksVisitor
	0000: |   class PerkRankVisitor
	==============================================================================*/
	class FindPerkInRanksVisitor : public PerkRankVisitor
	{
	public:
		virtual void Visit(void);	// 0054F460
	};

	/*==============================================================================
	class BGSPerk::ApplyPerksVisitor +0000 (_vtbl=010D1290)
	0000: class BGSPerk::ApplyPerksVisitor
	0000: |   class PerkRankVisitor
	==============================================================================*/
	class ApplyPerksVisitor : public PerkRankVisitor
	{
	public:
		virtual void Visit(void);	// 0054F480
	};

	/*==============================================================================
	class BGSPerk::AddPerkVisitor +0000 (_vtbl=010D1D84)
	0000: class BGSPerk::AddPerkVisitor
	0000: |   class PerkRankVisitor
	==============================================================================*/
	class AddPerkVisitor : public PerkRankVisitor
	{
	public:
		virtual void Visit(void);	// 0054F640
	};

	// @members
	UInt8							unk30;		// 30
	UInt8							unk31;		// 31
	UInt8							unk32;		// 32
	UInt8							unk33;		// 33
	UInt8							unk34;		// 34
	UInt8							pad35[3];	// 35
	Condition						* conditions;	// 38
	BSTArray<BGSPerkEntry*>			perkEntries;	// 3C
	BGSPerk *						nextPerk;		// 48
};
STATIC_ASSERT(sizeof(BGSPerk) == 0x4C);


class PerkEntryVisitor
{
public:
	virtual UInt32 Visit(BGSPerkEntry *perkEntry) = 0;
};
