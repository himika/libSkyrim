#pragma once

#include "BSExtraData.h"
#include "../BSCore/BSFixedString.h"

/*==============================================================================
class ExtraEditorID +0000 (_vtbl=01078FA4)
0000: class ExtraEditorID
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraEditorID : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::EditorID };

	ExtraEditorID(const char *str) { ctor(str); }
	virtual ~ExtraEditorID();					// 0040ED50

	// @override
	virtual UInt32	GetType(void) const override;		// 00491870 { return kExtraTypeID; }

	// @members
	BSFixedString editorID;		// 08
private:
	DEFINE_MEMBER_FN(ctor, ExtraEditorID*, 0x0040A2E0, const char *str);
};
