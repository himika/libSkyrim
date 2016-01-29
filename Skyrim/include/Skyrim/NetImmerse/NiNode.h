#pragma once

#include "NiAVObject.h"
#include "NiTArray.h"

/*==============================================================================
class NiNode +0000 (_vtbl=011171A4)
0000: class NiNode
0000: |   class NiAVObject
0000: |   |   class NiObjectNET
0000: |   |   |   class NiObject
0000: |   |   |   |   class NiRefObject
==============================================================================*/
// B8
class NiNode : public NiAVObject
{
public:
	enum { kRTTI = 0x01B910F0 };

	virtual ~NiNode();		// 00AAF280

	// @override
	virtual NiRTTI *		GetRTTI(void) const override;															// 02 00AAF240 { return 0x01B910F0; }
	virtual NiNode *		GetAsNiNode(void) override;																// 03 00C707B0 { return this; }
	virtual NiObject *		CreateClone(NiCloningProcess cloner) override;											// 13 00AAED30
	virtual void			LoadBinary(NiStream * stream) override;													// 14 00AAE220
	virtual void			LinkObject(NiStream * stream) override;													// 15 00AAEC90
	virtual bool			RegisterStreamables(NiStream * stream) override;										// 16 00AAE250
	virtual void			SaveBinary(NiStream * stream) override;													// 17 00AAE680
	virtual bool			IsEqual(NiObject * object) override;													// 18 00AAE2A0
	virtual void			ProcessClone(NiCloningProcess * cloner) override;										// 19 00AAEDD0
	virtual void			UpdateControllers(ControllerUpdateContext * ctx) override;								// 21 00AADEF0
	virtual void			UpdateNodeBound(ControllerUpdateContext * ctx) override;								// 22 00AAE330
	virtual void			ApplyTransform(NiMatrix3 * mtx, NiPoint3 * translate, bool postTransform) override;		// 23 00AAE4D0
	virtual void			SetPropertyState(NiProperty * prop) override;											// 24 00AAE390
	virtual NiAVObject *	GetObjectByName(const BSFixedString & name) override;									// 27 00AAE1D0
	virtual void			SetSelectiveUpdateFlags(bool * selectiveUpdate, bool selectiveUpdateTransforms, bool * rigid) override;	// 28 00AAE020
	virtual void			UpdateDownwardPass(ControllerUpdateContext * ctx, UInt32 unk1) override;				// 29 00AAD9A0
	virtual void			UpdateSelectedDownwardPass(ControllerUpdateContext * ctx, UInt32 unk1) override;		// 2A 00AADB00
	virtual void			UpdateRigidDownwardPass(ControllerUpdateContext * ctx, UInt32 unk1) override;			// 2B 00AADE20
	virtual void			UpdateWorldBound(void) override;														// 2C 00AADF60
	virtual void			UpdateNoControllers(ControllerUpdateContext * ctx) override;							// 2E 00AADD00
	virtual void			Unk_31(UInt32 arg0) override;															// 31 00AAE130
	virtual void			Unk_32(UInt32 arg0) override;															// 32 00AAE180

	// @add
	virtual void	AttachChild(NiAVObject * obj, bool firstAvail = false);		// 33 00AAE990
	virtual void	DetachChild(UInt32 unk1, NiAVObject * obj);					// 34 00AAEA40
	virtual void	Unk_35(void);												// 35 00AAE820
	virtual void	RemoveChild(NiAVObject * obj);								// 36 00AAE430
	virtual void	Unk_37(void);												// 37 00AAE730
	virtual void	RemoveAt(UInt32 i);											// 38 00AAE3E0
	virtual void	Unk_39(void);												// 39 00AAEAB0
	virtual void	Unk_3A(void);												// 3A 00AAE480
	virtual void	UpdateUpwardPass(void);										// 3B 00AAD8D0

	// children
	inline std::size_t GetArrayCount() const {
		return m_children.GetSize();
	}
	inline std::size_t GetChildCount() const {
		return m_children.GetEffectiveSize();
	}
	inline NiAVObject* GetAt(std::size_t index) const {
		return (index < m_children.GetSize()) ? m_children.GetAt(index) : nullptr;
	}

	static NiNode * Create(UInt32 arrBufLen = 0);

private:
	DEFINE_MEMBER_FN(ctor, NiNode*, 0x00AAED00, UInt32 arrBufLen);

	// @members
	NiTArray <NiAVObject *>	m_children;	// A8
};
STATIC_ASSERT(sizeof(NiNode) == 0xB8);
