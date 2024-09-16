#ifndef hget_pid
#define hget_pid
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <string>
#include <stdlib.h>


DWORD get_pid(std::wstring processName);


#endif // !hget_pid
