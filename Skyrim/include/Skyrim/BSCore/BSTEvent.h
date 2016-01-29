#pragma once

// c:_skyrim\code\tesv\bscore\BSTEvent.h

#include "BSSpinLock.h"
#include "BSTArray.h"

template <class T> class BSTEventSink;

enum EventResult
{
	kEvent_Continue = 0,
	kEvent_Abort
};

// 30
template <class EventT>
class BSTEventSource
{
	CLASS_SIZE_ASSERT(0x30);

public:
	typedef BSTEventSink<EventT> SinkT;

	BSTEventSource()							{ }

	void AddEventSink(SinkT * eventSink)		{ AddEventSink_Internal(eventSink); }
	void RemoveEventSink(SinkT * eventSink)		{ RemoveEventSink_Internal(eventSink); }
	void SendEvent(EventT * evn)				{ SendEvent_Internal(evn); }

	void operator()(EventT * evn)				{ SendEvent_Internal(evn); }

private:
	DEFINE_MEMBER_FN(ctor, BSTEventSource*, 0x0073E790);
	DEFINE_MEMBER_FN(dtor, BSTEventSource*, 0x00695990);
	DEFINE_MEMBER_FN(AddEventSink_Internal, void, 0x006E3E30, SinkT * eventSink);
	DEFINE_MEMBER_FN(RemoveEventSink_Internal, void, 0x008CE0C0, SinkT * eventSink);
	DEFINE_MEMBER_FN(SendEvent_Internal, void, 0x006EBC10, EventT * evn);

	// members
	BSSpinLock			lock;				// 000
	BSTArray<SinkT *>	eventSinks;			// 008
	BSTArray<SinkT *>	addBuffer;			// 014 - schedule for add
	BSTArray<SinkT *>	removeBuffer;		// 020 - schedule for remove
	bool				stateFlag;			// 02C - some internal state changed while sending
};

// 04
template <class EventT>
class BSTEventSink
{
public:
	virtual ~BSTEventSink() {}
	virtual	EventResult	ReceiveEvent(EventT * evn, BSTEventSource<EventT> * source) = 0; // pure

	//void	** _vtbl;	// 00
};
