%include "st_io.inc"
N equ 20
global _start
section .text
_start: 
mov ebx, 0
mov ecx, 0
BEGIN:
mov eax, [bufEAX]
mov esi, [bufESI]
cmp eax, esi
jae L1
mov edi, eax
mov eax, esi
mov esi, edi
L1:
mov edx, 0
div esi
mov eax, esi
mov esi, edx
cmp esi, 0
je L4
cmp esi, 1
je L5
jmp L1
L5:
mov dword[A + ebx + ecx], 1
jmp NEXT
L4:
mov [A + ebx + ecx], eax
NEXT:
UNSINT [A + ebx + ecx]
PUTCHAR ' '
add ebx, 4
inc dword[bufEAX]
cmp ebx, 4*N
jb BEGIN
PUTCHAR 0xA
add ecx, 4*N
mov ebx, 0
inc dword[bufESI]
mov dword[bufEAX], 1
cmp ecx, 4*N*N
jb BEGIN
FINISH

section .data
bufESI dd 1
bufEAX dd 1

section .bss
A resd N*N

