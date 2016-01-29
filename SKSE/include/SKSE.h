#pragma once

#ifdef _MSC_VER
#  ifndef _LIB
#    if _DEBUG
#      pragma comment(lib, "SKSE_d.lib")
#    else
#      pragma comment(lib, "SKSE.lib")
#    endif
#  endif
#endif

#include <Skyrim.h>
