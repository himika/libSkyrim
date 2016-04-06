#pragma once

#include "TESBoundObject.h"
#include "../../FormComponents/TESModelTextureSwap.h"


/*==============================================================================
class BGSStaticCollection +0000 (_vtbl=01081DD4)
0000: class BGSStaticCollection
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESModelTextureSwap
0020: |   |   class TESModel
0020: |   |   |   class BaseFormComponent
==============================================================================*/
// 3C
class BGSStaticCollection : public TESBoundObject,
	public TESModelTextureSwap		// 20
{
public:
	enum { kTypeID = (UInt32)FormType::StaticCollection };

};
STATIC_ASSERT(sizeof(BGSStaticCollection) == 0x3C);
