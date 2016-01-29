#pragma once

// c:_skyrim\code\tesv\bscore\BSFixedString.h

class BSFixedString;

// 08
class BSString
{
public:
	BSString() :m_data(nullptr), m_dataLen(0), m_bufLen(0) { }
	~BSString();	// 00402BE0

	operator const char*() const;
	const char * Get() const;
	
	UInt32 GetLength() const {
		return GetLength_Impl();
	}

	bool Set(const char *str, UInt32 unk = 0) {
		return SetCStr_Impl(str, unk);
	}

	BSString& operator=(const BSFixedString& str);
	BSString& operator=(const char* str);

protected:
	DEFINE_MEMBER_FN_const(GetLength_Impl, UInt32, 0x00402B20);
	DEFINE_MEMBER_FN(SetCStr_Impl, bool, 0x00402C00, const char * str, UInt32 unk);
	DEFINE_MEMBER_FN(SetBSString_Impl, bool, 0x00515DE0, const BSString &);

	// @members
	char	* m_data;	// 00
	UInt16	m_dataLen;	// 04
	UInt16	m_bufLen;	// 06

};
