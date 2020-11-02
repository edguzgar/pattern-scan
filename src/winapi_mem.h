#ifndef WINAPI_MEM_H
#define WINAPI_MEM_H

#include <windows.h>
#include <tlhelp32.h>

// WinAPI functions to manage memory of other processes in User Space.
// Only works for 32 bit

BOOL	 IsProcessRunning(const char* process);
DWORD  GetProcessID(const char* process);
HANDLE GetProcessHandle(DWORD pid);
int    GetModuleEntry(const char* moduleName, DWORD pid, MODULEENTRY32* module);
DWORD	 GetModuleBaseAddr(const char* moduleName, DWORD pid);

#endif // !WINAPI_MEM_H
