#pragma once

#include "TESForm.h"

class TESWorldSpace;

/*==============================================================================
class TESRegion +0000 (_vtbl=01080654)
0000: class TESRegion
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 30
class TESRegion : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::Region };

	virtual bool	Unk_3B(void);

	// C
	struct Data14
	{
		UInt32	unk0;		// 0
		UInt32	unk4;		// 4
		UInt8	unk8;		// 8
		UInt8	unk9[3];	// 9
	};

	// 8
	struct Data18
	{
		UInt32	unk0;
		UInt32	unk4;
	};

	// C
	struct Data24
	{
		UInt32	unk0;
		UInt32	unk4;
		UInt32	unk8;
	};

	Data14	* unk14;	// 14
	Data18	* unk18;	// 18
	TESWorldSpace	* worldSpace;		// 1C
	UInt32	unk20;		// 20
	Data24	unk24;		// 24
};
STATIC_ASSERT(sizeof(TESRegion) == 0x30);
