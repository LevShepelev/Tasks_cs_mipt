%include "st_io.inc"
global _start
extern Input_dd
extern Input_dw

section .text
_start:
call Input_dd
mov [b], eax
mov eax, 0
call Input_dw
add eax, [b]
UNSINT eax
FINISH
section .bss
b resd 1