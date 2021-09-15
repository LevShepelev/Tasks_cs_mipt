%include "st_io.inc"
global _start
section .text
_start:
GETUN eax
mov ebx, eax
and ax, 111b
mov cl, 3
rol bx, cl
and bx, 111b
cmp ax, bx
je EQUAL
PRINT "NOT EQUAL"
FINISH
EQUAL:
PRINT "EQUAL"
FINISH