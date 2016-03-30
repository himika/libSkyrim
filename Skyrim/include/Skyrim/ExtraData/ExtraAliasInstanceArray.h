#pragma once

#include "BSExtraData.h"
#include "../BSCore/BSTArray.h"

class TESQuest;
class BGSBaseAlias;
class TESPackage;

/*==============================================================================
class ExtraAliasInstanceArray +0000 (_vtbl=01079AB8)
0000: class ExtraAliasInstanceArray
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraAliasInstanceArray : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::AliasInstanceArray };

	// 0C
	struct AliasInfo
	{
		TESQuest				* quest;		// 00
		BGSBaseAlias			* alias;		// 04
		BSTArray<TESPackage *>	* packages;		// 08
	};


	ExtraAliasInstanceArray();
	virtual ~ExtraAliasInstanceArray();			// 00416D60

	// @override
	virtual UInt32	GetType(void) const override;		// 00421170 { return 0x00000088; }


	// @members
	BSTArray<AliasInfo *> aliases;	// 08
};
