#pragma once

#include <Pixic/core/typedefs/container/Containers.h>

#include <Pixic/core/container/Container_INT8.h>
#include <Pixic/core/container/Container_INT16.h>
#include <Pixic/core/container/Container_INT32.h>
#ifdef X64
#include <Pixic/core/container/Container_INT64.h>
#endif
#include <Pixic/core/container/Container_FLOAT32.h>
#ifdef X64
#include <Pixic/core/container/Container_FLOAT64.h>
#endif

union Containers
{
	Container_INT8 int8;
	Container_INT16 int16;
	Container_INT32 int32;
	#ifdef X64
	Container_INT64 int64;
	#endif
};