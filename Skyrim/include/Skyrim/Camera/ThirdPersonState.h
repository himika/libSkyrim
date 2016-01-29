#pragma once

#include "TESCameraState.h"
#include "../BSDevices/PlayerInputHandler.h"

class NiNode;

/*==============================================================================
class ThirdPersonState +0000 (_vtbl=010E29EC)
0000: class ThirdPersonState
0000: |   class TESCameraState
0004: |   |   struct BSIntrusiveRefCounted
0010: |   class PlayerInputHandler
==============================================================================*/
class ThirdPersonState : public TESCameraState,
	public PlayerInputHandler					// 10
{
public:
	ThirdPersonState();
	virtual ~ThirdPersonState();
	virtual void Unk_09(void);
	virtual void Unk_0A(void);
	virtual void UpdateMode(bool weaponDrawn);

	NiNode					* cameraNode;		// 18
	NiNode					* controllerNode;	// 1C
	float					unk20[0x03];		// 20
	UInt32					unk2C[0x04];		// 2C
	float					fOverShoulderPosX;	// 3C
	float					fOverShoulderCombatAddY;	// 40
	float					fOverShoulderPosZ;	// 44
	float					basePosX;			// 48 | (himika)
	float					basePosY;			// 4C |
	float					basePosZ;			// 50 |
	float					dstPosY;			// 54 | destination
	float					curPosY;			// 58 | current position
	float					unk5C;				// 5C | player->rot.z + diffRotZ
	float					unk60;				// 60 | equal unk5C ?
	float					unk64;				// 64 | initial position 1st->3rd
	UInt32					pad68[(0xAC - 0x68) >> 2];
	float					diffRotZ;			// AC | diff from player rotZ
	float					diffRotX;			// B0 | diff from player rotX
	bool					unkB4;				// B4 | weapon sheathed
	bool					unkB5;				// B5 | auto switch 1st-person camera when dstPosY==curPosY
	UInt8					unkB6;
	UInt8					unkB7;
	UInt8					unkB8;
	UInt8					unkB9;
	UInt8					unkBA;
	UInt8					unkBB;
};
STATIC_ASSERT(offsetof(ThirdPersonState, fOverShoulderPosX) == 0x3C);
STATIC_ASSERT(offsetof(ThirdPersonState, basePosX) == 0x48);
