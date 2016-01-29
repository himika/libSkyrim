#pragma once

#include "NiTypes.h"
#include "NiObject.h"
#include "../BSCore/BSFixedString.h"

class BSFaceGenModel;


/*==============================================================================
class NiExtraData +0000 (_vtbl=011189AC)
0000: class NiExtraData
0000: |   class NiObject
0000: |   |   class NiRefObject
==============================================================================*/
class NiExtraData : public NiObject
{
public:
	enum { kRTTI = 0x01B91074 };

	NiExtraData();
	~NiExtraData();												// 00AC29D0

	// @override
	virtual void	LoadBinary(NiStream * stream);				// 14 00AC2810
	virtual void	LinkObject(NiStream * stream);				// 15 00AC2830 { return; }
	virtual bool	RegisterStreamables(NiStream * stream);		// 16 00AC2840
	virtual void	SaveBinary(NiStream * stream);				// 17 00AC2870

	// @add
	virtual bool	Unk_21(void);								// 21 00AC27C0 { return true; }
	virtual bool	Unk_22(void);								// 22 00AC27B0 { return true; }

	const BSFixedString& GetName() const;
	void SetName(const BSFixedString& name);

	// @members
	BSFixedString	m_pcName;	// 08
};

// 10
class NiStringExtraData : public NiExtraData
{
public:
	NiStringExtraData();
	~NiStringExtraData();

	char	* m_pString;	// 0C
};

// 10
class NiIntegerExtraData : public NiExtraData
{
public:
	NiIntegerExtraData();
	~NiIntegerExtraData();

	SInt32 m_data;	// 0C
};

// 14
class NiBinaryExtraData : public NiExtraData
{
public:
	NiBinaryExtraData();
	~NiBinaryExtraData();

	char		* m_data;	// 0C
	UInt32		m_size;		// 10
};

// 14
class NiFloatsExtraData : public NiExtraData
{
public:
	NiFloatsExtraData();
	~NiFloatsExtraData();

	UInt32	m_size;		// 0C
	float	* m_data;	// 10
};

// 14
class NiIntegersExtraData : public NiExtraData
{
public:
	NiIntegersExtraData();
	~NiIntegersExtraData();

	UInt32	m_size;		// 0C
	SInt32	* m_data;	// 10
};

// 14
class NiStringsExtraData : public NiExtraData
{
public:
	NiStringsExtraData();
	~NiStringsExtraData();

	UInt32	m_size;		// 0C
	char	** m_data;	// 10
};

// 1C
class NiVectorExtraData : public NiExtraData
{
public:
	NiVectorExtraData();
	~NiVectorExtraData();

	float m_vector[4];
};


// 30
class BSFaceGenModelExtraData : public NiExtraData
{
public:
	BSFaceGenModel* m_model;
	BSFixedString bones[8];
	
};
STATIC_ASSERT(sizeof(BSFaceGenModelExtraData) == 0x30);
