#include "Skyrim.h"
#include "Skyrim/VMState.h"
#include "Skyrim/SkyrimVM.h"

using BSScript::BSScriptClass;
using BSScript::BSScriptStack;


bool VMState::GetScriptVariable(VMHandle handle, const BSFixedString & className, const BSFixedString & variableName, BSScript::BSScriptVariable & out)
{
	BSTSmartPointer<BSScriptClass> classInfo;

	if (GetScriptClassByName(className, classInfo) && classInfo)
	{
		int index = classInfo->GetVariableIndex(variableName);
		if (index > 0 && ExtractValue(handle, className, index, out))
			return true;
	}

	return false;
}


BSScriptStack* VMState::GetStack(UInt32 stackId)
{
	BSScriptStack* result = nullptr;

	stackLock.Lock();
	auto it = allStacks.find(stackId);
	if (it != allStacks.cend())
		result = it->value;
	stackLock.Unlock();

	return result;
}


void VMState::VisitScripts(VMHandle handle, std::function<bool(BSScript::BSScriptObject*, bool)> func)
{
	class ForEachScriptObjectFunctor : public BSScript::IForEachScriptObjectFunctor
	{
	public:
		typedef std::function<bool(BSScript::BSScriptObject*, bool)> visitor_type;

		ForEachScriptObjectFunctor(visitor_type a_func) : m_func(a_func) {}
		virtual bool Visit(BSScript::BSScriptObject * object, bool bConditional) override {
			return m_func(object, bConditional);
		}
	private:
		visitor_type m_func;
	};

	ForEachScriptObjectFunctor functor(func);
	VisitScripts(handle, &functor);
}

bool VMState::ExtractValue(BSScript::BSScriptVariable &var, const BSFixedString &name, BSScript::BSScriptVariable &out)
{
	bool result = false;
	
	if (var.IsObject())
	{
		BSScript::BSScriptObject *obj = var.data.object;
		VMHandle handle = obj->GetHandle();

		for (auto c = obj->GetClass(); c; c = c->GetParent())
		{
			SInt32 i = c->GetVariableIndex(name);
			if (i >= 0)
			{
				result = ExtractValue(handle, c->GetName(), i, out);
				break;
			}
		}
	}
	
	return result;
}
