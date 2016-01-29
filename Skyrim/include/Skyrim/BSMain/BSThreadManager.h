#pragma once

#include "../BSCore/BSTEvent.h"

struct BSThreadEvent
{
	struct ThreadEvent
	{
		/*
		00A4BAA6: 01B4AE14.AddEventSink(01B11550)
		class HavokSystem::`anonymous namespace'::HavokThreadMemorySink +0000
		+0000 05 class HavokSystem::`anonymous namespace'::HavokThreadMemorySink | 0125BCD4
-->		+0000 00 class BSTEventSink<struct BSThreadEvent::ThreadEvent> | 0125BB5C
		+0004 03 struct BSTSingletonSDM<class HavokSystem::`anonymous namespace'::HavokThreadMemorySink,struct BSTSingletonSDMOpStaticBuffer> | 0125BD18
		+0004 02 struct BSTSingletonSDMBase<struct BSTSDMTraits<class HavokSystem::`anonymous namespace'::HavokThreadMemorySink,struct BSTSingletonSDMOpStaticBuffer<class HavokSystem::`anonymous namespace'::HavokThreadMemorySink> > > | 0125BD90
		+0004 00 struct BSTSDMTraits<class HavokSystem::`anonymous namespace'::HavokThreadMemorySink,struct BSTSingletonSDMOpStaticBuffer<class HavokSystem::`anonymous namespace'::HavokThreadMemorySink> > | 0125BE50
		+0005 00 struct BSTSingletonSDMOpStaticBuffer<class HavokSystem::`anonymous namespace'::HavokThreadMemorySink> | 0125BEF8
		*/
	};
};


// no rtti
class BSThreadManager : public BSTEventSource<BSThreadEvent::ThreadEvent>
{
public:
	virtual ~BSThreadManager();		// 00A4BB60

	BSThreadManager* GetSingleton()
	{
		((void(*)())0x00A4BB30)();
		return m_pSingleton;
	}

protected:

	static BSThreadManager *& m_pSingleton;
};
