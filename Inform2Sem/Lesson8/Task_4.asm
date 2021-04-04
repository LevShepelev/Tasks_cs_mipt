%include "st_io.inc"
global _start
section .text
_start:
mov eax, 0; i
mov ebx, 9; j

L2:
mov cl, [a + ebx]
cmp cl, [a - 1 + ebx]
jge L1
mov dl, [a - 1 + ebx]
mov [a - 1 + ebx], cl
mov [a + ebx], dl
L1:
dec ebx
cmp ebx, eax
ja L2
inc eax
mov ebx, 9; здесь забыл вернуть ebx в нач состояние
cmp eax, 10
jb L2
mov edx, 0
L3:
mov al, [a + edx]
cbw
cwde
SIGNINT eax
PUTCHAR 0xA
inc edx
cmp edx, 10
jb L3
FINISH

section .data
a db -2, 3, 4, 1, -3, 4, 5, 1, -33, 4