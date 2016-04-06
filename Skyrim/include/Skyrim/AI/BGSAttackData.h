#pragma once

#include "../NetImmerse/NiSmartPointer.h"
#include "../NetImmerse/NiRefObject.h"
#include "../BSCore/BSFixedString.h"

NiSmartPointer(BGSAttackData)

class SpellItem;
class BGSKeyword;

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
	DEFINE_MEMBER_FN(ctor, BGSAttackData *, 0x005B1410);	// called from 005B1B61
};
STATIC_ASSERT(sizeof(BGSAttackData) == 0x38);
