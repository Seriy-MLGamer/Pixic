/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

This file is part of Pixic runtime.
Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <typedefs/my own/system/Property_block.h>

#include <my own/system/Node_block.h>
#include <typedefs/my own/system/Property.h>
#include <Pixic/core library/C OOP.h>

struct Property_block
{
	Node_block *nodes;
	Property **properties;
};
inline Property_block Property_block_new()
{
	Property_block self;

	self.nodes=new_array(Node_block, 3);
	clean(self.nodes);
	self.properties=new_array(Property *, 1);
	*self.properties=NULL;

	return self;
}