#include "Skyrim/Camera/PlayerCamera.h"
#include "Skyrim/Camera/ThirdPersonState.h"

#include "Skyrim/NetImmerse/NiNode.h"
#include "Skyrim/NetImmerse/NiCamera.h"
#include "Skyrim/NetImmerse/NiRTTI.h"

DECLARE_BSTSINGLETONSDM_STATIC_INSTANCE(PlayerCamera, 0x012E7288, 0x01B399A0);


void PlayerCamera::ForceFirstPersonSmooth(void)
{
	if (cameraState->stateId == kCameraState_ThirdPerson2)
	{
		ThirdPersonState* state = (ThirdPersonState*)cameraState;
		if (state->unkB5 == 0)
		{
			state->unk64 = state->curPosY;
			state->dstPosY = -0.2f;
			state->unkB5 = 1;
		}
		else
		{
			state->curPosY = state->dstPosY;
		}
	}
}

void PlayerCamera::ForceThirdPersonSmooth(void)
{
	if (cameraState == nullptr || cameraState->stateId < kCameraState_ThirdPerson2)
	{
		ThirdPersonState* tps = (ThirdPersonState*)cameraStates[kCameraState_ThirdPerson2];

		tps->basePosX = tps->fOverShoulderPosX;
		tps->basePosY = tps->fOverShoulderCombatAddY;
		tps->basePosZ = tps->fOverShoulderPosZ;
		tps->curPosY = -0.2f;
		tps->dstPosY = tps->unk64;

		SetCameraState(tps);
	}
}

bool PlayerCamera::WorldPtToScreenPt3(const NiPoint3 &in, float &x_out, float &y_out, float &z_out, float zeroTolerance)
{
	if (!cameraNode)
		return false;

	NiCamera *camera = GetNiCamera();
	if (!camera)
		return false;

	return camera->WorldPtToScreenPt3(in, x_out, y_out, z_out, zeroTolerance);
}


bool PlayerCamera::IsInScreen(float x, float y, float z) const
{
	static NiRect<float> kPort(0, 1, 0, 1);

	if (!cameraNode)
		return false;

	NiCamera *camera = GetNiCamera();
	if (!camera)
		return false;

	typedef bool(*_WorldPtToScreenPt3_Internal)(float * worldToCamMatrix, NiRect<float> * port, const NiPoint3 & in, float & x_out, float & y_out, float & z_out, float zeroTolerance);
	const _WorldPtToScreenPt3_Internal WorldPtToScreenPt3_Internal = (_WorldPtToScreenPt3_Internal)0x00AB84C0;

	float x_out, y_out, z_out;
	NiPoint3 in(x, y, z);
	if (!WorldPtToScreenPt3_Internal((float*)&camera->m_aafWorldToCam, &kPort, in, x_out, y_out, z_out, 1e-5f))
		return false;

	return (0.0f < x_out && x_out < 1.0f) && (0.0f < y_out && y_out < 1.0f);
}
