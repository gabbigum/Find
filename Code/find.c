#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchfile.c"
#define BUFFER_SIZE 1000

int main(int argc, char ** argv)
{
	//FILE *file;
	
	char buffer[BUFFER_SIZE];
	char *str = argv[1];
	//if argv[2] == "-i" -> store file name
	char *file_name = argv[2];

	searchfile(str, file_name);


/*
	file = fopen(file_name, "r");

	//reading every line of the file with fgets
	while(fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		//storing every word in a variable
		char *new_word = buffer;
		//getting length of the variable
		int len = strlen(new_word);

		//checking if the substring of our first argument
		//exists in the new_word variable that we created
		if(strstr(new_word, str) != NULL)
		{
			printf("%s", new_word);
		}

	}
	*/
	return 0;
}

