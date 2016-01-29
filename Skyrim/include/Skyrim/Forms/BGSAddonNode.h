#pragma once

#include "TESBoundObject.h"
#include "../FormComponents/TESModelTextureSwap.h"

/*==============================================================================
class BGSAddonNode +0000 (_vtbl=01080A04)
0000: class BGSAddonNode
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESModelTextureSwap
0020: |   |   class TESModel
0020: |   |   |   class BaseFormComponent
==============================================================================*/
// 4C
class BGSAddonNode : public TESBoundObject,
	public TESModelTextureSwap		// 20
{
public:
	enum { kTypeID = (UInt32)FormType::AddonNode };

	// @members
	UInt32	unk3C;		// 3C
	UInt32	unk40;		// 40
	UInt8	unk44[4];	// 44
	UInt32	unk48;		// 48
};
STATIC_ASSERT(sizeof(BGSAddonNode) == 0x4C);
