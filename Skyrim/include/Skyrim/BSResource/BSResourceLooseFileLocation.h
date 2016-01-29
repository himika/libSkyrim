#pragma once

#include "BSResourceLocation.h"

/*==============================================================================
class BSResource::LooseFileLocation +0000 (_vtbl=0107D6AC)
0000: class BSResource::LooseFileLocation
0000: |   class BSResource::Location
==============================================================================*/
	//// @override class BSResource::Location : (vtbl=0107D6AC)
	//virtual ????   Unk_000(????) override;                           // 00461580
	//virtual ????   Unk_003(????) override;                           // 00A43250
	//virtual ????   Unk_004(????) override;                           // 00A432B0
	//virtual ????   Unk_005(????) override;                           // 00A42AE0
	//virtual ????   Unk_006(????) override;                           // 00A42CE0
	//virtual ????   Unk_007(????) override;                           // 00A42BB0
	//virtual ????   Unk_008(????) override;                           // 00A42D10
	//virtual UInt32 Unk_009(void) override;                           // 00A42DD0 { return (UInt32)unk8; }
	//virtual UInt32 Unk_00B(void) override;                           // 00A424D0 { return (UInt32)unkC; }

namespace BSResource
{
	class LooseFileLocation : public Location
	{
	public:
		virtual ~LooseFileLocation();
	};
}
