#pragma once

#include "../../../BSSystem/BSTSmartPointer.h"
#include "../../../BSPathFinding/IMovementControllerRegisterInterface.h"


/*==============================================================================
class MovementControllerAI +0000 (_vtbl=????????)
0000: class MovementControllerAI
0004: |   struct BSIntrusiveRefCounted
0000: |   class IMovementControllerRegisterInterface
==============================================================================*/

class MovementControllerAI :
	public BSIntrusiveRefCounted,					// 04
	public IMovementControllerRegisterInterface		// 00
{
public:
	virtual ~MovementControllerAI();

	//virtual ????   Unk_000(????);                                    // 00767380
	//virtual ????   Unk_001(????);                                    // 00B70390
	//virtual ????   Unk_002(????);                                    // 00B70190
	//virtual ????   Unk_003(????);                                    // 00B70140
	//virtual ????   Unk_004(????);                                    // 00B703F0
	//virtual ????   Unk_005(????);                                    // 00B703B0
	//virtual ????   Unk_006(????);                                    // 00766140
	//virtual ????   Unk_007(????);                                    // 00B70A80
	//virtual ????   Unk_008(????);                                    // 00B70C30
	//virtual bool   Unk_009(void);                                    // 009B86F0 { return true; }
	//virtual ????   Unk_00A(????);                                    // 00763D20
	//virtual ????   Unk_00B(????);                                    // 00763D80
	//virtual ????   Unk_00C(????);                                    // 00763E50
	//virtual ????   Unk_00D(????);                                    // 00763EC0
	//virtual ????   Unk_00E(????);                                    // 00763B80
	//virtual UInt8  Unk_00F(void);                                    // 00763B90 { return (UInt8)unkE9; }
	//virtual ????   Unk_010(????);                                    // 00764CD0
	//virtual ????   Unk_011(????);                                    // 00763DE0
	//virtual ????   Unk_012(????);                                    // 00766910
	//virtual ????   Unk_013(????);                                    // 00767970
	//virtual ????   Unk_014(????);                                    // 007647D0

};
