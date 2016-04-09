#pragma once

#include "BSExtraData.h"
#include "../Magic/MagicTarget.h"

class Actor;

/*==============================================================================
class NonActorMagicTarget +0000 (_vtbl=01079834)
0000: class NonActorMagicTarget
0000: |   class BSExtraData
0008: |   class MagicTarget
==============================================================================*/
// 20
class NonActorMagicTarget : public BSExtraData,
	public MagicTarget		// 08
{
	CLASS_SIZE_ASSERT(0x20)

public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::MagicTarget };

	virtual ~NonActorMagicTarget();												// 00414900

	static NonActorMagicTarget* Create();

	// @override MagicTarget
	virtual bool		MagicTarget_Unk_01(void *arg) override;						// 01 00666FD0 { return MagicTarget::MagicTarget_Unk_01(arg) && MagicTarget::Un_00664470(1.0f); }
	virtual Actor *		GetMagicTargetActor(void) const override;					// 02 00E80F90 (void) { return actor; }
	virtual bool		MagicTarget_Unk_06(void) override;							// 06 009B86F0 (void) { return true; }
	virtual BSSimpleList<ActiveEffect*> *	GetActiveEffects(void) override;		// 07 00667000 (void) { return &activeEffects; }

private:
	// @members
	Actor 							* actor;		// 14
	BSSimpleList<ActiveEffect *>	activeEffects;	// 18

private:
	NonActorMagicTarget();
	DEFINE_MEMBER_FN(ctor, NonActorMagicTarget*, 0x0040F450);
};
