#pragma once

#include <typedefs/Map.h>
#include <Pixic/core library/C OOP.h>

struct Map
{
	Object;
};
struct Map_f
{
	void (*set)(void *self, const char *key, char *value);
	char *(*get)(void *self, const char *key);
	void (*unset)(void *self, const char *key);
	void (*show)(void *self);
	void (*remove)(void *self);
};