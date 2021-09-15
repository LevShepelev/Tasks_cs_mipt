%include "st_io.inc"
global _start
section .text
_start:
xor eax, eax
mov al, [d]
shl ax, 11
or [t1], ax
xor ax, ax
mov al, [m]
shl ax, 7
or [t1], ax
xor ax, ax
mov al, [y]
or [t1], ax

xor ax, ax
mov ah, [d1]
shl ah, 1
or [t2], ax
xor ax, ax
mov al, [m1]
shl ax, 5
or [t2], ax
xor ax, ax
mov al, [y1]
or [t2], ax

mov ax, [t2]
and ax, 11111b
UNSINT eax
PUTCHAR ':'

mov ax, [t2]
shr ax, 5
and ax, 1111b
UNSINT eax
PUTCHAR ':'

xor eax, eax
mov ax, [t2]
shr ax, 9
UNSINT eax
PUTCHAR 0xA

mov ax, [t1]
and ax, 1111111b
UNSINT eax
PUTCHAR ':'
shl ax, 9
mov [t2], ax

mov ax, [t1]
shr ax, 7
and ax, 1111b
UNSINT eax
PUTCHAR ':'
shl ax, 5
and ax, 11111b
and [t2], ax

mov ax, [t1]
shr ax, 11
UNSINT eax
or ax, 1111111111100000b
and [t2], ax 
PUTCHAR 0xA
FINISH

section .data
d db 26
m db 6
y db 21
d1 db 1
m1 db 5
y1 db 20
t1 dw 0
t2 dw 0