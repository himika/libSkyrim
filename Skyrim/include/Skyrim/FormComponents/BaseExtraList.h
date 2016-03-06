#pragma once

#include "../ExtraData/BSExtraData.h"
#include "../BSCore/BSSpinLock.h"

class TESForm;
class ExtraTextDisplayData;
class TESObjectREFR;
class BGSKeyword;
class InventoryChanges;

// 08
class BaseExtraList
{
public:
	BaseExtraList();
	~BaseExtraList();

	class const_iterator
	{
	public:
		typedef const_iterator _iter;
		typedef const BSExtraData &reference;
		typedef const BSExtraData *pointer;

		const_iterator(const BSExtraData *extra) : m_cur(const_cast<BSExtraData*>(extra)) {
		}

		operator pointer() const {
			return m_cur;
		}

		bool empty() const {
			return m_cur == nullptr;
		}

		operator bool() const {
			return !empty();
		}
		reference operator*() const {
			return *m_cur;
		}
		pointer operator->() const {
			return m_cur;
		}
		_iter& operator++() {
			m_cur = m_cur->next;
			return *this;
		}
		_iter operator++(int) {
			_iter tmp = *this;
			++*this;
			return tmp;
		}
		bool operator==(const _iter& rhs) const {
			return (m_cur == rhs.m_cur);
		}
		bool operator!=(const _iter& rhs) const {
			return (!(*this == rhs));
		}

	protected:
		BSExtraData *m_cur;
	};

	class iterator : public const_iterator
	{
	public:
		typedef iterator _iter;
		typedef BSExtraData &reference;
		typedef BSExtraData *pointer;

		iterator(BSExtraData *extra) : const_iterator(extra) {
		}

		operator pointer() const {
			return m_cur;
		}
		pointer operator*() const {
			return m_cur;
		}
		pointer operator->() const {
			return m_cur;
		}

		_iter& operator++() {
			m_cur = m_cur->next;
			return *this;
		}
		_iter operator++(int) {
			_iter tmp = *this;
			++*this;
			return tmp;
		}
	};

	iterator begin() {
		return iterator(m_data);
	}
	const_iterator cbegin() const {
		return const_iterator(m_data);
	}
	const_iterator begin() const {
		return cbegin();
	}
	iterator end() {
		return iterator(nullptr);
	}
	const_iterator cend() const {
		return const_iterator(nullptr);
	}
	const_iterator end() const {
		return cend();
	}


	bool HasType(UInt32 type) const {								// 0040A760
		return (m_presence) ? m_presence->HasType(type) : false;
	}
	UInt32 ItemsInList() const;										// 0070A710
	BSExtraData* AddExtra(BSExtraData *extra);						// 0040A790
	BSExtraData* GetExtraData(UInt32 type) const;					// 0040A8A0
	void RemoveAll(bool bDelete = true);							// 0040B890
	void RemoveAllDefault(bool bDelete = true);						// 0040B940
	bool RemoveExtra(UInt32 type);									// 0040BC10
	void RemoveExtra(BSExtraData *toRemove, bool bDelete = true);	// 0040BB00
	void RemoveAllCopyableExtra(bool bDelete = true);				// 0040BD30

	inline bool HasType(ExtraDataType type) const {
		return HasType((UInt32)type);
	}
	template<typename T>
	inline bool HasType(void) const {
		return HasType(T::kExtraTypeID);
	}
	inline BSExtraData* GetExtraData(ExtraDataType type) const {
		return GetExtraData((UInt32)type);
	}
	template<typename T>
	inline T* GetExtraData(void) const {
		return (T*)GetExtraData(T::kExtraTypeID);
	}
	inline bool RemoveExtra(ExtraDataType type) {
		return RemoveExtra((UInt32)type);
	}
	template<typename T>
	inline bool RemoveExtra(void) {
		return RemoveExtra(T::kExtraTypeID);
	}

	BSExtraData* GetByType(UInt32 type) const;
	inline BSExtraData* GetByType(ExtraDataType type) const {
		return GetByType((UInt32)type);
	}
	template<typename T>
	inline T* GetByType(void) const {
		return (T*)GetByType(T::kExtraTypeID);
	}

	bool Remove(UInt8 type, BSExtraData* toRemove);
	inline bool Remove(ExtraDataType type, BSExtraData* toRemove) {
		return Remove((UInt8)type, toRemove);
	}
	template<typename T>
	inline bool Remove(T* toRemove) {
		return Remove(T::kExtraTypeID, toRemove);
	}

	bool Add(UInt8 type, BSExtraData* toAdd);
	inline bool Add(ExtraDataType type, BSExtraData* toAdd) {
		return Add((UInt8)type, toAdd);
	}
	template<typename T>
	inline bool Add(T* toAdd) {
		return Add(T::kExtraTypeID, toAdd);
	}

	const char * GetDisplayName(TESForm * type);
	
	inline ExtraTextDisplayData* GetExtraTextDisplayData() const {
		return GetExtraTextDisplayData_Impl();
	}

	inline void BlockActivation(bool bBlocked) {
		BlockActivation_Impl(true, bBlocked);
	}

	inline bool IsActivationBlocked() const {
		return IsActivationBlocked_Impl(true);
	}

	inline RefHandle GetAshPileRefHandle(RefHandle &refHandle) const {
		return GetAshPileRefHandle_Impl(refHandle);
	}

	inline bool CheckContainerExtraData(bool isEquipped) const {
		return CheckContainerExtraData_Impl(isEquipped);
	}

	inline TESObjectREFR* GetLinkedRef(BGSKeyword * keyword) const {
		return GetLinkedRef_Impl(keyword);
	}

	inline bool IsQuestItem() const {
		return IsQuestItem_Impl();
	}

	inline TESObjectREFR* GetReferenceFromItemDropper() const {
		return GetReferenceFromItemDropper_Impl();
	}

	inline SInt16 GetItemCount() const {
		return GetItemCount_Impl();
	}

	inline InventoryChanges * GetInventoryChanges() const {
		return GetInventoryChanges_Impl();
	}

	inline void SetInventoryChanges(InventoryChanges *changes) {
		SetInventoryChanges_Impl(changes);
	}

	inline const char * GetEditorID() const {
		return GetEditorID_Impl();
	}

protected:
	struct PresenceBitfield
	{
		inline bool HasType(UInt32 type) const
		{
			UInt32 index = (type >> 3);
			if (index >= 0x17)
				return false;
			UInt8 bitMask = 1 << (type & 7);
			return (bits[index] & bitMask) != 0;
		}

		inline void MarkType(UInt32 type, bool bCleared)
		{
			UInt32 index = (type >> 3);
			UInt8 bitMask = 1 << (type & 7);
			UInt8& flag = bits[index];
			if (bCleared) {
				flag &= ~bitMask;
			}
			else {
				flag |= bitMask;
			}
		}

		UInt8	bits[0x17];
	};

	inline void MarkType(UInt32 type, bool bCleared)
	{
		m_presence->MarkType(type, bCleared);
	}
	inline void MarkType(ExtraDataType type, bool bCleared) {
		MarkType((UInt32)type, bCleared);
	}

	inline BSExtraData* GetPrevExtraData(UInt32 type) const {
		return GetPrevExtraData_Impl(type);
	}

	// @members
	BSExtraData			* m_data;		// 00
	PresenceBitfield	* m_presence;	// 04

protected:
	static BSSpinLock &ms_lock;

private:
	DEFINE_MEMBER_FN_const(	ItemsInList_Impl,				UInt32,			0x0040A710);
	DEFINE_MEMBER_FN_const(	HasType_Impl,					bool,			0x0040A760);
	DEFINE_MEMBER_FN(		AddExtra_Impl,					BSExtraData*,	0x0040A790, BSExtraData *extra);
	DEFINE_MEMBER_FN_const(	GetExtraData_Impl,				BSExtraData*,	0x0040A8A0, UInt32 type);
	DEFINE_MEMBER_FN_const(	GetPrevExtraData_Impl,			BSExtraData*,	0x0040A970, UInt32 type);
	DEFINE_MEMBER_FN_const(	CheckContainerExtraData_Impl,	bool,			0x0040ABF0, bool isEquipped);
	DEFINE_MEMBER_FN(		RemoveAll_Impl,					void,			0x0040B890, bool bDelete);
	DEFINE_MEMBER_FN(		RemoveAllDefault_Impl,			void,			0x0040B940, bool bDelete);
	DEFINE_MEMBER_FN(		RemoveExtra1_Impl,				bool,			0x0040BC10, UInt32 type);
	DEFINE_MEMBER_FN(		RemoveExtra2_Impl,				void,			0x0040BB00, BSExtraData *toRemove, bool bDelete);
	DEFINE_MEMBER_FN(		RemoveAllCopyableExtra_Impl,	void,			0x0040BD30, bool bDelete);
	DEFINE_MEMBER_FN_const(	GetInventoryChanges_Impl,		InventoryChanges*,	0x0040C090);
	DEFINE_MEMBER_FN_const(	GetOwner_Impl,					TESForm*,		0x0040C0B0);
	DEFINE_MEMBER_FN_const(	GetItemCount_Impl,				SInt16,			0x0040C190);
	DEFINE_MEMBER_FN(		SetInventoryChanges_Impl,		void,			0x0040C660, InventoryChanges *changes);
	//DEFINE_MEMBER_FN_const(GetCellImageSpace_Impl,		CellImageSpace*,	0x0040CDE0);
	DEFINE_MEMBER_FN_const(	GetEditorID_Impl,				const char*,	0x0040CDF0);
	//DEFINE_MEMBER_FN_const(GetPackage_Impl,				TESPackage*,	0x0040CE00);
	DEFINE_MEMBER_FN_const(	IsActivationBlocked_Impl,		bool,			0x0040E850, bool unk1);
	DEFINE_MEMBER_FN_const(	GetAshPileRefHandle_Impl,		RefHandle,		0x00411850, RefHandle &refHandle);
	DEFINE_MEMBER_FN_const(	GetLinkedRef_Impl,				TESObjectREFR*,	0x00415700, BGSKeyword * keyword);
	DEFINE_MEMBER_FN(		BlockActivation_Impl,			void,			0x00416C50, bool unk2, bool bBlocked);
	DEFINE_MEMBER_FN_const(	GetExtraTextDisplayData_Impl,	ExtraTextDisplayData*,	0x00418590);
	DEFINE_MEMBER_FN_const(	GetReferenceFromItemDropper_Impl,	TESObjectREFR*,	0x004153C0);
	DEFINE_MEMBER_FN_const(	IsQuestItem_Impl,				bool,			0x00418FE0);


};
STATIC_ASSERT(sizeof(BaseExtraList) == 0x08);
