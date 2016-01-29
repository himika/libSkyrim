#pragma once

#include "../BSSystem/BSTSmartPointer.h"

/*==============================================================================
class IMovementParameters +0000 (_vtbl=010C2004)
0000: class IMovementParameters
0004: |   struct BSIntrusiveRefCounted
==============================================================================*/
class IMovementParameters : public BSIntrusiveRefCounted
{
public:
	virtual ~IMovementParameters();			// 00760A60

	virtual void Unk_01(void) = 0;
	virtual void Unk_02(void) = 0;
	virtual void Unk_03(void) = 0;
	virtual void Unk_04(void) = 0;
	virtual void Unk_05(void) = 0;
	virtual void Unk_06(void) = 0;
	virtual void Unk_07(void) = 0;
	virtual void Unk_08(void) = 0;
};


/*==============================================================================
class MovementParameters +0000 (_vtbl=010C202C)
0000: class MovementParameters
0000: |   class IMovementParameters
0004: |   |   struct BSIntrusiveRefCounted
==============================================================================*/
class MovementParameters : public IMovementParameters
{
public:
	virtual void Unk_01(void) override;		// 005B05E0
	virtual void Unk_02(void) override;		// 005C55F0
	virtual void Unk_03(void) override;		// 00EFEBA0
	virtual void Unk_04(void) override;		// 004963E0
	virtual void Unk_05(void) override;		// 004963D0
	virtual void Unk_06(void) override;		// 005C5600
	virtual void Unk_07(void) override;		// 00760A00
	virtual void Unk_08(void) override;		// 005C5630
};
