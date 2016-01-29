#pragma once

/**** controllers
*	NiTimeController
*		BSDoorHavokController
*		BSPlayerDistanceCheckController
*		NiD3DController
*		NiControllerManager
*		NiInterpController
*			NiSingleInterpController
*				NiTransformController
*				NiPSysModifierCtlr
*					NiPSysEmitterCtlr
*					NiPSysModifierBoolCtlr
*						NiPSysModifierActiveCtlr
*					NiPSysModifierFloatCtlr
*						NiPSysInitialRotSpeedVarCtlr
*						NiPSysInitialRotSpeedCtlr
*						NiPSysInitialRotAngleVarCtlr
*						NiPSysInitialRotAngleCtlr
*						NiPSysGravityStrengthCtlr
*						NiPSysFieldMaxDistanceCtlr
*						NiPSysFieldMagnitudeCtlr
*						NiPSysFieldAttenuationCtlr
*						NiPSysEmitterSpeedCtlr
*						NiPSysEmitterPlanarAngleVarCtlr
*						NiPSysEmitterPlanarAngleCtlr
*						NiPSysEmitterLifeSpanCtlr
*						NiPSysEmitterInitialRadiusCtlr
*						NiPSysEmitterDeclinationVarCtlr
*						NiPSysEmitterDeclinationCtlr
*						NiPSysAirFieldSpreadCtlr
*						NiPSysAirFieldInheritVelocityCtlr
*						NiPSysAirFieldAirFrictionCtlr
*				NiFloatInterpController
*					NiFlipController
*					NiAlphaController
*					NiTextureTransformController
*					NiLightDimmerController
*				NiBoolInterpController
*					NiVisController
*				NiPoint3InterpController
*					NiMaterialColorController
*					NiLightColorController
*				NiExtraDataController
*					NiFloatsExtraDataPoint3Controller
*					NiFloatsExtraDataController
*					NiFloatExtraDataController
*					NiColorExtraDataController
*			NiMultiTargetTransformController
*			NiGeomMorpherController
*		bhkBlendController
*		bhkForceController
*		NiBSBoneLODController
*		NiUVController
*		NiPathController
*		NiLookAtController
*		NiKeyframeManager
*		NiBoneLODController
*		NiPSysUpdateCtlr
*		NiPSysResetOnLoopCtlr
*		NiFloatController
*			NiRollController
*/


#include "NiObject.h"

class NiObjectNET;

/*==============================================================================
class NiTimeController +0000 (_vtbl=011187CC)
0000: class NiTimeController
0000: |   class NiObject
0000: |   |   class NiRefObject
==============================================================================*/
// 034
class NiTimeController : public NiObject
{
public:
	enum { kRTTI = 0x01B92508 };

	NiTimeController();
	~NiTimeController();

	// @add
	virtual void		Start(float time);						// 21 00ABF5F0
	virtual void		Stop(void);								// 22 00ABF610
	virtual void		Update(float time) = 0;					// 23 
	virtual void		SetTarget(NiObjectNET * node);			// 24 00ABFBA0
	virtual bool		IsTransformController(void) const;		// 25 0092D110 { return false; }
	virtual bool		IsVertexController(void) const;			// 26 0092D110 { return false; }
	virtual float		ComputeScaledTime(float time);			// 27 00ABF6E0
	virtual void		OnPreDisplay(void);						// 28 00ABF640 { return; }
	virtual bool		IsStreamable(void) const;				// 29 009B86F0 { return true; }
	virtual bool		TargetIsRequiredType(void) const = 0;	// 2A for debugging purpose?
																//    0072FB70 BSPlayerDistanceCheckController, BSSimpleScaleController
																//    00A6BA80 NiControllerManager
	inline NiTimeController*	GetNext() const {
		return (NiTimeController*)next;
	}

	enum
	{
		kAnimType_AppTime =		0 << 0,
		kAnimType_AppInit =		1 << 0,

		kCycleType_Loop =		0 << 1,
		kCycleType_Reverse =	1 << 1,
		kCycleType_Clamp =		2 << 1,

		kActive =				1 << 3,
		
		kPlayBackwards =		1 << 4,
	};

	// @members
	//void				** _vtbl;		// 000 - 011187CC
	UInt16				flags;			// 008
	UInt8				pad00A[2];		// 00A
	float				m_fFrequency;	// 00C - 1.0
	float				m_fPhase;		// 010 - 0.0
	float				m_fLoKeyTime;	// 014 - 3.402823e+38
	float				m_fHiKeyTime;	// 018
	float				m_fStartTime;	// 01C
	float				m_fLastTime;	// 020 - -3.402823e+38
	float				unk024;			// 024 - -3.402823e+38 - updated in Unk_19
	float				unk028;			// 028
	UInt8				unk02C;			// 02C
	UInt8				pad02D[3];		// 02D
	NiObjectNET			* next;			// 030 - singly linked list of controllers
};
STATIC_ASSERT(sizeof(NiTimeController) == 0x34);