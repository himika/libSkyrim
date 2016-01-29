#pragma once

#include "BaseFormComponent.h"

// 8
class TESAttackDamageForm : public BaseFormComponent
{
public:
	virtual UInt16	GetAttackDamage(void);

	UInt16	attackDamage;	// 04
	UInt8	pad06[2];		// 06
};
