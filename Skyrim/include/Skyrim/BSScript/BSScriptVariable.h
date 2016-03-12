#pragma once

// c:_skyrim\code\tesv\bsscript\BSScriptVariable.h

#include "../BSSystem/BSTSmartPointer.h"
#include "../BSCore/BSFixedString.h"
#include <string>

class VMState;

namespace BSScript
{
	// Forward declarations
	class BSScriptArray;
	class BSScriptObject;
	class BSScriptVariable;

	template <class, class>		VMTypeID	GetTypeID(VMState * state);
	template <class _Ty, class>	void		PackValue(BSScriptVariable & dst, _Ty & src, VMState * state);
	template <class _Ty, class>	_Ty			UnpackValue(const BSScriptVariable& src);

	// 08 - the same type as VMValue in skse
	class BSScriptVariable
	{
	public:
		enum Type
		{
			kType_None = 0,
			kType_Object = 1,
			kType_String = 2,
			kType_Int = 3,
			kType_Float = 4,
			kType_Bool = 5,

			kType_ArraysStart = 11,
			kType_ObjectArray = 11,		// 0B
			kType_StringArray = 12,		// 0C
			kType_IntArray = 13,		// 0D
			kType_FloatArray = 14,		// 0E
			kType_BoolArray = 15,		// 0F
			kType_ArraysEnd = 16,

			kNumLiteralArrays = 4
		};

		union Data
		{
			SInt32			i;
			UInt32			u;
			float			f;
			bool			b;
			void			* p;
			BSScriptArray	* arr;
			BSScriptObject	* object;
			const char		* str;	// BSFixedString

			operator SInt32() const					{ return i; }
			operator UInt32() const					{ return u; }
			operator float() const					{ return f; }
			operator bool() const					{ return b; }
			operator const char*() const			{ return str; }

			operator BSFixedString() &				{ return *reinterpret_cast<BSFixedString *>(this); }
			operator const BSFixedString &() const	{ return *reinterpret_cast<const BSFixedString *>(this); }
			operator BSScriptObject *()				{ return object; }
			operator const BSScriptObject *() const	{ return object; }
			operator BSScriptArray *()				{ return arr; }
			operator const BSScriptArray *() const	{ return arr; }

			Data& operator=(SInt32 a_i)						{ i = a_i; return *this; }
			Data& operator=(UInt32 a_u)						{ u = a_u; return *this; }
			Data& operator=(float a_f)						{ f = a_f; return *this; }
			Data& operator=(bool a_b)						{ b = a_b; return *this; }
			Data& operator=(const BSFixedString & a_str);
			Data& operator=(const char* a_str);
			Data& operator=(const BSScriptObject * a_id);
			Data& operator=(const BSScriptArray* a_arr);
		};

		BSScriptVariable() {
			type = kType_None;
			data.u = 0;
		}
		BSScriptVariable(const BSScriptVariable & rhs) {
			type = kType_None;
			data.u = 0;
			Assign(rhs);
		}
		BSScriptVariable(BSScriptVariable && rhs) {
			type = rhs.type;
			data.u = rhs.data.u;

			rhs.type = kType_None;
			rhs.data.u = 0;
		}

		~BSScriptVariable() {
			Destroy();
		}

		BSScriptVariable& operator=(const BSScriptVariable & rhs) {
			Assign(rhs);
			return *this;
		}
		BSScriptVariable& operator=(BSScriptVariable && rhs) {
			Destroy();

			type = rhs.type;
			data.u = rhs.data.u;

			rhs.type = kType_None;
			rhs.data.u = 0;
			
			return *this;
		}

		bool operator==(const BSScriptVariable & rhs) const {
			if (IsObject() && rhs.IsObject())
				return data.u == rhs.data.u;
			else
				return (type == rhs.type) && (data.u == rhs.data.u);
		}
		bool operator!=(const BSScriptVariable & rhs) const {
			return !operator==(rhs);
		}

		UInt32 GetUnmangledType(void) const {
			if (type < kType_ArraysEnd)
				return type;
			return (type & kType_Object) ? kType_ObjectArray : kType_Object;
		}

		bool IsObject(void)	const {
			return GetUnmangledType() == kType_Object;
		}
		bool IsObjectArray() const {
			return (type >= kType_ArraysEnd && (type & kType_Object) != 0);
		}
		bool IsLiteralArray() const {
			return type - kType_ArraysStart <= kNumLiteralArrays;
		}
		bool IsInt() const {
			return type == kType_Int;
		}
		bool IsFloat() const {
			return type == kType_Float;
		}
		bool IsString() const {
			return type == kType_String;
		}
		bool IsBool() const {
			return type == kType_Bool;
		}
		bool IsArray() const {
			return IsLiteralArray() || IsObjectArray();
		}

		BSScriptObject *		GetObject(void);
		const BSScriptObject *	GetObject(void) const;
		BSScriptArray *			GetArray(void);
		const BSScriptArray *	GetArray(void) const;
		const BSFixedString &	GetString(void) const;

		void SetNone(void) {
			Destroy();
			type = kType_None;
			data.u = 0;
		}

		void SetObject(const BSScriptObject *a_object, UInt32 a_type) {
			SetNone();
			type = a_type;
			data = a_object;
		}

		void SetArray(const BSScriptArray * a_arr, UInt32 a_type) {
			SetNone();
			type = a_type;
			data = a_arr;
		}

		void SetString(const BSFixedString &str) {
			SetNone();
			type = kType_String;
			data = str;
		}

		template <class _Ty>
		void Pack(const _Ty src, VMState* state)
		{
			PackValue<_Ty>(*this, src, state);
		}

		template <class _Ty>
		_Ty Unpack(void) const
		{
			return UnpackValue<_Ty>(*this);
		}

		std::string GetTypeName() const;

		void GetTypeName(BSFixedString &out) const;

		// convert class object to string - e.g. [Actor < (00000014)>]
		std::string ToString(bool arg1, bool arg2) const;

		// @members
		VMTypeID	type;	// 00
		Data		data;	// 04

	private:
		DEFINE_MEMBER_FN(Assign, void, 0x00C329E0, const BSScriptVariable & src);
		DEFINE_MEMBER_FN(Destroy, void, 0x00C328E0);
		//DEFINE_MEMBER_FN(SetArray, void, 0x00C32CE0, BSScriptArray * data);
		DEFINE_MEMBER_FN_const(ToString_Internal, void, 0x00C325E0, char* buf, UInt32 bufSize, bool arg3, bool arg4);
		DEFINE_MEMBER_FN_const(IsNoneOrInvalid, bool, 0x00C31C60);
	};
	STATIC_ASSERT(sizeof(BSScriptVariable) == 0x08);
}
