#include "SKSE/PapyrusEvents.h"
#include <Skyrim/SkyrimVM.h>

namespace {

	static const UInt32 * g_TlsIndexPtr = (UInt32 *)0x01BBEB54;

	struct TLSData
	{
		// thread local storage

		UInt32	pad000[(0x4AC - 0x000) >> 2];   // 000
		volatile UInt32	state;                  // 4AC
	};

	static TLSData * GetTLSData(void)
	{
		UInt32 TlsIndex = *g_TlsIndexPtr;
		TLSData * data = nullptr;

		__asm {
			mov		ecx, [TlsIndex]
			mov		edx, fs:[2Ch]	// linear address of thread local storage array
			mov		eax, [edx + ecx * 4]
			mov		[data], eax
		}

		return data;
	}

}

namespace SKSEScript
{
	FunctionArgumentsBase::FunctionArgumentsBase()
	{
		m_state = g_skyrimVM->GetState();
	}

	FunctionArgumentsBase::~FunctionArgumentsBase()
	{
	}

	void FunctionArgumentsBase::QueueEvent(VMHandle handle, const BSFixedString & eventName, bool bBroadcast)
	{
		// change thread state = 14h
		TLSData* tlsData = GetTLSData();
		UInt32 oldState = tlsData->state;
		tlsData->state = 0x14;

		m_state->QueueEvent(handle, eventName, this);

		if (bBroadcast) {
			g_skyrimVM->QueueAliasEvent(handle, eventName, this, 0);
		}

		tlsData->state = oldState;

		return;
	}
}
