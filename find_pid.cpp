#include "find_pid.h"


// Function to find PID by process name
DWORD GetPIDByProcessName(const std::wstring& processName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return 0;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hSnapshot, &pe32)) {
        CloseHandle(hSnapshot);
        return 0;
    }

    do {
        if (wcscmp(pe32.szExeFile, processName.c_str()) == 0) {
            CloseHandle(hSnapshot);
            return pe32.th32ProcessID;
        }
    } while (Process32Next(hSnapshot, &pe32));

    CloseHandle(hSnapshot);
    return 0;
}

DWORD get_pid(std::wstring processName ) {
    
    DWORD pid = GetPIDByProcessName(processName);
    if (pid != 0) {
       
    }
    else {
       
    }
    return pid;
}
