#pragma once

#include "BSScript/BSScript.h"
#include "BSScript/BSScriptObject.h"
#include "BSScript/BSScriptObjectBindPolicy.h"
#include "BSScript/BSScriptIObjectHandlePolicy.h"
#include "BSCore/BSSpinLock.h"
#include "BSCore/BSTHashMap.h"


class IObjectManagerInterface;


namespace SkyrimScript
{
	struct StatsEvent
	{
	};

	// type_info: 0123F9E8
	class BaseHandleReaderWriter : public BSScript::IHandleReaderWriter
	{
	};

	/*==============================================================================
	class SkyrimScript::DataFileHandleReaderWriter +0000 (_vtbl=0107CB74)
	0000: class SkyrimScript::DataFileHandleReaderWriter
	0000: |   class SkyrimScript::BaseHandleReaderWriter
	0000: |   |   struct BSScript::IHandleReaderWriter
	==============================================================================*/
	// type_info: 0123FA1C
	class DataFileHandleReaderWriter : public BaseHandleReaderWriter
	{
	};


	/*==============================================================================
	class SkyrimScript::SaveFileHandleReaderWriter +0000 (_vtbl=010EB0D8)
	0000: class SkyrimScript::SaveFileHandleReaderWriter
	0000: |   class SkyrimScript::BaseHandleReaderWriter
	0000: |   |   struct BSScript::IHandleReaderWriter
	==============================================================================*/
	class SaveFileHandleReaderWriter : public BaseHandleReaderWriter
	{
	};

	/*==============================================================================
	class SkyrimScript::Store +0000 (_vtbl=010EA8C8)
	0000: class SkyrimScript::Store
	0000: |   class BSScript::IStore
	0000: |   |   class BSStorage
	0004: |   |   |   struct BSIntrusiveRefCounted
	==============================================================================*/
	class Store : public BSScript::IStore
	{
		virtual ~Store();									// 008C0C90

		virtual void Unk_01(void) override;					// 008C0690
		virtual void Unk_02(void) override;					// 008C05F0
		virtual void Unk_03(void) override;					// 008C06C0
		virtual void Unk_04(void) override;					// 008C0730
		virtual void Unk_06(const char *name) override;		// 008C0810 read .pex file. called from 00C454B2 (virtual ProbablyLoader::Unk_03)
		virtual void Unk_07(void) override;					// 008C0970
		virtual void Unk_08(void) override;					// 008C0C70
		virtual void Unk_09(void) override;					// 005AFB90
		virtual void Unk_0A(void) override;					// 008C0C80
		virtual void Unk_0B(void) override;					// 008C0650
	};

	// ?
	struct Internal
	{
		/*==============================================================================
		class SkyrimScript::Internal::AnimationCallbacks +0000 (_vtbl=010EA1A8)
		0000: class SkyrimScript::Internal::AnimationCallbacks
		0004: |   struct BSIntrusiveRefCounted
		0000: |   class BSTEventSink<struct BSAnimationGraphEvent>
		==============================================================================*/
		// type_info: 012B6408
		struct AnimationCallbacks
		{
		};

		/*==============================================================================
		class SkyrimScript::Internal::CallbackList +0000 (_vtbl=010EA1B4)
		0000: class SkyrimScript::Internal::CallbackList
		0004: |   struct BSIntrusiveRefCounted
		==============================================================================*/
		// type_info: 012B6440
		class CallbackList
		{
		};

		class IProfileCallQuery
		{
		};
	};

	/*==============================================================================
	class SkyrimScript::DelayFunctorFactory +0000 (_vtbl=010EA1CC)
	0000: class SkyrimScript::DelayFunctorFactory
	==============================================================================*/
	// type_info: 012B6474
	class DelayFunctorFactory
	{
	public:
		virtual ~DelayFunctorFactory();				// 008AF370

		virtual void Unk_01(void);					// (pure)
		virtual void Unk_02(void);					// (pure)

		// @members
		// void **	_vtbl		// 00 - 010EA1CC
	};

	/*==============================================================================
	class SkyrimScript::DelayFunctor +0000 (_vtbl=010EA1DC)
	0000: class SkyrimScript::DelayFunctor
	0004: |   struct BSIntrusiveRefCounted
	==============================================================================*/
	// type_info: 012B64A4
	class DelayFunctor : public BSIntrusiveRefCounted
	{
	public:
		virtual ~DelayFunctor();			// 008AF430

		virtual BSScript::BSScriptVariable* Unk_01(BSScript::BSScriptVariable* var) = 0;
		virtual bool	Unk_02() = 0;			// (pure)
		virtual bool	Unk_03(void);			// 0092D110 (void) { return false; }
		virtual void	Unk_04(void);			// 008AF460
		virtual UInt32	GetType(void) = 0;		// (pure)
		virtual void	Unk_06(void);			// 008AF5B0
		// @members
		// void **	_vtbl		// 00 - 010EA1DC
	};

	/*==============================================================================
	class SkyrimScript::Profiler +0000 (_vtbl=010EA744)
	0000: class SkyrimScript::Profiler
	0000: |   class BSScript::IProfilePolicy
	==============================================================================*/
	// type_info: 012B69C4
	class Profiler : public BSScript::IProfilePolicy
	{
	public:
		virtual ~Profiler();
		// void **	_vtbl		// 00 - 010EA744
	};

	/*==============================================================================
	class SkyrimScript::SavePatcher +0000 (_vtbl=010EA79C)
	0000: class SkyrimScript::SavePatcher
	0000: |   class BSScript::ISavePatcherInterface
	==============================================================================*/
	// type_info: 012B6C68
	class SavePatcher : public BSScript::ISavePatcherInterface
	{
	public:
		virtual ~SavePatcher();					// 008BF400
		virtual void Unk_01(void) override;		// 008BF480

		//void		** _vtbl		// 00 - 010EA79C
	};

	/*==============================================================================
	class SkyrimScript::Logger +0000 (_vtbl=010EA3C8)
	0000: class SkyrimScript::Logger
	0000: |   class BSScript::ErrorLogger
	0004: |   |   class BSTEventSource<struct BSScript::LogEvent>
	==============================================================================*/
	// type_info: 012B65A8
	class Logger : public BSScript::ErrorLogger
	{
	public:
		virtual ~Logger();
		// void **	_vtbl		// 00 - 010EA3C8
	};


	/*==============================================================================
	class SkyrimScript::PathingCallbackMgr +0000 (_vtbl=010EA680)
	0000: class SkyrimScript::PathingCallbackMgr
	0004: |   struct BSTSingletonSDM<class SkyrimScript::PathingCallbackMgr,struct BSTSingletonSDMOpStaticBuffer>
	0004: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class SkyrimScript::PathingCallbackMgr,struct BSTSingletonSDMOpStaticBuffer<class SkyrimScript::PathingCallbackMgr> > >
	0004: |   |   |   struct BSTSDMTraits<class SkyrimScript::PathingCallbackMgr,struct BSTSingletonSDMOpStaticBuffer<class SkyrimScript::PathingCallbackMgr> >
	0005: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class SkyrimScript::PathingCallbackMgr>
	0000: |   class BSTEventSink<struct BSPathEvent>
	==============================================================================*/
	class PathingCallbackMgr
	{
	};

	/*==============================================================================
	class SkyrimScript::QuestCallbackMgr +0000 (_vtbl=010EA790)
	0000: class SkyrimScript::QuestCallbackMgr
	000C: |   struct BSTSingletonSDM<class SkyrimScript::QuestCallbackMgr,struct BSTSingletonSDMOpStaticBuffer>
	000C: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class SkyrimScript::QuestCallbackMgr,struct BSTSingletonSDMOpStaticBuffer<class SkyrimScript::QuestCallbackMgr> > >
	000C: |   |   |   struct BSTSDMTraits<class SkyrimScript::QuestCallbackMgr,struct BSTSingletonSDMOpStaticBuffer<class SkyrimScript::QuestCallbackMgr> >
	000D: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class SkyrimScript::QuestCallbackMgr>
	0000: |   class BSTEventSink<struct TESQuestStageItemDoneEvent>
	0004: |   class BSTEventSink<struct TESQuestStartStopEvent>
	0008: |   class BSTEventSink<struct BGSEventProcessedEvent>
	==============================================================================*/
	class QuestCallbackMgr
	{
	};

	/*==============================================================================
	class SkyrimScript::SoundCallbackMgr +0000 (_vtbl=010EA804)
	0000: class SkyrimScript::SoundCallbackMgr
	0004: |   struct BSTSingletonSDM<class SkyrimScript::SoundCallbackMgr,struct BSTSingletonSDMOpStaticBuffer>
	0004: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class SkyrimScript::SoundCallbackMgr,struct BSTSingletonSDMOpStaticBuffer<class SkyrimScript::SoundCallbackMgr> > >
	0004: |   |   |   struct BSTSDMTraits<class SkyrimScript::SoundCallbackMgr,struct BSTSingletonSDMOpStaticBuffer<class SkyrimScript::SoundCallbackMgr> >
	0005: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class SkyrimScript::SoundCallbackMgr>
	==============================================================================*/
	class SoundCallbackMgr
	{
	};

	/*==============================================================================
	class SkyrimScript::HandlePolicy +0000 (_vtbl=010EBA1C)
	0000: class SkyrimScript::HandlePolicy
	0000: |   struct BSScript::IObjectHandlePolicy
	==============================================================================*/
	// 4C?
	class HandlePolicy : public BSScript::IObjectHandlePolicy
	{
	public:
		struct Data0C
		{
			UInt32	unk00;
			UInt32	unk04;
		};

		struct Data2C
		{
			UInt32	unk00;
			UInt32	unk04;
		};

		virtual ~HandlePolicy();														// 008D52E0

		virtual bool		IsType(UInt32 typeID, VMHandle handle) override;			// 008B3B20
		virtual bool		IsValidHandle(VMHandle handle) override;					// 008B3D60
		virtual VMHandle	GetInvalidHandle(void) override;							// 008B4300 { return 0x0000FFFF00000000; }
		virtual VMHandle	Create(UInt32 typeID, const void * srcData) override;		// 008B4310
		virtual bool		IsREFR(VMHandle handle) override;							// 008B39B0 { return IsType(TESObjectREFR::kTypeID, handle); }
		virtual VMHandle	Unk_06(UInt32 unk0, UInt32 unk1) override;					// 008B4430
		virtual VMHandle	Unk_07(UInt32 unk0, UInt32 unk1) override;					// 008B44F0
		virtual void *		Resolve(UInt32 typeID, VMHandle handle) override;			// 008B3E30
		virtual void		AddRef(VMHandle handle) override;							// 008B5040
		virtual void		Release(VMHandle handle) override;							// 008B51A0
		virtual void		ToString(VMHandle handle, BSFixedString &strOut) override;	// 008B3F40 { return "%s (%llX)", (className, handle); }

		template <class Ty>
		inline Ty * Resolve(VMHandle handle)
		{
			return (Ty *)Resolve(Ty::kTypeID, handle);
		}

		// @members
		// void							** _vtbl;			// 00 - 010EBA1C
		BSSpinLock						m_lock;				// 04
		BSTHashMap<VMHandle, Data0C>	unk0C;				// 0C - hash sentinel 012B90B4
		BSTHashMap<VMHandle, Data2C>	unk2C;				// 2C - hash sentinel 012B6564
	};
	STATIC_ASSERT(sizeof(HandlePolicy) == 0x4C);


	// 84-90
	class ObjectBindPolicy : public BSScript::ObjectBindPolicy
	{
	public:
		using BSScriptObjectPtr = BSScript::BSScriptObjectPtr;

		ObjectBindPolicy();
		virtual ~ObjectBindPolicy();			// 008D5BF0

		virtual void	Unk_01(UInt64 unk);
		virtual void	Unk_02(UInt64 unk);
		virtual void	Unk_03(UInt64 unk);
		virtual void	Unk_04(void);
		virtual UInt32	Unk_05(UInt32 unk0, UInt32 unk1);
		virtual void	Unk_06(UInt32 unk0, UInt32 unk1, UInt32 unk2, UInt32 unk3);
		virtual void	Unk_07(UInt32 unk0, UInt32 unk1, UInt32 unk2, UInt32 unk3, UInt32 unk4, UInt32 unk5);
		virtual bool	Unk_08(void);
		virtual void	Unk_09(UInt32 unk0, UInt32 unk1, UInt32 unk2, UInt32 unk3);
		virtual void	Unk_0A(UInt32 unk0, UInt32 unk1, UInt32 unk2, UInt32 unk3);
		virtual void	Unk_0B(UInt32 unk0, UInt32 unk1, UInt32 unk2, UInt32 unk3, UInt32 unk4);
		virtual void	Unk_0C(UInt32 unk0, UInt32 unk1, UInt32 unk2, UInt32 unk3, UInt32 unk4);

		// @members
		//void					** _vtbl;		// 00 - 010EBAD4
		UInt32					unk04;
		IObjectManagerInterface	* unk08;		// 08 - static_cast<IObjectManagerInterface*>(state);
		UInt32					unk0C;
		UInt32					unk10;
		//BSSpinLock			unk48;

		DEFINE_MEMBER_FN(BindObject, void, 0x00C2BCD0, BSScriptObjectPtr & objPtr, VMHandle handle);	//{ if (unk08) unk08->BindObject(identifier, handle, 0); }
	};
}
