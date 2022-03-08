#include "stdio.h"
#include <module 1/something else/Class>
#include <something/module 2/Class_derived>
#include <module 1/Interface2>

int main()
{
	//Всегда инициализируйте объект.
	Class a=Class_new(2, 2.8);
	//Вызов метода.
	float sum=Class_sum(&a);
	printf("Sum: %f\n", sum);
	Class_derived b=Class_derived_new(1, 1, 1);
	Interface2 *c=&b.Interface2;
	//Вызов виртуального метода.
	float magnitude=(*c)->magnitude(vcast(c));
	printf("Magnitude: %f\n", magnitude);
}