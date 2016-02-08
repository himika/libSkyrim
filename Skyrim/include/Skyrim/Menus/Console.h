#pragma once

#include "IMenu.h"
#include <cstdarg>

class TESObjectREFR;

/*==============================================================================
class Console +0000 (_vtbl=010E3CB4)
0000: class Console
0000: |   class IMenu
0000: |   |   class FxDelegateHandler
0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   |   class GRefCountImplCore
==============================================================================*/
// 34
class Console : public IMenu
{
public:
	// unk0C - 0x0C
	// Flags - 0x807
	// unk14 - 2

	// C+
	struct Unk20
	{
		struct Unk0
		{
			UInt32	unk0;
			UInt32	unk4;
		};

		struct Unk8
		{
			UInt32	unk0;
		};

		Unk0	unk0;	// 0
		Unk8	unk8;	// 8
	};

	virtual ~Console();		// 008472E0

	// @override
	virtual void	Accept(CallbackProcessor * processor) override;

	static RefHandle GetPickedRefHandle();

	static TESObjectREFR * GetPickedReference();

	// @members
	//void	** _vtbl;		// 00 - 010E3CB4
	void	* opcodeInfo;	// 1C - constructor checks that opcodes match
	Unk20	unk20;			// 20 - init'd to 0, probably history linked list?
	UInt32	unk2C;			// 2C - init'd to 0
	UInt8	unk30;			// 30 - init'd to 0

protected:
	static RefHandle & pickedRefHandle;
};


class ConsoleManager
{
public:
	ConsoleManager();
	~ConsoleManager();

	static ConsoleManager * GetSingleton()
	{
		return *((ConsoleManager **)0x01B10B58);
	}

	void Print(const char * fmt, ...)
	{
		va_list	args;
		va_start(args, fmt);
		VPrint(fmt, args);
		va_end(args);
	}

	static bool IsConsoleMode();

	DEFINE_MEMBER_FN(VPrint, void, 0x008486F0, const char *fmt, va_list args);

	void	* scriptContext;	// 00
};
