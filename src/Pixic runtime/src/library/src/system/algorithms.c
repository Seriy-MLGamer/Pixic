/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

This file is part of Pixic runtime.
Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.
*/

#include "Pixic/core library/algorithms.h"

#include "stdbool.h"

static Hash CRC32_table[256];
static bool table_created=false;

Hash hash(const void *data, size_t size)
{
	if (!table_created) for (int a=0; a!=256; a++)
	{
		Hash crc=a;
		for (int a=0; a!=8; a++) crc=crc&1?crc>>1^0xEDB88320:crc>>1;
		CRC32_table[a]=crc;
	}
	Hash result=0xFFFFFFFF;
	while (size--) result=CRC32_table[(result^*(char *)(data++))&0xFF]^result>>8;
	return result^0xFFFFFFFF;
}