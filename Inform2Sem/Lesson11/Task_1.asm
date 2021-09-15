%include "st_io.inc"
global _start
section .text
_start:
mov edx, 0
GETUN eax
mov ecx, 16
L1:
shl ax, 1
jnc ZERO
inc edx
ZERO:
loop L1
PRINT "число единиц = "
UNSINT edx
PUTCHAR 0xA
FINISH