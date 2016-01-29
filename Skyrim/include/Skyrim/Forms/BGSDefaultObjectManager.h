#pragma once

#include "TESForm.h"
#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSTEvent.h"

struct DefaultObjectsReadyEvent;

/*==============================================================================
class BGSDefaultObjectManager +0000 (_vtbl=0108CA3C)
0000: class BGSDefaultObjectManager
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class BSTSingletonImplicit<class BGSDefaultObjectManager>
==============================================================================*/
// 6D8 - singleton, ID 00000031
class BGSDefaultObjectManager : public TESForm,
	public BSTSingletonImplicit<BGSDefaultObjectManager>
{
public:
	enum { kTypeID = (UInt32)FormType::DOBJ };

	virtual ~BGSDefaultObjectManager();							// 004F9000

	virtual bool	LoadForm(TESFile *mod);						// 06 004F9030
	virtual void	InitItem(void);								// 13 004F9220 - send DefaultObjectsReadyEvent::Event

	static BGSDefaultObjectManager *	GetSingleton(void)
	{
		return (BGSDefaultObjectManager *)0x012E2500;
	}

	// @members
	//void	** _vtbl;					// 00 - 0108CA3C
	TESForm	* objects[0x15A];			// 14 - cleared to 0 in ctor
	UInt8	pad[0x15A];					// just pad out the rest of the space

private:
	DEFINE_MEMBER_FN(ctor, BGSDefaultObjectManager*, 0x004F8FB0)
};
STATIC_ASSERT(offsetof(BGSDefaultObjectManager, objects) == 0x14);

extern BGSDefaultObjectManager & g_defaultObjectManager;
