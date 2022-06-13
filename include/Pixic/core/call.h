#pragma once

#include <stdarg.h>
#include <Pixic/core/Var.h>

#define get_argument(dest, number)\
{\
	va_start(arguments, argument_count);\
	for (unsigned a=0; a<(number); a++) va_arg(arguments, Var);\
	(dest)=va_arg(arguments, Var);\
	va_end(arguments);\
}