#include "pattern_scan.h"

#include <string.h>

void* FindPattern(unsigned char* pattern, char* mask, unsigned char* buffer, size_t buffer_size)
{
    size_t mask_size = strlen(mask);
    unsigned char* end = buffer + buffer_size - mask_size;

    for (; buffer < end; ++buffer) {
        size_t i;

        for (i = 0; i < mask_size; ++i)
            if (mask[i] != '?' && buffer[i] != pattern[i])
                break;

        if (i == mask_size)
            return buffer + (strchr(mask, '?') - mask);
    }

    return NULL;
}