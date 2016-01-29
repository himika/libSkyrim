#pragma once

#include "TESCameraState.h"
#include "../BSDevices/PlayerInputHandler.h"

class NiNode;

/*==============================================================================
class FirstPersonState +0000 (_vtbl=010E30C8)
0000: class FirstPersonState
0000: |   class TESCameraState
0004: |   |   struct BSIntrusiveRefCounted
0010: |   class PlayerInputHandler
==============================================================================*/
class FirstPersonState : public TESCameraState,
	public PlayerInputHandler					// 10
{
public:
	FirstPersonState();
	virtual ~FirstPersonState();					// 0083C070

	// @override class TESCameraState : (vtbl=010E30C8)
	virtual void OnStateStart() override;			// 008399B0
	virtual void OnStateEnd() override;				// 008399F0
	virtual void OnUpdate(void * unk1) override;	// 0083A240
	virtual void Unk_04() override;					// 00839F60
	virtual void Unk_05() override;					// 00839930
	virtual void Unk_06() override;					// 00839720
	virtual void Unk_07() override;					// 00839790
	virtual void Unk_08() override;					// 00839800

	// @override class PlayerInputHandler : (vtbl=010E30B0)
	virtual bool	CanProcess(InputEvent *evn) override;										// 00839DF0
	virtual void	ProcessButton(ButtonEvent *evn, PlayerControls::Data14 *arg2) override;		// 00839E50

	// @members
	NiNode					* cameraNode;		// 18
	NiNode					* controllerNode;	// 1C
	float					unk20;				// 20 (himika) rotZ ?
	float					unk24;				// 24
	float					unk28;				// 28
	UInt32					unk2C[0x03];		// 2C
	UInt8					unk38[0x05];		// 38
	UInt8					pad3D;				// 3D
	UInt16					pad3E;				// 3E
};
STATIC_ASSERT(sizeof(FirstPersonState) == 0x40);
