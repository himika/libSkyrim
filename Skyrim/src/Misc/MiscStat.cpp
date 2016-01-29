#include "Skyrim/Misc/MiscStats.h"
#include <cstring>

MiscStatManager * MiscStatManager::GetSingleton(void)
{
	return (MiscStatManager *)0x012E6C34;
}

MiscStatManager::MiscStat * MiscStatManager::Get(const char * name)
{
	for (UInt32 i = 0; i < m_numStats; i++)
	{
		MiscStat	* stat = &m_stats[i];

		if (!_stricmp(name, stat->name))
		{
			return stat;
		}
	}

	return NULL;
}
