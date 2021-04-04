%include "st_io.inc"
global _start
section .text
_start:
GETUN eax
mov [T], eax
mov dword[k], 1
add [k], eax
mov eax, [k]
mov bx, 3600
div bx
mov cx, dx; запомнили остаток от деления секунд k на 3600
mov bl, 24
div bl
mov [H], al
mov bl, 60
mov ax, cx
div bl
mov [M], al
mov [S], ah
mov eax, 0
mov ax, word[H]
UNSINT eax
PUTCHAR ':'
mov eax, 0
mov ax, word[M]
UNSINT eax
PUTCHAR ':'
mov eax, 0
mov ax, word[S]
UNSINT eax
FINISH

section .bss
T resd 1
k resd 1
H resw 1
M resw 1
S resw 1