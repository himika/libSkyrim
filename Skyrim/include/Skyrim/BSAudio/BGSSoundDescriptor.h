#pragma once

#include "../FormComponents/BaseFormComponent.h"
#include "BSISoundDescriptor.h"
#include "../NetImmerse/NiPoint3.h"

class NiNode;

/*==============================================================================
class BGSSoundDescriptor +0000 (_vtbl=????????)
0000: class BGSSoundDescriptor
0000: |   class BSISoundDescriptor
==============================================================================*/
class BGSSoundDescriptor : public BSISoundDescriptor
{
public:
	struct SoundData
	{
		SoundData() : unk00(-1), unk04(0), unk08(0) {}

		DEFINE_MEMBER_FN(SetPosition, bool, 0x00B9A0F0, NiPoint3 pos);
		DEFINE_MEMBER_FN(SetNiNode, void, 0x00B9A2E0, NiNode *node);
		DEFINE_MEMBER_FN(Play, bool, 0x00B99ED0);

		// @members
		SInt32	unk00;
		UInt8	unk04;
		UInt32	unk08;
	};


	DEFINE_MEMBER_FN(SetUp, bool, 0x00B9CB60, SoundData *, BGSSoundDescriptor *, UInt32);

	//void	** _vtbl;	// 00
};
