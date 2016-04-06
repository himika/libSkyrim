#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../BSCore/BSFixedString.h"

/*==============================================================================
class BGSMaterialType +0000 (_vtbl=0108D3A4)
0000: class BGSMaterialType
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 38
class BGSMaterialType : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::MaterialType };

	// C
	struct Data20
	{
		float	unk0;
		float	unk4;
		float	unk8;
	};


	// @members
	TESForm				* parentType;		// 14 - init'd to 0
	BSFixedString		unk18;				// 18 - init'd to 0
	UInt32				unk1C;				// 1C - init'd to 0
	Data20				unk20;				// 20
	float				unk2C;				// 2C - init'd to 1
	UInt32				unk30;				// 30 - init'd to 0
	TESForm				* impactDataSet;	// 34 - init'd to 0
};
STATIC_ASSERT(sizeof(BGSMaterialType) == 0x38);
