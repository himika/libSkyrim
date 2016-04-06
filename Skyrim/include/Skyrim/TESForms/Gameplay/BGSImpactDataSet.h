#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/BGSPreloadable.h"


/*==============================================================================
class BGSImpactDataSet +0000 (_vtbl=0108CFD4)
0000: class BGSImpactDataSet
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class BGSPreloadable
0014: |   |   class BaseFormComponent
==============================================================================*/
// 38
class BGSImpactDataSet : public TESForm,
	public BGSPreloadable
{
public:
	enum { kTypeID = (UInt32)FormType::ImpactDataSet };

	// @members
	UInt32	unk18;	// 18
	UInt32	unk1C;	// 1C
	UInt32	unk20;	// 20
	UInt32	unk24;	// 24
	UInt32	unk28;	// 28
	UInt32	unk2C;	// 2C
	UInt32	unk30;	// 30
	UInt32	unk34;	// 34
};
STATIC_ASSERT(sizeof(BGSImpactDataSet) == 0x38);
