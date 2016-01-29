#pragma once

// 04
class BSFixedString
{
public:
	BSFixedString() : data(nullptr) { }
	BSFixedString(const BSFixedString & str);		// TESV.00A50D50
	BSFixedString(BSFixedString && str);
	BSFixedString(const char * str);				// TESV.00A511C0
	~BSFixedString();

	operator const char*() const { return data; }

	BSFixedString& operator=(const BSFixedString& rhs);
	BSFixedString& operator=(BSFixedString&& rhs);
	BSFixedString& operator=(const char* rhs);

	bool operator==(const char* str) const;
	bool operator!=(const char* str) const { return !(*this == str); }
	bool operator==(const BSFixedString& rhs) const { return data == rhs.data; }
	bool operator!=(const BSFixedString& rhs) const { return data != rhs.data; }

	BSFixedString& assign(const char * str);
	BSFixedString& assign(const BSFixedString & str);
	BSFixedString& assign(BSFixedString && str);

	UInt32	length(void) const;
	const char* c_str(void) const { return data; }

private:
	DEFINE_MEMBER_FN(impl_ctor, BSFixedString *, 0x00A511C0, const char * buf);
	DEFINE_MEMBER_FN(impl_ctor_copy, BSFixedString *, 0x00A50D50, const BSFixedString & rhs);
	DEFINE_MEMBER_FN(impl_Release, void, 0x00A511B0);

protected:
	DEFINE_MEMBER_FN(impl_Set, BSFixedString *, 0x00A51210, const char * buf);
	DEFINE_MEMBER_FN(impl_Set_copy, BSFixedString *, 0x00A51280, const BSFixedString & rhs);

	const char	* data;
};


// BSFixedStringCaseInsensitive ?
class BSFixedStringCI : public BSFixedString
{
public:
//	BSFixedStringCI() {}
//	BSFixedStringCI(const BSFixedStringCI &rhs) : BSFixedString((const BSFixedString&)rhs) { }
//	BSFixedStringCI(const char * str);				// TESV.0043BA00
//
//	BSFixedString& operator=(const BSFixedString& rhs);
//	BSFixedString& operator=(BSFixedString&& rhs);
//	BSFixedString& operator=(const char* rhs);
//
	bool operator==(const char* str) const;
	bool operator!=(const char* str) const { return !(*this == str); }
//	bool operator==(const BSFixedStringCI& rhs) const { return data == rhs.data; }
//	bool operator!=(const BSFixedStringCI& rhs) const { return data != rhs.data; }
//
//protected:
//	DEFINE_MEMBER_FN(ctor, BSFixedStringCI *, 0x0043BA00, const char * buf);
};
