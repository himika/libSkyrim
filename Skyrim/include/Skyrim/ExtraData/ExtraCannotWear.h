#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraCannotWear +0000 (_vtbl=010791E8)
0000: class ExtraCannotWear
0000: |   class BSExtraData
==============================================================================*/
// 08
class ExtraCannotWear : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::CannotWear };

	ExtraCannotWear();
	virtual ~ExtraCannotWear();

	static ExtraCannotWear* Create();
};
STATIC_ASSERT(sizeof(ExtraCannotWear) == 0x08);
