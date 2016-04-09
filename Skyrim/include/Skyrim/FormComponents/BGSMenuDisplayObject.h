#pragma once

#include "BaseFormComponent.h"

class TESObjectSTAT;


/*==============================================================================
class BGSMenuDisplayObject +0000 (_vtbl=0107C3EC)
0000: class BGSMenuDisplayObject
0000: |   class BaseFormComponent
==============================================================================*/
// 08
class BGSMenuDisplayObject : public BaseFormComponent
{
public:
	// @add
	virtual void *	GetMenuDisplayObject(void);			// 004F8CA0 { return worldStatic; }

	// @members
	TESObjectSTAT	* worldStatic;	// 04 - copyable

private:
	DEFINE_MEMBER_FN(ctor, BGSMenuDisplayObject *, 0x0044B660);
};
