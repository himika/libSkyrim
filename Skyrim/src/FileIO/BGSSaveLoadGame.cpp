#include "Skyrim/FileIO/BGSSaveLoadGame.h"



bool BGSSaveLoadGame::FormFlagMap::GetAt(FormID formID, FormFlagData &flags)
{
	lock.Lock();
	bool result = map.GetAt(formID, flags);
	lock.Unlock();

	return result;
}

bool BGSSaveLoadGame::FormFlagMap::Exists(FormID formID)
{
	lock.Lock();
	bool result = (map.count(formID) != 0);
	lock.Unlock();

	return result;
}
