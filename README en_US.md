<!--
(C) 2022-2023 Серый MLGamer <Seriy-MLGamer@yandex.ru>

This file is free documentation: you can redistribute it and/or modify it under the terms of the Creative Commons Attribution-ShareAlike 4.0 International license: <https://creativecommons.org/licenses/by-sa/4.0/>.
This file is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
-->

# **Pixic** - the Pixilang compiler

![Pixic logo](share/logo.png)

[**Pixilang**](http://warmplace.ru/soft/pixilang) is very convenient programming language. You can easily and quickly make a graphical program or demoscene using this language. But it has low performance because of bytecode interpretation.

With **Pixic** you can compile code written in Pixilang programming language! Firstly Pixic translates Pixilang code into C language, then translated code compiles into **native code**.

Performance of the Pixilang code compiled by Pixic increases at above **2** times!

Pixic is fully compatible with the official version of Pixilang.

# License

Pixic is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Pixic is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Pixic. If not, see <https://www.gnu.org/licenses/>.

![GNU GPLv3 logo](https://www.gnu.org/graphics/gplv3-with-text-136x68.png)

**Speed is a benefit of *free* Pixilang programs!** Only free programs can be compiled with Pixic and run because *Pixic runtime* library reqired for that is distributed under the terms of the not Lesser but normal **GNU General Public License**. Other programs can use an official Pixilang interpreter.

*Enjoy pixi-experiments.*

![Pixilang to C](share/code.png)

# In development. But something is working.

Now you can generate an intermediate file in C language using a few supported types of Pixilang statements:

* function definition: `fn miku($song)`;
* function call: `miku(ai_no_uta)`.

They support these types of expressions:

* global variable: `ai_no_uta`;
* local variable: `$song`;
* number (except color): `thank_yuu(39, 93)`;
* function: `miku(thank_yuu(39, 93))`.

Go to the "src/Pixic" folder and test it by running "test.sh" or "test.cmd" (but first you need to add Pixilang into the `PATH` environment variable). Report bugs if you find them and request pulls of your commits into the Pixic.