#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/TESModel.h"
#include "../../FormComponents/TESModelRDT.h"
#include "../../FormComponents/BGSPreloadable.h"

/*==============================================================================
class BGSBodyPartData +0000 (_vtbl=010A1E6C)
0000: class BGSBodyPartData
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESModel
0014: |   |   class BaseFormComponent
0028: |   class BGSPreloadable
0028: |   |   class BaseFormComponent
==============================================================================*/
// 44
class BGSBodyPartData : public TESForm,
	public TESModel,		// 14
	public BGSPreloadable	// 28
{
public:
	enum { kTypeID = (UInt32)FormType::BodyPartData };

	// @override
	// 0054A830 Unk_04		
	// 0054AA10 Unk_05		
	// 0054AA20 LoadForm		
	// 0054A850 InitItem		

	// @members
	struct Data
	{
		BSFixedString	unk00;		// 00
		BSFixedString	unk04;		// 04
		BSFixedString	unk08;		// 08
		BSFixedString	unk0C;		// 0C
		BSFixedString	unk10;		// 10
		TESModel		model;		// 14
		TESModelRDT		modelRDT;	// 28
	};

	Data	* part[5];		// 2C - init'd to 0
	UInt32	unk40;			// 40 - init'd to 0
};

