#pragma once

#include "BaseFormComponent.h"

// 18
class TESAIForm : public BaseFormComponent
{
public:
	// 8 - might be ExtraDataList
	struct Data
	{
		UInt32	unk0;	// 0
		Data	* next;	// 4
	};

	UInt32	flags;		// 04
	UInt16	unk08[3];	// 08
	UInt8	pad0D[2];	// 0D
	Data	unk10;		// 10
};
