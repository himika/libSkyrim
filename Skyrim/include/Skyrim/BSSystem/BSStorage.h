#pragma once

// c:_skyrim\code\tesv\bssystem\BSStorage.h

#include "../BSSystem/BSTSmartPointer.h"

/*==============================================================================
class BSStorage +0000 (_vtbl=0107CB3C)
0000: class BSStorage
0004: |   struct BSIntrusiveRefCounted
==============================================================================*/
class BSStorage : public BSIntrusiveRefCounted
{
public:
	virtual ~BSStorage() {}						// 00450AA0

	virtual void Unk_01(void) = 0;
	virtual void Unk_02(void) = 0;
	virtual void Unk_03(void) = 0;
	virtual void Unk_04(void) = 0;
	virtual void Unk_05(void) = 0;
};
