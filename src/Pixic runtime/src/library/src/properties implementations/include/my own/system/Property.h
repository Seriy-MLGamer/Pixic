#pragma once

#include <typedefs/my own/system/Property.h>

#include <typedefs/my own/system/Property_block.h>

struct Property
{
	char *value;
	Property_block *zero, *one;
};