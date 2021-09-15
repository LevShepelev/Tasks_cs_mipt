%include "st_io.inc"
global _start
section .text
_start:
mov ebx, 0
L1:
mov ax, 0
mov al, [a + ebx]
push ax
inc ebx
cmp ebx, 10
jb L1

mov bx, [esp]
mov eax, esp
add eax, 2
mov cx, [eax]
mov [esp], cx
mov [eax], bx
mov ebx, 0

L2:
pop ax
cwde
UNSINT eax
PUTCHAR 0xA
inc ebx
cmp ebx, 10
jb L2
FINISH
section .data
a db 1, 2, 3, 4, 0, 6, 0, 8, 9, 10