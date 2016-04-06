#pragma once

#include "BaseFormComponent.h"

class BGSPerk;
class PerkRankVisitor;


/*==============================================================================
class BGSPerkRankArray +0000 (_vtbl=0107C45C)
0000: class BGSPerkRankArray
0000: |   class BaseFormComponent
==============================================================================*/
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

	void VisitPerkRanks(PerkRankVisitor &visitor) const;


	// @members
	Entry	* perkRanks;	// 04
	UInt32	numPerkRanks;	// 08
};


class PerkRankVisitor
{
public:
	virtual bool operator()(const BGSPerkRankArray::Entry *) = 0;
};
