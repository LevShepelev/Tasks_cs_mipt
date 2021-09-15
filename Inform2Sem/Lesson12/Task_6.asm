%include "st_io.inc"
global _start
section .text
_start:
mov ecx, 3
mov esi, A
add esi, 12
mov edi, B
add edi, 8
rep movsd
mov ecx, 0

L1:
mov eax, [B + 4 * ecx]
SIGNINT eax
PUTCHAR 0xA
inc ecx
cmp ecx, 10
jb L1
FINISH

section .data
A dd 1, 2, 3, 4, 5, 1, 2, 3, 4, 5
B dd 10, 11, 12, 13, 14, 6, 7, 8, 9, 10