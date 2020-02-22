#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchfile.h"
#define BUFFER_SIZE 1000

int main(int argc, char ** argv)
{
	//char buffer[BUFFER_SIZE];
	char *str;
	char *file_name;
	char *replace;
	// do it in loop argc is the find arg
	//if argv-1 == "-i" setfile name
	for(int i = 0; i < argc; i++)
	{
		if(i == 1)
		{
			str = argv[i];
			continue;
		}
		if(strcmp(argv[i],"-i") == 0)
		{
			file_name = argv[i+1];
		}
		if(strcmp(argv[i],"-r") == 0)
		{
			replace = argv[i+1];
		}
	}
	
	for(int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i],"-r") == 0)
		{
			replace_str_single_word(replace, file_name); // test this
			return 0;
		}
		else if(strcmp(argv[i],"-c") == 0)
		{
			search_file_ignore_case(str, file_name);
			return 0;
		}
	}

	search_file(str, file_name);
	return 0;
}

