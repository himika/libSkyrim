#pragma once

#include "../BSSystem/BSTSmartPointer.h"

#include "BSScriptClass.h"
#include "BSScriptObject.h"
#include "BSScriptVariable.h"
#include "BSScriptArray.h"
#include "BSScriptStack.h"
#include "BSScriptIFunction.h"
#include "BSScriptIForEachScriptObjectFunctor.h"
#include "../SkyrimScript.h"


namespace BSScript
{
	// 08
	class IVirtualMachine :					// 00
		public BSIntrusiveRefCounted		// 04
	{
	public:
		enum
		{
			kFunctionFlag_NoWait = 0x01
		};

		enum
		{
			kSeverity_Info,
			kSeverity_Warning,
			kSeverity_Error
		};


		virtual ~IVirtualMachine();			// 00C334D0

		virtual void	Unk_01(ILoader *loader) = 0;
		virtual void	TraceStack(const char* str, UInt32 stackID, UInt32 aiSeverity = 0) = 0;
		virtual void	Unk_03(VMHandle handle) = 0;
		virtual void	OnUpdate(float arg) = 0;
		virtual void	OnUpdateGameTime(float arg) = 0;
		virtual void	OnUnk06(bool arg) = 0;
		virtual bool	OnChangeVMState(void) = 0;
		virtual void	RegisterForm(UInt32 typeID, const char *papyrusClassName) = 0;
		virtual bool	GetScriptClassByName(const BSFixedString &className, BSScriptClassPtr &outClassPtr) = 0;
		virtual bool	GetScriptClassByTypeID(UInt32 typeID, BSScriptClassPtr &outClass) = 0;
		virtual bool	RegisterScriptClass(const BSFixedString &className, BSScriptClassPtr &classPtr) = 0;
		virtual bool	Unk_0C(UInt32 typeID, BSScriptClassPtr &outClass) = 0;
		virtual bool	GetFormTypeID(const BSFixedString &className, UInt32 &typeID) = 0;
		virtual void	Unk_0E(UInt32 arg1) = 0;
		virtual bool	Unk_0F(const BSScriptType &type, BSScriptClassPtr &classPtr) = 0;
		virtual bool	Unk_10(const BSFixedString &className) = 0;
		virtual bool	Unk_11(UInt32 arg1) = 0;
		virtual void	Unk_12(UInt32 arg1, UInt32 arg2) = 0;
		virtual bool	CreateScriptObjectWithProperty(const BSFixedString &className, void *property, BSScriptObjectPtr &objPtr) = 0;
		virtual bool	CreateScriptObject(const BSFixedString &className, BSScriptObjectPtr &result) = 0;
		virtual bool	CreateScriptArray(const BSScriptType &typeID, UInt32 size, BSScriptArrayPtr &arrayPtr) = 0;
		virtual bool	CreateScriptArray2(VMTypeID typeID, const BSFixedString &className, UInt32 size, BSScriptArrayPtr &arrayPtr) = 0;
		virtual void	RegisterFunction(BSScript::IFunction * fn) = 0;
		virtual void	SetFunctionFlagsEx(const char * className, UInt32 unk0, const char * fnName, UInt32 flags) = 0;
		virtual void	SetFunctionFlags(const char * className, const char * fnName, UInt32 flags) = 0;
		virtual void	VisitScripts(VMHandle handle, IForEachScriptObjectFunctor * functor) = 0;
		virtual bool	ResolveScriptObject(VMHandle handle, const char * className, BSScriptObjectPtr &result) = 0;
		virtual void	Unk_1C(VMHandle arg1, VMHandle arg2) = 0;
		virtual void	Unk_1D(VMHandle handle) = 0;
		virtual bool	CastScriptObject(const BSScriptObjectPtr &fromObjPtr, const BSScriptClassPtr &toClassPtr, BSScriptObjectPtr &toObjPtr) = 0;
		virtual bool	SetObjectProperty(BSScriptObjectPtr &obj, const char *propertyName, BSScriptVariable &setVal) = 0;
		virtual bool	GetObjectProperty(BSScriptObjectPtr &obj, const char *propertyName, BSScriptVariable &getVal) = 0;
		virtual bool	ExtractValue(const BSScriptObjectPtr &objPtr, UInt32 index, BSScriptVariable &out) = 0;
		virtual bool	ExtractValueFromHandle(VMHandle handle, const BSFixedString & className, SInt32 variableIndex, BSScriptVariable & out) = 0;
		virtual void	QueueEvent(VMHandle handle, const BSFixedString & eventName, IFunctionArguments * args) = 0;
		virtual bool	QueueEventAll(const BSFixedString & eventName, IFunctionArguments * args) = 0;
		virtual bool	CallStaticFunction(const BSFixedString &className, const BSFixedString &fnName, IFunctionArguments *args, IStackCallbackFunctorPtr &result) = 0;
		virtual bool	CallMemberFunction(BSScriptObjectPtr &obj, const BSFixedString &fnName, IFunctionArguments * args, IStackCallbackFunctorPtr &result) = 0;
		virtual bool	CallMemberFunctionFromHandle(VMHandle handle, const BSFixedString &className, const BSFixedString &fnName, IFunctionArguments *args, IStackCallbackFunctorPtr &result) = 0;
		virtual bool	Unk_28(VMHandle handle, BSScriptClassPtr &arg3, UInt32 arg4, UInt32 arg5, UInt32 arg6) = 0;
		virtual bool	IsWaitingStack(UInt32 stackID);
		virtual void	SetLatentReturn(UInt32 stackID, const BSScriptVariable &val) = 0;
		virtual BSScript::ErrorLogger			* GetLogger(void) = 0;
		virtual SkyrimScript::HandlePolicy		* GetHandlePolicy(void) = 0;
		virtual BSScript::IObjectHandlePolicy	* GetHandlePolicy2(void) = 0;
		virtual SkyrimScript::ObjectBindPolicy	* GetObjectBindPolicy(void) = 0;
		virtual BSScript::ObjectBindPolicy		* GetObjectBindPolicy2(void) = 0;
		virtual BSScript::ISavePatcherInterface	* GetSavePatcher(void) = 0;
		virtual void	AddLogEventSink(BSTEventSink<BSScript::LogEvent> *sink) = 0;
		virtual void	RemoveLogEventSink(BSTEventSink<BSScript::LogEvent> *sink) = 0;
		virtual void	AddStatsEventSink(BSTEventSink<BSScript::StatsEvent> *sink) = 0;
		virtual void	RemoveStatsEventSink(BSTEventSink<BSScript::StatsEvent> *sink) = 0;

		// @members
		//void						** vtbl		// 00 - 01148088
		//BSIntrusiveRefCounted		refCount;	// 04
	};
}
