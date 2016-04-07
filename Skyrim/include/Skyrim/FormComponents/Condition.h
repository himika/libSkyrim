#pragma once

class TESObjectREFR;

// 4
class Condition
{
public:
	enum Opcode
	{
		kOpcode_Equal = 0,
		kOpcode_NotEqual,
		kOpcode_Greater,
		kOpCode_GreaterEqual,
		kOpCode_Less,
		kOpCode_LessEqual
	};

	enum ReferenceTypes
	{
		kReferenceType_None = 0,
		kReferenceType_Target,
		kReferenceType_Reference,
		kReferenceType_CombatTarget,
		kReferenceType_LinkedRef,
		kReferenceType_Alias,
		kReferenceType_PackageData,
		kReferenceType_EventData
	};

	// 20
	struct Node
	{
		// @members
		Node	* next;				// 00
		UInt32	comparisonValue;	// 04
		UInt32	unk08;				// 08
		UInt32	unk0C;				// 0C - FFFFFFFF
		UInt16	functionId;			// 10
		UInt8	unk12;				// 12
		UInt8	unk13;				// 13
		void	* param1;			// 14
		void	* param2;			// 18
		struct ComparisonFlags {
			bool	isOr : 1;				// 0x01	- false:And / true:Or
			bool	useAliases : 1;			// 0x02
			bool	global : 1;				// 0x04
			bool	usePackData : 1;		// 0x08
			bool	swapTarget : 1;			// 0x10
			UInt8	opcode : 3;				// 0x20 - 00:== 01:!= 02:> 03:>= 04:< 05:<=
		} comparisonType;			// 1C
		UInt8	referenceType;		// 1D

	private:
		DEFINE_MEMBER_FN(dtor, void, 0x005E9D90)
	};
	STATIC_ASSERT(sizeof(Node) == 0x20);

	Condition() : nodes(nullptr) {}
	~Condition() { dtor(); }

	bool Match(TESObjectREFR *arg1, TESObjectREFR *arg2 = nullptr) const {
		return Match_Impl(arg1, arg2);
	}

	// @members
	Node		* nodes;	// 00

private:
	DEFINE_MEMBER_FN(ctor, Condition *, 0x00A88CB0);
	DEFINE_MEMBER_FN(dtor, void, 0x005E9440);
	DEFINE_MEMBER_FN_const(Match_Impl, bool, 0x005E9800, TESObjectREFR *arg1, TESObjectREFR *arg2);
};
STATIC_ASSERT(sizeof(Condition) == 0x4);
