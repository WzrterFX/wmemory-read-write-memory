# Wmemory library

Wmemory is a versatile C++ library designed for Windows, providing functionalities for memory manipulation within external processes.
The library offers several features to facilitate process interaction and memory management.


## Getting Started

### Prerequisites
- Visual Studio or any C++ compiler that supports C++11 or later.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/WzrterFX/wmemory-read-write-memory
   ```



## Features

### 1. Get process
- **Function:** `Wmemory::GetProcessID(const wchar_t* processName);`
  - **Description:** Get the process id of a target process by providing its name.
  - **Example:**
    ```cpp
    uintptr_t processID = Wmemory::GetProcessID(L"Procces.exe");
    ```

### 2. Get module address
- **Function:** `GetModuleBaseAddress(uintptr_t processID, const wchar_t* moduleName);`
  - **Description:** Get the base address of a module within a specified process.
  - **Example:**
    ```cpp
    uintptr_t moduleBaseAddress = Wmemory::GetModuleBaseAddress(processID, L"target.dll");
    ```

### 3. Memory reading
- **Function:** `Wmemory::ReadMemory<T>(HANDLE processHandle, uintptr_t address);`
  - **Description:** Read the value of a specified data type from the memory of a target process.
  - **Example:**
    ```cpp
    int specifiedMemory = Wmemory::ReadMemory<int>(processHandle, moduleBaseAddress + 0x00);
    ```

### 4. Memory writing
- **Function:** `Wmemory::WriteMemory(HANDLE processHandle, uintptr_t address, const T& value)`
  - **Description:** Write a value of a specified data type to the memory of a target process.
  - **Example:**
    ```cpp
    Wmemory::WriteMemory<int>(processHandle, specifiedMemory + 0x00, 16);
    ```


## Example Usage

```cpp
#include <Windows.h>
#include <iostream>

using namespace std;

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

    uintptr_t localPlayerController = Wmemory::ReadMemory<uintptr_t>(processHandle, moduleBaseAddress + 0x180AA20);

    Wmemory::WriteMemory<int>(processHandle, localPlayerController + 0x6D4, 144);

    Wmemory::ReadMemory<int>(processHandle, localPlayerController + 0x6D4);

    CloseHandle(processHandle);
    return 0;
}
```
