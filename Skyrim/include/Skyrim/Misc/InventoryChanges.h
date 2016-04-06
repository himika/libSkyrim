#pragma once

#include "../BSCore/BSTList.h"
#include "../Memory.h"
#include <functional>

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

	DEFINE_MEMBER_FN(		GenerateName,	const char *,	0x00475AA0);
	DEFINE_MEMBER_FN_const(	GetCount,		SInt32,			0x005E8920);	// { return this->countDelta; }
	DEFINE_MEMBER_FN_const(	GetValue,		SInt32,			0x00475450);
	DEFINE_MEMBER_FN_const(	GetOwner,		TESForm *,		0x004755A0);
	DEFINE_MEMBER_FN_const(	IsQuestItem,	bool,			0x004759B0);

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
	// 4
	class IItemChangeVisitor
	{
	public:
		enum ResultType
		{
			kResult_Abort = 0,
			kResult_Continue
		};

		virtual ~IItemChangeVisitor() {}												// 00474FC0

		virtual UInt32	Visit(InventoryEntryData *pEntry) = 0;							// 00F51EE8 (pure)
		virtual bool	Unk_02(UInt32 arg1, UInt32 arg2) {								// 00780780
			return true;
		}
		virtual UInt32	Unk_03(InventoryEntryData *pEntry, UInt32 arg2, bool &result) {	// 00474C30
			result = true;
			return Visit(pEntry);
		}
	};


	/*==============================================================================
	class InventoryChanges::FindBestSoulGemVisitor +0000 (_vtbl=010D0938)
	0000: class InventoryChanges::FindBestSoulGemVisitor
	0000: |   class InventoryChanges::IItemChangeVisitor
	==============================================================================*/
	class FindBestSoulGemVisitor : public IItemChangeVisitor
	{
	public:
		// @override
		virtual UInt32	Visit(InventoryEntryData *pEntry) override;						// 004766D0
	};


	explicit InventoryChanges(TESObjectREFR *ref) {
		ctor(ref);
	}
	~InventoryChanges() {
		dtor();
	}

	TES_FORMHEAP_REDEFINE_NEW();

	inline TESObjectREFR * GetOwner() {
		return owner;
	}
	
	void Visit(IItemChangeVisitor *visitor) {
		return Visit_Impl(visitor);
	}
	void Visit(std::function<UInt32(InventoryEntryData *)> &func);

	void VisitWorn(IItemChangeVisitor *visitor) {
		return VisitWorn_Impl(visitor);
	}
	void VisitWorn(std::function<UInt32(InventoryEntryData *)> &func);

	InventoryEntryData * FindEntry(TESForm *item) const;

	DEFINE_MEMBER_FN_const(	HasLeveledItem,		bool,					0x00476260, UInt32 levItemIndex);
	DEFINE_MEMBER_FN_const(	GetEntryData,		InventoryEntryData *,	0x00477B20, TESForm *itemForm, bool unk1, bool unk2);
	DEFINE_MEMBER_FN_const(	GetItemCount,		SInt32,					0x0047A4D0,	TESForm *itemForm);		// { InventoryUtils::ItemFilter filter; return InventoryUtils::CountItem(itemForm, this, &filter); }
	DEFINE_MEMBER_FN(		SetUniqueID,		void,					0x00482050, BaseExtraList* itemList, TESForm * oldForm, TESForm * newForm);
	DEFINE_MEMBER_FN(		InitContainer,		void,					0x00483690);

	DEFINE_MEMBER_FN(RemoveItem, const RefHandle &, 0x0047E920, UInt32 arg1, TESObjectREFR *owner, TESForm *akItem, UInt32 aiCount, UInt32 mode, BaseExtraList *extraList, TESObjectREFR *moveToRef, UInt32 unk8, UInt32 unk9);
	DEFINE_MEMBER_FN(EquipItem, void, 0x00477C80, TESForm *akItem, UInt32 aiCount, TESObjectREFR *owner, bool arg4, bool bLeftHand, UInt32 arg6, UInt32 arg7);


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


	DEFINE_MEMBER_FN(Visit_Impl, void, 0x00475D20, IItemChangeVisitor *visitor);
	DEFINE_MEMBER_FN(VisitWorn_Impl, void, 0x00475D50, IItemChangeVisitor *visitor);
};


namespace InventoryUtils
{
	/*==============================================================================
	class InventoryUtils::ItemFilter +0000 (_vtbl=0107F41C)
	0000: class InventoryUtils::ItemFilter
	==============================================================================*/
	class ItemFilter
	{
	public:
		virtual ~ItemFilter() {};									// 00474D50
		virtual bool Visit(InventoryEntryData *pEntry) {			// 00C8CCA0
			return true;
		}
	};

	
	/*==============================================================================
	class InventoryUtils::QuestItemFilter +0000 (_vtbl=010811D4)
	0000: class InventoryUtils::QuestItemFilter
	0000: |   class InventoryUtils::ItemFilter
	==============================================================================*/
	class QuestItemFilter : public ItemFilter
	{
	public:
		virtual ~QuestItemFilter() {};								// 004910D0
		virtual bool Visit(InventoryEntryData *pEntry) override {	// 00476A50
			return pEntry->IsQuestItem();
		}
	};


	inline SInt32 CountItem(TESForm *itemForm, InventoryChanges *changes, ItemFilter *filter)
	{
		typedef SInt32(*Fn)(TESForm *, InventoryChanges *, ItemFilter *);
		const Fn fn = (Fn)0x0047A460;

		return fn(itemForm, changes, filter);
	}
}
