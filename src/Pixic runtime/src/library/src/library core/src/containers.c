/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

This file is part of Pixic runtime.
Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.
*/

#include <containers.h>

#include <stdio.h>
#include <Pixic/core/call.h>
#include <core/Container.h>
#include <core/core.h>

//FIXME
//These variables must be local for apps uses Pixic runtime library dynamically. I should implement apps accounting, but I'll do it later.
static Container **containers;
static Int container_count;
static Int container_pointer;

static void iset_element(Var *pixi, Var *x, Var *value)
{
	Container_ID ID=Var_to_int(pixi);
	if (ID>=0&&ID<settings.container_count) if (containers[ID]) Container_set(containers[ID], Var_to_int(x), 0, value);
}
static void iset_element2(Var *pixi, Var *x, Var *y, Var *value)
{
	Container_ID ID=Var_to_int(pixi);
	if (ID>=0&&ID<settings.container_count) if (containers[ID]) Container_set(containers[ID], Var_to_int(x), Var_to_int(y), value);
}
static Var iget_element(Var *pixi, Var *x)
{
	Container_ID ID=Var_to_int(pixi);
	if (ID>=0&&ID<settings.container_count) if (containers[ID]) return Container_get(containers[ID], Var_to_int(x), 0);
	return Var_new2(0);
}
static Var iget_element2(Var *pixi, Var *x, Var *y)
{
	Container_ID ID=Var_to_int(pixi);
	if (ID>=0&&ID<settings.container_count) if (containers[ID]) return Container_get(containers[ID], Var_to_int(x), Var_to_int(y));
	return Var_new2(0);
}

Var
	pcINT8,
	pcINT16,
	pcINT32,
	#ifdef X64
	pcINT64,
	#endif
	pcFLOAT32;
#ifdef X64
Var pcFLOAT64;
#endif

static Var ipfnew(unsigned argument_count, ...)	
{
	va_list arguments;
	Int xsize;
	if (argument_count<1) xsize=1;
	else
	{
		Var plxsize;
		get_argument(plxsize, 0)
		xsize=Var_to_int(&plxsize);
		if (xsize<1) return Var_new2(-1);
	}
	Int ysize;
	if (argument_count<2) ysize=1;
	else
	{
		Var plysize;
		get_argument(plysize, 1)
		ysize=Var_to_int(&plysize);
		if (ysize<1) return Var_new2(-1);
	}
	Int type;
	if (argument_count<3) type=Var_to_int(&pcPIXEL);
	else
	{
		Var pltype;
		get_argument(pltype, 2)
		type=Var_to_int(&pltype);
		if (type<INT8||type>=type_count) return Var_new2(-1);
	}
	if (container_count==settings.container_count)
	{
		printf("All container slots of %i are filled.\n", container_count);
		return Var_new2(-1);
	}
	while (containers[container_pointer]) container_pointer=(container_pointer+1)%settings.container_count;
	Container *container=new(Container);
	if (!container) return Var_new2(-1);
	*container=Container_new(xsize, ysize, type);
	containers[container_pointer]=container;
	container_count++;
	return Var_new2(container_pointer);
}
static Var ipfremove(unsigned argument_count, ...)
{
	va_list arguments;
	if (argument_count>=1)
	{
		Var plpixi;
		get_argument(plpixi, 0)
		Container_ID pixi=Var_to_int(&plpixi);
		if (pixi>=0&&pixi<settings.container_count)
		{
			Container **container=containers+pixi;
			if (*container!=NULL)
			{
				Container_remove(*container);
				*container=NULL;
				container_count--;
			}
		}
	}
	return Var_new2(0);
}

void (*set_element)(Var *pixi, Var *x, Var *value)=iset_element;
void (*set_element2)(Var *pixi, Var *x, Var* y, Var *value)=iset_element2;
Var (*get_element)(Var *pixi, Var *x)=iget_element;
Var (*get_element2)(Var *pixi, Var *x, Var* y)=iget_element2;

Var (*pfnew)(unsigned argument_count, ...)=ipfnew;
Var (*pfremove)(unsigned argument_count, ...)=ipfremove;

int containers_init()
{
	containers=new_array(Container *, settings.container_count);
	if (!containers) return 1;
	clean(containers);
	container_count=0;
	container_pointer=0;

	pcINT8=Var_new2(INT8);
	pcINT16=Var_new2(INT16);
	pcINT32=Var_new2(INT32);
	#ifdef X64
	pcINT64=Var_new2(INT64);
	#endif
	pcFLOAT32=Var_new2(FLOAT32);
	#ifdef X64
	pcFLOAT64=Var_new2(FLOAT64);
	#endif

	return 0;
}
int containers_deinit()
{
	container_pointer=0; while (container_count)
	{
		Container **container=containers+container_pointer;
		if (*container)
		{
			Container_remove(*container);
			delete(*container);
			container_count--;
		}
		container_pointer++;
	}
	delete(containers);
	return 0;
}