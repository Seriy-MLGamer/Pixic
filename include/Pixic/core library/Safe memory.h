#pragma once

#include "stddef.h"
#include "stdbool.h"

typedef struct Memory_data Memory_data;
struct Memory_data
{
	const char *name;
	size_t size;
};

extern size_t *memory_allocated;
extern size_t *max_memory_allocated;
extern Memory_data **not_freed;
extern size_t *not_freed_size;

extern int (*safe_memory_init)();
extern void *(*safe_malloc)(size_t size, const char *name);
extern void (*safe_clean)(void *data);
extern size_t (*safe_get_size)(void *data);
extern void *(*safe_realloc)(void *data, size_t new_size);
extern void (*safe_free)(void *data);
extern void (*safe_memory_deinit)(bool not_freed_list);