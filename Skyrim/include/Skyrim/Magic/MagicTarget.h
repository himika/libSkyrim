#pragma once

#include "../BSCore/BSTList.h"

class Actor;
class ActiveEffect;
class MagicItem;
class SpellItem;
class BGSKeyword;


/*==============================================================================
class MagicTarget +0000 (_vtbl=01079074)
0000: class MagicTarget
==============================================================================*/
// 0C
class MagicTarget
{
public:
	/*==============================================================================
	class MagicTarget::ForEachActiveEffectVisitor +0000 (_vtbl=0109511C)
	0000: class MagicTarget::ForEachActiveEffectVisitor
	==============================================================================*/
	class ForEachActiveEffectVisitor
	{
	public:
		virtual ~ForEachActiveEffectVisitor();	// 00 006634F0
		virtual bool Visit(SpellItem*) = 0;		// 01
	};


	/*==============================================================================
	struct MagicTarget::IPostCreationModification +0000 (_vtbl=010C8E44)
	0000: struct MagicTarget::IPostCreationModification
	==============================================================================*/
	struct IPostCreationModification
	{
		virtual ~IPostCreationModification();		// 00 0065E420
		virtual void Unk_01(void) = 0;				// 01
	};


	virtual ~MagicTarget();													// 00 0040A510

	virtual bool		MagicTarget_Unk_01(void *arg);						// 01 00664740
	virtual Actor *		GetMagicTargetActor(void) const;					// 02 005EADD0 { return 0; } Actor={ return static_cast<Actor*>(this); }
	virtual bool		IsActorMagicTarget(void) const;						// 03 0092D110 { return false; } Actor={ return true; }
	virtual bool		MagicTarget_Unk_04(void);							// 04 0092D110 { return false; }
	virtual void		MagicTarget_Unk_05(int);							// 05 00588F30 (UInt32 arg) { return; }
	virtual bool		MagicTarget_Unk_06(void) = 0;						// 06 00F51EE8 (pure)
	virtual BSSimpleList<ActiveEffect *> *	GetActiveEffects(void) = 0;		// 07 00F51EE8 (pure)
	virtual void		MagicTarget_Unk_08(int);							// 08 00588F30 (UInt32 arg) { return; }
	virtual void		MagicTarget_Unk_09(ActiveEffect *);					// 09 00588F30 (UInt32 arg) { return; }
	virtual double		MagicTarget_Unk_0A(int, int, int);					// 0A 00662960 { return 1.0; }
	virtual bool		MagicTarget_Unk_0B(Actor *, MagicItem *, Actor *);	// 0B 00933DE0 { return false; } can apply magic effect ?


	inline void VisitActiveEffects(ForEachActiveEffectVisitor & visitor)
	{
		VisitActiveEffects_Internal(visitor);
	}


	///<summary>Checks to see if the specified keyword is attached to a magic effect that belongs to an active effect currently on this reference.</summary>
	inline bool HasEffectKeyword(const BGSKeyword *keyword) const
	{
		return GetMagicEffectWithKeyword_Internal(keyword, nullptr);
	}

	inline ActiveEffect * GetEffectWithKeyword(const BGSKeyword *keyword) const
	{
		ActiveEffect *effect = nullptr;
		return (GetMagicEffectWithKeyword_Internal(keyword, &effect)) ? effect : nullptr;
	}

	///<summary>Checks to see if this actor is currently being affected by the given Magic Effect.</summary>
	DEFINE_MEMBER_FN_const(HasMagicEffect, bool, 0x00662E80, ActiveEffect *);


	// @members
	//void	** _vtbl;	// 00 - 01079074
	UInt32 unk04;		// 04
	UInt32 unk08;		// 08

private:
	DEFINE_MEMBER_FN(VisitActiveEffects_Internal, void, 0x00663410, ForEachActiveEffectVisitor & visitor);
	DEFINE_MEMBER_FN_const(GetMagicEffectWithKeyword_Internal, bool, 0x006635B0, const BGSKeyword *, ActiveEffect **result);
};
STATIC_ASSERT(sizeof(MagicTarget) == 0x0C);
