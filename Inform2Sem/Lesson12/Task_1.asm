%include "st_io.inc"
global _start
section .text
_start:
mov ax, 5
mov bx, 2
sub ax, bx
pushf 
pop ax
xor ax, 10000000b
push ax
popf
js L1
PRINT "sf = 0"
PUTCHAR 0xA
FINISH
L1:
PRINT "sf = 1"
PUTCHAR 0xA
FINISH