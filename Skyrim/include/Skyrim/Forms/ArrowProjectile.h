#pragma once

#include "MissileProjectile.h"

/*==============================================================================
class ArrowProjectile +0000 (_vtbl=010D702C)
0000: class ArrowProjectile
0000: |   class MissileProjectile
0000: |   |   class Projectile
0000: |   |   |   class TESObjectREFR
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
0014: |   |   |   |   class BSHandleRefObject
0014: |   |   |   |   |   class NiRefObject
001C: |   |   |   |   class BSTEventSink<struct BSAnimationGraphEvent>
0020: |   |   |   |   class IAnimationGraphManagerHolder
==============================================================================*/
// 150
class ArrowProjectile : public MissileProjectile
{
public:
	enum { kTypeID = (UInt32)FormType::Arrow };

	UInt32	unk148;
	UInt32	unk14C;
};
STATIC_ASSERT(sizeof(ArrowProjectile) == 0x150);
