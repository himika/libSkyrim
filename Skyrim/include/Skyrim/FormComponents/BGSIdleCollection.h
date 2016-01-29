#pragma once

#include "BaseFormComponent.h"

// 10
class BGSIdleCollection : public BaseFormComponent
{
public:
	UInt8	unk04;		// 04
	UInt8	unk05;		// 05 - unk08 length
	UInt8	unk06[2];	// 06
	void	** unk08;	// 08 - copyable struct
	UInt32	unk0C;		// 0C
};
