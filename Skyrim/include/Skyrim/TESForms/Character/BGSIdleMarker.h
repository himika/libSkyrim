#pragma once

#include "../../Forms/TESBoundObject.h"
#include "../../FormComponents/TESModel.h"
#include "../../FormComponents/BGSIdleCollection.h"

/*==============================================================================
class BGSIdleMarker +0000 (_vtbl=010A2FD4)
0000: class BGSIdleMarker
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESModel
0020: |   |   class BaseFormComponent
0034: |   class BGSIdleCollection
0034: |   |   class BaseFormComponent
==============================================================================*/
// 44
class BGSIdleMarker : public TESBoundObject,
	public TESModel,			// 20
	public BGSIdleCollection	// 34
{
public:
	enum { kTypeID = (UInt32)FormType::IdleMarker };
};
STATIC_ASSERT(sizeof(BGSIdleMarker) == 0x44);
