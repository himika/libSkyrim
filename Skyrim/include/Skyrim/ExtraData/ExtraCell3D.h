#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraCell3D +0000 (_vtbl=010797F0)
0000: class ExtraCell3D
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraCell3D : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Cell3D };

	virtual ~ExtraCell3D();										// 00423AB0

	// @override
	virtual UInt32	GetType(void) const override;				// 005C8DE0 { return 0x00000002; }

	// @members
	void	* unk08;		// 08 - NiRefObject ?
};
