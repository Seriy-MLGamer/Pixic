#pragma once

#include "stdbool.h"

typedef void *Thread, *Mutex;

extern Thread (*Thread_new)(void (*function)(void *arguments), void *arguments);
extern bool (*Thread_delete)(Thread *self);
extern Mutex (*Mutex_new)();
extern void (*Mutex_lock)(Mutex *self);
extern bool (*Mutex_trylock)(Mutex *self);
extern void (*Mutex_unlock)(Mutex *self);
extern void (*Mutex_delete)(Mutex *self);
extern void (*sleep)(unsigned long milliseconds);