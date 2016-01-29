#pragma once

#include "NiTypes.h"
#include "NiNode.h"
#include "../BSCore/BSFixedString.h"

class NiBoneNames
{
public:
	static NiBoneNames * GetSingleton(void);

	BSFixedString	root;	// 00
	BSFixedString	npc;	// 04
	BSFixedString	head;	// 08
	BSFixedString	pelvis;	// 0C
	BSFixedString	spine0;	// 10
	BSFixedString	spine1;	// 14
	BSFixedString	spine2;	// 18
	BSFixedString	lFoot;	// 1C
	BSFixedString	rFoot;	// 20
	BSFixedString	lCalf;	// 24
	BSFixedString	rCalf;	// 28
	BSFixedString	specialIdleCast;		// 2C
	BSFixedString	specialIdleAreaEffect;	// 30
	BSFixedString	attachSound;			// 34
	BSFixedString	soundMarker;			// 38
	BSFixedString	skinnedDecalNode;		// 3C
	BSFixedString	decalNode;				// 40
	BSFixedString	modelSwapNode;			// 44
	BSFixedString	open;	// 48
	BSFixedString	close;	// 4C
	BSFixedString	dvpg;	// 50
	BSFixedString	prn;	// 54
	BSFixedString	weapon;	// 58
	BSFixedString	weaponSword;	// 5C
	BSFixedString	weaponDagger;	// 60
	BSFixedString	weaponAxe;		// 64
	BSFixedString	weaponMace;		// 68
	BSFixedString	shield;			// 6C
	BSFixedString	weaponBack;		// 70
	BSFixedString	weaponBow;		// 74
	BSFixedString	quiver;			// 78
	BSFixedString	editorMarker;	// 7C	
	BSFixedString	editorMarker0;	// 80
	BSFixedString	editorMarker1;	// 84
	BSFixedString	editorMarker2;	// 88
	BSFixedString	arrowQuiver;	// 8C
	BSFixedString	markerSource;	// 90
	BSFixedString	markerTarget;	// 94
	BSFixedString	attachLight;	// 98
	BSFixedString	skin;			// 9C
	BSFixedString	faceGenEars;	// A0
	BSFixedString	unequip;		// A4
	BSFixedString	laserSight;		// A8
	BSFixedString	aimSight;		// AC
	BSFixedString	decal;			// B0
	BSFixedString	permanentDecal;	// B4
	BSFixedString	grabLeft;		// B8
	BSFixedString	grabRight;		// BC
	BSFixedString	arrow0;			// C0
	BSFixedString	arrowBone;		// C4
	BSFixedString	faceGenNiNodeSkinned;	// C8
	BSFixedString	entryPoint;		// CC
	BSFixedString	lUpperArm;		// D0
	BSFixedString	lForearm;		// D4
	BSFixedString	rUpperArm;		// D8
	BSFixedString	lookNode;		// DC
	BSFixedString	tail1;			// E0
	BSFixedString	tailHub;		// E4
	BSFixedString	npcPelvis;		// E8
	BSFixedString	talking;		// EC
	BSFixedString	camera1st;		// F0
	BSFixedString	camera3rd;		// F4
	BSFixedString	headMeshForExport;	// F8
	BSFixedString	pinnedLimb;		// FC
	BSFixedString	backpack;		// 100
	BSFixedString	projectileNode;	// 104
	BSFixedString	blastRadiusNode;	// 108
	BSFixedString	torchFire;		// 10C
	BSFixedString	lightOn;		// 110
	BSFixedString	npcCom;			// 114
	BSFixedString	skinAttachment;	// 118
	BSFixedString	npcNeck;		// 11C
	BSFixedString	nifRound;		// 120
	BSFixedString	scb;			// 124
	BSFixedString	upperBody;		// 128
	BSFixedString	lightOff;		// 12C
	BSFixedString	headMagicNode;	// 130
	BSFixedString	lMagicNode;		// 134
	BSFixedString	rMagicNode;		// 138
	BSFixedString	magicLeft;		// 13C
	BSFixedString	magicRight;		// 140
	BSFixedString	magicOther;		// 144
	BSFixedString	cameraControl;	// 148
	BSFixedString	npcRoot;		// 14C
	BSFixedString	saddleBone;		// 150
	BSFixedString	perchFireNode;	// 154
	BSFixedString	animationGraphVariables[101];
};

class NiWeaponNodes
{
public:
	enum
	{
		kTypeWeapon1 = 0,
		kTypeWeaponSword,
		kTypeWeaponDagger,
		kTypeWeaponAxe,
		kTypeWeaponMace,
		kTypeWeaponBack1,
		kTypeWeaponBack2,
		kTypeWeaponBow1,
		kTypeWeapon2,
		kTypeWeaponBow2,
		kTypeUnknown,
		kNumTypes
	};

	static NiWeaponNodes * GetSingleton(void);

	BSFixedString	nodes[kNumTypes];
};

typedef NiBoneNames * (* _GetBoneNames)(void);
extern const _GetBoneNames GetBoneNames;

typedef NiAVObject * (* _GetNodeByName)(NiNode * parent, BSFixedString nodeName, UInt8 unk1);
extern const _GetNodeByName GetNodeByName;

typedef BSFixedString (* _GetNodeNameByWeaponType)(UInt32 weaponType);
extern const _GetNodeNameByWeaponType GetNodeNameByWeaponType;

typedef BSFixedString (* _GetInternalNode)(UInt32 type, UInt8 unk1);
extern const _GetInternalNode GetInternalNode;

typedef UInt8 (* _SwapNodeParent)(NiNode * skeleton, BSFixedString sourceNode, BSFixedString destNode, UInt8 unk1);
extern const _SwapNodeParent SwapNodeParent;