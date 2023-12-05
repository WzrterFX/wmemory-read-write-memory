using namespace std;

#include <Windows.h>
#include <iostream>

#include "wmemory/wmemory.h"

int main()
{
    uintptr_t processID = Wmemory::GetProcessID(L"cs2.exe");
    if (processID == NULL)
        return 0;

    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
    if (processHandle == NULL)
        return 0;

    uintptr_t moduleBaseAddress = Wmemory::GetModuleBaseAddress(processID, L"client.dll");
    if (moduleBaseAddress == NULL)
        return 0;

    uintptr_t localPlayerController;
    ReadProcessMemory(processHandle, reinterpret_cast<LPCVOID>(moduleBaseAddress + 0x180AA20), &localPlayerController, sizeof(uintptr_t), NULL);

    int writeFov = 144;
    WriteProcessMemory(processHandle, reinterpret_cast<LPVOID>(localPlayerController + 0x6D4), &writeFov, sizeof(int), NULL);

    int readFov = NULL;
    ReadProcessMemory(processHandle, reinterpret_cast<LPVOID>(localPlayerController + 0x6D4), &readFov, sizeof(int), NULL);

    CloseHandle(processHandle);
    return 0;
}