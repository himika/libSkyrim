#pragma once

#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSTArray.h"
#include "../BSCore/BSTHashMap.h"
#include "../BSCore/BSSpinLock.h"
#include "../Forms/MagicItem.h"

class TESForm;

class EffectItem;
class EnchantmentItem;
class AlchemyItem;


// 84
class BGSDynamicPersistenceManager : public BSTSingletonSDM<BGSDynamicPersistenceManager>
{
public:
	struct Data
	{
		EnchantmentItem	* enchantment;		// 00
		volatile long	refCount;			// 04
	};


	DEFINE_MEMBER_FN(Unk_00689860, void, 0x00689860, EnchantmentItem * enchantment, bool isWeapon);		// called from 0084EA1A
	DEFINE_MEMBER_FN(CreateWeaponEnchantment, EnchantmentItem *, 0x00689D30, BSTArray<MagicItem::EffectItem> * effectArray);
	DEFINE_MEMBER_FN(CreateArmorEnchantment, EnchantmentItem *, 0x00689D80, BSTArray<MagicItem::EffectItem> * effectArray);
	DEFINE_MEMBER_FN(MakePersistent, void, 0x0068A0F0, EnchantmentItem *);
	DEFINE_MEMBER_FN(ScheduleForDeletion, void, 0x0068A1B0, EnchantmentItem *);
	DEFINE_MEMBER_FN(CreatePotion, void, 0x0068ACB0, AlchemyItem *& resultPotion, BSTArray<MagicItem::EffectItem> * effectArray);
	DEFINE_MEMBER_FN(CreatePoison, void, 0x0068AD00, AlchemyItem *& resultPoison, BSTArray<MagicItem::EffectItem> * effectArray);


	// @members
	//BSTSingletonSDM						singleton;				// 00
	BSTArray<Data>							offensiveEnchants;		// 04
	BSTArray<Data>							defensiveEnchants;		// 10
	BSTHashMap<FormID, TESBoundObject *>	offensiveObjects;		// 1C - weapon and poison
	BSTHashMap<FormID, TESBoundObject *>	defensiveObjects;		// 3C - armor and potion
	BSTHashMap<UInt32, UInt32>				map5C;					// 5C
	BSSpinLock								lock;					// 7C

private:
	friend struct BSTSingletonSDMBase<BSTSDMTraits<BGSDynamicPersistenceManager>>;
	DEFINE_MEMBER_FN(ctor, BGSDynamicPersistenceManager *, 0x0068AA60);
};
STATIC_ASSERT(sizeof(BGSDynamicPersistenceManager) == 0x84);
STATIC_ASSERT(offsetof(BGSDynamicPersistenceManager, weaponEnchants) == 0x04);
