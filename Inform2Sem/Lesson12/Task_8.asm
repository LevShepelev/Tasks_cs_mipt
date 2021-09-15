%include "st_io.inc"
global _start
section .text
_start:
cld
mov ecx, 4
mov esi, A
add esi, 2
mov edi, B
add edi, 1
repe cmpsb
js L1
PRINT "equal"
FINISH
L1:
PRINT "Not equal"
FINISH

section .data
A db "1100001111"
B db "1000011111"