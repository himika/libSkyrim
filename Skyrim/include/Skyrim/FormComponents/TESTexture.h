#pragma once

#include "BaseFormComponent.h"
#include "../BSCore/BSFixedString.h"

class BSString;

// 08
class TESTexture : public BaseFormComponent
{
public:
	// @add
	virtual UInt32			TESTexture_Unk_04(void);			// 005EADD0 { return 0; }
	virtual void			GetNormalMapName(BSString * out);	// 00457C40 might have const char * retn type
	virtual const char *	GetSearchDir(void);					// 00457980 { return "Texture\\"; }

	BSFixedString	str;	// 04
};
