#include "stop.h"

#include <stdio.h>

void stop()
{
    printf("\n");

    fflush(stdin);

    puts("Press ENTER to continue ... ");
    getchar();
}