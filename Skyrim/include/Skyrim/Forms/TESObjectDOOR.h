#pragma once

#include "TESBoundAnimObject.h"
#include "TESBoundAnimObject.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESModelTextureSwap.h"
#include "../FormComponents/BGSDestructibleObjectForm.h"
#include "../FormComponents/BGSOpenCloseForm.h"
#include "../BSCore/BSTArray.h"


/*==============================================================================
class TESObjectDOOR +0000 (_vtbl=010850B4)
0000: class TESObjectDOOR
0000: |   class TESBoundAnimObject
0000: |   |   class TESBoundObject
0000: |   |   |   class TESObject
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
0020: |   class TESFullName
0020: |   |   class BaseFormComponent
0028: |   class TESModelTextureSwap
0028: |   |   class TESModel
0028: |   |   |   class BaseFormComponent
0050: |   class TESMagicCasterForm
0051: |   class TESMagicTargetForm
0044: |   class BGSDestructibleObjectForm
0044: |   |   class BaseFormComponent
004C: |   class BGSOpenCloseForm
==============================================================================*/
// 70
class TESObjectDOOR : public TESBoundAnimObject,
	public TESFullName,					// 20
	public TESModelTextureSwap,			// 28
	public BGSDestructibleObjectForm,	// 44
	public BGSOpenCloseForm				// 4C
{
public:
	enum { kTypeID = (UInt32)FormType::Door };

	// @members
	UInt32	unk50;		// 50
	UInt32	unk54;		// 54
	UInt32	unk58;		// 58
	UInt32	unk5C;		// 5C
	UInt8	unk60;		// 60
	UInt8	pad61[3];	// 61
	BSTArray<void*>	unk64;
};
