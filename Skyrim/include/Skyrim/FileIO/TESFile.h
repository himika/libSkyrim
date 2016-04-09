#pragma once

#include "../BSCore/BSTList.h"
#include "../BSCore/BSTArray.h"
#include "../BSCore/BSString.h"
#include "../NetImmerse/NiTPointerMap.h"

class TESRegionList;
class BSFile;


class TESFile
{
public:
	TESFile();
	~TESFile();

	struct FormRecordData
	{
		UInt8		typeID;		// corresponds to FormType::XXX
		UInt32		typeCode;	// i.e. 'GMST', 'FACT'
		UInt32		unk08;		// only seen zero
	};

	struct ChunkHeader
	{
		UInt32	type;	// i.e. 'XGRD', 'DATA'
		UInt16	size;
	};

	// 18 info about currently loading form
	struct FormInfo
	{
		UInt32		recordType;			// 00 i.e. 'FACT', 'GMST'
		UInt32		unk04;				// 04 looks like size of entire record
		UInt32		formFlags;			// 08 copied to TESForm->flags
		FormID		formID;				// 0C 
		UInt32		unk10;				// 10
		UInt16		unk14;				// 14 always initialized to 0F on SaveForm. 
		UInt16		unk16;				// 16
	};

	static const TESFile * LookupByName(const char *name);

	bool IsLoaded() const { return true; }
	bool HasMaster(const TESFile* file) const;
	bool HasMaster(const char* modName) const;

	UInt8 GetModIndex() const {
		return modIndex;
	}

	const char * GetAuthor() const {
		return (const char*)author;
	}
	const char * GetDescription() const {
		return (const char*)description;
	}

	TESFile * Duplicate(UInt32 a_cacheSize = 0x10000) {
		return Duplicate_Impl(a_cacheSize);
	}

	DEFINE_MEMBER_FN(ReadData,					void,	0x00445340,	UInt32 numValues, UInt32 valueSize);
	DEFINE_MEMBER_FN(GetCurrentSubRecordType,	UInt32,	0x00445B70);
	DEFINE_MEMBER_FN(GetFormType,				UInt8,	0x00445E30);
	DEFINE_MEMBER_FN(ReadFile,					void,	0x00446130,	const char *filePath, const char *fileName, UInt32 arg3, UInt32 arg4);
	DEFINE_MEMBER_FN(Seek,						bool,	0x00446DA0,	UInt32 offset);

	static inline UInt8 GetFormTypeFromRecordType(UInt32 recordType) {
		return ((UInt8(*)(UInt32))0x004509E0)(recordType);
	}

	// @members
	BSSimpleList<UInt32>				unkList;			// 000
	NiTPointerMap<UInt32, TESFile *>	* pointerMap;		// 008 - NiTPointerMap<ThreadID, *> - ctor 00445150 - called from 00446FE0
	void								* unk00C;			// 00C
	BSFile								* unkFile;			// 010
	UInt32								unk014;				// 014 
	void								* unk018;			// 018 seen all zeroes. size unknown
	void								* unk01C;			// 01C as above
	char								name[0x104];		// 020
	char								filepath[0x104];	// 124 - "Data\"
	UInt32								unk228;				// 228
	UInt32								cacheSize;			// 22C - init'd to dword_F469CC (0x2800) same val as BSFile+10?
	UInt32								unk230;				// 230
	UInt32								unk234;				// 234
	UInt32								unk238;				// 238
	UInt32								unk23C;				// 23C
	FormInfo							formInfo;			// 240
	ChunkHeader							subRecord;			// 258
	UInt32								fileSize;			// 260
	UInt32								fileOffset;			// 264
	UInt32								dataOffset;			// 268 index into dataBuf
	UInt32								subrecordBytesRead;	// 26C generates error on Read if != expected length
	UInt32								unk268[(0x298 - 0x270) >> 2];	// 270
	UInt8								unk298;				// 298
	bool								bIsBigEndian;		// 299
	UInt8								unk29A;				// 29A
	UInt8								pad29B;				// 29B
	UInt32								fileData[0x50];		// 29C - WIN32_FIND_DATA
	float								unk3DC;				// 3DC - init'd to 0.94
	UInt32								unk3E0;				// 3E0
	UInt32								flags;				// 3E4 - init'd to 0x00000800. 4000 and 40000 do stuff
	UInt8								unk3E8;				// 3E8
	UInt8								pad3E9[3];
	UInt32								unk3EC;				// 3EC
	UInt32								unk3F0;				// 3F0
	UInt32								unk3F4;				// 3F4
	UInt32								unk3F8;				// 3F8
	UInt32								numRefMods;			// 3FC related to modindex; see 004472D0
															//     formIDs in mod are as saved in GECK, must fix up at runtime
	TESFile								** refModInfo;		// 400 used to look up modInfo based on fixed mod index, double-check
	UInt32								unk404;				// 404
	UInt32								unk408;				// 408
	UInt8								modIndex;			// 40C init to 0xFF
	UInt8								pad40D[3];
	BSString							author;				// 410
	BSString							description;		// 418
	void								* dataBuf;			// 420 
	UInt32								unk424;				// 424 looks like size of entire record
	UInt8								unk428;				// 428
	UInt8								pad429[3];			// 429
	UInt32								unk42C;				// 42C
	BSTArray<void *>					* unk430;			// 430

private:
	DEFINE_MEMBER_FN(ctor, TESFile *, 0x00446A00, const char *a_filepath, const char *a_name, UInt32 a_cacheSize, UInt32 arg4, TESFile *arg5);

	DEFINE_MEMBER_FN(Duplicate_Impl, TESFile *, 0x004472D0, UInt32 a_cacheSize);
	DEFINE_MEMBER_FN(Duplicate2_Impl, TESFile *, 0x00446EC0, UInt32 a_threadID, UInt32 a_cacheSize);
};
STATIC_ASSERT(offsetof(TESFile, refModInfo) == 0x400);
STATIC_ASSERT(sizeof(TESFile) == 0x434);
