#pragma once

#include <fstream>

#if _DEBUG
#define DEBUG_MESSAGE(str) do { gLog << str << std::endl; gLog.flush(); } while (false)
#else
#define DEBUG_MESSAGE(str) do { } while (false)
#endif

class DebugLog : public std::ofstream
{
public:
	DebugLog();

	void operator()(const char* message);
	void operator()(const char* message, ...);
};

void _MESSAGE(const char* fmt, ...);

extern DebugLog gLog;
