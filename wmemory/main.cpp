#include <Windows.h>
#include <iostream>

#include "wmemory/wmemory.h"

using namespace std;

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

    uintptr_t localPlayerController = Wmemory::ReadMemory<uintptr_t>(processHandle, moduleBaseAddress + 0x180AA20);

    Wmemory::WriteMemory<int>(processHandle, localPlayerController + 0x6D4, 144);

    Wmemory::ReadMemory<int>(processHandle, localPlayerController + 0x6D4);

    CloseHandle(processHandle);
    return 0;
}