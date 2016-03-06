#pragma once

#include "IMenu.h"
#include "../Memory.h"
#include "../Events/MenuEvent.h"
#include "../BSCore/BSTArray.h"
#include "../BSCore/BSString.h"

class TESObjectREFR;


class SubtitleManager
{
public:
	// 14
	struct SubtitleData
	{
		RefHandle		speakerRefHandle;	// 00
		BSString		text;				// 04
		UInt32			unk0C;				// 0C - float ?
		bool			unk10;				// 10
	};


	static SubtitleManager * GetSintleton()
	{
		return (SubtitleManager *)0x012E35EC;
	}

	DEFINE_MEMBER_FN(Display, bool, 0x00893220);
	DEFINE_MEMBER_FN(AddSubtitle, void, 0x00892CE0, Actor *speaker, const char *str, bool arg3);	// push
	DEFINE_MEMBER_FN(Unk_00892DA0, void, 0x00892DA0);


	// @members
	UInt32					unk00;		// 00 - BSTSingletonSDM ?
	BSTArray<SubtitleData>	subtitles;	// 04
	UInt32					unk10;		// 10
};


/*==============================================================================
class HUDData +0000 (_vtbl=010E8D4C)
0000: class HUDData
0000: |   class IUIMessageData
==============================================================================*/
class HUDData : public IUIMessageData
{
public:
	enum MessageType
	{
		kType_ShowMessage				= 1,
		kType_SetLoadDoorInfo			= 4,
		kType_ShowSubtitle				= 5,
		kType_HideSubtitle				= 6,
		kType_ShowArrowCount			= 7,
		kType_HideArrowCount			= 8,
		kType_SetSubtitlesEnabled		= 9,
		kType_DragonSoulAbsorbed		= 0x16,
		kType_ShowElements				= 0x17,
		kType_Discoverd					= 0x1A,
		kType_Favor						= 0x1B,
		kType_ValidateCrosshair			= 0x1C,
		kType_SetLocationName			= 0x1D,
		kType_ShowTutrialHintText		= 0x1E,
		kType_SetCrosshairEnabled		= 0x1F,
		kType_Unk20						= 0x20,
		kType_RefreshActivateButtonArt	= 0x21,
		kType_Unk22						= 0x22		// ResetAll ?
	};


	// @members
	UInt32		type;			// 08
	BSString	text;			// 0C
	void		* unk14;		// 14
	UInt32		unk18;			// 18
	UInt32		unk1C;			// 1C
	bool		unk20;			// 20
	UInt8		pad21[3];
	UInt32		unk24;			// 24
};
STATIC_ASSERT(offsetof(HUDData, text) == 0x0C);


/*==============================================================================
class HUDObject +0000 (_vtbl=010E5098)
0000: class HUDObject
==============================================================================*/
// 20
class HUDObject
{
public:
	HUDObject(GFxMovieView *movie);
	virtual ~HUDObject(void);											// 0085FF10

	virtual void	Update(void);										// 00F51EE8 Called per-frame
	virtual bool	Unk_02(void * unk1) { return false; }				// 004091A0 { return false; }
	virtual void *	Unk_03(void * unk1) { return Impl_Fn03(unk1); }		// 0085F030 { return Impl_Fn03(unk1); }
	virtual void	Unk_04(void) { return; }							// 006C50E0 { return; }

	// @members
	//void			** _vtbl;	// 00
	//UInt32		pad04;		// 04 - padding for alignment
	GFxMovieView	* view;		// 08
	//UInt32		pad0C;		// 0C - padding for alignment
	GFxValue		object;		// 10

	// redirect to formheap
	static void * operator new(std::size_t size)
	{
		return FormHeap_Allocate(size);
	}

	static void * operator new(std::size_t size, const std::nothrow_t &)
	{
		return FormHeap_Allocate(size);
	}

	// placement new
	static void * operator new(std::size_t size, void * ptr)
	{
		return ptr;
	}

	static void operator delete(void * ptr)
	{
		FormHeap_Free(ptr);
	}

	static void operator delete(void * ptr, const std::nothrow_t &)
	{
		FormHeap_Free(ptr);
	}

	static void operator delete(void *, void *)
	{
		// placement delete
	}

private:
	DEFINE_MEMBER_FN(dtor, void, 0x0085FF10);
	DEFINE_MEMBER_FN(Impl_Fn03, void *, 0x0085F030, void * unk1);
};
STATIC_ASSERT(offsetof(HUDObject, view) == 0x08);
STATIC_ASSERT(offsetof(HUDObject, object) == 0x10);
STATIC_ASSERT(sizeof(HUDObject) == 0x20);


/*==============================================================================
class Compass +0000 (_vtbl=010E51A4)
0000: class Compass
0000: |   class HUDObject
==============================================================================*/
// 30
class Compass : public HUDObject
{
public:
	virtual ~Compass();									// 0085F870

	// @override
	virtual void	Update(void) override;				// 01 00863320
	virtual void *	Unk_03(void * unk1) override;		// 03 0085F260

	// @members
	UInt32	unk20;	// 20
	UInt32	unk24;	// 24
	UInt32	unk28;	// 28
	UInt32	unk2C;	// 2C
};
STATIC_ASSERT(sizeof(Compass) == 0x30);


/*==============================================================================
class FloatingQuestMarker +0000 (_vtbl=010E52AC)
0000: class FloatingQuestMarker
0000: |   class HUDObject
==============================================================================*/
// A0
class FloatingQuestMarker : public HUDObject
{
public:

};


/*==============================================================================
class HUDNotifications +0000 (_vtbl=010E556C)
0000: class HUDNotifications
0000: |   class HUDObject
==============================================================================*/
// 58
class HUDNotifications : public HUDObject
{
public:

};

/*==============================================================================
class EnemyHealth +0000 (_vtbl=010E51BC)
0000: class EnemyHealth
0000: |   class HUDObject
==============================================================================*/
// 68
class EnemyHealth : public HUDObject
{
public:
	UInt32			handle;			// 20
	UInt32			unk24;			// 24
	UInt32			unk28;			// 28
	UInt32			unk2C;			// 2C
	GFxValue		unk30;			// 30
	GFxValue		unk40;			// 40
	GFxValue		text;			// 50
	UInt32			unk5C;			// 5C
	UInt32			unk60;			// 60
	UInt32			unk64;			// 64

	TESObjectREFR	* GetTarget() const;
};
STATIC_ASSERT(offsetof(EnemyHealth, handle) == 0x20);


/*==============================================================================
class StealthMeter +0000 (_vtbl=010E51D4)
0000: class StealthMeter
0000: |   class HUDObject
==============================================================================*/
// 70
class StealthMeter : public HUDObject
{
public:

};

/*==============================================================================
class HUDChargeMeter +0000 (_vtbl=010E51EC)
0000: class HUDChargeMeter
0000: |   class HUDObject
==============================================================================*/
// 28
class HUDChargeMeter : public HUDObject
{
public:

};


/*==============================================================================
class HUDMeter +0000 (_vtbl=010E521C)
0000: class HUDMeter
0000: |   class HUDObject
==============================================================================*/// 38?
class HUDMeter : public HUDObject
{
public:
	virtual double GetMaxValue(void);

	char	* setMeterPercent;	// 20
	char	* startBlinking;	// 24
	char	* fadeOut;			// 28
	float	unk28;				// 2C
	UInt32	unk2C;				// 30
	UInt32	unk34;				// 34
};
STATIC_ASSERT(sizeof(HUDMeter) == 0x38);


/*==============================================================================
class ActorValueMeter +0000 (_vtbl=010E5238)
0000: class ActorValueMeter
0000: |   class HUDMeter
0000: |   |   class HUDObject
==============================================================================*/
// 38
class ActorValueMeter : public HUDMeter
{
public:

};


/*==============================================================================
class ShoutMeter +0000 (_vtbl=010E5260)
0000: class ShoutMeter
0000: |   class HUDMeter
0000: |   |   class HUDObject
==============================================================================*/
// 38
class ShoutMeter : public HUDMeter
{
public:

};


/*==============================================================================
class HUDMenu +0000 (_vtbl=010E537C)
0000: class HUDMenu
0000: |   class IMenu
0000: |   |   class FxDelegateHandler
0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   |   class GRefCountImplCore
001C: |   class BSTEventSink<class UserEventEnabledEvent>
==============================================================================*/
// 58
class HUDMenu : public IMenu,
	public BSTEventSink<UserEventEnabledEvent>	// 1C
{
	// unk0C - 2
	// Flags - 0x18902
	// unk14 - 0x12
public:
	~HUDMenu();			// 00863650


	// @override
	virtual void	Accept(CallbackProcessor *processor) override;	// 00863240
	virtual UInt32	ProcessMessage(UIMessage *message) override;	// 00863B40
	virtual void	NextFrame(UInt32 arg0, UInt32 arg1) override;	// 0085EF60
	virtual void	InitMovie(void) override;						// 00861450

	static IMenu * Create();

	static void SendHUDMessage(HUDData::MessageType type, bool arg2, const char *text, UInt32 arg4)
	{
		typedef void(*Fn)(HUDData::MessageType, bool, const char *, UInt32);
		const Fn fn = (Fn)0x00897430;
		fn(type, arg2, text, arg4);
	}

	static void SendHUDMessage(HUDData::MessageType type, const char *text)
	{
		typedef void(*Fn)(HUDData::MessageType, const char *);
		const Fn fn = (Fn)0x00897480;
		fn(type, text);
	}

	// @members
	BSTArray<HUDObject*>	hudComponents;	// 20
	UInt32	unk2C;
	UInt32	unk30;
	UInt32	unk34;
	UInt32	unk38;
	UInt32	unk3C;
	UInt32	unk40;
	UInt32	unk44;
	UInt32	unk48;
	UInt32	unk4C;
	UInt32	unk50;
	UInt32	unk54;
};
STATIC_ASSERT(sizeof(HUDMenu) == 0x58);
