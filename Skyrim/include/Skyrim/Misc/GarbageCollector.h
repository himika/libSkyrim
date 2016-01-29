#pragma once

#include "../BSCore/BSTSingleton.h"
#include "../Events/PositionPlayerEvent.h"

class NiAVObject;


/*==============================================================================
class GarbageCollector +0000 (_vtbl=010CDCC0)
0000: class GarbageCollector
0004: |   struct BSTSingletonSDM<class GarbageCollector,struct BSTSingletonSDMOpStaticBuffer>
0004: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class GarbageCollector,struct BSTSingletonSDMOpStaticBuffer<class GarbageCollector> > >
0004: |   |   |   struct BSTSDMTraits<class GarbageCollector,struct BSTSingletonSDMOpStaticBuffer<class GarbageCollector> >
0005: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class GarbageCollector>
0000: |   class BSTEventSink<struct PositionPlayerEvent>
==============================================================================*/
class GarbageCollector : public BSTSingletonSDM<GarbageCollector>,
	public BSTEventSink<PositionPlayerEvent>
{
public:
	virtual ~GarbageCollector();		// 00690BD0

	// @override
	virtual EventResult ReceiveEvent(PositionPlayerEvent *, BSTEventSource<PositionPlayerEvent> *) override;

	static GarbageCollector * GetSingleton(void);

	DEFINE_MEMBER_FN(AddNiAVObject, UInt32, 0x0068FCF0, NiAVObject * object);
};
