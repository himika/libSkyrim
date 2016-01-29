#include "Skyrim/FileIO/BGSSaveLoadManager.h"

BGSSaveLoadManager * BGSSaveLoadManager::GetSingleton(void)
{
	return *((BGSSaveLoadManager **)0x01B2E3A8);
}
