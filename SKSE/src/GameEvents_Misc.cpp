#include "SKSE/GameEvents.h"

template <>
BSTEventSource<BGSFootstepEvent>* SKSEEvent2<BGSFootstepEvent>::GetEventSource()
{
	return BGSFootstepManager::GetSingleton();
}
