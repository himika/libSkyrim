#include "Skyrim/AI/BGSAttackDataMap.h"


BGSAttackData * BGSAttackDataMap::Get(const BSFixedString & eventName)
{
	auto iter = map.find(eventName);
	return (iter != map.end()) ? iter->value : nullptr;
}

BGSAttackData * BGSAttackDataMap::Add(const BSFixedString & eventName)
{
	BGSAttackDataPtr ptr = BGSAttackData::Create();
	if (ptr)
	{
		ptr->eventName = eventName;
		map.insert(eventName, ptr);
	}

	return ptr;
}

BGSAttackData * BGSAttackDataMap::Add(BGSAttackData *attackData)
{
	if (attackData)
	{
		BGSAttackDataPtr ptr = attackData;

		map.insert(attackData->eventName, ptr);
	}

	return attackData;
}

void BGSAttackDataMap::Remove(const BSFixedString & eventName)
{
	auto iter = map.find(eventName);
	if (iter != map.end())
	{
		map.erase(eventName);
	}
}
