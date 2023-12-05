# wmemory-read-write-memory
Simple source for write/read x64 procces
just import wmemory folder in project and include "wmemory/wmemory.h"


### uintptr_t GetProcessID(const wchar_t* processName);
> The function finds the ID of a process by its name.
```
uintptr_t processID = GetProcessID(L"targetProcces.exe");
HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
```

### uintptr_t GetModuleBaseAddress(uintptr_t processID, const wchar_t* moduleName);
> The function retrieves the base address of a module within a specified process.
```
uintptr_t moduleAddres = GetModuleBaseAddress(processID, L"targetModule.dll")
```
