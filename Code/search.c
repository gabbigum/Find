#include <string.h>
#include <stdio.h>
#include "search.h"

//this method searches for a string in string and prints it
//Find string while knowing part of it and return string

void search_string(char *user_string, char *str)
{
	int counter = 0;

	while(str != NULL)
	{
		printf("%s\n",strstr(str, user_string));
		counter++;
	}

	/*
	int len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		printf("%s\n", strstr(str, user_string));
	}
	*/

/*	int counter = 0;
	int user_string_counter = 0;

	while(counter < len)
	{
		//check if user string matches the given string
		//until the user string runs out of characters
		//if they are equal until that point print the whole string
		while(user_string[user_string_counter] != '\0')
		{
			if(user_string[user_string_counter] == str[counter])\
			{	
				counter++;
				user_string_counter++;
			}
			else
			{
				user_string_counter = 0;
				break;
			}
		}

		counter++;
	}*/
}	

int string_contains(char *str, char *contains)
{
	int counter = 0;
	int len = strlen(contains);

	while(str != NULL)
	{

		if(strcmp(contains, str) == len)
		{
			printf("%s", str);
			break;
		}
	}	
	return 0;
}

//this method searches for a string in a file
