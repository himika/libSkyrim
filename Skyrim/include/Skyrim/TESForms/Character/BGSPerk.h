#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/TESDescription.h"
#include "../../FormComponents/TESIcon.h"
#include "../../FormComponents/Condition.h"
#include "../../FormComponents/BGSPerkRankArray.h"
#include "../../BSCore/BSTArray.h"
#include "BGSPerkEntry.h"


/*==============================================================================
class BGSPerk +0000 (_vtbl=010A37CC)
0000: class BGSPerk
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class TESDescription
001C: |   |   class BaseFormComponent
0028: |   class TESIcon
0028: |   |   class TESTexture
0028: |   |   |   class BaseFormComponent
==============================================================================*/
// 4C
class BGSPerk : public TESForm,
	public TESFullName,
	public TESDescription,
	public TESIcon
{
public:
	enum { kTypeID = (UInt32)FormType::Perk };

	/*==============================================================================
	class BGSPerk::FindPerkInRanksVisitor +0000 (_vtbl=010D1288)
	0000: class BGSPerk::FindPerkInRanksVisitor
	0000: |   class PerkRankVisitor
	==============================================================================*/
	class FindPerkInRanksVisitor : public PerkRankVisitor
	{
	public:
		virtual void Visit(void);	// 0054F460
	};

	/*==============================================================================
	class BGSPerk::ApplyPerksVisitor +0000 (_vtbl=010D1290)
	0000: class BGSPerk::ApplyPerksVisitor
	0000: |   class PerkRankVisitor
	==============================================================================*/
	class ApplyPerksVisitor : public PerkRankVisitor
	{
	public:
		virtual void Visit(void);	// 0054F480
	};

	/*==============================================================================
	class BGSPerk::AddPerkVisitor +0000 (_vtbl=010D1D84)
	0000: class BGSPerk::AddPerkVisitor
	0000: |   class PerkRankVisitor
	==============================================================================*/
	class AddPerkVisitor : public PerkRankVisitor
	{
	public:
		virtual void Visit(void);	// 0054F640
	};


	// @members
	UInt8							unk30;			// 30
	UInt8							unk31;			// 31
	UInt8							unk32;			// 32
	UInt8							unk33;			// 33
	UInt8							unk34;			// 34
	UInt8							pad35[3];		// 35
	Condition						* conditions;	// 38
	BSTArray<BGSPerkEntry *>		perkEntries;	// 3C
	BGSPerk							* nextPerk;		// 48
};
STATIC_ASSERT(sizeof(BGSPerk) == 0x4C);


class PerkEntryVisitor
{
public:
	virtual UInt32 Visit(BGSPerkEntry *perkEntry) = 0;
};
