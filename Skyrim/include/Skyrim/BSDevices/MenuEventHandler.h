#pragma once

#include "../BSSystem/BSTSmartPointer.h"
#include "../Events/InputEvent.h"

/*==============================================================================
class MenuEventHandler +0000 (_vtbl=010E4B9C)
0000: class MenuEventHandler
0004: |   struct BSIntrusiveRefCounted
==============================================================================*/
class MenuEventHandler : public BSIntrusiveRefCounted
{
public:
	MenuEventHandler();
	virtual ~MenuEventHandler();									// 00877F50

	virtual bool	CanProcess(InputEvent *evn) = 0;				// 01 00F51EE8 (pure) - called from 00877EC2
	virtual bool	ProcessKinect(KinectEvent *evn);				// 02 004091A0 (UInt32 arg) { return false; }
	virtual bool	ProcessThumbstick(ThumbstickEvent *evn);		// 03 004091A0 (UInt32 arg) { return false; }
	virtual bool	ProcessMouseMove(MouseMoveEvent *evn);			// 04 004091A0 (UInt32 arg) { return false; }
	virtual bool	ProcessButton(ButtonEvent *evn);				// 05 004091A0 (UInt32 arg) { return false; }

	// @members
	//void	** _vtbl;		// 00 - 010E4B9C
	//long	RefCount;		// 04
	UInt8	unk08;			// 08 - This appears to be 1 when a menu is open
	UInt8	unk09;
	UInt8	pad0A[2];
};
