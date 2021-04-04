%include "st_io.inc"
global _start
section .text
_start:
mov eax, 0
GETUN eax
mov [Z], ax; вводимое число 
mov bl, 12
div bl
mov [R], ah; остаток
cmp ah, 0
jne L2
jmp L1
L2:
mov eax, 0
mov ax, word [Z]
mov bx, 0
mov bl, byte [R]
sub ax, bx
mov bl, 12
div bl
mov ebx, 0
mov bl, al
UNSINT ebx
PUTCHAR ':'
mov eax, 0
mov al, [R]
UNSINT eax
PUTCHAR 0xA
FINISH

L1:
mov [Y], byte 12
mov ax, 12
sub [Z], ax
mov eax, 0
mov ax, [Z]
UNSINT eax
PUTCHAR ':'
mov eax, 0
mov al, [Y]
UNSINT eax
PUTCHAR 0xA
FINISH

section .bss
Y resb 1
R resb 1
Z resw 1