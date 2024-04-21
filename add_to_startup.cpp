
#include "add_to_startup.h"

#pragma comment(lib, "Shlwapi.lib")

bool bAddToStartup(const std::wstring& appName, const std::wstring& appPath) {
    HKEY hKey;
    LPCWSTR keyPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";

    if (RegOpenKeyExW(HKEY_CURRENT_USER, keyPath, 0, KEY_SET_VALUE, &hKey) != ERROR_SUCCESS) {
        std::cerr << "Error opening registry key." << std::endl;
        return false;
    }

    if (RegSetValueExW(hKey, appName.c_str(), 0, REG_SZ, (BYTE*)appPath.c_str(), (DWORD)((appPath.length() + 1) * sizeof(wchar_t))) != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        std::cerr << "Error setting registry value." << std::endl;
        return false;
    }

    RegCloseKey(hKey);
    std::cout << "Program successfully added to startup." << std::endl;
    return true;
}

void AddToStartup() {
    std::wstring appName = L"shellinject";
    std::wstring appPath = L"C:\\Users\\adamp\\projects\\vs\\shellinject\\x64\\Debug\\shellinject.exe";

    if (!bAddToStartup(appName, appPath)) {
        std::cerr << "Failed to add program to startup." << std::endl;
        
    }

}