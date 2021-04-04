%include "st_io.inc"
global _start
section .text
_start:
jmp L1
L2:
mov eax, 4; Вывод msgt
mov ebx, 1
mov ecx, msgt
mov edx, msgtl
int 0x80
mov eax, 10
UNSINT eax
PUTCHAR 0xA
mov eax, 1; Завершение работы программы
mov ebx, 0
int 0x80
L1:
jmp L2
section .data
msgt db 'MIPT', 0, 0xA
msgtl equ $-msgt