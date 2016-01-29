#include "Skyrim.h"
#include "Skyrim/RTTI.h"
#include <typeinfo>

const _Runtime_DynamicCast Runtime_DynamicCast = (_Runtime_DynamicCast)0x00F51DAE;


struct TYPE_INFO_NODE
{
	void *memPtr;
	TYPE_INFO_NODE* next;
};


const char* TYPE_INFO::name(void) const
{
	const char *result;

	if (*(const UInt32*)this != 0x0118E204)
	{
		std::type_info const *pThis = reinterpret_cast<std::type_info const *>(this);
		result = pThis->name();
	}
	else
	{
		typedef const char* (*_RTTI_Name_base)(const TYPE_INFO* pThis, TYPE_INFO_NODE* pNode);
		_RTTI_Name_base RTTI_Name_base = (_RTTI_Name_base)0x00F5D278;
		TYPE_INFO_NODE* type_info_root_node = (TYPE_INFO_NODE*)0x01BBEB60;

		result = RTTI_Name_base(this, type_info_root_node);
	}

	return result;
}

const char* TYPE_INFO::raw_name(void) const
{
	return _M_d_name;
}
