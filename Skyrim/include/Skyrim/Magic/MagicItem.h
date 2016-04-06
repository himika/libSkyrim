#pragma once

// c:_skyrim\code\tesv\magic\MagicItem.h

#include "../TESForms/Objects/TESBoundObject.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/BGSKeywordForm.h"
#include "../BSCore/BSTArray.h"
#include "EffectItem.h"

class EffectSetting;

/*==============================================================================
class MagicItem +0000 (_vtbl=01077E7C)
0000: class MagicItem
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESFullName
0020: |   |   class BaseFormComponent
0028: |   class BGSKeywordForm
0028: |   |   class BaseFormComponent
==============================================================================*/
// 50
class MagicItem : public TESBoundObject,
	public TESFullName,		// 20
	public BGSKeywordForm	// 28
{
public:
	enum
	{
		kType_unk00 = 0,
		kType_unk01,
		kType_unk02,
		kType_unk03,
		kType_unk04,
		kType_unk05,
		kType_unk06,
		kType_Archemy,		// 7
		kType_Scroll = 0x0D
	};

	enum
	{
		kCastType_0 = 0,
		kCastType_1
	};

	// @override
	virtual bool	Unk_29(void) override;				// 009B86F0 { return true; }

	// @add
	virtual UInt32	GetMagicType(void) = 0;				// 54 00F51EE8 ArchemyItem=7 ScrollItem=0x0D
	virtual void	SetCastType(UInt32 arg);			// 55 00588F30 { return; }
	virtual UInt32	GetCastType(void) = 0;				// 56 00F51EE8 ArchemyItem=1
	virtual void	SetDeliveryType(UInt32 arg);		// 57 00588F30 { return; }
	virtual UInt32	GetDeliveryType(void) = 0;			// 58 00F51EE8 ArchemyItem=0
	virtual bool	Unk_59(UInt32 arg);					// 00C8CCA0 { return true; }
	virtual float	Unk_5A(void);						// 0066E8A0 { return 0.0f; }
	virtual float	Unk_5B(void);						// 0066E8A0 { return 0.0f; }
	virtual bool	Unk_5C(void);						// 0092D110 { return false; }
	virtual bool	Unk_5D(void);						// 0092D110 { return false; }
	virtual bool	Unk_5E(void);						// 0092D110 { return false; }
	virtual bool	Unk_5F(void);						// 0092D110 { return false; }
	virtual bool	Unk_60(void);						// 0092D110 { return false; }
	virtual bool	Unk_61(UInt32 arg);					// 004091A0 { return false; }
	virtual bool	Unk_62(void);						// 00405250 { return GetMagicType() == 5 } offensive or defensive ?
	virtual bool	Unk_63(void);						// 0092D110 { return false; }
	virtual void	Unk_64(UInt32 arg0, UInt32 arg1);	// 004D43E0 { return; }
	virtual float	Unk_65(void);						// 0066E8A0 { return 0.0f; }
	virtual UInt32	Unk_66(void);						// 005EADD0 { return 0; } IngredientItem=4
	virtual SInt32	Unk_67(void);						// 00407240 { return -1; } ArchemyItem=0x10, EnchantmentItem=0x17, ScrollItem=-1
	virtual bool	Unk_68(void);						// 0092D110 { return false; }
	virtual UInt32	GetSigniture(void) = 0;				// 69 00F51EE8 returns char code
	virtual void	Unk_6A(MagicItem * src) = 0;		// 00F51EE8 copy data if possible?
	virtual void	Unk_6B(UInt32 arg0, UInt32 arg1);	// 004D43E0 loading-related
	virtual void	Unk_6C(UInt32 arg);					// 00588F30 { return; }
	virtual void *	Unk_6D(void) = 0;					// 00F51EE8 returns data
	virtual void *	Unk_6E(void) = 0;					// 00F51EE8 returns data
	virtual UInt32	Unk_6F(void) = 0;					// 00F51EE8 return size of data, SpellItem=0x24 AlchemyItem=0x14, EnchantmentItem=0x24
	virtual void	Unk_70(void) = 0;					// 00F51EE8 byteswap?

	class PreloadableVisitor
	{
	public:
		virtual ~PreloadableVisitor();
		virtual void Visit(void) = 0;
	};


	// @members
	BSTArray<EffectItem *>	effectItemList;		// 34
	UInt32					hostile;			// 40
	EffectSetting			* unk44;			// 44
	UInt32					unk48;				// 48
	UInt32					unk4C;				// 4C

	DEFINE_MEMBER_FN(GetCostliestEffectItem, EffectItem *, 0x00407860, int arg1, bool arg2);
	DEFINE_MEMBER_FN(GetEffectiveMagickaCost, double, 0x00406EF0, Actor * caster);
};
STATIC_ASSERT(sizeof(MagicItem) == 0x50);
