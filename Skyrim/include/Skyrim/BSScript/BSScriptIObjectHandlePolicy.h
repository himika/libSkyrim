#pragma once

namespace BSScript
{
	/*==============================================================================
	struct BSScript::IObjectHandlePolicy +0000 (_vtbl=010EAD24)
	0000: struct BSScript::IObjectHandlePolicy
	==============================================================================*/
	// 04
	struct IObjectHandlePolicy
	{
	public:
		virtual ~IObjectHandlePolicy();		// 008C5E10

		virtual bool		IsType(UInt32 typeID, VMHandle handle) = 0;
		virtual bool		IsValidHandle(VMHandle handle) = 0;
		virtual VMHandle	GetInvalidHandle(void) = 0;
		virtual VMHandle	Create(UInt32 typeID, void * srcData) = 0;
		virtual bool		IsREFR(VMHandle handle) = 0;
		virtual VMHandle	Unk_06(UInt32 unk0, UInt32 unk1) = 0;
		virtual VMHandle	Unk_07(UInt32 unk0, UInt32 unk1) = 0;
		virtual void *		Resolve(UInt32 typeID, VMHandle handle) = 0;
		virtual void		AddRef(VMHandle handle) = 0;
		virtual void		Release(VMHandle handle) = 0;
		virtual void		ToString(VMHandle handle, const char *& outStr) = 0;

		// void		** _vtbl;	// 00 - 010EAD24
	};
}