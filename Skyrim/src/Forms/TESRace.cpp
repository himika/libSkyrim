#include "Skyrim/Forms/TESRace.h"
#include "Skyrim/FileIO/TESDataHandler.h"


TESRace* TESRace::LookupByEditorID(const BSFixedString& editorId)
{
	TESDataHandler* dhdl = TESDataHandler::GetSingleton();
	if (!dhdl)
		return nullptr;

	for (TESRace *race : dhdl->races)
	{
		if (race->editorId == editorId)
			return race;
	}

	return nullptr;
}
