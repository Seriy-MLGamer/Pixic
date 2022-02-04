#pragma once

#include "stdbool.h"

typedef void* thread_t;
typedef void* mutex_t;

thread_t thread_create(void (*function)(void* arguments), void* arguments);
bool thread_destroy(thread_t thread);
mutex_t mutex_create();
void mutex_lock(mutex_t mutex);
bool mutex_trylock(mutex_t mutex);
void mutex_unlock(mutex_t mutex);
void mutex_destroy(mutex_t mutex);
void sleep(unsigned long milliseconds);