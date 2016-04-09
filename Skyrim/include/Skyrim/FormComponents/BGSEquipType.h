#pragma once

#include "BaseFormComponent.h"

class BGSEquipSlot;

/*==============================================================================
class BGSEquipType +0000 (_vtbl=0107C3A0)
0000: class BGSEquipType
0000: |   class BaseFormComponent
==============================================================================*/
// 08
class BGSEquipType : public BaseFormComponent
{
public:
	virtual ~BGSEquipType();									// 00457E70

	// @add
	virtual	BGSEquipSlot *	GetEquipSlot(void);					// 04 004F8CA0 { return unk04; }
	virtual void			SetEquipSlot(BGSEquipSlot * type);	// 05 00401AD0

	// @members
	BGSEquipSlot * unk04;	// 04
};
