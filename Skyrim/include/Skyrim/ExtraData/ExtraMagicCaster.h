#pragma once

#include "BSExtraData.h"
#include "../FormComponents/MagicCaster.h"

/*==============================================================================
class ExtraMagicCaster +0000 (_vtbl=????????)
0000: class ExtraMagicCaster
0000: |   class BSExtraData
0008: |   class MagicCaster
==============================================================================*/
class ExtraMagicCaster : public BSExtraData,
	public MagicCaster			// 08
{
};
