#pragma once

#include <Windows.h>

namespace Wmemory
{
	uintptr_t GetProcessID(const wchar_t* processName);

	uintptr_t GetModuleBaseAddress(uintptr_t processID, const wchar_t* moduleName);

	uintptr_t ReadMemory(HANDLE processHandle, uintptr_t address, size_t size);

	void WriteMemory(HANDLE processHandle, uintptr_t address, uintptr_t value, size_t size);
}