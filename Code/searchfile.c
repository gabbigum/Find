#include <stdio.h>
#include <stdlib.h>
#include "searchfile.h"
#define BUFFER_SIZE 1000

void searchfile(char *str, char *file_name)
{
	FILE *file;
	char buffer[BUFFER_SIZE];

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
	fclose(file);
}