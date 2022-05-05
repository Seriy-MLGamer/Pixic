#include <something else/module 2/Class_derived.h>

#include <math.h>

float Class_derived_magnitude(Class_derived *self)
{
	return sqrtf(self->x*self->x+self->y*self->y+self->z*self->z);
}
Class_derived Class_derived_dot(Class_derived *self, Class_derived *operand)
{
	return Class_derived_new(
		self->y*operand->z-operand->y*self->z,
		self->z*operand->x-operand->z*self->x,
		self->x*operand->y-operand->x*self->y
	);
}
//Задаём таблицу виртуальных методов.
static const struct Class_derived_f f=
{
	(float (*)(void *))Class_derived_magnitude,
	(Class_derived (*)(void *, Class_derived *))Class_derived_dot
};
Class_derived Class_derived_new(float x, float y, float z)
{
	Class_derived self;
	//Вызов унаследованного конструтора делается так.
	*(Class_base *)&self=Class_base_new(x, y);
	//Добавляем ссылку на таблицу.
	self.f=&f;

	self.z=z;

	return self;
}