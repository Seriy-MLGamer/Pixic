/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

Copying and distribution of this file, with or without modification, are permitted in any medium without royalty provided the copyright notice and this notice are preserved. This file is offered as-is, without any warranty.
*/

#include <module 1/something/Class_base.h>

#include <math.h>

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
float Class_base_magnitude(Class_base *self)
{
	return sqrtf(self->x*self->x+self->y*self->y);
}