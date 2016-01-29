#include "Skyrim.h"
#include "Skyrim/Forms/TESForm.h"
#include "Skyrim/FormComponents/TESContainer.h"

class ItemCounter
{
	UInt32	m_count;
	TESForm	* m_item;

public:
	ItemCounter(TESForm * item) : m_count(0), m_item(item) {}

	bool Accept(TESContainer::Entry * entry)
	{
		if (entry->form == m_item)
			m_count += entry->count;
		return true;
	}

	UInt32 Count() const	{ return m_count; }
};

UInt32 TESContainer::CountItem(TESForm * item) const
{
	ItemCounter v(item);
	Visit(v);
	return v.Count();
}

bool TESContainer::GetContainerLevItemAt(UInt32 idx, TESContainer::Entry *& entry) const
{
	UInt32 n = 0;

	for (UInt32 i = 0; i < numEntries; ++i)
	{
		Entry *p = entries[i];
		if (p->form->Is(FormType::LeveledItem))
		{
			if (n == idx)
			{
				entry = p;
				return true;
			}
			++n;
		}
	}

	return false;
}
