%include "st_io.inc"
global _start
section .text
_start:
mov ecx, 0
BEGIN:
cmp byte[s1 + ecx], '9'
ja Not_a_number
cmp byte[s1 + ecx], '1'
jb Not_a_number
add byte[s1 + ecx], 'a' - '1'
Not_a_number:
inc ecx
cmp ecx, length
jb BEGIN

mov eax, 4
mov ebx, 1
mov ecx, s1
mov edx, length
int 0x80
mov eax, 1
mov ebx, 0
int 0x80

section .data 
s1 db "1231Weqe qwewE3, 123"
length equ $-s1