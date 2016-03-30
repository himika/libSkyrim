#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraCellMusicType +0000 (_vtbl=010795A8)
0000: class ExtraCellMusicType
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraCellMusicType : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::CellMusicType };

	// @override
	virtual UInt32	GetType(void) const override;				// 005C5580 { return 0x00000007; }
	virtual bool	IsNotEqual(const BSExtraData *rhs) const;	// 00421230 { return unk08 != rhs->unk08; }

	// @members
	UInt32	unk08;			// 08
};
