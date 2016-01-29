#pragma once

#include "BSExtraData.h"

class BGSLocationRefType;

/*==============================================================================
class ExtraLocationRefType +0000 (_vtbl=010792D8)
0000: class ExtraLocationRefType
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraLocationRefType : public BSExtraData
{
	CLASS_SIZE_ASSERT(0x0C)

public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::LocationRefType };

	BGSLocationRefType * refType;
};
