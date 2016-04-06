#pragma once

#include "Actor.h"

NiSmartPointer(Character);

/*==============================================================================
class Character +0000 (_vtbl=010D16D4)
0000: class Character
0000: |   class Actor
0000: |   |   class TESObjectREFR
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0014: |   |   |   class BSHandleRefObject
0014: |   |   |   |   class NiRefObject
001C: |   |   |   class BSTEventSink<struct BSAnimationGraphEvent>
0020: |   |   |   class IAnimationGraphManagerHolder
0054: |   |   class MagicTarget
0060: |   |   class ActorValueOwner
0064: |   |   class ActorState
0064: |   |   |   struct IMovementState
0064: |   |   |   |   struct IMovementInterface
0070: |   |   class BSTEventSink<class BSTransformDeltaEvent>
0074: |   |   class BSTEventSink<class bhkCharacterMoveFinishEvent>
0078: |   |   class IPostAnimationChannelUpdateFunctor
==============================================================================*/
// 19C
class Character : public Actor
{
public:
	enum { kTypeID = (UInt32)FormType::Character };

	// @override class Actor : (vtbl=010D16D4)
	//virtual ????   Unk_00E(????) override;                           // 00730590
	//virtual ????   Unk_00F(????) override;                           // 007305A0
	//virtual ????   Unk_010(????) override;                           // 007305B0
	//virtual ????   Unk_011(????) override;                           // 007305C0
	//virtual ????   Unk_012(????) override;                           // 00730A80
	//virtual ????   Unk_03B(????) override;                           // 00730E10
	//virtual ????   Unk_05E(????) override;                           // 00730AB0
	//virtual ????   Unk_061(????) override;                           // 00731590
	//virtual ????   Unk_063(????) override;                           // 00730AD0
	//virtual void * Unk_07F(void) override;                           // 00730580 { return &unk188; }
	//virtual ????   Unk_081(????) override;                           // 00730E70
	//virtual ????   Unk_0BF(????) override;                           // 00731350
	//virtual ????   Unk_0C3(????) override;                           // 00730690
	//virtual UInt8  Unk_0C4(void) override;                           // 007306A0 { return (UInt8)unk196; }
	//virtual UInt32 Unk_0C5(void) override;                           // 00CAC8A0 { return 0x00000001; }
	//virtual ????   Unk_0C9(????) override;                           // 007304A0
	//virtual ????   Unk_0D6(????) override;                           // 00730BE0
	//virtual ????   Unk_0DB(????) override;                           // 00731000
	//virtual ????   Unk_0E5(????) override;                           // 00731740
	//virtual ????   Unk_0E6(????) override;                           // 00730460
	//virtual ????   Unk_0E7(????) override;                           // 007304C0
	//virtual ????   Unk_11F(????) override;                           // 007317F0

	// @add
	virtual void	Unk_128(void);	// 00730870
	virtual bool	Unk_129(void);	// 009B86F0 (void) { return true; }
};
STATIC_ASSERT(sizeof(Character) == 0x19C);
