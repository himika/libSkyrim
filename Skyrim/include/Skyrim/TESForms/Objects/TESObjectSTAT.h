#pragma once

#include "TESBoundObject.h"
#include "../../FormComponents/TESModelTextureSwap.h"

/*==============================================================================
class TESObjectSTAT +0000 (_vtbl=010855BC)
0000: class TESObjectSTAT
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESModelTextureSwap
0020: |   |   class TESModel
0020: |   |   |   class BaseFormComponent
==============================================================================*/
// 44
class TESObjectSTAT : public TESBoundObject,
	public TESModelTextureSwap			// 20
{
public:
	enum { kTypeID = (UInt32)FormType::Static };

	// @members
	// 8
	struct Data3C
	{
		float	unk0;
		UInt32	unk4;
	};

	// @members
	Data3C	unk3C;	// 3C
};
STATIC_ASSERT(sizeof(TESObjectSTAT) == 0x44);
