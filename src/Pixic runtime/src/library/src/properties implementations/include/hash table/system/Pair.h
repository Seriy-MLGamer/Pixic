#pragma once

#include <typedefs/hash table/system/Pair.h>

#include <hash table/system/hash.h>

struct Pair
{
	Hash hash;
	const char *key;
	char *value;
	Pair *prev, *next;
};