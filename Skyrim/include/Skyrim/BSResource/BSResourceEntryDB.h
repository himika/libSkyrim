#pragma once

#include "BSResource.h"
#include "../BSCore/BSTSingleton.h"

namespace BSResource
{
	// 68
	class IEntryDB
	{
	public:
		virtual ~IEntryDB();
		virtual void Unk_01(void);
		virtual void Unk_02(void);
		virtual void Unk_03(void);
		virtual void Unk_04(void);
		virtual void Unk_05(void);

		class PostFlushNotify
		{
		};

		UInt32 unk00[0x1A];
	};

	template <class> struct EntryDBBase;
	template <class, class> struct EntryDBTraits;

	/*==============================================================================
	class BSResource::EntryDB<struct LipSynchAnimDB::DBTraits> +0000 (_vtbl=0107F4F8)
	0000: class BSResource::EntryDB<struct LipSynchAnimDB::DBTraits>
	0000: |   class BSResource::IEntryDB
	0068: |   struct BSResource::EntryDBBase<struct BSResource::EntryDBTraits<struct LipSynchAnimDB::DBTraits,class BSResource::EntryDB<struct LipSynchAnimDB::DBTraits> > >
	0068: |   |   struct BSResource::EntryDBTraits<struct LipSynchAnimDB::DBTraits,class BSResource::EntryDB<struct LipSynchAnimDB::DBTraits> >
	0069: |   |   struct LipSynchAnimDB::DBTraits
	0418: |   struct BSTSingletonSDM<class BSResource::EntryDB<struct LipSynchAnimDB::DBTraits>,struct BSTSingletonSDMOpStaticBuffer>
	0418: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class BSResource::EntryDB<struct LipSynchAnimDB::DBTraits>,struct BSTSingletonSDMOpStaticBuffer<class BSResource::EntryDB<struct LipSynchAnimDB::DBTraits> > > >
	0418: |   |   |   struct BSTSDMTraits<class BSResource::EntryDB<struct LipSynchAnimDB::DBTraits>,struct BSTSingletonSDMOpStaticBuffer<class BSResource::EntryDB<struct LipSynchAnimDB::DBTraits> > >
	0419: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class BSResource::EntryDB<struct LipSynchAnimDB::DBTraits> >
	==============================================================================*/
	template<class Traits>
	class EntryDB :
		public IEntryDB,												// 00
		public EntryDBBase<EntryDBTraits<Traits, EntryDB<Traits>>>,		// 68
		public BSTSingletonSDM<EntryDB<Traits>>							// 
	{
	public:
		typedef Traits TraitsType;

		virtual ~EntryDB();
	};


	template <class Traits, class Entry>
	struct EntryDBTraits
	{
		typedef Entry EntryType;
	};

	template<typename Traits>
	struct EntryDBBase :
		public Traits,							// 00
		public Traits::EntryType::TraitsType	// 01
	{
	};
}
