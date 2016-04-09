#pragma once

#include "../../../Misc/BGSAttachTechniques.h"
#include "../../../Magic/MagicCaster.h"
#include "../../../Animation/SimpleAnimationGraphManagerHolde.h"
#include "../../../Animation/IPostAnimationChannelUpdateFunctor.h"
#include "../../../Events/ActorEvent.h"
#include "../../../BSCore/BSTEvent.h"

/*==============================================================================
class ActorMagicCaster +0000 (_vtbl=010C8CB4)
0000: class ActorMagicCaster
0000: |   class MagicCaster
0030: |   class SimpleAnimationGraphManagerHolder
0030: |   |   class IAnimationGraphManagerHolder
003C: |   class BSTEventSink<struct BSAnimationGraphEvent>
==============================================================================*/
// 90
class ActorMagicCaster :
	public MagicCaster,							// 00
	public SimpleAnimationGraphManagerHolder,	// 30
	public BSTEventSink<BSAnimationGraphEvent>	// 3C
{
public:
	enum SlotType
	{
		kSlot_LeftHand		= 0,
		kSlot_RightHand		= 1,
		kSlot_Voice			= 4
	};

	ActorMagicCaster(Actor* actor, UInt32 slot) {
		ctor(actor, slot);
	}

	virtual ~ActorMagicCaster();											// 00659AD0

	// @override MagicCaster
	virtual void	MagicCaster_Unk_03(void) override;						// 00658D10
	virtual bool	MagicCaster_Unk_04(void) override;						// 006588D0
	virtual void	MagicCaster_Unk_05(void) override;						// 00658610
	virtual void	MagicCaster_Unk_06(void) override;						// 00659360
	virtual void	MagicCaster_Unk_07(void) override;						// 006571C0 { if (caster) { caster->Unk_006AB9E0(slot, 0); caster->Unk_006E9840(0); } flags &= 0xFFFFFFFC; unk84 = 0; }
	virtual void	MagicCaster_Unk_08(UInt32 arg1) override;				// 00658940
	virtual void	MagicCaster_Unk_09(UInt32 arg1, UInt32 arg2, UInt32 arg3) override;		// 00659B00
	virtual bool	MagicCaster_Unk_0A(UInt32 arg1, UInt32 arg2, float* arg3, UInt32* arg4, UInt32 arg5, UInt32 arg6, UInt32 arg7) override;	// 00657DC0
	virtual Actor *	MagicCaster_Unk_0B(void) override;						// 006572F0 { return caster; }
	virtual Actor *	GetCaster() override;									// 006572F0 { return caster; }
	virtual UInt32	MagicCaster_Unk_0E(void) override;						// 00657510 .... if (eax) unk6C = eax->Unk02; return unk6C;
	virtual void	MagicCaster_Unk_0F(void) override;						// 006574B0 { unk6C = 0; }
	virtual void	MagicCaster_Unk_10(MagicItem *arg) override;			// 00658C40
	virtual void	MagicCaster_Unk_11(void) override;						// 006586F0
	virtual void	MagicCaster_Unk_12(void) override;						// 00657200
	virtual void	MagicCaster_Unk_13(void) override;						// 006571B0 { flags |= 2; }
	virtual void	CalculateMagickaCost(void) override;					// 00657750
	virtual UInt32	GetSlot() override;										// 00657300 { return slot; }
	virtual bool	MagicCaster_Unk_16(void) override;						// 006574E0 { return flag & 1; }
	virtual void	MagicCaster_Unk_17(bool b) override;					// 006574F0 { if (b) { flags |= 1; } else { flags &= ~1; } }
	virtual void	MagicCaster_Unk_18(UInt32 arg1) override;				// 00657240
	virtual void	MagicCaster_Unk_19(UInt32 arg1) override;				// 00657990
	virtual void	MagicCaster_Unk_1A(UInt32 arg1) override;				// 00657A80
	virtual void	MagicCaster_Unk_1B(UInt32 arg1, UInt32 arg2) override;	// 00657AE0
	virtual void	MagicCaster_Unk_1C(UInt32 arg1, UInt32 arg2, UInt32 arg3) override;		// 00657900

	// @override BSTEventSink<BSAnimationGraphEvent>
	virtual	EventResult	ReceiveEvent(BSAnimationGraphEvent * evn, BSTEventSource<BSAnimationGraphEvent> * source) override;	// 006590C0

	// @add
	virtual void	ActorMagicCaster_Unk_1D(void);							// 00659680

	// @members
	//void						** _vtbl;					// 00 - 0x010C8CB4
	RefAttachTechniqueInput		refAttachTechniqueInput;	// 40
	UInt32						unk64;						// 64 - 0
	Actor						* caster;					// 68
	UInt32						pad6C[(0x88 - 0x6C) >> 2];	// 6C
	UInt32						slot;						// 88 - 0:left hand 1:right hand 4:voice
	UInt32						flags;						// 8C

	DEFINE_MEMBER_FN(CastStart, bool, 0x00662430, MagicItem *, UInt32, UInt32);
	DEFINE_MEMBER_FN(CastRelease, bool, 0x00662120, UInt32, UInt32)
	DEFINE_MEMBER_FN(UsePower, bool, 0x006622D0, MagicItem *, UInt32, UInt32, UInt32);

private:
	DEFINE_MEMBER_FN(ctor, ActorMagicCaster *, 0x00657420, Actor * caster, UInt32 slot);
};
STATIC_ASSERT(sizeof(ActorMagicCaster) == 0x90);


