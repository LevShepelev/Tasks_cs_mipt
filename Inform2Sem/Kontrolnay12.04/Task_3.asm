%include "st_io.inc"
global _start
section .text
_start:
mov eax, 1
mov ebx, 1
L1:
mul ebx
mov [fact + 4 * ebx - 4], eax
inc ebx
cmp ebx, 17
jb L1

mov eax, 0; Печать массива
L4:
inc eax
cmp eax, 17
jb L4


mov ecx, 0; движение по массиву факториалов
mov eax, 0; движение массив a
L2:
mov ebx, [fact + 4 * ecx]
cmp [a + 4 * eax], ebx
je EQUAL
inc ecx
cmp ecx, 17
jb L2
mov ecx, 0
mov dword [a + 4 * eax], 0
inc eax
cmp eax, 6; 6 - размер массива
jb L2
jmp FIN

EQUAL:
mov edx, ecx
inc edx
mov [a + 4 * eax], edx
inc eax
cmp eax, 6; 6 - размер массива
jb L2
FIN:

mov eax, 0; Печать массива 
L3:
UNSINT [a + 4 * eax]
PUTCHAR 0xA
inc eax
cmp eax, 6
jb L3
FINISH

section .data 
a dd 2, 7, 40320, 6, 120, 720
section .bss
fact resd 17