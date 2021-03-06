#pragma once

#include "BaseFormComponent.h"
#include "../FormComponents/FormTypes.h"

class BSFixedString;
class TESObjectREFR;
class BGSKeyword;
class TESFile;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;

typedef TESForm* (*_LookupFormByID)(FormID id);
extern const _LookupFormByID LookupFormByID;

/*==================================================================================
class TESForm + 0000 (_vtbl = 0107CBE4)
	+ 0000 01 class TESForm | 0123B000
		+ 0000 00 class BaseFormComponent | 0123B030
==================================================================================*/
// 14
class TESForm : public BaseFormComponent
{
public:
	enum { kTypeID = 0 };	// special-case

	struct TESFileArray
	{
		TESFile		** files;
		UInt32		numFiles;
	};

	struct Flags
	{
		bool	visible : 1;
		bool	unk01 : 1;
		bool	unk02 : 1;
		bool	unk03 : 1;
		bool	unk04 : 1;
		bool	deleted : 1;			// :05 0x0020
		bool	playerKnows : 1;		// :06 0x0040
		bool	unk07 : 1;
		bool	unk08 : 1;
		bool	unk09 : 1;
		bool	unk0A : 1;
		bool	disabled : 1;			// :0B 0x0800
		bool	unk0C : 1;				// :0C 0x1000
		bool	unk0D : 1;
		bool	unk0E : 1;              // :0E 0x4000 see TEObjetREFR::~TESObjectREFR()
		bool	unk0F : 1;
		bool	unk10 : 1;				// :10 0x10000
		bool	unk11 : 1;
		bool	unk12 : 1;
		bool	unk13 : 1;
		bool	ignoreFriendlyHits : 1;	// 14 0x00100000
		bool	unk15 : 1;				// 15 0x00200000 see 0067BE72
	};


	virtual ~TESForm();														// 00 004522A0

	// @override
	virtual void	Init(void) override;									// 01 006C50E0 { return; }
	virtual void	ReleaseRefs(void) override;								// 02 004506C0
	virtual void	CopyFromBase(BaseFormComponent * rhs) override;			// 03 00451180
	
	// @add
	virtual void			Unk_04(void);									// 04 006C50E0 { return; } reset/init? would leak pointers if called on a live object
	virtual void			Unk_05(void);									// 05 006C50E0 { return; } release pointers?
	virtual bool			LoadForm(TESFile *mod);							// 06 00C8CCA0 { return true; } called from 0043B4B9
	virtual bool			Unk_07(UInt32 arg);								// 07 00C8CCA0 { return true; }
	virtual bool			Unk_08(TESFile *arg);							// 08 00401A00 calls LoadForm
	virtual TESForm *		DupulicateForm(UInt32 arg1, void * arg2);		// 09 00451980
	virtual bool			MarkChanged(UInt32 changed);					// 0A 00451000 mark as changed?
	virtual void			Unk_0B(UInt32 arg);								// 0B 00451060
	virtual bool			Unk_0C(UInt32 arg);								// 0C 004091A0 { return false; }
	virtual bool			PreSaveBuffer(BGSSaveFormBuffer *buf);			// 0D 00C8CCA0 { return true; }   - called from 00679A03 check if need to save ?
	virtual void			SaveBuffer(BGSSaveFormBuffer *buf);				// 0E 00451090 - called from 006794DC (BGSSaveLoadGame::SaveGame)
	virtual void			LoadBuffer(BGSLoadFormBuffer *buf);				// 0F 004510D0 - called from 0067BE80 (BGSSaveLoadGame::LoadGame)
	virtual void			Unk_10(BGSLoadFormBuffer *buf);					// 10 00588F30 { return; } called after LoadBuffer
	virtual void			Unk_11(BGSLoadFormBuffer *buf);					// 11 00588F30 { return; } called after Unk_10
	virtual void			Unk_12(BGSLoadFormBuffer *buf);					// 12 00588F30 { return; } revert form? called before LoadBuffer
	virtual void			InitItem(void);									// 13 006C50E0 { return; } called once all dependent forms are loaded
	virtual void			Unk_14(void);									// 14 00401A10 { Unk_004515B0(-1); }
	virtual UInt32			GetFormType(void);								// 15 00401A20
	virtual void			GetFormDesc(char * buf, UInt32 bufLen);			// 16 00451480 overrided by TESObjectREFR
	virtual bool			PlayerKnows(void) const;						// 17 00401A30 { return flags.playerKnows; }
	virtual bool			GetFlag00010000(void);							// 18 00401A40
	virtual bool			IsPlayable(void);								// 19 00401A50
	virtual bool			Unk_1A(void);									// 1A 0092D110 { return false; }  new
	virtual bool			GetFlag00020000(void);							// 1B 004C0310 new
	virtual bool			GetFlag00080000(void);							// 1C 00401A60
	virtual bool			GetFlag02000000(void);							// 1D 00401A70
	virtual bool			Unk_1E(void);									// 1E 0092D110 { return false; }
	virtual bool			GetFlag00000200(void);							// 1F 00401A80
	virtual bool			GetFlag00000100(void);							// 20 00401A90
	virtual void			SetFlag00000200(bool set);						// 21 004507B0
	virtual bool			Unk_22(void);									// 22 0092D110 { return false; }
	virtual void			SetFlag00000020(bool set);						// 23 00450DE0
	virtual void			SetFlag00000002(bool set);						// 24 00450ED0
	virtual void			Unk_25(void);									// 25 006C50E0 { return; }
	virtual void			Unk_26(TESFile *mod);							// 26 00588F30 { return; }
	virtual bool			Has3D(void);									// 27 0092D110 { return false; }
	virtual bool			Unk_28(void);									// 28 0092D110 { return false; } TESObject=true;
	virtual bool			IsMagicItem(void) const;						// 29 0092D110 { return false; } MagicItem=true
	virtual bool			Unk_2A(void);									// 2A 0092D110 { return false; }
	virtual TESForm *		Unk_2B(void);									// 2B 005EADD0 { return nullptr; }
	virtual TESObjectREFR *	GetReference(void);								// 2C 005EADD0 { return nullptr; }
	virtual void *			Unk_2D(void);									// 2D 005EADD0 { return nullptr; }
	virtual const char *	GetAliasName(const BSFixedString &alias);		// 2E 00450A50 - alias: "Pronoun" "PronounObj" "PronounPos" "PronounPosObj" "PronounRef" "PronounInt" "Race" "Gender" "ShortName". see http://www.creationkit.com/Text_Replacement
	virtual void			CopyFrom(TESForm * srcForm);					// 2F 00588F30 { return; }
	virtual bool			Unk_30(void * arg0, UInt32 arg1, UInt32 arg2);	// 30 00451210 - arg0 => TESFile::FormInfo
	virtual bool			Unk_31(void * dst, void * unk);					// 31 00451250 - dst => TESFile::FormInfo
	virtual const char *	GetName(void);									// 32 00401AA0 { return ""; }
	virtual bool			SetName(const char * str);						// 33 00C8CCA0 { return true; }
	virtual bool			Unk_34(void);									// 34 0092D110 { return false; } TESTopic,TESObjectCELL,TESWorldSpace=true
	virtual bool			Unk_35(void);									// 35 0092D110 { return false; }
	virtual bool			Unk_36(FormType arg);							// 36 004091A0 { return false; }
	virtual bool			ActivateReference(TESObjectREFR* targetRef, TESObjectREFR* activatorRef, UInt32 arg2, UInt32 arg3, UInt32 arg4);	// 37 00404710 { return false; }
	virtual void			SetFormID(UInt32 id, bool bGenerateID);			// 38 00451D50
	virtual const char *	GetTypeString(void) const;						// 39 00401AA0 { return ""; }
	virtual bool			Unk_3A(void);									// 3A 009B86F0 { return true; } not used?

	static TESForm * CreateEmptyForm(FormType formType);

	template <class T>
	static inline T* CreateEmptyForm() {
		return static_cast<T*>(CreateEmptyForm((FormType)T::kTypeID));
	}

	static inline TESForm *	LookupByID(FormID id) {
		return LookupFormByID(id);
	}

	UInt32 GetFormID() const {
		return formID; 
	}

	bool Is(FormType type) const { return formType == type; }
	template <class First, class... Rest>
	bool Is(First first, Rest... rest) const {
		return Is(first) || Is(rest...);
	}

	bool IsNot(FormType type) const { return formType != type; }
	template <class First, class... Rest>
	bool IsNot(First first, Rest... rest) const {
		return IsNot(first) && IsNot(rest...);
	}

	bool IsKey() const		{ return this->Is(FormType::Key); }
	bool IsWeapon()	const	{ return this->Is(FormType::Weapon); }
	bool IsAmmo() const		{ return this->Is(FormType::Ammo); }
	bool IsArmor() const	{ return this->Is(FormType::Armor); }
	bool IsSoulGem() const	{ return this->Is(FormType::SoulGem); }
	bool IsLockpick() const	{ return this->formID == 0x00000A; }
	bool IsGold() const		{ return this->formID == 0x00000F; }

	bool	HasWorldModel(void) const;
	UInt32	GetGoldValue() const;
	double	GetWeight() const;
	bool	HasKeyword(BGSKeyword* keyword) const;

	TESFile * GetFile(SInt32 index = -1) const {
		return GetFile_Impl(index);
	}

public:
	// @members
	//void			** _vtbl;			// 00 - 0107CBE4
	TESFileArray	* sourceFiles;		// 04
	Flags			flags;				// 08
	FormID			formID;				// 0C
	UInt16			unk10;				// 10
	FormType		formType;			// 12
	UInt8			pad13;				// 13

protected:
	DEFINE_MEMBER_FN(ReadVMAD, void, 0x0045170, TESFile *mod);			// virtual machine adaptor
	DEFINE_MEMBER_FN_const(GetFile_Impl, TESFile *, 0x004515B0, SInt32 index);

};
STATIC_ASSERT(sizeof(TESForm) == 0x14);
