#pragma once

#include "TESForm.h"
#include "../FormComponents/TESTexture.h"

/*==============================================================================
class TESEffectShader +0000 (_vtbl=01082834)
0000: class TESEffectShader
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 1D4
class TESEffectShader : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::EffectShader };

	virtual ~TESEffectShader();				// 00498F70

	// @override
	virtual void	Unk_04(void) override;							// 00497F40
	virtual bool	LoadForm(TESFile *arg) override;				// 00497F50
	virtual void	InitItem(void) override;						// 00497170

	// 190?
	struct Data
	{
		UInt8	pad[0x190];	// ###
	};

	Data		unk14;
	TESTexture	unk1A4;
	TESTexture	unk1AC;
	TESTexture	unk1B4;
	TESTexture	unk1BC;
	TESTexture	unk1C4;
	UInt32		unk1CC;	// BSIntrusiveRefCounted *
	UInt32		unk1D0;	// BSIntrusiveRefCounted *
};
STATIC_ASSERT(sizeof(TESEffectShader) == 0x1D4);
