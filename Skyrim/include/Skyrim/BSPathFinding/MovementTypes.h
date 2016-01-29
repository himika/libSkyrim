#pragma once

#include "MovementParameters.h"

class NiPoint3;

/*==============================================================================
struct IMovementInterface +0000 (_vtbl=010D0AB4)
0000: struct IMovementInterface
==============================================================================*/
// 04
struct IMovementInterface
{
public:
	virtual ~IMovementInterface();		// 0076DC90
};


/*==============================================================================
struct IMovementState +0000 (_vtbl=010CF71C)
0000: struct IMovementState
0000: |   struct IMovementInterface
==============================================================================*/
// 04
struct IMovementState : public IMovementInterface
{
public:
	virtual ~IMovementState();		// 006A6920

	virtual FormID	IMovementState_Unk_01(void) = 0;
	virtual void	IMovementState_Unk_02(UInt32 arg) = 0;
	virtual void	IMovementState_Unk_03(NiPoint3 &pos) = 0;
	virtual void	IMovementState_Unk_04(NiPoint3 &pos) = 0;
	virtual float	IMovementState_Unk_05(void) = 0;
	virtual float	IMovementState_Unk_06(void) = 0;
	virtual void	IMovementState_Unk_07(NiPoint3 &pos) = 0;
	virtual bool	IMovementState_Unk_08(UInt32 arg) = 0;
	virtual float	IMovementState_Unk_09(void) = 0;
	virtual float	IMovementState_Unk_0A(void) = 0;
	virtual float	IMovementState_Unk_0B(void) = 0;
	virtual float	IMovementState_Unk_0C(void) = 0;
	virtual float	IMovementState_Unk_0D(void) = 0;
	virtual bool	IMovementState_Unk_0E(void) = 0;
	virtual MovementParameters *	IMovementState_Unk_0F(void) = 0;		// PlayerCharacter={ return (class MovementParameters *)0x01275B88; }
	virtual bool	IMovementState_Unk_10(UInt32 arg) = 0;
	virtual UInt32	IMovementState_Unk_11(void) = 0;
	virtual bool	IMovementState_Unk_12(void) = 0;
	virtual bool	IMovementState_Unk_13(void) = 0;
};
