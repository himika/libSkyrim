#pragma once

#include "TESBoundObject.h"
#include "../../FormComponents/TESLeveledList.h"


/*==============================================================================
class TESLevSpell +0000 (_vtbl=010836E4)
0000: class TESLevSpell
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESLeveledList
0020: |   |   class BaseFormComponent
==============================================================================*/
// 34
class TESLevSpell : public TESBoundObject,
	public TESLeveledList			// 20
{
public:
	enum { kTypeID = (UInt32)FormType::LeveledSpell };
};
STATIC_ASSERT(sizeof(TESLevSpell) == 0x34);
