#pragma once

#include "TESBoundObject.h"

/*==============================================================================
class TESBoundAnimObject +0000 (_vtbl=01083FC4)
0000: class TESBoundAnimObject
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
==============================================================================*/
// 20
class TESBoundAnimObject : public TESBoundObject
{
public:
	// @override
	virtual bool	CanAnimate(void) override;		// 54 0092D110 { return true; }

	// @members
	// void **	_vtbl	// 00   01083FC4
};
