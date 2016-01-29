#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

class ExtraEnableStateParent : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::EnableStateParent };

	ExtraEnableStateParent();
	virtual ~ExtraEnableStateParent();

	UInt32		unk08;	// 08
	RefHandle	handle;	// 0C handle?

	TESObjectREFR * GetReference();
};
