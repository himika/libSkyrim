#pragma once

#include "../../FormComponents/TESForm.h"

class BGSArtObject;
class TESEffectShader;


/*==============================================================================
class BGSReferenceEffect +0000 (_vtbl=01086924)
0000: class BGSReferenceEffect
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 20 - visual effect
class BGSReferenceEffect : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::ReferenceEffect };

	// C
	struct Data
	{
		BGSArtObject	* effectArt;	// 00 (14)
		TESEffectShader	* shader;		// 04 (18)
		UInt32			flags;			// 08 (1C)
	};


	// @members
	Data	data;		// 14
};
STATIC_ASSERT(sizeof(BGSReferenceEffect) == 0x20);
