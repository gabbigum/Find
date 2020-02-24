# Find

Find is a C program which is dealing with string occurances in text files.
It's main functions are to search for a substrings with option for case insensitive search,and to replace all given ocurrances of substring with another substring. 

## Installation

Use the makefile located in the program folder to build and run the program.

GCC compiler is used for compiling and linking the program.

1.Open terminal window in the program directory

2.Use command "make all" to build. The program will output
an object file named "find"

3.To run the program write "./find *arguments*"

## Arguments that the program takes

	Note: 1.The first argument is always of type string (the string we are searching for in the text file)

	2.The order of passed arguments does NOT matter after the first argument
		  list of arguments:
		  	i <file_name> - input the file name
		  	-r <string>   - replace all substring occurances 
		  	-c 	      - case insensitive search  

	3. Example
		  ./find Hello -i sentences_test.txt -c
		  ./find el i- single_words_text.txt -r EL

