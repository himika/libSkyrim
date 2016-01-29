#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraLinkedRefChildren +0000 (_vtbl=01079B08)
0000: class ExtraLinkedRefChildren
0000: |   class BSExtraData
==============================================================================*/
// 18
class ExtraLinkedRefChildren : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::LinkedRefChildren };

	ExtraLinkedRefChildren();
	virtual ~ExtraLinkedRefChildren();

	static ExtraLinkedRefChildren* Create();

	UInt32 unk08;
	UInt32 unk0C;
	UInt32 unk10;
	UInt32 unk14;
};
