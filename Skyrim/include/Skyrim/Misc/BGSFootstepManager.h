#pragma once

#include "../BSCore/BSTEvent.h"
#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSTArray.h"
#include "../Events.h"


struct BGSFootstepEvent
{
	RefHandle	actorHandle;
};


class BGSFootstepManager :
	public BSTEventSource<BGSFootstepEvent>,		// 00
	public BSTSingletonSDM<BGSFootstepManager>		// 30
{
public:
	BGSFootstepManager() {}

	BSTArray<UInt32>	unk34;

private:
	friend struct BSTSingletonSDMBase<BSTSDMTraits<BGSFootstepManager>>;
	BGSFootstepManager * ctor();
};
