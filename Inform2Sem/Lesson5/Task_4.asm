%include "st_io.inc"
section data
a dw 15
b db 3
global _start:
section text
_start:
mov eax, 0
mov al, [b]
mul word[a]
UNSINT eax
PUTCHAR 0xA
FINISH