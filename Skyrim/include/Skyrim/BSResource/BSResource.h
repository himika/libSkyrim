#pragma once

// c:_skyrim\code\tesv\bsstream\BSResource.h

namespace BSResource
{
	class Location;
	class LooseFileLocation;

	struct ArchiveStreamOpenedEvent
	{
	};

	struct NameFoundEvent
	{
		// 00A403C3: SendEventSink

		const char			* name;			// arg1
		void				* unk04;
		LooseFileLocation	* unk08;		// arg2
	};

	struct ArchiveRegisteredEvent
	{
		// 00A40191: SendEventSink

		const char			* name;		// "aaa", "aab", "aac", "aad"...
		void				* data;
	};
}
