#pragma once

#include "BSExtraData.h"
#include "../BSCore/BSTArray.h"

class TESForm;

class ExtraPromotedRef : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::PromotedRef };

	ExtraPromotedRef();
	virtual ~ExtraPromotedRef();

	BSTArray<TESForm*> unk08;
};
