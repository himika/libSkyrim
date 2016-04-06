#pragma once

#include "../BSCore/BSTArray.h"
#include "../BSCore/BSTList.h"
#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSTEvent.h"
#include "../FormComponents/FormTypes.h"
#include "../NetImmerse/NiTArray.h"

class TESFile;
class TESRegionList;


struct TESDataHandlerPostBuildFileListEvent
{
	// this is constructed in stack memory and not enabled on startup.
	// see .text 0069D2A2 - 0069D2B6
	static BSTEventSource<TESDataHandlerPostBuildFileListEvent> *& eventSource;
};


class TESDataHandler : public BSTSingletonSDM<TESDataHandler>
{
public:
	typedef BSTArray<TESForm*>	UnkFormArray;

	struct ModList
	{
		BSSimpleList<TESFile *>	modInfoList;			// 00
		UInt32					loadedModCount;			// 08
		TESFile					* loadedMods[0xFF];		// 0C
	};

	const TESFile* LookupModByName(const char* modName);
	UInt8 GetModIndex(const char* modName);

	DEFINE_MEMBER_FN(GetNextID, FormID, 0x0043B6D0);
	DEFINE_MEMBER_FN(IsGeneratedID, bool, 0x0043B790, FormID formID);		// { return (formID >= 0xFF000000); } 
	DEFINE_MEMBER_FN(HotLoadPlugin, void, 0x00443810, const char *name);

	// @members
	UInt32							unk004;				// 004
	BSTArray<TESForm*>				persistanceForms;	// 008 - PapyrusPersistenceForm(formid=028A), CommandingActorPersistenceForm(0294)
	UnkFormArray					unk014;				// 014
	UnkFormArray					unk020;				// 020
	UnkFormArray					unk02C;				// 02C
	BSTArray<BGSKeyword*>			keywords;			// 038
	BSTArray<BGSLocationRefType*>	locRefTypes;		// 044
	BSTArray<BGSAction*>			actions;			// 050
	BSTArray<BGSTextureSet*>		textureSets;		// 05C
	BSTArray<BGSMenuIcon*>			menuIcons;			// 068
	BSTArray<TESGlobal*>			globals;			// 074
	BSTArray<TESClass*>				classes;			// 080
	BSTArray<TESFaction*>			factions;			// 08C
	BSTArray<BGSHeadPart*>			headParts;			// 098
	BSTArray<TESEyes*>				eyes;				// 0A4
	BSTArray<TESRace*>				races;				// 0B0
	BSTArray<TESSound*>				sounds;				// 0BC
	BSTArray<BGSAcousticSpace*>		acousticSpaces;		// 0C8
	UnkFormArray					unkSkills;			// 0D4
	BSTArray<EffectSetting*>		magicEffects;		// 0E0
	BSTArray<Script*>				scripts;			// 0EC
	BSTArray<TESLandTexture*>		landTextures;		// 0F8
	BSTArray<EnchantmentItem*>		enchantments;		// 104
	BSTArray<SpellItem*>			spellItems;			// 110
	BSTArray<ScrollItem*>			scrolls;			// 11C
	BSTArray<TESObjectACTI*>		activators;			// 128
	BSTArray<BGSTalkingActivator*>	talkingActivators;	// 134
	BSTArray<TESObjectARMO*>		armors;				// 140
	BSTArray<TESObjectBOOK*>		books;				// 14C
	BSTArray<TESObjectCONT*>		containers;			// 158
	BSTArray<TESObjectDOOR*>		doors;				// 164
	BSTArray<IngredientItem*>		ingredients;		// 170
	BSTArray<TESObjectLIGH*>		lights;				// 17C
	BSTArray<TESObjectMISC*>		miscObjects;		// 188
	BSTArray<BGSApparatus*>			apparatuses;		// 194
	BSTArray<TESObjectSTAT*>		statics;			// 1A0
	BSTArray<BGSStaticCollection*>	staticCollections;	// 1AC
	BSTArray<BGSMovableStatic*>		movableStatics;		// 1B8
	BSTArray<TESGrass*>				grasses;			// 1C4
	BSTArray<TESObjectTREE*>		trees;				// 1D0
	BSTArray<TESFlora*>				flora;				// 1DC
	BSTArray<TESFurniture*>			furniture;			// 1E8
	BSTArray<TESObjectWEAP*>		weapons;			// 1F4
	BSTArray<TESAmmo*>				ammo;				// 200
	BSTArray<TESNPC*>				npcs;				// 20C
	BSTArray<TESLevCharacter*>		levCharacters;		// 218
	BSTArray<TESKey*>				keys;				// 224
	BSTArray<AlchemyItem*>			potions;			// 230
	BSTArray<BGSIdleMarker*>		idleMarkers;		// 23C
	BSTArray<BGSNote*>				notes;				// 248
	BSTArray<BGSConstructibleObject*> constructibles;	// 254
	BSTArray<BGSProjectile*>		projectiles;		// 260
	BSTArray<BGSHazard*>			bgsHazards;			// 26C
	BSTArray<TESSoulGem*>			soulGems;			// 278
	BSTArray<TESLevItem*>			levItems;			// 284
	BSTArray<TESWeather*>			weather;			// 290
	BSTArray<TESClimate*>			climates;			// 29C
	BSTArray<BGSShaderParticleGeometryData*>	shaderParticleGeometryData;		// 2A8
	BSTArray<BGSReferenceEffect*>	referenceEffects;	// 2B4
	BSTArray<TESRegion*>			regions;			// 2C0
	BSTArray<NavMeshInfoMap*>		navMeshInfoMaps;	// 
	BSTArray<TESObjectCELL*>		cells;				// 
	BSTArray<TESObjectREFR*>		refs;				// 
	BSTArray<Character*>			characters;			// 
	BSTArray<MissileProjectile*>	missleProjs;		// 
	BSTArray<ArrowProjectile*>		arrowProjs;			// 
	BSTArray<GrenadeProjectile*>	grenadeProjs;		// 
	BSTArray<BeamProjectile*>		beamProjs;			// 
	BSTArray<FlameProjectile*>		flameProjs;			// 
	BSTArray<ConeProjectile*>		coneProjs;			// 
	BSTArray<BarrierProjectile*>	barrierProjs;		// 
	BSTArray<Hazard*>				hazards;			// 
	BSTArray<TESWorldSpace*>		worldSpaces;		// 
	BSTArray<TESObjectLAND*>		lands;				// 
	BSTArray<NavMesh*>				navMeshes;			// 
	UnkFormArray					unkTLOD;			// 
	BSTArray<TESTopic*>				topics;				// 
	BSTArray<TESTopicInfo*>			topicInfos;			// 
	BSTArray<TESQuest*>				quests;				// 
	BSTArray<TESIdleForm*>			idleForms;			// 
	BSTArray<TESPackage*>			packages;			// 
	BSTArray<TESCombatStyle*>		combatStyles;		// 
	BSTArray<TESLoadScreen*>		loadScreens;		// 
	BSTArray<TESLevSpell*>			levSpells;			// 
	BSTArray<TESObjectANIO*>		anios;				// 
	BSTArray<TESWaterForm*>			waterForms;			// 
	BSTArray<TESEffectShader*>		effectShaders;		// 
	UnkFormArray					unkTOFTs;			// 
	BSTArray<BGSExplosion*>			explosions;			// 
	BSTArray<BGSDebris*>			debris;				// 
	BSTArray<TESImageSpace*>		imageSpaces;		// 
	BSTArray<TESImageSpaceModifier*>	imageSpaceModifiers;		// 
	BSTArray<BGSListForm*>			listForms;			// 
	BSTArray<BGSPerk*>				perks;				// 
	BSTArray<BGSBodyPartData*>		bodyPartData;		// 
	BSTArray<BGSAddonNode*>			addonNodes;			// 
	BSTArray<ActorValueInfo*>		actorValueInfos;	// 
	BSTArray<BGSCameraShot*>		cameraShots;		// 
	BSTArray<BGSCameraPath*>		cameraPaths;		// 
	BSTArray<BGSVoiceType*>			voiceTypes;			// 
	BSTArray<BGSMaterialType*>		materialTypes;		// 
	BSTArray<BGSImpactData*>		impactData;			// 
	BSTArray<BGSImpactDataSet*>		impactDataSets;		// 
	BSTArray<TESObjectARMA*>		armorAddons;		// 
	BSTArray<BGSEncounterZone*>		encounterZones;		// 
	BSTArray<BGSLocation*>			locations;			// 
	BSTArray<BGSMessage*>			messages;			// 
	BSTArray<BGSRagdoll*>			ragdolls;			// 
	UnkFormArray					unkDOBJs;			// 
	BSTArray<BGSLightingTemplate*>	lightingTemplates;	// 
	BSTArray<BGSMusicType*>			musicTypes;			// 
	BSTArray<BGSFootstep*>			footsteps;			// 
	BSTArray<BGSFootstepSet*>		footstepSets;		// 
	BSTArray<BGSStoryManagerBranchNode*>	branchNodes;	// 
	BSTArray<BGSStoryManagerQuestNode*>	questNodes;		// 
	BSTArray<BGSStoryManagerEventNode*>	eventNodes;		// 
	BSTArray<BGSDialogueBranch*>	dialogBranches;		// 
	BSTArray<BGSMusicTrackFormWrapper*>	musicTrackFormWrappers;		// 
	UnkFormArray					unkDLVWs;			// 
	BSTArray<TESWordOfPower*>		wordOfPowers;		// 
	BSTArray<TESShout*>				shouts;				// 
	BSTArray<BGSEquipSlot*>			equipSlots;			// 
	BSTArray<BGSRelationship*>		relationships;		// 
	BSTArray<BGSScene*>				scenes;				// 
	BSTArray<BGSAssociationType*>	associationTypes;	// 
	BSTArray<BGSOutfit*>			outfits;			// 
	BSTArray<BGSArtObject*>			artObjects;			// 
	BSTArray<BGSMaterialObject*>	materialObjects;	// 
	BSTArray<BGSMovementType*>		movementTypes;		// 
	BSTArray<BGSSoundDescriptorForm*>	soundDescriptors;		// 
	BSTArray<BGSDualCastData*>		dualCastData;		// 
	BSTArray<BGSSoundCategory*>		soundCategories;	// 
	BSTArray<BGSSoundOutput*>		soundOutputs;		// 
	BSTArray<BGSCollisionLayer*>	collisonLayers;		// 
	BSTArray<BGSColorForm*>			colors;				// 
	BSTArray<BGSReverbParameters*>	reverbParams;		// 

	TESRegionList					* regionList;		// 65C - ctor 0048E4A0

	NiTPrimitiveArray<TESObjectCELL*>	_cells;			// 660
	NiTPrimitiveArray<BGSAddonNode*>	_addonNodes;	// 670

	UInt32							pad680;
	UInt32							pad684;
	UInt32							pad688;
	FormID							nextBlankID;		// 68C - init'd 0x800
	UInt32							pad690;
	ModList							modList;			// 694

	//TESRegionDataManager			* unkAAC;			// AAC

	//static NiFormArray *m_formArray;	// 0x01B10754

private:
	friend struct BSTSingletonSDMBase<BSTSDMTraits<TESDataHandler>>;
	DEFINE_MEMBER_FN(ctor, TESDataHandler*, 0x0043DE50);
};
STATIC_ASSERT(offsetof(TESDataHandler, modList) == 0x694);
