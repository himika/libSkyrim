#pragma once

#include "Projectile.h"

/*==============================================================================
class FlameProjectile +0000 (_vtbl=010D82CC)
0000: class FlameProjectile
0000: |   class Projectile
0000: |   |   class TESObjectREFR
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0014: |   |   |   class BSHandleRefObject
0014: |   |   |   |   class NiRefObject
001C: |   |   |   class BSTEventSink<struct BSAnimationGraphEvent>
0020: |   |   |   class IAnimationGraphManagerHolder
==============================================================================*/
// 148
class FlameProjectile : public Projectile
{
public:
	enum { kTypeID = (UInt32)FormType::FlameProj };

	// @members
	UInt32	unk140;
	UInt32	unk144;
};
STATIC_ASSERT(sizeof(FlameProjectile) == 0x148);
