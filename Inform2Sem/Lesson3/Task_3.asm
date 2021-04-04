%include "st_io.inc"
global _start
section .text
_start:

mov ax,[a]
mov byte [b], ah
mov byte [b + 1], al
mov ebx, 0
mov bx, [b]
UNSINT ebx
PUTCHAR 0xA
FINISH
section .data
a dw 73
b dw 0