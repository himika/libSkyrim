#pragma once

#include "TESForm.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESModelTextureSwap.h"
#include "../FormComponents/TESModelTri.h"
#include "../BSCore/BSTArray.h"

// 98
/*==============================================================================
class BGSHeadPart +0000 (_vtbl=010A2E84)
0000: class BGSHeadPart
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class TESModelTextureSwap
001C: |   |   class TESModel
001C: |   |   |   class BaseFormComponent
==============================================================================*/
class BGSHeadPart : public TESForm,
	public TESFullName,						// 14
	public TESModelTextureSwap				// 1C
{
public:
	enum { kTypeID = (UInt32)FormType::HeadPart };


	enum {
		kTypeMisc = 0,
		kTypeFace,
		kTypeEyes,
		kTypeHair,
		kTypeFacialHair,
		kTypeScar,
		kTypeBrows,
		kNumTypes
	};

	enum 
	{
		kFlagPlayable	= 1 << 0,
		kFlagMale		= 1 << 1,
		kFlagFemale		= 1 << 2,
		kFlagExtraPart	= 1 << 3,
		kFlagSolidTint	= 1 << 4
	};

	// @members
	UInt8					partFlags;		// 38 // Flag Inconsistencies (Is Extra Part?) (Use Solid Tint?)
	UInt8					pad39[3];       // 39
	UInt32					type;			// 3C
	BSTArray <BGSHeadPart*>	extraParts;		// 40
	BGSTextureSet			* textureSet;	// 4C
	TESModelTri				raceMorph;		// 50
	TESModelTri				morph;			// 64
	TESModelTri				chargenMorph;	// 78
	UInt32					unk8C;          // 8C
	BGSListForm				* validRaces;	// 90
	BSFixedString			partName;		// 94

	bool IsExtraPart() { return (partFlags & kFlagExtraPart) == kFlagExtraPart; }
};
STATIC_ASSERT(sizeof(BGSHeadPart) == 0x98);
