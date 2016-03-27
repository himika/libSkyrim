#pragma once

// c:_skyrim\code\tesv\bsscript\BSScriptVariable.h

#include "../BSSystem/BSTSmartPointer.h"
#include "../BSCore/BSFixedString.h"
#include <string>

class VMState;

namespace BSScript
{
	// External Classes
	class BSScriptArray;
	class BSScriptClass;
	class BSScriptObject;
	class BSScriptVariable;

	template <class, class>		VMTypeID	GetTypeID(VMState * state);
	template <class _Ty, class>	void		PackValue(BSScriptVariable & dst, _Ty & src, VMState * state);
	template <class _Ty, class>	_Ty			UnpackValue(const BSScriptVariable& src);


	// 04
	class BSScriptType
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

			kType_ObjectArray = 11,		// 0B
			kType_StringArray,			// 0C
			kType_IntArray,				// 0D
			kType_FloatArray,			// 0E
			kType_BoolArray,			// 0F

			kType_ArraysEnd,			// 10
		};

		BSScriptType() : type(kType_None) {
		}
		BSScriptType(VMTypeID a_type) : type(a_type) {
		}
		BSScriptType(const BSScriptType &rhs) : type(rhs.type) {
		}
		BSScriptType(const BSScriptType &typeID, bool bToVector) {
			ctor(typeID, bToVector);
		}

		operator VMTypeID() const {
			return type;
		}

		Type GetUnmangledType(void) const {	// 00505B70
			if (type < kType_ArraysEnd)
				return (Type)type;
			return (type & kType_Object) ? kType_ObjectArray : kType_Object;
		}

		BSScriptClass * GetScriptClass() const {	// 008B5870
			return (type >= kType_ArraysEnd && (type & 1) == 0) ? (BSScriptClass *)type : nullptr;
		}

		bool IsObject(void)	const {
			return GetUnmangledType() == kType_Object;
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
		bool IsObjectArray() const {
			return (type >= kType_ArraysEnd && (type & 1) != 0);
		}
		bool IsLiteralArray() const {
			return (type >= kType_StringArray) && (type <= kType_BoolArray);
		}
		bool IsArray() const {
			return IsLiteralArray() || IsObjectArray();
		}

		void ToString(BSFixedString &out) const;

		// @members
		VMTypeID	type;		// 00

	private:
		DEFINE_MEMBER_FN(ctor, BSScriptType *, 0x00C3A4A0, const BSScriptType &typeID, bool bToVecter);
	};


	// 08 - the same type as VMValue in skse
	class BSScriptVariable : public BSScriptType
	{
	public:
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
			Data& operator=(const BSFixedString &a_str);
			Data& operator=(const char* a_str);
			Data& operator=(const BSScriptObject *a_id);
			Data& operator=(const BSScriptArray *a_arr);
		};

		BSScriptVariable() : BSScriptType(kType_None) {
			data.u = 0;
		}
		BSScriptVariable(const BSScriptType &a_type) : BSScriptType(a_type) {
			data.u = 0;
		}
		BSScriptVariable(const BSScriptVariable &rhs) : BSScriptType() {	// 005398B0
			data.u = 0;
			Assign(rhs);
		}
		BSScriptVariable(BSScriptVariable &&rhs) {
			type = rhs.type;
			data.u = rhs.data.u;

			rhs.type = kType_None;
			rhs.data.u = 0;
		}

		~BSScriptVariable() {
			Destroy();
		}

		BSScriptVariable& operator=(const BSScriptVariable &rhs) {
			Assign(rhs);
			return *this;
		}
		BSScriptVariable& operator=(BSScriptVariable &&rhs) {
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

		void SetObject(const BSScriptObject *a_object);

		void SetObject(const BSScriptObject *a_object, VMTypeID a_type) {
			SetNone();
			type = a_type;
			data = a_object;
		}

		void SetArray(const BSScriptArray * a_arr, VMTypeID a_type) {
			SetNone();
			type = a_type;
			data = a_arr;
		}

		void SetString(const BSFixedString &str) {
			SetNone();
			type = kType_String;
			data = str;
		}

		void SetInt(UInt32 u) {
			SetNone();
			type = kType_Int;
			data.u = u;
		}

		void SetInt(SInt32 i) {
			SetNone();
			type = kType_Int;
			data.i = i;
		}

		void SetInt(double lf) {
			SetNone();
			type = kType_Int;
			data.i = (int)lf;
		}

		void SetInt(const char * str);

		void SetInt(const BSFixedString &str) {
			SetInt(str.c_str());
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

		void GetTypeName(BSFixedString &out) const
		{
			this->BSScriptType::ToString(out);
		}

		// converts to string - e.g. [Actor < (00000014)>]
		std::string ToString(bool arg1, bool arg2) const;

		const BSScriptVariable & CastTo(const BSScriptType &typeID, BSScriptVariable &var);

		// @members
		//BSScriptType	type;	// 00
		Data			data;	// 04

	private:
		DEFINE_MEMBER_FN(Assign, void, 0x00C329E0, const BSScriptVariable & src);
		DEFINE_MEMBER_FN(Destroy, void, 0x00C328E0);
		//DEFINE_MEMBER_FN(SetArray, void, 0x00C32CE0, BSScriptArray * data);
		DEFINE_MEMBER_FN_const(ToString_Internal, void, 0x00C325E0, char* buf, UInt32 bufSize, bool arg3, bool arg4);
		DEFINE_MEMBER_FN_const(IsNoneOrInvalid, bool, 0x00C31C60);

		DEFINE_MEMBER_FN(GetScriptObjectPtr, BSTSmartPointer<BSScriptObject> &, 0x00C322E0);
		DEFINE_MEMBER_FN(SetScriptObject, void, 0x00C32C70, const BSTSmartPointer<BSScriptClass> &, const BSTSmartPointer<BSScriptObject> &);
	};
	STATIC_ASSERT(sizeof(BSScriptVariable) == 0x08);
}
