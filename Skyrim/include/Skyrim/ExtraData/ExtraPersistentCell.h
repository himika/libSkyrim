#pragma once

#include "BSExtraData.h"

class TESObjectCELL;

class ExtraPersistentCell : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::PersistentCell };

	ExtraPersistentCell();
	virtual ~ExtraPersistentCell();

	TESObjectCELL* cell;
};
