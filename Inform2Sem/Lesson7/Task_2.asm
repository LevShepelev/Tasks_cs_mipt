%include "st_io.inc"
global _start
section .text
_start:
mov cl, 1; для байта
mov al, 1
L2:
L1:
inc cl
mov ebx, 0
mov bl, al
mul cl
jnc L1
jno L2
dec cl
UNSINT ebx
PUTCHAR 0xA
mov eax, 0
mov al, cl
UNSINT eax
PUTCHAR 0xA;

mov cx, 1; для слова
mov ax, 1
L4:
L3:
inc cx
mov ebx, 0
mov bx, ax
mul cx
jnc L3
jno L4
dec cx
UNSINT ebx
PUTCHAR 0xA
mov eax, 0
mov ax, cx
UNSINT eax
PUTCHAR 0xA;

mov ecx, 1; для двойного слова
mov eax, 1
L6:
L5:
inc ecx
mov ebx, 0
mov ebx, eax
mul ecx
jnc L5
jno L6
dec ecx
UNSINT ebx
PUTCHAR 0xA
mov eax, 0
mov eax, ecx
UNSINT eax
PUTCHAR 0xA;

FINISH