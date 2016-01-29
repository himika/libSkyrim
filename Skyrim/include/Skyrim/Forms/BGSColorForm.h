#pragma once

#include "TESForm.h"
#include "../FormComponents/TESFullName.h"

/*==============================================================================
class BGSColorForm +0000 (_vtbl=0108A76C)
0000: class BGSColorForm
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
==============================================================================*/
// 24
class BGSColorForm : public TESForm,
	public TESFullName					// 14
{
public:
	enum { kTypeID = (UInt32)FormType::ColorForm };

	// @override
	virtual void	Unk_04(void) override;				// 004F8C90 { abgr = 0; unk20 = 0; }
	virtual void	Unk_05(void) override;				// 004F8C90 { abgr = 0; unk20 = 0; }
	virtual bool	LoadForm(TESFile *arg) override;	// 004F8DA0

	// @members
	struct Color {
		UInt8 red;
		UInt8 green;
		UInt8 blue;
		UInt8 alpha; // The alpha isn't actually used here so its usually zero
	} color;		// 1C
	UInt32  unk20;  // 20
};
STATIC_ASSERT(sizeof(BGSColorForm) == 0x24);
