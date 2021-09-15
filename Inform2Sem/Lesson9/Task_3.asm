%include "st_io.inc"
global _start
section .text
_start:
mov ebx, 0
mov ecx, 10
L1:
mov al, [a + ebx]
cbw
push ax
inc ebx
cmp ebx, 10
jb L1

mov ebx, 0
L3:
cmp word[esp + 2 * ebx], 0
jne NotZero
mov esi, ebx
dec ecx
L4:
dec esi
mov ax, [esp + 2 * esi]
inc esi
mov [esp + 2 * esi], ax
dec esi
cmp esi, 0
ja L4
add esp, 2
jmp L3

NotZero:
inc ebx
cmp ebx, ecx
jb L3

L6:
pop ax
cwde
SIGNINT eax
PUTCHAR 0xA
inc ebp
cmp ebp, ecx
jb L6
FINISH

section .data
a db 0, 0, 23, 0, 0, 6, 0, -8, 0, 5
ret_adr dd 0