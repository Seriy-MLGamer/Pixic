/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

Copying and distribution of this file, with or without modification, are permitted in any medium without royalty provided the copyright notice and this notice are preserved. This file is offered as-is, without any warranty.
*/

#include <stdio.h>
#include <module 1/Class.h>
#include <something else/module 2/Class_derived.h>

int main()
{
	//Всегда инициализируйте объект.
	Class a=Class_new(2, 2.8);
	//Вызов метода.
	float sum=Class_sum(&a);
	printf("Sum: %f\n", sum);
	Class_derived b=Class_derived_new(1, 1, 1);
	Class_base *c=(Class_base *)&b;
	//Вызов виртуального метода.
	float magnitude=((Class_base_f)c->f)->magnitude(c);
	printf("Magnitude: %f\n", magnitude);
	return 0;
}

//Теперь попробуйте сами всё скомпилировать.