#pragma once

#include "../../../BSSystem/BSTSmartPointer.h"
#include "../../../BSPathFinding/IMovementControllerRegisterInterface.h"


/*==============================================================================
class MovementControllerAI +0000 (_vtbl=????????)
0000: class MovementControllerAI
0004: |   struct BSIntrusiveRefCounted
0000: |   class IMovementControllerRegisterInterface
==============================================================================*/

class MovementControllerAI :
	public BSIntrusiveRefCounted,					// 04
	public IMovementControllerRegisterInterface		// 00
{
};
