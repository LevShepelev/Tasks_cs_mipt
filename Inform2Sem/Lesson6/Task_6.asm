%include "st_io.inc"
global _start
section .text
_start:
mov eax, 0
mov ebx, 1
mov ecx, 2
L2:
add eax, ebx
mov edx, eax; меняем местами eax и ebx
mov eax, ebx
mov ebx, edx
inc ecx
cmp ecx, 10
jbe L2
UNSINT eax
PUTCHAR 0xA
FINISH