%include "st_io.inc"
global _start
section .text
_start:
mov eax, L1
jmp eax
L2:
mov eax, 10
UNSINT eax
PUTCHAR 0xA
FINISH
L1:
mov eax, L2
mov [z], eax
mov ebx, z
jmp [ebx]
section .data
msgt db 'MIPT', 0, 0xA
msgtl equ $-msgt
section .bss
z resd 1