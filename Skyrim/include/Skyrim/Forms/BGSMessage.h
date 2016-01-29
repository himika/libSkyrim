#pragma once

#include "TESForm.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESDescription.h"
#include "../BSCore/BSString.h"
#include "../BSCore/BSFixedString.h"
#include "../BSCore/BSTList.h"
#include <string>

class TESQuest;

/*==============================================================================
class BGSMessage +0000 (_vtbl=0108D694)
0000: class BGSMessage
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class TESDescription
001C: |   |   class BaseFormComponent
==============================================================================*/
// 40
class BGSMessage : public TESForm,
	public TESFullName,		// 14
	public TESDescription	// 1C
{
public:
	enum { kTypeID = (UInt32)FormType::Message };

	// @members
	TESForm						* icon;		// 28 - init'd to 0
	TESQuest					* quest;	// 2C - init'd to 0
	BSSimpleList<BSFixedString>	buttons;	// 30
	UInt32						unk38;		// 38 - init'd to 1
	UInt32						unk3C;		// 3C - init'd to 2

	std::string GetDescription()
	{
		BSString str;
		TESDescription::Get(&str, this, 'DESC');
		return str.Get();
	};
};
STATIC_ASSERT(sizeof(BGSMessage) == 0x40);
