#pragma once

#include "BaseFormComponent.h"

/*==============================================================================
class ActorValueOwner +0000 (_vtbl=010A5400)
0000: class ActorValueOwner
==============================================================================*/
// 04
class ActorValueOwner
{
public:
	virtual ~ActorValueOwner();											// 0055FF60

	// Argument is the ActorValue ID
	virtual float	GetCurrent(UInt32 arg);								// 0055FF50 { return 0.0f; }
	virtual float	GetMaximum(UInt32 arg);								// 0055FF50 { return 0.0f; }
	virtual float	GetBase(UInt32 arg);								// 0055FF50 { return 0.0f; }
	virtual void	SetBase(UInt32 arg0, float arg1);					// 004D43E0 { return; }
	virtual void	ModBase(UInt32 arg0, float arg1);					// 004D43E0 { return; }
	virtual void	Unk_06(UInt32 arg0, UInt32 arg1, UInt32 arg2);		// 00D62BE0 { return; } Force/Mod AV?
	virtual void	SetCurrent(UInt32 arg0, float arg1);				// 00560330
	virtual bool	ActorValueOwner_Unk_08(void);						// 0092D110 { return false; } PlayerCarachter={ return true; }

	//	void	** _vtbl;	// 00
};
STATIC_ASSERT(sizeof(ActorValueOwner) == 0x04);
