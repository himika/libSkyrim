#pragma once

#include "NiBackToFrontAccumulator.h"

/*==============================================================================
class NiAlphaAccumulator +0000 (_vtbl=0111CFCC)
0000: class NiAlphaAccumulator
0000: |   class NiBackToFrontAccumulator
0000: |   |   class NiAccumulator
0000: |   |   |   class NiObject
0000: |   |   |   |   class NiRefObject
==============================================================================*/
// 30
class NiAlphaAccumulator : public NiBackToFrontAccumulator
{
public:
	enum { kRTTI = 0x01B92B08 };

	// @members
	UInt32	unk2C;
};
