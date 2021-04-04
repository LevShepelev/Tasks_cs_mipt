 global _start
 section .text
 mov eax, 4
 mov ebx, 1
 mov ecx, msgty
 mov edx, msglty
 int 0x80
 mov eax, 1
 mov ebx, 0
 int 0x80
 section .data
 msgty db 'MIPT', 0, 0xA
 msglty equ $-msgty

