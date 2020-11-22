#include "pattern_scan.h"

#include <string.h>
#include <stddef.h>

void* find_pattern(const void* buffer, size_t bufferlen, const void* pattern, const char* mask)
{
    const unsigned char* patt = (const unsigned char*)pattern;
    const unsigned char* buff = (const unsigned char*)buffer;
    
    if(pattern == NULL)
        return NULL;

    if(mask == NULL)
        return NULL;

    if(buffer == NULL)
        return NULL;
    
    if(bufferlen == 0)
        return NULL;

    size_t masklen = strlen(mask);

    if (masklen == 0)
        return NULL;

    const unsigned char* end = buff + bufferlen - masklen;

    for (; buff < end; ++buff) {
        size_t i;

        for (i = 0; i != masklen; ++i) {
            if (mask[i] != '?' && buff[i] != patt[i])
                break;
        }
        if (i == masklen)
            return (void*)(buff + (strchr(mask, '?') - mask));
    }

    return NULL;
}
