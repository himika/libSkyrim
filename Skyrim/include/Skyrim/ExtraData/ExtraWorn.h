#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraWorn +0000 (_vtbl=010791C8)
0000: class ExtraWorn
0000: |   class BSExtraData
==============================================================================*/
class ExtraWorn : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Worn };

	ExtraWorn();
	virtual ~ExtraWorn();
};
