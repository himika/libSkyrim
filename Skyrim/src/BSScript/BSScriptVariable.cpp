#include "Skyrim.h"
#include "Skyrim/BSScript/BSScriptVariable.h"
#include "Skyrim/BSScript/BSScriptClass.h"
#include "Skyrim/BSScript/BSScriptArray.h"
#include "Skyrim/BSScript/BSScriptObject.h"
#include "Skyrim/SkyrimVM.h"
#include "Skyrim/VMState.h"
#include <stdlib.h>

namespace BSScript
{
	void BSScriptType::ToString(BSFixedString &out) const
	{
		char buf[0x100];

		// array type -> single type
		bool bIsArray = false;
		UInt32 singleType = GetUnmangledType();
		if (singleType > 10)
		{
			bIsArray = true;
			singleType -= 10;
		}

		const char *typeName;

		switch (singleType)
		{
		case kType_None:
			typeName = "None";
			break;
		case kType_Object:
		{
			const BSScriptClass *klass = reinterpret_cast<BSScriptClass *>(type & 0xFFFFFFFE);
			typeName = "None";
			if (klass)
			{
				const BSFixedString &name = klass->GetName();
				if (name.length() > 0)
					typeName = name.c_str();
			}
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

		if (bIsArray)
			strcat_s(buf, "[]");

		out = buf;
	}

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
		*reinterpret_cast<BSScriptObjectPtr *>(this) = a_id;
		return *this;
	}
	BSScriptVariable::Data& BSScriptVariable::Data::operator=(const BSScriptArray* a_arr)
	{
		*reinterpret_cast<BSScriptArrayPtr *>(this) = a_arr;
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

	void BSScriptVariable::SetObject(const BSScriptObject *a_object)
	{
		SetNone();
		type = a_object->GetClass()->GetTypeID();
		data = a_object;
	}

	void BSScriptVariable::SetInt(const char *p)
	{
		SetInt(atoi(p));
	}

	const BSScriptVariable & BSScriptVariable::CastTo(const BSScriptType &toType, BSScriptVariable &toVar)
	{
		if (this->type == toType.type)
		{
			toVar = *this;
			return toVar;
		}

		UInt32 unmangled = toType.GetUnmangledType();

		switch (unmangled)
		{
		case kType_Object:
			{
				UInt32 UnmangledThis = GetUnmangledType();

				if (UnmangledThis == kType_None)
				{
					toVar = BSScriptVariable(toType);
				}
				else if (UnmangledThis != kType_Object)
				{
					// "Cannot cast from %s to %s"
					toVar = BSScriptVariable(toType);
				}
				else
				{
					VMState *state = g_skyrimVM->GetState();
					BSScriptClassPtr toClassPtr = toType.GetScriptClass();
					BSScriptObjectPtr &fromObjPtr = GetScriptObjectPtr();
					BSScriptObjectPtr toObjPtr = nullptr;

					if (fromObjPtr && state->CastScriptObject(fromObjPtr, toClassPtr, toObjPtr) && toObjPtr)
					{
						toVar.SetScriptObject(toClassPtr, toObjPtr);
					}
					else
					{
						toVar = BSScriptVariable(toType);
					}
				}
			}
			break;

		case kType_String:
			{
				char buf[0x400];
				ToString_Internal(buf, 0x400, false, false);
				BSFixedString str = buf;
				toVar.SetString(str);
			}
			break;

		case kType_Int:
			if (type == kType_String)
			{
				const BSFixedString &str = GetString();
				int num = (str.length() > 0) ? atoi(str.c_str()) : 0;
				toVar.SetInt(num);
			}
			else if (type == kType_Float)
			{
				toVar.SetNone();
				toVar.type = kType_Int;
				toVar.data.i = (int)data.f;
			}
			else if (type == kType_Bool)
			{
				toVar.SetNone();
				toVar.type = kType_Int;
				toVar.data.i = (data.b) ? 1 : 0;
			}
			else
			{
				// "Cannot cast from %s to %s"
				toVar = BSScriptVariable(toType);
			}
			break;

		case kType_Float:
			if (type == kType_String)
			{
				const BSFixedString &str = GetString();
				double num = (str.length() > 0) ? atof(str.c_str()) : 0.0f;
				toVar.SetNone();
				toVar.type = kType_Float;
				toVar.data.f = (float)num;
			}
			else if (type == kType_Int)
			{
				toVar.SetNone();
				toVar.type = kType_Float;
				toVar.data.f = (float)data.i;
			}
			else if (type == kType_Bool)
			{
				SetInt(data.b ? 1.0f : 0.0f);
			}
			else
			{
				// "Cannot cast from %s to %s"
				toVar = BSScriptVariable(toType);
			}
			break;

		case kType_Bool:
			if (type == kType_String)
			{
				const BSFixedString &str = GetString();
				toVar.SetNone();
				toVar.type = kType_Bool;
				toVar.data.b = (str.length() > 0);
			}
			else if (type == kType_Int)
			{
				toVar.SetNone();
				toVar.type = kType_Bool;
				toVar.data.b = (data.i != 0);
			}
			else if (type == kType_Float)
			{
				toVar.SetNone();
				toVar.type = kType_Bool;
				toVar.data.b = (data.f != 0.0f);
			}
			else
			{
				// "Cannot cast from %s to %s"
				toVar = BSScriptVariable(toType);
			}
			break;

		default:
			// "Cannot cast from %s to %s"
			toVar = BSScriptVariable(toType);
		}

		return toVar;
	}

	std::string BSScriptVariable::ToString(bool arg1, bool arg2) const
	{
		char buf[0x400];
		ToString_Internal(buf, sizeof(buf), arg1, arg2);

		return std::string(buf);
	}
}
