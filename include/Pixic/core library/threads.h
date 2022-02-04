#pragma once

#include "stdbool.h"

typedef void *Thread;
typedef void *Mutex;

Thread Thread_new(void (*function)(void *arguments), void *arguments);
bool Thread_delete(Thread thread);
Mutex Mutex_new();
void Mutex_lock(Mutex mutex);
bool Mutex_trylock(Mutex mutex);
void Mutex_unlock(Mutex mutex);
void Mutex_delete(Mutex mutex);
void sleep(unsigned long milliseconds);