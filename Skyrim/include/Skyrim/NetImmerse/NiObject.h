#pragma once

#include "NiRefObject.h"
#include "NiRTTI.h"

class NiRTTI;
class NiNode;
class NiSwitchNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;
class NiParticles;
class NiLines;
class NiCloningProcess;
class NiStream;
class NiObjectGroup;


/*==============================================================================
class NiObject +0000 (_vtbl=011173FC)
0000: class NiObject
0000: |   class NiRefObject
==============================================================================*/
// 08
class NiObject : public NiRefObject
{
public:
	enum { kRTTI = 0x01B9111C };

	bool IsKindOf(const NiRTTI* rtti) const
	{
		const NiRTTI* p = GetRTTI();

		while (p)
		{
			if (p == rtti)
				return true;
			p = p->GetBaseRTTI();
		}
		return false;
	}

	NiObject * DynamicCast(const NiRTTI* rtti) const
	{
		return (IsKindOf(rtti)) ? (NiObject*)this : nullptr;
	}


	// standard NetImmerse
	virtual NiRTTI *		GetRTTI(void) const;						// 02 004B5290 { return 0x01B9111C; }

	// then a bunch of attempts to avoid dynamic_cast?
	// unverified, do not use
	virtual NiNode			* GetAsNiNode(void);						// 03 005EADD0 { return 0; }
	virtual NiSwitchNode	* GetAsNiSwitchNode(void);					// 04 005EADD0 { return 0; }
	virtual void *			Unk_05(void);								// 05 005EADD0 { return 0; }
	virtual void *			Unk_06(void);								// 06 005EADD0 { return 0; }
	virtual NiGeometry		* GetAsNiGeometry(void);					// 07 005EADD0 { return 0; }
	virtual NiTriBasedGeom	* GetAsNiTriBasedGeom(void);				// 08 005EADD0 { return 0; }
	virtual NiTriStrips		* GetAsNiTriStrips(void);					// 09 005EADD0 { return 0; }
	virtual NiTriShape		* GetAsNiTriShape(void);					// 0A 005EADD0 { return 0; }
	virtual BSSegmentedTriShape * GetAsBSSegmentedTriShape(void);		// 0B 005EADD0 { return 0; }
	virtual void *			Unk_0C(void);								// 0C 005EADD0 { return 0; }
	virtual NiParticles *	GetAsNiParticles(void);						// 0D 005EADD0 { return 0; }
	virtual NiLines *		GetAsNiLines(void);							// 0E 005EADD0 { return 0; }
	virtual void *			Unk_0F(void);								// 0F 005EADD0 { return 0; } bhkNiCollisionObject::Unk_0F { return this; }
	virtual void *			Unk_10(void);								// 10 005EADD0 { return 0; }
	virtual void *			Unk_11(void);								// 11 005EADD0 { return 0; } bhkRigidBody::Unk_11 { return this; }
	virtual void *			Unk_12(void);								// 12 005EADD0 { return 0; }

	// then back to NetImmerse
	virtual NiObject *		CreateClone(NiCloningProcess cloner);		// 13 00AAFC30 { return this; }

	virtual void			LoadBinary(NiStream * stream);				// 14 00AAFC40 { return; }
	virtual void			LinkObject(NiStream * stream);				// 15 00AAFC50 { return; }
	virtual bool			RegisterStreamables(NiStream * stream);		// 16 00AAFC70
	virtual void			SaveBinary(NiStream * stream);				// 17 00AAFC90 { return; }
	virtual bool			IsEqual(NiObject * object);					// 18 00AAFCC0

	// viewer appears to be disabled sadly
	// why did you do that? it was really useful for figuring out class data
	// and it's not like it totally bloated up the executa... er never mind
	virtual void			ProcessClone(NiCloningProcess * cloner);	// 19 00AAFED0
	virtual void			PostLinkObject(NiStream * stream);			// 1A 00AAFC60 { return; }
	virtual bool			StreamCanSkip(void);						// 1B 00AAFCA0 { return false; }
	virtual const NiRTTI *	GetStreamableRTTI(void) const;				// 1C 00AAFCB0
	virtual UInt32			GetBlockAllocationSize(void) const;			// 1D 00AAFBC0 { return 0; }
	virtual NiObjectGroup *	GetGroup(void) const;						// 1E 00AAFBD0 { return 0; }
	virtual void			SetGroup(NiObjectGroup * group);			// 1F 00AAFBE0 { return; }

	// begin bethesda extensions? possibly just stuff we can't match up
	virtual UInt32			Unk_20(void);								// 20 00AAFBF0 { return 0; }

	

	DEFINE_MEMBER_FN(DeepCopy, NiStream *, 0x00AAFD60, NiObject ** result);
};
STATIC_ASSERT(sizeof(NiObject) == 0x08);
