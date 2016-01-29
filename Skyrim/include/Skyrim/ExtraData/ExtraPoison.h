#pragma once

#include "BSExtraData.h"

class AlchemyItem;

class ExtraPoison : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Poison };

	ExtraPoison();
	virtual ~ExtraPoison();

	UInt32			unk08;		// 08
	AlchemyItem*	poison;		// 0C
};
