# Wmemory

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
- **Function:** `Wmemory wmemory(const wchar_t* name);`
  - **Description:** Constructor for wmemory.
  - **Example:**
    ```cpp
    Wmemory wmemory("target.exe");
    ```

### 2. Get module address
- **Function:** `uint64 GetModuleBase(const wchar_t* name);`
  - **Description:** Get the base address of a module within a specified process.
  - **Example:**
    ```cpp
    adr64 base = wmemory.GetModuleBase(L"target.dll");
    ```

### 3. Memory reading
- **Function:** `T ReadMemory(uint64 address);`
  - **Description:** Read the value of a specified data type from the memory of a target process.
  - **Example:**
    ```cpp
    uint64 address = wmemory.ReadMemory<uint64>(0x0);
    ```

### 4. Memory writing
- **Function:** `void WriteMemory(uint64 address, const T& value)`
  - **Description:** Write a value of a specified data type to the memory of a target process.
  - **Example:**
    ```cpp
    wmemory.WriteMemory<sint32>(0x0, 144);
    ```
