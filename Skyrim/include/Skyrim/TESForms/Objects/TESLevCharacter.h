#pragma once

#include "TESBoundAnimObject.h"
#include "../../FormComponents/TESLeveledList.h"
#include "../../FormComponents/TESModelTextureSwap.h"

/*==============================================================================
class TESLevCharacter +0000 (_vtbl=0108331C)
0000: class TESLevCharacter
0000: |   class TESBoundAnimObject
0000: |   |   class TESBoundObject
0000: |   |   |   class TESObject
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
0020: |   class TESLeveledList
0020: |   |   class BaseFormComponent
0034: |   class TESModelTextureSwap
0034: |   |   class TESModel
0034: |   |   |   class BaseFormComponent
==============================================================================*/
// 50
class TESLevCharacter : public TESBoundAnimObject,
	public TESLeveledList,		// 20
	public TESModelTextureSwap	// 34
{
public:
	enum { kTypeID = (UInt32)FormType::LeveledCharacter };
};
