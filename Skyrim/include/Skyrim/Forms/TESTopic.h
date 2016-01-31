#pragma once

#include "TESForm.h"
#include "../FormComponents/TESFullName.h"

/*==============================================================================
class TESTopic +0000 (_vtbl=010A6B1C)
0000: class TESTopic
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
==============================================================================*/
// 3C
class TESTopic : public TESForm,
	public TESFullName				// 14
{
public:
	enum { kTypeID = (UInt32)FormType::Topic };

	//explicit TESTopic(UInt32 arg1);						// 0057BE4F

	virtual ~TESTopic();									// 0057BEB0

	// @overide
	virtual const char *	GetName(void);					// 0057BBE0 { return unk38 ? unk38 : ""; }
	virtual bool			SetName(const char * str);		// 0057BBA0 { bool r = (unk38 == str); unk38 = str; return r; }
	virtual bool			Unk_34(void) override;			// 009B86F0 { return true; }
	virtual bool			Unk_36(FormType arg) override;	// 0057BD60 { return arg1 == 0x4C; }

	// @members
	//void				** _vtbl;		// 00 - 010A6B1C
	UInt8				unk1C;			// 1C - init'd 0
	UInt8				unk1D;			// 1D - init'd arg1
	UInt8				pad1E[2];		// 1E - init'd 0
	UInt32				unk20;			// 20 - init'd 0x32000000
	UInt32				unk24;			// 24 - init'd 0
	TESQuest			* questOwner;	// 28 - init'd 0
	UInt32				unk2C;			// 2C - init'd 0
	void				** unk30;		// 30- - buf[unk30]
	UInt32				unk34;			// 34 - len
	BSFixedString		unk38;			// 38 - init'd 0
};
STATIC_ASSERT(sizeof(TESTopic) == 0x3C);
