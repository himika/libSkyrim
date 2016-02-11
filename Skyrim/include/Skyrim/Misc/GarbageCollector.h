#pragma once

#include "../BSCore/BSTSingleton.h"
#include "../Events/PositionPlayerEvent.h"

class NiAVObject;
class TESBoundObject;
class BSAnimationGraphManager;


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
	virtual EventResult ReceiveEvent(PositionPlayerEvent *, BSTEventSource<PositionPlayerEvent> *) override;	// 00690540

	inline void Add(NiAVObject *pObj)				{ AddNiAVObject(pObj); }
	inline void Add(TESBoundObject *pObj)			{ AddTESBoundObject(pObj); }
	inline void Add(BSAnimationGraphManager *pObj)	{ AddAnimationGraphManager(pObj); }
	inline void ClearTempEffects()					{ ClearTempEffects_Impl (); }

private:
	DEFINE_MEMBER_FN(ctor, GarbageCollector *, 0x006908C0);

	DEFINE_MEMBER_FN(AddTESBoundObject,			void, 0x0068FB00, TESBoundObject *pObj);
	DEFINE_MEMBER_FN(AddAnimationGraphManager,	void, 0x0068FBB0, BSAnimationGraphManager *pObj);
	//DEFINE_MEMBER_FN(AddBipedAnim,			void, 0x0068FC20, BipedAnim *pObj);
	DEFINE_MEMBER_FN(AddNiAVObject,				void, 0x0068FCF0, NiAVObject *pObj);
	//DEFINE_MEMBER_FN(AddNavMesh,				void, 0x0068FD60, NavMeshSmartPtr &pObj);
	//DEFINE_MEMBER_FN(AddQueuedFile,			void, 0x0068FDD0, QueuedFilePtr &pObj);
	//DEFINE_MEMBER_FN(AddCloneReserver,		void, 0x0068FCF0, BSCloneReserverPtr &pObj);
	DEFINE_MEMBER_FN(ClearTempEffects_Impl,		void, 0x0068FEB0);
};
