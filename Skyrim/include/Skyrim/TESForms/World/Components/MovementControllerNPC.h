#pragma once

#include "MovementControllerAI.h"
#include "../../../BSPathFinding/IMovementInterface.h"
#include "../../../Animation/IAnimationSetCallbackFunctor.h"


class IMovementMessageInterface;
class IMovementMotionDrivenControl;
class IMovementSelectIdle;
class IMovementDirectControl;
class IMovementPlannerDirectControl;

/*==============================================================================
class IMovementMessageInterface +0000 (_vtbl=010D3680)
0000: class IMovementMessageInterface
0000: |   struct IMovementInterface
==============================================================================*/
class IMovementMessageInterface : public IMovementInterface
{
};
	// @override struct IMovementInterface : (vtbl=010D3680)
	//virtual ????   Unk_000(????) override;                           // 00763C30
	// @add
	//virtual ????   Unk_001(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_002(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_003(????);                                    // 00F51EE8 (pure)

/*==============================================================================
class IMovementDirectControl +0000 (_vtbl=010D3694)
0000: class IMovementDirectControl
0000: |   struct IMovementInterface
==============================================================================*/
class IMovementDirectControl : public IMovementInterface
{
};
// @override struct IMovementInterface : (vtbl=010D3694)
	//virtual ????   Unk_000(????) override;                           // 00763C60
	// @add
	//virtual ????   Unk_001(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_002(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_003(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_004(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_005(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_006(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_007(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_008(????);                                    // 00F51EE8 (pure)

/*==============================================================================
class IMovementPlannerDirectControl +0000 (_vtbl=010D36BC)
0000: class IMovementPlannerDirectControl
0000: |   struct IMovementInterface
==============================================================================*/
class IMovementPlannerDirectControl : public IMovementInterface
{
};
// @override struct IMovementInterface : (vtbl=010D36BC)
	//virtual ????   Unk_000(????) override;                           // 00763C90
	// @add
	//virtual ????   Unk_001(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_002(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_003(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_004(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_005(????);                                    // 00F51EE8 (pure)

/*==============================================================================
class IMovementSelectIdle +0000 (_vtbl=010D36D8)
0000: class IMovementSelectIdle
0000: |   struct IMovementInterface
==============================================================================*/
class IMovementSelectIdle : public IMovementInterface
{
};
// @override struct IMovementInterface : (vtbl=010D36D8)
	//virtual ????   Unk_000(????) override;                           // 00763CC0
	// @add
	//virtual ????   Unk_001(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_002(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_003(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_004(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_005(????);                                    // 00F51EE8 (pure)

/*==============================================================================
class IMovementMotionDrivenControl +0000 (_vtbl=010D36F4)
0000: class IMovementMotionDrivenControl
0000: |   struct IMovementInterface
==============================================================================*/
class IMovementMotionDrivenControl : public IMovementInterface
{
};
// @override struct IMovementInterface : (vtbl=010D36F4)
	//virtual ????   Unk_000(????) override;                           // 00763CF0
	// @add
	//virtual ????   Unk_001(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_002(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_003(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_004(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_005(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_006(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_007(????);                                    // 00F51EE8 (pure)
	//virtual ????   Unk_008(????);                                    // 00F51EE8 (pure)



/*==============================================================================
class MovementControllerNPC +0000 (_vtbl=010D37DC)
0000: class MovementControllerNPC
0000: |   class MovementControllerAI
0004: |   |   struct BSIntrusiveRefCounted
0000: |   |   class IMovementControllerRegisterInterface
008C: |   class IMovementMessageInterface
008C: |   |   struct IMovementInterface
0090: |   class IMovementMotionDrivenControl
0090: |   |   struct IMovementInterface
0094: |   class IMovementSelectIdle
0094: |   |   struct IMovementInterface
0098: |   class IMovementDirectControl
0098: |   |   struct IMovementInterface
009C: |   class IMovementPlannerDirectControl
009C: |   |   struct IMovementInterface
00A0: |   class IAnimationSetCallbackFunctor
==============================================================================*/
class MovementControllerNPC :
	public MovementControllerAI,
	public IMovementMessageInterface,
	public IMovementMotionDrivenControl,
	public IMovementSelectIdle,
	public IMovementDirectControl,
	public IMovementPlannerDirectControl,
	public IAnimationSetCallbackFunctor
{
public:
	virtual ~MovementControllerNPC();				// 00767380

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
	//// @override class IMovementMessageInterface : (vtbl=010D37C8)
	//virtual ????   Unk_001(????) override;                           // 00765D40
	//virtual ????   Unk_002(????) override;                           // 00765DC0
	//virtual ????   Unk_003(????) override;                           // 00764830
	//// @override class IMovementMotionDrivenControl : (vtbl=010D37A0)
	//virtual ????   Unk_001(????) override;                           // 00764270
	//virtual ????   Unk_002(????) override;                           // 007642C0
	//virtual ????   Unk_003(????) override;                           // 00764C90
	//virtual ????   Unk_004(????) override;                           // 00764B10
	//virtual ????   Unk_005(????) override;                           // 00764D20
	//virtual ????   Unk_006(????) override;                           // 00763AF0
	//virtual ????   Unk_007(????) override;                           // 00763B30
	//virtual ????   Unk_008(????) override;                           // 00763B50
	//// @override class IMovementSelectIdle : (vtbl=010D3784)
	//virtual ????   Unk_001(????) override;                           // 007664F0
	//virtual ????   Unk_002(????) override;                           // 00765AA0
	//virtual ????   Unk_003(????) override;                           // 007659F0
	//virtual ????   Unk_004(????) override;                           // 00766F50
	//virtual ????   Unk_005(????) override;                           // 00763B70
	//// @override class IMovementDirectControl : (vtbl=010D375C)
	//virtual ????   Unk_001(????) override;                           // 00763FC0
	//virtual ????   Unk_002(????) override;                           // 00764EE0
	//virtual ????   Unk_003(????) override;                           // 00764F50
	//virtual ????   Unk_004(????) override;                           // 00764FC0
	//virtual ????   Unk_005(????) override;                           // 00765030
	//virtual ????   Unk_006(????) override;                           // 007650A0
	//virtual ????   Unk_007(????) override;                           // 00765110
	//virtual ????   Unk_008(????) override;                           // 00765180
	//// @override class IMovementPlannerDirectControl : (vtbl=010D3740)
	//virtual ????   Unk_001(????) override;                           // 00763FE0
	//virtual ????   Unk_002(????) override;                           // 007651F0
	//virtual ????   Unk_003(????) override;                           // 00765260
	//virtual ????   Unk_004(????) override;                           // 007652D0
	//virtual ????   Unk_005(????) override;                           // 00765340
	//// @override class IAnimationSetCallbackFunctor : (vtbl=010D3734)
	//virtual ????   Unk_001(????) override;                           // 007653B0
};
