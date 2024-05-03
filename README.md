# Wmemory

Wmemory is a versatile C++ library designed for Windows, providing functionalities for memory manipulation within external processes.
The library offers several features to facilitate process interaction and memory management.

## Getting Started

### Prerequisites
- Visual Studio or any C++ compiler that supports C++14 or later.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/WzrterFX/wmemory-read-write-memory
   ```

## Features

### 1. Get process
- **Function:** `Memory memory(const wchar_t* name);`
  - **Description:** Constructor for wmemory.
  - **Example:**
    ```cpp
    Memory memory("target.exe");
    ```

### 2. Get module address
- **Function:** `uintptr_t GetModule(const wchar_t* name);`
  - **Description:** Get the base address of a module within a specified process.
  - **Example:**
    ```cpp
    uintptr_t target = memory.GetModule(L"target.dll");
    ```

### 3. Memory reading
- **Function:** `T ReadMemory(uintptr_t address);`
  - **Description:** Read the value of a specified data type from the memory of a target process.
  - **Example:**
    ```cpp
    T address = memory.ReadMemory<T>(0x0);
    ```

### 4. Memory writing
- **Function:** `void WriteMemory(uintptr_t address, const T& value)`
  - **Description:** Write a value of a specified data type to the memory of a target process.
  - **Example:**
    ```cpp
    memory.WriteMemory<int>(0x0, 144);
    ```
