#pragma once

#include "../Objects/TESBoundObject.h"
#include "../../FormComponents/TESModel.h"
#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/TESIcon.h"
#include "../../FormComponents/BGSPickupPutdownSounds.h"

/*==============================================================================
class BGSNote +0000 (_vtbl=010A34E4)
0000: class BGSNote
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESModel
0020: |   |   class BaseFormComponent
0034: |   class TESFullName
0034: |   |   class BaseFormComponent
003C: |   class TESIcon
003C: |   |   class TESTexture
003C: |   |   |   class BaseFormComponent
0044: |   class BGSPickupPutdownSounds
0044: |   |   class BaseFormComponent
==============================================================================*/
// 64
class BGSNote : public TESBoundObject,
	public TESModel,				// 20
	public TESFullName,				// 34
	public TESIcon,					// 3C
	public BGSPickupPutdownSounds	// 44
{
public:
	enum { kTypeID = (UInt32)FormType::Note };

	// @members
	struct Entry
	{
		void	* data;
		Entry	* next;
	};

	UInt32	unk50;		// 50
	UInt32	unk54;		// 54
	Entry	unk58;		// 58
	UInt8	unk60;		// 60
	UInt8	unk61;		// 61
	UInt8	pad62[2];	// 62
};
STATIC_ASSERT(sizeof(BGSNote) == 0x64);
