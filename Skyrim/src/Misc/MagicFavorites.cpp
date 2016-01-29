#include "Skyrim/Misc/MagicFavorites.h"

#include <algorithm>

void MagicFavorites::ClearHotkey(SInt8 idx)
{
	if (idx < 0 || idx >= hotkeys.size())
		return;

	hotkeys[idx] = nullptr;
}


void MagicFavorites::SetHotkey(TESForm * form, SInt8 idx)
{
	if (form == nullptr)
		return;

	if (idx < 0 || idx >= hotkeys.size())
		return;

	if (hotkeys[idx] == form)
		return;

	if (!IsFavorited(form))
		return;

	//auto it = std::find(hotkeys.begin(), hotkeys.end(), form);
	//if (it != hotkeys.end())
	//	*it = nullptr;

	hotkeys[idx] = form;
}


TESForm * MagicFavorites::GetSpell(SInt8 idx)
{
	TESForm * form = NULL;
	hotkeys.GetAt(idx, form);
	return form;
}

bool MagicFavorites::IsFavorited(TESForm * form)
{
	std::size_t indexOut;
	if (GetSortIndex(spells, form, &indexOut))
		return true;
	else
		return false;
}
