#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/TESModel.h"
#include "../../FormComponents/TESTexture.h"

/*==============================================================================
class TESClimate +0000 (_vtbl=01087084)
0000: class TESClimate
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 48
class TESClimate : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::Climate };

	struct Data28
	{
		UInt32	unk0;
		UInt32	unk4;
	};

	TESModel	model;			// 14
	Data28		unk28;			// 28
	TESTexture	textures[2];	// 30
	UInt8		unk40[6];		// 40
	UInt8		pad46[2];		// 46
};
STATIC_ASSERT(sizeof(TESClimate) == 0x48);
