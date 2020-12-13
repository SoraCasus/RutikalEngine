#pragma once


#ifdef _WIN32
#	ifdef _WIN64
#		define R3D_OS_WINDOWS
#	else
#		error "x86 Builds are not supported!"
#	endif
#elif defined(__APPLE__) || defined(__MACH__)
#	include <TargetConditionals.h>
#	if TARGET_IPHONE_SIMULATOR == 1
#		error "IOS simulator is not supported!"
#	elif TARGET_OS_IPHONE == 1
#		define R3D_OS_IOS
#		error "IOS is not supported!"
#	elif TARGET_OS_MAC == 1
#		define R3D_OS_MACOS
#		error "MacOS is not supported!"
#	else
#		error "Unknown Apple platform!"
#	endif
#elif defined(__ANDROID__)
#	define R3D_OS_ANDROID
#	error "Android is not supported!"
#elif defined(__linux__)
#	define R3D_OS_LINUX
#	error "Linux is not supported!"
#else
#	define R3D_OS_UNKNOWN
#	error "Unknown platform!"
#endif
