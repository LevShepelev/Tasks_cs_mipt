%include "st_io.inc"
global _start
section .text
_start:
GETUN eax
mov [a], ax
mov bl, 10
mov bh, 0
mov cl, 5
L1:
div bl
cmp ah, cl
jne L2
jmp L3
L2:
mov ah, 0
cmp al, bh
ja L1
PRINT "5 was not found"
FINISH
L3:
PRINT "5 was found"
FINISH
section .bss
a resw 1