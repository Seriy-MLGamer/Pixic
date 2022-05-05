#pragma once

#include <Pixic/core/typedefs/container/Container_INT64.h>
#include <Pixic/core/container/Container.h>

struct Container_INT64
{
	Container;
	
	long long *array;
};