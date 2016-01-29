#pragma once

#include "BSAnimationGraphChannel.h"


/*==============================================================================
class BSTAnimationGraphDataChannel<class Actor,float,class ActorCopyGraphVariableChannel> +0000 (_vtbl=0107E5FC)
0000: class BSTAnimationGraphDataChannel<class Actor,float,class ActorCopyGraphVariableChannel>
0000: |   class BSAnimationGraphChannel
0004: |   |   struct BSIntrusiveRefCounted
0010: |   class ActorCopyGraphVariableChannel<class Actor,float>
==============================================================================*/
template <class Ty, class TVal, template <class, class> TChannel>
class BSTAnimationGraphDataChannel :
	public BSAnimationGraphChannel,					// 00
	public TChannel<Ty, TVal>	// 10
{
public:
};


template <class Ty, class TVal>
class ActorCopyGraphVariableChannel
{
};

//ActorSpeedChannel
//ActorTargetSpeedChannel
//ActorRollChannel
//ActorTurnDeltaChannel
//ActorCopyGraphVariableChannel
//ActorWardHealthChannel
//ActorLookAtChannel
//ActorDirectionChannel
//ActorPitchDeltaChannel
//ActorWeaponSpeedChannel
//ActorWantBlockChannel
//ActorLeftWeaponSpeedChannel
//ActorTimeDeltaChannel
