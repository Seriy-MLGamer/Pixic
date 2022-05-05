#pragma once

#include <Pixic/core/classes/typedefs/Property.h>
#include <Pixic/core library/C OOP.h>

#include <Pixic/core/classes/variable/Arithmetical.h>

struct Property
{
	Object;

	Arithmetical value;
	Hash hash;
	Property *prev, *next;
};