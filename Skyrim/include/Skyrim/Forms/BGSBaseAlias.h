#pragma once

#include "FormTypes.h"
#include "../BSCore/BSFixedString.h"

class TESQuest;

/*==============================================================================
class BGSBaseAlias +0000 (_vtbl=010A32B4)
0000: class BGSBaseAlias
==============================================================================*/
// 14
class BGSBaseAlias // Not actually a form, but its used like one in Papyrus
{
public:
	enum { kTypeID = (UInt32)FormType::Alias };

	virtual ~BGSBaseAlias();								// 0054DF80

	virtual bool					Unk01(UInt32 arg1) = 0;		// 00F51EE8
	virtual void					Unk02(UInt32 arg1) = 0;		// 00F51EE8
	virtual const BSFixedString &	GetTypeString(void) = 0;	// 00F51EE8

	enum {
		kFlag_ReservesRefernce = 1,
		kFlag_Optional = 1 << 1,				// 0x0002
		kFlag_QuestObject = 1 << 2,				// 0x0004
		kFlag_AllowReuseInQuest = 1 << 3,		// 0x0008
		kFlag_AllowDead = 1 << 4,				// 0x0010
		kFlag_0x0020 = 1 << 5,
		kFlag_Essential = 1 << 6,				// 0x0040
		kFlag_AllowDisabled = 1 << 7,			// 0x0080
		kFlag_StoresText = 1 << 8,				// 0x0100
		kFlag_AllowDestroyed = 1 << 12,			// 0x1000
		kFlag_UseStoredText = 1 << 14,			// 0x4000
		kFlag_ClearsNameWhenRemoved = 1 << 18	// 0x20000
	};

	BSFixedString	name;			// 04
	TESQuest		* owner;		// 08
	UInt32			aliasId;		// 0C
	UInt32			flags;			// 10
};
STATIC_ASSERT(sizeof(BGSBaseAlias) == 0x14);