#pragma once

#include "ExtraDataTypes.h"
#include "../Memory.h"

// C
class BSExtraData
{
public:
	BSExtraData() : next(nullptr) {}

	virtual ~BSExtraData();										// 00423F00

	virtual UInt32	GetType(void) const = 0;
	virtual bool	IsNotEqual(const BSExtraData *rhs) const;	// 004091A0 { return false; }

	static BSExtraData* Create(UInt32 size, UInt32 vtbl);

	TES_FORMHEAP_REDEFINE_NEW()

	// @members
	//void			** _vtbl	// 00
	BSExtraData		* next;		// 04
};
