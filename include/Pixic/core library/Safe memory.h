#pragma once

#include "stddef.h"
#include "stdbool.h"

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

bool safe_memory_init();
void *safe_malloc(size_t size, const char *name);
void safe_clean(void *data);
size_t safe_get_size(void *data);
void *safe_realloc(void *data, size_t new_size);
void safe_free(void *data);
void safe_memory_deinit(bool not_freed_list);