/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

This file is part of Pixic runtime.
Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <typedefs/system/linked list/Linked_list.h>

#include <stddef.h>

struct Linked_list
{
	void *prev, *next;
};
inline void Linked_list_set(Linked_list *self, Linked_list **list)
{
	Linked_list *start=*list;
	self->prev=NULL;
	if (start)
	{
		start->prev=self;
		self->next=start;
	}
	else self->next=NULL;
	*list=self;
}
inline void Linked_list_unset(Linked_list *self, Linked_list **list)
{
	Linked_list *prev=self->prev;
	Linked_list *next=self->next;
	if (prev)
	{
		if (next)
		{
			prev->next=next;
			next->prev=prev;
		}
		else prev->next=NULL;
	}
	else if (next)
	{
		next->prev=NULL;
		*list=next;
	}
	else *list=NULL;
}