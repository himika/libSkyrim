#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraWornLeft +0000 (_vtbl=010791D8)
0000: class ExtraWornLeft
0000: |   class BSExtraData
==============================================================================*/
class ExtraWornLeft : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::WornLeft };

	ExtraWornLeft();
	virtual ~ExtraWornLeft();
};
