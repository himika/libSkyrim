#pragma once

#include "BaseFormComponent.h"

// 10
class TESReactionForm : public BaseFormComponent
{
public:
	// 0C
	struct Data
	{
		UInt32	unk0;	// 00
		UInt32	unk4;	// 04
		UInt32	unk8;	// 08
	};

	// 08
	struct Entry
	{
		Data	* data;	// 00
		Entry	* unk4;	// 04
	};

	Entry	entry;		// 04
	UInt8	unk0C;		// 0C
	UInt8	pad0D[3];	// 0D
};
