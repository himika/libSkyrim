#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../BSAudio/BGSSoundDescriptor.h"
#include "../../BSCore/BSFixedString.h"
#include "BGSStandardSoundDef.h"


/*==============================================================================
class BGSSoundDescriptorForm +0000 (_vtbl=0108E0D4)
0000: class BGSSoundDescriptorForm
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class BSISoundDescriptor
==============================================================================*/
// 20
class BGSSoundDescriptorForm : public TESForm,
	public BSISoundDescriptor				// 14
{
public:
	enum { kTypeID = (UInt32)FormType::SoundDescriptor };

	// @override class BSISoundDescriptor : (vtbl=0108E0C0)
	virtual void	BSISoundDescriptor_Unk_01(void) override;			// 00500610
	virtual void	BSISoundDescriptor_Unk_02(void) override;			// 00500570


	// @add
	virtual void	Unk_3B(void);	// // 00500560 calls something on unk18


	// @members
	BGSStandardSoundDef		* standardSoundDef;	// 18
	BSFixedString			unk1C;				// 1C
};
STATIC_ASSERT(sizeof(BGSSoundDescriptorForm) == 0x20);
