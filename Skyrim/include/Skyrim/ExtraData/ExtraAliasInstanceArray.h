#pragma once

#include "BSExtraData.h"
#include "../BSCore/BSTArray.h"

class TESQuest;
class BGSBaseAlias;
class TESPackage;

class ExtraAliasInstanceArray : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::AliasInstanceArray };

	ExtraAliasInstanceArray();
	virtual ~ExtraAliasInstanceArray();

	struct AliasInfo
	{
		TESQuest		* quest;
		BGSBaseAlias	* alias;
		BSTArray<TESPackage*>	* packages;
	};

	BSTArray<AliasInfo*> aliases;	// 08
};
