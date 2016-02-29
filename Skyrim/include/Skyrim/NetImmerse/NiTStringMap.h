#pragma once

#include "NiTMap.h"
#include "NiTPointerMap.h"


// The hash function class
class NiStringHashFunctor
{
public:
	static unsigned int KeyToHashIndex(const char* pcKey, unsigned int uiTableSize);
};

// The equality function class
class NiStringEqualsFunctor
{
public:
	static bool IsKeysEqual(const char* pcKey1, const char* pcKey2);
};



/*==============================================================================
class NiTStringTemplateMap<class NiTPointerMap<char const *,unsigned short>,unsigned short> +0000 (_vtbl=01117700)
0000: class NiTStringTemplateMap<class NiTPointerMap<char const *,unsigned short>,unsigned short>
0000: |   class NiTPointerMap<char const *,unsigned short>
0000: |   |   class NiTMapBase<class NiTPointerAllocator<unsigned int>,char const *,unsigned short>
==============================================================================*/
template <class TPARENT, class TVAL, class THASH = NiStringHashFunctor, class TEQUALS = NiStringEqualsFunctor >
class NiTStringTemplateMap : public TPARENT
{
public:
	NiTStringTemplateMap(unsigned int uiHashSize = 37, bool bCopy = true);
	virtual ~NiTStringTemplateMap();

protected:
	virtual void SetValue(NiTMapItem<const char*, TVAL>* pkItem, const char* pcKey, TVAL val);
	virtual void ClearValue(NiTMapItem<const char*, TVAL>* pkItem);

	bool m_bCopy;
};


template <class TVAL, class THASH = NiStringHashFunctor, class TEQUALS = NiStringEqualsFunctor >
class NiTStringMap : public NiTStringTemplateMap<NiTMap<const char*, TVAL, THASH, TEQUALS>, TVAL>
{
public:
	NiTStringMap(unsigned int uiHashSize = 37, bool bCopy = true);
};


/*==============================================================================
class NiTStringPointerMap<unsigned short> +0000 (_vtbl=011177D8)
0000: class NiTStringPointerMap<unsigned short>
0000: |   class NiTStringTemplateMap<class NiTPointerMap<char const *,unsigned short>,unsigned short>
0000: |   |   class NiTPointerMap<char const *,unsigned short>
0000: |   |   |   class NiTMapBase<class NiTPointerAllocator<unsigned int>,char const *,unsigned short>
==============================================================================*/
template <class TVAL, class THASH = NiStringHashFunctor, class TEQUALS = NiStringEqualsFunctor >
class NiTStringPointerMap : public NiTStringTemplateMap<NiTPointerMap<const char*, TVAL, THASH, TEQUALS>, TVAL>
{
public:
	NiTStringPointerMap(unsigned int uiHashSize = 37, bool bCopy = true);
};
