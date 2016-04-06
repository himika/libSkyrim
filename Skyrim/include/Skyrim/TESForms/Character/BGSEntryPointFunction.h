#pragma once

#include "../../BSCore/BSFixedString.h"

class BGSPerk;
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
	
	virtual ~BGSEntryPointFunctionData();		// 00 0054B640

	virtual UInt32	GetType(void) const = 0;	// 01
	virtual void	Unk_002(void) = 0;			// 02
	virtual void	Unk_003(void);				// 03 00588F30 (UInt32 arg) { return; }
	virtual void	Unk_004(void);				// 04 004D43E0 (UInt32 arg1, UInt32 arg2) { return; }
	virtual void	Unk_005(void);				// 05 0054F4B0
	virtual void	Unk_006(void);				// 06 00588F30 (UInt32 arg) { return; }
	virtual void	Unk_007(void);				// 07 005EADD0 (void) { return 0; }
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

	virtual UInt32	GetType() const override;						// 01 009048A0 { return 0x00000004; }
	//virtual ????   Unk_002(????) override;                        // 02 0054BF50
	//virtual ????   Unk_003(????) override;                        // 03 0054C1B0
	//virtual ????   Unk_005(????) override;                        // 05 0054B630
	//virtual ????   Unk_006(????) override;                        // 06 00474D90
	//virtual UInt32 Unk_007(void) override;                        // 07 005E8920 { return (UInt32)unk8; }

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
