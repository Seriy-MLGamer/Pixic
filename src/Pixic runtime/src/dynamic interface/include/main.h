#pragma once

#include <configuration.h>

#ifdef OS_WINDOWS
#include <libloaderapi.h>

HMODULE library;
#endif
#ifdef OS_LINUX
#include <dlfcn.h>

void *library;
#endif