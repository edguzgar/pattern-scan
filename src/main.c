#include "string.h"
#include "swap.h"
#include "stop.h"
#include "winapi_mem.h"
#include "pattern_scan.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    DWORD pid = GetProcessID("csgo.exe");

    if (pid == -1)
    {
        puts("Process not found, exiting ...");
        stop();
        return EXIT_FAILURE;
    }
    
    HANDLE process = GetProcessHandle(pid);

    if (process == NULL) 
    {
        puts("Process not found, exiting ...");
        stop();
        return EXIT_FAILURE;
    }

    MODULEENTRY32* module = (MODULEENTRY32*)malloc(sizeof(MODULEENTRY32));
    
    GetModuleEntry("client.dll", pid, module);

    if (module == NULL)
    {
        puts("Module not found, exiting ...");
        stop();
        return EXIT_FAILURE;
    }

    unsigned char* buffer = (unsigned char*)malloc(module->modBaseSize);

    SIZE_T read_bytes = 0;

    if (!ReadProcessMemory(process, (LPVOID)module->modBaseAddr, buffer, (SIZE_T)module->modBaseSize, &read_bytes)) 
    {
        puts("Failed to read module, exiting ...");
        stop();
        return EXIT_FAILURE;
    }

    if (read_bytes != module->modBaseSize) 
    {
        puts("Failed to read module, exiting ...");
        stop();
        return EXIT_FAILURE;
    }

    /* Example :
    *       Health Pattern
    * 
            pattern =   \x04\x83\xB9\x00\x01\x00\x00\x00\x0F\x8E\x36\x01
            mask    =   xxx????xxxxx
    */

    char* patt = NULL;
    unsigned char* pattern = NULL;
    char* mask = NULL;

    puts("Insert the pattern:");
    patt = scan(patt);

    remove_char(patt, '\\');
    remove_char(patt, 'x');
    remove_char(patt, 'X');

    puts("Insert the mask:");
    mask = scan(mask);

    puts(patt);
    puts(mask);
    
    pattern = hexstr_to_char(patt);

    DWORD* health_ptr = (DWORD*)find_pattern(buffer, module->modBaseSize, pattern, mask);

    if (health_ptr == NULL)
    {
        puts("Pattern not found ...");
        stop();
        return EXIT_FAILURE;
    }

    printf("The value of the Health Offset is: %#x", *health_ptr);
    
    free(patt);
    free(pattern);
    free(mask);
    free(module);
    free(buffer);
    
    stop();

    return EXIT_SUCCESS;
}
