#ifndef PATTERN_SCAN_H
#define PATTERN_SCAN_H

#include <stddef.h>

/*

   Simple function that search a value in an array of bytes that is located
   between the pattern bounds and return its pointer.
   It uses a simple and naive algorithm, for better performance use KMP.
   
 */

void* find_pattern(const void* buffer, size_t bufferlen, const void* pattern, const char* mask);

#endif // !PATTERN_SCAN_H
