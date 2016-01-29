#pragma once

#include "BSExtraData.h"
#include "../BSCore/BSTArray.h"

class BGSKeyword;

/*==============================================================================
class ExtraLinkedRef +0000 (_vtbl=01079AF8)
0000: class ExtraLinkedRef
0000: |   class BSExtraData
==============================================================================*/
class ExtraLinkedRef : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::LinkedRef };

	ExtraLinkedRef();
	virtual ~ExtraLinkedRef();

	static ExtraLinkedRef* Create();

	struct Pair
	{
		BGSKeyword	* keyword;
		UInt32		  unk04;
	};

	// @members
	BSTSmallArray<Pair> pairs;
};
