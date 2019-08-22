#include "pattern_scan.h"

#include <string.h>

void* find_pattern(unsigned char* pattern, char* mask, unsigned char* buffer, size_t n)
{
    size_t m = strlen(mask);
    unsigned char* end = buffer + n - m;

    for (; buffer < end; ++buffer) {
        size_t i;

        for (i = 0; i < m; ++i)
            if (mask[i] != '?' && buffer[i] != pattern[i])
                break;

        if (i == m)
            return buffer + (strchr(mask, '?') - mask);
    }

    return NULL;
}
