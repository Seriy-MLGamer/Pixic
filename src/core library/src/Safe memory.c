#include "Pixic/core library/Safe memory.h"

#include "stdlib.h"
#include "string.h"
#include "Pixic/core library/threads.h"

typedef struct Memory_block Memory_block;
struct Memory_block
{
	const char *name;
	size_t size;
	Memory_block *prev, *next;
};

size_t memory_allocated;
size_t max_memory_allocated;
Memory_data *not_freed;
size_t not_freed_size;
static Memory_block *last_block;
static Mutex memory_mutex;

bool safe_memory_init()
{
	memory_allocated=0;
	max_memory_allocated=0;
	last_block=NULL;
	memory_mutex=Mutex_new();
	if (!memory_mutex) return false;
	return true;
}
void *safe_malloc(size_t size, const char *name)
{
	Memory_block *result=malloc(sizeof(Memory_block)+size);
	if (!result) return NULL;
	result->name=name;
	result->size=size;
	result->next=NULL;
	Mutex_lock(memory_mutex);
	result->prev=last_block;
	if (last_block) last_block->next=result;
	last_block=result;
	memory_allocated+=size;
	if (memory_allocated>max_memory_allocated) max_memory_allocated=memory_allocated;
	Mutex_unlock(memory_mutex);
	return (void *)result+sizeof(Memory_block);
}
void safe_clean(void *data)
{
	Memory_block *block=data-sizeof(Memory_block);
	memset(data, 0, block->size);
}
size_t safe_get_size(void *data)
{
	Memory_block *block=data-sizeof(Memory_block);
	return block->size;
}
void *safe_realloc(void *data, size_t new_size)
{
	Memory_block
		*result=data-sizeof(Memory_block),
		*prev=result->prev,
		*next=result->next;
	size_t size=result->size;
	Mutex_lock(memory_mutex);
	result=realloc(result, sizeof(Memory_block)+new_size);
	if (!result)
	{
		if (next)
		{
			next->prev=prev;
			if (prev) prev->next=next;
		}
		else
		{
			if (prev) prev->next=NULL;
			last_block=prev;
		}
		memory_allocated-=size;
		Mutex_unlock(memory_mutex);
		return NULL;
	}
	memory_allocated+=new_size-result->size;
	if (memory_allocated>max_memory_allocated) max_memory_allocated=memory_allocated;
	if (next)
	{
		next->prev=result;
		Mutex_unlock(memory_mutex);
		if (prev) prev->next=result;
		result->size=new_size;
	}
	else
	{
		if (prev) prev->next=result;
		last_block=result;
		result->size=new_size;
		Mutex_unlock(memory_mutex);
	}
	return (void *)result+sizeof(Memory_block);
}
void safe_free(void *data)
{
	Memory_block *block=data-sizeof(Memory_block);
	Mutex_lock(memory_mutex);
	if (block->next)
	{
		block->next->prev=block->prev;
		if (block->prev) block->prev->next=block->next;
	}
	else
	{
		if (block->prev) block->prev->next=NULL;
		last_block=block->prev;
	}
	memory_allocated-=block->size;
	Mutex_unlock(memory_mutex);
	free(block);
}
void safe_memory_deinit(bool not_freed_list)
{
	if (not_freed_list)
	{
		not_freed=malloc(1);
		not_freed_size=0;
		Memory_block *a=last_block; while (a)
		{
			not_freed=realloc(not_freed, sizeof(Memory_data)*(not_freed_size+1));
			not_freed[not_freed_size].name=a->name;
			not_freed[not_freed_size].size=a->size;
			not_freed_size++;
			Memory_block *prev=a->prev;
			free(a);
			a=prev;
		}
	}
	else
	{
		Memory_block *a=last_block; while (a)
		{
			Memory_block *prev=a->prev;
			free(a);
			a=prev;
		}
	}
	Mutex_delete(memory_mutex);
}