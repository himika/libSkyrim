#pragma once

#include "TESBoundObject.h"
#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/TESModelTextureSwap.h"
#include "../../FormComponents/TESIcon.h"
#include "../../FormComponents/TESValueForm.h"
#include "../../FormComponents/TESWeightForm.h"
#include "../../FormComponents/TESDescription.h"
#include "../../FormComponents/BGSDestructibleObjectForm.h"
#include "../../FormComponents/BGSMessageIcon.h"
#include "../../FormComponents/BGSPickupPutdownSounds.h"
#include "../../FormComponents/BGSKeywordForm.h"

/*==============================================================================
class TESObjectBOOK +0000 (_vtbl=01084B0C)
0000: class TESObjectBOOK
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
004C: |   class TESValueForm
004C: |   |   class BaseFormComponent
0054: |   class TESWeightForm
0054: |   |   class BaseFormComponent
005C: |   class TESDescription
005C: |   |   class BaseFormComponent
0068: |   class BGSDestructibleObjectForm
0068: |   |   class BaseFormComponent
0070: |   class BGSMessageIcon
0070: |   |   class BaseFormComponent
007C: |   class BGSPickupPutdownSounds
007C: |   |   class BaseFormComponent
0088: |   class BGSKeywordForm
0088: |   |   class BaseFormComponent
==============================================================================*/
// AC
class TESObjectBOOK : public TESBoundObject,
	public TESFullName,						// 20
	public TESModelTextureSwap,				// 28
	public TESIcon,							// 44
	public TESValueForm,					// 4C
	public TESWeightForm,					// 54
	public TESDescription,					// 5C
	public BGSDestructibleObjectForm,		// 68
	public BGSMessageIcon,					// 70
	public BGSPickupPutdownSounds,			// 7C
	public BGSKeywordForm					// 88
{
public:
	enum { kTypeID = (UInt32)FormType::Book };

	// @members
	struct Data
	{
		enum	// type - these are technically flags
		{
			kType_None			= 0,
			kType_Skill			= 1 << 0,	// 01
			kType_CantBeTaken	= 1 << 1,	// 02
			kType_Spell			= 1 << 2,	// 04 takes priority over skill
			kType_Read			= 1 << 3,	// 08 set once the book is equipped by the player, along with the CHANGE_BOOK_READ (0x40) change flag
		};

		UInt8	flags;		// 0
		UInt8	type;		// 1
		UInt16	unk02;		// 2, probably padding too
		union
		{
			UInt32		skill;
			SpellItem	* spell;
		} teaches;			// 4

		// make some sense of the flags field so we know what's in the union
		UInt32	GetSanitizedType(void);
	};

	virtual ~TESObjectBOOK();											// 004A3280

	// @override class TESBoundObject : (vtbl=01084B0C)
	virtual void	Unk_04(void) override;								// 004A2E80
	virtual void	Unk_05(void) override;								// 004067E0
	virtual bool	LoadForm(TESFile *mod) override;					// 004A32B0
	virtual void	SaveBuffer(BGSSaveFormBuffer *buf) override;		// 004A3070
	virtual void	LoadBuffer(BGSLoadFormBuffer *buf) override;		// 004A30B0
	virtual void	InitItem(void) override;							// 004A38C0
	virtual bool	ActivateReference(TESObjectREFR* targetRef, TESObjectREFR* activatorRef, UInt32 arg2, UInt32 arg3, UInt32 arg4) override;	// 004A36F0
	virtual bool	GetCrosshairText(TESObjectREFR *ref, BSString *dst, bool unk) override;		// 004A3980


	bool IsRead() const
	{
		return ((data.flags & Data::kType_Read) != 0);
	}


	// @members
	Data			data;			// 94
	TESObjectSTAT	* bookStat;		// 9C
	TESDescription	description2;	// A0
};

STATIC_ASSERT(sizeof(TESObjectBOOK) == 0xAC);
