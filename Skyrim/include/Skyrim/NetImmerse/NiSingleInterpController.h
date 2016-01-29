#pragma once

#include "NiInterpController.h"

/*==============================================================================
class NiSingleInterpController +0000 (_vtbl=011102C4)
0000: class NiSingleInterpController
0000: |   class NiInterpController
0000: |   |   class NiTimeController
0000: |   |   |   class NiObject
0000: |   |   |   |   class NiRefObject
==============================================================================*/
// 040
class NiSingleInterpController : public NiInterpController
{
public:
	enum { kRTTI = 0x01B90C5C };

	NiSingleInterpController();
	~NiSingleInterpController();

	// @add
	virtual bool	Unk_38(void * arg) = 0;

	NiInterpolator	* interpolator;	// 03C
};

