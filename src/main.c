#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "winapi_mem.h"
#include "pattern_scan.h"

int main(void)
{
    DWORD pid = GetProcessID("csgo.exe");

    if (pid == 0) 
    {
        puts("Process not found, exiting ...");
        return EXIT_FAILURE;
    }
    
    HANDLE process = GetProcessHandle(pid);

    if (process == NULL) 
    {
        puts("Process not found, exiting ...");
        return EXIT_FAILURE;
    }

    MODULEENTRY32 module;
    
    if (GetModuleEntry("client_panorama.dll", pid, &module) != 0) 
    {
        puts("Module not found, exiting ...");
        return EXIT_FAILURE;
    }

    unsigned char* buffer = (unsigned char*)malloc(module.modBaseSize);

    SIZE_T read_bytes = 0;

    if (!ReadProcessMemory(process, (LPVOID)module.modBaseAddr, buffer, (SIZE_T)module.modBaseSize, &read_bytes)) 
    {
        puts("Failed to read module, exiting ...");
        return EXIT_FAILURE;
    }

    if (read_bytes != module.modBaseSize) 
    {
        puts("Failed to read module, exiting ...");
        return EXIT_FAILURE;
    }

    unsigned char health_pattern[] = "\x89\x41\x64\x8B\x4F\x04\x83\xB9\x00\x00\x00\x00\x00\x7F\x2E\x8B\x01\x8B\x80\x88\x04\x00\x00";
    char health_mask[] = "xxxxxxxx????xxxxxxxxxxx";

    ptrdiff_t health_ptr = find_pattern(buffer, module.modBaseSize, health_pattern, health_mask);

    if (health_ptr == NULL) 
    {
        puts("Pattern not found ...");
        return EXIT_FAILURE;
    }

    printf("The value of the Health Offset is: %#x", health_ptr);
    
    free(buffer);

    return EXIT_SUCCESS;
}
