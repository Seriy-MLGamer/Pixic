/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

Copying and distribution of this file, with or without modification, are permitted in any medium without royalty provided the copyright notice and this notice are preserved. This file is offered as-is, without any warranty.
*/

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