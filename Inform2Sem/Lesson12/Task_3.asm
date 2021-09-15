%include "st_io.inc"
global _start
section .text
_start:
mov ecx, 6
mov esi, s1
mov edi, s2
rep movsb 

mov eax, 4
mov ebx, 1
mov ecx, s2
mov edx, 6
int 0x80
mov eax, 1
mov ebx, 0
int 0x80

section .data
s1 db "123456"
s2 db "asdfgh"