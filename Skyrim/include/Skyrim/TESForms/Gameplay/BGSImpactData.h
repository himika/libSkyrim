#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/TESModel.h"

/*==============================================================================
class BGSImpactData +0000 (_vtbl=0108CDBC)
0000: class BGSImpactData
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESModel
0014: |   |   class BaseFormComponent
==============================================================================*/
// 78
class BGSImpactData : public TESForm,
	public TESModel
{
public:
	enum { kTypeID = (UInt32)FormType::ImpactData };

	// 20
	struct DecalData
	{
		float	minw;				// 00 - init'd to 8
		float	maxw;				// 04 - init'd to 32
		float	minh;				// 08 - init'd to 8
		float	maxh;				// 0C - init'd to 32
		float	depth;				// 10 - init'd to 32
		float	shininess;			// 14 - init'd to 4
		float	parallaxScale;		// 18 - init'd to 1
		UInt8	parallaxPasses;		// 1C - init'd to 4

		enum
		{
			kDecalFlag_Parallax			= (1 << 0),
			kDecalFlag_AlphaBlending	= (1 << 1),
			kDecalFlag_AlphaTesting		= (1 << 2),
			kDecalFlag_NoSubtextures	= (1 << 3)
		};

		UInt8	flags;		// 1D - init'd to 0
		UInt8	pad1E[2];	// 1E
	};

	enum
	{
		kOrientation_SurfaceNormal = 0,
		kOrientation_ProjectileNormal = 1,
		kOrientation_ProjtectileReflection = 2
	};

	enum
	{
		kFlags_NoDecalData = 1
	};

	// @members
	float					duration;			// 28 - init'd to .25
	UInt32					orientation;		// 2C - init'd to 2
	float					angleThreshold;		// 30 - init'd to 15
	float					placementRadius;	// 34 - init'd to 16
	UInt32					soundLevel;			// 38 - init'd to 1
	UInt8					flags;				// 3C
	UInt8					impactResult;		// 3D
	UInt8					pad3E[2];			// 3E
	BGSTextureSet			* textures[2];		// 40 - texture set
	BGSSoundDescriptorForm	* sounds[2];		// 48 - sound
	BGSHazard				* hazard;			// 50 - hazard
	DecalData				unk54;				// 54
	UInt32					pad74;				// 74
};
STATIC_ASSERT(sizeof(BGSImpactData) == 0x78);
