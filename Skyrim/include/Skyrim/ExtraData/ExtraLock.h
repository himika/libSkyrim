#pragma once

#include "BSExtraData.h"

// 14
struct LockState
{
	UInt8	unk00;		// 00 - init'd 0
	UInt32	unk04;		// 04 - init'd 0
	bool	isLocked;	// 08 - init'd 0
	UInt32	unk0C;		// 0C - init'd 0
	UInt32	unk10;		// 10 - init'd 0
};


/*==============================================================================
class ExtraLock +0000 (_vtbl=01079148)
0000: class ExtraLock
0000: |   class BSExtraData
==============================================================================*/

class ExtraLock : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Lock };

	explicit ExtraLock(LockState *a_state) : state(a_state) {}
	virtual ~ExtraLock();												// 0040AD40

	// @override
	virtual UInt32	GetType(void) const override;						// 009C36A0 { reuturn kExtraTypeID; }
	virtual bool	IsNotEqual(const BSExtraData *rhs) const override;	// 00420B00
	
	// @members
	//void		** _vtbl	// 00 - 01079148
	LockState	* state;	// 08

private:
	DEFINE_MEMBER_FN(ctor, ExtraLock *, 0x0040AD00);
	DEFINE_MEMBER_FN(ctor1, ExtraLock *, 0x00422460, LockState *a_state);	// { state = a_state; }
	DEFINE_MEMBER_FN(dtor, void, 0x00422480);
};
