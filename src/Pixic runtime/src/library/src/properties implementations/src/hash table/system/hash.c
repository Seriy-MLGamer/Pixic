#include <hash table/system/hash.h>

static Hash CRC32_table[256];
static bool table_not_created=true;

Hash hash(const char *data)
{
	Hash result;
	if (table_not_created)
	{
		for (int a=0; a!=256; a++)
		{
			result=a;
			for (int a=0; a!=8; a++) result=result&1?result>>1^0xEDB88320:result>>1;
			CRC32_table[a]=result;
		}
		table_not_created=false;
	}
	result=0xFFFFFFFF;
	while (*data) result=CRC32_table[(result^*(data++))&0xFF]^result>>8;
	return result^0xFFFFFFFF;
}