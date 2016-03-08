#pragma once

#include "BGSBaseAlias.h"

class BSFixedString;

/*==============================================================================
class BGSLocAlias +0000 (_vtbl=010A32C8)
0000: class BGSLocAlias
0000: |   class BGSBaseAlias
==============================================================================*/
class BGSLocAlias : public BGSBaseAlias
{
public:
	enum { kTypeID = (UInt32)FormType::LocationAlias };

	virtual ~BGSLocAlias();												// 0054E4E0

	// @override
	virtual bool					Unk01(UInt32 arg1) override;		// 0054E1B0
	virtual void					Unk02(UInt32 arg1) override;		// 0054E0B0
	virtual const BSFixedString &	GetTypeString(void) const override;	// 0054DFB0 { return BSFixedString("Loc"); }

	// @add
	virtual void					Unk_04(void);			// 00636F4C

	void Clear();

	UInt32 unk18[0x08];
};
