%include "st_io.inc"
global _start
section .text
_start:
mov si, 0
mov ax, [a]
mov bx, 10
L1:
mov dx, 0
div bx
inc si
add al, 0
loopnz L1
mov eax, 0
mov ax, si
UNSINT eax
FINISH

section .data
a dw 43
