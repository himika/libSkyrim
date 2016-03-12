#include "Skyrim.h"
#include "Skyrim/VMState.h"
#include "Skyrim/SkyrimVM.h"

using BSScript::BSScriptClass;
using BSScript::BSScriptStack;


void VMState::VisitScripts(VMHandle handle, std::function<UInt32(BSScript::BSScriptObject*, bool)> func)
{
	class ForEachScriptObjectFunctor : public BSScript::IForEachScriptObjectFunctor
	{
	public:
		typedef std::function<UInt32(BSScript::BSScriptObject*, bool)> visitor_type;

		ForEachScriptObjectFunctor(visitor_type a_func) : m_func(a_func) {}

		virtual UInt32 Visit(BSScript::BSScriptObject *object, bool bConditional) override {
			return m_func(object, bConditional);
		}
	private:
		visitor_type m_func;
	};

	ForEachScriptObjectFunctor functor(func);
	VisitScripts(handle, &functor);
}

bool VMState::ExtractValue(const BSScriptObjectPtr &objPtr, const BSFixedString &varName, BSScriptVariable &out)
{
	const BSScript::BSScriptClass *pClass = objPtr->GetClass();
	int index = pClass->GetVariableIndex(varName);

	return (index >= 0) ? this->ExtractValue(objPtr, index, out) : false;
}


bool VMState::ExtractValue(const BSScript::BSScriptVariable &var, const BSFixedString &name, BSScript::BSScriptVariable &out)
{
	bool result = false;

	if (var.IsObject() && var.data.u != 0)
	{
		BSScriptObjectPtr objPtr = var.GetObject();
		result = ExtractValue(objPtr, name, out);
	}

	return result;
}


bool VMState::GetScriptVariable(VMHandle handle, const BSFixedString &className, const BSFixedString &variableName, BSScript::BSScriptVariable &out)
{
	BSScriptClassPtr classPtr;

	if (GetScriptClassByName(className, classPtr) && classPtr)
	{
		int index = classPtr->GetVariableIndex(variableName);

		if (index >= 0 && ExtractValueFromHandle(handle, className, index, out))
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

bool VMState::GetStack(UInt32 stackId, BSScriptStackPtr &stackPtr)
{
	bool result = false;

	stackLock.Lock();

	auto it = allStacks.find(stackId);
	if (it != allStacks.cend())
	{
		stackPtr = it->value;
		result = true;
	}

	stackLock.Unlock();

	return result;
}
