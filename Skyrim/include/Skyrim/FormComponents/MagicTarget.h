#pragma once

#include "../BSCore/BSTList.h"

class Actor;
class ActiveEffect;
class SpellItem;
class BGSKeyword;

/*==============================================================================
class MagicTarget +0000 (_vtbl=01079074)
0000: class MagicTarget
==============================================================================*/
// 0C
class MagicTarget
{
	CLASS_SIZE_ASSERT(0x0C)

public:
	virtual ~MagicTarget();													// 0040A510

	virtual bool						MagicTarget_Unk_01(float arg);		// 00664740
	virtual Actor *						MagicTarget_Unk_02(void);			// 005EADD0 { return 0; } PlayerCharacter= { return static_cast<Actor*>(this); }
	virtual bool						MagicTarget_Unk_03(void);			// 0092D110 { return false; } PlayerCharacter={ return true; }
	virtual bool						MagicTarget_Unk_04(void);			// 0092D110 { return false; }
	virtual void						MagicTarget_Unk_05(int);			// 00588F30 (UInt32 arg) { return; }
	virtual bool						MagicTarget_Unk_06(void) = 0;		// 00F51EE8 (pure)
	virtual BSSimpleList<ActiveEffect*> *	GetActiveEffects(void) = 0;		// 00F51EE8 (pure)
	virtual void						MagicTarget_Unk_08(int);			// 00588F30 (UInt32 arg) { return; }
	virtual void						MagicTarget_Unk_09(int);			// 00588F30 (UInt32 arg) { return; }
	virtual double						MagicTarget_Unk_0A(int, int, int);	// 00662960
	virtual bool						MagicTarget_Unk_0B(int, int, int);	// 00933DE0 { return false; }

	class ForEachActiveEffectVisitor
	{
	public:
		virtual ~ForEachActiveEffectVisitor();
		virtual bool Visit(SpellItem*) = 0;
	};

	inline void VisitActiveEffects(ForEachActiveEffectVisitor & visitor) {
		VisitActiveEffects_Internal(visitor);
	}

	//void	** _vtbl;	// 00 - 01079074
	UInt32 unk04;		// 04
	UInt32 unk08;		// 08

	///<summary>Checks to see if the specified keyword is attached to a magic effect that belongs to an active effect currently on this reference.</summary>
	DEFINE_MEMBER_FN_const(HasEffectKeyword, bool, 0x006635B0, const BGSKeyword *, bool);

	///<summary>Checks to see if this actor is currently being affected by the given Magic Effect.</summary>
	DEFINE_MEMBER_FN_const(HasMagicEffect, bool, 0x00662E80, ActiveEffect *);

private:
	DEFINE_MEMBER_FN(VisitActiveEffects_Internal, void, 0x00663410, ForEachActiveEffectVisitor & visitor);
};
