#pragma once

#include "NiObjectNET.h"
#include "NiTypes.h"

NiSmartPointer(NiAVObject);

class NiProperty;
class BSFixedString;

/*==============================================================================
class NiAVObject +0000 (_vtbl=011172B4)
0000: class NiAVObject
0000: |   class NiObjectNET
0000: |   |   class NiObject
0000: |   |   |   class NiRefObject
==============================================================================*/
// A8
class NiAVObject : public NiObjectNET
{
public:
	enum { kRTTI = 0x01B91100 };

	enum
	{
		kFlag_SelectiveUpdate =				0x00000002,
		kFlag_UpdatePropertyControllers =	0x00000004,

		kFlag_SelectiveUpdateRigid =		0x00000010,

		kFlag_OverrideSelectiveTransforms =	0x00000080,
	};

	struct ControllerUpdateContext
	{
		enum
		{
			kDirty =	1 << 0,
		};

		float	delta;
		UInt8	flags;
	};

	virtual ~NiAVObject();													// 00AAFB90

	// @override
	virtual NiRTTI *	GetRTTI(void) const override;						// 02 00AAFB80 { return 0x01B91100; }
	virtual void		LoadBinary(NiStream * stream) override;				// 14 00AAF9E0
	virtual void		LinkObject(NiStream * stream) override;				// 15 00AAFA80
	virtual bool		RegisterStreamables(NiStream * stream) override;	// 16 00AAF700
	virtual void		SaveBinary(NiStream * stream) override;				// 17 00AAFAF0
	virtual bool		IsEqual(NiObject * object) override;				// 18 00AAF730
	virtual void		ProcessClone(NiCloningProcess * cloner) override;	// 19 00AAF6D0

	// @add
	virtual void	UpdateControllers(ControllerUpdateContext * ctx);								// 21 00AAF670 - calls controller vtbl+0x8C
	virtual void	UpdateNodeBound(ControllerUpdateContext * ctx);									// 22 00AAF3F0
	virtual void	ApplyTransform(NiMatrix3 * mtx, NiPoint3 * translate, bool postTransform);		// 23 00AAF410 { return; }
	virtual void	SetPropertyState(NiProperty * prop);											// 24 00588F30 { return; }
	virtual void	Unk_25(UInt32 arg0);															// 25 00AAF300 { return; }
	virtual void	Unk_26(UInt32 arg0);															// 26 00AAF310 { return; }
	virtual NiAVObject *	GetObjectByName(const BSFixedString & name);							// 27 00AAF450 - BSFixedString? alternatively BSFixedString is a typedef of a netimmerse type
	virtual void	SetSelectiveUpdateFlags(bool * selectiveUpdate, bool selectiveUpdateTransforms, bool * rigid);	// 28 00AAF8D0
	virtual void	UpdateDownwardPass(ControllerUpdateContext * ctx, UInt32 unk1);					// 29 00AAF4F0
	virtual void	UpdateSelectedDownwardPass(ControllerUpdateContext * ctx, UInt32 unk1);			// 2A 00AAF540
	virtual void	UpdateRigidDownwardPass(ControllerUpdateContext * ctx, UInt32 unk1);			// 2B 00AAF5E0
	virtual void	UpdateWorldBound(void);															// 2C 006C50E0 { return; }
	virtual void	UpdateWorldData(ControllerUpdateContext * ctx);									// 2D 00AB53E0
	virtual void	UpdateNoControllers(ControllerUpdateContext * ctx);								// 2E 00AAF380
	virtual void	UpdateDownwardPassTempParent(NiNode * parent, ControllerUpdateContext * ctx);	// 2F 00AAF3B0
	virtual void	Unk_30(void);																	// 30 00AAF3E0 - calls virtual function on parent
	virtual void	Unk_31(UInt32 arg0);															// 31 00AAF420 { return; }
	virtual void	Unk_32(UInt32 arg0);															// 32 00AAF4E0 { return; }


	const NiPoint3 & GetWorldTranslate() const {
		return m_worldTransform.pos;
	}
	const NiMatrix3 & GetWorldRotate() const {
		return m_worldTransform.rot;
	}
	const float GetWorldScale() const {
		return m_worldTransform.scale;
	}

	const NiPoint3 & GetLocalTranslate() const {
		return m_localTransform.pos;
	}
	const NiMatrix3 & GetLocalRotate() const {
		return m_localTransform.rot;
	}
	const float GetLocalScale() const {
		return m_localTransform.scale;
	}

	// @members
	NiNode		* m_parent;			// 18
	NiAVObject	* unk1C;			// 1C
	NiTransform	m_localTransform;	// 20
	NiTransform	m_worldTransform;	// 54
	float		unk88;				// 88
	float		unk8C;				// 8C
	float		unk90;				// 90
	float		unk94;				// 94
	UInt32		m_flags;			// 98 - bitfield
	float		unk9C;				// 9C
	UInt32		unkA0;				// A0
	UInt8		unkA4;				// A4
	UInt8		unkA5;				// A5 - bitfield

	DEFINE_MEMBER_FN(UpdateNode, void, 0x00AAF320, ControllerUpdateContext * ctx);
};
STATIC_ASSERT(sizeof(NiAVObject) == 0xA8);
