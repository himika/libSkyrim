#pragma once

#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/BGSDestructibleObjectForm.h"
#include "TESObjectSTAT.h"

/*==============================================================================
class BGSMovableStatic +0000 (_vtbl=01081994)
0000: class BGSMovableStatic
0000: |   class TESFullName
0000: |   |   class BaseFormComponent
0008: |   class BGSDestructibleObjectForm
0008: |   |   class BaseFormComponent
0010: |   class TESObjectSTAT
0010: |   |   class TESBoundObject
0010: |   |   |   class TESObject
0010: |   |   |   |   class TESForm
0010: |   |   |   |   |   class BaseFormComponent
0030: |   |   class TESModelTextureSwap
0030: |   |   |   class TESModel
0030: |   |   |   |   class BaseFormComponent
==============================================================================*/
// 5C
// they probably wanted this to derive from TESObjectSTAT first
// doesn't really hurt anything except performance (shims)
class BGSMovableStatic :
	public TESFullName,					// 00
	public BGSDestructibleObjectForm,	// 08
	public TESObjectSTAT				// 10
{
public:
	enum { kTypeID = (UInt32)FormType::MovableStatic };

	// @members
	UInt8	unk54;		// 54
	UInt8	pad55[3];	// 59
};
