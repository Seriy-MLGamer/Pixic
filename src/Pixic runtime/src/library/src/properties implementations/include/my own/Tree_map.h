#pragma once

#include <typedefs/my own/Tree_map.h>
#include <Map.h>

#include <typedefs/my own/system/Property_block.h>

struct Tree_map
{
	Map;

	Property_block *zero, *one;
};
Tree_map Tree_map_new();
void Tree_map_set(Tree_map *self, const char *key, char *value);
char *Tree_map_get(Tree_map *self, const char *key);
void Tree_map_unset(Tree_map *self, const char *key);
void Tree_map_show(Tree_map *self);
void Tree_map_remove(Tree_map *self);