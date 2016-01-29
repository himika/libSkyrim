#include "Skyrim.h"
#include "Skyrim/BSScript/BSScriptPackUnpack.h"
#include "Skyrim/VMArray.h"

namespace BSScript
{
	static void BindID(BSScriptObjectPtr &objectPtr, void * srcData, VMState * state, IObjectHandlePolicy * handlePolicy, UInt32 typeID)
	{
		UInt32	id = 0;
		BSScriptClassPtr classPtr = objectPtr->GetClass();

		if (state->GetFormTypeID(classPtr->GetName(), id))
		{
			VMHandle handle = handlePolicy->Create(typeID, srcData);

			if (handlePolicy->IsType(id, handle) || handle == handlePolicy->GetInvalidHandle())
				state->GetObjectBindPolicy()->BindObject(objectPtr, handle);
		}
	}

	VMTypeID GetTypeIDFromFormTypeID(UInt32 formTypeID, VMState * state)
	{
		VMTypeID	result = 0;
		BSScriptClassPtr classPtr = nullptr;

		if (state->GetScriptClassByTypeID(formTypeID, classPtr) && classPtr)
			result = classPtr->GetTypeID();

		return result;
	}

	void PackHandle(BSScriptVariable * dst, void * src, UInt32 typeID, VMState * state)
	{
		dst->SetNone();

		if (!src)
			return;


		BSScriptClassPtr classPtr;
		state->GetScriptClassByTypeID(typeID, classPtr);
		if (!classPtr)
			return;

		auto handlePolicy = state->GetHandlePolicy();
		VMHandle handle = handlePolicy->Create(typeID, src);

		BSScriptObjectPtr objectPtr;
		if (!state->ResolveScriptObject(handle, classPtr->GetName(), objectPtr))
		{
			// when cannot be resolved, then create new objectPtr
			if (state->CreateScriptObject(classPtr->GetName(), objectPtr) && objectPtr)
			{
				// create handle and bind it to the new objectPtr
				BindID(objectPtr, src, state, handlePolicy, typeID);
			}
		}

		if (objectPtr)
			dst->SetObject(objectPtr, classPtr->GetTypeID());
	}

	void * UnpackHandle(const BSScriptVariable * src, UInt32 typeID)
	{
		void* result = nullptr;

		const BSScriptObject* objectPtr = src->GetObject();
		if (objectPtr)
		{
			BSScript::IObjectHandlePolicy* policy = g_objectHandlePolicy;
			VMHandle handle = objectPtr->GetHandle();
			if (policy->IsType(typeID, handle) && policy->IsValidHandle(handle))
				result = policy->Resolve(typeID, handle);
		}

		return result;
	}
}
