//Объявление класса.

#pragma once

/**
 * class Class_derived extends Class_base;
 * Указываем, от какого класса наследуется этот класс.
 */
typedef struct Class_derived Class_derived;
//Объявление таблицы виртуальных методов производится следующим образом.
//Оно нужно для виртуальных вызовов.
typedef const struct Class_derived_f *Class_derived_f;