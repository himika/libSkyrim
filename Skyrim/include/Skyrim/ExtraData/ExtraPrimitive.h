#pragma once

#include "BSExtraData.h"

class BGSPrimitive;

class ExtraPrimitive : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Primitive };

	ExtraPrimitive();
	virtual ~ExtraPrimitive();											// 0040AEB0

	// @override
	virtual UInt32	GetType(void) const override;						// 00401860 { return kExtraTypeID; }
	virtual bool	IsNotEqual(const BSExtraData *rhs) const override;	// 00421230 { return primitive != rhs->unk8; }

	BGSPrimitive	* primitive;
};
