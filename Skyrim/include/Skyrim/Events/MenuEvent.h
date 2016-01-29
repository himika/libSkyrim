#pragma once

#include "../BSCore/BSTEvent.h"
#include "../BSCore/BSFixedString.h"

// 08
class MenuOpenCloseEvent
{
public:
	BSFixedString	menuName;	// 00
	bool			opening;	// 04
	char			pad[3];
};

class MenuModeChangeEvent
{
};

class UserEventEnabledEvent
{
};
