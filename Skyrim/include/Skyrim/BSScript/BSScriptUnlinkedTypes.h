#pragma once

// c:_skyrim\code\tesv\bsscript\BSScriptUnlinkedTypes.h

#include "../BSCore/BSTHashMap.h"

class VMState;

namespace BSScript
{
	// 04
	class UnlinkedTypesBase
	{
		virtual ~UnlinkedTypesBase();									// 00C55630

		virtual UnlinkedTypesBase *	Create(void) = 0;					// 00F51EE8
		virtual void				SetLoader(void *a_loader) = 0;		// 00F51EE8
		virtual bool				Link(const BSFixedString &) = 0;	// 00F51EE8

		// @members
		//void	** _vtbl;		// 00 - 0114A888
	};


	// 48
	class UnlinkedTypes : public UnlinkedTypesBase
	{
	public:
		typedef BSTHashMap<BSFixedString, BSScriptClass *> ClassMap;

		UnlinkedTypes(void *a_unk08, ClassMap *a_unk44);					// 00C67100
		virtual ~UnlinkedTypes();											// 00C69F80

		virtual UnlinkedTypesBase *	Create(void);							// 00C67160
		virtual void				SetLoader(void *a_loader);				// 00C69D70 { loader = a_loader; }
		virtual bool				Link(const BSFixedString & className);	// 00C692E0 "Error: Cannot link class "%s" without a loader"

		// @members
		//void							** _vtbl;	// 00 - 0114D2D0
		VMState							 * state;	// 04 - init'd 0
		void							* unk08;	// 08 -          01B33510
		void							* loader;	// 0C -          01B334F0
		UInt8							unk10;		// 10 - init'd 0
		UInt8							pad11[3];	// 11
		BSScrapArray<BSFixedString>		unk14;		// 14
		BSScrapArray<BSFixedString>		unk24;		// 24
		BSScrapArray<BSFixedString>		unk34;		// 34
		ClassMap						* unk44;	// 44 -          &VMState::linkedClassMap
	};
	STATIC_ASSERT(sizeof(UnlinkedTypes) == 0x48);
}
