#pragma once

// c:_skyrim\code\tesv\bsscript\BSScriptStack.h

#include "../BSSystem/BSTSmartPointer.h"
#include "BSScriptVariable.h"

class ProbablyCallStackManager;

//// 28
//class VMInstructionSequence : public BSIntrusiveRefCounted
//{
//public:
//	typedef BSTSmartPointer<VMInstructionSequence> SmartPtr;
//
//	using BSScriptClass = BSScript::BSScriptClass;
//	using BSScriptVariable = BSScript::BSScriptVariable;
//	using IFunctionArguments = BSScript::IFunctionArguments;
//
//	explicit VMInstructionSequence(UInt32 arg1, BSTSmartPointer<BSScriptClass> & classInfo, const BSFixedString & funcName, BSScriptVariable * baseValue, IFunctionArguments::Output* output)
//	{
//		ctor(arg1, classInfo, funcName, baseValue, output);
//	}
//
//	virtual ~VMInstructionSequence();	// 00C57D10
//
//	virtual bool Set(UInt32 arg1, BSTSmartPointer<BSScriptClass> & classInfo, const BSFixedString & funcName, BSScriptVariable* baseValue, IFunctionArguments::Output* output);	// 00C57C70
//
//	// @members
//	//void						** _vtbl	// 00 - 0114AB9C
//	UInt32						unk08;
//	BSTSmartPointer<BSScriptClass>		classInfo;	// 0C
//	BSFixedString				funcName;	// 10
//	BSScriptVariable			baseValue;	// 14
//	BSTArray<BSScriptVariable>	params;		// 1C
//
//private:
//	DEFINE_MEMBER_FN(ctor, VMInstructionSequence*, 0x00C57BB0, UInt32 arg1, BSTSmartPointer<BSScriptClass> & classInfo, const BSFixedString & eventName, BSScriptVariable * baseValue, IFunctionArguments::Output * output);
//};



namespace BSScript
{
	BSSmartPointer(BSScriptStack);

	// 20
	// the same type as VMState in skse
	// the same type as UnkStackData1 except missing unk000
	class StackFrame
	{
	public:
		using BSScriptStack = BSScript::BSScriptStack;
		using BSScriptVariable = BSScript::BSScriptVariable;
		using IFunction = BSScript::IFunction;

		BSScriptStack		* stack;		// 00
		StackFrame			* parent;		// 04
		IFunction			* func;			// 08
		void				* unk0C;
		UInt32				unk10;
		BSScriptVariable	baseValue;		// 14
		UInt32				numArgs;		// 1C
		//BSScriptVariable	Args[];			// 20~

		BSScriptVariable *	GetArgs() const {
			return (BSScriptVariable*)(this + 1);
		}
	};

	// 48
	// the same type as VMArgList and UnkVMStackData2 in skse)
	// BSScriptStack?
	class BSScriptStack : public BSIntrusiveRefCounted
	{
		CLASS_SIZE_ASSERT(0x48);

	public:
		typedef BSTSmartPointer<BSScriptStack> SmartPtr;

		using BSScriptVariable = BSScript::BSScriptVariable;

		BSScriptStack();
		~BSScriptStack();

		// 08 + sizeof(Data)
		struct Chunk
		{
			void *	GetHead(void) const	{ return (void*)(this + 1); }
			void *	GetTail(void) const	{ return (void*)((UInt32)GetHead() + size); }

			bool	IsInRange(void * pointer) const {
				return (pointer >= GetHead()) && (pointer < GetTail());
			}

			UInt32			size;	// 00 - max 128byte?
			//StackFrame	frame	// 04
		};

		// 08
		struct Pair
		{
			Chunk *	chunk;		// 00
			UInt32	unk04;		// 04
		};

		// @members
		ProbablyCallStackManager *	manager;		// 04
		UInt32						unk08;
		BSTSmallArray<Pair, 3>		chunks;			// 0C - stack data is splitted into 128-byte chunks
		UInt32						unk2C;			// 2C
		StackFrame *				current;		// 30
		UInt32						unk34;
		UInt32						unk38;
		BSScriptVariable			resultValue;	// 3C
		UInt32						stackID;		// 44

		DEFINE_MEMBER_FN_const(GetOffset, UInt32, 0x00C3A620, StackFrame * frame);
		DEFINE_MEMBER_FN(Get, BSScript::BSScriptVariable *, 0x00C3AC40, StackFrame * frame, UInt32 idx, UInt32 offset);
	};
	STATIC_ASSERT(offsetof(BSScriptStack, unk2C) == 0x2C);
}
