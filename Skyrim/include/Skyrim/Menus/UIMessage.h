#pragma once

#include "../BSCore/BSFixedString.h"
#include "../BSCore/BSString.h"
#include "../Scaleform/GFxEvent.h"


/*==============================================================================
class IUIMessageData +0000 (_vtbl=010CF27C)
0000: class IUIMessageData
==============================================================================*/
// 08
class IUIMessageData
{
public:
	virtual ~IUIMessageData();			// 00897320

	// @members
	//void	** _vtbl;	// 00 - 010CF27C
	UInt8	unk04;		// 04
	UInt8	unk05;		// 05
	UInt8	pad06[2];	// 06
};


/*==============================================================================
class BSUIMessageData +0000 (_vtbl=010CF284)
0000: class BSUIMessageData
0000: |   class IUIMessageData
==============================================================================*/
// 14
class BSUIMessageData : public IUIMessageData
{
public:
	virtual ~BSUIMessageData();			// 006A0F10

	// @members
	BSString		* unk08;	// 08
	BSFixedString	unk0C;		// 0C
	UInt32			unk10;		// 10
};


/*==============================================================================
struct RefHandleUIData +0000 (_vtbl=010E8D44)
0000: struct RefHandleUIData
0000: |   class IUIMessageData
==============================================================================*/
// 0C
class RefHandleUIData : public IUIMessageData
{
public:

	// @members
	RefHandle	refHandle;	// 08
};


/*==============================================================================
class BSUIScaleformData +0000 (_vtbl=0110DF70)
0000: class BSUIScaleformData
0000: |   class IUIMessageData
==============================================================================*/
class BSUIScaleformData : public IUIMessageData
{
public:
	virtual ~BSUIScaleformData() {}		// 00897320

	//void		** _vtbl;		// 00 - 0110DF70
	GFxEvent	* event;		// 08
};
STATIC_ASSERT(sizeof(BSUIScaleformData) == 0x0C);
STATIC_ASSERT(offsetof(BSUIScaleformData, event) == 0x08);

/*==============================================================================
class HUDData +0000 (_vtbl=010E8D4C)
0000: class HUDData
0000: |   class IUIMessageData
==============================================================================*/

/*==============================================================================
class MessageBoxData +0000 (_vtbl=010E452C)
0000: class MessageBoxData
0000: |   class IUIMessageData
==============================================================================*/

/*==============================================================================
struct TESFormUIData +0000 (_vtbl=010E8D1C)
0000: struct TESFormUIData
0000: |   class IUIMessageData
==============================================================================*/

/*==============================================================================
struct LoadingMenuData +0000 (_vtbl=010E8D24)
0000: struct LoadingMenuData
0000: |   class IUIMessageData
==============================================================================*/

/*==============================================================================
class KinectStateChangeData +0000 (_vtbl=010E8D2C)
0000: class KinectStateChangeData
0000: |   class IUIMessageData
==============================================================================*/


// 10
class UIMessage
{
public:
	enum Type
	{
		kMessage_Refresh = 0,				// 0 used after ShowAllMapMarkers
		kMessage_Open,						// 1
		kMessage_PreviouslyKnownAsClose,	// 2
		kMessage_Close,						// 3
		kMessage_Unk04,
		kMessage_Unk05,
		kMessage_Scaleform,					// 6 BSUIScaleformData
		kMessage_Message					// 7 BSUIMessageData
	};

	static void * CreateUIMessageData(const BSFixedString &name);

	// @members
	BSFixedString		name;		// 00
	Type				type;		// 04
	IUIMessageData		* data;		// 08 - something with a virtual destructor
	UInt8				isPooled;	// 0C
	UInt8				pad0D[3];	// 0D
};
