#include <module 1/something/Class_base.h>

#include <math.h>

float Class_base_magnitude(Class_base *self)
{
	return sqrtf(self->x*self->x+self->y*self->y);
}
//Задаём таблицу виртуальных методов.
static const struct Class_base_f f=
{
	(float (*)(void *))Class_base_magnitude
};
Class_base Class_base_new(float x, float y)
{
	Class_base self;
	//Добавляем ссылку на таблицу.
	self.f=&f;

	self.x=x;
	self.y=y;

	return self;
}