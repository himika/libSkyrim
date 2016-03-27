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
	virtual float	GetActorValueCurrent(UInt32 arg);								// 01 0055FF50 { return 0.0f; }
	virtual float	GetActorValueMaximum(UInt32 arg);								// 02 0055FF50 { return 0.0f; }
	virtual float	GetActorValueBase(UInt32 arg);									// 03 0055FF50 { return 0.0f; }
	virtual void	SetActorValueBase(UInt32 arg0, float arg1);						// 04 004D43E0 { return; }
	virtual void	ModActorValueBase(UInt32 arg0, float arg1);						// 05 004D43E0 { return; }
	virtual void	ActorValueOwner_Unk_06(UInt32 arg0, UInt32 arg1, UInt32 arg2);	// 06 00D62BE0 { return; } Force/Mod AV?
	virtual void	SetActorValueCurrent(UInt32 arg0, float arg1);					// 07 00560330
	virtual bool	ActorValueOwner_Unk_08(void);									// 08 0092D110 { return false; } PlayerCarachter={ return true; }

	//	void	** _vtbl;	// 00
};
STATIC_ASSERT(sizeof(ActorValueOwner) == 0x04);
