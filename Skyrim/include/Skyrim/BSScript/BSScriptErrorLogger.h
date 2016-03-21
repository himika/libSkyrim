#pragma once

#include "../BSCore/BSTEvent.h"

namespace BSScript
{
	struct LogEvent
	{
	};


	// type_info: 012B65CC
	// 34
	class ErrorLogger :								// 00
		public BSTEventSource<BSScript::LogEvent>	// 04
	{
	public:
		virtual ~ErrorLogger();
	};
	STATIC_ASSERT(sizeof(ErrorLogger) == 0x34);
}
