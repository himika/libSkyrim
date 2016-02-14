#pragma once

#include "../../../BSPathFinding/MovementTypes.h"

/*==============================================================================
class ActorState +0000 (_vtbl=010D0ABC)
0000: class ActorState
0000: |   struct IMovementState
0000: |   |   struct IMovementInterface
==============================================================================*/
// 0C
class ActorState : public IMovementState
{
public:
	virtual ~ActorState();											// 006C51E0

	// @override
	virtual FormID	IMovementState_Unk_01(void) override;			// 005EADD0 { return 0; } Actor={ return formID; }
	virtual void	IMovementState_Unk_02(UInt32 arg) override;		// 00588F30 { return; }
	virtual void	IMovementState_Unk_03(NiPoint3 &pos) override;	// 00588F30 { return; }
	virtual void	IMovementState_Unk_04(NiPoint3 &pos) override;	// 00588F30 { return; }
	virtual float	IMovementState_Unk_05(void) override;			// 0066E8A0 { return 0.0f; }
	virtual float	IMovementState_Unk_06(void) override;			// 0066E8A0 { return 0.0f; }
	virtual void	IMovementState_Unk_07(NiPoint3 &pos) override;	// 00588F30 { return; }
	virtual bool	IMovementState_Unk_08(UInt32 arg) override;		// 004091A0 { return false; }

	// @add
	virtual bool	ActorState_Unk_14(UInt32 arg);					// 006C50B0	- called when ChairEnter (arg=3), BedEnter (arg=7) ChairFurnitureExit BedFurnitureExit (arg=0)
	virtual bool	ActorState_Unk_15(UInt32 arg);					// 006F0ED0

	enum {
		kState_Running = 0x40,
		kState_Walking = 0x80,
		kState_Sprinting = 0x100,
		kState_Sneaking = 0x200,
		kState_Swimming = 0x400,
		kState_Sit = (0x0F << 0x0E),
		kState_Flying = (0x07 << 0x12)
	};

	enum {
		kSitState_NotSitting = 0,
		kSitState_WantsToSit = 2,
		kSitState_Sitting = 3,
		kSitState_WantsToStand = 4
	};

	enum {
		kSleepState_NotSleeping = 0,
		kSleepState_WantsToSleep = 2,
		kSleepState_Sleeping = 3,
		kSleepState_WantsToWake = 4
	};

	//struct {
	//	unsigned char	unk0 : 6;				// 00
	//	bool			runnging : 1;			// 06 0x00000040
	//	bool			walking : 1;			// 07 0x00000080
	//	bool			sprinting : 1;			// 08 0x00000100
	//	bool			sneaking : 1;			// 09 0x00000200
	//	bool			swimming : 1;			// 0A 0x00000400
	//	bool			unk0B : 1;				// 0B 0x00000800
	//	bool			unk0C : 1;				// 0C 0x00001000
	//	bool			unk0D : 1;				// 0D 0x00002000
	//	unsigned char	sitSleepState : 4;		// 0E 0x0003C000
	//	unsigned char	flyingState : 3;		// 12 0x001C0000
	//	unsigned char	bleedingState : 4;		// 15 0x01E00000
	//  unsigned char	unk19 : 3;				// 19 0x0E000000
	//  unsigned char	attackState : 4;		// 1C 0xF0000000
	//} flags;

	///<summary>Obtains this actor's sit state.</summary>
	UInt32 GetSitState() const
	{
		UInt32 state = (flags04 >> 0x0E) & 0x0F;
		switch (state)
		{
		case 1:
		case 2:
			return kSitState_WantsToSit;
		case 3:
			return kSitState_Sitting;
		case 4:
			return kSitState_WantsToStand;
		default:
			return kSitState_NotSitting;
		}
	}

	UInt32 GetSleepState() const
	{
		UInt32 state = (flags04 >> 0x0E) & 0x0F;
		switch (state)
		{
		case 5:
		case 6:
			return kSleepState_WantsToSleep;
		case 7:
			return kSleepState_Sleeping;
		case 8:
			return kSleepState_WantsToWake;
		default:
			return kSleepState_NotSleeping;
		}
	}

	///<summary>Obtains this actor's current flying state.</summary>
	UInt32 GetFlyingState() const
	{
		return (flags04 >> 0x12) & 0x07;
	}

	///<summary>Is this actor currently bleeding out?</summary>
	bool IsBleedingOut() const
	{
		UInt32 state = (flags04 >> 0x15) & 0x0F;
		return (state == 7 || state == 8);
	}

	///<summary>Does this actor have his equipped weapon and/or magic spell drawn?</summary>
	bool IsWeaponDrawn() const
	{
		return (flags08 >> 5 & 7) >= 3;
	}

	///<summary>Is this actor currently sneaking?</summary>
	bool IsSneaking() const
	{
		return (flags04 & kState_Sneaking) != 0;
	}

	///<summary>Is this actor currently sprinting?</summary>
	bool IsSwimming() const
	{
		return (flags04 & kState_Swimming) != 0;
	}

	///<summary>Is this actor currently sprinting?</summary>
	bool IsSprinting() const
	{
		return (flags04 & kState_Sprinting) != 0;
	}

	///<summary>Is this actor currently flying?</summary>
	bool IsFlying() const
	{
		UInt32 flyingState = GetFlyingState();
		return (flyingState != 0) && (flyingState != 5);
	}

	///<summary>Is this actor currently unconscious?</summary>
	bool IsUnconscious() const
	{
		return (flags04 & 0x01E00000) == 0x00600000;
	}

//protected:
	// @members
	//void	** _vtbl;	// 00 - 010D0ABC
	UInt32	flags04;
	UInt32	flags08;
};
STATIC_ASSERT(sizeof(ActorState) == 0x0C);
