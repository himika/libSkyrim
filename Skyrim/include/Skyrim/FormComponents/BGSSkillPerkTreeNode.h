#pragma once

#include "../BSCore/BSTArray.h"

class BGSPerk;
class ActorValueInfo;

// 3C
class BGSSkillPerkTreeNode
{
public:
	virtual ~BGSSkillPerkTreeNode();

	UInt32	index;		// 04
	BSTArray<BGSSkillPerkTreeNode*> connections;	// 08
	BSTArray<BGSSkillPerkTreeNode*> connectees;	// 14
	BGSPerk	* perk;		// 20
	UInt32	unk24;		// 24
	UInt32	gridX;		// 28
	UInt32	gridY;		// 2C
	ActorValueInfo	* skill;	// 30
	float	horizontalPos;		// 34
	float	verticalPos;		// 38

	class PerkVisitor
	{
	public:
		virtual bool Accept(BGSPerk * node) = 0;
	};

	bool VisitPerks(PerkVisitor & visitor)
	{
		if (visitor.Accept(perk))
			return true;

		UInt32 i = 0;
		BGSSkillPerkTreeNode* connector = nullptr;
		while (connections.GetAt(i++, connector)) {
			if (connector->VisitPerks(visitor))
				return true;
		}

		return false;
	}
};