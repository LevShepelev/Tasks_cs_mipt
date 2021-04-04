%include "st_io.inc"
global _start
section .text
_start:
mov ebx, 0
mov ecx, 0
mov edx, 0
L1:
mov al, [A + ebx + ecx]
add dl, [A + ebx + ecx]
inc ebx
cmp ebx, 3
jb L1
add ecx, 3
mov ebx, 0
UNSINT edx
PUTCHAR 0xA
mov edx, 0
cmp ecx, 12
jb L1
FINISH


section .data
A db 2, 3, 4, 5, 2, 4, 5, 7, 2, 0, 3, 1; 4x3