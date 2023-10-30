# wmemory-read-write-memory
Simple source for write/read x64 procces
just import wmemory folder in project and include "wmemory/wmemory.h"


### uintptr_t GetProcessID(const wchar_t* processName);
> The function finds the ID of a process by its name.
```
uintptr_t processID = GetProcessID(L"MyProcces.exe");
HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
```

### uintptr_t GetModuleBaseAddress(uintptr_t processID, const wchar_t* moduleName);
> The function retrieves the base address of a module within a specified process.
```
uintptr_t moduleAddres = GetModuleBaseAddress(processID, L"MyModule.dll")
```

### uintptr_t ReadMemory(HANDLE processHandle, uintptr_t address, size_t size);
> The function reads memory address in a target process and returns that data as a uintptr_t value.
```
uintptr_t addresFromModule = ReadMemory(processHandle, moduleAddres + myAddres, sizeof(uintptr_t));
uintptr_t myAddres1 = addresFromModule + myAddres2;
```

### void WriteMemory(HANDLE processHandle, uintptr_t address, uintptr_t value, size_t size);
> The function stores memory address within a target process.
```
WriteMemory(processHandle, myAddres1, 144, sizeof(int));
```


### example of working
> cs2 read/write memory example
```
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
```
![image](https://github.com/WzrterFX/wmemory-read-write-memory/assets/122642787/8f347725-40f0-4234-9d0c-9442b12db808)
