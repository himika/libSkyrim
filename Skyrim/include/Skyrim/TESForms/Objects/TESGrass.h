#pragma once

#include "TESBoundObject.h"
#include "../../FormComponents/TESModel.h"

/*==============================================================================
class TESGrass +0000 (_vtbl=01082E3C)
0000: class TESGrass
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESModel
0020: |   |   class BaseFormComponent
==============================================================================*/
// 54
class TESGrass : public TESBoundObject,
	public TESModel				// 20
{
public:
	enum { kTypeID = (UInt32)FormType::Grass };

	virtual UInt8	GetUnk34(void);				// return unk34;
	virtual bool	SetUnk34(UInt8 data);		// if(data > 100) return false;
												// unk34 = data; return true;
	virtual UInt8	GetUnk35(void);				// return unk35;
	virtual bool	SetUnk35(UInt8 data);		// if(data > 90) return false;
												// if(data > unk36) return false;
												// unk35 = data; return true;
	virtual UInt8	GetUnk36(void);				// return unk36;
	virtual bool	SetUnk36(UInt8 data);		// if(data > 90) return false;
												// if(data < unk35) return false;
												// unk36 = data; return true;
	virtual float	GetUnk35_Float(void);		// return unk35 * (M_PI / 180);
	virtual float	GetUnk36_Float(void);		// return unk36 * (M_PI / 180);
	virtual UInt16	GetUnk38(void);				// return unk38;
	virtual void	SetUnk38(UInt16 data);		// unk38 = data;
	virtual UInt32	GetUnk3C(void);				// return unk3C;
	virtual void	SetUnk3C(UInt32 data);		// unk3C = data;
	virtual float	GetUnk40(void);				// return unk40;
	virtual bool	SetUnk40(float data);		// if((data < 0) || (data > 512)) return false;
												// unk40 = data; return true;
	virtual float	GetUnk44(void);				// return unk44;
	virtual bool	SetUnk44(float data);		// if((data < 0) || (data > 1)) return false;
												// unk44 = data; return true;
	virtual float	GetUnk48(void);				// return unk48;
	virtual bool	GetUnk48(float data);		// if((data < 0) || (data > 1)) return false;
												// unk48 = data; return true;
	virtual float	GetUnk4C(void);				// return unk4C;
	virtual bool	SetUnk4C(float data);		// if(data <= 0) return false;
												// unk4C = data; return true;
	virtual bool	GetUnk50_01(void);			// return (unk50 & 1) != 0;
	virtual void	SetUnk50_01(UInt8 data);	// if(data) unk50 |= 1; else unk50 &= ~1;
	virtual bool	GetUnk50_02(void);			// return (unk50 & 2) != 0;
	virtual void	SetUnk50_02(UInt8 data);	// if(data) unk50 |= 2; else unk50 &= ~2;
	virtual bool	GetUnk50_04(void);			// return (unk50 & 4) != 0;
	virtual void	SetUnk50_04(UInt8 data);	// if(data) unk50 |= 4; else unk50 &= ~4;

	// @members
	UInt8		unk34;		// 34
	UInt8		unk35;		// 35 - degrees
	UInt8		unk36;		// 36 - degrees
	UInt8		pad37;		// 37
	UInt16		unk38;		// 38
	UInt8		pad3A[2];	// 3A
	UInt32		unk3C;		// 3C
	float		unk40;		// 40
	float		unk44;		// 44
	float		unk48;		// 48
	float		unk4C;		// 4C
	UInt8		unk50;		// 50
	UInt8		pad51[3];	// 51
};
STATIC_ASSERT(sizeof(TESGrass) == 0x54);
