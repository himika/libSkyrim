#include "Skyrim/BSResource/BSResourceStreamBase.h"


namespace BSResource
{
	StreamBase::~StreamBase()
	{
	}

	UInt64 StreamBase::GetPosition(void)
	{
		return GetPosition_Impl();
	}

	StreamBase::Status StreamBase::Unk_04(UInt32 arg)
	{
		return Unk_04_Impl(arg);
	}
}
