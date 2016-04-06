#pragma once

#include "TESBoundAnimObject.h"
#include "../../FormComponents/TESContainer.h"
#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/TESModelTextureSwap.h"
#include "../../FormComponents/TESWeightForm.h"
#include "../../FormComponents/BGSDestructibleObjectForm.h"
#include "../../FormComponents/BGSOpenCloseForm.h"

/*==============================================================================
class TESObjectCONT +0000 (_vtbl=01084D44)
0000: class TESObjectCONT
0000: |   class TESBoundAnimObject
0000: |   |   class TESBoundObject
0000: |   |   |   class TESObject
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
0020: |   class TESContainer
0020: |   |   class BaseFormComponent
002C: |   class TESFullName
002C: |   |   class BaseFormComponent
0034: |   class TESModelTextureSwap
0034: |   |   class TESModel
0034: |   |   |   class BaseFormComponent
0050: |   class TESWeightForm
0050: |   |   class BaseFormComponent
0064: |   class TESMagicCasterForm
0065: |   class TESMagicTargetForm
0058: |   class BGSDestructibleObjectForm
0058: |   |   class BaseFormComponent
0060: |   class BGSOpenCloseForm
==============================================================================*/
// 74
class TESObjectCONT : public TESBoundAnimObject,
	public TESContainer,				// 20
	public TESFullName,					// 2C
	public TESModelTextureSwap,			// 34
	public TESWeightForm,				// 50
	public BGSDestructibleObjectForm,	// 58
	public BGSOpenCloseForm				// 60
{
public:
	enum { kTypeID = (UInt32)FormType::Container };

	virtual ~TESObjectCONT();															// 004A41E0

	// @override class TESBoundAnimObject : (vtbl=01084D44)
	virtual void	Unk_04(void) override;												// 004A3CD0
	virtual bool	LoadForm(TESFile *mod) override;									// 004A4210
	virtual void	InitItem(void) override;											// 004A3DB0
	virtual bool	ActivateReference(TESObjectREFR* targetRef, TESObjectREFR* activatorRef, UInt32 arg2, UInt32 arg3, UInt32 arg4) override;	// 004A4620
	virtual bool	GetCrosshairText(TESObjectREFR *ref, BSString * dst, bool unk) override;	// 004A4900
	virtual bool	Unk_4E(void * arg0, UInt8 arg1, UInt32 arg2, float arg3) override;	// 004A3F30

	// @override class BGSOpenCloseForm : (vtbl=01084EB8)
	virtual	void	ProcessOpen(TESObjectREFR *target, Actor *activator) override;		// 004A4040
	virtual	void	ProcessClose(TESObjectREFR *target, Actor *activator) override;		// 004A4880
	virtual	bool	CanProcessOpenClose(void) override;									// 009B86F0 { return true; }


	// @members
	UInt32	unk64;		// 64
	UInt32	unk68;		// 68
	UInt32	unk6C;		// 6C
	UInt8	unk70;		// 70
	UInt8	pad71[3];	// 71
};
STATIC_ASSERT(sizeof(TESObjectCONT) == 0x74);
