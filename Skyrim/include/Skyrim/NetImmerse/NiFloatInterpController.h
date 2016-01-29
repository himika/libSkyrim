#pragma once

#include "NiSingleInterpController.h"

/*==============================================================================
class NiFloatInterpController +0000 (_vtbl=01116C9C)
0000: class NiFloatInterpController
0000: |   class NiSingleInterpController
0000: |   |   class NiInterpController
0000: |   |   |   class NiTimeController
0000: |   |   |   |   class NiObject
0000: |   |   |   |   |   class NiRefObject
==============================================================================*/
// 040
class NiFloatInterpController : public NiSingleInterpController
{
public:
	enum { kRTTI = 0x01B9107C };

	NiFloatInterpController();
	~NiFloatInterpController();

	// @add
	virtual void	Unk_39(float * out) = 0;
};
