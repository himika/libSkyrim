#pragma once

#include "NiTimeController.h"

class NiInterpolator;
class NiBlendInterpolator;

/*==============================================================================
class NiInterpController +0000 (_vtbl=0110F5D4)
0000: class NiInterpController
0000: |   class NiTimeController
0000: |   |   class NiObject
0000: |   |   |   class NiRefObject
==============================================================================*/
// 03C
class NiInterpController : public NiTimeController
{
public:
	enum { kRTTI = 0x01B904E0 };

	NiInterpController();
	~NiInterpController();

	// @add
	virtual UInt16					GetNumInterpolators(void) = 0;												// 2B
	virtual char *					GetInterpolatorName(UInt16 idx) = 0;										// 2C
	virtual SInt16					GetInterpolatorIdx(char * name) = 0;										// 2D
	virtual UInt16					Unk_2E(UInt32 arg) = 0;														// 2E
	virtual NiInterpolator *		GetInterpolator(UInt16 idx) = 0;											// 2F
	virtual void					SetInterpolator(NiInterpolator * _interpolator, UInt16 idx) = 0;			// 30
	virtual void					ResetTimeExtrema(void);														// 31 00A76270
	virtual char *					GetName(void);																// 32 00A76260 { return 0; }
	virtual NiInterpolator *		CreatePoseInterpolator(UInt16 idx) = 0;										// 33
	virtual void					SynchronizePoseInterpolator(NiInterpolator *interpolator, UInt16 idx) = 0;	// 34
	virtual NiBlendInterpolator *	CreateBlendInterpolator(UInt16 idx, bool, bool, float, UInt8) = 0;			// 35
	virtual void					GuaranteeTimeRange(float fStart, float fEnd) = 0;							// 36
	virtual void					InterpolatorIsCorrectType(NiInterpolator *interpolator, UInt16 idx) = 0;	// 37

	enum
	{
		kIsManagerControlled =	1 << 5,
	};

	// @members
	//void	** _vtbl;		// 00 - 0110F5D4
};
