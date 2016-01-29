#pragma once

#include "BaseFormComponent.h"
#include "../BSCore/BSFixedString.h"

// 08
class TESFullName : public BaseFormComponent
{
public:
	virtual const char *	GetFullNameLength(void);
	virtual const char *	GetFullName(void);

	// void	**		_vtbl		// 00 0x01077604
	BSFixedString	fullName;	// 04
};

