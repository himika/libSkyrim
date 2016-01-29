#pragma once

#include "../../../NetImmerse/NiRefObject.h"

/*==============================================================================
class DetectionState +0000 (_vtbl=010D53A8)
0000: class DetectionState
0000: |   class NiRefObject
==============================================================================*/
// 40
class DetectionState : public NiRefObject
{
public:
	// 10
	struct Data
	{
		float		unk00;				// 10 - init'd FF7FFFFF - unknown passed time
		float		unk04;				// 10 - init'd [01B910A4]
		float		unk08;				// 14 - init'd [01B910A8]
		float		unk0C;				// 18 - init'd [01B910AC]
	};

	// @members
	SInt32		detectionLevel;		// 08 - init'd -1000
	bool		bInSight;			// 0C - init'd 0
	bool		unk0D;				// 0D - init'd 0
	UInt8		unk0E;				// 0E - init'd 0
	Data		unk10;				// 10
	Data		unk20;				// 10
	Data		unk30;				// 10

private:
	DEFINE_MEMBER_FN(ctor, DetectionState, 0x0077EF90);
};
STATIC_ASSERT(offsetof(DetectionState, detectionLevel) == 0x08);
STATIC_ASSERT(sizeof(DetectionState) == 0x40);
