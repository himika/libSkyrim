#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../BSCore/BSTArray.h"

/*==============================================================================
class BGSEquipSlot +0000 (_vtbl=010A2D0C)
0000: class BGSEquipSlot
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 24
class BGSEquipSlot : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::EquipSlot };

	// @members
	BSTArray<BGSEquipSlot *>	parentSlots;
	UInt32						unk20;
};
STATIC_ASSERT(sizeof(BGSEquipSlot) == 0x24);


typedef BGSEquipSlot * (*_GetEitherHandSlot)();
extern const _GetEitherHandSlot GetEitherHandSlot;

typedef BGSEquipSlot * (*_GetRightHandSlot)();
extern const _GetRightHandSlot GetRightHandSlot;

typedef BGSEquipSlot * (*_GetLeftHandSlot)();
extern const _GetLeftHandSlot GetLeftHandSlot;
