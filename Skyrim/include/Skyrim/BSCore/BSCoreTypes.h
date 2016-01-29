#pragma once

// c:_skyrim\code\tesv\bscore\BSCoreTypes.h

#include <cstddef>
#include <cstdint>

typedef std::uint8_t		UInt8;		//!< An unsigned 8-bit integer value
typedef std::uint16_t		UInt16;		//!< An unsigned 16-bit integer value
typedef std::uint32_t		UInt32;		//!< An unsigned 32-bit integer value
typedef std::uint64_t		UInt64;		//!< An unsigned 64-bit integer value
typedef std::int8_t			SInt8;		//!< A signed 8-bit integer value
typedef std::int16_t		SInt16;		//!< A signed 16-bit integer value
typedef std::int32_t		SInt32;		//!< A signed 32-bit integer value
typedef std::int64_t		SInt64;		//!< A signed 64-bit integer value
typedef float				Float32;	//!< A 32-bit floating point value
typedef double				Float64;	//!< A 64-bit floating point value

typedef UInt32 FormID;
typedef UInt32 RefHandle;
typedef UInt32 VMTypeID;
typedef UInt64 VMHandle;

enum class FormType : UInt8;
enum class ExtraDataType : UInt8;


//"A dynamic cast failed; this would become a static cast and badness in release!"
//"c:\projects\sbailey_buildfarm09\tesv\current\bscore\BSCoreTypes.h"


