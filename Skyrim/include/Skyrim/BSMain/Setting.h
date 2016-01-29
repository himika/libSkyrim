#pragma once

#include "../NetImmerse/NiTMap.h"

/*==============================================================================
class Setting +0000 (_vtbl=01077224)
0000: class Setting
==============================================================================*/
// C
class Setting
{
public:
	virtual ~Setting();					// 00402870

	virtual bool	Unk_01(void);		// 00AF43F0 { return false; }

	enum
	{
		kType_Unknown = 0,
		kType_Integer,
		kType_Float,
		kType_String,
		kType_Bool,
		kType_ID6,	// need to find an example of this
		kType_ID,
	};

	union Data
	{
		UInt32	u32;
		SInt32	s32;
		float	f32;
		UInt8	u8;		// used for bool
		char	* s;
	};

	// @members
	//void	** _vtbl;	// 00 - 01077224
	Data	data;		// 04
	char	* name;		// 08

	UInt32	GetType(void) const;

	bool	GetDouble(double * out) const;
	bool	SetDouble(double value);

	bool	SetString(const char * value);
};


/*==============================================================================
class SettingCollection<class Setting> +0000 (_vtbl=01077230)
0000: class SettingCollection<class Setting>
==============================================================================*/
template <class T>
class SettingCollection
{
public:
	virtual ~SettingCollection();			// 00402BB0

	virtual void	Unk_01(void) = 0;		// 00F51EE8 (pure)
	virtual void	Unk_02(void) = 0;		// 00F51EE8 (pure)
	virtual void	Unk_03(void) = 0;		// 00F51EE8 (pure)
	virtual void	Unk_04(void) = 0;		// 00F51EE8 (pure)
	virtual bool	Unk_05(UInt32 arg);		// 004091A0 { return false; }
	virtual bool	Unk_06(void);			// 009B86F0 { return true; }
	virtual void	Unk_07(void);			// 004028A0 { return this->unk108 != 0; }
	virtual void	Unk_08(void);			// 004028A0 { return this->unk108 != 0; }

};



/*==============================================================================
class SettingCollectionMap<class Setting> +0000 (_vtbl=010772D8)
0000: class SettingCollectionMap<class Setting>
0000: |   class SettingCollection<class Setting>
==============================================================================*/
template <class T>
class SettingCollectionMap : public SettingCollection<T>
{
public:
	virtual ~SettingCollectionMap();			// 00403800

	virtual void	Unk_01(void) override;		// 00403780
	virtual void	Unk_02(void) override;		// 00403550
	virtual void	Unk_07(void) override;		// 00403580
	virtual void	Unk_08(void) override;		// 00403610
};



/*==============================================================================
class GameSettingCollection +0000 (_vtbl=01077388)
0000: class GameSettingCollection
0000: |   class SettingCollectionMap<class Setting>
0000: |   |   class SettingCollection<class Setting>
==============================================================================*/
// 120
class GameSettingCollection : public SettingCollectionMap<Setting>
{
public:
	// @override
	virtual void	Unk_03(void) override;			// 004091A0 (UInt32 arg) { return false; }
	virtual void	Unk_04(void) override;			// 0048B960
	virtual bool	Unk_05(UInt32 arg) override;	// 0048B940
	virtual bool	Unk_06(void) override;			// 0048B950

	// @add
	virtual void	Unk_09(void);					// 0048BA10

	Setting *	Get(const char * name);

	// @members
	//void	** _vtbl;							// 000 - 01077388
	UInt32	pad004[(0x10C - 0x004) / 4];
	NiTMap <char const *, Setting *>	items;	// 10C - actually BSTCaseInsensitiveStringMap but that only changes the virtual functions
};


/*==============================================================================
class SettingCollectionList<class Setting> +0000 (_vtbl=0107A5D0)
0000: class SettingCollectionList<class Setting>
0000: |   class SettingCollection<class Setting>
==============================================================================*/
// 114
template <class T>
class SettingCollectionList : public SettingCollection<T>
{
public:
	virtual ~SettingCollectionList();			// 00437030

	virtual void	Unk_01(void) override;		// 0042CEB0
	virtual void	Unk_02(void) override;		// 0042CE90
	virtual void	Unk_07(void) override;		// 0042CF80
	virtual void	Unk_08(void) override;		// 0042CFC0
};


/*==============================================================================
class INISettingCollection +0000 (_vtbl=0107A64C)
0000: class INISettingCollection
0000: |   class SettingCollectionList<class Setting>
0000: |   |   class SettingCollection<class Setting>
==============================================================================*/
class INISettingCollection : public SettingCollectionList<class Setting>
{
public:
	virtual void	Unk_03(void) override;				// 00AFEB50
	virtual void	Unk_04(void) override;				// 00AFED60
	virtual bool	Unk_05(UInt32 arg) override;		// 00AFF0C0
	virtual bool	Unk_06(void) override;				// 00AFF0D0

	struct Entry
	{
		Setting	* setting;
		Entry	* next;
	};

	//void	** _vtbl;						// 000
	UInt32	pad004[(0x10C - 0x004) / 4];
	Entry	items;							// 10C

	Setting	*	Get(const char * name);

private:
	DEFINE_MEMBER_FN(Get_Internal, bool, 0x005263E0, const char * name, Setting ** out);
};



/*==============================================================================
class SettingT<class GameSettingCollection> +0000 (_vtbl=010773B4)
0000: class SettingT<class GameSettingCollection>
0000: |   class Setting
==============================================================================*/
template <template <class> class T>
class SettingT : public T<Setting>
{
public:
};



Setting * GetINISetting(const char * name);

extern INISettingCollection		*& g_iniSettingCollection;
extern INISettingCollection		*& g_iniPrefSettingCollection;
extern GameSettingCollection	*& g_gameSettingCollection;

extern const float	* g_mapLocalHeight;
extern const float	* g_localMapMinFrustumWidth;
