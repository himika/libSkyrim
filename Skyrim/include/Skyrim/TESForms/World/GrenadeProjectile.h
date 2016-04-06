#pragma once

#include "Projectile.h"

/*==============================================================================
class GrenadeProjectile +0000 (_vtbl=010D8654)
0000: class GrenadeProjectile
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
class GrenadeProjectile : public Projectile
{
public:
	enum { kTypeID = (UInt32)FormType::Grenade };

	// @members
	UInt32	unk140;
	UInt32	unk144;
};
STATIC_ASSERT(sizeof(GrenadeProjectile) == 0x148);
