#include "winapi_mem.h"

#include <string.h>

BOOL IsProcessRunning(const char* szProcess)
{
    HANDLE processSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (processSnapshot != INVALID_HANDLE_VALUE) {
        
        PROCESSENTRY32 processEntry;
        processEntry.dwSize = sizeof(PROCESSENTRY32);

        if (Process32First(processSnapshot, &processEntry)) {
            do {
                if (strcmp(processEntry.szExeFile, szProcess) == 0) {
                    CloseHandle(processSnapshot);
                    return TRUE;
                }
            } while (Process32Next(processSnapshot, &processEntry));
        }

        CloseHandle(processSnapshot);
    }

    return FALSE;
}

DWORD GetProcessID(const char* szProcess)
{
    DWORD pid = 0;
    HANDLE processSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (processSnapshot != INVALID_HANDLE_VALUE) {
        
		PROCESSENTRY32 processEntry;
        processEntry.dwSize = sizeof(PROCESSENTRY32);

        if (Process32First(processSnapshot, &processEntry)) {
            do {
                if (strcmp(processEntry.szExeFile, szProcess) == 0) {
                    pid = processEntry.th32ProcessID;
                    break;
                }
            } while (Process32Next(processSnapshot, &processEntry));
        }

        CloseHandle(processSnapshot);
    }

    return pid;
}

HANDLE GetProcessHandle(DWORD pid)
{
    return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);		// PROCESS_VM_READ to just read
}

int GetModuleEntry(const char* szModule, DWORD pid, MODULEENTRY32* module)
{
    HANDLE moduleSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);

    if (moduleSnapshot != INVALID_HANDLE_VALUE) {
        
        module->dwSize = sizeof(MODULEENTRY32);

        if (Module32First(moduleSnapshot, module)) {
            do {
                if (strcmp(module->szModule, szModule) == 0) {
                    CloseHandle(moduleSnapshot);
                    return 0;
                }
            } while (Module32Next(moduleSnapshot, module));
        }

        CloseHandle(moduleSnapshot);
    }

    return -1;
}

DWORD GetModuleBaseAddr(const char* szModule, DWORD pid)
{
    DWORD moduleBaseAddr = 0;
    HANDLE moduleSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);

    if (moduleSnapshot != INVALID_HANDLE_VALUE) {

        MODULEENTRY32 module;
        module.dwSize = sizeof(MODULEENTRY32);

        if (Module32First(moduleSnapshot, &module)) {
            do {
                if (strcmp(module.szModule, szModule) == 0) {
                    moduleBaseAddr = (DWORD)module.modBaseAddr;
                    break;
                }
            } while (Module32Next(moduleSnapshot, &module));
        }

        CloseHandle(moduleSnapshot);
    }

    return moduleBaseAddr;
}
