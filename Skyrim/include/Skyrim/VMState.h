#pragma once

#include "BSCore/BSSpinLock.h"
#include "BSScript/BSScriptClass.h"
#include "BSScript/BSScriptObject.h"
#include "BSScript/BSScriptVariable.h"
#include "BSScript/BSScriptArray.h"
#include "BSScript/BSScriptObjectBindPolicy.h"
#include "BSScript/BSScriptUnlinkedTypes.h"
#include "BSScript/BSScriptStack.h"
#include "BSScript/BSScriptIForEachScriptObjectFunctor.h"
#include "SkyrimScript.h"
#include "BSCore/BSTHashMap.h"

#include <functional>


// Forward declarations
namespace BSScript
{
	template <class, class>		VMTypeID	GetTypeID(VMState * state);
	template <class _Ty, class>	void		PackValue(BSScriptVariable & dst, _Ty & src, VMState * state);
	template <class _Ty, class>	_Ty			UnpackValue(const BSScriptVariable& src);
}


class IVMStateBase
{
public:
	virtual ~IVMStateBase();

	//void	** vtbl		// 00 - 01148088
};


class IProbablyBindPolicy
{
public:
	IProbablyBindPolicy();
	virtual ~IProbablyBindPolicy();																		// 00C5B710

	using BSScriptObject = BSScript::BSScriptObject;

	virtual VMHandle	IProbablyBindPolicy_Unk_01(UInt32 arg) = 0;										// 00C47330
	virtual bool		IProbablyBindPolicy_Unk_02(UInt32 arg1, UInt32 arg2, UInt32 arg3) = 0;			// 00C47F50
	virtual void		BindObject(BSTSmartPointer<BSScriptObject> & object, VMHandle handle) = 0;		// 00C480E0
	// 00C52E20
	// 00C530B0
	// 00C531A0
	// 00C53320
	// 00C534A0
	// 00C48A30
	// 00C4EDD0

	// void **	_vtbl			// 00 - 0114C180
};


class IUnknown_0114C128
{
public:
	virtual ~IUnknown_0114C128();
};


class IUnknown_0114C120
{
public:
	virtual ~IUnknown_0114C120();
};


// 1C
class Unknown_01B334CC
{
public:
	class Unknown_01122D2C
	{
		virtual ~Unknown_01122D2C();			// 00B72260
		virtual void Unk_01(void) = 0;			// 00F51EE8
		virtual void Unk_02(void) = 0;			// 00F51EE8
		virtual void Unk_03(void) = 0;			// 00F51EE8
		virtual void Unk_04(void) = 0;			// 00F51EE8
	};

	class Unknown_01149B68 : public Unknown_01122D2C
	{
	public:
		virtual ~Unknown_01149B68();			// 00B72260
		virtual void Unk_01(void) override;		// 00C42890
		virtual void Unk_02(void) override;		// 00C428E0
		virtual void Unk_03(void) override;		// 00C42A10
		virtual void Unk_04(void) override;		// 00C42B00

		// @members
		//void **	_vtbl;		// 00 - 01149B68
		UInt32		unk04;
		UInt32		unk08;
		UInt32		unk0C;
		UInt8		unk10;
		UInt8		pad11[3];
		UInt32		unk14;
		UInt32		unk18;
		UInt32		unk1C;
		UInt32		unk20;
	};

	Unknown_01149B68				* unk00;			// 00
	SkyrimScript::HandlePolicy		* handlePolicy;		// 04
	SkyrimScript::ObjectBindPolicy	* bindPolicy;		// 08
	UInt32							pad54;				// 0C
	UInt32							pad58;				// 10
	UInt32							pad5C;				// 14
	SkyrimScript::SavePatcher		* savePatcher;		// 18;
};
STATIC_ASSERT(sizeof(Unknown_01B334CC) == 0x1C);


// 4B04
// the same type as VMClassRegistry in skse
// this does more than hold on to class registrations, but for now that's all we care about
class VMState :
	public BSIntrusiveRefCounted,		// 04
	public IVMStateBase,				// 00
	public IProbablyBindPolicy,			// 08
	public IUnknown_0114C128,			// 0C
	public IUnknown_0114C120			// 10
{
public:
	using BSScriptObject     = BSScript::BSScriptObject;
	using BSScriptClass      = BSScript::BSScriptClass;
	using BSScriptVariable   = BSScript::BSScriptVariable;
	using BSScriptArray      = BSScript::BSScriptArray;
	using BSScriptStack      = BSScript::BSScriptStack;
	using IFunction			 = BSScript::IFunction;
	using IFunctionArguments = BSScript::IFunctionArguments;

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

	virtual ~VMState();																												// 00 00C5B770

	// @override
	virtual void	Unk_01(void *logger);																							// 01 00C5B730 - called from 008D83C8, logger=01B334F0 (vtbl 01149B98, no rtti)
	virtual void	TraceStack(const char* str, UInt32 stackID, UInt32 aiSeverity = 0);												// 02 00C49A30
	virtual void	Unk_03(VMHandle handle);																						// 03 00C47080 - called when script property is missing.
	virtual void	OnUpdate(float arg);																							// 04 00C52840 - called from 008D4A73 "VM is frozen...", "VM is freezing", "VM is thawing"
	virtual void	OnUpdateGameTime(float arg);																					// 05 00C472A0 - called from 008C7778, , This will not be called if the game is in menu mode.
	virtual void	OnUnk06(bool arg);																								// 06 00C47070 { this->unk4158 = arg1; } called from 008D540B
	virtual bool	OnChangeVMState(void);																							// 07 00C474C0
	virtual void	RegisterForm(UInt32 typeID, const char * papyrusClassName);														// 08 00C4BCB0
	virtual bool	GetScriptClassByName(const BSFixedString &className, BSTSmartPointer<BSScriptClass> &outClass);					// 09 00C4AD30 { classListLock.Lock(); this->Unk_00C4A650(className, outClass); classListLock.Release(); } 
	virtual bool	GetScriptClassByTypeID(UInt32 typeID, BSTSmartPointer<BSScriptClass> &outClass);								// 0A 00C4AC20
	virtual bool	Unk_0B(UInt32 arg1, UInt32 arg2);																				// 0B 00C49CA0
	virtual bool	GetScriptClassByTypeID2(UInt32 typeID, BSTSmartPointer<BSScriptClass> &outClass);								// 0C 00C49B10
	virtual bool	GetFormTypeID(const BSFixedString & className, UInt32 & typeID);												// 0D 00C49DC0
	virtual void	Unk_0E(UInt32 arg1);																							// 0E 00C489C0
	virtual bool	Unk_0F(UInt32 arg1, UInt32 arg2);																				// 0F 00C4ADA0
	virtual bool	Unk_10(UInt32 arg1);																							// 10 00C47DE0
	virtual bool	Unk_11(UInt32 arg1);																							// 11 00C49E50
	virtual void	Unk_12(UInt32 arg1, UInt32 arg2);																				// 12 00C554E0 - added in 1.6.86
	virtual bool	Unk_13(UInt32 arg1, UInt32 arg2, UInt32 arg3);																	// 13 00C47500
	virtual bool	CreateScriptObject(const BSFixedString & className, BSTSmartPointer<BSScriptObject> &result);					// 14 00C4ED90
	virtual bool	CreateScriptArray(BSScriptVariable * value, UInt32 size, BSTSmartPointer<BSScriptArray> &arrayPtr);				// 15 00C4A060
	virtual bool	Unk_16(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4);														// 16 00C49F90
	virtual void	RegisterFunction(BSScript::IFunction * fn);																		// 17 00C4D420
	virtual void	SetFunctionFlagsEx(const char * className, UInt32 unk0, const char * fnName, UInt32 flags);						// 18 00C4A160
	virtual void	SetFunctionFlags(const char * className, const char * fnName, UInt32 flags);									// 19 00C47120
	virtual void	VisitScripts(VMHandle handle, BSScript::IForEachScriptObjectFunctor * functor);									// 1A 00C4BF60
	virtual bool	ResolveScriptObject(VMHandle handle, const char * className, BSTSmartPointer<BSScriptObject> &result);			// 1B 00C4D5F0
	virtual void	Unk_1C(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4);														// 1C 00C52C70
	virtual void	Unk_1D(UInt32 arg1, UInt32 arg2);																				// 1D 00C4C020
	virtual bool	Unk_1E(UInt32 arg1, UInt32 arg2, UInt32 arg3);																	// 1E 00C48B90
	virtual bool	SetObjectProperty(BSTSmartPointer<BSScriptObject> &obj, const char *propertyName, BSScriptVariable &setVal);	// 1F 00C4F4D0 - "%s does not have a property named %s." "Cannot set property "%s" on a None object."
	virtual bool	GetObjectProperty(BSTSmartPointer<BSScriptObject> &obj, const char *propertyName, BSScriptVariable &getVal);	// 20 00C4F800 - "%s does not have a property named %s." "Cannot get property "%s" on a None object."
	virtual bool	Unk_21(UInt32 arg1, UInt32 arg2, UInt32 arg3);																	// 21 00C47E90
	virtual bool	ExtractValue(VMHandle handle, const BSFixedString & className, SInt32 variableIndex, BSScriptVariable & out);	// 22 00C48D60
	virtual void	QueueEvent(VMHandle handle, const BSFixedString & eventName, IFunctionArguments * args);						// 23 00C4C160
	virtual bool	Unk_24(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4, UInt32 arg5, UInt32 arg6);							// 24 00C48E40
	virtual bool	CallStaticFunction(const BSFixedString &objName, const BSFixedString &fnName, IFunctionArguments *args, BSScriptVariable &result);
																																	// 25 00C4FA10 - "error: Unable to call static function %s on object %s due to stack creation failure or queue full, call ignored."
	virtual bool	CallMemberFunction(BSTSmartPointer<BSScriptObject> &obj, const BSFixedString &fnName, IFunctionArguments * args, BSScriptVariable &result);
																																	// 26 00C4FCE0 - "error: Unable to call member function %s on object %s due to stack creation failure or queue full, call ignored."
	virtual bool	Unk_27(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4, UInt32 arg5, UInt32 arg6);							// 27 00C48F10
	virtual bool	Unk_28(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4, UInt32 arg5, UInt32 arg6);							// 28 00C4B130
	virtual bool	Unk_29(UInt32 arg1);																							// 29 00C4A420
	virtual void	Unk_2A(UInt32 arg1, UInt32 arg2);																				// 2A 00C50410 - "Received a latent return for stack %d, but stack is not waiting on a latent - ignoring."
	virtual BSScript::ErrorLogger			* GetLogger(void);																		// 2B 00C47140 { return logger; } probably not used
	virtual SkyrimScript::HandlePolicy		* GetHandlePolicy(void);																// 2C 00C47170
	virtual BSScript::IObjectHandlePolicy	* GetHandlePolicy2(void);																// 2D 00C47150 - probably not used
	virtual SkyrimScript::ObjectBindPolicy	* GetObjectBindPolicy(void);															// 2E 00C47180 - called from 00440485, 004517C5, 008B6216
	virtual BSScript::ObjectBindPolicy		* GetObjectBindPolicy2(void);															// 2F 00C47170 - probably not used
	virtual BSScript::ISavePatcherInterface	* GetSavePatcher(void);																	// 30 00C47190 { return unk048.savePatcher; }
	virtual void	AddLogEventSink(BSTEventSink<BSScript::LogEvent> *sink);														// 31 00C4A4C0 { logger->AddEventSink(sink); }
	virtual void	RemoveLogEventSink(BSTEventSink<BSScript::LogEvent> *sink);														// 32 00C4A500 { logger->RemoveEventSink(sink); }
	virtual void	AddStatsEventSink(BSTEventSink<BSScript::StatsEvent> *sink);													// 33 00C4A540 { statsEventSource.AddEventSink(sink); }
	virtual void	RemoveStatsEventSink(BSTEventSink<BSScript::StatsEvent> *sink);													// 34 00C4A580 { statsEventSource.RemoveEventSink(sink); }


	void			VisitScripts(VMHandle handle, std::function<bool(BSScriptObject*, bool)> func);
	bool			ExtractValue(BSScriptVariable &var, const BSFixedString &name, BSScriptVariable &out);
	bool			GetScriptVariable(VMHandle handle, const BSFixedString &className, const BSFixedString &variableName, BSScriptVariable &out);
	BSScriptStack *	GetStack(UInt32 stackId);

	template <class Ty>
	bool GetScriptVariable(Ty *pObject, const BSFixedString &className, const BSFixedString &variableName, BSScriptVariable &out)
	{
		SkyrimScript::HandlePolicy *policy = GetHandlePolicy();
		VMHandle handle = policy->Create(Ty::kTypeID, pObject);
		if (!policy->IsValidHandle(handle))
			return false;

		return GetScriptVariable(handle, className, variableName, out);
	}

	DEFINE_MEMBER_FN(AllocateArray, bool, 0x00C49670, VMTypeID& typeID, UInt32 size, BSTSmartPointer<BSScriptArray>& arr);
	DEFINE_MEMBER_FN(CreateStack, void, 0x00C4E2D0, UInt32 arg1, void * arg2, BSTSmartPointer<BSScriptStack> & stack);
	

	struct BoundScriptMap
	{
	public:
		struct Array
		{
			UInt32	count;
			union
			{
				UInt32	singleEntry;
				UInt32	* entries;
			};

			DEFINE_MEMBER_FN(Call, void, 0x00C55880, BSScript::IForEachScriptObjectFunctor *);
		};

		BSSpinLock					lock;		// 00 (4A18)
		BSTHashMap<UInt64, Array>	map;		// 04 (4A20)
	};


	// @members
	//void										** _vtbl;							// 0000 - 0114C1B0
	BSTEventSource<BSScript::StatsEvent>		statsEventSource;					// 0014
	SkyrimScript::Logger						* logger;							// 0044
	Unknown_01B334CC							unk048;								// 0048
	BSSpinLock									classListLock;						// 0064
	BSScript::UnlinkedTypes						unlinkedClassList;					// 006C
	BSTHashMap<BSFixedString, BSScriptClass *>	linkedClassMap;						// 00B4
	BSTHashMap<UInt32, BSFixedString>			typeToClassNameMap;					// 00D4
	BSTHashMap<BSFixedString, UInt32>			classNameToTypeMap;					// 00F4
	UInt32										unk0114[(0x49B8 - 0x0114) >> 2];	// 0114
																					// 4134 - vtbl 0114A8AC
																					// 4160 - vtbl 0114A8C8
																					// 4574 - vtbl 0114A8C8

	BSSpinLock									stackLock;							// 49B8
	BSTHashMap<UInt32, BSScriptStack *>			allStacks;							// 49C0
	BSTHashMap<UInt32, BSScriptStack *>			waitingStacks;						// 49E0
	
	UInt32										unk4A00[(0x4A18 - 0x4A00) >> 2];	// 4A00

	BoundScriptMap								boundScriptMap;						// 4A18
	//BSSpinLock								unk4A18;							// 4A18
	//BSTHashMap<UInt64, void*>					unk4A20;							// 4A20

	UInt32										unk4A40[(0x4B04 - 0x4A40) >> 2];	// 4A40

private:
	DEFINE_MEMBER_FN(ctor, VMState*, SkyrimScript::Logger *logger, Unknown_01B334CC arg2);
	DEFINE_MEMBER_FN(dtor, void, 0x00C551D0);
};
STATIC_ASSERT(sizeof(VMState) == 0x4B04);
STATIC_ASSERT(offsetof(VMState, unlinkedClassList) == 0x006C);
STATIC_ASSERT(offsetof(VMState, stackLock) == 0x49B8);

inline void GetVMState(BSTSmartPointer<VMState> &state)
{
	typedef void(*Fn)(BSTSmartPointer<VMState> &);
	Fn fn = (Fn)0x0043C9C0;
	fn(state);
}

DEPRECATED_TYPEDEF(VMState, VMClassRegistry);
