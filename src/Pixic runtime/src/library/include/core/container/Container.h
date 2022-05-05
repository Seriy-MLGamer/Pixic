#pragma once

#include <core/typedefs/container/Container.h>
#include <Pixic/core library/C OOP.h>

#include <Pixic/core/typedefs/variable/Var.h>
#include <Pixic/core/typedefs/variable/Arithmetical.h>
#include <core/typedefs/Color.h>
#include <core/typedefs/container/Container_ID.h>
#include <core/typedefs/container/Container_data.h>

struct Container
{
	Object;

	Int	width, height;
	unsigned long flags;
	Color key_color;
	Container_ID alpha;
	Container_data *optional;
};
struct Container_f
{
	void (*set_element)(void *self, Int x, Int y, Var *value);
	Arithmetical (*get_element)(void *self, Int x, Int y);
	void (*clean)(void *self, Var *value);
};
inline Container Container_new(Int width, Int height, unsigned long flags)
{
	Container self;

	self.width=width;
	self.height=height;
	self.flags=flags;
	self.key_color=0;
	self.alpha=-1;
	self.optional=NULL;

	return self;
}