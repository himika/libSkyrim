#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraTeleport +0000 (_vtbl=01079168)
0000: class ExtraTeleport
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraTeleport : public BSExtraData
{
public:
	virtual ~ExtraTeleport();											// 0040AD70

	virtual UInt32	GetType(void) const override;						// 00561320 { return 0x0000002B; }
	virtual bool	IsNotEqual(const BSExtraData *rhs) const override;	// 00420C60

	// 20
	struct Data
	{
		RefHandle	refHandle;		// ref to linked door
		float		unk04;
		float		unk08;
		float		unk0C;
		float		unk10;
		float		unk14;
		float		unk18;
		UInt8		unk1C;
	};

	// @members
	Data	* data;
};
