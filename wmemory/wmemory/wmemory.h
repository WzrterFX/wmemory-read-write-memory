#ifndef WMEMORY_H
#define WMEMORY_H

#include <Windows.h>

namespace Wmemory
{
    uintptr_t GetProcessID(const wchar_t* processName);

    uintptr_t GetModuleBaseAddress(uintptr_t processID, const wchar_t* moduleName);

    template <typename T>
    T ReadMemory(HANDLE processHandle, uintptr_t address)
    {
        T value;
        ReadProcessMemory(processHandle, reinterpret_cast<LPCVOID>(address), &value, sizeof(T), NULL);
        return value;
    }

    template <typename T>
    void WriteMemory(HANDLE processHandle, uintptr_t address, const T& value)
    {
        WriteProcessMemory(processHandle, reinterpret_cast<LPVOID>(address), &value, sizeof(T), NULL);
    }
}

#endif