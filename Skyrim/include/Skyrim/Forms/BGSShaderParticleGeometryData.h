#pragma once

#include "TESForm.h"
#include "../FormComponents/TESTexture.h"
#include "../BSCore/BSTArray.h"

/*==============================================================================
class BGSShaderParticleGeometryData +0000 (_vtbl=01086BB4)
0000: class BGSShaderParticleGeometryData
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 28
class BGSShaderParticleGeometryData : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::SPGD };

	BSTArray<void*>		unk14;		// 14
	TESTexture			texture;	// 20
};
STATIC_ASSERT(sizeof(BGSShaderParticleGeometryData) == 0x28);
