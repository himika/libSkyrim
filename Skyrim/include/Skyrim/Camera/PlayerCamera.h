#pragma once

#include "TESCamera.h"
#include "../BSCore/BSTSingleton.h"
#include "FirstPersonState.h"
#include "ThirdPersonState.h"

/*==============================================================================
class PlayerCamera +0000 (_vtbl=010E3244)
0000: class PlayerCamera
0000: |   class TESCamera
0029: |   struct BSTSingletonSDM<class PlayerCamera,struct BSTSingletonSDMOpStaticBuffer>
0029: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class PlayerCamera,struct BSTSingletonSDMOpStaticBuffer<class PlayerCamera> > >
0029: |   |   |   struct BSTSDMTraits<class PlayerCamera,struct BSTSingletonSDMOpStaticBuffer<class PlayerCamera> >
002A: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class PlayerCamera>
==============================================================================*/
// D8
class PlayerCamera : public TESCamera,
	public BSTSingletonSDM<PlayerCamera>
{
public:
	enum
	{
		kCameraState_FirstPerson = 0,
		kCameraState_AutoVanity,
		kCameraState_VATS,
		kCameraState_Free,
		kCameraState_IronSights,
		kCameraState_Furniture,
		kCameraState_Transition,
		kCameraState_TweenMenu,
		kCameraState_ThirdPerson1,
		kCameraState_ThirdPerson2,
		kCameraState_Horse,
		kCameraState_Bleedout,
		kCameraState_Dragon,
		kNumCameraStates
	};

	PlayerCamera();
	virtual ~PlayerCamera();			// 0083E8B0

	// @override
	virtual void Update();				// 0083C0B0

	inline bool IsFirstPerson(void) const {
		return cameraState == cameraStates[kCameraState_FirstPerson];
	}
	inline bool IsThirdPerson(void) const {
		return cameraState == cameraStates[kCameraState_ThirdPerson2];
	}

	void ForceFirstPersonSmooth(void);
	void ForceThirdPersonSmooth(void);

	bool IsInScreen(float x, float y, float z) const;
	bool IsInScreen(const NiPoint3 &pt) const {
		return IsInScreen(pt.x, pt.y, pt.z);
	}

	bool WorldPtToScreenPt3(const NiPoint3 &in, float &x_out, float &y_out, float &z_out, float zeroTolerance = 1e-5f);

	DEFINE_MEMBER_FN(UpdateThirdPerson, void, 0x0083C7E0, bool weaponDrawn);
	DEFINE_MEMBER_FN(ToggleFlyCam, void, 0x0083E4C0, bool);

	// @members
	RefHandle		unk2C;										// 2C <-- [01310630] g_invalidRefHandle
	UInt32			unk34[(0x6C - 0x30) >> 2];					// 28
	TESCameraState	* cameraStates[kNumCameraStates];			// 6C
	UInt32			unkA0;										// A0
	UInt32			unkA4;										// A4
	UInt32			unkA8;										// A8
	float			worldFOV;									// AC
	float			firstPersonFOV;								// B0
	UInt32			padB4[(0xC4 - 0xB4) >> 2];					// B4
	float			unkC4;										// C4
	UInt32			padC8[(0xD0 - 0xC8) >> 2];					// C8
	bool			allowTogglePov;								// D0 allow switch pov
	bool			unkD1;										// D1 eagle eye related. reduce stamina while this is true
	UInt8			unkD2;										// D2
	UInt8			unkD3;										// D3
	UInt8			unkD4;										// D4
	UInt8			unkD5;										// D5
	UInt8			padD6[2];									// D6

private:
	friend struct BSTSingletonSDMBase<BSTSDMTraits<PlayerCamera>>;
	DEFINE_MEMBER_FN(ctor, PlayerCamera*, 0x0083E7B0);	// called from 0074E11E
	DEFINE_MEMBER_FN(dtor, void, 0x0083E2D0);
};
STATIC_ASSERT(offsetof(PlayerCamera, cameraStates) == 0x6C);
STATIC_ASSERT(offsetof(PlayerCamera, padD6) == 0xD6);
STATIC_ASSERT(sizeof(PlayerCamera) == 0xD8);


// ==== (himika) ====
class PlayerCameraAngleController
{
public:
	PlayerCameraAngleController() {}

	UInt32	unk00;		// 00 (01277C58)
	float	startRotZ;	// 04 (01277C5C)
	float	startRotX;	// 08 (01277C60)
	float	endRotZ;	// 0C (01277C64)
	float	endRotX;	// 10 (01277C68)
	UInt32	unk14;		// 14 (01277C6C)
	UInt32	unk18;		// 18 (01277C70)
	bool	disabled;	// 1C (01277C74)
	UInt8	pad1D[3];	// 1D (01277C75)

	static PlayerCameraAngleController* GetSingleton()
	{
		return (PlayerCameraAngleController*)0x01277C58;
	}

	DEFINE_MEMBER_FN(Rotate, void, 0x00736480, float startRotZ, float startRotX, float endRotZ, float endRotX, float fWait, float unk);

private:
	DEFINE_MEMBER_FN(DoRotate, void, 0x00738420, float arg1);	// arg1 = PlayerCamera::unkC4
};
