#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/BGSPreloadable.h"

/*==============================================================================
class BGSDebris +0000 (_vtbl=01081294)
0000: class BGSDebris
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class BGSPreloadable
0014: |   |   class BaseFormComponent
==============================================================================*/
// 20
class BGSDebris : public TESForm,
	public BGSPreloadable
{
public:
	enum { kTypeID = (UInt32)FormType::Debris };

	struct Data
	{
		UInt32	unk0;
		UInt32	unk4;
	};

	// @members
	Data	unk18;	// 18 - linked list
};
STATIC_ASSERT(sizeof(BGSDebris) == 0x20);
