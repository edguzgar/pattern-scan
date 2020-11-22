#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* scan(char* string)
{
    int c;
    string = malloc(sizeof(char));

    string[0] = '\0';
    
    int i = 0;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        string = realloc(string, (i + 2) * sizeof(char));   // Reallocating memory (+ 1 for new character + 2 for '\0')
        string[i] = (char)c;
        ++i;
    }

    string[i] = '\0';   // Inserting null character at the end

    return string;
}

int count(char str[], char search)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == search)
        {
            ++count;
        }

        ++i;
    }

    return count;
}

void remove_char(char* s, int c)
{
    int j, n = strlen(s);
    
    for (int i = j = 0; i < n; i++)
        if (s[i] != c)
            s[j++] = s[i];

    s[j] = '\0';
}

unsigned char* hexstr_to_char(const char* hexstr) // Autor: xsleonard, https://gist.github.com/xsleonard/7341172
{
    size_t len = strlen(hexstr);

    if(len % 2 != 0)           // Make an assertion
        return NULL;

    size_t final_len = len / 2;
    unsigned char* chrs = (unsigned char*)malloc((final_len + 1) * sizeof(*chrs));

    for (size_t i = 0, j = 0; j < final_len; i += 2, j++)
        chrs[j] = (hexstr[i] % 32 + 9) % 25 * 16 + (hexstr[i + 1] % 32 + 9) % 25;

    chrs[final_len] = '\0';

    return chrs;
}
