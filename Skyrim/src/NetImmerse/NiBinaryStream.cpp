#include "Skyrim.h"
#include "Skyrim/NetImmerse/NiBinaryStream.h"

UInt32 NiBinaryStream::GetPosition() const
{
	return m_currentPos;
}

void NiBinaryStream::CopyFrom(void * arg0)
{
	CopyFrom_Impl(arg0);
}
