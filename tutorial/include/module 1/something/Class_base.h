//Определение класса.

#pragma once

#include <module 1/typedefs/something/Class_base.h>
#include <Pixic/core library/C OOP.h>

struct Class_base
{
	//Все классы наследуют класс Object.
	//Наследование производится через анонимную структуру.
	Object;

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
//Методы.
float Class_base_magnitude(Class_base *self);

//Конструктор.
Class_base Class_base_new(float x, float y);