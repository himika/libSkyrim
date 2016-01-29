#include "Skyrim.h"
#include "Skyrim/FileIO/TESDataHandler.h"
#include "Skyrim/FileIO/TESFile.h"


DECLARE_BSTSINGLETONSDM_STATIC_INSTANCE(TESDataHandler, 0x012E2CB8, 0x012E3600);


BSTEventSource<TESDataHandlerPostBuildFileListEvent> *& TESDataHandlerPostBuildFileListEvent::eventSource = *(BSTEventSource<TESDataHandlerPostBuildFileListEvent>**)0x012E567C;


const TESFile * TESDataHandler::LookupModByName(const char * modName)
{
	//return modList.modInfoList.Find(LoadedModFinder(modName));

	for (TESFile *modInfo : modList.modInfoList)
	{
		if (_stricmp(modInfo->name, modName) == 0)
			return modInfo;
	}

	return nullptr;
}


UInt8 TESDataHandler::GetModIndex(const char* modName)
{
	UInt8 index = 0;
	for (TESFile *modInfo : modList.modInfoList)
	{
		if (_stricmp(modInfo->name, modName) == 0)
			return index;
		++index;
	}

	return -1;
}
