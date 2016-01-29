#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraCellWaterType +0000 (_vtbl=010795E8)
0000: class ExtraCellWaterType
0000: |   class BSExtraData
==============================================================================*/
class ExtraCellWaterType : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::CellWaterType
	};

	virtual ~ExtraCellWaterType();

	// @override
	virtual UInt32	GetType(void) const override;
};
