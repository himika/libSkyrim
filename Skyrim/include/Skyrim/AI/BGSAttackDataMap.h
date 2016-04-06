#pragma once

#include "../NetImmerse/NiSmartPointer.h"
#include "../NetImmerse/NiRefObject.h"
#include "../BSCore/BSTHashMap.h"
#include "../AI/BGSAttackData.h"

class TESRace;
class TESFile;

NiSmartPointer(BGSAttackDataMap)

/*==============================================================================
class BGSAttackDataMap +0000 (_vtbl=010C013C)
0000: class BGSAttackDataMap
0000: |   class NiRefObject
==============================================================================*/
// 2C
class BGSAttackDataMap : public NiRefObject
{
public:
	typedef BSTHashMap<BSFixedString, BGSAttackDataPtr> HashMap;

	BGSAttackData * Get(const BSFixedString & eventName);
	BGSAttackData * Add(const BSFixedString & eventName);
	BGSAttackData * Add(BGSAttackData *attackData);
	void Remove(const BSFixedString &eventName);

	static HashMap::iterator begin(HashMap &a_map) {
		return a_map.begin();
	}

	// @members
	//void	** _vtbl		// 00 - 010C013C
	HashMap	map;			// 08
	TESRace	* attackRace;	// 28 - init'd 0

	DEFINE_MEMBER_FN(AddFromMod, void, 0x005B1AE0, TESRace *race, TESFile *mod)

private:
	BGSAttackDataMap() {
		ctor();
	}

	DEFINE_MEMBER_FN(ctor, BGSAttackDataMap*, 0x005B1F70)
};
STATIC_ASSERT(sizeof(BGSAttackDataMap) == 0x2C);
