#pragma once

#include <cstdint>

#include "platform/Platform.h"

#ifdef R3D_OS_WINDOWS
#	ifdef R3D_CORE_DLL
#		define R3D_API __declspec(dllexport)
#	else
#		define R3D_API __declspec(dllimport)
#	endif
#	define R3D_ALIGN_16 __declspec(align(16))
#else
#	define R3D_API
#	define R3D_ALIGN_16
#endif

using R3Dfloat = float;
using R3Ddouble = double;

using R3Dbyte = std::int8_t;
using R3Dubyte = std::uint8_t;
using R3Dchar = std::uint8_t;

using R3Dshort = std::int16_t;
using R3Dushort = std::uint16_t;

using R3Dint = std::int32_t;
using R3Duint = std::uint32_t;

using R3Dlong = std::int64_t;
using R3Dulong = std::uint64_t;