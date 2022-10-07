/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

Copying and distribution of this file, with or without modification, are permitted in any medium without royalty provided the copyright notice and this notice are preserved. This file is offered as-is, without any warranty.
*/

//Определение класса.

#pragma once

#include <something else/module 2/typedefs/Class_derived.h>
#include <module 1/something/Class_base.h>

struct Class_derived
{
	//Наследование производится через анонимную структуру.
	Class_base;

	//Поля.
	float z;
};
//Таблица виртуальных методов класса.
//Интерфейсы не нужны!
struct Class_derived_f
{
	//Таблицы тоже могут наследоваться!
	struct Class_base_f;

	//Виртуальные методы.
	Class_derived (*dot)(void *self, Class_derived *operand);
};
//Конструктор.
Class_derived Class_derived_new(float x, float y, float z);
//Методы.
float Class_derived_magnitude(Class_derived *self);
Class_derived Class_derived_dot(Class_derived *self, Class_derived *operand);