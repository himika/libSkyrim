#pragma once

#include "TESBoundAnimObject.h"

class BGSSoundDescriptorForm;

/*==============================================================================
class TESSound +0000 (_vtbl=010A1834)
0000: class TESSound
0000: |   class TESBoundAnimObject
0000: |   |   class TESBoundObject
0000: |   |   |   class TESObject
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
==============================================================================*/
// 2C
class TESSound : public TESBoundAnimObject
{
public:
	enum { kTypeID = (UInt32)FormType::Sound };

	BGSSoundDescriptorForm	* descriptor;	// 20
};
