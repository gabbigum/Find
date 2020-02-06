#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"


int main(int argc, char ** argv)
{
	char string[] = "Hello";
	char search[] = "el";

	string_contains(search, string);
	//search_string(search, string);
	return 0;
}