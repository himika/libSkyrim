#pragma once

// 20
class Condition
{
public:
	enum _ComparisonFlags {
		kComparisonFlag_And = 0x00,
		kComparisonFlag_Or = 0x01,
		kComparisonFlag_Equal = 0x00,
		kComparisonFlag_UseAliases = 0x02,
		kComparisonFlag_Global = 0x04,
		kComparisonFlag_UsePackData = 0x08,
		kComparisonFlag_SwapTarget = 0x10,
		kComparisonFlag_NotEqual = 0x20,
		kComparisonFlag_Greater = 0x40,
		kComparisonFlag_GreaterEqual = 0x60,
		kComparisonFlag_Less = 0x80,
		kComparisonFlag_LessEqual = 0xA0
	};

	enum _ReferenceTypes {
		kReferenceType_None = 0,
		kReferenceType_Target,
		kReferenceType_Reference,
		kReferenceType_CombatTarget,
		kReferenceType_LinkedRef,
		kReferenceType_Alias,
		kReferenceType_PackageData,
		kReferenceType_EventData
	};

	Condition	* next;					// 00
	UInt32		compareValue;			// 04
	UInt32		unk08;					// 08
	UInt32		unk0C;					// 0C - FFFFFFFF
	UInt16		functionId;				// 10
	UInt8		unk12;					// 12
	UInt8		unk13;					// 13
	UInt32		param1;					// 14
	UInt32		param2;					// 18
	struct ComparisonFlags {
		bool	isOr : 1;				// 0x01	- false:And / true:Or
		bool	useAliases : 1;		// 0x02
		bool	global : 1;			// 0x04
		bool	usePackData : 1;	// 0x08
		bool	swapTarget : 1;		// 0x10
		UInt8	comparisonOp : 3;	// 0x20 - 00:== 01:!= 02:> 03:>= 04:< 05:<=
	} comparisonType;					// 1C
	enum class ReferenceTypes : UInt8 {
		None = 0,
		Target,
		Reference,
		CombatTarget,
		LinkedRef,
		Alias,
		PackageData,
		EventData
	} referenceType;					// 1D
};
STATIC_ASSERT(sizeof(Condition) == 0x20);
