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