#pragma once

#include "BSExtraData.h"
#include "ExtraMagicCaster.h"

/*==============================================================================
class NonActorMagicCaster +0000 (_vtbl=010C9A44)
0000: class NonActorMagicCaster
0000: |   class ExtraMagicCaster
0000: |   |   class BSExtraData
0008: |   |   class MagicCaster
==============================================================================*/
class NonActorMagicCaster : public ExtraMagicCaster
{
public:
	virtual ~NonActorMagicCaster();			// 00666A00

	// @override class MagicCaster : (vtbl=010C99CC)
	//virtual ????   Unk_001(????) override;                           // 00666CE0
	//virtual ????   Unk_007(????) override;                           // 00666DA0
	//virtual UInt32 Unk_00B(void) override;                           // 006669A0 { return (UInt32)unk30; }
	//virtual ????   Unk_00C(????) override;                           // 00666EE0
	//virtual ????   Unk_00D(????) override;                           // 006669B0
	//virtual ????   Unk_00E(????) override;                           // 00666E70
	//virtual ????   Unk_018(????) override;                           // 00666F90
	//virtual ????   Unk_019(????) override;                           // 00666DC0
};
