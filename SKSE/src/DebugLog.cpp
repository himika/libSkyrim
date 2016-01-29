#include "SKSE/DebugLog.h"
#include <cstdarg>

using std::endl;

DebugLog gLog;

DebugLog::DebugLog() : std::ofstream()
{
}


void DebugLog::operator()(const char* message)
{
	*this << message;
}

void DebugLog::operator()(const char* fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	char formatBuf[1024];
	vsprintf_s(formatBuf, fmt, args);
	va_end(args);

	*this << formatBuf;
}

void _MESSAGE(const char* fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	char formatBuf[1024];
	vsprintf_s(formatBuf, fmt, args);
	va_end(args);

	gLog << formatBuf << endl;
	gLog.flush();
}
