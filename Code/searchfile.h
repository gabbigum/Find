#pragma once

void search_file(char *str, char *file_name);
void search_file_ignore_case(char *str, char *file_name);
void search_file_and_replace(char *str, char *str_replace, char *file_name);
void remove_newline(char *str);
char* replace_word(char* str, char* str_replace);
void replace_str_single_word(char *str_replace, char *file_name);