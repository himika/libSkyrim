#pragma once

#include "TESBoundObject.h"

/*==============================================================================
class BGSAcousticSpace +0000 (_vtbl=0108A08C)
0000: class BGSAcousticSpace
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
==============================================================================*/
// 2C
class BGSAcousticSpace : public TESBoundObject
{
public:
	enum { kTypeID = (UInt32)FormType::AcousticSpace };

	TESForm	* loopingSound;	// 20
	TESForm	* soundRegion;	// 24
	TESForm	* reverbType;	// 28
};
STATIC_ASSERT(sizeof(BGSAcousticSpace) == 0x2C);
