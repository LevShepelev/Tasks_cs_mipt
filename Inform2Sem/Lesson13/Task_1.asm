%include "st_io.inc"
global _start

section .bss
adr resd 1
section .data
a dd 0
b dd 0

section .text
_start:
GETSIG [a]
GETSIG [b]
mov eax, ret
mov [adr], eax
mov eax, [a]
mov ebx, [b]
jmp SUM
ret:
SIGNINT eax
PUTCHAR 0xA

GETSIG [a]
GETSIG [b]
mov eax, ret1
mov [adr], eax
mov eax, [a]
mov ebx, [b]
jmp SUM
ret1:
SIGNINT eax
PUTCHAR 0xA

FINISH 


SUM:
add eax, ebx
jmp dword[adr]


