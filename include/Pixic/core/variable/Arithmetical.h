#pragma once

#include <Pixic/core/typedefs/variable/Arithmetical.h>

#include <Pixic/core/variable/Var_null.h>
#include <Pixic/core/variable/Var_int.h>
#include <Pixic/core/variable/Var_float.h>

union Arithmetical
{
	Var_null n;
	Var_int i;
	Var_float f;
};