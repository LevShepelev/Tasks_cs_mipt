%include "st_io.inc"
global _start
section .text
_start:
mov cx, [a]
mov bl, 3
L1:
mov ax, cx
div bl
mov edx, 0
mov dl, ah
UNSINT edx
PUTCHAR 0xA
add cx, [h]
cmp cx, [b]
jbe L1
FINISH
section .data
a dw 20
b dw 40
h dw 4