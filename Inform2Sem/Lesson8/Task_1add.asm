%include "st_io.inc"
global _start
section .text
_start:
mov ebx, 0
mov ecx, 0

L1:
mov eax, 0
mov al, [A + ebx + 4 * ecx]
mov edx, eax
mov eax, 0
mov al, [B + ebx + 4 * ecx]
add edx, eax
UNSINT edx
PUTCHAR ' '
inc ebx
cmp ebx, 4
jb L1
PUTCHAR 0xA
inc ecx
mov ebx, 0
cmp ecx, 3
jb L1
FINISH


section .data
A db 2, 3, 4, 5, 2, 4, 5, 7, 2, 0, 3, 1; 3x4
B db 1, 3, 4, 5, 6, 1, 3, 4, 5, 7, 2, 2; 3x4
C db 2, 3, 1, 4, 6, 7, 8, 9, 0, 1, 2, 3; 3x4