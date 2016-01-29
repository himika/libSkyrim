#pragma once

#include "MenuEvent.h"
#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSFixedString.h"

// 09C+
class UserEventManager : public BSTSingletonExplicit<UserEventManager>
{
public:
	UserEventManager()
	{
		ctor();
	}

	// 14;
	struct Data
	{
		BSFixedString	unk00;
		UInt32			unk04;
		UInt32			unk08;
		UInt32			unk0C;
		BSFixedString	unk10;
	};
	STATIC_ASSERT(sizeof(Data) == 0x14);

	// @members
	UInt32				unk00;		// 00
	BSTEventSource<UserEventEnabledEvent> userEventEnabledEventSource;	// 04
	void *				unk34[(0x78 - 0x34) >> 2];						// 34
	BSTArray<Data>		unk78;		// 78
	BSTArray<UInt32>	unk84;		// 84
	SInt32				unk90;		// 90 - init'd -1
	UInt32				unk94;		// 94 - init'd 0x80000000
	UInt8				unk98;		// 98 - init'd 0
	UInt8				unk99;		// 99 - init'd 0
	UInt8				unk9A;		// 9A - init'd 0

	DEFINE_MEMBER_FN(ctor, UserEventManager*, 0x00A68770);
};
STATIC_ASSERT(offsetof(UserEventManager, unk78) == 0x78);
STATIC_ASSERT(offsetof(UserEventManager, unk84) == 0x84);
