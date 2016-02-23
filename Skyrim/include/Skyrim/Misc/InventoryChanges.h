#pragma once

#include "../BSCore/BSTList.h"
#include "../Memory.h"

class BaseExtraList;
class TESForm;
class TESObjectREFR;


// 0C
class InventoryEntryData
{
public:
	InventoryEntryData(TESForm *item, SInt32 count);	// 004750C0
	~InventoryEntryData();

	bool IsOwnedBy(TESForm *actor, bool unk1) const {
		return IsOwnedBy_Impl2(actor, unk1);
	}
	bool IsOwnedBy(TESForm *actor, TESForm *itemOwner, bool unk1) const {
		return IsOwnedBy_Impl1(actor, itemOwner, unk1);
	}

	TES_FORMHEAP_REDEFINE_NEW();

	DEFINE_MEMBER_FN(GenerateName, const char *, 0x00475AA0);
	DEFINE_MEMBER_FN_const(GetCount, UInt32, 0x005E8920);		// { return this->countDelta; }
	DEFINE_MEMBER_FN_const(GetValue, SInt32, 0x00475450);
	DEFINE_MEMBER_FN_const(GetOwner, TESForm*, 0x004755A0);
	DEFINE_MEMBER_FN_const(IsQuestItem, bool, 0x004759B0);

	void AddEntryList(BaseExtraList *extra);

	// @members
	TESForm							* baseForm;		// 00
	BSSimpleList<BaseExtraList *>	* extraList;	// 04
	SInt32							countDelta;		// 08

private:
	DEFINE_MEMBER_FN_const(IsOwnedBy_Impl1, bool, 0x004755D0, TESForm *actor, TESForm *itemOwner, bool unk1);
	DEFINE_MEMBER_FN_const(IsOwnedBy_Impl2, bool, 0x00477010, TESForm *actor, bool unk1);
};


// 14?
class InventoryChanges
{
public:
	/*==============================================================================
	class InventoryChanges::IItemChangeVisitor +0000 (_vtbl=0107F408)
	0000: class InventoryChanges::IItemChangeVisitor
	==============================================================================*/
	class IItemChangesVisitor
	{
	public:
		virtual ~IItemChangesVisitor();												// 00474FC0

		virtual bool	Visit(InventoryEntryData *data) = 0;						// 00F51EE8 (pure)
		virtual bool	Unk_02(UInt32 arg1, UInt32 arg2);							// 00780780 { return true; }
		virtual bool	Unk_03(InventoryEntryData *arg1, UInt32 arg2, bool *arg3);	// 00474C30 { arg3 = true; return Unk_01(arg1); }
	};

	/*==============================================================================
	class InventoryChanges::FindBestSoulGemVisitor +0000 (_vtbl=010D0938)
	0000: class InventoryChanges::FindBestSoulGemVisitor
	0000: |   class InventoryChanges::IItemChangeVisitor
	==============================================================================*/
	class FindBestSoulGemVisitor : public IItemChangesVisitor
	{
	public:
		// @override
		virtual bool	Visit(InventoryEntryData *data) override;						// 004766D0
	};


	explicit InventoryChanges(TESObjectREFR *ref)
	{
		ctor(ref);
	}
	~InventoryChanges()
	{
		dtor();
	}

	TES_FORMHEAP_REDEFINE_NEW();

	inline TESObjectREFR * GetOwner() {
		return owner;
	}
	
	InventoryEntryData * FindEntry(TESForm *item) const;

	DEFINE_MEMBER_FN(SetUniqueID,		void,	0x00482050, BaseExtraList* itemList, TESForm * oldForm, TESForm * newForm);
	DEFINE_MEMBER_FN(Visit,				void,	0x00475D50, IItemChangesVisitor*);
	DEFINE_MEMBER_FN(HasLeveledItem,	bool,	0x00476260, UInt32 levItemIndex);
	DEFINE_MEMBER_FN(InitContainer,		void,	0x00483690);

	// @members
	BSSimpleList<InventoryEntryData *>	* entryList;	// 00
	TESObjectREFR						* owner;		// 04
	float								totalWeight;	// 08 - init'd -1
	float								armorWeight;	// 0C
	bool								changed;		// 10 - init'd 0
	bool								unk11;			// 11 - init'd 0

private:
	DEFINE_MEMBER_FN(ctor, InventoryChanges *, 0x00477280, TESObjectREFR *ref);
	DEFINE_MEMBER_FN(dtor, void, 0x00477A60);
};
