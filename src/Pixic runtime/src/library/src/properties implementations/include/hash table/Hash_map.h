/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

This file is part of Pixic runtime.
Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <typedefs/hash table/Hash_map.h>
#include <Map.h>

#include <typedefs/hash table/system/Pair.h>
#include <hash table/system/hash.h>

struct Hash_map
{
	Map;

	Pair **pairs;
	size_t pair_count;
};
Hash_map Hash_map_new();
void Hash_map_set(Hash_map *self, const char *key, char *value);
void Hash_map_set2(Hash_map *self, Hash key, char *value);
char *Hash_map_get(Hash_map *self, const char *key);
char *Hash_map_get2(Hash_map *self, Hash key);
void Hash_map_unset(Hash_map *self, const char *key);
void Hash_map_unset2(Hash_map *self, Hash key);
void Hash_map_show(Hash_map *self);
void Hash_map_remove(Hash_map *self);