#pragma once

#include "BaseFormComponent.h"

class BGSSoundDescriptorForm;

// 0C
class BGSPickupPutdownSounds : public BaseFormComponent
{
public:
	BGSSoundDescriptorForm	* pickUp;	// 04
	BGSSoundDescriptorForm	* putDown;	// 08
};
