#pragma once

#include "TESBoundObject.h"
#include "../FormComponents/TESModelTextureSwap.h"

/*==============================================================================
class BGSArtObject +0000 (_vtbl=01080E7C)
0000: class BGSArtObject
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESModelTextureSwap
0020: |   |   class TESModel
0020: |   |   |   class BaseFormComponent
==============================================================================*/
// 40
class BGSArtObject : public TESBoundObject,
	public TESModelTextureSwap		// 20
{
public:
	enum { kTypeID = (UInt32)FormType::Art };

	// @members
	UInt32	unk3C;	// 3C
};
STATIC_ASSERT(sizeof(BGSArtObject) == 0x40);
