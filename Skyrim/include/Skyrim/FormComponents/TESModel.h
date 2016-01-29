#pragma once

#include "BaseFormComponent.h"
#include "../BSCore/BSFixedString.h"

/*==============================================================================
class TESModel +0000 (_vtbl=0107CE64)
0000: class TESModel
0000: |   class BaseFormComponent
==============================================================================*/
// 14
class TESModel : public BaseFormComponent
{
public:
	virtual ~TESModel();										// 00454270

	// @add
	virtual const char *	GetModelName(void) const;			// 004F8CA0 { return modelName.c_str(); }
	virtual void			SetModelName(const char * name);	// 00447B80 { modelName = name; }
	virtual TESModel *		TESModel_Unk_06(void);				// 005EADD0 { return nullptr; }

	BSFixedString	modelName;	// 04

	UInt32			unk08;		// 08 - NiTPointerMap <int, void *>
	UInt32			unk0C;		// 0C
	UInt16			unk10;		// 10
	UInt8			unk12;		// 12
	UInt8			unk13;		// 13
};
