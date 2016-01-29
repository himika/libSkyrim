#pragma once

#include "TESObjectACTI.h"
#include "../BSCore/BSTArray.h"

/*==============================================================================
class TESFurniture +0000 (_vtbl=01082C94)
0000: class TESFurniture
0000: |   class TESObjectACTI
0000: |   |   class TESBoundAnimObject
0000: |   |   |   class TESBoundObject
0000: |   |   |   |   class TESObject
0000: |   |   |   |   |   class TESForm
0000: |   |   |   |   |   |   class BaseFormComponent
0020: |   |   class TESFullName
0020: |   |   |   class BaseFormComponent
0028: |   |   class TESModelTextureSwap
0028: |   |   |   class TESModel
0028: |   |   |   |   class BaseFormComponent
005C: |   |   class TESMagicTargetForm
0044: |   |   class BGSDestructibleObjectForm
0044: |   |   |   class BaseFormComponent
004C: |   |   class BGSOpenCloseForm
0050: |   |   class BGSKeywordForm
0050: |   |   |   class BaseFormComponent
==============================================================================*/
// 84
class TESFurniture : public TESObjectACTI
{
public:
	enum { kTypeID = (UInt32)FormType::Furniture };

	// 4
	struct Data78
	{
		UInt8	unk0;		// 0
		UInt8	unk1;		// 1
		UInt8	pad2[2];	// 2
	};

	BSTArray<void*>	unk6C;
	Data78	unk78;	// 78
	UInt32	unk7C;	// 7C
	UInt32	unk80;	// 80
};
STATIC_ASSERT(sizeof(TESFurniture) == 0x84);
