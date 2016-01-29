#pragma once

#include "BaseFormComponent.h"
#include "../Misc/InventoryChanges.h"

class TESForm;
class Actor;

// 0C
class TESContainer : public BaseFormComponent
{
public:
	struct Entry
	{
		struct ExtraData		// COED - COntainer Extra Data
		{
			Actor	* owner;
			SInt32	requiredRank;
			float	condition;
		};

		SInt32		count;			// 00
		TESForm		* form;			// 04
		ExtraData	* data;			// 08
	};

	bool GetContainerItemAt(UInt32 idx, Entry *& entry) const {
		return (idx < numEntries) ? (entry = entries[idx], true) : false;
	}

	template <class Op>
	UInt32 CountIf(Op& op) const
	{
		UInt32 count = 0;
		for (UInt32 n = 0; n < numEntries; n++) {
			Entry* pEntry = entries[n];
			if (pEntry && op.Accept(pEntry))
				count++;
		}
		return count;
	}

	template <class Op>
	Entry* Find(Op& op) const
	{
		bool bFound = false;
		UInt32 n = 0;
		Entry* pEntry = nullptr;
		for (UInt32 n = 0; n < numEntries && !bFound; n++) {
			pEntry = entries[n];
			if (pEntry) {
				bFound = op.Accept(pEntry);
			}
		}
		return (bFound && pEntry) ? pEntry : nullptr;
	}

	template <class Op>
	void Visit(Op& op) const {
		bool bContinue = true;
		for (UInt32 n = 0; n < numEntries && bContinue; n++) {
			Entry* pEntry = entries[n];
			if (pEntry) {
				bContinue = op.Accept(pEntry);
			}
		}
	}

	bool GetContainerLevItemAt(UInt32 idx, Entry *& entry) const;

	UInt32 CountItem(TESForm* item) const;	// 0044F2A0


	// @members
	Entry	** entries;	// 04
	UInt32	numEntries;	// 08
};
