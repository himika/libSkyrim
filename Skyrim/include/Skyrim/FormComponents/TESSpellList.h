#pragma once

#include "BaseFormComponent.h"

class SpellItem;
class TESShout;

// 08
class TESSpellList : public BaseFormComponent
{
public:
	UInt32		GetSpellCount() const;
	SpellItem	* GetNthSpell(UInt32 n) const;

	UInt32		GetShoutCount() const;
	TESShout	* GetNthShout(UInt32 n) const;

	struct Data
	{
		SpellItem	** spells;	// SpellItem**  (null terminated array of spells)
		void		* unk4;
		TESShout	** shouts;
		UInt32		numSpells;
		UInt32		numUnk4;
		UInt32		numShouts;
	};

	Data	* unk04;	// 04
};
