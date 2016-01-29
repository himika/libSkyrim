#pragma once

#include "BaseFormComponent.h"
#include "../BSCore/BSTArray.h"

class TESForm;
class TESGlobal;

/*==============================================================================
class TESLeveledList +0000 (_vtbl=0107CD2C)
0000: class TESLeveledList
0000: |   class BaseFormComponent
==============================================================================*/
// 14
class TESLeveledList : public BaseFormComponent
{
public:
	struct Entry
	{
		TESForm		* form;		// 00 - init'd to 0
		UInt16		count;		// 04 - init'd to 1
		UInt16		level;		// 06 - init'd to 1
		UInt32		unk08;		// 08 - init'd to 0
	};

	struct CalcuratedResult
	{
		TESForm		* form;		// 00
		UInt32		count;		// 04
		UInt32		unk08;		// 08
		UInt32		unk0C;		// 0C
		float		unk10;		// 10 - 1.0f
	};

	enum
	{
		kFlagCalculateFromAllLevelsLTPCLevel	= 1 << 0,
		kFlagCalculateForEachItemInCount		= 1 << 1,
		kFlagUseAll								= 1 << 2,
		kFlagSpecialLoot						= 1 << 3
	};

	virtual UInt8	GetLevChanceValue(void);				// 04 00452680 { return (chanceGlobal) ? (UInt8)chanceGlobal->value : chanceValue; } called from 00452FC9
	virtual bool	HasFlagUseAll(void);					// 05 004526D0 { return (flags & 2) != 0; } called from 00453700
	virtual SInt32	GetLevDifferenceMax(void);				// 06 005EADD0 { return 0; } called from 00453185
	virtual bool	IsValidLevItem(FormType type) = 0;		// 07 pure

	inline bool Calcurate(UInt16 level, UInt16 count, BSScrapArray<CalcuratedResult> &result, bool ignoreChanceValue = false, bool unk = true)
	{
		return Calcurate_Impl(level, count, result, ignoreChanceValue, unk);
	}

	DEFINE_MEMBER_FN(Unk_00452FA0_Impl, UInt32, 0x00452FA0, UInt32 arg1, void *arg2, void *arg3, void *arg4, UInt32 arg5, UInt32 arg6, UInt32 arg7);

	DEFINE_MEMBER_FN(Calcurate_Impl, bool, 0x00453640, UInt16 level, UInt16 count, BSScrapArray<CalcuratedResult> &result, bool ignoreChanceValue, bool unk);


	// @members
	Entry		* entries;			// 04
	UInt8		chanceValue;		// 08
	UInt8		flags;				// 09
	UInt8		length;				// 0A
	UInt8		unk0B;				// 0B
	void		* unk0C;			// 0C
	TESGlobal	* chanceGlobal;		// 10
};
