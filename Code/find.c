#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchfile.c"
#define BUFFER_SIZE 1000

int main(int argc, char ** argv)
{
	//char buffer[BUFFER_SIZE];
	char *str = argv[1];
	//if argv[2] == "-i" -> store file name
	char *file_name = argv[2];

	search_file_sentance(str, file_name);
	/*
	printf("searching words method:\n");
	search_file(str, file_name);
*/
	return 0;
}

