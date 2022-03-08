#include <something/module 2/Class_derived>

#include "math.h"
#include <module 1/Interface1>
#include <module 1/Interface2>
#include <something/module 2/Interface3>

float Class_derived_magnitude(Class_derived *self)
{
	return sqrtf(self->x*self->x+self->y*self->y+self->z*self->z);
}
static const struct vtable_Interface2 vtable_Interface2=
{
	cast_offset(Class_derived, Interface2),

	(float (*)(Interface2 *))Class_derived_magnitude
};

static const struct vtable_Interface3 vtable_Interface3={cast_offset(Class_derived, Interface3)};

Class_derived Class_derived_new(float x, float y, float z)
{
	Class_derived self;
	*(Class_base *)&self=Class_base_new(x, y);
	self.Interface2=&vtable_Interface2;
	self.Interface3=&vtable_Interface3;

	self.z=z;

	return self;
}