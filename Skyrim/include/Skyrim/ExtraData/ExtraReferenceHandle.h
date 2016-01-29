#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

class ExtraReferenceHandle : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::ReferenceHandle };

	ExtraReferenceHandle();
	virtual ~ExtraReferenceHandle();

	RefHandle	handle;		// 08

	TESObjectREFR * GetReference();
	static ExtraReferenceHandle* Create();
};
