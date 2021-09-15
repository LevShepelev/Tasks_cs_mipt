%include "st_io.inc"
global _start
section .text
_start:
mov ecx, 20
mov esi, A
mov edi, B
rep movsw 
mov ecx, 10
L1:
mov ax, [B + 2 * ecx]
cwde
SIGNINT eax
PUTCHAR 0xA
dec ecx
cmp ecx, 0
ja L1
FINISH

section .data
A dw 1, 2, 3, 4, 5, -1, -2, -3, -4, -5
B dw -10, -11, -12, -13, -14, 6, 7, 8, 9, 10