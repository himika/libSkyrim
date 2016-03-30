#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraLightData +0000 (_vtbl=010794D8)
0000: class ExtraLightData
0000: |   class BSExtraData
==============================================================================*/
// 1C
class ExtraLightData : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::LightData };

	ExtraLightData();
	virtual ~ExtraLightData();

	// @override
	virtual UInt32	GetType(void) const override;						// 00421220 { return 0x00000091; }
	virtual bool	IsNotEqual(const BSExtraData *rhs) const override;	// 004211A0

	// @members
	float	unk08;		// 08
	UInt32	unk0C;		// 0C
	UInt32	unk10;		// 10
	float	unk14;		// 14 - init'd 1.0
	UInt8	unk18;		// 18
};
