#include "Skyrim/Misc/InventoryChanges.h"


InventoryEntryData::InventoryEntryData(TESForm *item, SInt32 count)		// 004750C0
{
	baseForm = item;
	//extraList = new BSSimpleList<BaseExtraList *>;
	extraList = nullptr;
	countDelta = count;
}

InventoryEntryData::~InventoryEntryData()
{
	if (extraList)
	{
		delete extraList;
	}
}

void InventoryEntryData::AddEntryList(BaseExtraList *extra)
{
	if (!extra)
		return;

	if (!extraList)
		extraList = new BSSimpleList<BaseExtraList *>;
	if (extraList)
		extraList->push_back(extra);
}


InventoryEntryData * InventoryChanges::FindEntry(TESForm *item) const
{
	if (entryList)
	{
		for (InventoryEntryData *entry : *entryList)
		{
			if (entry->baseForm == item)
				return entry;
		}
	}

	return nullptr;
}
