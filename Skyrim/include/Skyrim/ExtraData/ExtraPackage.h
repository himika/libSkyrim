#pragma once

#include "BSExtraData.h"

class TESPackage;

/*==============================================================================
class ExtraPackage +0000 (_vtbl=01079DAC)
0000: class ExtraPackage
0000: |   class BSExtraData
==============================================================================*/
// 18
class ExtraPackage : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Package };

	virtual ~ExtraPackage();			// 00416D60

	// @override
	virtual UInt32	GetType(void) const override;		// 004950F0 { return 0x00000019; }


	// @members
	TESPackage	* package;		// 08
	UInt32		unk0C;
	UInt32		unk10;
	UInt32		unk14;
};
