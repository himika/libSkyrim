#pragma once

#include "TESForm.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/BGSKeywordForm.h"
#include "../BSCore/BSTArray.h"

class BGSLocationRefType;

/*==============================================================================
class BGSLocation +0000 (_vtbl=0108669C)
0000: class BGSLocation
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class BGSKeywordForm
001C: |   |   class BaseFormComponent
==============================================================================*/
// 88
class BGSLocation : public TESForm,
	public TESFullName,				// 14
	public BGSKeywordForm			// 1C
{
public:
	enum { kTypeID = (UInt32)FormType::Location };

	// @members
	BGSLocation					* child;	// 28 (himika)
	UInt32						unk2C;		// 2C - init'd to 0
	UInt32						unk30;		// 30 - init'd to 0
	UInt32						unk34;		// 34 - init'd to 0
	UInt32						unk38;		// 38 - init'd to 0
	UInt32						unk3C;		// 3C - init'd to 0
	BSTArray<void*>				unk40;		// 40 - array of locationRefTypes
	BSTArray<void*>				unk4C;		// 4C
	UInt32						unk58;		// 58 - init'd to 0
	UInt32						unk5C;		// 5C - init'd to 0
	BSTArray<void*>				unk60;		// 60
	UInt32						unk6C;		// 6C - init'd to 0	loaded cell array?
	UInt32						unk70;		// 70 - init'd to 0
	BSTArray<void*>				unk74;		// 74 - keywordData
	UInt32						unk80;		// 80 - init'd to 0
	bool						isCleard;	// 84 (himika)
	UInt8						unk85;		// 85 - init'd to 0
	UInt8						pad86[2];	// 86

	// (himika)
	bool IsLoaded(void) const {						// 008EA080 - Location.IsLoaded()
		return (unk6C) ? true : false;
	}
	bool IsCleared(void) const {					// 008EA070 - Location.IsCleared()
		return isCleard;
	}
	bool IsChild(BGSLocation* akOther) const {		// 008E9FC0 - Location.IsChild()
		bool result = false;
		for (const BGSLocation* loc = akOther; loc; loc = loc->child) {
			if (loc->child == this) {
				result = true;
				break;
			}
		}
		return result;
	}
	float	GetKeywordData(const BGSKeyword *keyword) const {	// 008EA040 - Location.GetKeywordData(Keyword)
		return GetKeywordData_Impl(keyword);
	}
	UInt32	GetRefTypeAliveCount(const BGSLocationRefType *locationRefType) const;
	UInt32	GetRefTypeDeadCount(const BGSLocationRefType *locationRefType) const;
	bool	HasRefType(const BGSLocationRefType *) const;

private:
	DEFINE_MEMBER_FN_const(GetKeywordData_Impl, float, 0x004B0400, const BGSKeyword *);
	DEFINE_MEMBER_FN_const(GetRefTypeCount_Impl, UInt32, 0x004B1550, const BGSLocationRefType*, bool, bool, bool, bool, bool);
	DEFINE_MEMBER_FN_const(HasRefType_Impl, bool, 0x004B1150, const BGSLocationRefType *, bool);
};
STATIC_ASSERT(sizeof(BGSLocation) == 0x88);
