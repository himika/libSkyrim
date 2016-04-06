#pragma once

#include "BaseFormComponent.h"
#include "../AI/BGSAttackDataMap.h"

/*==============================================================================
class BGSAttackDataForm +0000 (_vtbl=0107C2E4)
0000: class BGSAttackDataForm
0000: |   class BaseFormComponent
==============================================================================*/
// 08
class BGSAttackDataForm : public BaseFormComponent
{
public:
	// @members
	//void				** _vtbl			// 00 - 0107C2E4
	BGSAttackDataMapPtr	attackDataMap;		// 04

	DEFINE_MEMBER_FN(CreateAttackDataMap, void, 0x004479C0);
	DEFINE_MEMBER_FN(AddFromMod, void, 0x00447AD0, TESRace *race, TESFile *mod);
};
