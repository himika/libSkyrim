#pragma once

#include "BaseFormComponent.h"

class BGSEquipSlot;

// 08
class BGSEquipType : public BaseFormComponent
{
public:
	virtual ~BGSEquipType();									// 00457E70
	// @add
	virtual	BGSEquipSlot *	GetEquipSlot(void);					// 004F8CA0 { return unk04; }
	virtual void			SetEquipSlot(BGSEquipSlot * type);	// 00401AD0

	BGSEquipSlot * unk04;	// 04
};
