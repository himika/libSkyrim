#pragma once

#include "BSExtraData.h"

class ExtraSoul : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Soul };

	ExtraSoul();
	virtual ~ExtraSoul();

	UInt32 count;

	static ExtraSoul* Create();
};
