#pragma once

#include "TESForm.h"
#include "../FormComponents/TESModel.h"
#include "../FormComponents/TESImageSpaceModifiableForm.h"

/*==============================================================================
class BGSCameraShot +0000 (_vtbl=0108A494)
0000: class BGSCameraShot
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESModel
0014: |   |   class BaseFormComponent
0028: |   class TESImageSpaceModifiableForm
0028: |   |   class BaseFormComponent
==============================================================================*/
// 74
class BGSCameraShot : public TESForm,
	public TESModel,							// 14
	public TESImageSpaceModifiableForm			// 28
{
public:
	enum { kTypeID = (UInt32)FormType::CameraShot };

	// @members
	UInt32	unk30;		// 30
	UInt32	unk34;		// 34
	UInt32	unk38;		// 38
	UInt32	unk3C;		// 3C
	UInt32	unk40;		// 40
	UInt32	unk44;		// 44
	float	globalTimeMultiplier;	// 48
	UInt32	unk4C;		// 4C
	UInt32	unk50;		// 50
	UInt32	unk54;		// 54

	UInt32	unk58;		// 58
	UInt32	unk5C;		// 5C
	UInt32	unk60;		// 60
	UInt32	unk64;		// 64
	UInt32	unk68;		// 68
	UInt8	unk6C;		// 6C
	UInt8	pad6D[3];	// 6D
	UInt32	unk70;		// 70
};
STATIC_ASSERT(sizeof(BGSCameraShot) == 0x74);
