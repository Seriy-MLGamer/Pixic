/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

This file is part of Pixic runtime.
Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <core/Color.h>
#include <core/Container_ID.h>
#include <system/C OOP.h>
#include <Pixic/core/Var.h>

typedef enum Container_type Container_type;
enum Container_type
{
	INT8,
	INT16,
	INT32,
	#ifdef X64
	INT64,
	#endif
	FLOAT32,
	#ifdef X64
	FLOAT64,
	#endif

	type_count
};
/**
 * Pixi-containers are universal 2D arrays that also can have properties, animation, etc.
 */
typedef struct Container Container;
struct Container
{
	Container_type type;
	union
	{
		int8_t *int8;
		int16_t *int16;
		int32_t *int32;
		#ifdef X64
		int64_t *int64;
		#endif
		float *float32;
		#ifdef X64
		double *float64;
		#endif
	};
	Int width, height;
	uint32_t flags;
	Color key_color;
	Container_ID alpha;
};
inline Container Container_new(Int width, Int height, Container_type type)
{
	Container self;

	self.type=type;
	switch (type)
	{
		case INT8:
			self.int8=new_array(int8_t, width*height);
			break;
		case INT16:
			self.int16=new_array(int16_t, width*height);
			break;
		case INT32:
			self.int32=new_array(int32_t, width*height);
			break;
		#ifdef X64
		case INT64:
			self.int64=new_array(int64_t, width*height);
			break;
		#endif
		case FLOAT32:
			self.float32=new_array(float, width*height);
		#ifdef X64
			break;
		case FLOAT64:
			self.float64=new_array(double, width*height);
		#endif
	}
	self.width=width;
	self.height=height;
	self.flags=0;
	self.key_color=0;
	self.alpha=0;

	return self;
}
inline void Container_remove(Container *self)
{
	delete(self->int8);
}
inline void Container_set(Container *self, Int x, Int y, Var *value)
{
	Int index=x+y*self->width;
	if (index>=0&&index<self->width*self->height) switch (self->type)
	{
		case INT8:
			self->int8[index]=Var_to_int(value);
			break;
		case INT16:
			self->int16[index]=Var_to_int(value);
			break;
		case INT32:
			self->int32[index]=Var_to_int(value);
			break;
		#ifdef X64
		case INT64:
			self->int64[index]=Var_to_int(value);
			break;
		#endif
		case FLOAT32:
			self->float32[index]=Var_to_float(value);
		#ifdef X64
			break;
		case FLOAT64:
			self->float64[index]=Var_to_float(value);
		#endif
	}
}
inline Var Container_get(Container *self, Int x, Int y)
{
	Int index=x+y*self->width;
	if (index>=0&&index<self->width*self->height) switch (self->type)
	{
		case INT8: return Var_new2(self->int8[index]);
		case INT16: return Var_new2(self->int16[index]);
		case INT32: return Var_new2(self->int32[index]);
		#ifdef X64
		case INT64: return Var_new2(self->int64[index]);
		#endif
		case FLOAT32: return Var_new3(self->float32[index]);
		#ifdef X64
		case FLOAT64: return Var_new3(self->float64[index]);
		#endif
	}
}