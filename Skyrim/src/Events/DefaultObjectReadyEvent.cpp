#include "Skyrim/Events/DefaultObjectsReadyEvent.h"
#include <new>


BSTEventSource<DefaultObjectsReadyEvent::Event>* DefaultObjectsReadyEvent::GetEventSource()
{
	typedef BSTEventSource<DefaultObjectsReadyEvent::Event> EventSource;

	EventSource *instance = (EventSource*)0x01B107B4;
	UInt8 &bInit = *(UInt8*)(instance + 1);
	if (bInit & 1) {
		bInit |= 1;
		new(instance)EventSource;
	}
	return instance;
}
