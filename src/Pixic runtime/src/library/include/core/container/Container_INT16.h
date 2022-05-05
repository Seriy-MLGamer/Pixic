#pragma once

#include <core/typedefs/container/Container_INT16.h>
#include <core/container/Container.h>

struct Container_INT16
{
	Container;
	
	short *array;
};
void Container_INT16_set_element(Container_INT16 *self, Int x, Int y, Var *value);
Arithmetical Container_INT16_get_element(Container_INT16 *self, Int x, Int y);
void Container_INT16_clean(Container_INT16 *self, Var *value);

Container_INT16 Container_INT16_new(Int width, Int height, unsigned long flags);