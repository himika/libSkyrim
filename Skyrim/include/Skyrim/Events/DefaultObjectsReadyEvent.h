#pragma once

#include "../BSCore/BSTEvent.h"

struct DefaultObjectsReadyEvent
{
	/*
	004F91D9: 01B107B4.AddEventSink(01B331B0)
	class UIBlurManager +0000
	+0000 05 class UIBlurManager | 012B49A0
	+0004 03 struct BSTSingletonSDM<class UIBlurManager,struct BSTSingletonSDMOpStaticBuffer> | 012B49C0
	+0004 02 struct BSTSingletonSDMBase<struct BSTSDMTraits<class UIBlurManager,struct BSTSingletonSDMOpStaticBuffer<class UIBlurManager> > > | 012B4A18
	+0004 00 struct BSTSDMTraits<class UIBlurManager,struct BSTSingletonSDMOpStaticBuffer<class UIBlurManager> > | 012B4A98
	+0005 00 struct BSTSingletonSDMOpStaticBuffer<class UIBlurManager> | 012B4AFC
-->	+0000 00 class BSTEventSink<struct DefaultObjectsReadyEvent::Event> | 01271D7C

	004F91D9: 01B107B4.AddEventSink(01271D04)
	class `anonymous namespace'::DefaultObjectInitListener +0000
	+0000 01 class `anonymous namespace'::DefaultObjectInitListener | 01271E94
-->	+0000 00 class BSTEventSink<struct DefaultObjectsReadyEvent::Event> | 01271D7C
	*/

	struct Event
	{
		bool	b;
	};

	static BSTEventSource<DefaultObjectsReadyEvent::Event> * GetEventSource();

	static inline void AddEventSink(BSTEventSource<DefaultObjectsReadyEvent::Event> *sink)
	{
		typedef void(*Fn)(BSTEventSource<DefaultObjectsReadyEvent::Event> *);
		const Fn fn = (Fn)0x004F91A0;

		fn(sink);
	}

	static inline void RemoveEventSink(BSTEventSource<DefaultObjectsReadyEvent::Event> *sink)
	{
		typedef void(*Fn)(BSTEventSource<DefaultObjectsReadyEvent::Event> *);
		const Fn fn = (Fn)0x004F91E0;

		fn(sink);
	}
};
