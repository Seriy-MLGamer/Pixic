#include <hash table/system/hash.h>

static Hash CRC32_table[256];
static bool table_not_created=true;

Hash hash(const char *data)
{
	if (table_not_created) for (int a=0; a!=256; a++)
	{
		Hash crc=a;
		for (int a=0; a!=8; a++) crc=crc&1?crc>>1^0xEDB88320:crc>>1;
		CRC32_table[a]=crc;
		table_not_created=false;
	}
	Hash result=0xFFFFFFFF;
	while (*data) result=CRC32_table[(result^*(data++))&0xFF]^result>>8;
	return result^0xFFFFFFFF;
}