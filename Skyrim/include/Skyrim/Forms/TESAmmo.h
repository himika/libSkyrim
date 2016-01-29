#pragma once

#include "TESBoundObject.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESModelTextureSwap.h"
#include "../FormComponents/TESIcon.h"
#include "../FormComponents/BGSMessageIcon.h"
#include "../FormComponents/TESValueForm.h"
#include "../FormComponents/BGSDestructibleObjectForm.h"
#include "../FormComponents/BGSPickupPutdownSounds.h"
#include "../FormComponents/TESDescription.h"
#include "../FormComponents/BGSKeywordForm.h"
#include "../BSCore/BSFixedString.h"

/*==============================================================================
class TESAmmo +0000 (_vtbl=010822B4)
0000: class TESAmmo
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESFullName
0020: |   |   class BaseFormComponent
0028: |   class TESModelTextureSwap
0028: |   |   class TESModel
0028: |   |   |   class BaseFormComponent
0044: |   class TESIcon
0044: |   |   class TESTexture
0044: |   |   |   class BaseFormComponent
004C: |   class BGSMessageIcon
004C: |   |   class BaseFormComponent
0058: |   class TESValueForm
0058: |   |   class BaseFormComponent
0060: |   class BGSDestructibleObjectForm
0060: |   |   class BaseFormComponent
0068: |   class BGSPickupPutdownSounds
0068: |   |   class BaseFormComponent
0074: |   class TESDescription
0074: |   |   class BaseFormComponent
0080: |   class BGSKeywordForm
0080: |   |   class BaseFormComponent
==============================================================================*/
// 9C
class TESAmmo : public TESBoundObject,
	public TESFullName,					// 20
	public TESModelTextureSwap,			// 28
	public TESIcon,						// 44
	public BGSMessageIcon,				// 4C
	public TESValueForm,				// 58
	public BGSDestructibleObjectForm,	// 50
	public BGSPickupPutdownSounds,		// 68
	public TESDescription,				// 74
	public BGSKeywordForm				// 80
{
public:
	enum { kTypeID = (UInt32)FormType::Ammo };

	virtual ~TESAmmo();											// 00495D90

	// @override TESObject
	virtual UInt32	Unk_40(UInt32 arg0, UInt32 arg1) override;	// 00496250 "Arrow%d"

	// @override TESBoundObject
	virtual void	Unk_4F(UInt32 arg);							// 004961B0


	// @members

	// 0C
	struct AmmoSettings
	{
		BGSProjectile	* projectile;
		UInt32			flags;
		float			damage;
	};

	enum {
		kIgnoreNormalResist = (1 << 0),
		kNotPlayable = (1 << 1),
		kNotBolt = (1 << 2)
	};

	bool isBolt() { return (settings.flags & kNotBolt) != kNotBolt; }
	bool isPlayable() { return (settings.flags & kNotPlayable) != kNotPlayable; }

	AmmoSettings		settings;	// 8C
	BSFixedString		unk98;		// 98
};
STATIC_ASSERT(sizeof(TESAmmo) == 0x9C);
