#pragma once

#include "Projectile.h"

/*==============================================================================
class BarrierProjectile +0000 (_vtbl=010D749C)
0000: class BarrierProjectile
0000: |   class Projectile
0000: |   |   class TESObjectREFR
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0014: |   |   |   class BSHandleRefObject
0014: |   |   |   |   class NiRefObject
001C: |   |   |   class BSTEventSink<struct BSAnimationGraphEvent>
0020: |   |   |   class IAnimationGraphManagerHolder
==============================================================================*/
// 150
class BarrierProjectile : public Projectile
{
public:
	enum { kTypeID = (UInt32)FormType::BarrierProj };

	UInt32 unk140;
	UInt32 unk144;
	UInt32 unk148;
	UInt32 unk14C;
};
STATIC_ASSERT(sizeof(BarrierProjectile) == 0x150);
