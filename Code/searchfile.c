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
		new_word = strtok(buffer, " ,.-!?\n");
		//comparing every token until it reaches end of line
		while(new_word != NULL)
		{
			//if new_word contains substring of str we print it
			//to the console
			if(strstr(new_word, str) != NULL)
			{
				printf("%s\n", new_word);
			}	

			new_word = strtok(NULL, " ,.-!?\n");
			
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
		new_word = strtok(buffer, " ,.-!?\n");
		//comparing every token until it reaches end of line
		while(new_word != NULL)
		{

			//comparing the word without replacing the new_word string
			caseless_str = strlwr(str);
			strcpy(caseless_word, new_word);
			strlwr(caseless_word);
			//problem might be working with references
			if(strstr(caseless_word, caseless_str) != NULL)
			{
				//printing original string with casing
				printf("%s\n", new_word);
			}	

			
			new_word = strtok(NULL, " ,.-!?\n");
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
			char* safe_copy;

			safe_copy = replace_word(new_word, str_replace);

			printf("%s\n", new_word);
			printf("%s\n", safe_copy);
			fprintf(write_file, "%s", safe_copy);
			

			free(safe_copy);
			safe_copy = 0;
		}
		else
		{
			fprintf(write_file, "%s", new_word);
		}

		

	}
	fclose(file);
	fclose(write_file);

}

char* replace_word(char *str, char *str_replace)
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

//https://stackoverflow.com/questions/23618316/undefined-reference-to-strlwr
//source of the strlwr function
char *strlwr(char *str)
{
	  unsigned char *p = (unsigned char *)str;

	  while (*p) 
	  {
	     *p = tolower((unsigned char)*p);
	      p++;
	  }

	  return str;
}

//geekfor geeks
char *replaceWord(const char *s, const char *oldW, 
                                 const char *newW) 
{ 
    char *result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
  
    // Counting the number of times old word 
    // occur in the string 
    for (i = 0; s[i] != '\0'; i++) 
    { 
        if (strstr(&s[i], oldW) == &s[i]) 
        { 
            cnt++; 
  
            // Jumping to index after the old word. 
            i += oldWlen - 1; 
        } 
    } 
  
    // Making new string of enough length 
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1); 
  
    i = 0; 
    while (*s) 
    { 
        // compare the substring with the result 
        if (strstr(s, oldW) == s) 
        { 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    } 
  
    result[i] = '\0'; 
    return result; 
}
