#pragma once

#include "BaseFormComponent.h"


/*==============================================================================
class BGSDestructibleObjectForm +0000 (_vtbl=0107C350)
0000: class BGSDestructibleObjectForm
0000: |   class BaseFormComponent
==============================================================================*/
// 08
class BGSDestructibleObjectForm : public BaseFormComponent
{
public:
	// 14
	struct Data
	{
		UInt32	unk00;		// 00
		UInt8	unk04;		// 04
		UInt8	unk05;		// 05
		UInt8	pad06[2];	// 06
		UInt32	unk08;		// 08
		UInt32	unk0C;		// 0C
		UInt32	unk10;		// 10 - object
	};

	// @members
	Data	* data;	// 04
};
