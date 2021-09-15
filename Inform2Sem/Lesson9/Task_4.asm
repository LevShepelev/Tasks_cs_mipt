%include "st_io.inc"
global _start
section .text
_start:
mov ebx, 0
L1:
mov al, [a + ebx]
cbw
push ax
inc ebx
cmp ebx, 10
jb L1

mov ebx, 0
mov ecx, 1
L2:
mov ax, [esp + 2 * ebx]
cmp ax, [esp + 2 * ecx]
je FIN
inc ecx
cmp ecx, 10
jb L2
inc ebx
mov ecx, ebx
inc ecx
cmp ebx, 9
jb L2
mov al, 0
add esp, 10
PRINT "Нет одинаковых слов"
FINISH
FIN:
mov al, 1
PRINT "есть одинаковые слова"
FINISH
section .data
a db 4, 2, 23, -24, 3, 6, 7, -8, 0, 5