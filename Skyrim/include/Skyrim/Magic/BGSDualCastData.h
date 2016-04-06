#pragma once

// c:_skyrim\code\tesv\magic\BGSDualCastData.h

#include "../Forms/TESBoundObject.h"

/*==============================================================================
class BGSDualCastData +0000 (_vtbl=01076E2C)
0000: class BGSDualCastData
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
==============================================================================*/
// 38
class BGSDualCastData : public TESBoundObject
{
public:
	enum { kTypeID = (UInt32)FormType::DualCastData };

	// 18
	struct Data
	{
		UInt32	unk00;	// 00
		UInt32	unk04;	// 04
		UInt32	unk08;	// 08
		UInt32	unk0C;	// 0C
		UInt32	unk10;	// 10
		UInt32	unk14;	// 14
	};

	Data	unk20;	// 20
};
STATIC_ASSERT(sizeof(BGSDualCastData) == 0x38);
