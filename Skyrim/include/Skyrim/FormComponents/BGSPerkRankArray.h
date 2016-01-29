#pragma once

#include "BaseFormComponent.h"

class BGSPerk;
class PerkEntryVisitor;

// 0C
class BGSPerkRankArray : public BaseFormComponent
{
public:
	// 08
	struct Entry
	{
		BGSPerk	* perk;		// 00
		UInt8	rank;		// 04
		UInt8	pad05[3];	// 05
	};

	Entry	* perkRanks;	// 04
	UInt32	numPerkRanks;	// 08

	void VisitPerkEntry(PerkEntryVisitor &visitor) const;
};


class PerkEntryVisitor
{
public:
	virtual bool operator()(const BGSPerkRankArray::Entry *) = 0;
};
