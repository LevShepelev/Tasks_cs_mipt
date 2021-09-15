%include "st_io.inc"
global _start
section .text
_start:
GETUN eax
mov bx, ax
mov dx, ax
and dx, 11111b
mov cl, 11
shl dx, cl
and bx, 1111100000000000b 
mov cl, 5
rol bx, cl
and ax, 11111100000b
or ax, bx
or ax, dx
UNSINT eax
FINISH