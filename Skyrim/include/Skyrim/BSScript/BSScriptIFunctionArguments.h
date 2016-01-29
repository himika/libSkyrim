#pragma once

#include "BSScriptVariable.h"
#include "../BSCore/BSTArray.h"

namespace BSScript
{
	// 04
	class IFunctionArguments
	{
	public:
		IFunctionArguments() { }
		virtual ~IFunctionArguments()	{ }

		struct Output
		{
			void						* unk00;	// 00
			BSTArray<BSScriptVariable>	args;		// 04

			BSScriptVariable * Get(std::size_t idx) {
				return &args[idx];
			}
			BSScriptVariable & operator[](std::size_t idx) {
				return args[idx];
			}

			//UInt32	unk00;		// 00
			//BSScriptVariable	* m_data;	// 04 - tArray <VMValue>?
			//UInt32	unk08;		// 08
			//UInt32	m_size;		// 0C

			//BSScriptVariable	* Get(std::size_t idx)	{ return (idx < m_size) ? &m_data[idx] : nullptr; }
			//BSScriptVariable	& operator[](std::size_t idx)	{ return m_data[idx]; }

			DEFINE_MEMBER_FN(Resize, bool, 0x008C2A70, std::size_t len);
		};

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
			dst.Resize(0);
			return true;
		}
	};
}
