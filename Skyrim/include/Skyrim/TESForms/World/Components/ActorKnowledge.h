#pragma once

#include "../../../NetImmerse/NiRefObject.h"

class DetectionState;

/*==============================================================================
class ActorKnowledge +0000 (_vtbl=010D536C)
0000: class ActorKnowledge
0000: |   class NiRefObject
==============================================================================*/
// 30
class ActorKnowledge : public NiRefObject
{
public:
	DEFINE_MEMBER_FN(GetDetectionState, DetectionState *, 0x0077D9F0, UInt32 unk);		// unk=3

	// @members
	UInt32			unk08;
	UInt32			unk0C;
	UInt32			unk10;
	float			unk14;	// unknown passed time
	DetectionState	* detectionState;
	UInt32			unk1C;
	UInt32			unk20;
	UInt32			unk24;
	UInt32			unk28;
	float			unk2C;

private:
	DEFINE_MEMBER_FN(ctor, ActorKnowledge *, 0x0077D860);
	DEFINE_MEMBER_FN(ctor2, ActorKnowledge *, 0x0077D930, Actor *me, Actor *target);
};
STATIC_ASSERT(sizeof(ActorKnowledge) == 0x30);
