using namespace std;

#include <Windows.h>
#include <iostream>

#include "Wmemory/Wmemory.h"

const wchar_t* processName = L"cs2.exe";
const wchar_t* moduleName = L"client.dll";

int main()
{
    uintptr_t processID = Wmemory::GetProcessID(processName);
    if (processID == 0)
        return 0;

    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
    if (processHandle == nullptr)
        return 0;

    uintptr_t moduleBaseAddress = Wmemory::GetModuleBaseAddress(processID, moduleName);
    if (moduleBaseAddress == 0)
        return 0;

    uintptr_t localPlayerController = Wmemory::ReadMemory(processHandle, moduleBaseAddress + 0x17FCDC8, sizeof(uintptr_t));

    Wmemory::WriteMemory(processHandle, localPlayerController + 0x6BC, 144, sizeof(int));

    CloseHandle(processHandle);
    return 0;
}