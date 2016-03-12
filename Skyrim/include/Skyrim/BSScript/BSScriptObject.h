#pragma once

#include "../BSCore/BSFixedString.h"
#include "../BSSystem/BSTSmartPointer.h"
#include "../BSSystem/BSTPointerAndFlags.h"
#include "BSScriptClass.h"

// Forward declarations
namespace SkyrimScript
{
	class HandlePolicy;
}


namespace BSScript
{
	// Forward declarations
	class BSScriptVariable;
	struct IObjectHandlePolicy;

	BSSmartPointer(BSScriptObject);

	// 20 - the same type as VMIdentifier and VMScriptInstance in skse
	class BSScriptObject
	{
	public:
		enum Flag
		{
			kFlag_HasVariables = 1,
			kFlag_Unk02 = 2,
			kFlag_Unk04 = 4
		};


		BSScriptObject(const BSScriptClassPtr &a_classPtr, SkyrimScript::HandlePolicy *a_policy, UInt32 a_numProperties);		// 00C30DF0
		~BSScriptObject();		// 00C30E90

		TES_FORMHEAP_REDEFINE_NEW();

		BSScriptClass * GetClass(void)
		{
			return classPtr;
		}
		const BSScriptClass * GetClass(void) const
		{
			return classPtr;
		}
		const BSFixedString & GetState(void) const
		{
			return currentState;
		}
		bool HasVariables() const
		{
			return (flags & kFlag_HasVariables) != 0;
		}
		BSScriptVariable * GetVariables()
		{
			return reinterpret_cast<BSScriptVariable *>(this + 1);
		}
		const BSScriptVariable * GetVariables() const
		{
			return reinterpret_cast<const BSScriptVariable *>(this + 1);
		}

		VMHandle GetHandle(void) const;	// 00C307C0
		void SetHandle(VMHandle a_handle);	// 00C30830
		bool IsInvalidHandle() const;
		void GetClass(BSScriptClassPtr &classPtr) const;		// 00505F30
		void * Resolve(UInt32 typeID) const;

		template <class Ty>
		inline Ty * Resolve() const
		{
			return (Ty *)Resolve(Ty::kTypeID);
		}

		void Release()
		{
			if (DecRefCount() == 0)
				delete this;
		}

	//protected:
		SInt32	Lock(void);					// 00C30720
		void	Unlock(SInt32 oldLock);
		void	IncRefCount(void);		// 00C306A0
		SInt32	DecRefCount(void);		// 00C30720

		// @members
		unsigned int				flags			: 3;	// 00-00
		unsigned int				numProperties	: 19;	// 00-03
		BSScriptClassPtr			classPtr;				// 04
		BSFixedString				currentState;			// 08
		BSTPointerAndFlags<long>	unk0C;					// 0C - BSScriptObjectPropertyTypeInfo ?
		volatile VMHandle			handle;					// 10
		volatile long				refCount;				// 18
		//							pad for alignment;		// 1C
		//BSScriptVariable			vars[];					// 20

		static SkyrimScript::HandlePolicy *& ms_handlePolicy;

		friend struct BSTSmartPointerIntrusiveRefCount<BSScriptObject>;

	protected:
		BSScriptObject() {}

		DEFINE_MEMBER_FN(ctor, BSScriptObject *, 0x00C30DF0, const BSScriptClassPtr &classPtr, SkyrimScript::HandlePolicy *policy, UInt32 numProperties);	// called from 00C48AE1(IObjectManagerInterface::CreateScriptObject), 00C495CD
		DEFINE_MEMBER_FN(dtor, void, 0x00C30E90);
		DEFINE_MEMBER_FN(Unk_00C305D0, void, 0x00C305D0);
		DEFINE_MEMBER_FN_const(GetClass_Impl, void, 0x00505F30, BSScriptClassPtr &classPtr);
	};
	STATIC_ASSERT(offsetof(BSScriptObject, handle) == 0x10);
	STATIC_ASSERT(sizeof(BSScriptObject) == 0x20);
}
