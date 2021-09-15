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
cmp ebx, 5
jb L1

mov edx, 0
mov ebx, 0

POS:
mov ax, [esp + 2 * ebx]
cwde

cmp word[esp + 2 * ebx], 0
jl NEG
inc ebx
cmp ebx, 5
jb POS
PRINT "THERE'S NO 2 NEGATIVE NUMBERS"
FINISH

NEG:
mov [n + 4 * edx], ebx; номер отрицательного
inc edx
inc ebx
cmp edx, 2
jb POS

mov ecx, [n]
mov edx, [n + 4]
mov ax, [esp + 2 * ecx]
mov bx, [esp + 2 * edx] 
mov [esp + 2 * ecx], bx
mov [esp + 2 * edx], ax

mov ebx, 0
L5:
pop ax
mov [a + ebx], al
cwde
SIGNINT eax
PUTCHAR 0xA
inc ebx
cmp ebx, 5
jb L5
FINISH

section .data 
a db 1, -2, -3, -4, 1
section .bss
n resd 2