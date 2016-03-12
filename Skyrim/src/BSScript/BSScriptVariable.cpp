#include "Skyrim.h"
#include "Skyrim/BSScript/BSScriptVariable.h"
#include "Skyrim/BSScript/BSScriptClass.h"
#include "Skyrim/BSScript/BSScriptArray.h"
#include "Skyrim/BSScript/BSScriptObject.h"

namespace BSScript
{
	BSScriptVariable::Data& BSScriptVariable::Data::operator=(const BSFixedString & a_str)
	{
		*reinterpret_cast<BSFixedString*>(this) = a_str;
		return *this;
	}
	BSScriptVariable::Data& BSScriptVariable::Data::operator=(const char* a_str)
	{
		*reinterpret_cast<BSFixedString*>(this) = a_str;
		return *this;
	}
	BSScriptVariable::Data& BSScriptVariable::Data::operator=(const BSScriptObject * a_id)
	{
		*reinterpret_cast<BSTSmartPointer<BSScriptObject>*>(this) = a_id;
		return *this;
	}
	BSScriptVariable::Data& BSScriptVariable::Data::operator=(const BSScriptArray* a_arr)
	{
		*reinterpret_cast<BSTSmartPointer<BSScriptArray>*>(this) = a_arr;
		return *this;
	}

	BSScriptObject* BSScriptVariable::GetObject(void)
	{
		return (IsObject()) ? (BSScriptObject*)data : nullptr;
	}

	const BSScriptObject* BSScriptVariable::GetObject(void) const
	{
		return (IsObject()) ? (const BSScriptObject*)data : nullptr;
	}

	BSScriptArray* BSScriptVariable::GetArray(void)
	{
		return (IsArray()) ? (BSScriptArray*)data : nullptr;
	}

	const BSScriptArray* BSScriptVariable::GetArray(void) const
	{
		return (IsArray()) ? (const BSScriptArray*)data : nullptr;
	}

	const BSFixedString& BSScriptVariable::GetString(void) const
	{
		if (IsString())
			return (const BSFixedString &)data;

		static BSFixedString empty("");
		return empty;
	}

	std::string BSScriptVariable::GetTypeName() const
	{
		std::string typeName;

		UInt32 tp = GetUnmangledType();

		// array type -> single type
		if (tp > 10)
			tp -= 10;

		switch (tp)
		{
		case kType_None:
			typeName = "None";
			break;
		case kType_Object:
		{
			const BSScriptClass *klass = reinterpret_cast<BSScriptClass *>(type & 0xFFFFFFFE);
			const BSFixedString &name = klass->GetName();
			typeName = (name.length() > 0) ? name.c_str() : "None";
		}
		break;
		case kType_String:
			typeName = "String";
			break;
		case kType_Int:
			typeName = "Int";
			break;
		case kType_Float:
			typeName = "Float";
			break;
		case kType_Bool:
			typeName = "Bool";
			break;
		default:
			typeName = "Unknown";
			break;
		}

		if (IsArray())
			typeName += "[]";

		return typeName;
	}

	void BSScriptVariable::GetTypeName(BSFixedString &out) const
	{
		char buf[256];

		UInt32 tp = GetUnmangledType();

		// array type -> single type
		if (tp > 10)
			tp -= 10;

		const char *typeName;

		switch (tp)
		{
		case kType_None:
			typeName = "None";
			break;
		case kType_Object:
		{
			const BSScriptClass *klass = reinterpret_cast<BSScriptClass *>(type & 0xFFFFFFFE);
			const BSFixedString &name = klass->GetName();
			typeName = (name.length() > 0) ? name.c_str() : "None";
		}
		break;
		case kType_String:
			typeName = "String";
			break;
		case kType_Int:
			typeName = "Int";
			break;
		case kType_Float:
			typeName = "Float";
			break;
		case kType_Bool:
			typeName = "Bool";
			break;
		default:
			typeName = "Unknown";
			break;
		}

		strcpy_s(buf, typeName);

		if (IsArray())
			strcat_s(buf, "[]");

		out = buf;
	}

	std::string BSScriptVariable::ToString(bool arg1, bool arg2) const
	{
		char buf[0x400];
		ToString_Internal(buf, sizeof(buf), arg1, arg2);

		return std::string(buf);
	}
}
