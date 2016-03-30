#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraProcessMiddleLow +0000 (_vtbl=01087B60)
0000: class ExtraProcessMiddleLow
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraProcessMiddleLow : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::ProcessMiddleLow };

	// @override
	virtual UInt32	GetType(void) const override;		// 00904A50 { return 0x00000009; }

	// @members
	//void		** _vtbl;			// 00 - 01087B60
	UInt32		numProcessing;		// 08 - init'd 0
};
