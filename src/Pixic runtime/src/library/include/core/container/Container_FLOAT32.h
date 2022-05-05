#pragma once

#include <core/typedefs/container/Container_FLOAT32.h>
#include <core/container/Container.h>

struct Container_FLOAT32
{
	Container;
	
	float *array;
};
void Container_FLOAT32_set_element(Container_FLOAT32 *self, Int x, Int y, Var *value);
Arithmetical Container_FLOAT32_get_element(Container_FLOAT32 *self, Int x, Int y);
void Container_FLOAT32_clean(Container_FLOAT32 *self, Var *value);

Container_FLOAT32 Container_FLOAT32_new(Int width, Int height, unsigned long flags);