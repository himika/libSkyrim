#pragma once

#include "../../FormComponents/TESForm.h"

/*==============================================================================
class BGSRelationship +0000 (_vtbl=010A3AE4)
0000: class BGSRelationship
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 24
class BGSRelationship : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::Relationship };

	UInt32	unk14;	// 14
	UInt32	unk18;	// 18
	UInt32	unk1C;	// 1C
	UInt32	unk20;	// 20
};
STATIC_ASSERT(sizeof(BGSRelationship) == 0x24);
