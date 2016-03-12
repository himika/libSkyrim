#pragma once

#include "BSScriptVariable.h"
#include "../BSCore/BSTArray.h"

namespace BSScript
{
	// 04
	class IFunctionArguments
	{
	public:
		typedef BSScript::BSScriptVariable BSScriptVariable;
		typedef BSScrapArray<BSScriptVariable> Output;

		IFunctionArguments() { }
		virtual ~IFunctionArguments()	{ }
		virtual bool Copy(Output & dst) = 0;
	};

	// 04
	class ZeroFunctionArguments : public IFunctionArguments
	{
	public:
		ZeroFunctionArguments()	{}
		virtual ~ZeroFunctionArguments()	{ }

		virtual bool Copy(Output & dst) override
		{
			dst.clear();
			return true;
		}
	};
}
