#pragma once

#include "../BSCore/BSFixedString.h"
#include "../BSCore/BSTArray.h"
#include "../BSCore/BSSpinLock.h"
#include "../BSSystem/BSTSmartPointer.h"
#include "BSAnimationGraphChannel.h"


BSSmartPointer(BSAnimationGraphManager);


struct AnimationVariableData
{
	union Data
	{
		bool	b;
		SInt32	i;
		float	f;
	};

	BSFixedString	name;		// 00
	Data			* data;		// 04
};


class UnkClass_011250F0
{
public:
	virtual ~UnkClass_011250F0();

	DEFINE_MEMBER_FN(SendEvent, bool, 0x00BAE3D0, const BSFixedString &eventName);
};


// 60
class BSAnimationGraphManager : public BSIntrusiveRefCounted
{
public:
	virtual ~BSAnimationGraphManager();			// 00BA9270

	virtual UInt32	Unk_01(UInt32 arg);			// 00BA78C0

	template <class Ty>
	struct Param
	{
		BSFixedString	name;
		Ty				value;
		bool			flag;
	};

	DEFINE_MEMBER_FN(SetBool, void, 0x0064FEE0, Param<bool> *param);
	DEFINE_MEMBER_FN(SetInt, void, 0x0064FFC0, Param<bool> *param);
	DEFINE_MEMBER_FN(SetFloat, void, 0x006500A0, Param<bool> *param);
	DEFINE_MEMBER_FN(SendEvent, bool, 0x00BA7400, const BSFixedString &eventName);

	// @members
	//void								** _vtbl;		// 00 - 01124E90
	//BSIntrusiveRefCounted				count;			// 04
	BSTArray<BSAnimationGraphChannel*>	channels;		// 08
	UInt32								unk14[3];		// 14
	BSTSmallArray<UnkClass_011250F0*>	unk20;			// 20
	UInt32								unk2C[3];		// 2C
	BSTArray<AnimationVariableData*>	unk38;			// 38
	void								* unk44;		// 44
	void								* unk48;		// 48
	BSSpinLock							lock;			// 4C

private:
	DEFINE_MEMBER_FN(ctor, BSAnimationGraphManager*, 0x00BA7B60);
	DEFINE_MEMBER_FN(ctor2, BSAnimationGraphManager*, 0x00BA7BE0, UInt32 arg1, UInt32 arg2);
	DEFINE_MEMBER_FN(dtor, void, 0x00BA8920);
};
