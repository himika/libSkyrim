#pragma once

#include "NiAVObject.h"

extern float &g_worldToCamMatrix;
extern NiRect<float> &g_viewPort;


/*==============================================================================
class NiCamera +0000 (_vtbl=01117CFC)
0000: class NiCamera
0000: |   class NiAVObject
0000: |   |   class NiObjectNET
0000: |   |   |   class NiObject
0000: |   |   |   |   class NiRefObject
==============================================================================*/
class NiCamera : public NiAVObject
{
public:
	enum { kRTTI = 0x01B91420 };

	virtual ~NiCamera();			// 00AB98A0

	// @override
	virtual NiRTTI *	GetRTTI(void) const override;								// 02 00AB9890 { return 0x01B91420; }
	virtual NiObject *	CreateClone(NiCloningProcess cloner) override;				// 13 00AB9250
	virtual void		LoadBinary(NiStream * stream) override;						// 14 00AB9410
	virtual void		LinkObject(NiStream * stream) override;						// 15 00AB9330
	virtual bool		RegisterStreamables(NiStream * stream) override;			// 16 00AB89F0
	virtual void		SaveBinary(NiStream * stream) override;						// 17 00AB9630
	virtual bool		IsEqual(NiObject * object) override;						// 18 00AB8A00
	virtual void		UpdateWorldBound(void) override;							// 2C 00AB8620
	virtual void		UpdateWorldData(ControllerUpdateContext * ctx) override;	// 2D 00AB8F30

	// 00AB85E0
	bool WorldPtToScreenPt3(const NiPoint3 &in, float &x_out, float &y_out, float &z_out, float zeroTolerance = 1e-5f) const;

	bool WorldPtToScreenPt3(const NiPoint3 &in, NiPoint3 &out, float zeroTolerance = 1e-5f) const {
		return WorldPtToScreenPt3(in, out.x, out.y, out.z, zeroTolerance);
	}

	
	// @members
	//void			** _vtbl;				// 00 - 01117CFC
	float			m_aafWorldToCam[4][4];	// A8
	NiFrustum		m_frustum;				// E8
	float			m_fMinNearPlaneDist;	// 104
	float			m_fMaxFarNearRatio;		// 108
	NiRect<float>	m_kPort;				// 10C - The viewport, which is contained in the unit square [0,1]^2.
	float			m_fLODAdjust;			// 11C
};
STATIC_ASSERT(offsetof(NiCamera, m_frustum) == 0xE8);
STATIC_ASSERT(offsetof(NiCamera, m_fLODAdjust) == 0x11C);
