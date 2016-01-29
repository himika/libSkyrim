#pragma once

#include "../BSCore/BSTArray.h"
#include "../BSCore/BSTList.h"
#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSTEvent.h"
#include "../Forms/FormTypes.h"
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
		BSSimpleList<TESFile*>	modInfoList;			// 00
		UInt32					loadedModCount;			// 08
		TESFile					* loadedMods[0xFF];		// 0C
	};

	const TESFile* LookupModByName(const char* modName);
	UInt8 GetModIndex(const char* modName);

	DEFINE_MEMBER_FN(GetNextID, FormID, 0x0043B6D0);
	DEFINE_MEMBER_FN(IsGeneratedID, bool, 0x0043B790, FormID formID);		// { return (formID >= 0xFF000000); } 
	DEFINE_MEMBER_FN(HotLoadPlugin, void, 0x00443810, const char *name);

	// @members
	UInt32							unk004;
	BSTArray<TESForm*>				persistanceForms;	// 08 - PapyrusPersistenceForm(formid=028A), CommandingActorPersistenceForm(0294)
	UnkFormArray					unk014;				// 14
	UnkFormArray					unk020;
	UnkFormArray					unk02C;
	BSTArray<BGSKeyword*>			keywords;
	BSTArray<BGSLocationRefType*>	locRefTypes;
	BSTArray<BGSAction*>			actions;
	BSTArray<BGSTextureSet*>		textureSets;
	BSTArray<BGSMenuIcon*>			menuIcons;
	BSTArray<TESGlobal*>			globals;
	BSTArray<TESClass*>				classes;
	BSTArray<TESFaction*>			factions;
	BSTArray<BGSHeadPart*>			headParts;
	BSTArray<TESEyes*>				eyes;
	BSTArray<TESRace*>				races;
	BSTArray<TESSound*>				sounds;
	BSTArray<BGSAcousticSpace*>		acousticSpaces;
	UnkFormArray					unkSkills;
	BSTArray<EffectSetting*>		magicEffects;
	BSTArray<Script*>				scripts;
	BSTArray<TESLandTexture*>		landTextures;
	BSTArray<EnchantmentItem*>		enchantments;
	BSTArray<SpellItem*>			spellItems;
	BSTArray<ScrollItem*>			scrolls;
	BSTArray<TESObjectACTI*>		activators;
	BSTArray<BGSTalkingActivator*>	talkingActivators;
	BSTArray<TESObjectARMO*>		armors;
	BSTArray<TESObjectBOOK*>		books;
	BSTArray<TESObjectCONT*>		containers;
	BSTArray<TESObjectDOOR*>		doors;
	BSTArray<IngredientItem*>		ingredients;
	BSTArray<TESObjectLIGH*>		lights;
	BSTArray<TESObjectMISC*>		miscObjects;
	BSTArray<BGSApparatus*>			apparatuses;
	BSTArray<TESObjectSTAT*>		statics;
	BSTArray<BGSStaticCollection*>	staticCollections;
	BSTArray<BGSMovableStatic*>		movableStatics;
	BSTArray<TESGrass*>				grasses;
	BSTArray<TESObjectTREE*>		trees;
	BSTArray<TESFlora*>				flora;
	BSTArray<TESFurniture*>			furniture;
	BSTArray<TESObjectWEAP*>		weapons;
	BSTArray<TESAmmo*>				ammo;
	BSTArray<TESNPC*>				npcs;
	BSTArray<TESLevCharacter*>		levCharacters;
	BSTArray<TESKey*>				keys;
	BSTArray<AlchemyItem*>			potions;
	BSTArray<BGSIdleMarker*>		idleMarkers;
	BSTArray<BGSNote*>				notes;
	BSTArray<BGSConstructibleObject*> constructibles;
	BSTArray<BGSProjectile*>		projectiles;
	BSTArray<BGSHazard*>			bgsHazards;
	BSTArray<TESSoulGem*>			soulGems;
	BSTArray<TESLevItem*>			levItems;
	BSTArray<TESWeather*>			weather;
	BSTArray<TESClimate*>			climates;
	BSTArray<BGSShaderParticleGeometryData*>	shaderParticleGeometryData;
	BSTArray<BGSReferenceEffect*>	referenceEffects;
	BSTArray<TESRegion*>			regions;
	BSTArray<NavMeshInfoMap*>		navMeshInfoMaps;
	BSTArray<TESObjectCELL*>		cells;
	BSTArray<TESObjectREFR*>		refs;
	BSTArray<Character*>			characters;
	BSTArray<MissileProjectile*>	missleProjs;
	BSTArray<ArrowProjectile*>		arrowProjs;
	BSTArray<GrenadeProjectile*>	grenadeProjs;
	BSTArray<BeamProjectile*>		beamProjs;
	BSTArray<FlameProjectile*>		flameProjs;
	BSTArray<ConeProjectile*>		coneProjs;
	BSTArray<BarrierProjectile*>	barrierProjs;
	BSTArray<Hazard*>				hazards;
	BSTArray<TESWorldSpace*>		worldSpaces;
	BSTArray<TESObjectLAND*>		lands;
	BSTArray<NavMesh*>				navMeshes;
	UnkFormArray					unkTLOD;
	BSTArray<TESTopic*>				topics;
	BSTArray<TESTopicInfo*>			topicInfos;
	BSTArray<TESQuest*>				quests;
	BSTArray<TESIdleForm*>			idleForms;
	BSTArray<TESPackage*>			packages;
	BSTArray<TESCombatStyle*>		combatStyles;
	BSTArray<TESLoadScreen*>		loadScreens;
	BSTArray<TESLevSpell*>			levSpells;
	BSTArray<TESObjectANIO*>		anios;
	BSTArray<TESWaterForm*>			waterForms;
	BSTArray<TESEffectShader*>		effectShaders;
	UnkFormArray					unkTOFTs;
	BSTArray<BGSExplosion*>			explosions;
	BSTArray<BGSDebris*>			debris;
	BSTArray<TESImageSpace*>		imageSpaces;
	BSTArray<TESImageSpaceModifier*>	imageSpaceModifiers;
	BSTArray<BGSListForm*>			listForms;
	BSTArray<BGSPerk*>				perks;
	BSTArray<BGSBodyPartData*>		bodyPartData;
	BSTArray<BGSAddonNode*>			addonNodes;
	BSTArray<ActorValueInfo*>		actorValueInfos;
	BSTArray<BGSCameraShot*>		cameraShots;
	BSTArray<BGSCameraPath*>		cameraPaths;
	BSTArray<BGSVoiceType*>			voiceTypes;
	BSTArray<BGSMaterialType*>		materialTypes;
	BSTArray<BGSImpactData*>		impactData;
	BSTArray<BGSImpactDataSet*>		impactDataSets;
	BSTArray<TESObjectARMA*>		armorAddons;
	BSTArray<BGSEncounterZone*>		encounterZones;
	BSTArray<BGSLocation*>			locations;
	BSTArray<BGSMessage*>			messages;
	BSTArray<BGSRagdoll*>			ragdolls;
	UnkFormArray					unkDOBJs;
	BSTArray<BGSLightingTemplate*>	lightingTemplates;
	BSTArray<BGSMusicType*>			musicTypes;
	BSTArray<BGSFootstep*>			footsteps;
	BSTArray<BGSFootstepSet*>		footstepSets;
	BSTArray<BGSStoryManagerBranchNode*>	branchNodes;
	BSTArray<BGSStoryManagerQuestNode*>	questNodes;
	BSTArray<BGSStoryManagerEventNode*>	eventNodes;
	BSTArray<BGSDialogueBranch*>	dialogBranches;
	BSTArray<BGSMusicTrackFormWrapper*>	musicTrackFormWrappers;
	UnkFormArray					unkDLVWs;
	BSTArray<TESWordOfPower*>		wordOfPowers;
	BSTArray<TESShout*>				shouts;
	BSTArray<BGSEquipSlot*>			equipSlots;
	BSTArray<BGSRelationship*>		relationships;
	BSTArray<BGSScene*>				scenes;
	BSTArray<BGSAssociationType*>	associationTypes;
	BSTArray<BGSOutfit*>			outfits;
	BSTArray<BGSArtObject*>			artObjects;
	BSTArray<BGSMaterialObject*>	materialObjects;
	BSTArray<BGSMovementType*>		movementTypes;
	BSTArray<BGSSoundDescriptorForm*>	soundDescriptors;
	BSTArray<BGSDualCastData*>		dualCastData;
	BSTArray<BGSSoundCategory*>		soundCategories;
	BSTArray<BGSSoundOutput*>		soundOutputs;
	BSTArray<BGSCollisionLayer*>	collisonLayers;
	BSTArray<BGSColorForm*>			colors;
	BSTArray<BGSReverbParameters*>	reverbParams;

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
