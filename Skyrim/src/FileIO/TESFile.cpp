#include "Skyrim/FileIO/TESFile.h"
#include "Skyrim/FileIO/TESDataHandler.h"
#include <string.h>

const TESFile * TESFile::LookupByName(const char *name)
{
	TESDataHandler *dhdl = TESDataHandler::GetSingleton();
	return (dhdl) ? dhdl->LookupModByName(name) : nullptr;
}


bool TESFile::HasMaster(const TESFile *master) const
{
	for (std::size_t i = 0; i < this->numRefMods; i++)
	{
		if (this->refModInfo[i] == master)
			return true;
	}
	return false;
}


bool TESFile::HasMaster(const char* masterName) const
{
	const TESFile* master = LookupByName(masterName);
	return (master) && HasMaster(master);
}
