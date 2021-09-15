%include "st_io.inc"
global _start
section .text
_start:
mov ebx, 0
mov eax, 0
push dword a
push dword b
push dword c
L1:
mov ebx, [esp + 4 * eax]
mov byte[ebx], 0
inc eax
cmp eax, 3
jb L1

mov ebx, 0
L2:
pop ecx
mov al, [ecx]
cbw
cwde
SIGNINT eax
PUTCHAR 0xA
inc ebx
cmp ebx, 3
jb L2

FINISH
section .data
a db 3
b db 4
c db -5