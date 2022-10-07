/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

Copying and distribution of this file, with or without modification, are permitted in any medium without royalty provided the copyright notice and this notice are preserved. This file is offered as-is, without any warranty.
*/

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