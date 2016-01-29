#pragma once

#include "TESForm.h"
#include "../BSCore/BSFixedString.h"

/*==============================================================================
class TESLoadScreen +0000 (_vtbl=01091884)
0000: class TESLoadScreen
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 20
class TESLoadScreen : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::LoadScreen };

	void				* unk14;	// 14 - linked list
	TESObjectSTAT		* object;	// 18
	BSFixedString		unk1C;		// 1C
};
STATIC_ASSERT(sizeof(TESLoadScreen) == 0x20);
