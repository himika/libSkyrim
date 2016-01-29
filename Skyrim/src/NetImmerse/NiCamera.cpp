#include "Skyrim/NetImmerse/NiCamera.h"


float &g_worldToCamMatrix = *(float*)0x001B3EA10;
NiRect<float> &g_viewPort = *(NiRect<float> *)0x001B3EA74;


bool NiCamera::WorldPtToScreenPt3(const NiPoint3 & in, float &x_out, float &y_out, float &z_out, float zeroTolerance) const
{
	typedef bool(*_WorldPtToScreenPt3_Internal)(const float * worldToCamMatrix, const NiRect<float> * port, const NiPoint3 & in, float & x_out, float & y_out, float & z_out, float zeroTolerance);
	const _WorldPtToScreenPt3_Internal WorldPtToScreenPt3_Internal = (_WorldPtToScreenPt3_Internal)0x00AB84C0;

	return WorldPtToScreenPt3_Internal((float*)&this->m_aafWorldToCam, &this->m_kPort, in, x_out, y_out, z_out, zeroTolerance);
}
