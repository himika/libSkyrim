#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

/*==============================================================================
class ExtraForcedTarget +0000 (_vtbl=010797C0)
0000: class ExtraForcedTarget
0000: |   class BSExtraData
==============================================================================*/
class ExtraForcedTarget : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::ForcedTarget };

	RefHandle	handle;	// 08

	static ExtraForcedTarget* Create();
	TESObjectREFR * GetReference();
};
