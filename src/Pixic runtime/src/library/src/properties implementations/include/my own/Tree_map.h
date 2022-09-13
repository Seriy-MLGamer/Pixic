/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

This file is part of Pixic runtime.
Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.
*/

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