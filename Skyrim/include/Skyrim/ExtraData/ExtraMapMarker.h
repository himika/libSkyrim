#pragma once

#include "BSExtraData.h"
#include "../FormComponents/TESFullName.h"

class TESForm;

/*==============================================================================
class ExtraMapMarker +0000 (_vtbl=01079D2C)
0000: class ExtraMapMarker
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraMapMarker : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::MapMarker };

	//DEFINE_MEMBER_FN(ctor, ExtraMapMarker*, 0x00422460, UInt32 arg1);	{ unk08 = arg1; }

	// 0C
	class Data : public TESFullName
	{
		CLASS_SIZE_ASSERT(0x0C)
	public:
		UInt8	flags1;
		UInt8	flags2;
		UInt16	unk0A;

		void Enable(bool abEnabled) {		// 0x00428FE0
			if (abEnabled)
				flags1 |= 0x02;
			else
				flags1 &= 0xFD;
		}
	};


	// @members
	//void	** _vtbl	// 00 - 01079148
	Data	* mapMarker;

private:
	DEFINE_MEMBER_FN(ctor, ExtraMapMarker*, 0x00422630);
};
