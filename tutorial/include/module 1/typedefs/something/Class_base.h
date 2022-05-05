//Объявление класса.

#pragma once

/**
 * class Class_base;
 * Мы указываем, что представляет из себя этот класс.
 */
typedef struct Class_base Class_base;
//Объявление таблицы виртуальных методов производится следующим образом.
//Оно нужно для виртуальных вызовов.
typedef const struct Class_base_f *Class_base_f;