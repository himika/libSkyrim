#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraCellSkyRegion +0000 (_vtbl=010795C8)
0000: class ExtraCellSkyRegion
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraCellSkyRegion : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::CellSkyRegion };

	// @override
	virtual UInt32	GetType(void) const override;				// 00667E20 { return 0x00000008; }
	virtual bool	IsNotEqual(const BSExtraData *rhs) const;	// 00421230 { return unk08 != rhs->unk08; }

	// @members
	UInt32	unk08;			// 08
};
