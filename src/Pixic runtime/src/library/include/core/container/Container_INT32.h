#pragma once

#include <core/typedefs/container/Container_INT32.h>
#include <core/container/Container.h>

struct Container_INT32
{
	Container;
	
	long *array;
};
void Container_INT32_set_element(Container_INT32 *self, Int x, Int y, Var *value);
Arithmetical Container_INT32_get_element(Container_INT32 *self, Int x, Int y);
void Container_INT32_clean(Container_INT32 *self, Var *value);

Container_INT32 Container_INT32_new(Int width, Int height, unsigned long flags);