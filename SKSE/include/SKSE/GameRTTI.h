#pragma once

#include <Skyrim.h>
#include <Skyrim/RTTI.h>

const TYPE_INFO* GetObjectTypeInfo(const void * objBase);
const char* GetObjectClassName(const void * objBase);
void DumpObjectClassHierarchy(const void * objBase, bool verbose=false);
