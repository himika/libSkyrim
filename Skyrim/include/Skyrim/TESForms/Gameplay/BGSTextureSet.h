#pragma once

#include "../Objects/TESBoundObject.h"
#include "../../FormComponents/TESTexture.h"
#include "../../NetImmerse/BSTextureSet.h"


/*==============================================================================
class BGSTextureSet +0000 (_vtbl=0108E5FC)
0000: class BGSTextureSet
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class BSTextureSet
0020: |   |   class NiObject
0020: |   |   |   class NiRefObject
==============================================================================*/
// D0
class BGSTextureSet : public TESBoundObject,
	public BSTextureSet			// 20
{
public:
	enum { kTypeID = (UInt32)FormType::TextureSet };

	// @members

	// 0C
	struct Data
	{
		UInt32	unk00;	// 00
		UInt32	unk04;	// 04
		UInt32	unk08;	// 08
	};

	enum
	{
		kTextureDiffuse = 0,
		kTextureNormal,
		kTextureEnvironmentMask,
		kTextureSubsurfaceTint = kTextureEnvironmentMask,
		kTextureGlowMap,
		kTextureDetailMap = kTextureGlowMap,
		kTextureHeight,
		kTextureEnvironment,
		kTextureMultilayer,
		kTextureBacklightMask,
		kTextureSpecular = kTextureBacklightMask,
		kNumTextures
	};


	// @members
	TESTexture		texturePaths[kNumTextures];	// 28
	UInt32			unk68;						// 68
	UInt32			unk6C;						// 6C
	Data			unk70[kNumTextures];		// 70
};
STATIC_ASSERT(sizeof(BGSTextureSet) == 0xD0);
