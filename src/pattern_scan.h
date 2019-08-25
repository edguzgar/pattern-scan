#ifndef PATTERN_SCAN_H
#define PATTERN_SCAN_H

#include <stddef.h>

/*

   Simple function that search a value in an array of bytes that is located
   between the pattern bounds and return its pointer.
   It uses a simple and naive algorithm, for better performance use KMP.
   
 */

void* find_pattern(void* pattern, char* mask, void* buffer, size_t buffer_size);

#endif // !PATTERN_SCAN_H
