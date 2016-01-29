#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraCount +0000 (_vtbl=010791B8)
0000: class ExtraCount
0000: |   class BSExtraData
==============================================================================*/
class ExtraCount : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Count };

	ExtraCount();
	virtual ~ExtraCount();

	SInt16 count;

	static ExtraCount* Create();
};
