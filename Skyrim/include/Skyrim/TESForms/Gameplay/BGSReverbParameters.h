#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/BSIReverbType.h"

/*==============================================================================
class BGSReverbParameters +0000 (_vtbl=0108DD7C)
0000: class BGSReverbParameters
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class BSIReverbType
==============================================================================*/
// 28
class BGSReverbParameters : public TESForm,
	public BSIReverbType		// 14
{
public:
	enum { kTypeID = (UInt32)FormType::ReverbParam };

	// @members
	UInt16	unk18;	// 18 - init'd to 1250
	UInt16	unk1A;	// 1A - init'd to 800
	UInt8	unk1C;	// 1C - init'd to 100
	UInt8	unk1D;	// 1D - init'd to 100
	UInt8	unk1E;	// 1E - init'd to 0
	UInt8	unk1F;	// 1F - init'd to 0
	UInt8	unk20;	// 20 - init'd to 100
	UInt8	unk21;	// 21 - init'd to 0
	UInt8	unk22;	// 22 - init'd to 0
	UInt8	unk23;	// 23 - init'd to 100
	UInt32	unk24;	// 24 - ???
};
STATIC_ASSERT(sizeof(BGSReverbParameters) == 0x28);
