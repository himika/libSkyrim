#pragma once

#include "../BSCore/BSTArray.h"
#include "../BSCore/BSTList.h"

class TESForm;
class TESObjectREFR;
class Actor;

/*==============================================================================
class BGSLoadGameBuffer +0000 (_vtbl=010CD1E0)
0000: class BGSLoadGameBuffer
==============================================================================*/
// 18
class BGSLoadGameBuffer
{
public:

	virtual ~BGSLoadGameBuffer();

	virtual	UInt8	Unk_01(void);

	DEFINE_MEMBER_FN(ReadBuffer, void, 0x00685E20, void *out, UInt32 len1, UInt32 len2)	// len1 == len2 ?

	// @members
	//void	** _vtbl;		// 00 - 010CD1E0
	void	* buffer;		// 04 - init'd 0
	UInt32	unk08;			// 08 - init'd 0
	UInt32	unk0C;			// 0C - init'd 0
	UInt32	unk10;			// 10 - init'd 0
	UInt32	offset;			// 14 - init'd 0

private:
	DEFINE_MEMBER_FN(ctor, BGSLoadGameBuffer*, 0x00685BA0)
};


/*==============================================================================
class TempLoadGameBuffer +0000 (_vtbl=010A8194)
0000: class TempLoadGameBuffer
0000: |   class BGSLoadGameBuffer
==============================================================================*/
class TempLoadGameBuffer : public BGSLoadGameBuffer
{
};


class BGSLoadFormData
{
public:
	// @members
	FormID		formID;			// 04 - 18 - init'd 0
	UInt32		unk04;			// 04 - 1C - init'd 0
	UInt32		unk08;			// 08 - 20 - init'd 0
	TESForm		* form;			// 0C - 24 - init'd 0
	UInt32		unk10;			// 10 - 28 - init'd 0 flags?
	UInt32		unk14;			// 14 - 2C - init'd 0
	UInt16		unk18;			// 18 - 30 - init'd 0 flags?
	UInt8		unk1A;			// 1A - 32 - init'd 0
	UInt8		unk1B;			// 1B - 33

private:
	DEFINE_MEMBER_FN(ctor, BGSLoadFormData*, 0x00685920)
	DEFINE_MEMBER_FN(GetForm, TESForm*, 0x006858A0)
};


/*==============================================================================
class BGSLoadFormBuffer +0000 (_vtbl=0107B614)
0000: class BGSLoadFormBuffer
0000: |   class BGSLoadGameBuffer
0018: |   class BGSLoadFormData
==============================================================================*/
class BGSLoadFormBuffer :
	public BGSLoadGameBuffer,	// 00
	public BGSLoadFormData		// 18
{
public:
	virtual ~BGSLoadFormBuffer();				// 0058F990

	// @override
	virtual	UInt8	Unk_01(void) override;		// 00685910 { return (UInt8)BGSLoadFormData::unk1B; }

};
STATIC_ASSERT(offsetof(BGSLoadFormBuffer, unk1B) == 0x33);


/*==============================================================================
class BGSSaveGameBuffer +0000 (_vtbl=010CD368)
0000: class BGSSaveGameBuffer
==============================================================================*/
// 10?
class BGSSaveGameBuffer
{
public:
	virtual ~BGSSaveGameBuffer();					// 00686C30

	virtual	TESForm *		GetForm(void);			// 005EADD0 { return nullptr; }
	virtual	TESObjectREFR *	GetReference(void);		// 005EADD0 { return nullptr; }
	virtual	Actor *			GetActor(void);			// 005EADD0 { return nullptr; }

	DEFINE_MEMBER_FN(WriteBuffer, void, 0x00686E30, void *out, UInt32 len1, UInt32 len2, UInt32 arg4)	// len1 == len2 ?

	// @members
	//void	** _vtbl;		// 00 - 010CD368
	void	* unk04;		// 04 - init'd 0 - released in dtor
	UInt32	unk08;			// 08 - init'd 0
	UInt32	offset;			// 0C - init'd 0

private:
	DEFINE_MEMBER_FN(ctor, BGSSaveGameBuffer*, 0x00686BE0)
	DEFINE_MEMBER_FN(dtor, void, 0x00686C00)
};
STATIC_ASSERT(sizeof(BGSSaveGameBuffer) == 0x10);


/*==============================================================================
class BGSSaveFormBuffer +0000 (_vtbl=010CD354)
0000: class BGSSaveFormBuffer
0000: |   class BGSSaveGameBuffer
==============================================================================*/
// 20?
class BGSSaveFormBuffer : public BGSSaveGameBuffer
{
public:
	virtual ~BGSSaveFormBuffer();							// 00686A60

	// @override
	virtual	TESForm *		GetForm(void) override;			// 00422F80 { return form; }
	virtual	TESObjectREFR *	GetReference(void) override;	// 00686A10 { TESForm* form = GetForm(); return (form) ? form->GetReference() : nullptr; }
	virtual	Actor *			GetActor(void) override;		// 00686A90 { TESForm* form = GetForm(); return (form->Is(FormType::Character)) : (Actor*)this : nullptr; }

	// @members
	//void	** _vtbl;	// 00 - 010CD354
	UInt8	unk10;		// 10 - init'd 0
	UInt8	unk11;		// 10 - init'd 0
	UInt8	unk12;		// 10 - init'd 0
#pragma pack(1)
	UInt32	unk13;		// 13 - init'd 0
#pragma pack()
	UInt8	unk17;		// 17 - init'd 0
	UInt8	unk18;		// 18 - init'd 0
	TESForm	* form;		// 1C - init'd 0

private:
	DEFINE_MEMBER_FN(ctor, BGSSaveFormBuffer*, 0x00686A30)
};
STATIC_ASSERT(offsetof(BGSSaveFormBuffer, unk13) == 0x13);
STATIC_ASSERT(sizeof(BGSSaveFormBuffer) == 0x20);


// 58
class BGSSaveLoadManager
{
public:
	enum
	{
		kEvent_Autosave = 1 << 0,
		kEvent_Save = 1 << 1,
		kEvent_Unk02 = 1 << 2,
		kEvent_Unk03 = 1 << 3,
		kEvent_Unk04 = 1 << 4,

		kEvent_Unk07 = 1 << 7,
	};

	static BGSSaveLoadManager *	GetSingleton(void);

	DEFINE_MEMBER_FN(Save, bool, 0x006814D0, const char * name, int unk1, UInt32 unk2);
	DEFINE_MEMBER_FN(Load, bool, 0x006821C0, const char * name, int unk1, UInt32 unk2, UInt32 unk3);
	DEFINE_MEMBER_FN(ProcessEvents, void, 0x00682400);

	// @members
	BSSimpleList<const char**>	* saveList;		// 00
	UInt32				unk04;					// 04
	UInt32				unk08;					// 08
	UInt32				unk0C;					// 0C
	UInt8				unk10;					// 10
	UInt8				unk11;					// 11
	UInt8				pad12[2];				// 12
	UInt32				pendingEvents;			// 14
	UInt32				unk18;					// 18
	UInt32				startTickCount;			// 1C - GetTickCount when constructed
	UInt8				unk20;					// 20 - init'd to 0x01
	UInt8				pad21[3];				// 21
	UInt32				unk24;					// 24
	UInt32				unk28;					// 28 - init'd to 0xFFFFFFFF
	bool				unk2C;					// 2C
	UInt8				pad2E[3];				// 2E
	void				* unk30;				// 30
	UInt8				unk34;					// 34 - init'd to 0x01
	UInt8				unk35;					// 35
	UInt8				pad36[2];				// 36
	UInt32				unk38;					// 38
	UInt32				unk3C;					// 3C
	UInt32				unk40;					// 40
	UInt32				unk44;					// 44
	UInt32				unk48;					// 48
	UInt32				unk4C;					// 4C
	UInt32				unk50;					// 50
	void				* unk54;				// 54
	
private:
	DEFINE_MEMBER_FN(ctor, BGSSaveLoadManager*, 0x0067FA20);
	DEFINE_MEMBER_FN(CopySaveGamesFromHost, void, 0x006807E0, UInt32 unk);
	DEFINE_MEMBER_FN(SysUtilLoadCompleteCallback, void, 0x00682390, UInt32 unk)
};
STATIC_ASSERT(sizeof(BGSSaveLoadManager) == 0x58);
