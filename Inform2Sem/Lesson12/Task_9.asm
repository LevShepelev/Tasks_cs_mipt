%include "st_io.inc"
global _start
section .text
_start:
mov al, '*'
mov ecx, 10
mov edi, s1
repne scasb
mov al, '+'
dec edi
stosb
mov eax, 4
mov ebx, 1
mov ecx, s1
mov edx, 10
int 0x80
mov eax, 1
mov ebx, 0
int 0x80

section .data 
s1 db "121*11811*"