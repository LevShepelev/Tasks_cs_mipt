%include "st_io.inc"
section .data
a dw 12313
b db 3
ans dd 0
global _start:
section text
_start:
mov ebx, 0
mov al, byte[a]
mul byte[b]
mov bx, ax
mov eax, 0
mov byte[ans], bl
mov al, byte[a + 1]
mul byte[b]
add bh, al
mov byte[ans + 1], bh
adc ah, 0
mov byte[ans + 2], ah
UNSINT dword[ans]
PUTCHAR 0xA
FINISH