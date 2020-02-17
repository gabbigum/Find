#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		
		
		if(strstr(new_word, str_replace) != NULL)
		{	
			new_word = replace_word(new_word, str_replace);
			printf("%s", new_word);
			fprintf(write_file, "%s\n", new_word);
		}
		else
		{
			fprintf(write_file, "%s\n", new_word);
		}

		
	}
	fclose(file);
	fclose(write_file);

}

char* replace_word(char *str, char* str_replace)
{
	int len = strlen(str);
	char replaced[50];
	int replace_counter = 0;

	for(int i = 0; i < len; i++)
	{
		//!!!! maybe raplace from the starting point of str str !!!!!
		if(strcmp(str[i],str_replace[replace_counter]) == 0)
		{
			replaced[i] = str_replace[replace_counter];
			replace_counter++;
		}
		else
		{
			replaced[i] = str[i];
		}
	}
	replaced[len + 1] = '\0';

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