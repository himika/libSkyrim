#pragma once

#include "TESForm.h"

/*==============================================================================
class TESLandTexture +0000 (_vtbl=0108795C)
0000: class TESLandTexture
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 2C
class TESLandTexture : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::LandTexture };

	struct Data24
	{
		UInt32	unk0;	// 0
		UInt32	unk4;	// 4
	};

	UInt32	unk14;		// 14
	UInt8	unk18;		// 18
	UInt8	unk19;		// 19
	UInt8	pad1A[2];	// 1A
	UInt32	unk1C;		// 1C
	UInt8	unk20;		// 20
	UInt8	pad21[3];	// 21
	Data24	unk24;		// 24
};
STATIC_ASSERT(sizeof(TESLandTexture) == 0x2C);
