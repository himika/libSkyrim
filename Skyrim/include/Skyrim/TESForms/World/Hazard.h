#pragma once

#include "TESObjectREFR.h"

/*==============================================================================
class Hazard +0000 (_vtbl=010D89CC)
0000: class Hazard
0000: |   class TESObjectREFR
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
0014: |   |   class BSHandleRefObject
0014: |   |   |   class NiRefObject
001C: |   |   class BSTEventSink<struct BSAnimationGraphEvent>
0020: |   |   class IAnimationGraphManagerHolder
==============================================================================*/
// 88
class Hazard : public TESObjectREFR
{
	enum { kTypeID = (UInt32)FormType::Hazard };

	// @add
	virtual void Unk_0A2(void);		// 00795AB0
	virtual void Unk_0A3(void);		// 006C50E0 (void) { return; }
	virtual void Unk_0A4(void);		// 0079E450
};
