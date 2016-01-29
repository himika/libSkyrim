#pragma once

// c:_skyrim\code\tesv\bsstream\BSResourceEntry.h

#include "BSResource.h"
#include "../BSCore/BSTEvent.h"

namespace BSResource
{
	// 40 no rtti
	class BSResourceEntry : public BSTEventSource<ArchiveStreamOpenedEvent>
	{
	public:
		BSResourceEntry()					// 00A3F123
		{
			*(UInt32*)this = 0x0110CBB0;	// vtbl

			typedef void(*Func)(UInt32);
			Func func = (Func)0x00A49B40;

			func(0x01063830);
		}

		virtual ~BSResourceEntry() {};		// 00A3EBB0

		static BSResourceEntry* GetSingleton();

		// @members
		//void										** _vtbl;		// 00
		BSTArray<void*>								unk34;			// 34
	};
	STATIC_ASSERT(sizeof(BSResourceEntry) == 0x40);
}
