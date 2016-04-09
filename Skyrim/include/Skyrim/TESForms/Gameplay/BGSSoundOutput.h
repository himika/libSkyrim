#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../BSAudio/BSISoundOutputModel.h"


/*==============================================================================
class BGSSoundOutput +0000 (_vtbl=0108E2CC)
0000: class BGSSoundOutput
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class BSISoundOutputModel
==============================================================================*/
// 28
class BGSSoundOutput : public TESForm,
	public BSISoundOutputModel		// 14
{
public:
	enum { kTypeID = (UInt32)FormType::SoundOutput };

	/*==============================================================================
	struct BGSSoundOutput::DynamicAttenuationCharacteristics +0000 (_vtbl=0108E288)
	0000: struct BGSSoundOutput::DynamicAttenuationCharacteristics
	0000: |   struct BSISoundOutputModel::BSIAttenuationCharacteristics
	==============================================================================*/
	struct DynamicAttenuationCharacteristics : public BSISoundOutputModel::BSIAttenuationCharacteristics
	{
		virtual void Unk_001(void) override;		// 005B05E0
		virtual void Unk_002(void) override;		// 00500B80
		virtual void Unk_003(void) override;		// 00500B90
	};

	// @members
	UInt32	unk18;		// 18
	UInt32	unk1C;		// 1C
	UInt32	unk20;		// 20
	void	* unk24;	// 24
};
STATIC_ASSERT(sizeof(BGSSoundOutput) == 0x28);
