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

void replace_str_in_file(char* str_to_replace, char *str_replace, char *file_name)
{
	FILE *file;
	FILE *write_file;
	char buffer[BUFFER_SIZE];

	//output.txt
	file = fopen(file_name, "r");
	write_file = fopen("output.txt","w");

	while(fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		char *new_word = buffer; // storing the buffer in new_word pointer
		
		if(strstr(new_word, str_to_replace) != NULL)
		{	
			//creating the replaced string 
			char *replaced = replace_str(new_word, str_to_replace, str_replace); 

			//printing the string to be replaced with its replaced version
			printf("%s%s", new_word, replaced);
			//writing to the file with the replaced version only
			fprintf(write_file, "%s", replaced);

			free(replaced); // freeing the memory which we allocated on the heap
			replaced = 0; // setting replaced to null
		}
		else
		{
			//writing the rest of the file
			fprintf(write_file, "%s", new_word);
		}

	}
	//closing files
	fclose(file);
	fclose(write_file);

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
//https://stackoverflow.com/questions/779875/what-is-the-function-to-replace-string-in-c?fbclid=IwAR1_XGSwl36Ag_z5kGyPvnCyUW_R_aMfuVcaTey7E78Cu98H97h9lJPZj_s
//func from stackoverflow
char* replace_str(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}
