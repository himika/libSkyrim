#pragma once

#ifdef _MSC_VER
#  ifndef _LIB
#    if _DEBUG
#      pragma comment(lib, "Skyrim_d.lib")
#    else
#      pragma comment(lib, "Skyrim.lib")
#    endif
#  endif
// 4018 - signed/unsigned mismatch
// 4244 - loss of data by assignment
// 4267 - possible loss of data (truncation)
// 4305 - truncation by assignment
// 4288 - disable warning for crap microsoft extension screwing up the scope of variables defined in for loops
// 4311 - pointer truncation
// 4312 - pointer extension
#  pragma warning(disable: 4018 4244 4267 4305)
#endif

#include "Skyrim/Macros.h"
#include "Skyrim/BSCore/BSCoreTypes.h"
