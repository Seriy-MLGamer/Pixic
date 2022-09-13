/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

This file is part of Pixic runtime.
Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <Pixic/core library/Safe memory.h>

#define new(type) safe_malloc(sizeof(type), #type " @ \"" __FILE__ "\"")
#define new_array(type, size) safe_malloc(sizeof(type)*(size_t)(size), #type " array @ \"" __FILE__ "\"")
#define clean(object) safe_clean(object)
#define length(object_array) (safe_get_size(object_array)/sizeof *(object_array))
#define resize(object_array, new_size) ((object_array)=safe_realloc(object_array, sizeof *(object_array)*(size_t)(new_size)))
#define delete(object) safe_free(object)

#define vtable_class const void *f;