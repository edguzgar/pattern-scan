#ifndef STRING_H
#define STRING_H

char*           scan(char* str);                 // Read dynamically allocated string of stdin
int             count(char* str, char c);      // Count ocurrences of search character "search" in the string "str"
void            remove_char(char* str, char c);      // Remove specified char "c" in the string "str"
unsigned char*  hexstr_to_char(const char* hexstr); // Turn a hex string to unsigned char (Autor: xsleonard, https://gist.github.com/xsleonard/7341172)

#endif // !STRING_H
