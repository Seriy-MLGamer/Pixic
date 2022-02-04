#include "Pixic.h"

#include "stdio.h"
#include <classes/Parsing>
#include <classes/UTF-8/UTF8_file>

using namespace std;

int argument_count;
char** arguments;

int main(int argc, char** argv)
{
	argument_count=argc;
	arguments=argv;
	Parsing a;
	cout<<"Input: "<<a.input_file<<'\n';
	cout<<"Output: "<<a.output_folder<<'\n';
	cout<<"Optimization: "<<a.optimization<<'\n';
	/*FILE* pixi=fopen(a.input_file, "rb");
	fseek(pixi, 0, SEEK_END);
	long size=ftell(pixi);
	fseek(pixi, 0, SEEK_SET);
	printf("Hello! Size is %li\n", size);
	printf("\"include\" is here: %li\n", search_in_file(pixi, size, "include", SEARCH_CASE_SENSITIVE|SEARCH_WHOLE_WORD));*/
}