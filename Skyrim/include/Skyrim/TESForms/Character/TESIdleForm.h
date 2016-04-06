#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../BSCore/BSString.h"
#include "../../BSCore/BSFixedString.h"

/*==============================================================================
class TESIdleForm +0000 (_vtbl=010A5114)
0000: class TESIdleForm
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 3C
class TESIdleForm : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::Idle };

	// @members
	void				* unk14;			// 14 - linked list
	UInt8				loopMin;			// 18
	UInt8				loopMax;			// 19
	UInt8				flags;				// 1A
	UInt8				group;				// 1B
	UInt16				unk1C;				// 1C
	UInt8				pad1E[2];			// 1E
	UInt32				unk20;				// 20 - NiFormArray
	TESIdleForm			* relatedIdle1;		// 24
	TESIdleForm			* relatedIdle2;		// 28
	BSFixedString		fileName;			// 2C
	BSFixedString		animationEvent;		// 30
	BSString			editorId;			// 34
};
STATIC_ASSERT(sizeof(TESIdleForm) == 0x3C);
