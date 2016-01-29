#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraScale +0000 (_vtbl=01079238)
0000: class ExtraScale
0000: |   class BSExtraData
==============================================================================*/
class ExtraScale : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Scale };

	ExtraScale();
	virtual ~ExtraScale();

	float scale;		// 08
};
