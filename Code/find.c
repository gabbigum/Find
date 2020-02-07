#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"
#define BUFFER_SIZE 1000

int main(int argc, char ** argv)
{
	FILE *file;
	
	char buffer[BUFFER_SIZE];
	char *str = argv[1];
	char *file_name = argv[2];

	file = fopen(file_name, "r");

	while(fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		char *new_word = buffer;
		int len = strlen(new_word);

		if(strstr(new_word, str) != NULL)
		{
			printf("%s", new_word);
		}

	}
	//that's the string that we will be working with
	//argv 1 is the first command 


	return 0;
}

