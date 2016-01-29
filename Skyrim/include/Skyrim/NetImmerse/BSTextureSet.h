#pragma once

#include "Skyrim/NetImmerse/NiObject.h"

class NiSourceTexture;

/*==============================================================================
class BSTextureSet +0000 (_vtbl=0108E4AC)
0000: class BSTextureSet
0000: |   class NiObject
0000: |   |   class NiRefObject
==============================================================================*/
// 08
class BSTextureSet : public NiObject
{
public:
	enum { kRTTI = 0x01BA85A8 };

	virtual const char * GetTexturePath(UInt32 index);
	virtual void	SetTexture(UInt32 index, NiSourceTexture * texture);
	virtual void	SetTexturePath(UInt32 index, const char * path);

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
		kTextureUnused08,
		kNumTextures = 9
	};
};

/*==============================================================================
class BSShaderTextureSet +0000 (_vtbl=0108E544)
0000: class BSShaderTextureSet
0000: |   class BSTextureSet
0000: |   |   class NiObject
0000: |   |   |   class NiRefObject
==============================================================================*/
// 2C
class BSShaderTextureSet : public BSTextureSet
{
public:
	UInt32	unk08;
	UInt32	unk0C;
	UInt32	unk10;
	UInt32	unk14;
	UInt32	unk18;
	UInt32	unk1C;
	UInt32	unk20;
	UInt32	unk24;
	UInt32	unk28;

	static BSShaderTextureSet * Create();

private:
	DEFINE_MEMBER_FN(ctor, BSShaderTextureSet *, 0x00501EA0);
};
STATIC_ASSERT(sizeof(BSShaderTextureSet) == 0x2C);

