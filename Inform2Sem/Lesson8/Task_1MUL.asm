%include "st_io.inc"
global _start
section .text
_start:
mov ebp,  0;
mov ebx,  0; A
mov ecx,  0; A
mov edx,  0; B
mov esi,  0; B
mov word[buf], 0

L2:
mov [bEDX], edx
mov eax, 0
mov al, [A + ebx + ecx]
imul byte[B + edx + esi]
mov edx, [bEDX]
add [buf], ax
mov eax, 4
cmp ebx, eax
jae One_elem_fin
inc ebx
add esi, 3
mov eax, 12
cmp esi, eax
jb L2
One_elem_fin:
mov ax, [buf]
cwde
SIGNINT eax
mov word[buf], 0
PUTCHAR ' '
inc edx
mov ebx, 0
mov eax, 3
mov esi, 0
cmp edx, eax
jb L2
PUTCHAR 0xA
add ecx, 4
mov edx, 0
mov esi, 0
mov eax, 12
cmp ecx, eax
jb L2
FINISH


section .data
A db 2, 3, 4, -4, 2, 4, 5, 7, 2, 0, 3, 1; 3x4
B db 1, 3, 4, 5, 6, 1, -8, 4, 5, 7, 2, 2; 4x3
buf dw 0
bEDX dd 0
section .bss
C resw 9; 3x3