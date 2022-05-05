#pragma once

#include <Pixic/core/typedefs/container/Container_data.h>
#include <Pixic/core library/C OOP.h>

#include <Pixic/core/typedefs/container/Property.h>

struct Container_data
{
	Object;

	Property *last_property;
	void *hidden_data;
};