#include <module 1/Class.h>

Class Class_new(int a, float b)
{
	Class self;

	self.a=a;
	self.b=b;

	return self;
}
float Class_sum(Class *self)
{
	return self->a+self->b;
}