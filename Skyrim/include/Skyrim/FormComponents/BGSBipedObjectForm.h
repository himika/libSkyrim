#pragma once

#include "BaseFormComponent.h"

// 10 - 1.6.89 and earlier
// 0C - 1.7.7 and after
class BGSBipedObjectForm : public BaseFormComponent
{
public:
	// applicable to DefaultRace
	enum PartFlag
	{
		kPart_Head = 1 << 0,
		kPart_Hair = 1 << 1,
		kPart_Body = 1 << 2,
		kPart_Hands = 1 << 3,
		kPart_Forearms = 1 << 4,
		kPart_Amulet = 1 << 5,
		kPart_Ring = 1 << 6,
		kPart_Feet = 1 << 7,
		kPart_Calves = 1 << 8,
		kPart_Shield = 1 << 9,
		kPart_Tail = 1 << 10,
		kPart_LongHair = 1 << 11,
		kPart_Circlet = 1 << 12,
		kPart_Ears = 1 << 13,
		kPart_Unnamed14 = 1 << 14,
		kPart_Unnamed15 = 1 << 15,
		kPart_Unnamed16 = 1 << 16,
		kPart_Unnamed17 = 1 << 17,
		kPart_Unnamed18 = 1 << 18,
		kPart_Unnamed19 = 1 << 19,
		kPart_Unnamed20 = 1 << 20,
		kPart_Unnamed21 = 1 << 21,
		kPart_Unnamed22 = 1 << 22,
		kPart_Unnamed23 = 1 << 23,
		kPart_Unnamed24 = 1 << 24,
		kPart_Unnamed25 = 1 << 25,
		kPart_Unnamed26 = 1 << 26,
		kPart_Unnamed27 = 1 << 27,
		kPart_Unnamed28 = 1 << 28,
		kPart_Unnamed29 = 1 << 29,
		kPart_Unnamed30 = 1 << 30,
		kPart_FX01 = 1 << 31,
	};

	enum
	{
		kWeight_Light = 0,
		kWeight_Heavy,
		kWeight_None,
	};

	struct Data
	{
		UInt32	parts;			// 00 - init'd to 0
		UInt32	weightClass;	// 04 - init'd to 2 (none)
	};

	Data	bipedObjectData;	// 04

	UInt32	GetSlotMask() const				{ return bipedObjectData.parts; }
	void	SetSlotMask(UInt32 mask)		{ bipedObjectData.parts = mask; }
	bool	HasPartOf(UInt32 flag) const	{ return (bipedObjectData.parts & flag) != 0; }

	UInt32	GetWeightClass() const			{ return bipedObjectData.weightClass; }
	bool	IsLightArmor() const			{ return bipedObjectData.weightClass == kWeight_Light; }
	bool	IsHeavyArmor() const			{ return bipedObjectData.weightClass == kWeight_Heavy; }

	UInt32	AddSlotToMask(UInt32 mask);
	UInt32	RemoveSlotFromMask(UInt32 mask);
};
