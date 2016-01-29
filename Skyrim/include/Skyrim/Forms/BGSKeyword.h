#pragma once

#include "TESForm.h"
#include "../BSCore/BSString.h"

/*==============================================================================
class BGSKeyword +0000 (_vtbl=010A3184)
0000: class BGSKeyword
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 1C
class BGSKeyword : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::Keyword };

	// @override
	virtual bool		LoadForm(TESFile *arg) override;		// 0054DE60
	virtual const char	* GetName(void) override;				// 00966620 { return (const char*)keyword; }
	virtual bool		SetName(const char * str) override;		// 004B24E0 { keyword = str; }

	BSString	keyword;	// 14
};
STATIC_ASSERT(sizeof(BGSKeyword) == 0x1C);
