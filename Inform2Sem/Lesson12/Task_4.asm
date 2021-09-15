%include "st_io.inc"
global _start
section .text
_start:
mov esi, s2
add esi, 5
mov edi, s1
add edi, 3
mov ecx, 4
rep movsb 

mov eax, 4
mov ebx, 1
mov ecx, s1
mov edx, 10
int 0x80
mov eax, 1
mov ebx, 0
int 0x80



section .data
s1 db "1234567891"
s2 db "asdfghjklz"