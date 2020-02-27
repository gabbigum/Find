#pragma once

void search_file(char *str, char *file_name);
void search_file_ignore_case(char *str, char *file_name);
void replace_str_in_file(char* str_to_replace,char *str_replace, char *file_name);
char* strlwr(char *str);
char *replace_str(char *orig, char *rep, char *with);