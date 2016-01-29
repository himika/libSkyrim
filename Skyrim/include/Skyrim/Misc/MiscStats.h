#pragma once

class MiscStatManager
{
public:
	// 14
	struct MiscStat
	{
		const char	* name;		// 00
		const char	* unk04;	// 04
		UInt32		value;		// 08
		UInt32		unk0C;		// 0C
		UInt8		unk10;		// 10
		UInt8		pad11[3];	// 11
	};

	class IMiscStatVisitor
	{
	public:
		virtual void Visit(MiscStat * stat, void * stat_unk04, UInt32 stat_unk0C, UInt32 value, UInt32 stat_unk10) = 0;
	};


	/*==============================================================================
	struct MiscStatManager::FindStatByCRC +0000 (_vtbl=0108E954)
	0000: struct MiscStatManager::FindStatByCRC
	0000: |   struct MiscStatManager::IMiscStatVisitor
	==============================================================================*/
	class FindStatByCRC
	{
	public:
		virtual void Visit(MiscStat * stat, void * stat_unk04, UInt32 stat_unk0C, UInt32 value, UInt32 stat_unk10)
		{
			Visit_Internal(stat, stat_unk04, stat_unk0C, value, stat_unk10);
		}

	private:
		DEFINE_MEMBER_FN(Visit_Internal, void, 0x00487F90, MiscStat * stat, void * stat_unk04, UInt32 stat_unk0C, UInt32 value, UInt32 stat_unk10);
	};

	static MiscStatManager *	GetSingleton(void);

	MiscStat *	Get(const char * name);

	DEFINE_MEMBER_FN(Visit, void, 0x00488120, IMiscStatVisitor *& visitor);

	// @members
	MiscStat	* m_stats;	// 00
	UInt32		unk04;		// 04
	UInt32		m_numStats;	// 08

};
