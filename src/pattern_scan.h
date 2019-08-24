#ifndef PATTERN_SCAN_H
#define PATTERN_SCAN_H

#include <stddef.h>

/*
  Simple function that search a value in an array of bytes that is located
  between the pattern bounds and return its pointer.
  It uses a simple and naive algorithm, for better performance use KMP.

  Usage :

    - pass the pattern e.g "/xA1/xFF/xF2/x42/x00/x00/x00/x00/x10/x22/x55/xFF"
      or "{ 0xA1, 0xFF, 0xF2, 0x42, 0x00, 0x00, 0x00, 0x00, 0x10, 0x22, 0x55, 0xFF }"
    - pass the mask as char array "xxxx????xxxx" where '?' means the value to find.
    - pass the pointer to the buffer of bytes.
    - pass its size in bytes.
 */

void* find_pattern(void* pattern, char* mask, void* buffer, size_t buffer_size);

#endif // !PATTERN_SCAN_H
