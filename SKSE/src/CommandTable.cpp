#include "SKSE/CommandTable.h"
#include "SKSE/DebugLog.h"



CommandInfo * CommandInfo::Create()
{
	CommandInfo *commands = *(CommandInfo**)0x00516B0B;
	const UInt32 maxIdx = *(UInt32*)(0x00516C10 + 6);

	for (int idx = 0x300; idx <= maxIdx; ++idx)
	{
		CommandInfo *p = &commands[idx];

		if (!p->longName || !p->longName[0])
			return p;
	}

	return nullptr;
}
