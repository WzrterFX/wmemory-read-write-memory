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

### 1. Process Identification
- **Function:** `Wmemory::GetProcessID`
  - **Description:** Obtain the process ID (PID) of a target process by providing its name.
  - **Example:**
    ```cpp
    uintptr_t processID = Wmemory::GetProcessID(L"Procces.exe");
    ```

### 2. Module Base Address Retrieval
- **Function:** `Wmemory::GetModuleBaseAddress`
  - **Description:** Retrieve the base address of a module within a specified process.
  - **Example:**
    ```cpp
    uintptr_t moduleBaseAddress = Wmemory::GetModuleBaseAddress(processID, L"target.dll");
    ```

### 3. Memory Reading
- **Function:** `Wmemory::ReadMemory`
  - **Description:** Read the value of a specified data type from the memory of a target process.
  - **Example:**
    ```cpp
    int specifiedMemory = Wmemory::ReadMemory<int>(processHandle, moduleBaseAddress + 0x00);
    ```

### 4. Memory Writing
- **Function:** `Wmemory::WriteMemory`
  - **Description:** Write a value of a specified data type to the memory of a target process.
  - **Example:**
    ```cpp
    Wmemory::WriteMemory<int>(processHandle, specifiedMemory + 0x00, 16);
    ```


## Example Usage
```main.cpp
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


###Contributing
If you wish to contribute to repository, please create a fork of the repository, make your changes, and submit a pull request.
