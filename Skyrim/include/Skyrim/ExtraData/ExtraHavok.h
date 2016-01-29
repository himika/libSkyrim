#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraHavok +0000 (_vtbl=01078FC4)
0000: class ExtraHavok
0000: |   class BSExtraData
==============================================================================*/
// 10
class ExtraHavok : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Havok };

	virtual ~ExtraHavok();							// 0040A3A0

	// @override
	virtual UInt32	GetType(void) const override;	// 00CAC8A0 { return 0x00000001; }

private:
	// @members
	void	* unk08;	// init'd arg1
	UInt32	unk0C;		// init'd 0

	DEFINE_MEMBER_FN(ctor, ExtraHavok*, 0x0040A360, void* arg1);
};
