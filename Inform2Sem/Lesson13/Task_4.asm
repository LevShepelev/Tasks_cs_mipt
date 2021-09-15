%include "st_io.inc"
global _start
section .data
a dd 0
b dd 0
section .bss
adr resd 1
section .text

Sum:
pop dword[adr]
pop ebx
pop eax
add eax, ebx
SIGNINT eax
PUTCHAR 0xA
push dword[adr]
ret

_start:
GETSIG [a]
GETSIG [b]
push dword[a]
push dword[b]
call Sum
push dword[a]
push dword[b]
call Sub
FINISH

Sub:
pop dword[adr]
pop ebx
pop eax
sub eax, ebx
SIGNINT eax
PUTCHAR 0xA
push dword[adr]
ret