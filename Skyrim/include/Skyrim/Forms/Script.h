#pragma once

#include "TESForm.h"

/*==============================================================================
class Script +0000 (_vtbl=010919E4)
0000: class Script
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 50
class Script : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::Script };

	// 14
	struct Data
	{
		UInt32	unk00;	// 00
		UInt32	unk04;	// 04 - numRefs?
		UInt32	unk08;	// 08 - dataLength?
		UInt32	unk0C;	// 0C - varCount?
		UInt32	unk10;	// 10 - type?
	};

	struct RefListEntry
	{
		void			* data;
		RefListEntry	* next;
	};

	struct VarInfoEntry
	{
		void			* data;
		VarInfoEntry	* next;
	};

	Data			unk14;				// 14
	void			* unk28;			// 28
	void			* unk2C;			// 2C
	UInt32			unk30;				// 30
	float			questDelayTimer;	// 34
	float			secondsPassed;		// 38
	TESForm			* parentQuest;		// 3C
	RefListEntry	refList;			// 40
	VarInfoEntry	varList;			// 48
};
STATIC_ASSERT(sizeof(Script) == 0x50);
