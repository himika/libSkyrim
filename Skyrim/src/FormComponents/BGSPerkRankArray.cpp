#include "Skyrim.h"
#include "Skyrim/FormComponents/BGSPerkRankArray.h"

void BGSPerkRankArray::VisitPerkEntry(PerkEntryVisitor &visitor) const
{
	for (UInt32 i = 0; i < numPerkRanks; ++i)
	{
		if (visitor(perkRanks) == false)
			return;
	}
}
