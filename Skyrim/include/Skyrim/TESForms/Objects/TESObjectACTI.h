#pragma once

#include "TESBoundAnimObject.h"
#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/TESModelTextureSwap.h"
#include "../../FormComponents/BGSDestructibleObjectForm.h"
#include "../../FormComponents/BGSOpenCloseForm.h"
#include "../../FormComponents/BGSKeywordForm.h"
#include "../../FormComponents/TESMagicTargetForm.h"

class TESWaterForm;


/*==============================================================================
class TESObjectACTI +0000 (_vtbl=010841B4)
0000: class TESObjectACTI
0000: |   class TESBoundAnimObject
0000: |   |   class TESBoundObject
0000: |   |   |   class TESObject
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
0020: |   class TESFullName
0020: |   |   class BaseFormComponent
0028: |   class TESModelTextureSwap
0028: |   |   class TESModel
0028: |   |   |   class BaseFormComponent
005C: |   class TESMagicTargetForm
0044: |   class BGSDestructibleObjectForm
0044: |   |   class BaseFormComponent
004C: |   class BGSOpenCloseForm
0050: |   class BGSKeywordForm
0050: |   |   class BaseFormComponent
==============================================================================*/
// 6C
class TESObjectACTI : public TESBoundAnimObject,
	public TESFullName,					// 20
	public TESModelTextureSwap,			// 28
	public TESMagicTargetForm,			// 5C
	public BGSDestructibleObjectForm,	// 44
	public BGSOpenCloseForm,			// 4C
	public BGSKeywordForm				// 50
{
public:
	enum { kTypeID = (UInt32)FormType::Activator };

	virtual ~TESObjectACTI();											// 0049FF40

	// @override class TESBoundAnimObject : (vtbl=010841B4)
	virtual void	Unk_04(void) override;								// 0049FCF0
	virtual void	Unk_05(void) override;								// 004A0A40
	virtual bool	LoadForm(TESFile *mod) override;					// 004A0980
	virtual void	SaveBuffer(BGSSaveFormBuffer *buf) override;		// 0049FE10
	virtual void	LoadBuffer(BGSLoadFormBuffer *buf) override;		// 0049FF70
	virtual void	InitItem(void) override;							// 004A05D0
	virtual bool	Unk_22(void) override;								// 00494E70 { return (unk68 >> 1) & 1; }
	virtual bool	Unk_2A(void) override;								// 0049FD00 { return waterType != nullptr; }
	virtual bool	ActivateReference(TESObjectREFR* targetRef, TESObjectREFR* activatorRef, UInt32 arg2, UInt32 arg3, UInt32 arg4) override;	// 004A0040
	virtual bool	GetCrosshairText(TESObjectREFR *ref, BSString *dst, bool unk) override;		// 004A0170
	virtual bool	Unk_4E(void * arg0, UInt8 arg1, UInt32 arg2, float arg3) override;			// 0049FD10 { return true; }

	// @members
	BGSSoundDescriptorForm	* loopingSound;			// 5C - SNAM - looping sound
	BGSSoundDescriptorForm	* activationSound;		// 60 - VNAM - activation sound
	TESWaterForm			* waterType;			// 64 - WNAM - water type
	UInt16					unk68;					// 68 - FNAM - flags
	UInt8					pad6A[2];				// 6A

private:
	DEFINE_MEMBER_FN(ctor, TESObjectACTI *, 0x0049FEB0);
};
STATIC_ASSERT(sizeof(TESObjectACTI) == 0x6C);
