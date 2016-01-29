#pragma once

#include "NiObject.h"

/*==============================================================================
class NiAccumulator +0000 (_vtbl=0111D2B4)
0000: class NiAccumulator
0000: |   class NiObject
0000: |   |   class NiRefObject
==============================================================================*/
class NiAccumulator : public NiObject
{
public:
	enum { kRTTI = 0x01B92B5C };

	// @override
	virtual NiRTTI *	GetRTTI(void) const;								// 02 00AECD30 { return 0x01B92B5C; }
	virtual void		LoadBinary(NiStream * stream) override;				// 14 00AECCC0 { NiObject::LoadBinary(stream); }
	virtual void		LinkObject(NiStream * stream) override;				// 15 00AECCD0 { NiObject::LinkObject(stream); }
	virtual bool		RegisterStreamables(NiStream * stream) override;	// 16 00AECCE0 { return NiObject::RegisterStreamables(stream); }
	virtual void		SaveBinary(NiStream * stream) override;				// 17 00AECCF0 { NiObject::SaveBinary(stream); }
	virtual bool		IsEqual(NiObject * object) override;				// 18 00AECD00 { return NiObject::IsEqual(object);

	// @add
	virtual void   SetUnk08(UInt32 arg);		// 00AECC80 { unk08 = arg1; }
	virtual void   ClearUnk08(void);			// 00AECC90 { unk08 = 0; }
	virtual void   Unk_23(void);				// 00F51EE8 (pure)
	virtual bool   Unk_24(UInt32 arg);			// 004091A0 { return false; }

	// @members
	//void	** _vtbl;		// 00 - 0111D2B4
	UInt32	unk08;
};
