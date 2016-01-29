#pragma once

#include "BaseFormComponent.h"
#include "../BSSystem/BSTSmartPointer.h"
#include "../NetImmerse/NiSmartPointer.h"
#include "../NetImmerse/NiRefObject.h"
#include "../BSCore/BSFixedString.h"
#include "../BSCore/BSTHashMap.h"
#include "../Memory.h"

class BGSKeyword;
class SpellItem;
class TESRace;
class TESFile;

NiSmartPointer(BGSAttackData)
NiSmartPointer(BGSAttackDataMap)

/*==============================================================================
class BGSAttackData +0000 (_vtbl=010C0130)
0000: class BGSAttackData
0000: |   class NiRefObject
==============================================================================*/
// 38
class BGSAttackData : public NiRefObject
{
public:
	static BGSAttackData * Create();

	// @members
	//void			** _vtbl			// 00 - 010C0130
	BSFixedString	eventName;			// 08
	float			damageMult;			// 0C init'd 1.0f
	float			attackChance;		// 10 init'd 1.0f
	SpellItem		* attackSpell;		// 14 init'd 0
	struct
	{
		bool	ignoreWeapon	: 1;
		bool	bashAttack		: 1;
		bool	powerAttack		: 1;
		bool	leftAttack		: 1;
		bool	rotatingAttack	: 1;
	} flags;							// 18
	float			attackAngle;		// 1C init'd 0
	float			strikeAngle;		// 20 init'd [01B14FB8]
	float			stagger;			// 24 init'd 0	
	BGSKeyword		* attackType;		// 28 init'd 0
	float			knockdown;			// 2C init'd 0
	float			recoveryTime;		// 30 init'd 0
	float			staminaMult;		// 34 init'd 1.0f

private:
	BGSAttackData() {
		ctor();
	}
	DEFINE_MEMBER_FN(ctor, BGSAttackData*, 0x005B1410);	// called from 005B1B61
};
STATIC_ASSERT(sizeof(BGSAttackData) == 0x38);


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

	DEFINE_MEMBER_FN(CreateAttackDataMap, void, 0x004479C0)
	DEFINE_MEMBER_FN(AddFromMod, void, 0x00447AD0, TESRace *race, TESFile *mod)
};
