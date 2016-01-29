#pragma once

#include "TESForm.h"
#include "../BSCore/BSFixedString.h"
/*==============================================================================
class BGSMovementType +0000 (_vtbl=010A3334)
0000: class BGSMovementType
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 50
class BGSMovementType : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::MovementType };

	enum {
		kType_Walk = 0,
		kType_Run,
		kType_Max
	};

	enum
	{
		kDefaultData_Left = 0,
		kDefaultData_Right,
		kDefaultData_Forward,
		kDefaultData_Back,
		kDefaultData_RotateInPlace,
		kDefaultData_Max
	};

	enum
	{
		kAnimChangeThresholds_Direction = 0,
		kAnimChangeThresholds_MovementSpeed,
		kAnimChangeThresholds_RotationSpeed,
		kAnimChangeThresholds_Max
	};

	BSFixedString		typeId;									// 14
	float				data[kDefaultData_Max][kType_Max];		// 18
	float				rotateWhileMoving;						// 40 - init'd to pi
	float				thresholds[kAnimChangeThresholds_Max];	// 44 - read from INAM chunk
};
STATIC_ASSERT(sizeof(BGSMovementType) == 0x50);
