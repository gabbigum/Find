#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "searchfile.h"
#define BUFFER_SIZE 1000


void search_file(char *str, char *file_name)
{
	FILE *file;
	char buffer[BUFFER_SIZE];

	//open the file
	file = fopen(file_name, "r");

	//read every line from the file until it reaches the end
	while(fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		//array to store the new word
		char *new_word;
		//tokenizing every string on the line
		new_word = strtok(buffer, " ,.-!?");
		//comparing every token until it reaches end of line
		while(new_word != NULL)
		{
			//if new_word contains substring of str we print it
			//to the console
			if(strstr(new_word, str) != NULL)
			{
				printf("%s\n", new_word);
			}	

			new_word = strtok(NULL, " ,.-!?");
			
		}
	}
	//closing file
	fclose(file);
}

void search_file_ignore_case(char *str, char *file_name)
{
	FILE *file;
	char buffer[BUFFER_SIZE];
	
	//open the file
	file = fopen(file_name, "r");

	//read every line from the file until it reaches the end
	while(fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		//array to store the new word
		char *new_word;
		char *caseless_word;
		char *caseless_str;
		//tokenizing every string on the line
		new_word = strtok(buffer, " ,.-!?");
		//comparing every token until it reaches end of line
		while(new_word != NULL)
		{
			//if new_word contains substring of str we print it
			//to the console
			
			//comparing the word without replacing the new_word string
			caseless_str = strlwr(str);
			caseless_word = strlwr(new_word);
			//problem might be working with references
			if(strstr(caseless_word, caseless_str) != NULL)
			{
				//printing original string with casing
				printf("%s\n", new_word);
			}	

			new_word = strtok(NULL, " ,.-!?");
			
			caseless_str = NULL;
			caseless_word = NULL;
			
		}
	}
	//closing file
	fclose(file);
}

void replace_str_single_word(char *str_replace, char*file_name)
{
	FILE *file;
	FILE *write_file;
	char buffer[BUFFER_SIZE];

	//output.txt
	file = fopen(file_name, "r");
	write_file = fopen("output.txt","w");

	while(fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		char *new_word = buffer;
		
		//collect the index of new_word str str
		// substring address - address of the first char 
		if(strstr(new_word, str_replace) != NULL)
		{	
			//maybe this line need a fix make sure it replaces the word
			//correctly
			new_word = replace_word(new_word, str_replace);

			printf("%s\n", new_word);
			fprintf(write_file, "%s", new_word);
		}
		else
		{
			fprintf(write_file, "%s", new_word);
		}

		
		free(new_word);

		new_word = 0;
	}
	fclose(file);
	fclose(write_file);

}

char* replace_word(char *str, char* str_replace)
{
	//try it with void return type because stack is faster
	int len = strlen(str);
	char *replaced = (char*)malloc(50 * sizeof(char)); 

	for(int i = 0; i < len; i++)
	{
		//!!!! maybe raplace from the starting point of str str !!!!!
		if(strstr(str, str_replace) != NULL)
		{
			for(int j = 0; j < strlen(str_replace); j++)
			{
				replaced[i] = str_replace[j];
				i++;
			}
		}
		else
		{
			replaced[i] = str[i];
		}
	}
	
	replaced[len-1] = '\0';
	//replaced[len + 1] = '\n';

	return replaced;
}
void search_file_and_replace(char *str, char *str_replace, char *file_name)
{
	FILE *file;
	FILE *write_file;
	char buffer[BUFFER_SIZE];

	//output.txt
	file = fopen(file_name, "r");
	write_file = fopen("output.txt","w");

	while(fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		char *new_word;
		
		new_word = strtok(buffer, " ,.-!?");

		while(new_word != NULL)
		{
			if(strstr(new_word, str) != NULL)
			{	
				printf("%s", new_word);
				fprintf(write_file, "%s\n", new_word);
			}	

			new_word = strtok(NULL, " ,.-!?");
				//compare each word and move onto the next line
		}
	}
	fclose(file);
	fclose(write_file);
}


char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return str;
}