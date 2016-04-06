#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../BSCore/BSString.h"

/*==============================================================================
class TESGlobal +0000 (_vtbl=01091764)
0000: class TESGlobal
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 24
class TESGlobal : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::Global };

	// @override
	virtual const char *	GetName(void) override;					// 005134E0 { return unk14.m_data ? unk14.m_data : ""; }
	virtual bool			SetName(const char * str) override;		// 005134F0 { unk14.Set(str, 0); return true; }

	// @members
	BSString	unk14;	// 14
	UInt8		unk1C;	// 1C - type?
	UInt8		pad[3];	// 1D
	float		value;	// 20 (himika)
};
STATIC_ASSERT(sizeof(TESGlobal) == 0x24);
