#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchfile.h"
#define BUFFER_SIZE 1000

void search_file(char *str, char *file_name)
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

void search_file_sentance(char *str, char *file_name)
{
	FILE *file;
	char buffer[BUFFER_SIZE];

	file = fopen(file_name, "r");

	while(fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		char *new_word;

		new_word = strtok(buffer, " ,.-!?");

		while(new_word != NULL)
		{
			if(strstr(new_word, str) != NULL)
			{
				printf("%s\n", new_word);
			}	

			new_word = strtok(NULL, " ,.-!?");
			//compare each word and move onto the next line
		}
	}
	fclose(file);
}

/*char* string_tokenize(char *str)
{
	char *pch;
	printf("Splitting %s into tokens\n", str);

	pch = strtok (str," ");
	
	while (pch != NULL)
	{
		printf ("%s ",pch);
	    pch = strtok (NULL, " ,.-");
	}
	return pch;
}
*/