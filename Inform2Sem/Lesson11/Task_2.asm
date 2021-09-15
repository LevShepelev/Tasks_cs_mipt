%include "st_io.inc"
global _start
section .text
_start:
GETUN ebx

cmp ebx, 0
jne L3
PUTCHAR '0'
PUTCHAR 0xA
FINISH
L3:

mov ecx, 15
L1:
shl bx, 1
jnc cont
jmp PRINTING
cont:
dec ecx
cmp ecx, 0
ja L1

PRINTING:
PUTCHAR '1'
cmp ecx, 0
ja L2
PUTCHAR 0xA
FINISH

L2:
shl bx, 1
jc ONE
PUTCHAR '0'
dec ecx
cmp ecx, 0
ja L2
PUTCHAR 0xA
FINISH
ONE:
PUTCHAR '1'
dec ecx
cmp ecx, 0
ja L2
PUTCHAR 0xA
FINISH
