#include "swap.h"

int swap_int16(int num)
{
    int swap;
    swap = (num >> 8) | (num << 8);
    return swap;
}

int swap_int32(int num)
{
    int swap;
    swap = ((num >> 24) & 0xff) |
           ((num << 8) & 0xff0000) |
           ((num >> 8) & 0xff00) |
           ((num << 24) & 0xff000000);
    return swap;
}