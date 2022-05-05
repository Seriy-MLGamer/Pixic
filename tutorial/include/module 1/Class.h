//Определение класса.

#pragma once

#include <module 1/typedefs/Class.h>
#include <Pixic/core library/C OOP.h>

struct Class
{
	//Все классы наследуют класс Object.
	//Наследование производится через анонимную структуру.
	Object;

	//Поля.
	int a;
	float b;
};
//Конструктор.
Class Class_new(int a, float b);
//Методы.
float Class_sum(Class *self);