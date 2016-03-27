#pragma once

// c:_skyrim\code\tesv\bsscript\BSScriptArray.h
// c:_skyrim\code\tesv\bsscript\BSScriptBoundScript.h
// c:_skyrim\code\tesv\bsscript\BSScriptByteCode.h
// c:_skyrim\code\tesv\bsscript\BSScriptCompiledScriptLoader.h
// c:_skyrim\code\tesv\bsscript\BSScriptErrorLogger.h
// c:_skyrim\code\tesv\bsscript\BSScriptIVirtualMachine.h
// c:_skyrim\code\tesv\bsscript\BSScriptInternalCodeTasklet.h
// c:_skyrim\code\tesv\bsscript\BSScriptInternalIFuncCallQuery.h
// c:_skyrim\code\tesv\bsscript\BSScriptInternalScriptFunction.h
// c:_skyrim\code\tesv\bsscript\BSScriptInternalVDescTable.h
// c:_skyrim\code\tesv\bsscript\BSScriptInternalVirtualMachine.h
// c:_skyrim\code\tesv\bsscript\BSScriptLinkerProcessor.h
// c:_skyrim\code\tesv\bsscript\BSScriptMemoryPagePolicy.h
// c:_skyrim\code\tesv\bsscript\BSScriptObject.h
// c:_skyrim\code\tesv\bsscript\BSScriptObjectBindPolicy.h
// c:_skyrim\code\tesv\bsscript\BSScriptObjectTypeInfo.h
// c:_skyrim\code\tesv\bsscript\BSScriptPropertyTypeInfo.h
// c:_skyrim\code\tesv\bsscript\BSScriptStack.h
// c:_skyrim\code\tesv\bsscript\BSScriptUnlinkedTypes.h
// c:_skyrim\code\tesv\bsscript\BSScriptUtilities.h
// c:_skyrim\code\tesv\bsscript\BSScriptVariable.h



#include "../BSCore/BSTEvent.h"
#include "../BSSystem/BSTSmartPointer.h"
#include "../BSCore/BSTArray.h"
#include "../BSSystem/BSStorage.h"

namespace BSScript
{
	struct StatsEvent
	{
	};

	class BSScriptClass;				// ==> BSScriptClass.h

	class BSScriptObject;				// ==> BSScriptObject.h

	class BSScriptObjectTypeInfo;

	class BSScriptObjectPropertyTypeInfo;

	class BSScriptVariable;				// ==> BSScriptVariable.h

	class BSScriptArray;				// ==> ScriptVariable.h

	class IForEachScriptObjectFunctor;	// => BSScriptIForEachScriptObjectFunctor.h

	class IFunctionArguments;			// ==> BSScriptIFunctionArguments.h
	class ZeroFunctionArguments;

	/*==============================================================================
	struct BSScript::IHandleReaderWriter +0000 (_vtbl=0107CB1C)
	0000: struct BSScript::IHandleReaderWriter
	==============================================================================*/
	// 04
	class IHandleReaderWriter
	{
	public:
		virtual ~IHandleReaderWriter() {};	// 00450B00
		virtual void Unk_01(void) = 0;		// 00F51EE8 (pure)
		virtual void Unk_02(void) = 0;		// 00F51EE8 (pure)
		virtual void Unk_03(void) = 0;		// 00F51EE8 (pure)
	};


	/*==============================================================================
	class BSScript::IProfilePolicy +0000 (_vtbl=010EAD6C)
	0000: class BSScript::IProfilePolicy
	==============================================================================*/
	// 04
	class IProfilePolicy
	{
	public:
		virtual ~IProfilePolicy();		// 008C5A70
		virtual void Unk_01(void) = 0;	// (pure)
		virtual void Unk_02(void) = 0;	// (pure)
		virtual void Unk_03(void) = 0;	// (pure)
		virtual void Unk_04(void) = 0;	// (pure)
	};

	/*==============================================================================
	class BSScript::ISavePatcherInterface +0000 (_vtbl=010EB090)
	0000: class BSScript::ISavePatcherInterface
	==============================================================================*/
	// 04
	class ISavePatcherInterface
	{
	public:
		virtual ~ISavePatcherInterface();		// 008C5B70
		virtual void Unk_01(void) = 0;			// (pure)
	};

	/*==============================================================================
	class BSScript::IStore +0000 (_vtbl=010EA84C)
	0000: class BSScript::IStore
	0000: |   class BSStorage
	0004: |   |   struct BSIntrusiveRefCounted
	==============================================================================*/
	// 04
	class IStore : public BSStorage
	{
	public:
		virtual ~IStore();							// 008C0620
		virtual void Unk_05(void) override;			// 00687260
		virtual void Unk_06(const char *name) = 0;	// (pure)
		virtual void Unk_07(void) = 0;				// (pure)
		virtual void Unk_08(void) = 0;				// (pure)
		virtual void Unk_09(void) = 0;				// (pure)
		virtual void Unk_0A(void) = 0;				// (pure)
		virtual void Unk_0B(void) = 0;				// (pure)
	};
	BSSmartPointer(IStore);

	struct IObjectHandlePolicy;	// ==> BSScriptIObjectHandlePolicy.h

	/*==============================================================================
	struct BSScript::ILoader +0000 (_vtbl=010EAD58)
	0000: struct BSScript::ILoader
	==============================================================================*/
	// 04
	struct ILoader
	{
	public:
		virtual ~ILoader();		// 00C45DF0
		virtual ILoader *	Duplicate(void) = 0;
		virtual void		SetStore(IStorePtr &arg0) = 0;
		virtual bool		Load(const char *name, void *unkObj) = 0;

		// void **	_vtbl				// 00 - 010EAD58
	};

	class IStackCallbackFunctor;	// ==> BScriptStack.h

	/*==============================================================================
	class BSScript::IFreezeQuery +0000 (_vtbl=010EAE70)
	0000: class BSScript::IFreezeQuery
	==============================================================================*/
	// 04
	class IFreezeQuery
	{
	public:
		virtual ~IFreezeQuery();						// 008C5B10
		virtual bool IFreezeQuery_Unk_01(void) = 0;		// (pure)
	};

	/*==============================================================================
	class BSScript::IStackCallbackSaveInterface +0000 (_vtbl=010EAE7C)
	0000: class BSScript::IStackCallbackSaveInterface
	==============================================================================*/
	// 04
	class IStackCallbackSaveInterface
	{
	public:
		virtual ~IStackCallbackSaveInterface();															// 008C5B40
		virtual bool	IStackCallbackSaveInterface_Unk_01(UInt32 arg1, UInt32 arg2) = 0;				// (pure)
		virtual bool	IStackCallbackSaveInterface_Unk_02(UInt32 arg1, UInt32 arg2, UInt32 arg3) = 0;	// (pure)
	};

	class ObjectBindPolicy;		// ==> BSScriptObjectBindPolicy.h

	class IFunction;	// ==> BSScriptIFunction.h
}
