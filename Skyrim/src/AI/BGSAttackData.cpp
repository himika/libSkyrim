#include "Skyrim/AI/BGSAttackData.h"


BGSAttackData * BGSAttackData::Create()
{
	BGSAttackData *attackData = FormHeap_Allocate<BGSAttackData>();
	if (attackData)
	{
		attackData->ctor();
	}

	return attackData;
}
