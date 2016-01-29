#pragma once

#include "BaseFormComponent.h"

class BGSSoundDescriptorForm;
class IngredientItem;

// 10?
class TESProduceForm : public BaseFormComponent
{
public:
	BGSSoundDescriptorForm	* harvestSound;	// 04
	IngredientItem			* produce;		// 08
	UInt8					unk0C[4];		// 0C
};
