%include "st_io.inc"
global _start
section .text
_start:
mov ebx, 0; Ai
mov ecx, 0; Aj
mov edx, 0; Bi
mov esi, 0; Bj
L1:
mov al, [A + ebx + ecx]
mov [B + edx + esi], al
inc ebx
add esi, 3
cmp ebx, 4
jb L1
add ecx, 4
inc edx
mov esi, 0
mov ebx, 0
cmp edx, 3
jb L1
mov edx, 0
mov esi, 0
L2:
mov al, [B + edx + esi]
cbw
cwde
SIGNINT eax
PUTCHAR ' '
inc edx
cmp edx, 3
jb L2
PUTCHAR 0xA
add esi, 3
mov edx, 0
cmp esi, 12
jb L2
FINISH

FINISH
section .data
A db 1, 3, 4, -24, 1, 2, 3, 4, 5, -2, 7, 2; 3x4
section .bss
B resb 12