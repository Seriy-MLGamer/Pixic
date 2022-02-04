#include <classes/Parsing>

#include "string.h"
#include <iostream>
#include "Pixic.h++"
#include <classes/UTF-8/UTF8_file>

using namespace std;

static string temp_pixi_name;
static UTF8_file temp_pixi;

static inline void show_help();
static inline void parse_optimization(Parsing& result, string argument);

Parsing::Parsing()
{
	if (argument_count>4)
	{
		cerr<<*arguments<<": error: too many arguments.\n";
		exit(EXIT_FAILURE);
	}
	optimization=0;
	for (int a=1; a!=argument_count; a++)
	{
		if (arguments[a][0]=='-')
		{
			switch (arguments[a][1])
			{
				case '-':
					if (!strcmp(&arguments[a][2], "help")) show_help();
					else
					{
						cerr<<*arguments<<": error: unknown keyword.\n";
						exit(EXIT_FAILURE);
					}
				case 'h':
					show_help();
				case 'O':
					try
					{
						parse_optimization(*this, &arguments[a][2]);
					}
					catch(exception&)
					{
						exit(EXIT_FAILURE);
					}
					break;
				default:
					cerr<<*arguments<<": error: unknown symbol.\n";
					exit(EXIT_FAILURE);
			}
		}
		else if (input_file=="") input_file=arguments[a];
		else if (output_folder=="") output_folder=arguments[a];
	}
	if (input_file!="")
	{
		if (output_folder=="")
		{
			size_t length=input_file.length();
			size_t a=length;
			do a--; while (input_file[a]!='.'&&a);
			if (a) length=a;
			output_folder=input_file;
			output_folder.resize(length);
		}
	}
	else
	{
		cerr<<*arguments<<": error: no input file.\n";
		exit(EXIT_FAILURE);
	}
}
/*void Parsing::Pixilang_to_C()
{
	size_t length=strlen(output_folder);
	temp_pixi_name=new char[length+12];
	memcpy(temp_pixi_name, output_folder, length);
	memcpy(&temp_pixi_name[length], "/.temp.pixi", 12);
	temp_pixi=fopen(temp_pixi_name, "wb");
	delete[] temp_pixi_name;
}*/

static inline void show_help()
{
	cout<<"I can't help you.\n";
	exit(EXIT_SUCCESS);
}
static inline void parse_optimization(Parsing& result, string argument)
{
	if (!isdigit(argument[0]))
	{
		cerr<<*arguments<<": error: optimization level is not a number.\n";
		throw exception();
	}
	result.optimization=stoi(argument);
}