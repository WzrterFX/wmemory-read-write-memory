#ifndef WMEMORY_H
#define WMEMORY_H

#include <Windows.h>

namespace Wmemory
{
    /// <summary>
    /// Get the process ID associated with a specified process name.
    /// </summary>
    /// <param name="processName">The name of the target process.</param>
    /// <returns>The process id as an unsigned integer "uintptr_t".</returns>
    uintptr_t GetProcessID(const wchar_t* processName);

    /// <summary>
    /// Get the base address of a module within a given process.
    /// </summary>
    /// <param name="processID">The process id of the target process.</param>
    /// <param name="moduleName">The name of the target module.</param>
    /// <returns>The process id as an unsigned integer "uintptr_t".</returns>
    uintptr_t GetModuleBaseAddress(uintptr_t processID, const wchar_t* moduleName);
}

#endif