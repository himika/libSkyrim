#pragma once

#include "BSScript/BSScriptIVirtualMachine.h"
#include "BSScript/BSScriptUnlinkedTypes.h"
#include "BSScript/BSScriptIFuncCallQuery.h"
#include "BSCore/BSSpinLock.h"
#include "BSCore/BSTHashMap.h"
#include "BSSystem/BSTPointerAndFlags.h"

#include <functional>

// External Classes
class SkyrimVM;

namespace BSScript
{
	class MemoryPagePolicy;
	class IStackCallbackSaveInterface;
}


// 04 - VMState+0008
class IObjectManagerInterface
{
public:
	using BSScriptObjectPtr = BSScript::BSScriptObjectPtr;

	IObjectManagerInterface();
	virtual ~IObjectManagerInterface();		// 00C2E760

	virtual VMHandle	GetHandle(const BSScriptObjectPtr &objPtr) = 0;
	virtual bool		IObjectManagerInterface_Unk_02(const BSFixedString &className, VMHandle handle) = 0;
	virtual void		BindObject(BSScriptObjectPtr &objPtr, VMHandle handle, bool bCounditional) = 0;
	virtual void		RegisterObject(BSScriptObjectPtr &objPtr, VMHandle handle, bool bCounditional) = 0;
	virtual void		IObjectManagerInterface_Unk_05(VMHandle handle) = 0;
	virtual void		IObjectManagerInterface_Unk_06(VMHandle handle) = 0;
	virtual void		IObjectManagerInterface_Unk_07(VMHandle handle) = 0;
	virtual void		IObjectManagerInterface_Unk_08(UInt32 arg1) = 0;
	virtual bool		CreateScriptObject(const BSFixedString &className, UInt32 numProperties, BSScriptObjectPtr &objPtr) = 0;
	virtual bool		SetProperty(BSScriptObjectPtr &objPtr, void *property, bool arg3) = 0;

	// void **	_vtbl			// 00 - 01147C88
};


// 04 - VMState+000C
class IUnknown_01148030
{
public:
	virtual ~IUnknown_01148030();		// 00C334A0

	virtual void	IUnknown_01148030_Unk01(UInt32 arg1, UInt32 arg2, UInt32 arg3) = 0;
	virtual void	IUnknown_01148030_Unk02(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4) = 0;
	virtual void	IUnknown_01148030_Unk03(UInt32 arg1) = 0;
	virtual void	IUnknown_01148030_Unk04(void) = 0;
	virtual void	IUnknown_01148030_Unk05(void) = 0;
	virtual void	IUnknown_01148030_Unk06(void) = 0;
	virtual void	IUnknown_01148030_Unk07(void) = 0;
	virtual UInt32	IUnknown_01148030_Unk08(UInt32 arg1) = 0;
	virtual void	IUnknown_01148030_Unk09(UInt32 arg1, UInt32 arg2) = 0;
	virtual void	IUnknown_01148030_Unk0A(void) = 0;
	virtual void	IUnknown_01148030_Unk0B(void) = 0;
	virtual void	IUnknown_01148030_Unk0C(void) = 0;
	virtual void	IUnknown_01148030_Unk0D(void) = 0;
	virtual void	IUnknown_01148030_Unk0E(void) = 0;
	virtual void	IUnknown_01148030_Unk0F(void) = 0;
	virtual void	IUnknown_01148030_Unk10(void) = 0;
	virtual void	IUnknown_01148030_Unk11(void) = 0;
	virtual void	IUnknown_01148030_Unk12(void) = 0;
	virtual void	IUnknown_01148030_Unk13(void) = 0;
	virtual void	IUnknown_01148030_Unk14(void) = 0;
	virtual void	IUnknown_01148030_Unk15(void) = 0;

	// @members
	//void		**_vtbl;		// 00 - 01148030
};


// 4B04
// the same type as VMClassRegistry in skse
// this does more than hold on to class registrations, but for now that's all we care about
class VMState :	public BSScript::IVirtualMachine,	// 00
	public IObjectManagerInterface,		// 08
	public IUnknown_01148030,			// 0C
	public IUnknown_0112197C			// 10
{
public:
	using BSScriptObject = BSScript::BSScriptObject;
	using BSScriptClass = BSScript::BSScriptClass;
	using BSScriptType = BSScript::BSScriptType;
	using BSScriptVariable = BSScript::BSScriptVariable;
	using BSScriptArray = BSScript::BSScriptArray;
	using BSScriptStack = BSScript::BSScriptStack;
	using IFunction = BSScript::IFunction;
	using IFunctionArguments = BSScript::IFunctionArguments;
	using BSScriptObjectPtr = BSScript::BSScriptObjectPtr;
	using BSScriptClassPtr = BSScript::BSScriptClassPtr;
	using BSScriptArrayPtr = BSScript::BSScriptArrayPtr;
	using BSScriptStackPtr = BSScript::BSScriptStackPtr;
	using IFunctionPtr = BSScript::IFunctionPtr;
	using IStackCallbackFunctorPtr = BSScript::IStackCallbackFunctorPtr;
	using IFuncCallQueryPtr = BSScript::IFuncCallQueryPtr;
	using IForEachScriptObjectFunctor = BSScript::IForEachScriptObjectFunctor;


	virtual ~VMState();																												// 00 00C5B770

	// @override class IVMStateBase : (vtbl=0114C1B0)
	virtual void	Unk_01(void *logger) override;																							// 01 00C5B730 - called from 008D83C8, logger=01B334F0 (vtbl 01149B98, no rtti)
	virtual void	TraceStack(const char* str, UInt32 stackID, UInt32 aiSeverity = 0) override;											// 02 00C49A30
	virtual void	Unk_03(VMHandle handle) override;																						// 03 00C47080 - called when script property is missing.
	virtual void	OnUpdate(float arg) override;																							// 04 00C52840 - called from 008D4A73 "VM is frozen...", "VM is freezing", "VM is thawing"
	virtual void	OnUpdateGameTime(float arg) override;																					// 05 00C472A0 - called from 008C7778, , This will not be called if the game is in menu mode.
	virtual void	OnUnk06(bool arg) override;																								// 06 00C47070 { this->unk4158 = arg1; } called from 008D540B
	virtual bool	OnChangeVMState(void) override;																							// 07 00C474C0
	virtual void	RegisterForm(UInt32 typeID, const char *papyrusClassName) override;														// 08 00C4BCB0
	virtual bool	GetScriptClassByName(const BSFixedString &className, BSScriptClassPtr &outClassPtr) override;							// 09 00C4AD30
	virtual bool	GetScriptClassByTypeID(UInt32 typeID, BSScriptClassPtr &outClass) override;												// 0A 00C4AC20
	virtual bool	RegisterScriptClass(const BSFixedString &className, BSScriptClassPtr &classPtr) override;								// 0B 00C49CA0
	virtual bool	GetScriptClassByTypeID2(UInt32 typeID, BSScriptClassPtr &outClass) override;											// 0C 00C49B10
	virtual bool	GetFormTypeID(const BSFixedString &className, UInt32 &typeID) override;													// 0D 00C49DC0
	virtual void	Unk_0E(UInt32 arg1) override;																							// 0E 00C489C0
	virtual bool	Unk_0F(const UInt32 &typeID, BSScriptClassPtr &classPtr) override;														// 0F 00C4ADA0
	virtual bool	Unk_10(UInt32 arg1) override;																							// 10 00C47DE0
	virtual bool	Unk_11(UInt32 arg1) override;																							// 11 00C49E50
	virtual void	Unk_12(UInt32 arg1, UInt32 arg2) override;																				// 12 00C554E0 - added in 1.6.86
	virtual bool	CreateScriptObjectWithProperty(const BSFixedString &className, void *property, BSScriptObjectPtr &objPtr) override;		// 13 00C47500
	virtual bool	CreateScriptObject(const BSFixedString &className, BSScriptObjectPtr &result) override;									// 14 00C4ED90
	virtual bool	CreateScriptArray(const BSScriptType &type, UInt32 size, BSScriptArrayPtr &arrayPtr) override;						// 15 00C4A060
	virtual bool	CreateScriptArray2(VMTypeID typeID, const BSFixedString &className, UInt32 size, BSScriptArrayPtr &arrayPtr) override;	// 16 00C49F90
	virtual void	RegisterFunction(BSScript::IFunction * fn) override;																	// 17 00C4D420
	virtual void	SetFunctionFlagsEx(const char * className, UInt32 unk0, const char * fnName, UInt32 flags) override;					// 18 00C4A160
	virtual void	SetFunctionFlags(const char * className, const char * fnName, UInt32 flags) override;									// 19 00C47120
	virtual void	VisitScripts(VMHandle handle, IForEachScriptObjectFunctor *functor) override;											// 1A 00C4BF60
	virtual bool	ResolveScriptObject(VMHandle handle, const char *className, BSScriptObjectPtr &result) override;						// 1B 00C4D5F0
	virtual void	Unk_1C(VMHandle arg1, VMHandle arg2) override;																			// 1C 00C52C70
	virtual void	Unk_1D(VMHandle handle) override;																						// 1D 00C4C020
	virtual bool	CastScriptObject(const BSScriptObjectPtr &fromObjPtr, const BSScriptClassPtr &toClassPtr, BSScriptObjectPtr &toObjPtr) override;	// 1E 00C48B90
	virtual bool	SetObjectProperty(BSScriptObjectPtr &obj, const char *propertyName, BSScriptVariable &setVal) override;					// 1F 00C4F4D0 - only works with a property on the conditional scripts.
	virtual bool	GetObjectProperty(BSScriptObjectPtr &obj, const char *propertyName, BSScriptVariable &getVal) override;					// 20 00C4F800 - only works with a property on the conditional scripts.
	virtual bool	ExtractValue(const BSScriptObjectPtr &objPtr, UInt32 index, BSScriptVariable &out) override;							// 21 00C47E90
	virtual bool	ExtractValueFromHandle(VMHandle handle, const BSFixedString & className, SInt32 variableIndex, BSScriptVariable & out) override;	// 22 00C48D60
	virtual void	QueueEvent(VMHandle handle, const BSFixedString &eventName, IFunctionArguments * args) override;						// 23 00C4C160
	virtual bool	QueueEventAll(const BSFixedString & eventName, IFunctionArguments * args) override;										// 24 00C48E40
	virtual bool	CallStaticFunction(const BSFixedString &className, const BSFixedString &fnName, IFunctionArguments *args, IStackCallbackFunctorPtr &result) override;	// 25 00C4FA10 - "error: Unable to call static function %s on object %s due to stack creation failure or queue full, call ignored."
	virtual bool	CallMemberFunction(BSScriptObjectPtr &obj, const BSFixedString &fnName, IFunctionArguments *args, IStackCallbackFunctorPtr &result) override;		// 26 00C4FCE0 - "error: Unable to call member function %s on object %s due to stack creation failure or queue full, call ignored."
	virtual bool	CallMemberFunctionFromHandle(VMHandle handle, const BSFixedString &className, const BSFixedString &fnName, IFunctionArguments *args, IStackCallbackFunctorPtr &result) override;	// 27 00C48F10
	virtual bool	Unk_28(VMHandle handle, BSScriptClassPtr &arg3, UInt32 arg4, UInt32 arg5, UInt32 arg6) override;						// 28 00C4B130
	virtual bool	IsWaitingStack(UInt32 stackID) override;																				// 29 00C4A420
	virtual void	SetLatentReturn(UInt32 stackID, const BSScriptVariable &val) override;													// 2A 00C50410 - "Received a latent return for stack %d, but stack is not waiting on a latent - ignoring."
	virtual BSScript::ErrorLogger			* GetLogger(void) override;																		// 2B 00C47140 { return logger; } probably not used
	virtual SkyrimScript::HandlePolicy		* GetHandlePolicy(void) override;																// 2C 00C47170 { return unk048.handlePolicy; }
	virtual BSScript::IObjectHandlePolicy	* GetHandlePolicy2(void) override;																// 2D 00C47150 { return unk048.handlePolicy; } - probably not used
	virtual SkyrimScript::ObjectBindPolicy	* GetObjectBindPolicy(void) override;															// 2E 00C47180 { return unk048.bindPolicy; }- called from 00440485, 004517C5, 008B6216
	virtual BSScript::ObjectBindPolicy		* GetObjectBindPolicy2(void) override;															// 2F 00C47170 { return unk048.bindPolicy; } - probably not used
	virtual BSScript::ISavePatcherInterface	* GetSavePatcher(void) override;																// 30 00C47190 { return unk048.savePatcher; }
	virtual void	AddLogEventSink(BSTEventSink<BSScript::LogEvent> *sink) override;														// 31 00C4A4C0 { logger->AddEventSink(sink) override; }
	virtual void	RemoveLogEventSink(BSTEventSink<BSScript::LogEvent> *sink) override;													// 32 00C4A500 { logger->RemoveEventSink(sink) override; }
	virtual void	AddStatsEventSink(BSTEventSink<BSScript::StatsEvent> *sink) override;													// 33 00C4A540 { statsEventSource.AddEventSink(sink) override; }
	virtual void	RemoveStatsEventSink(BSTEventSink<BSScript::StatsEvent> *sink) override;												// 34 00C4A580 { statsEventSource.RemoveEventSink(sink) override; }

	// @override class IObjectManagerInterface : (vtbl=0114C180)
	virtual VMHandle	GetHandle(const BSScriptObjectPtr &objPtr) override;										// 01 00C47330
	virtual bool		IObjectManagerInterface_Unk_02(const BSFixedString &className, VMHandle handle) override;	// 02 00C47F50
	virtual void		BindObject(BSScriptObjectPtr &objPtr, VMHandle handle, bool bCounditional) override;		// 03 00C480E0
	virtual void		RegisterObject(BSScriptObjectPtr &objPtr, VMHandle handle, bool bCounditional) override;	// 04 00C52E20 - called in BindObject
	virtual void		IObjectManagerInterface_Unk_05(VMHandle handle) override;									// 05 00C530B0 - DeleteHandle ?
	virtual void		IObjectManagerInterface_Unk_06(VMHandle handle) override;									// 06 00C531A0
	virtual void		IObjectManagerInterface_Unk_07(VMHandle handle) override;									// 07 00C53320
	virtual void		IObjectManagerInterface_Unk_08(UInt32 arg1) override;										// 08 00C534A0
	virtual bool		CreateScriptObject(const BSFixedString &className, UInt32 numProperties, BSScriptObjectPtr &objPtr) override;	// 09 00C48A30
	virtual bool		SetProperty(BSScriptObjectPtr &objPtr, void *property, bool arg3) override;					// 0A 00C4EDD0 - "%s does not have a property named %s, property skipped."

	// @override class IUnknown_01148030 : (vtbl=0114C128)
	virtual void	IUnknown_01148030_Unk01(UInt32 arg1, UInt32 arg2, UInt32 arg3) override;						// 01 00C4CF10 - "Failed to write string table for internal VM save data"
	virtual void	IUnknown_01148030_Unk02(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4) override;			// 02 00C544D0 - "Failed to load string table for internal VM save data" "VM Save file version number is too new. Expected %u or lower, found %u"
	virtual void	IUnknown_01148030_Unk03(UInt32 arg1) override;													// 03 00C47E50
	virtual void	IUnknown_01148030_Unk04(void) override;															// 04 00C470D0 { return [ECX+4ACC] }
	virtual void	IUnknown_01148030_Unk05(void) override;															// 05 00C472D0
	virtual void	IUnknown_01148030_Unk06(void) override;															// 06 00C4E050
	virtual void	IUnknown_01148030_Unk07(void) override;															// 07 00C51780
	virtual UInt32	IUnknown_01148030_Unk08(UInt32 arg1) override;													// 08 00c470e0 { return arg1; }
	virtual void	IUnknown_01148030_Unk09(UInt32 arg1, UInt32 arg2) override;										// 09 00C470F0 { return; }
	//...

	// @override class IUnknown_0112197C : (vtbl=0114C120)
	virtual void	IUnknown_0112197C_Unk01(void) override;		// 00C4D2D0


	void VisitScripts(VMHandle handle, std::function<UInt32(BSScriptObject*, bool)> func);
	bool ExtractValue(const BSScriptObjectPtr &objPtr, const BSFixedString &name, BSScriptVariable &out);
	bool ExtractValue(const BSScriptVariable &var, const BSFixedString &name, BSScriptVariable &out);
	bool GetScriptVariable(VMHandle handle, const BSFixedString &className, const BSFixedString &variableName, BSScriptVariable &out);

	inline bool ExtractValue(VMHandle handle, const BSFixedString & className, SInt32 variableIndex, BSScriptVariable & out)
	{
		return ExtractValueFromHandle(handle, className, variableIndex, out);
	}
	inline bool CreateScriptArray(VMTypeID typeID, const BSFixedString &className, UInt32 size, BSScriptArrayPtr &arrayPtr)
	{
		CreateScriptArray2(typeID, className, size, arrayPtr);
	}
	inline bool CallScriptFunction(const BSFixedString &className, const BSFixedString &fnName, IFunctionArguments *args, IStackCallbackFunctorPtr &result)
	{
		return CallStaticFunction(className, fnName, args, result);
	}
	inline bool CallScriptFunction(BSScriptObjectPtr &objPtr, const BSFixedString &fnName, IFunctionArguments *args, IStackCallbackFunctorPtr &result)
	{
		return CallMemberFunction(objPtr, fnName, args, result);
	}
	inline bool CallScriptFunction(VMHandle handle, const BSFixedString &className, const BSFixedString &fnName, IFunctionArguments *args, IStackCallbackFunctorPtr &result)
	{
		return CallMemberFunctionFromHandle(handle, className, fnName, args, result);
	}

	template <class Ty>
	bool GetScriptVariable(Ty *pObject, const BSFixedString &className, const BSFixedString &variableName, BSScriptVariable &out)
	{
		SkyrimScript::HandlePolicy *policy = GetHandlePolicy();
		VMHandle handle = policy->Create(Ty::kTypeID, pObject);
		if (!policy->IsValidHandle(handle))
			return false;

		return GetScriptVariable(handle, className, variableName, out);
	}

	BSScriptStack *	GetStack(UInt32 stackId);
	bool			GetStack(UInt32 stackId, BSScriptStackPtr &stackPtr);

	DEFINE_MEMBER_FN_const(FindMemberFunction, bool, 0x00C48370, const BSScriptClassPtr &classPtr, const BSFixedString &fnName, const BSFixedString &stateName, BSScriptClassPtr &foundClassPtr, IFunctionPtr &foundFuncPtr);

	DEFINE_MEMBER_FN(AllocateArray, bool, 0x00C49670, const VMTypeID &typeID, UInt32 size, BSScriptArrayPtr &arr);
	DEFINE_MEMBER_FN(CreateStack, void, 0x00C4E2D0, UInt32 arg1, IStackCallbackFunctorPtr &callbackPtr, BSScriptStackPtr &stack);
	DEFINE_MEMBER_FN(CreateStack2, void, 0x00C4DA30, UInt32 stackID, UInt32 arg1, IStackCallbackFunctorPtr &callbackPtr, BSScriptStackPtr &stack);
	DEFINE_MEMBER_FN(QueueStack, bool, 0x00C48FB0, BSScriptStack *stack, IFuncCallQueryPtr &queryPtr);
	DEFINE_MEMBER_FN(InitScriptObject, void, 0x00C4E400, BSScriptObjectPtr &objPtr);	// "error: Unable to call member function OnInit on object %s due to stack creation failure or queue full, call ignored."


	// 1C
	class PolicyHolder
	{
	public:
		// @members
		BSScript::MemoryPagePolicy				* memoryPagePolicy;		// 00 (48) - 01B333C4 - skyrimVM+010C
		SkyrimScript::HandlePolicy				* handlePolicy;			// 04 (4C) - 01B33578 - skyrimVM+01B8
		SkyrimScript::ObjectBindPolicy			* bindPolicy;			// 08 (50) - 01B335C4 - skyrimVM+0204
		SkyrimVM								* skyrimVM;				// 0C (54) - 01B333C0
		BSScript::IStackCallbackSaveInterface	* stackCallback;		// 10 (58) - 01B333C4 - skyrimVM+0004
		void									* unk14;				// 14 (5C) - 0
		SkyrimScript::SavePatcher				* savePatcher;			// 18 (60) - 01B337C0
	};
	STATIC_ASSERT(sizeof(PolicyHolder) == 0x1C);


	struct BoundedScriptMap
	{
	public:
		// 08
		struct Data
		{
			typedef BSTPointerAndFlags<BSScriptObject> Entry;

			UInt32	len;				// 00
			union
			{
				Entry	singleEntry[1];		// (len == 1)
				Entry	* entries;			// (len > 1)
			};							// 04

			DEFINE_MEMBER_FN(Visit, void, 0x00C55880, IForEachScriptObjectFunctor *& visitor);
			DEFINE_MEMBER_FN(RemoveAt, void, 0x00C58BA0, UInt32 index);
		};

		DEFINE_MEMBER_FN(RemoveAt, void, 0x00C5B4C0, const VMHandle &handle);

		BSSpinLock						lock;		// 00 (4A18)
		BSTHashMap<VMHandle, Data>		map;		// 04 (4A20)
	};

	struct Data0C
	{
		bool	unk00;
		BSScriptStackPtr	unk04;
		IFuncCallQueryPtr	unk08;

		// dtor 00C56C70
	};

	// 08 - VMState::unk4134
	class UnkClass_0114A8AC
	{
	public:
		virtual ~UnkClass_0114A8AC();

		// @members
		//void		** _vtbl;		// 00 - 0114A8AC
		UInt32		lockValue;		// 04
	};


	// @members
	//void										** _vtbl;							// 0000 - 0114C1B0
	BSTEventSource<BSScript::StatsEvent>		statsEventSource;					// 0014
	SkyrimScript::Logger						* logger;							// 0044
	PolicyHolder								policies;							// 0048
	BSSpinLock									classListLock;						// 0064
	BSScript::UnlinkedTypes						unlinkedClassList;					// 006C
	BSTHashMap<BSFixedString, BSScriptClass *>	linkedClassMap;						// 00B4
	BSTHashMap<UInt32, BSFixedString>			typeToClassNameMap;					// 00D4
	BSTHashMap<BSFixedString, UInt32>			classNameToTypeMap;					// 00F4
	void										* unk114;							// 0114 - dtor 00C5544C
	UInt32										unk118;								// 0118
	UInt32										unk11C;								// 011C
	BSSpinLock									unk120;								// 0120
	void										* unk128;							// 0128 - vtbl ???????? - parent 0115A2B8
	UInt32										unk0128[(0x49B8 - 0x012C) >> 2];	// 012C
																					// 4134 - vtbl 0114A8AC - dtor 00C56F50 - parent vtbl 01122D2C
																					// 4148 - BSTArray<Data0C> 
																					// 4154 - UInt32
																					// 4160 - vtbl 0114A8C8
																					// 4574 - vtbl 0114A8C8
	BSSpinLock									stackLock;							// 49B8
	BSTHashMap<UInt32, BSScriptStackPtr>		allStacks;							// 49C0
	BSTHashMap<UInt32, BSScriptStackPtr>		waitingStacks;						// 49E0
	UInt32										nextEmptyStackID;					// 4A00
	UInt32										unk4A00[(0x4A18 - 0x4A04) >> 2];	// 4A04
	BoundedScriptMap							boundedScriptMap;					// 4A18
	UInt32										unk4A40[(0x4A50 - 0x4A40) >> 2];	// 4A40
	BSSpinLock									unk4A50;							// 4A50 - script array lock ?
	UInt32										unk4A58[(0x4A68 - 0x4A58) >> 2];	// 4A58
	BSSpinLock									unk4A68;							// 4A68
	BSTArray<BSScriptObject *>					unk4A70;							// 4A70
	UInt32										unk4A7C[(0x4B04 - 0x4A7C) >> 2];	// 4A7C

private:
	DEFINE_MEMBER_FN(ctor, VMState*, SkyrimScript::Logger *logger, UnkClass_01B334CC arg2);
	DEFINE_MEMBER_FN(dtor, void, 0x00C551D0);
};
STATIC_ASSERT(sizeof(VMState) == 0x4B04);
STATIC_ASSERT(offsetof(VMState, unlinkedClassList) == 0x006C);
STATIC_ASSERT(offsetof(VMState, stackLock) == 0x49B8);
STATIC_ASSERT(offsetof(VMState, boundedScriptMap) == 0x4A18);

inline void GetVMState(BSTSmartPointer<VMState> &state)
{
	typedef void(*Fn)(BSTSmartPointer<VMState> &);
	Fn fn = (Fn)0x0043C9C0;
	fn(state);
}

DEPRECATED_TYPEDEF(VMState, VMClassRegistry);
