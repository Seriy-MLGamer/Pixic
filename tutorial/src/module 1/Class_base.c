#include <module 1/Class_base>

#include "math.h"
#include <module 1/Interface1>
#include <module 1/Interface2>

//Задаём таблицы виртуальных методов.
static const struct vtable_Interface1 vtable_Interface1={cast_offset(Class_base, Interface1)};

float Class_base_magnitude(Class_base *self)
{
	return sqrtf(self->x*self->x+self->y*self->y);
}
static const struct vtable_Interface2 vtable_Interface2=
{
	cast_offset(Class_base, Interface2),

	(float (*)(Interface2 *))Class_base_magnitude
};

Class_base Class_base_new(float x, float y)
{
	Class_base self;
	//Добавляем ссылки на таблицы.
	self.Interface1=&vtable_Interface1;
	self.Interface2=&vtable_Interface2;

	self.x=x;
	self.y=y;

	return self;
}