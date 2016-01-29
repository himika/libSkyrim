#pragma once

#include "TESForm.h"
#include "../FormComponents/Condition.h"

/*==============================================================================
class TESTopicInfo +0000 (_vtbl=010A6CCC)
0000: class TESTopicInfo
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 2C
class TESTopicInfo : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::TopicInfo };

	enum
	{
		kDialogFlag_Goodbye =					1 << 0,
		kDialogFlag_Random =					1 << 1,
		kDialogFlag_SayOnce =					1 << 2,
		kDialogFlag_RandomEnd =					1 << 5,
		kDialogFlag_InvisibleContinue =			1 << 6,
		kDialogFlag_ForceSubtitle =				1 << 8,
		kDialogFlag_CanMoveWhileGreeting =		1 << 10,
		kDialogFlag_HasNoLipFile =				1 << 11,
		kDialogFlag_RequiresPostProcessing =	1 << 12,
		kDialogFlag_SpendsFavorPoints =			1 << 14,
	};

	UInt32		unk14;				// 14
	UInt32		unk18;				// 18 - show response data from info?
	Condition	* conditions;		// 1C - linked list
	UInt16		unk20;				// 20 - init'd to FFFF
	UInt8		unk22;				// 22
	UInt8		favorLevel;			// 23
	UInt16		dialogFlags;		// 24
	UInt16		hoursUntilReset;	// 26
	void		* unk28;			// 28 - quest pointer?
};
STATIC_ASSERT(sizeof(TESTopicInfo) == 0x2C);
