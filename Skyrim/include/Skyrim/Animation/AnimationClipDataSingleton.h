#pragma once

#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSFixedString.h"
#include "../BSCore/BSTHashMap.h"
#include "../BSCore/BSTArray.h"
#include "../BSSystem/BSTSmartPointer.h"


/*==============================================================================
class AnimationClipDataSingleton +0000 (_vtbl=010C8240)
0000: class AnimationClipDataSingleton
0004: |   struct BSTSingletonSDM<class AnimationClipDataSingleton,struct BSTSingletonSDMOpStaticBuffer>
0004: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class AnimationClipDataSingleton,struct BSTSingletonSDMOpStaticBuffer<class AnimationClipDataSingleton> > >
0004: |   |   |   struct BSTSDMTraits<class AnimationClipDataSingleton,struct BSTSingletonSDMOpStaticBuffer<class AnimationClipDataSingleton> >
0005: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class AnimationClipDataSingleton>
==============================================================================*/
class AnimationClipDataSingleton : public BSTSingletonSDM<AnimationClipDataSingleton>
{
public:
	virtual ~AnimationClipDataSingleton();

	// 8
	struct ClipTriggerData
	{
		BSFixedString	name;		// 00
		float			time;		// 04
	};

	// 8 + (numTriggers * 8)
	struct EventData
	{
		float		motionSpeed;	// 00
		UInt16		elementID;		// 04
		UInt16		numTriggers;	// 06

		ClipTriggerData * GetAt(std::size_t idx) const
		{
			ClipTriggerData *triggers = (ClipTriggerData *)(this + 1);
			return &triggers[idx];
		}
	};

	// 14
	struct MovementData
	{
		UInt32		unk00;				// 00 -float ?
		UInt32		numFlames;			// 04
		float		unk08;				// 08
		UInt32		numQuaternions;		// 0C
		float		motionDuration;		// 10
	};

	// 3C
	struct AnimationData : public BSIntrusiveRefCounted
	{
		BSTHashMap<BSFixedString, EventData*>	events;			// 04 - event data
		BSTArray<MovementData>					movements;		// 24 - movement data
		BSTArray<BSFixedString>					hkxFiles;		// 30 - hkx files
	};

	typedef BSTHashMap<BSFixedString, AnimationData*>	AnimationDataMap;


	// @members
	//void						** _vtbl;		// 00 - 010C8240
	//BSTSingletonSDM							// 04
	AnimationDataMap			animMap;		// 08
	BSTArray<UInt32>			unk28;			// 28

private:
	friend struct BSTSingletonSDMBase<BSTSDMTraits<AnimationClipDataSingleton>>;
	DEFINE_MEMBER_FN(ctor, AnimationClipDataSingleton*, 0x00644E50);
};
