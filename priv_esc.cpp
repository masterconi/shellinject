
#include "priv_esc.h"

int priv_esc() {
    // Simulated user with normal privileges
    HANDLE hToken;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
        
        return 1;
    }

    // Adjust privileges to enable SeDebugPrivilege
    TOKEN_PRIVILEGES tp;
    tp.PrivilegeCount = 1;
    if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid)) {
        
        CloseHandle(hToken);
        return 1;
    }
    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    if (!AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), NULL, NULL)) {
        
        CloseHandle(hToken);
        return 1;
    }

    // Check if SeDebugPrivilege is now enabled
    BOOL bPrivilegeEnabled;
    _PRIVILEGE_SET RequiredPrivileges;
    RequiredPrivileges.PrivilegeCount = 1;
    RequiredPrivileges.Control = PRIVILEGE_SET_ALL_NECESSARY;
    RequiredPrivileges.Privilege[0].Luid = tp.Privileges[0].Luid;
    RequiredPrivileges.Privilege[0].Attributes = SE_PRIVILEGE_ENABLED;

    if (!PrivilegeCheck(hToken, &RequiredPrivileges, &bPrivilegeEnabled)) {
       
        CloseHandle(hToken);
        return 1;
    }
    if (bPrivilegeEnabled) {
        
    }
    else {
        
        CloseHandle(hToken);
        return 1;
    }

    // Close handles
    CloseHandle(hToken);

    // Open an admin terminal
    /*
    if (!ShellExecute(NULL, L"runas", L"cmd.exe", NULL, NULL, SW_SHOWNORMAL)) {
        std::cerr << "Failed to open admin terminal\n";
        return 1;
    }
    */
    return 0;
}