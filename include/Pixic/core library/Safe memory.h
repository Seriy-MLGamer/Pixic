/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

This file is part of Pixic runtime.
Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct Memory_data Memory_data;
struct Memory_data
{
	const char *name;
	size_t size;
};

extern size_t memory_allocated;
extern size_t max_memory_allocated;
extern Memory_data *not_freed;
extern size_t not_freed_size;

int safe_memory_init();
void safe_memory_deinit(bool not_freed_list);
void *safe_malloc(size_t size, const char *name);
size_t safe_get_size(void *data);
void
	safe_clean(void *data),
	*safe_realloc(void *data, size_t new_size),
	safe_free(void *data);