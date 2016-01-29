#include "Skyrim/Camera/TESCamera.h"

#include "Skyrim/NetImmerse/NiNode.h"
#include "Skyrim/NetImmerse/NiCamera.h"
#include "Skyrim/NetImmerse/NiRTTI.h"

NiCamera * TESCamera::GetNiCamera() const
{
	NiCamera *camera = nullptr;
	std::size_t size = cameraNode->GetArrayCount();
	for (std::size_t i = 0; i < size; ++i)
	{
		NiAVObject* pObj = cameraNode->GetAt(i);
		if (!pObj)
			continue;

		if (pObj->GetRTTI() == NiRTTI_NiCamera) {
			camera = (NiCamera*)pObj;
			break;
		}

	}
	return camera;
}
