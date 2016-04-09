#pragma once

#include "BaseFormComponent.h"

class BGSSoundDescriptorForm;


/*==============================================================================
class BGSPickupPutdownSounds +0000 (_vtbl=0107C478)
0000: class BGSPickupPutdownSounds
0000: |   class BaseFormComponent
==============================================================================*/
// 0C
class BGSPickupPutdownSounds : public BaseFormComponent
{
public:
	// @members
	BGSSoundDescriptorForm	* pickUp;	// 04
	BGSSoundDescriptorForm	* putDown;	// 08
};
