#include <classes/UTF-8/UTF8_file>

/*int main(int argument_count, char** arguments)
{
	if (argument_count!=4) exit(EXIT_FAILURE);
	FILE* read=fopen(arguments[1], "rb");
	FILE* write=fopen(arguments[2], "wb");
	long value;
	while ((value=fgetc(read))!=EOF)
	{
		for (char a=7; a!=-1; a--) putchar(value&1<<a?'O':'o');
		putchar(' ');
	}
	putchar('\n');
	fseek(read, 0, SEEK_SET);
	while ((value=get_UTF8(read))!=EOF)
	{
		for (char a=31; a!=-1; a--) putchar(value&1<<a?'O':'o');
		putchar('\n');
		if (value==UTF8_ERROR)
		{
			printf("UTF-8 error!\n");
			exit(EXIT_FAILURE);
		}
		fputc(value, write);
		fputc(value>>8, write);
	}
	fclose(read);
	fclose(write);
	read=fopen(arguments[2], "rb");
	write=fopen(arguments[3], "wb");
	while ((value=fgetc(read))!=EOF)
	{
		value|=fgetc(read)<<8;
		put_UTF8_LE(value, write);
	}
	printf("%i\n", rand());
	exit(EXIT_SUCCESS);
}*/

using namespace std;

int main(int argument_count, char** arguments)
{
	if (argument_count!=2) return EXIT_FAILURE;
	UTF8_file* miku=new UTF8_file(arguments[1], ios_base::in|ios_base::binary);
	miku->seekg(0, ios_base::end);
	printf("%li\n", (long)miku->tellg());
	miku->seekg(-2, ios_base::cur);
	UTF32_char a=miku->get();
	UTF8_file hatsune("MLG.txt", ios_base::out|ios_base::binary);
	hatsune.put(a);
	delete miku;
	return EXIT_SUCCESS;
}