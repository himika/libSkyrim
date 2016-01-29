#include "Skyrim/Forms/BGSOutfit.h"
#include "Skyrim/Forms/TESLevItem.h"


void BGSOutfit::Calcurate(UInt16 level, BSTArray<TESForm*> &result, bool ignoreChanceValue, bool unk) const
{
	result.clear();
	result.reserve(5);

	BSScrapArray<TESLeveledList::CalcuratedResult> calcurated(10);

	for (TESForm *item : armorOrLeveledItemArray)
	{
		if (item->Is(FormType::LeveledItem))
		{
			TESLevItem *levItem = (TESLevItem*)item;
			levItem->Calcurate(level, 1, calcurated, ignoreChanceValue, unk);
		}
		else if (item->Is(FormType::Armor))
		{
			if (result.Find(item) < 0)
				result.Add(item);
		}
	}

	for (auto &node : calcurated)
	{
		if (node.form->IsArmor() && result.Find(node.form) < 0)
			result.Add(node.form);
	}
}
