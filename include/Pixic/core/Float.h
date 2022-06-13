#pragma once

#include <configuration.h>

#ifdef X32
	typedef float Float;
#endif
#ifdef X64
	typedef double Float;
#endif