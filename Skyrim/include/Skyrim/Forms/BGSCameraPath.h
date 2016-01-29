#pragma once

#include "TESForm.h"

/*==============================================================================
class BGSCameraPath +0000 (_vtbl=0108A25C)
0000: class BGSCameraPath
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 30
class BGSCameraPath : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::CameraPath };

	UInt32	unk14;		// 14
	UInt32	unk18;		// 18
	UInt32	unk1C;		// 1C
	UInt8	unk20;		// 20
	UInt8	pad21[3];	// 21
	UInt32	unk24;		// 24
	UInt32	unk28;		// 28
	UInt32	unk2C;		// 2C
};

