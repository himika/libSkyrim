#pragma once

#include "../BSSystem/BSTSmartPointer.h"

/*==============================================================================
class BSAnimationGraphChannel +0000 (_vtbl=0107E5EC)
0000: class BSAnimationGraphChannel
0004: |   struct BSIntrusiveRefCounted
==============================================================================*/
// 10
class BSAnimationGraphChannel : public BSIntrusiveRefCounted
{
public:
	virtual ~BSAnimationGraphChannel();

	virtual	void	Unk_01(void) = 0;		// pure
	virtual	void	Unk_02(void) = 0;		// pure

	// @members
	//void	** _vtbl;		// 00 - 0107E5EC
	UInt32	unk08;			// 08
	UInt32	unk0C;			// 0C
};
STATIC_ASSERT(sizeof(BSAnimationGraphChannel) == 0x10);
