#include "Skyrim.h"
#include "Skyrim/BSCore/BSString.h"
#include "Skyrim/Memory.h"
#include "Skyrim/BSCore/BSFixedString.h"



BSString::~BSString()
{
	if (m_data)
	{
		FormHeap_Free(m_data);
		m_data = nullptr;
	}
}


BSString::operator const char*() const
{
	return m_data ? m_data : "";
}

const char * BSString::Get(void) const
{
	return m_data ? m_data : "";
}

BSString& BSString::operator=(const BSFixedString& str) {
	Set(str);
	return *this;
}

BSString& BSString::operator=(const char* str) {
	Set(str);
	return *this;
}
