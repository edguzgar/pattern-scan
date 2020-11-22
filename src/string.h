#ifndef STRING_H
#define STRING_H

char*           scan(char* string);                 // Read dynamically allocated string of stdin
int             count(char str[], char search);     // Count ocurrences of search character (search) in the string (str)
void            remove_char(char* s, int c);        // Remove char
unsigned char*  hexstr_to_char(const char* hexstr); // Turn a hex string to unsigned char

#endif // !STRING_H
