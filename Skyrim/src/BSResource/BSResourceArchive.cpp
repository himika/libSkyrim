#include "Skyrim/BSResource/BSResourceArchive.h"


DECLARE_BSTSINGLETONSDM_STATIC_INSTANCE(BSResource::Archive, 0x01B4110C, 0x01B417A0);


namespace BSResource
{
	Archive* Archive::ctor()
	{
		UInt32 *vtbl = (UInt32*)this;
		*vtbl = 0x0110CCF8;

		auto *src1 = static_cast<BSTEventSource<NameFoundEvent> *>(this);
		new (src1)BSTEventSource<NameFoundEvent>;

		auto *src2 = static_cast<BSTEventSource<ArchiveRegisteredEvent> *>(this);
		new (src2)BSTEventSource<ArchiveRegisteredEvent>;

		return this;
	}
}
