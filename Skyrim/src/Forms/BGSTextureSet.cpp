#include "Skyrim.h"
#include "Skyrim/Forms/BGSTextureSet.h"
#include "Skyrim/Memory.h"

BSShaderTextureSet * BSShaderTextureSet::Create()
{
	BSShaderTextureSet * textureSet = (BSShaderTextureSet*)FormHeap_Allocate(sizeof(BSShaderTextureSet));
	textureSet->ctor();
	return textureSet;
}
