#pragma once

#include <typedefs/hash table/Hash_map.h>
#include <Map.h>

#include <typedefs/hash table/system/Pair.h>

struct Hash_map
{
	Map;

	Pair **pairs;
	size_t pair_count;
};
Hash_map Hash_map_new();
void Hash_map_set(Hash_map *self, const char *key, char *value);
char *Hash_map_get(Hash_map *self, const char *key);
void Hash_map_unset(Hash_map *self, const char *key);
void Hash_map_show(Hash_map *self);
void Hash_map_remove(Hash_map *self);