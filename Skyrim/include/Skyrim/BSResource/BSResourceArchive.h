#pragma once

#include "BSResource.h"
#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSTEvent.h"

namespace BSResource
{
	// 68? no rtti
	class Archive :
		public BSTSingletonSDM<Archive>,		// 04
		public BSTEventSource<NameFoundEvent>,			// 08
		public BSTEventSource<ArchiveRegisteredEvent>	// 38
	{
	public:
		virtual ~Archive();

		// @members
		//void				** _vtbl;		// 00 - 0110CCF8
		//									// 04 - BSTSingletonSDM<Archive>
		//									// 08 - BSTEventSource<NameFoundEvent>
		//									// 38 - BSTEventSource<ArchiveRegisteredEvent>

		Archive* ctor();
	};
	STATIC_ASSERT(sizeof(Archive) == 0x68);
}
