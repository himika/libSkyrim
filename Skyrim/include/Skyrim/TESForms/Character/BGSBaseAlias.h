#pragma once

#include "../../FormComponents/FormTypes.h"
#include "../../BSCore/BSFixedString.h"

class TESQuest;

/*==============================================================================
class BGSBaseAlias +0000 (_vtbl=010A32B4)
0000: class BGSBaseAlias
==============================================================================*/
// 18
class BGSBaseAlias
{
public:
	enum { kTypeID = (UInt32)FormType::Alias };

	enum Flag
	{
		kFlag_ReservesRefernce			= 1 << 0,		// 0x0001 - Once a reference is assigned to a "Reserved" alias, the Story Manager will not fill any other alias with this reference.
		kFlag_Optional					= 1 << 1,		// 0x0002 - If checked, the quest is not required to fill this in order to start. If unchecked, the quest will fail to start if the Story Manager fails to fill this alias.
		kFlag_QuestObject				= 1 << 2,		// 0x0004
		kFlag_AllowReuseInQuest			= 1 << 3,		// 0x0008
		kFlag_AllowDead					= 1 << 4,		// 0x0010
		kFlag_0x0020					= 1 << 5,
		kFlag_Essential					= 1 << 6,		// 0x0040
		kFlag_AllowDisabled				= 1 << 7,		// 0x0080
		kFlag_StoresText				= 1 << 8,		// 0x0100 - Check this if the alias is used in text replacement.
		kFlag_AllowDestroyed			= 1 << 12,		// 0x1000
		kFlag_UseStoredText				= 1 << 14,		// 0x4000 - Check this if the alias requires text replacement (for example, a book with text replacement tags, or an alias which uses text replacement in an alternate Display Name).
		kFlag_ClearsNameWhenRemoved		= 1 << 18		// 0x20000
	};

	virtual ~BGSBaseAlias();										// 0054DF80

	virtual bool					Unk_01(UInt32 arg1) = 0;		// 00F51EE8 (pure)
	virtual void					Unk_02(UInt32 arg1) = 0;		// 00F51EE8 (pure)
	virtual const BSFixedString &	GetTypeString(void) const = 0;	// 00F51EE8 (pure)

	bool IsLocationAlias() const;
	bool IsReferenceAlias() const;

	// @members
	BSFixedString	name;			// 04
	TESQuest		* owner;		// 08
	UInt32			aliasId;		// 0C
	UInt32			flags;			// 10
	UInt16			unk14;			// 14
	UInt16			pad16;			// 16

private:
	DEFINE_MEMBER_FN(ctor, BGSBaseAlias *, 0x0054DFC0, TESQuest *questOwner, UInt32 aliasId);
};
STATIC_ASSERT(sizeof(BGSBaseAlias) == 0x18);
