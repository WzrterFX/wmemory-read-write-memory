using namespace std;

#include <Windows.h>
#include <iostream>

#include "wmemory/wmemory.h"

const uintptr_t dwLocalPlayerController = 0x17E8158;
const uintptr_t m_iDesiredFOV = 0x6A4;

int main()
{
    uintptr_t processID = GetProcessID(L"cs2.exe");
    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
    if (processHandle == NULL)
        return 0;

    uintptr_t clientModule = GetModuleBaseAddress(processID, L"client.dll");
    if (clientModule == NULL)
        return 0;

    uintptr_t localPlayerController = ReadMemory(processHandle, clientModule + dwLocalPlayerController, sizeof(uintptr_t));

    uintptr_t desiredFOVAddress = localPlayerController + m_iDesiredFOV;

    int defaultFov = ReadMemory(processHandle, desiredFOVAddress, sizeof(int));
    cout << "default fov is " << defaultFov << endl;

    WriteMemory(processHandle, desiredFOVAddress, 144, sizeof(int));
    int currentFov = ReadMemory(processHandle, desiredFOVAddress, sizeof(int));
    cout << "new fov is " << currentFov << endl;

    CloseHandle(processHandle);
    return 0;
}