#pragma once

#include "BSExtraData.h"

class ExtraLock : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Lock };

	explicit ExtraLock(UInt32 arg1) : unk08(arg1) {}
	virtual ~ExtraLock();				// 0040AD40

	// @override
	virtual UInt32	GetType(void) const override;								// 009C36A0 { reuturn kExtraTypeID; }
	virtual bool	IsNotEqual(const BSExtraData *rhs) const override;	// 00420B00
	
	//DEFINE_MEMBER_FN(ctor, ExtraLock*, 0x00422460, UInt32 arg1);	{ unk08 = arg1; }

	// @members
	//void	** _vtbl	// 00 - 01079148
	UInt32	unk08;
};
