#pragma once

// c:_skyrim\code\tesv\bsscript\BSScriptArray.h


#include "../BSSystem/BSTSmartPointer.h"
#include "BSScriptVariable.h"

namespace BSScript
{
	class BSScriptVariable;

	BSSmartPointer(BSScriptArray);

	// 04
	class BSScriptTypeID
	{
	public:
		BSScriptTypeID() {}
		BSScriptTypeID(VMTypeID a_id) : id(a_id) {}
		BSScriptTypeID(BSScriptTypeID& typeID, bool bToVector) {
			ctor(typeID, bToVector);
		}

		operator VMTypeID() const {
			return id;
		}

		// @members
		VMTypeID	id;

	private:
		DEFINE_MEMBER_FN(ctor, BSScriptTypeID*, 0x00C3A4A0, BSScriptTypeID& typeID, bool bToVecter);
	};


	// 14+
	// the same type as VMValue::ArrayData in skse
	class BSScriptArray : public BSIntrusiveRefCounted
	{
	public:
		typedef std::size_t size_type;
		typedef BSScriptVariable value_type;
		typedef BSTSmartPointer<BSScriptArray> SmartPtr;

		~BSScriptArray();

		UInt32 GetSize(void) const {
			return len;
		}
		
		BSScriptVariable & operator[](size_type idx);
		const BSScriptVariable& operator[](size_type idx) const;

		BSScriptVariable & Get(size_type idx) {
			return (*this)[idx];
		}
		const BSScriptVariable & Get(size_type idx) const {
			return (*this)[idx];
		}

		bool GetAt(size_type idx, BSScriptVariable &val) const {
			return (idx < GetSize()) ? (val = (*this)[idx], true) : false;
		}

		bool SetAt(size_type idx, const BSScriptVariable &val) {
			return (idx < GetSize()) ? ((*this)[idx] = val, true) : false;
		}

	private:
		BSScriptArray();

		BSScriptArray(BSScriptTypeID & typeID, size_type size) {
			ctor(typeID, size);
		}

		BSScriptVariable * GetData(void) {
			return reinterpret_cast<BSScriptVariable*>(this + 1);
		}

		const BSScriptVariable * GetData(void) const {
			return reinterpret_cast<const BSScriptVariable*>(this + 1);
		}

		DEFINE_MEMBER_FN(ctor, BSScriptArray*, 0x00C3A050, BSScriptTypeID & typeID, size_type size);
		DEFINE_MEMBER_FN(dtor, void, 0x00C3A0A0);

		// @members
		BSScriptTypeID		typeID;		// 04
		UInt32				len;		// 08
		UInt32				unk0C;		// 0C
		UInt32				unk10;		// 10
		//BSScriptVariable	data[];		// 14~
	};
}
