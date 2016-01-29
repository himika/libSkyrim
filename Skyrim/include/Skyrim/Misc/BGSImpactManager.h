#pragma once

#include "../BSCore/BSTEvent.h"
#include "../BSCore/BSTSingleton.h"
#include "BGSFootstepManager.h"
#include "BGSCombatImpactManager.h"
#include "BGSCollisionSoundManager.h"

/*==============================================================================
class BGSImpactManager +0000 (_vtbl=010CE110)
0000: class BGSImpactManager
0000: |   class BSTEventSink<struct BGSFootstepEvent>
0004: |   class BSTEventSink<struct BGSCombatImpactEvent>
0008: |   class BSTEventSink<struct BGSCollisionSoundEvent>
000C: |   struct BSTSingletonSDM<class BGSImpactManager,struct BSTSingletonSDMOpStaticBuffer>
000C: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class BGSImpactManager,struct BSTSingletonSDMOpStaticBuffer<class BGSImpactManager> > >
000C: |   |   |   struct BSTSDMTraits<class BGSImpactManager,struct BSTSingletonSDMOpStaticBuffer<class BGSImpactManager> >
000D: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class BGSImpactManager>
==============================================================================*/
class BGSImpactManager :
	public BSTEventSink<BGSFootstepEvent>,			// 00
	public BSTEventSink<BGSCombatImpactEvent>,		// 04
	public BSTEventSink<BGSCollisionSoundEvent>,	// 08
	public BSTSingletonSDM<BGSImpactManager>		// 0C
{
private:
	DEFINE_MEMBER_FN(ctor, BGSImpactManager*, 0x00698560);
};
