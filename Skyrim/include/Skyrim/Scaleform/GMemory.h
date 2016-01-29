#pragma once

#include "GStats.h"

class GSysAllocPaged;
class GHeapMemVisitor;
class GHeapSegVisitor;
class GStatBag;

struct GMemAddressStub { };
typedef GMemAddressStub* GMemAddressPtr;

#define GALLOC(s,id)                    GMemory::Alloc((s))
#define GMEMALIGN(s,a,id)               GMemory::Alloc((s),(a))
#define GREALLOC(p,s,id)                GMemory::Realloc((p),(s))
#define GFREE(p)                        GMemory::Free((p))
#define GFREE_ALIGN(s)                  GMemory::Free((s))

#define GHEAP_ALLOC(heap,s,id)          GMemory::AllocInHeap((heap),(s))
#define GHEAP_MEMALIGN(heap,s,a,id)     GMemory::AllocInHeap((heap),(s),(a))
#define GHEAP_AUTO_ALLOC(addr,s)        GMemory::AllocAutoHeap((addr),(s))
#define GHEAP_AUTO_ALLOC_ID(addr,s,id)  GMemory::AllocAutoHeap((addr),(s))
#define GHEAP_FREE(heap, p)             GMemory::Free((p))

#define GFC_MEMORY_REDEFINE_NEW(class_name, StatType)															\
	void* operator new(std::size_t sz)																			\
	{ void *p = GALLOC(sz, StatType); return p; }																\
	void* operator new(std::size_t sz, GMemoryHeap* heap)														\
	{ void *p = GHEAP_ALLOC(heap, sz, StatType); return p; }													\
	void* operator new(std::size_t sz, GMemoryHeap* heap, int blocktype)										\
	{ GUNUSED(blocktype); void *p = GHEAP_ALLOC(heap, sz, blocktype); return p; }								\
	void* operator new(std::size_t sz, GMemAddressPtr adr)														\
	{ void *p = GMemory::AllocAutoHeap(adr, sz, GAllocDebugInfo(StatType,__FILE__,__LINE__)); return p; }		\
	void* operator new(std::size_t sz, const char* pfilename, int line)											\
	{ void* p = GMemory::Alloc(sz, GAllocDebugInfo(StatType, pfilename, line)); return p; }						\
	void* operator new(std::size_t sz, GMemoryHeap* heap, const char* pfilename, int line)						\
	{ void* p = GMemory::AllocInHeap(heap, sz, GAllocDebugInfo(StatType, pfilename, line)); return p; }			\
	void* operator new(std::size_t sz, GMemAddressPtr adr, const char* pfilename, int line)						\
	{ void* p = GMemory::AllocAutoHeap(adr, sz, GAllocDebugInfo(StatType, pfilename, line)); return p; }		\
	void* operator new(std::size_t sz, int blocktype, const char* pfilename, int line)							\
	{ void* p = GMemory::Alloc(sz, GAllocDebugInfo(blocktype, pfilename, line)); return p; }					\
	void* operator new(std::size_t sz, GMemoryHeap* heap, int blocktype, const char* pfilename, int line)		\
	{ void* p = GMemory::AllocInHeap(heap, sz, GAllocDebugInfo(blocktype, pfilename, line)); return p; }		\
	void* operator new(std::size_t sz, GMemAddressPtr adr, int blocktype, const char* pfilename, int line)		\
	{ void* p = GMemory::AllocAutoHeap(adr, sz, GAllocDebugInfo(blocktype, pfilename, line)); return p; }		\
	void operator delete(void *p)																				\
	{ GFREE(p); }																								\
	void operator delete(void *p, const char*, int)																\
	{ GFREE(p); }																								\
	void operator delete(void *p, int, const char*, int)														\
	{ GFREE(p); }																								\
	void operator delete(void *p, GMemoryHeap*)																	\
	{ GFREE(p); }																								\
	void operator delete(void *p, GMemoryHeap*, int)															\
	{ GFREE(p); }																								\
	void operator delete(void *p, GMemoryHeap*, const char*, int)												\
	{ GFREE(p); }																								\
	void operator delete(void *p, GMemoryHeap*, int,const char*,int)											\
	{ GFREE(p); }																								\
	void operator delete(void *p, GMemAddressPtr)																\
	{ GFREE(p); }																								\
	void operator delete(void *p, GMemAddressPtr, int)															\
	{ GFREE(p); }																								\
	void operator delete(void *p, GMemAddressPtr, const char*, int)												\
	{ GFREE(p); }																								\
	void operator delete(void *p, GMemAddressPtr,int,const char*,int)											\
	{ GFREE(p); }																								\

struct GAllocDebugInfo
{
	UInt32	StatId;

	GAllocDebugInfo() : StatId(GStat_Default_Mem)
	{
	}
	GAllocDebugInfo(UInt32 statId, const char*, UInt32) : StatId(statId)
	{
	}
	GAllocDebugInfo(const GAllocDebugInfo& src) : StatId(src.StatId)
	{
	}
};


class GMemoryHeap
{
public:
	enum MemReportType
	{
		MemReportBrief,
		MemReportSummary,
		MemReportMedium,
		MemReportFull,
		MemReportSimple,
		MemReportSimpleBrief,
		MemReportFileSummary,
		MemReportHeapsOnly
	};

	enum HeapFlags
	{
		Heap_ThreadUnsafe = 0x0001,
		Heap_FastTinyBlocks = 0x0002,
		Heap_FixedGranularity = 0x0004,
		Heap_Root = 0x0008,
		Heap_NoDebugInfo = 0x0010,
		Heap_UserDebug = 0x1000
	};

	enum RootHeapParameters
	{
		RootHeap_MinAlign = 16,
		RootHeap_Granularity = 16 * 1024,
		RootHeap_Reserve = 16 * 1024,
		RootHeap_Threshold = 256 * 1024,
		RootHeap_Limit = 0
	};

	struct HeapDesc
	{
		unsigned	Flags;
		UInt32		MinAlign;
		UInt32		Granularity;
		UInt32		Reserve;
		UInt32		Threshold;
		UInt32		Limit;
		UInt32		HeapId;
		UInt32		Arena;

		HeapDesc(unsigned  flags = 0,
			UInt32 minAlign = 16,
			UInt32 granularity = 8 * 1024,
			UInt32 reserve = 8 * 1024,
			UInt32 threshold = ~UInt32(0),
			UInt32 limit = 0,
			UInt32 heapId = 0,
			UInt32 arena = 0)
			: Flags(flags), MinAlign(minAlign),
			Granularity(granularity), Reserve(reserve),
			Threshold(threshold), Limit(limit),
			HeapId(heapId), Arena(arena)
		{
		}

		void Clear()
		{
			Flags = 0;
			Granularity = 0;
			MinAlign = 16;
			Reserve = 0;
			Threshold = ~UInt32(0);
			Limit = 0;
			HeapId = 0;
			Arena = 0;
		}
	};

	struct LimitHandler
	{
		virtual ~LimitHandler() {}
		virtual bool OnExceedLimit(GMemoryHeap* heap, UInt32 overLimit) = 0;
		virtual void OnFreeSegment(GMemoryHeap* heap, UInt32 freeingSize) = 0;
	};

	struct HeapTracer
	{
		virtual ~HeapTracer() {}
		virtual void OnCreateHeap(const GMemoryHeap* heap) = 0;
		virtual void OnDestroyHeap(const GMemoryHeap* heap) = 0;
		virtual void OnAlloc(const GMemoryHeap* heap, UInt32 size, UInt32 align, unsigned sid, const void* ptr) = 0;
		virtual void OnRealloc(const GMemoryHeap* heap, const void* oldPtr, UInt32 newSize, const void* newPtr) = 0;
		virtual void OnFree(const GMemoryHeap* heap, const void* ptr) = 0;
	};

	struct RootStats
	{
		UInt32 SysMemFootprint;
		UInt32 SysMemUsedSpace;
		UInt32 PageMapFootprint;
		UInt32 PageMapUsedSpace;
		UInt32 BookkeepingFootprint;
		UInt32 BookkeepingUsedSpace;
		UInt32 DebugInfoFootprint;
		UInt32 DebugInfoUsedSpace;
		UInt32 UserDebugFootprint;
		UInt32 UserDebugUsedSpace;
	};

protected:
	GMemoryHeap();

	virtual ~GMemoryHeap() {}																		// 00 00F7B080

public:
	virtual void	CreateArena(UInt32 arena, GSysAllocPaged* sysAlloc) = 0;						// 01 004D43E0
	virtual void	DestroyArena(UInt32 arena) = 0;													// 02 00588F30
	virtual bool	ArenaIsEmpty(UInt32 arena) = 0;													// 03 00C8CCA0
	virtual GMemoryHeap * CreateHeap(const char* name, const HeapDesc& desc) = 0;					// 04 00F7B3F0
	virtual void	SetLimitHandler(LimitHandler* handler) = 0;										// 05 00F7B110
	virtual void	SetLimit(UInt32 newLimit) = 0;													// 06 00F7B140
	virtual void	AddRef() = 0;																	// 07 00F7B180
	virtual void	Release() = 0;																	// 08 00F7B520
	virtual void *	AllocDbg(UInt32 size, UInt32 align, const GAllocDebugInfo* info) = 0;			// 09 00F7B210
	virtual void *	Alloc(UInt32 size, UInt32 align) = 0;											// 0A 00F7B1B0
	virtual void *	Realloc(void* oldPtr, UInt32 newSize) = 0;										// 0B 00F7BB10
	virtual void	Free(void* ptr) = 0;															// 0C 00F7BA10

	virtual void *	AllocAutoHeap(const void *thisPtr, UInt32 size) = 0;
	virtual void *	AllocAutoHeap(const void *thisPtr, UInt32 size, UInt32 align) = 0;
	virtual GMemoryHeap *	GetAllocHeap(const void *thisPtr) = 0;
	virtual UInt32	GetUsableSize(const void* ptr) = 0;
	virtual void *	AllocSysDirect(UInt32 size) = 0;
	virtual void	FreeSysDirect(void* ptr, UInt32 size) = 0;
	virtual bool	GetStats(GStatBag* bag) = 0;
	virtual UInt32	GetFootprint() const = 0;
	virtual UInt32	GetTotalFootprint() const = 0;
	virtual UInt32	GetUsedSpace() const = 0;
	virtual UInt32	GetTotalUsedSpace() const = 0;
	virtual void	GetRootStats(RootStats* stats) = 0;
	virtual void	VisitMem(GHeapMemVisitor* visitor, unsigned flags) = 0;
	virtual void	VisitRootSegments(GHeapSegVisitor* visitor) = 0;
	virtual void	VisitHeapSegments(GHeapSegVisitor* visitor) const = 0;
	virtual void	SetTracer(HeapTracer* tracer) = 0;

protected:
	virtual void	destroyItself() = 0;
	virtual void	ultimateCheck() = 0;
	virtual void	releaseCachedMem() = 0;
	virtual bool	dumpMemoryLeaks() = 0;
	virtual void	checkIntegrity() const = 0;
	virtual void	getUserDebugStats(RootStats* stats) const = 0;
};



class GMemory
{
public:
	static GMemoryHeap *&	pGlobalHeap;

	static void *	Alloc(std::size_t size)												{ return pGlobalHeap->Alloc(size, 0); }
	static void *	Alloc(std::size_t size, std::size_t align)							{ return pGlobalHeap->Alloc(size, align); }

	static void *	AllocAutoHeap(const void *p, std::size_t size)						{ return pGlobalHeap->AllocAutoHeap(p, size); }
	static void *	AllocAutoHeap(const void *p, std::size_t size, std::size_t align)	{ return pGlobalHeap->AllocAutoHeap(p, size, align); }

	static void *	AllocInHeap(GMemoryHeap* heap, std::size_t size)					{ return heap->Alloc(size, 0); }
	static void *	AllocInHeap(GMemoryHeap* heap, std::size_t size, std::size_t align)	{ return heap->Alloc(size, align); }


	static void *	Realloc(void *p, std::size_t newSize)								{ return pGlobalHeap->Realloc(p, newSize); }

	static void		Free(void *p)														{ return pGlobalHeap->Free(p); }

	static GMemoryHeap *	GetHeapByAddress(const void* p)								{ return pGlobalHeap->GetAllocHeap(p); }
};

template<int Stat>
class GNewOverrideBase
{
public:
	enum { StatType = Stat };

	GFC_MEMORY_REDEFINE_NEW(GNewOverrideBase, Stat)
};
