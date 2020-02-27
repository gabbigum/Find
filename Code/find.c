#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchfile.h"
#define BUFFER_SIZE 1000

int main(int argc, char ** argv)
{
	char *str;
	char *file_name;
	char *replace;

	for(int i = 0; i < argc; i++)
	{
		if(i == 1)
		{
			str = argv[i]; // storing the search string in the first position of argv
			continue;
		}
		if(strcmp(argv[i],"-i") == 0)
		{
			file_name = argv[i+1]; // storing the name of the file after -i argument
		}
		if(strcmp(argv[i],"-r") == 0)
		{
			replace = argv[i+1]; //storing the replace string after -r argument
		}
	}
	
	for(int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i],"-r") == 0) // if we have arg -r we execute the method below and exit the application
		{
			replace_str_in_file(str ,replace, file_name); 
			return 0;
		}
		else if(strcmp(argv[i],"-c") == 0) // same for arg -c
		{
			search_file_ignore_case(str, file_name);
			return 0;
		}
	}

	search_file(str, file_name); // this method is executed if only -r and -c are not passed as an arguments
	return 0;
}

