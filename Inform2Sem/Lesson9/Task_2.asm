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
mov eax, 0
mov ebx, 0
L2:
mov cx, [esp + ebx]
cmp cx, 0
jne L3
inc al
L3:
add ebx, 2
cmp ebx, 20
jb L2
UNSINT eax
PUTCHAR 0xA
FINISH

section .data
a db 1, 2, 0, 4, 0, 6, 0, 8, 0, 10