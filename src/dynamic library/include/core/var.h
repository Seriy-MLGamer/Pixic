#pragma once

#include "Pixic/core/var.h"

long var_to_long(var* self);
float var_to_float(var* self);
long long var_to_long_long(var* self);
double var_to_double(var* self);
#ifdef x32
	#define var_to_INT var_to_long;
	#define var_to_FLOAT var_to_float;
#endif
#ifdef x64
	#define var_to_INT var_to_long_long;
	#define var_to_FLOAT var_to_double;
#endif