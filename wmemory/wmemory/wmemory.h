#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include <vector>

/// <summary>
/// <para> The function finds the ID of a process by its name. </para>
/// <para> uintptr_t processID = GetProcessID(L"MyProcces.exe"); </para>
/// <para> HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID); </para>
/// </summary>
uintptr_t GetProcessID(const wchar_t* processName);

/// <summary>
/// <para> The function retrieves the base address of a module within a specified process. </para>
/// <para> uintptr_t moduleAddres = GetModuleBaseAddress(processID, L"MyModule.dll"); </para>
/// </summary>
uintptr_t GetModuleBaseAddress(uintptr_t processID, const wchar_t* moduleName);

/// <summary>
/// <para> The function reads memory address in a target process and returns that data as a uintptr_t value. </para>
/// <para> uintptr_t addresFromModule = ReadMemory(processHandle, moduleAddres + myAddres, sizeof(uintptr_t)); </para>
/// <para> uintptr_t myAddres1 = addresFromModule + myAddres2; </para>
/// <para> int myReadValue = ReadMemory(processHandle, myAddres1, sizeof(int)); </para>
/// </summary>
uintptr_t ReadMemory(HANDLE processHandle, uintptr_t address, size_t size);

/// <summary>
/// <para> The function stores memory address within a target process. </para>
/// <para> WriteMemory(processHandle, myAddres1, 144, sizeof(int)); </para>
/// </summary>
void WriteMemory(HANDLE processHandle, uintptr_t address, uintptr_t value, size_t size);