#pragma once

#include "BSExtraData.h"

class ExtraFlags : public BSExtraData
{
	enum { kExtraTypeID = (UInt32)ExtraDataType::Flags };

	ExtraFlags();
	virtual ~ExtraFlags();

	UInt32 flags;
};
