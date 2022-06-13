#pragma once

#include <configuration.h>

#include <stdint.h>

#ifdef X32
	typedef int32_t Int;
#endif
#ifdef X64
	typedef int64_t Int;
#endif