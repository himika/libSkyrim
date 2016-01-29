#pragma once

#include "BaseFormComponent.h"

class TESObjectSTAT;

// 08
class BGSMenuDisplayObject : public BaseFormComponent
{
public:
	// @add
	virtual void *	GetMenuDisplayObject(void);			// 004F8CA0 { return worldStatic; }

	// @members
	TESObjectSTAT	* worldStatic;	// 04 - copyable
};

