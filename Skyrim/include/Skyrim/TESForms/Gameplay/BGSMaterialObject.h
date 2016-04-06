#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/TESModel.h"
#include "../../FormComponents/BSMaterialObject.h"
/*==============================================================================
class BGSMaterialObject +0000 (_vtbl=0108D284)
0000: class BGSMaterialObject
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESModel
0014: |   |   class BaseFormComponent
0028: |   class BSMaterialObject
==============================================================================*/
// 74
class BGSMaterialObject : public TESForm,
	public TESModel,			// 14
	public BSMaterialObject		// 28
{
public:
	enum { kTypeID = (UInt32)FormType::Material };

	// @members
	BSTArray<void *>		unk68;	// 68
};
STATIC_ASSERT(sizeof(BGSMaterialObject) == 0x74);
