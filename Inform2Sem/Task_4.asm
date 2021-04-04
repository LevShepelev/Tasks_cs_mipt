%include "st_io.inc"
global _start
section .data
a dw 254
b dw 250
section .text
_start:
mov ah, byte[b]
add byte[a], ah
mov ah, byte[b + 1]
adc byte[a + 1], ah
mov eax, 0
mov ax, [a]
UNSINT eax
PUTCHAR 0xA
FINISH