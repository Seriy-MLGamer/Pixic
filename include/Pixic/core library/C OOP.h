#pragma once

#include "Safe memory.h"

#define class(name) struct name
#define interface(name) struct vtable_##name

#define cast_offset(dest_type, interface) (size_t)&((dest_type *)NULL)->interface
#define vcast(interface) ((void *)(interface)-(*(interface))->cast)

#define new(type, size) safe_malloc(sizeof(type)*(size), #type " @ \"" __FILE__ "\"")
#define clean(object) safe_clean(object)
#define length(object_array) safe_get_size(object_array)*sizeof *(object_array)
#define resize(object_array, new_size) ((object_array)=safe_realloc(object_array, sizeof *(object_array)*(new_size)))
#define delete(object) safe_free(object)