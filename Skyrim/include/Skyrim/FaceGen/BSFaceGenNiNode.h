#pragma once

#include "../NetImmerse/NiNode.h"

class BSFaceGenAnimationData;

/*==============================================================================
class BSFaceGenNiNode +0000 (_vtbl=010BEA8C)
0000: class BSFaceGenNiNode
0000: |   class NiNode
0000: |   |   class NiAVObject
0000: |   |   |   class NiObjectNET
0000: |   |   |   |   class NiObject
0000: |   |   |   |   |   class NiRefObject
==============================================================================*/
// EC
class BSFaceGenNiNode : public NiNode
{
public:
	virtual ~BSFaceGenNiNode();																// 005A8A60

	// @override class NiNode : (vtbl=010BEA8C)
	virtual NiRTTI *	GetRTTI(void) const override;										// 02 005A7E60 { return 0x01B1DF44; }
	virtual NiObject *	CreateClone(NiCloningProcess cloner);								// 13 00AAFC30 { return this; }
	virtual void		UpdateDownwardPass(ControllerUpdateContext * ctx, UInt32 unk1);		// 29 005A8D90

	//// @add
	virtual void		Unk_3C(void);														// 3C 005A88A0

	// @members
	UInt32	unkB8;
	UInt32	unkBC;
	UInt32	unkC0;
	UInt32	unkC4;
	float	unkC8;
	UInt32	unkCC;
	UInt32	unkD0;
	UInt32	unkD4;
	float	unkD8;
	BSFaceGenAnimationData	* animData;
	float	unkE0;
	UInt32	handle;	// handle
	UInt32	unkE8;

	enum {
		kAdjustType_Unk0 = 0,
		kAdjustType_Unk1 = 1,
		kAdjustType_Unk2 = 2,
		kAdjustType_Neck = 3,
	};

	DEFINE_MEMBER_FN(AdjustHeadMorph, void, 0x005A8270, UInt32 unk04, UInt32 unk08, float delta);
};
STATIC_ASSERT(sizeof(BSFaceGenNiNode) == 0xEC);
STATIC_ASSERT(offsetof(BSFaceGenNiNode, animData) == 0xDC);
STATIC_ASSERT(offsetof(BSFaceGenNiNode, handle) == 0xE4);
