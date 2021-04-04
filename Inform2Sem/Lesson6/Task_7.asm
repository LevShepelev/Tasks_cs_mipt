%include "st_io.inc"
global _start
section .text
_start:
GETUN eax
mov [a], ax
GETUN eax
mov [b], ax
mul word[a]
jc L3
jmp L1
L3:
jo L2
jmp L1
L2:
PRINT "Произошло переполнение"
PUTCHAR 0xA
FINISH
L1:
PRINT"Переполнение не произошло"
PUTCHAR 0xA
FINISH

section .bss
a resw 1
b resw 1