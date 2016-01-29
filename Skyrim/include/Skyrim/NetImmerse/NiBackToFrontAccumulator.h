#pragma once

#include "NiAccumulator.h"

/*==============================================================================
class NiBackToFrontAccumulator +0000 (_vtbl=0111D1FC)
0000: class NiBackToFrontAccumulator
0000: |   class NiAccumulator
0000: |   |   class NiObject
0000: |   |   |   class NiRefObject
==============================================================================*/
// 2C
class NiBackToFrontAccumulator : public NiAccumulator
{
public:
	enum { kRTTI = 0x01B92B4C };

	virtual void	Unk_25(void);	// 25 00AEC840

	// @members
	UInt32	unk0C;		// 0C - init'd 0
	UInt32	unk10;		// 10 - init'd 0
	UInt32	unk14;		// 14 - init'd 0
	UInt32	unk18;		// 18 - init'd 0
	UInt32	unk1C;		// 1C - init'd 0
	UInt32	unk20;		// 20 - init'd 0
	UInt32	unk24;		// 24 - init'd 0
	UInt32	unk28;		// 28 - init'd 0

private:
	DEFINE_MEMBER_FN(ctor, NiBackToFrontAccumulator*, 0x00AECAB0);
};
