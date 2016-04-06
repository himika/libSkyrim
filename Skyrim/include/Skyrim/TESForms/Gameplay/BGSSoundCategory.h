#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/BSISoundCategory.h"

/*==============================================================================
class BGSSoundCategory +0000 (_vtbl=0108DF3C)
0000: class BGSSoundCategory
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class BSISoundCategory
==============================================================================*/
// 38
class BGSSoundCategory : public TESForm,
	public TESFullName,
	public BSISoundCategory
{
public:
	enum { kTypeID = (UInt32)FormType::SoundCategory };

	// @members
	UInt32	unk20;	// 20 - init'd to 0
	UInt32	unk24;	// 24 - init'd to 0 
	UInt16	unk28;	// 28 - init'd to 0
	UInt16	unk2A;	// 2A - init'd to 0
	UInt16	unk2C;	// 2C - init'd to FFFF
	UInt16	unk2E;	// 2E - init'd to FFFF
	float	unk30;	// 30 - init'd to 1
	float	unk34;	// 34 - init'd to 1
};
STATIC_ASSERT(sizeof(BGSSoundCategory) == 0x38);
