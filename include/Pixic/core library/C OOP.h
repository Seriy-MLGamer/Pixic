#pragma once

#include <Pixic/core library/Safe memory.h>

#define new(type) ((type *)safe_malloc(sizeof(type), #type " @ \"" __FILE__ "\""))
#define new_array(type, size) ((type *)safe_malloc(sizeof(type)*(size), #type " array @ \"" __FILE__ "\""))
#define clean(object) safe_clean(object)
#define length(object_array) (safe_get_size(object_array)/sizeof *(object_array))
#define resize(object_array, new_size) (*(void **)&(object_array)=safe_realloc(object_array, sizeof *(object_array)*(new_size)))
#define delete(object) safe_free(object)

/**
 * abstract class Object;
 * A base class for all other objects.
 */
typedef struct Object Object;
struct Object
{
	const void *f;
};