/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

Copying and distribution of this file, with or without modification, are permitted in any medium without royalty provided the copyright notice and this notice are preserved. This file is offered as-is, without any warranty.
*/

//Определение класса.

#pragma once

#include <module 1/typedefs/something/Class_base.h>

struct Class_base
{
	//Класс, содержащий виртуальные методы, должен содержать это поле.
	const void *f;

	//Поля.
	float x, y;
};
//Таблица виртуальных методов класса.
//Интерфейсы не нужны!
struct Class_base_f
{
	//Виртуальные методы.
	float (*magnitude)(void *self);
};
//Конструктор.
Class_base Class_base_new(float x, float y);
//Методы.
float Class_base_magnitude(Class_base *self);