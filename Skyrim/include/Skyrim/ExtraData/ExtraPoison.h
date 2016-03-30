#pragma once

#include "BSExtraData.h"

class AlchemyItem;

/*==============================================================================
class ExtraPoison +0000 (_vtbl=01079308)
0000: class ExtraPoison
0000: |   class BSExtraData
==============================================================================*/
// 10
class ExtraPoison : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Poison };

	ExtraPoison();
	virtual ~ExtraPoison();		// 0040AE20

	// @override
	virtual UInt32	GetType(void) const override;						// 00420F70 { return 0x0000003E; }
	virtual bool	IsNotEqual(const BSExtraData *rhs) const override;	// 00420F40 { return (unk08 != rhs->unk08) && (poison != rhs->poison); }


	// @members
	UInt32			unk08;		// 08
	AlchemyItem *	poison;		// 0C
};
