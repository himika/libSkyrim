#pragma once

#include "BSExtraData.h"
#include "../Magic/MagicCaster.h"

/*==============================================================================
class ExtraMagicCaster +0000 (_vtbl=????????)
0000: class ExtraMagicCaster
0000: |   class BSExtraData
0008: |   class MagicCaster
==============================================================================*/
class ExtraMagicCaster : public BSExtraData,
	public MagicCaster			// 08
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::MagicCaster };

	// @override class BSExtraData : (vtbl=010C9A44)
	virtual UInt32	GetType(void) const override;					// 00421C00 { return kExtraTypeID; }
};
