#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../BSCore/BSTArray.h"


/*==============================================================================
class BGSScene +0000 (_vtbl=010A3C64)
0000: class BGSScene
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 70
class BGSScene : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::Scene };


	TESQuest * GetOwningQuest(void) {
		return questOwner;
	}
	bool IsPlaying(void) const {
		return isPlaying;
	}
	void ForceStart(void);
	void Start(void);
	void Stop(void);

	///<summary>Checks to see if the specified action in this scene is completed.</summary>
	DEFINE_MEMBER_FN_const(IsActionCompleted, bool, 0x00555FA0, UInt32 aiActionID);


	// @members
	BSTArray<void *>	unk14;			// 14
	BSTArray<void *>	unk20;			// 20
	BSTArray<void *>	unk2C;			// 2C
	BSTArray<void *>	unk38;			// 38
	BSTArray<void *>	unk44;			// 44
	TESQuest			* questOwner;	// 50
	UInt32				unk54;			// 54
	void				* unk58;		// 58 - linked list
	bool				isPlaying;		// 5C
	UInt8				unk5D;			// 5D
	UInt8				unk5E;			// 5E
	UInt8				unk5F;			// 5F
	UInt8				unk60;			// 60
	UInt8				unk61;			// 61
	UInt8				unk62;			// 62
	UInt8				unk63;			// 63
	UInt8				unk64;			// 64
	UInt8				pad65[3];		// 65
	UInt32				unk68;			// 68
	UInt32				unk6C;			// 6C

private:
	DEFINE_MEMBER_FN(StartStop_impl, void, 0x008ED1F0, UInt32 bStart);
	DEFINE_MEMBER_FN(ForceStart_impl , void, 0x00558100);
};
STATIC_ASSERT(sizeof(BGSScene) == 0x70);
