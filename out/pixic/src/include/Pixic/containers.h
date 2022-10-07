/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

This file is part of Pixic runtime.
Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <Pixic/core/Var.h>

extern void (*set_element)(Var *pixi, Var *x, Var *value);
extern void (*set_element2)(Var *pixi, Var *x, Var *y, Var *value);
extern Var (*get_element)(Var *pixi, Var *x);
extern Var (*get_element2)(Var *pixi, Var *x, Var *y);

extern Var
	pcINT8,
	pcINT16,
	pcINT32,
	#ifdef X64
	pcINT64,
	#endif
	pcFLOAT32;
#ifdef X64
extern Var pcFLOAT64;
#endif
#ifdef X32
#define pcINT pcINT32
#define pcFLOAT pcFLOAT32
#endif
#ifdef X64
#define pcINT pcINT64
#define pcFLOAT pcFLOAT64
#endif
#define pcPIXEL pcINT32

extern Var (*pfnew)(unsigned argument_count, ...);
extern Var (*pfremove)(unsigned argument_count, ...);