#pragma once

#include "BaseFormComponent.h"

class BGSKeyword;

// 0C
class BGSKeywordForm : public BaseFormComponent
{
public:
	virtual ~BGSKeywordForm();										// 0044B3C0

	// @override
	virtual void	Init(void) override;							// 006C50E0 { return; }
	virtual void	ReleaseRefs(void) override;						// 0044B400
	virtual void	CopyFromBase(BaseFormComponent * rhs) override;	// 0044B410

	// @add
	virtual bool	HasKeyword(BGSKeyword* keyword) const;			// 0044B1E0
	virtual UInt32	GetDefaultKeyword(void);						// 005EADD0 (void) { return 0; }

	bool HasKeyword(FormID formID) const;

	bool GetKeywordAt(UInt32 idx, BGSKeyword *& keyword) const {
		return (idx < numKeywords) ? (keyword = keywords[idx], true) : false;
	}

	inline UInt32 GetSize() const {
		return numKeywords;
	}

private:
	BGSKeyword	** keywords;	// 04
	UInt32		numKeywords;	// 08
};
