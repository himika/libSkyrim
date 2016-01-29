#include "SKSE/GameEvents.h"
#include <Skyrim/BSResource/BSResourceEntry.h>
#include <Skyrim/BSResource/BSResourceArchive.h>

template <>
BSTEventSource<BSResource::ArchiveStreamOpenedEvent>* SKSEEvent2<BSResource::ArchiveStreamOpenedEvent>::GetEventSource()
{
	BSResource::BSResourceEntry *pSingleton = BSResource::BSResourceEntry::GetSingleton();
	return static_cast<BSTEventSource<BSResource::ArchiveStreamOpenedEvent>*>(pSingleton);
}

template <>
BSTEventSource<BSResource::NameFoundEvent>* SKSEEvent2<BSResource::NameFoundEvent>::GetEventSource()
{
	BSResource::Archive *pSingleton = BSResource::Archive::GetSingleton();
	return static_cast<BSTEventSource<BSResource::NameFoundEvent>*>(pSingleton);
}

template <>
BSTEventSource<BSResource::ArchiveRegisteredEvent>* SKSEEvent2<BSResource::ArchiveRegisteredEvent>::GetEventSource()
{
	BSResource::Archive *pSingleton = BSResource::Archive::GetSingleton();
	return static_cast<BSTEventSource<BSResource::ArchiveRegisteredEvent>*>(pSingleton);
}
