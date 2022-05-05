#pragma once

#include <core/typedefs/container/Container_INT8.h>
#include <core/container/Container.h>

struct Container_INT8
{
	Container;

	char *array;
};
void Container_INT8_set_element(Container_INT8 *self, Int x, Int y, Var *value);
Arithmetical Container_INT8_get_element(Container_INT8 *self, Int x, Int y);
void Container_INT8_clean(Container_INT8 *self, Var *value);

Container_INT8 Container_INT8_new(Int width, Int height, unsigned long flags);