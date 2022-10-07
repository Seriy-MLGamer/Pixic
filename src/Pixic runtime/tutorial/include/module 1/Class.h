/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

Copying and distribution of this file, with or without modification, are permitted in any medium without royalty provided the copyright notice and this notice are preserved. This file is offered as-is, without any warranty.
*/

//Определение класса.

#pragma once

#include <module 1/typedefs/Class.h>

struct Class
{
	//Поля.
	int a;
	float b;
};
//Конструктор.
Class Class_new(int a, float b);
//Методы.
float Class_sum(Class *self);