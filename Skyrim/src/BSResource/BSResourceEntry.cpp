#include "Skyrim/BSResource/BSResourceEntry.h"

#include <new>


namespace BSResource
{
	BSResourceEntry* BSResourceEntry::GetSingleton()
	{
		BSResourceEntry *pInstance = (BSResourceEntry*)0x01B410B8;
		UInt8 &bInit = *(UInt8*)(pInstance + 1);
		if (bInit & 1) {
			new(pInstance)BSResourceEntry();
			bInit |= 1;
		}
		return pInstance;
	}
}
