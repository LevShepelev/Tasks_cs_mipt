%include "st_io.inc"
global _start
section .text
_start:
mov eax, 1
mov ebx, 2
mov ecx, 3
mov edx, 4
mov esi, 5
mov edi, 6
mov ebp, 7
pushad
mov ecx, 100
add [esp + 4 * 7], ecx
popad
UNSINT eax
PUTCHAR 0xA
FINISH