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

		virtual bool		IsType(UInt32 typeID, VMHandle handle) = 0;				// 01
		virtual bool		IsValidHandle(VMHandle handle) = 0;						// 02
		virtual VMHandle	GetInvalidHandle(void) = 0;								// 03
		virtual VMHandle	Create(UInt32 typeID, const void * srcData) = 0;		// 04
		virtual bool		IsREFR(VMHandle handle) = 0;							// 05
		virtual VMHandle	Unk_06(UInt32 unk0, UInt32 unk1) = 0;					// 06
		virtual VMHandle	Unk_07(UInt32 unk0, UInt32 unk1) = 0;					// 07
		virtual void *		Resolve(UInt32 typeID, VMHandle handle) = 0;			// 08
		virtual void		AddRef(VMHandle handle) = 0;							// 09
		virtual void		Release(VMHandle handle) = 0;							// 0A
		virtual void		ToString(VMHandle handle, BSFixedString &strOut) = 0;	// 0B

		// void		** _vtbl;	// 00 - 010EAD24
	};
}